#include "node.hh"
#include "c1.tab.hh"
#include "global.hh"
#include "err.hh"

int NumNode::cal() { return val; }

int BinaryExpNode::cal() 
{
    int l = lhs->cal();
    int r = rhs->cal();
    if (l == 0x7fffffff || r == 0x7fffffff) 
        return 0x7fffffff;
    switch(op)
    {
        case(PLUS): return l+r;
        case(MINUS): return l-r;
        case(MULT): return l*r;
        case(DIV): return l/r;
        case(MOD): return l%r;
        default: return 0x7fffffff;
    }
} 

int UnaryExpNode::cal()
{
    int l = operand->cal();
    if (l == 0x7fffffff) return l;
    switch(op)
    {
        case(PLUS): return l;
        case(MINUS): return -l;
        default: return 0x7fffffff;
    }
}

int VarNode::cal()
{
    if (table.find(*name) == table.end())
    {
        errfactory.append(new errmsg(UndefinedVar, \
        loc->first_line, loc->first_column, infile_name, false));
        return 0x7fffffff;
    }
    if (!table[*name].isConst) 
    {
        errfactory.append(new errmsg(InitWithUNCONST, \
        loc->first_line, loc->first_column, infile_name, false));
        return 0x7fffffff;
    }
    else if (table[*name].type == 0)
        return table[*name].value->at(0);
    else 
    {
        int i = exp->cal();
        if (i != 0x7fffffff && i < table[*name].value->size())
            return table[*name].value->at(i);   
        return 0x7fffffff;    
    }
}
