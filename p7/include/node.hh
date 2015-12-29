#ifndef _NODE_HH_
#define _NODE_HH_

#include <stdio.h>
#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>
#include "dumpdot.hh"
#include "llvmhead.hh"
#define debug(a) 
using namespace std;

typedef enum {
    NUM,
    VAR,
    ASGN,
    EXP,
    BINARYEXP,
    UNARYEXP,
    BLOCK,
    COND,
    WHILESTMT,
    IFSTMT,
    FUNCDEF,
    CONSTINT,
    CONSTARRAY,
    VARINT,
    VARARRAY,
    CONSTDECL,
    VARDECL,
    EXTERNDECL,
    FUNCALL,
    EMPTY,
    EXTERNF,
    BRK,
    CTN,
    COMPUNIT
} NodeType;

typedef struct {
    int first_line;
    int first_column;
    int last_line;
    int last_column;
} *Loc;

typedef struct {
    Value *alloc;
    int type;
    bool isConst;
    int BlockDepth;
    vector<int> *value;
} tabelem;


class Node {
public:
    NodeType type;
    Loc loc;
    Node() {loc = (Loc)malloc(sizeof(int) * 4);}
    virtual ~Node() { free(loc); }
    virtual Value *Codegen() = 0;
    void setLoc(Loc loc) {memcpy(this->loc, loc, sizeof(int) * 4);}
    virtual int dumpdot(DumpDOT *dumper) = 0;
};


class ExpNode : public Node {
public:
    virtual int dumpdot(DumpDOT *dumper) = 0;
    virtual Value *Codegen() = 0;
    virtual void Codegen(BasicBlock*, BasicBlock*) {}
    virtual int cal() {return 0;}
};

class VarNode : public ExpNode {
public:
    string *name;
    int Type; 
    ExpNode *exp;
    VarNode(string* name, int type, ExpNode *exp) : name(name), Type(type), exp(exp) { this->type = VAR; };
    ~VarNode() { delete name; delete exp; }
    Value *Codegen();
    int cal();
    int dumpdot(DumpDOT *dumper);
};


class DeclNode : public Node {
public:
    virtual int dumpdot(DumpDOT *dumper) = 0;
    virtual Value* CodegenGlobal() = 0;
};

class ConstDefNode : public Node {
public:
    VarNode *var;
    ConstDefNode(VarNode *var) : var(var){}
    ~ConstDefNode() { delete var; }
    virtual int dumpdot(DumpDOT *dumper) = 0;
    virtual Value *CodegenGlobal() = 0;
};

class ConstINTNode : public ConstDefNode {
public:
    ExpNode *val;
    ConstINTNode(ExpNode *val, VarNode *var) : val(val), ConstDefNode(var) \
        { type = CONSTINT; }
    ~ConstINTNode() { delete val; }
    Value *Codegen();
    Value *CodegenGlobal();
    int dumpdot(DumpDOT *dumper);
};

class ConstARRAYNode : public ConstDefNode {
public:
    vector<ExpNode*> val;
    ConstARRAYNode(vector<ExpNode*> val, VarNode *var) : val(val), ConstDefNode(var) \
        { type = CONSTARRAY; }
    ~ConstARRAYNode() { for (int i = 0; i < val.size(); i++) delete val[i]; }
    Value *Codegen();
    Value *CodegenGlobal();
    int dumpdot(DumpDOT *dumper);
};

class VarDefNode : public Node {
public:
    VarNode *var;
    VarDefNode(VarNode *var) : var(var){}
    ~VarDefNode() { delete var; }
    virtual int dumpdot(DumpDOT *dumper) = 0;
    virtual Value *CodegenGlobal() = 0;
    virtual Value *CodegenGlobal(bool) = 0;
};

class VarINTNode : public VarDefNode {
public:
    bool isInitialized;
    ExpNode *val;
    VarINTNode(VarNode *var, bool isInitialized, ExpNode *val) \
        : isInitialized(isInitialized), val(val), VarDefNode(var) \
        { type = VARINT;}
    ~VarINTNode() { delete val; }
    Value *Codegen();
    Value *CodegenGlobal();
    Value *CodegenGlobal(bool);
    int dumpdot(DumpDOT *dumper);  
};

class VarARRAYNode : public VarDefNode {
public:
    bool isInitialized;
    vector<ExpNode*> val;
    VarARRAYNode(VarNode *var, bool isInitialized, vector<ExpNode*> val) \
        : isInitialized(isInitialized), val(val), VarDefNode(var)  \
        { type = VARARRAY; }
    ~VarARRAYNode() {for (int i = 0; i < val.size(); i++) delete val[i]; }
    Value *Codegen();
    Value *CodegenGlobal();
    Value *CodegenGlobal(bool);
    int dumpdot(DumpDOT *dumper);  
};

class ConstDeclNode : public DeclNode {
public:
    vector<ConstDefNode*> decl;
    ConstDeclNode() { type = CONSTDECL; }
    ConstDeclNode(vector<ConstDefNode*> Decl) : decl(Decl) { type = CONSTDECL; }
    ~ConstDeclNode() { for (int i = 0; i < decl.size(); i++) delete decl[i]; }
    Value *Codegen();
    Value *CodegenGlobal();
    int dumpdot(DumpDOT *dumper);
    void append(ConstDefNode *def) { decl.push_back(def); }
};

class VarDeclNode : public DeclNode {
public:
    vector<VarDefNode*> decl;
    VarDeclNode() { type = VARDECL; }
    VarDeclNode(vector<VarDefNode*> def) : decl(def){ type = VARDECL; }
    ~VarDeclNode() { for (auto i : decl) delete i; }
    Value *Codegen();
    Value *CodegenGlobal();
    int dumpdot(DumpDOT *dumper);
    void append(VarDefNode *def) { decl.push_back(def); }
};

class ExternDeclNode : public DeclNode {
public:
    vector<VarDefNode*> decl;
    ExternDeclNode() { type = EXTERNDECL; }
    ExternDeclNode(vector<VarDefNode*> def) : decl(def){ type = EXTERNDECL; }
    ~ExternDeclNode() { for (auto i : decl) delete i; }
    Value *Codegen();
    Value *CodegenGlobal() { return this->Codegen(); }
    int dumpdot(DumpDOT *dumper);
    void append(VarDefNode *def) { decl.push_back(def); }
};


class NumNode : public ExpNode {
public:
    int val;
    NumNode(int val) : val(val) { type = NUM; }
    Value *Codegen();
    int cal();
    int dumpdot(DumpDOT *dumper);
};

class BinaryExpNode : public ExpNode {
public:
    int op;
    ExpNode *lhs, *rhs;
    BinaryExpNode(int op, ExpNode *lhs, ExpNode *rhs) : op(op), lhs(lhs), rhs(rhs) { type = BINARYEXP; }
    ~BinaryExpNode() { delete lhs; delete rhs; }
    int cal();
    Value *Codegen();
    int dumpdot(DumpDOT *dumper);
};

class UnaryExpNode : public ExpNode {
public:
    int op;
    ExpNode *operand;
    UnaryExpNode(int op, ExpNode *operand) : op(op), operand(operand) { type = UNARYEXP; }
    ~UnaryExpNode() {delete operand; }
    int cal();
    Value *Codegen();
    int dumpdot(DumpDOT *dumper);
};

class CondNode : public ExpNode {
public:
    int op;
    ExpNode *lhs, *rhs;
    CondNode(int op, ExpNode *lhs, ExpNode *rhs) : op(op), lhs(lhs), rhs(rhs) { type = COND; }
    ~CondNode() {delete lhs; delete rhs;}
    Value *Codegen();
    void Codegen(BasicBlock*, BasicBlock*);
    int dumpdot(DumpDOT *dumper);
};


class StmtNode : public Node {
public:
    virtual int dumpdot(DumpDOT *dumper) = 0;    
    virtual Value *Codegen(BasicBlock*, BasicBlock*) = 0;
    virtual Value *Codegen() = 0;
};

class BreakNode : public StmtNode {
public:
    BreakNode() { type = BRK; }
    Value *Codegen() { return 0; }
    Value *Codegen(BasicBlock*, BasicBlock*);
    int dumpdot(DumpDOT *dumper) { return 0; }
};

class ContinueNode : public StmtNode {
public:
    ContinueNode() { type = CTN; }
    Value *Codegen() { return 0; }
    Value *Codegen(BasicBlock*, BasicBlock*);
    int dumpdot(DumpDOT *dumper) { return 0; }
};

class AsgnNode : public StmtNode {
public:
    VarNode *var;
    ExpNode *exp;
    AsgnNode(VarNode *var, ExpNode *exp) : var(var), exp(exp) { type = ASGN; };
    ~AsgnNode() {delete var; delete exp;}
    Value *Codegen();
    Value *Codegen(BasicBlock *condbb, BasicBlock *endbb) {return this->Codegen();}
    int dumpdot(DumpDOT *dumper);
};


class WhileStmtNode : public StmtNode {
public:
    CondNode *cond;
    StmtNode *stmt;
    WhileStmtNode(CondNode *cond, StmtNode *stmt) : cond(cond), stmt(stmt) { type = WHILESTMT; } 
    ~WhileStmtNode() {delete cond; delete stmt; }
    Value *Codegen();
    Value *Codegen(BasicBlock*, BasicBlock*);
    int dumpdot(DumpDOT *dumper);    
};

class IfStmtNode : public StmtNode {
public:
    CondNode *cond;
    StmtNode *then, *Else;
    bool haveElse;
    IfStmtNode(CondNode *cond, StmtNode *then, StmtNode *Else) \
        : cond(cond), then(then), Else(Else) \
        { type = IFSTMT; if (Else) haveElse = true; else haveElse = false;}
    ~IfStmtNode() { delete cond; delete then; delete Else;}
    Value *Codegen();
    Value *Codegen(BasicBlock*, BasicBlock*);
    int dumpdot(DumpDOT *dumper);  
};

class FuncCallNode : public StmtNode {
public:
    string *name;
    FuncCallNode(string *name) : name(name) { type = FUNCALL; }
    ~FuncCallNode() {delete name;}
    Value *Codegen();
    Value *Codegen(BasicBlock *condbb, BasicBlock *endbb) {return this->Codegen();}
    int dumpdot(DumpDOT *dumper);
};

 
class EmptyNode : public StmtNode {
public:
    EmptyNode() { type = EMPTY; }
    Value *Codegen(); 
    Value *Codegen(BasicBlock *condbb, BasicBlock *endbb) {return this->Codegen();}
    int dumpdot(DumpDOT *dumper);
};

class BlockNode : public StmtNode {
public:
    vector<DeclNode*> decl;
    vector<StmtNode*> stmts;
    BlockNode() { type = BLOCK; }
    ~BlockNode()
    {
        for (int i = 0; i < decl.size(); i++)
            delete decl[i];
        for (int i = 0; i < stmts.size(); i++)
            delete stmts[i];
    }
    Value *Codegen();
    Value *Codegen(BasicBlock*, BasicBlock*);
    int dumpdot(DumpDOT *dumper);
    void append(DeclNode *Decl) { decl.push_back(Decl); }
    void append(StmtNode *stmt) { stmts.push_back(stmt); }
};

class ExternFuncNode : public Node {
public:
    string *name;
    ExternFuncNode(string *name) : name(name) { type = EXTERNF; }
    ~ExternFuncNode() { delete name; }
    virtual Value *Codegen();
    virtual int dumpdot(DumpDOT *dumper);
};

class FuncDefNode : public ExternFuncNode {
public:
    BlockNode *block;
    FuncDefNode(string *name, BlockNode *block) : ExternFuncNode(name), block(block) { type = FUNCDEF; }
    ~FuncDefNode()
    {
        delete block;
    }
    Value *Codegen();
    int dumpdot(DumpDOT *dumper);    
};


class CompUnitNode :public Node {
public:
    vector<DeclNode*> decl;
    vector<ExternFuncNode*> func;
    CompUnitNode() { type = COMPUNIT; }
    ~CompUnitNode()
    {
    	for (int i = 0; i < decl.size(); i++)
    	    delete decl[i];
    	for (int i = 0; i < func.size(); i++)
    	    delete func[i];
    }
    Value *Codegen();
    int dumpdot(DumpDOT *dumper);
    void append(DeclNode *Decl) { decl.push_back(Decl); }
    void append(ExternFuncNode *Func) { func.push_back(Func); }    
};
#endif
