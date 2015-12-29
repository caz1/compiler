#include <cstdio>
#include <cmath>
#include "err.hh"
#include "dumpdot.hh"
#include "util.hh"
#include "global.hh"
#include "c1.tab.hh"
#include <getopt.h>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "llvmhead.hh"

extern int yylineno, yycolumn;
Node* root;	
ErrFactory errfactory;
vector<Node*> List;
bool haveError;
char *infile_name, *outfile_name, *dumpfile_name;
FILE *infp, *outfp, *dumpfp;
map<string, tabelem> table;
vector<pair<string, tabelem>> oldVal;
map<string, Function*> functab;
IRBuilder<> Builder(getGlobalContext());
Module *mod = new Module("demo", getGlobalContext());

void usage() 
{
	printf("usage: c1 [options] [file]\n");
    printf("-h  --help     print this usage and exit\n");
    printf("-v  --version  print version and exit\n");
    printf("-o <file>      place the output into <file>\n");
    printf("-d <file>      dump AST into <file>\n");
	
}

bool handle_opt(int argc, char** argv)
{
    int c;
    int version_flag = 0;
    int help_flag = 0;

    struct option long_options[] =
    {
        {"version", no_argument, &version_flag, 'v'},
        {"help", no_argument, &help_flag, 'h'},
        {"dump", required_argument, NULL, 'd'},
        {0, 0, 0, 0}
    };
    int option_index = 0;
    opterr = 0;

    while ((c = getopt_long(argc, argv, ":hvo:d:", long_options, &option_index)) != -1) {
        switch (c)
        {
            case 0:
                break;
            case 'h':
                help_flag = 1;
                break;
            case 'v':
                version_flag = 1;
                break;
            case 'o':
                outfile_name = optarg;
                break;
            case 'd':
                dumpfile_name = optarg;
                break;
            case '?':
                error("Unknown option -%c\n", optopt);
                return false;
            case ':':
                if (optopt == 'o')
                    error("Option -o requires an argument\n");
                else if (optopt == 'd')
                    error("Option -d requires an argument\n");
                else
                    error("Unknown option -%c\n", optopt);
            default:
                error("Error in handle_opt()\n");
        }
    }

    if (help_flag)
    {
        usage();
        return false;
    }
    if (version_flag)
    {
        printf("c1 compiler 1.0 by caz@ustc\n");
        return false;
    }
    if (optind < argc)
        infile_name = argv[optind];
    if (infile_name == NULL)
    {
        error("no input file");
        exit(-1);
    }
    else
    {
        infp = fopen(infile_name, "r");
        if (infp == NULL)
        {
            error("Can not open infile %s\n", infile_name);
            return false;
        }
    }
    if (outfile_name == NULL)
        outfp = stdout;
    else
    {
        outfp = fopen(outfile_name, "w");
        if (outfp == NULL)
        {
            error("Can not open outfile %s\n", outfile_name);
            return false;
        }
    }
    if (dumpfile_name == NULL)
        dumpfp = stdout;        
    else
    {
        dumpfp = fopen(dumpfile_name, "w");
        if (dumpfp == NULL)
        {
            error("Can not open dumpfile %s\n", dumpfile_name);
            return false;
        }
    }
    return true;
}

	

int main(int argc, char *argv[])
{
	
	extern FILE *yyin;
	int temp;
	haveError = false;
	if (!handle_opt(argc, argv)) return 0; 
	//DumpDOT *dot = new DumpDOT(dumpfp);

    fprintf(outfp, "Parsing ...\n");
    yyin = infp;
	fprintf(outfp, "Parsing file \"\033[1;31;40m%s\033[0m\"\n", infile_name);
	temp = yyparse(infile_name);
	
	if(temp == 1)
	{
		yylineno = 0;
		fprintf(outfp, "parsing failed\n");		
	}		
	else if (temp == 2)
	{
		fprintf(outfp, "using up memory\n");
		fclose(yyin);	
		exit(-1);	
	}
	else 
	{
		yylineno = 1;
		fprintf(outfp, "parsing file \"\033[1;31;40m%s\033[0m\" succcessful\n", infile_name);				
	}
	yycolumn = 1;
	fclose(yyin);

	if (errfactory.error.size() == 0)    
	{
	    //root->dumpdot(dot); // dump ast to the dumpfile
        root->Codegen();
        delete root;
	}
	else
	{
	    if (dumpfp) fclose(dumpfp);	    
	    dumpfp = fopen(dumpfile_name, "w"); // clear file
	}	
	if (errfactory.error.size() == 0)    
        mod->dump();
	errfactory.dump(); // dump warnings and errors
    //delete dot;
	if (dumpfp) fclose(dumpfp);	    
	if (outfp) fclose(outfp);	

	return 0;
}
