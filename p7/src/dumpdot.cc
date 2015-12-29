#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include "node.hh"
#include "dumpdot.hh"
#include "c1.tab.hh"

using namespace std;
//===----------------------------------------------------------------------===//
// Utilities in Dump DOT
//===----------------------------------------------------------------------===//

// There are two ways to create a dot node:
// 1. newNode(num, str1, str2, ...)
//    num corresponds to the number of strings
//    Each string will appear in the generated image as a port
//    All strings are char*
// 2. newNode(vec)
//    All elements of the vector are std::string
// newNode returns an integer, which is the number of the corresponding
// node in DOT file.

int DumpDOT::newNode(int num, ...) {
    va_list list;
    va_start(list, num);
    fprintf(fp, "    %d [label = \"", count);
    bool first = true;
    for (int i=0; i<num; i++) {
        char* st = va_arg(list, char*);
        if (!first)
            fprintf(fp, "|");
        first = false;
        if (st[0]=='<')
            fprintf(fp, "<%d> \\<", i);
        else
            fprintf(fp, "<%d> %s", i, st);
    }
    va_end(list);
    fprintf(fp, "\"];\n");
    return count++;
}

int DumpDOT::newNode(std::vector<std::string> list) {
    fprintf(fp, "    %d [label = \"", count);
    bool first = true;
    for (int i=0; i<list.size(); i++) {
        std::string st = list[i];
        if (!first)
            fprintf(fp, "|");
        first = false;
        fprintf(fp, "<%d> %s", i, st.c_str());
    }
    fprintf(fp, "\"];\n");
    return count++;
}

// Draw a line from nSrc node's pSrc port to nDst node.
// If you want it start from the whole node, let pSrc = -1

void DumpDOT::drawLine(int nSrc, int pSrc, int nDst) {
    fprintf(fp, "    %d", nSrc);
    if (pSrc>=0)
        fprintf(fp, ":%d", pSrc);
    fprintf(fp, " -> %d;\n", nDst);
}

//===----------------------------------------------------------------------===//
// Dump AST to DOT
//===----------------------------------------------------------------------===//

// The following functions convert AST to DOT using DumpDOT.
// Each dumpdot returns an integer, which is corresponding number in DOT file.
// 53+29*71 will become:
// digraph {
// node [shape = record];
//     0 [label = "<0> |<1> +|<2> "];
//     1 [label = "<0> 53"];
//     2 [label = "<0> |<1> *|<2> "];
//     3 [label = "<0> 29"];
//     4 [label = "<0> 71"];
//     0:0 -> 1;
//     0:2 -> 2;
//     2:0 -> 3;
//     2:2 -> 4;
// }

int NumNode::dumpdot(DumpDOT *dumper) {
    std::ostringstream strs;
    strs << val;
    int nThis = dumper->newNode(1, strs.str().c_str());
    return nThis;
}

int VarNode::dumpdot(DumpDOT *dumper) {
    int nThis;
    if (type == 1)
    {
        if (exp != NULL)
        {
            nThis = dumper->newNode(4, name->c_str(), "[", "exp", "]");
            int nexp = exp->dumpdot(dumper);
            dumper->drawLine(nThis, 2, nexp);
        }
        else 
        {
            nThis = dumper->newNode(2, name->c_str(), "[]");
        }
    }
    else 
        nThis = dumper->newNode(1, name->c_str());
    
    return nThis;
}

int BinaryExpNode::dumpdot(DumpDOT *dumper) {
    string temp;
    switch(op)
    {
        case PLUS: temp += '+'; break;
        case MINUS: temp += '-'; break;
        case MULT: temp += '*'; break;
        case DIV: temp += '/'; break;
        case MOD: temp += '%'; break;
    }    
    int nThis = dumper->newNode(3, " ", temp.c_str(), " ");
    int nlhs = lhs->dumpdot(dumper);
    int nrhs = rhs->dumpdot(dumper);
    dumper->drawLine(nThis, 0, nlhs);
    dumper->drawLine(nThis, 2, nrhs);
    return nThis;
}

int UnaryExpNode::dumpdot(DumpDOT *dumper) {
    string temp;
    switch(op)
    {
        case PLUS: temp += '+'; break;
        case MINUS: temp += '-'; break;
        case MULT: temp += '*'; break;
        case DIV: temp += '/'; break;
        case MOD: temp += '%'; break;
    }    
    int nThis = dumper->newNode(2, temp.c_str(), " ");
    int nOperand = operand->dumpdot(dumper);
    dumper->drawLine(nThis, 1, nOperand);
    return nThis;
}

int AsgnNode::dumpdot(DumpDOT *dumper) {
    int nThis = dumper->newNode(2, "name", "exp");
    int nVar = var->dumpdot(dumper);
    int nExp = exp->dumpdot(dumper);
    dumper->drawLine(nThis, 0, nVar);
    dumper->drawLine(nThis, 1, nExp);
    return nThis;
}

int ConstINTNode::dumpdot(DumpDOT *dumper) 
{
	int nThis = dumper->newNode(3, "name", "=", "exp");
	int nname = var->dumpdot(dumper);
	int nexp = val->dumpdot(dumper);
	dumper->drawLine(nThis, 0, nname);
	dumper->drawLine(nThis, 2, nexp);
	return nThis;
}

int ConstARRAYNode::dumpdot(DumpDOT *dumper)
{
    int nThis = dumper->newNode(3, "name", "=", "exp");
    int nname = var->dumpdot(dumper);
	dumper->drawLine(nThis, 0, nname);
	for (int i = 0; i < val.size(); i++)
    {
        int temp = val[i]->dumpdot(dumper);
        dumper->drawLine(nThis, 2, temp);
    }
    return nThis;
}

int VarINTNode::dumpdot(DumpDOT *dumper)
{
    int nname = var->dumpdot(dumper);
    int nThis;
    if (isInitialized)
    {
        nThis = dumper->newNode(3, "name", "=", "exp");
        int nexp = val->dumpdot(dumper);
        dumper->drawLine(nThis, 2, nexp);
    }
    else 
        nThis = dumper->newNode(1, "name");
    
    dumper->drawLine(nThis, 0, nname);
    return nThis;
}

int VarARRAYNode::dumpdot(DumpDOT *dumper)
{
    int nname = var->dumpdot(dumper);
    int nThis;
    if (isInitialized)
    {
        nThis = dumper->newNode(3, "name", "=", "exp");
        for (int i = 0; i < val.size(); i++)
        {
            int temp = val[i]->dumpdot(dumper);
            dumper->drawLine(nThis, 2, temp);
        }
    }
    else 
        nThis = dumper->newNode(1, "name");
    dumper->drawLine(nThis, 0, nname);
    return nThis;
}

int ConstDeclNode::dumpdot(DumpDOT *dumper)
{
    int nThis = dumper->newNode(3, "const", "int", "def");
    for (int i = 0; i < decl.size(); i++)
    {
        int temp = decl[i]->dumpdot(dumper);
        dumper->drawLine(nThis, 2, temp);
    }
    return nThis;
}

int VarDeclNode::dumpdot(DumpDOT *dumper)
{
    int nThis = dumper->newNode(2, "int", "def");
    for (int i = 0; i < decl.size(); i++)
    {
        int temp = decl[i]->dumpdot(dumper);
        dumper->drawLine(nThis, 1, temp);
    }
    return nThis;
}

int CondNode::dumpdot(DumpDOT *dumper)
{
    string oper;
    switch(op)
    {
        case ISEQ: oper += "=="; break;
        case GT: oper += "\\>"; break;
        case LT: oper += "\\<"; break;
        case LE: oper += "\\<="; break;
        case GE: oper += "\\>="; break;
        case NE: oper += "!="; break;
        case NOT: oper += "!"; break;
        case AND: oper += "&&"; break;
        case OR: oper += "||"; break;
        default: oper += " ";
    }
    int left = lhs->dumpdot(dumper);
    int right;
    if (rhs != NULL)
        right = rhs->dumpdot(dumper);
    int nThis = dumper->newNode(3, "exp", oper.c_str(), "exp");
    dumper->drawLine(nThis, 0, left);
    if (rhs != NULL)
        dumper->drawLine(nThis, 2, right);
    return nThis;
}

int WhileStmtNode::dumpdot(DumpDOT *dumper)
{
    int ncond = cond->dumpdot(dumper);
    int nstmt = stmt->dumpdot(dumper);
    int nThis = dumper->newNode(3, "while", "cond", "block");
    dumper->drawLine(nThis, 1, ncond);
    dumper->drawLine(nThis, 2, nstmt);
    return nThis;
}

int IfStmtNode::dumpdot(DumpDOT *dumper)
{
    int ncond = cond->dumpdot(dumper);
    int nthen = then->dumpdot(dumper);
    int nThis;
    if (!haveElse)
        nThis = dumper->newNode(3, "if", "cond", "stmt");
    else
    {
        nThis = dumper->newNode(5, "if", "cond", "stmt", "else", "stmt");
        int nelse = Else->dumpdot(dumper);
        dumper->drawLine(nThis, 4, nelse);
    }
    dumper->drawLine(nThis, 1, ncond);
    dumper->drawLine(nThis, 2, nthen);
    return nThis;   
} 

int FuncCallNode::dumpdot(DumpDOT *dumper)
{
    int nThis = dumper->newNode(2, "name", "()");
    int nname = dumper->newNode(1, name->c_str());
    dumper->drawLine(nThis, 0, nname);
    return nThis;
}

int EmptyNode::dumpdot(DumpDOT *dumper)
{
    return 0;
}

int BlockNode::dumpdot(DumpDOT *dumper)
{
    int nThis = dumper->newNode(2, "decl", "stmts");
    for (int i = 0; i < decl.size(); i++)
    {
        int temp = decl[i]->dumpdot(dumper);
        dumper->drawLine(nThis, 0, temp);
    }
    for (int i = 0; i < stmts.size(); i++)
    {
        int temp = stmts[i]->dumpdot(dumper);
        dumper->drawLine(nThis, 1, temp);
    }
    return nThis;
}

int FuncDefNode::dumpdot(DumpDOT *dumper)
{
    int nThis = dumper->newNode(3, name->c_str(), "()", "block");
    int nblock = block->dumpdot(dumper);
    dumper->drawLine(nThis, 2, nblock);
    return nThis;    
}

int ExternFuncNode::dumpdot(DumpDOT *dumper)
{
    return dumper->newNode(3, "extern", name->c_str(), "()");
}

int ExternDeclNode::dumpdot(DumpDOT *dumper)
{
    int nThis = dumper->newNode(3, "extern", "int", "decl");
    for (auto i : decl)
    {
    	int temp = i->dumpdot(dumper);
    	dumper->drawLine(nThis, 2, temp);
    }
    return nThis;
}

int CompUnitNode::dumpdot(DumpDOT *dumper)
{
    int nThis = dumper->newNode(2, "decl", "func");
    for (int i = 0; i < decl.size(); i++)
    {
        int temp = decl[i]->dumpdot(dumper);
        dumper->drawLine(nThis, 0, temp);
    }
    for (int i = 0; i < func.size(); i++)
    {
        int temp = func[i]->dumpdot(dumper);
        dumper->drawLine(nThis, 1, temp);
    }
    return nThis;
}


