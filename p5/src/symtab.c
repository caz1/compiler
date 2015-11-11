/*
 * Functions of Symbolic Table
 * Author: Yu Zhang (yuzhang@ustc.edu.cn)
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <common.h>
/**
 * Creates a symbolic table
 */
Table
newTable()
{
	Table new;
	NEW0(new);
	return new;
}

static void
destroyBucket(Entry *list)
{
	Entry node = *list, temp;
	while ( node != NULL ) {
		temp = node->next;
		free(node);
		node = temp;
	}
	*list = NULL;
}

/**
 * Destroys the specified table
 */
void
destroyTable(Table *tab)
{
	int i=0;
	if (*tab == NULL)
		return;
	Entry *bucket = (*tab)->buckets, *bucket_end = (*tab)->buckets+256;
	while (bucket < bucket_end ) {
		destroyBucket(bucket);
		bucket++;
	}
	free(*tab);
	*tab = NULL;
}

// Look up the symbolic table to get the symbol with specified name
Symbol
lookupvar(Table ptab, const char *name)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next)
		if (pent->kind == INt && strcmp(name, pent->sym->name) == 0)
			return pent->sym;
	return NULL;
}

arraySymbol 
lookuparray(Table tab, const char *name)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	for (pent = tab->buckets[hashkey]; pent != NULL; pent = pent->next)
		if (pent->kind == ARRAY && strcmp(name, pent->asym->name) == 0)
			return pent->asym;
	return NULL;
}

funcSymbol
lookupfunc(Table tab, const char *name)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE - 1);
	for (pent = tab->buckets[hashkey]; pent != NULL; pent = pent->next)
		if (pent->kind == FUNC && strcmp(name, pent->fsym->name) == 0)
			return pent->fsym;
	return NULL;
}


Entry 
lookup(Table tab, const char *name, int type)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE - 1);
	for (pent = tab->buckets[hashkey]; pent != NULL; pent = pent->next)
		if (pent->kind == type)
			if (type == INt && strcmp(name, pent->sym->name) == 0)
				return pent;
			else if (type == ARRAY && strcmp(name, pent->asym->name) == 0)
				return pent;
			else if (type == FUNC && strcmp(name, pent->fsym->name) == 0)
				return pent;
	return NULL;
}



// Get value of the specified name from the symbolic table
int *
getVal(Table ptab, const char *name, int *size)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next)
		if ( strcmp(name, pent->sym->name) == 0 ) 
		{

			return pent->sym->val;
		}
	NEW0(pent);
	int *temp = (int *)malloc(sizeof(int));
	temp[0] = 0;
	pent->sym->name = (char *)name;
	pent->sym->val = temp;
	pent->kind = INt; //set as int
	//pent->sym->size = 1;
	*size = 1;
	printf("Warn: %s(%d) was not initialized before, set it 0 as default\n",
		(char *)name, hashkey);
	pent->next = ptab->buckets[hashkey];
	ptab->buckets[hashkey] = pent;
	return 0;
}

Symbol
getSym(Table ptab, const char *name)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next)
		if (pent->kind == INt && strcmp(name, pent->sym->name) == 0) 
			return pent->sym;
	NEW0(pent);
	Symbol new;
	NEW0(new);
	pent->sym = new;
	pent->kind = INt;
	pent->sym->exp = NULL;
	pent->sym->name = (char *)name;
	//pent->sym->val = 0; // initial with 0
	pent->sym->isInitial = 0;
	pent->next = ptab->buckets[hashkey];
	ptab->buckets[hashkey] = pent;
	return pent->sym;
}


arraySymbol 
getaSym(Table tab, const char *name)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE - 1);
	for (pent = tab->buckets[hashkey]; pent != NULL; pent = pent->next)
		if (pent->kind == ARRAY && strcmp(name, pent->asym->name) == 0)
			return pent->asym;
	NEW0(pent);
	arraySymbol new;
	NEW0(new);
	pent->asym = new;
	pent->kind = ARRAY;
	pent->asym->name = (char *)name;
	//pent->asym->val = temp;
	pent->asym->exp = NULL;
	pent->asym->isInitial = 0;
	pent->asym->sizeInitial = 0;
	//pent->asym->size = 0;
	pent->next = tab->buckets[hashkey];
	tab->buckets[hashkey] = pent;
	return pent->asym;
}

funcSymbol 
getfSym(Table tab, const char *name)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE - 1);
	for (pent = tab->buckets[hashkey]; pent != NULL; pent = pent->next)
		if (pent->kind == FUNC && strcmp(name, pent->fsym->name) == 0)
			return pent->fsym;
	NEW0(pent);
	funcSymbol new;
	NEW0(new);
	pent->fsym = new;
	pent->kind = FUNC;
	pent->fsym->name = (char *)name;
	pent->next = tab->buckets[hashkey];
	tab->buckets[hashkey] = pent;
	return pent->fsym;
}

// Set value of the specified name into the symbolic table
Symbol
setVal(Table ptab, const char *name, int val)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next) {
		if ( strcmp(name, pent->sym->name) == 0 ) {
			pent->sym->val = val;
#if DEBUG
			printf("update %s(%d)  %f\n", 
				(char *)name, hashkey, val);
#endif
			return pent->sym;
		}
	}
	NEW0(pent);
	Symbol new;
	NEW0(new);
	pent->kind = INt;
	pent->sym = new;
	pent->sym->name = (char *)name;
	pent->sym->val = val;
#if DEBUG
	printf("create %s(%d) %f\n", (char *)name, 
		hashkey, val);
#endif
	pent->next = ptab->buckets[hashkey];
	ptab->buckets[hashkey] = pent;
	return pent->sym;
}

Entry 
newINTEntry(Table tab, const char *name, int isInitial, ASTNode exp)
{
	Entry pent;
	NEW0(pent);
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	pent->kind = INt;
	Symbol sym;
	NEW0(sym);
	pent->sym = sym;
	pent->sym->name = name;
	pent->sym->isInitial = isInitial;
	pent->sym->exp = exp;
	pent->next = tab->buckets[hashkey];
	tab->buckets[hashkey] = pent;
	return pent;
}

Entry 
newArrayEntry(Table tab, const char *name, int sizeInitial, List exp)
{
	Entry pent;
	NEW0(pent);
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	pent->kind = ARRAY;
	arraySymbol sym;
	NEW0(sym);
	pent->asym = sym;
	pent->asym->name = name;
	pent->asym->isInitial = ((sizeInitial && exp->size == 1) || \
	                            (!sizeInitial && exp->size == 0)) ? 0 : 1;
	pent->asym->sizeInitial = sizeInitial;
	pent->asym->exp = exp;
	pent->next = tab->buckets[hashkey];
	tab->buckets[hashkey] = pent;
	return pent;
}

Entry 
newFuncEntry(Table tab, const char *name)
{
	Entry pent;
	NEW0(pent);
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	pent->kind = INt;
	funcSymbol sym;
	NEW0(sym);
	pent->fsym = sym;
	pent->fsym->name = name;
	pent->next = tab->buckets[hashkey];
	tab->buckets[hashkey] = pent;
	return pent;
}




