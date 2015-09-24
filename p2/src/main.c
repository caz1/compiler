#include"token.h"

int num;	// store the number 
char *identifier; // store the identifier
extern FILE* yyin;
extern int yylex();

void printToken(int token, FILE *fp){
	switch(token){// for different tokens, just print it out
		case NUL: fprintf(fp, "< NULL >"); break;
		case NUMBER: fprintf(fp, "<NUMBER, %d>", num); break;
		case ID: fprintf(fp, "<IDENTIFIER, %s>", identifier); break;
		case PLUS: fprintf(fp, "<BINOP, +>"); break;
		case MINUS: fprintf(fp, "<BINOP, ->"); break;
		case MULT: fprintf(fp, "<BINOP, *>"); break;
		case DIV: fprintf(fp, "<BINOP, />"); break;
		case MOD: fprintf(fp, "<BINOP, \%>"); break;
		case EQ: fprintf(fp, "<RELOP, =>"); break;
		case NE: fprintf(fp, "<RELOP, !=>"); break;
		case LT: fprintf(fp, "<RELOP, < >"); break;
		case LE: fprintf(fp, "<RELOP, <=>"); break;
		case GT: fprintf(fp, "<RELOP, > >"); break;
		case GE: fprintf(fp, "<RELOP, >=>"); break;
		case MAIN: fprintf(fp, "<MAIN>"); break;
		case QUOTE: fprintf(fp, "< \" >"); break;
		case SLASH: fprintf(fp, "< \\ >"); break;
		case COMMA: fprintf(fp, "< , >"); break;
		case SEMICOLON: fprintf(fp, "< ; >"); break;
		case LBRACKET: fprintf(fp, "< [ >"); break;
		case RBRACKET: fprintf(fp, "< ] >"); break;
		case LPAR: fprintf(fp, "< ( >"); break;
		case RPAR: fprintf(fp, "< ) >"); break;
		case LBRACE: fprintf(fp, "< { >"); break;
		case RBRACE: fprintf(fp, "< } >"); break;
		case WHILE: fprintf(fp, "< WHILE >"); break;
		case IF: fprintf(fp, "< IF >"); break;
		case CONST: fprintf(fp, "< CONST >"); break;
		case INT: fprintf(fp, "< INT >"); break;
		case ELSE: fprintf(fp, "< ELSE >"); break;
		case ISEQ: fprintf(fp, "< == >"); break;
		default:break;
	}
}

int main(int argc, char **argv){
	char *infilename;
	FILE *fp;
	int token;
	if (argc == 1) {
		printf("please enter the source file name:");		
		cin >> infilename;
	}
	else if (argc == 2)
		infilename = argv[1];


	if ( (fp=fopen(infilename, "r"))==NULL ) {
		printf("File %s can't be opened.\n", infilename);
		exit(1);
	}

	printf("/*****************************\n");
	printf("This is the lex of %s\n", infilename);
	yyin = fp;
	while (token = yylex())
		printToken(token, stdout);

	return 0;
}
