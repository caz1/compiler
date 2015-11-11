/*
 * Functions of Error Messages and their Container
 * Author: Yu Zhang (yuzhang@ustc.edu.cn)
 * Modified by CAZ@USTC
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

char *errmsgs[] = {
#undef errxx
#define errxx(a, b) b,
#include "errcfg.h"
	"Other Errors"
};

/**
 * Creates an error message and inserts it into the error list 
 * of the specified error factory
 */
Errmsg
newError(ErrFactory errfactory, int type, int line, int col, char *filename)
{
	Errmsg new;
	NEW0(new);
	new->isWarn = FALSE;
	new->type = type;
	new->msg = errmsgs[type];
	new->line = line;	
	new->column = col;
	strcpy(new->filename, filename);
	listaddItem(errfactory->errors, new);	
	return new;
}

/**
 * Creates a warning message and inserts it into the warning list 
 * of the specified error factory
 */
Errmsg
newWarning(ErrFactory errfactory, int type, int line, int col, char *filename)
{
	Errmsg new;
	NEW0(new);
	new->isWarn = TRUE;
	new->type = type;
	new->msg = errmsgs[type];
	new->line = line;	
	new->column = col;
	strcpy(new->filename, filename);
	listaddItem(errfactory->warnings, new);	
	return new;
}

/**
 * Destroy an error/warning message.
 */
void
destroyErrmsg(Errmsg *msg)
{
	if (*msg == NULL) return;
	free(*msg);
	*msg = NULL;
}

/**
 * Get one line in fp
 */
void fgetline(char *str, FILE *fp)
{
	int i = 0;
	char c = fgetc(fp);

	while (c != EOF && c != '\n')
	{
		str[i++] = c;
		c = fgetc(fp);
	}
	str[i] = '\0';
}
	

/**
 * Dumps an error message
 */
void
dumpErrmsg(Errmsg error)
{
	int i = 0;
	size_t len = 0;
	FILE *fp= fopen(error->filename, "r");
	char c, *str = (char *)malloc(500 * sizeof(char));
	if ( error->isWarn )
		printf("\033[1;31;40mWarning\033[0m");
	else
		printf("\033[1;31;40mError\033[0m");
	printf(" in file \033[1;33;40m%s\033[0m @(%d, %d): %s\n", error->filename, error->line, error->column, error->msg);
	for (i = 0, fgetline(str, fp); i < error->line - 1; i++, fgetline(str, fp));	
	printf("%s\n", str);
	
	for (i = 0; i < error->column - 1; i++)
		if (str[i] == '\t')
			printf("\t");
		else 
			printf(" ");
	printf("\033[1;34;40m^\033[0m\n");
	free(str);
}

ErrFactory
newErrFactory()
{
	ErrFactory new;
	NEW(new);
	new->errors = newList();
	new->warnings = newList();
	return new;
}

/**
 * Dumps all error messages
 */
void
dumpErrors(ErrFactory errfactory)
{
	List errors = errfactory->errors;
	int i = 0, size = errors->size;
	if (size > 0)	
		printf("\nFound %d errors at least:\n", 
			size);
	
	ListItr itr = getGListItr(errors, 0);
	
	Errmsg msg;
	while( hasNext(itr) ) {
		msg = (Errmsg)nextItem(itr);
		dumpErrmsg(msg);
	}
}

void
dumpWarnings(ErrFactory errfactory)
{
	List warns = errfactory->warnings;
	int i = 0, size = warns->size;
	if (size > 0)
		printf("\nFound %d warnings at least:\n", 
			size);
	
	ListItr itr = getGListItr(warns, 0);
	
	Errmsg msg;
	while( hasNext(itr) ) {
		msg = (Errmsg)nextItem(itr);
		dumpErrmsg(msg);
	}
}

/**
 * Destroys the specified error factory
 */
void
destroyErrFactory(ErrFactory *errfact)
{
	destroyList(&(*errfact)->errors, &destroyErrmsg);
	destroyList(&(*errfact)->warnings, &destroyErrmsg);
	free(*errfact);
	*errfact = NULL;
}
