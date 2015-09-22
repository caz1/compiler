#include"token.h"


int main(int argc, char **argv){

	printf("please enter the source file name:");
	scanf("%s", infilename);
	if ( (infile=fopen(infilename, "r"))==NULL ) {
		printf("File %s can't be opened.\n", infilename);
		exit(1);
	}
	extern FILE* yyin;
	yyin = infile;

