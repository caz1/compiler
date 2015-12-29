#ifndef _GLOBAL_HH_
#define _GLOBAL_HH_

#include "err.hh"
#include "llvmhead.hh"

extern char *infile_name;
extern char *outfile_name;
extern char *dumpfile_name;
extern FILE *infp;
extern FILE *outfp;
extern FILE *dumpfp;
extern map<string, tabelem> table;
extern map<string, Function*> functab;
extern ErrFactory errfactory;
extern IRBuilder<> Builder;
extern Module *mod;
extern vector<pair<string, tabelem>> oldVal;
#endif
