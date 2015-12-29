#include "err.hh"
#include "global.hh"

string errmsgs[] = {
#undef errxx
#define errxx(a, b) b,
#include "errcfg.hh"
	"Other Errors"
};


     errmsg::errmsg(int type, int line, int column, string filename, bool isWarn)\
    : type(type), line(line), column(column), filename(filename), isWarn(isWarn)
     { msg = errmsgs[type]; }
void fgetline(string &str, FILE *fp)
{
	int i = 0;
	char c = fgetc(fp);

	while (c != EOF && c != '\n')
	{
		str += c;
		c = fgetc(fp);
	}
}

void errmsg::dumpErr()
{
    int i = 0;
	size_t len = 0;
	FILE *fp= fopen(filename.c_str(), "r");
	char c;
	string str;
	if (isWarn)
		fprintf(outfp, "\033[1;31;40mWarning\033[0m");
	else
		fprintf(outfp, "\033[1;31;40mError\033[0m");
	fprintf(outfp, " in file \033[1;33;40m%s\033[0m @(%d, %d): %s\n",\
	 filename.c_str(), line, column, msg.c_str());
	for (i = 0, fgetline(str, fp); i < line - 1; str.clear(), i++, fgetline(str, fp));	
	fprintf(outfp, "%s\n", str.c_str());
	
	for (i = 0; i < column - 1; i++)
		if (str[i] == '\t')
			fprintf(outfp, "\t");
		else 
			fprintf(outfp, " ");
	fprintf(outfp, "\033[1;34;40m^\033[0m\n");
}

void ErrFactory::dump()
{
    if (error.size() > 0) 
		fprintf(outfp, "\nFound %d errors at least:\n", 
			error.size());
    for (int i = 0; i < error.size(); i++)
        error[i]->dumpErr();
    if (warning.size() > 0) 
		fprintf(outfp, "\nFound %d warnings at least:\n", 
			warning.size());
    for (int i = 0; i < warning.size(); i++)
        warning[i]->dumpErr();  
}


