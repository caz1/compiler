#ifndef _ERR_HH_
#define _ERR_HH_

#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "node.hh"
using namespace std;


enum {
#define errxx(a, b) a,
#include "errcfg.hh"
	LASTERR
};

class errmsg {
public:
    bool isWarn;
    int type;
    int line;
    int column;
    string msg;
    string filename;
    errmsg(int type, int line, int column, string filename, bool isWarn);
    void dumpErr();
    
};

class ErrFactory {
public:
    vector<errmsg*> error, warning;
    ErrFactory() {}
    void dump();
    void clear() {error.clear(); warning.clear();}
    void append(errmsg *err) 
    {
        if(err->isWarn) 
            warning.push_back(err); 
        else 
        error.push_back(err);
    }
};

#endif
