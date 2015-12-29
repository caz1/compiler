#include "node.hh"
#include "global.hh"
#include "c1.tab.hh"

int BlockDepth = 0;

Value *VarNode::Codegen()
{
    if (Type == 0)
    {
        Value *val = table[*name].alloc;
        if (val == 0) return 0;
        return val;
    }
    else 
    {
        Value *val = table[*name].alloc;
        if (val == 0) return 0;
        vector<Value*> Idx;
        Idx.push_back(ConstantInt::get(mod->getContext(), APInt(32, 0)));
        Value *idx = exp->Codegen();
        if (idx == 0) return 0;
        if (exp->type == VAR) idx = Builder.CreateLoad(idx, "loadtemp");
        Idx.push_back(idx);
        return Builder.CreateGEP(val, Idx, name->c_str());
    }
}


Value *ConstINTNode::Codegen()
{
    AllocaInst *Alloca = Builder.CreateAlloca(IntegerType::get(mod->getContext(), 32), 0, var->name->c_str());
    int Val = val->cal();
    if (Val == 0x7fffffff) return 0;
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = Alloca;
    temp.isConst = true;
    temp.type = 0;
    temp.BlockDepth = BlockDepth;
    temp.value = new vector<int>(Val);
    table[*(var->name)] = temp;
    Value* val_const= ConstantInt::get(mod->getContext(), APInt(32, Val, true));
    Builder.CreateStore(val_const, Alloca);
    return val_const;
}


Value *ConstINTNode::CodegenGlobal()
{
    GlobalVariable* gvar = new GlobalVariable(/*Module=*/*mod, 
    /*Type=*/IntegerType::get(mod->getContext(), 32),
    /*isConstant=*/true,
    /*Linkage=*/GlobalValue::ExternalLinkage,
    /*Initializer=*/0, 
    /*Name=*/var->name->c_str());
    int value = val->cal();
    if (value == 0x7fffffff) return 0;
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = gvar;
    temp.isConst = true;
    temp.type = 0;
    temp.BlockDepth = BlockDepth;
    temp.value = new vector<int>(value);
    table[*(var->name)] = temp;
    ConstantInt* Val = ConstantInt::get(mod->getContext(), APInt(32, value, true));
    gvar->setInitializer(Val);
    return Val;
}

Value *ConstARRAYNode::Codegen()
{
    int size;
    if (var->exp == NULL)
        size = val.size();
    else 
        size = var->exp->cal();
    if (size == 0x7fffffff) return 0;    
    ArrayType* ArrayTy = ArrayType::get(IntegerType::get(mod->getContext(), 32), size);
    AllocaInst *Alloca = Builder.CreateAlloca(ArrayTy, 0, var->name->c_str());
    vector<int> *value = new vector<int>();    
    {
        vector<Constant*> Val;

        for (int i = 0; i < size; i++)
        {
            if (i < val.size())
            {
                int a = val[i]->cal();
                if (a == 0x7fffffff) return 0;
                value->push_back(a);
                Val.push_back(ConstantInt::get(mod->getContext(), APInt(32, a, true)));
            }
            else 
            {
                Val.push_back(ConstantInt::get(mod->getContext(), APInt(32, 0, true)));
                value->push_back(0);
            }
        }
        vector<Value*> idx;
        idx.push_back(ConstantInt::get(mod->getContext(), APInt(32, 0)));
        int j = 0;
        for(auto i : Val)
        {
            idx.push_back(ConstantInt::get(mod->getContext(), APInt(32, j++)));
            auto temp = Builder.CreateGEP(Alloca, idx);
            idx.pop_back();
            Builder.CreateStore(i, temp);
        }
    }
    
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = Alloca;
    temp.isConst = true;
    temp.type = 1;
    temp.BlockDepth = BlockDepth;
    temp.value = value;
    table[*(var->name)] = temp;
    return Alloca;    
}


Value *ConstARRAYNode::CodegenGlobal()
{
    int size;
    if (var->exp == NULL)
        size = val.size();
    else 
        size = var->exp->cal();
    if (size == 0x7fffffff) return 0;
     ArrayType* ArrayTy = ArrayType::get(IntegerType::get(mod->getContext(), 32), size);
     GlobalVariable* gvar = new GlobalVariable(/*Module=*/*mod, 
    /*Type=*/ArrayTy,
    /*isConstant=*/true,
    /*Linkage=*/GlobalValue::ExternalLinkage,
    /*Initializer=*/0, // has initializer, specified below
    /*Name=*/var->name->c_str());
    vector<Constant*> Val;
    vector<int> *value = new vector<int>();
    for (int i = 0; i < size; i++)
    {
        if (i < val.size())
        {
            int a = val[i]->cal();
            if (a == 0x7fffffff) return 0;
            value->push_back(a);
            Val.push_back(ConstantInt::get(mod->getContext(), APInt(32, a, true)));
        }
        else 
        {
            Val.push_back(ConstantInt::get(mod->getContext(), APInt(32, 0, true)));
            value->push_back(0);
        }
    }
    Constant *ValList =  ConstantArray::get(ArrayTy, Val);
    gvar->setInitializer(ValList);
    
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = gvar;
    temp.isConst = true;
    temp.type = 1;
    temp.BlockDepth = BlockDepth;
    temp.value = value;
    table[*(var->name)] = temp;
    
    return gvar;       
}   

Value *NumNode::Codegen()
{
    return ConstantInt::get(getGlobalContext(), APInt(32, val, true));
}

Value *VarINTNode::Codegen()
{
    AllocaInst *Alloca = Builder.CreateAlloca(IntegerType::get(mod->getContext(), 32), 0, var->name->c_str());
    if (isInitialized)
    { 
        Value *Val = val->Codegen();
        Value *temp;
        if (Val == 0) return 0;
        if (val->type == VAR) temp = Builder.CreateLoad(Val, "loadtemp");
        else temp = Val;
        Builder.CreateStore(temp, Alloca);
    }
    
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = Alloca;
    temp.isConst = false;
    temp.type = 0;
    temp.BlockDepth = BlockDepth;
    temp.value = NULL;
    table[*(var->name)] = temp;
    
    return Alloca;
}
Value *VarINTNode::CodegenGlobal(bool isExtern)
{
    GlobalVariable* gvar = new GlobalVariable(/*Module=*/*mod, 
    /*Type=*/IntegerType::get(mod->getContext(), 32),
    /*isConstant=*/false,
    /*Linkage=*/GlobalValue::ExternalLinkage,
    /*Initializer=*/0, // has initializer, specified below
    /*Name=*/var->name->c_str());
    
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = gvar;
    temp.isConst = false;
    temp.type = 0;
    temp.BlockDepth = BlockDepth;
    temp.value = NULL;
    table[*(var->name)] = temp;
    
    return gvar;
}


Value *VarINTNode::CodegenGlobal()
{
    GlobalVariable* gvar = new GlobalVariable(/*Module=*/*mod, 
    /*Type=*/IntegerType::get(mod->getContext(), 32),
    /*isConstant=*/false,
    /*Linkage=*/GlobalValue::ExternalLinkage,
    /*Initializer=*/0, // has initializer, specified below
    /*Name=*/var->name->c_str());
    ConstantInt* Val;
    int value = 0;
    if (isInitialized)
    {
        value = val->cal();
        if (value == 0x7fffffff) return 0;
        Val = ConstantInt::get(mod->getContext(), APInt(32, value, true));
    }
    else 
        Val = ConstantInt::get(mod->getContext(), APInt(32, value, true));
    gvar->setInitializer(Val);
    
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = gvar;
    temp.isConst = false;
    temp.type = 0;
    temp.BlockDepth = BlockDepth;
    temp.value = NULL;
    table[*(var->name)] = temp;
    
    return Val;
}

Value *VarARRAYNode::Codegen()
{
    if (var->exp == NULL && !isInitialized)
    {
        errfactory.append(new errmsg(UninitializedArray, loc->last_line, loc->last_column, infile_name, false));
        return 0;
    }
    int size;
    if (var->exp == NULL)
        size = val.size();
    else
    {
        size = var->exp->cal();
        if (size == 0x7fffffff) return 0;
    }
    ArrayType* ArrayTy = ArrayType::get(IntegerType::get(mod->getContext(), 32), size);
    AllocaInst *Alloca = Builder.CreateAlloca(ArrayTy, 0, var->name->c_str());  
    
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = Alloca;
    temp.isConst = false;
    temp.type = 1;
    temp.BlockDepth = BlockDepth;
    temp.value = NULL;
    table[*(var->name)] = temp;
    
    if (isInitialized)
    {
        vector<Constant*> Val;
        vector<int> value;
        for (int i = 0; i < size; i++)
        {
            if (i < val.size())
            {
                int a = val[i]->cal();
                if (a == 0x7fffffff) return 0;
                value.push_back(a);
                Val.push_back(ConstantInt::get(mod->getContext(), APInt(32, a, true)));
            }
            else 
            {
                Val.push_back(ConstantInt::get(mod->getContext(), APInt(32, 0, true)));
                value.push_back(0);
            }
        }
        vector<Value*> idx;
        idx.push_back(ConstantInt::get(mod->getContext(), APInt(32, 0)));
        int j = 0;
        for(auto i : Val)
        {
            idx.push_back(ConstantInt::get(mod->getContext(), APInt(32, j++)));
            auto temp = Builder.CreateGEP(Alloca, idx);
            idx.pop_back();
            Builder.CreateStore(i, temp);
        }
    } 
    return Alloca;
}

Value *VarARRAYNode::CodegenGlobal()
{
    if (var->exp == NULL && !isInitialized)
    {
        errfactory.append(new errmsg(UninitializedArray, loc->last_line, loc->last_column, infile_name, false));
        return 0;
    }
    int size;
    if (var->exp == NULL)
        size = val.size();
    else
    {
        size = var->exp->cal();
        if (size == 0x7fffffff) return 0;
    }
    ArrayType* ArrayTy = ArrayType::get(IntegerType::get(mod->getContext(), 32), size);
    GlobalVariable* gvar = new GlobalVariable(/*Module=*/*mod, 
    /*Type=*/ArrayTy,
    /*isConstant=*/false,
    /*Linkage=*/GlobalValue::ExternalLinkage,
    /*Initializer=*/0, // has initializer, specified below
    /*Name=*/var->name->c_str());
    vector<Constant*> Val;
    vector<int> value;
    for (int i = 0; i < size; i++)
    {
        if (i < val.size())
        {
            int a = val[i]->cal();
            if (a == 0x7fffffff) return 0;
            value.push_back(a);
            Val.push_back(ConstantInt::get(mod->getContext(), APInt(32, a, true)));
        }
        else 
        {
            Val.push_back(ConstantInt::get(mod->getContext(), APInt(32, 0, true)));
            value.push_back(0);
        }
    }
    
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = gvar;
    temp.isConst = false;
    temp.type = 1;
    temp.BlockDepth = BlockDepth;
    temp.value = NULL;
    table[*(var->name)] = temp;
    
    Constant *ValList =  ConstantArray::get(ArrayTy, Val);
    gvar->setInitializer(ValList);
    return gvar;
}

Value *VarARRAYNode::CodegenGlobal(bool isExtern)
{
    if (var->exp == NULL && !isInitialized)
    {
        errfactory.append(new errmsg(UninitializedArray, loc->last_line, loc->last_column, infile_name, false));
        return 0;
    }
    int size;
    if (var->exp == NULL)
        size = val.size();
    else
    {
        size = var->exp->cal();
        if (size == 0x7fffffff) return 0;
    }
    ArrayType* ArrayTy = ArrayType::get(IntegerType::get(mod->getContext(), 32), size);
    GlobalVariable* gvar = new GlobalVariable(/*Module=*/*mod, 
    /*Type=*/ArrayTy,
    /*isConstant=*/false,
    /*Linkage=*/GlobalValue::ExternalLinkage,
    /*Initializer=*/0, // has initializer, specified below
    /*Name=*/var->name->c_str());
    
    if (table.find(*(var->name)) != table.end() && \
        table[*(var->name)].BlockDepth == BlockDepth) 
    {
        errfactory.append(new errmsg(RedefinedVar, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    else if (table.find(*(var->name)) != table.end()) 
    {
        oldVal.push_back(pair<string, tabelem>(*(var->name), table[*(var->name)]));
    }
    tabelem temp;
    temp.alloc = gvar;
    temp.isConst = false;
    temp.type = 1;
    temp.BlockDepth = BlockDepth;
    temp.value = NULL;
    table[*(var->name)] = temp;
    
    return gvar;
}

Value *ConstDeclNode::Codegen()
{
    for (auto i : decl)
    {
        Value *temp = i->Codegen();    
        if (temp == 0) return 0;
    }
    return ConstantInt::get(mod->getContext(), APInt(32, 1, true));    
}

Value *ConstDeclNode::CodegenGlobal()
{
    for (auto i : decl)
    {
        Value *temp = i->CodegenGlobal();    
        if (temp == 0) return 0;
    }
    return ConstantInt::get(mod->getContext(), APInt(32, 1, true));  
}


Value *VarDeclNode::CodegenGlobal()
{
    for (auto i : decl)
    {
        Value *temp = i->CodegenGlobal();    
        if (temp == 0) return 0;
    }
    return ConstantInt::get(mod->getContext(), APInt(32, 1, true));
}

Value *VarDeclNode::Codegen()
{
    for (auto i :decl)
    {
        Value *temp = i->Codegen();    
        if (temp == 0) return 0;
    }
    return ConstantInt::get(mod->getContext(), APInt(32, 1, true));
}


Value *BinaryExpNode::Codegen() 
{
    Value *l = lhs->Codegen();
    if (lhs->type == VAR) l = Builder.CreateLoad(l, "loadtemp");
    Value *r = rhs->Codegen();
    if (rhs->type == VAR) r = Builder.CreateLoad(r, "loadtemp");
    if (l == 0 || r == 0) return 0;
    
    switch(op)
    {
        case(PLUS): return Builder.CreateAdd(l, r, "addtemp");
        case(MINUS): return Builder.CreateSub(l, r, "subtemp");
        case(MULT): return Builder.CreateMul(l, r, "multemp");
        case(DIV): return Builder.CreateSDiv(l, r, "divtemp");
        case(MOD): return Builder.CreateSRem(l, r, "modtemp");
        default: return 0;
    }
}

Value *UnaryExpNode::Codegen()
{
    Value *l = operand->Codegen();
    if (l == 0) return 0;
    switch(op)
    {
        case(PLUS): return l;
        case(MINUS): return Builder.CreateNeg(l, "negtemp");
        default: return 0;
    }
}

Value *CondNode::Codegen()
{
    Value *l, *r;
    l = lhs->Codegen();
    if (lhs->type == VAR) l = Builder.CreateLoad(l, "loadtemp");
    if (l == 0) return 0;
    if (op != NOT)
    {
        r = rhs->Codegen();
        if (rhs->type == VAR) r = Builder.CreateLoad(r, "loadtemp");
        if (r == 0) return 0;
    }
    switch(op)
    {
        case(LT): return Builder.CreateICmpSLT(l, r, "LTtemp");
        case(ISEQ): return Builder.CreateICmpEQ(l, r, "EQtemp");
        case(LE): return Builder.CreateICmpSLE(l, r, "LEtemp");
        case(GT): return Builder.CreateICmpSGT(l, r, "GTtemp");
        case(GE): return Builder.CreateICmpSGE(l, r, "GEtemp");
        case(NE): return Builder.CreateICmpNE(l, r, "NEtemp");
        case(NOT): return Builder.CreateNot(l, "NOTtemp");
        default: return 0;
    }
}

void CondNode::Codegen(BasicBlock *bodybb, BasicBlock *endbb)
{
    Value *l, *r;
    Function *parent = Builder.GetInsertBlock()->getParent();   
    
    CondNode *lh = dynamic_cast<CondNode*>(lhs);
    CondNode *rh = dynamic_cast<CondNode*>(rhs);    
    if (op == AND)
    {
        BasicBlock *first = BasicBlock::Create(mod->getContext(), "cond1.true", parent);
        if (lh->op == AND || lh->op == OR)
            lhs->Codegen(bodybb, endbb);
        else
        { 
            l = lhs->Codegen();
            if (l == 0) return ;
            Builder.CreateCondBr(l, first, endbb);
        }
        Builder.SetInsertPoint(first);
        if (rh->op == AND || rh->op == OR)
            rhs->Codegen(bodybb, endbb);
        else
        {
            r = rhs->Codegen();
            if (r == 0) return ;
            Builder.CreateCondBr(r, bodybb, endbb);
        }            
    }
    else 
    {
        BasicBlock *first = BasicBlock::Create(mod->getContext(), "cond1.false", parent);
        if (lh->op == AND || lh->op == OR)
            lhs->Codegen(bodybb, endbb);
        else
        { 
            l = lhs->Codegen();
            if (l == 0) return ;
            Builder.CreateCondBr(l, bodybb, first);
        }
        Builder.SetInsertPoint(first);
        if (rh->op == AND || rh->op == OR)
            rhs->Codegen(bodybb, endbb);
        else
        {
            r = rhs->Codegen();
            if (r == 0) return ;
            Builder.CreateCondBr(r, bodybb, endbb);
        }  
    }
}

Value *AsgnNode::Codegen()
{
    Value *Var = var->Codegen();
    Value *Exp = exp->Codegen();
    if (Var == 0 || Exp == 0) return 0;
    if (exp->type == VAR) Exp = Builder.CreateLoad(Exp, "loadtemp");
    if (table[*(var->name)].isConst)
    {
        errfactory.append(new errmsg(AsgnConst, loc->first_line, loc->last_line, infile_name, false));
        return 0;
    }
    return Builder.CreateStore(Exp, Var);
}

Value *WhileStmtNode::Codegen() // todo
{
    Function *parent = Builder.GetInsertBlock()->getParent();

    BasicBlock *condbb = BasicBlock::Create(mod->getContext(), "while.cond", parent);
    BasicBlock *bodybb = BasicBlock::Create(mod->getContext(), "while.body", parent);
    BasicBlock *endbb = BasicBlock::Create(mod->getContext(), "while.end", parent);
    Builder.CreateBr(condbb);
    Builder.SetInsertPoint(condbb);
    if (cond->op == NOT || ((cond->lhs->type != COND) && (cond->rhs->type != COND)))
    {
        Value *Cond = cond->Codegen();
        if (Cond == 0) return 0;
        Builder.CreateCondBr(Cond, bodybb, endbb);
    }
    else 
    {
        cond->Codegen(bodybb, endbb);
    }
    
    Builder.SetInsertPoint(bodybb);
    
    Value *Stmt = stmt->Codegen(condbb, endbb);  
    if (Stmt == 0) return 0;  
    Builder.CreateBr(condbb);
    bodybb = Builder.GetInsertBlock();

    Builder.SetInsertPoint(endbb);
    return Stmt;
}

Value *IfStmtNode::Codegen()
{
    Function *parent = Builder.GetInsertBlock()->getParent();   
    BasicBlock *condbb = BasicBlock::Create(getGlobalContext(), "if.cond", parent);
    BasicBlock *thenbb = BasicBlock::Create(getGlobalContext(), "if.then", parent);
    BasicBlock *elsebb = 0;
    if (haveElse)
        elsebb = BasicBlock::Create(getGlobalContext(), "if.else", parent);        
    BasicBlock *endbb = BasicBlock::Create(getGlobalContext(), "if.end", parent);
    Builder.CreateBr(condbb);
    Builder.SetInsertPoint(condbb);
    if (cond->op == NOT || ((cond->lhs->type != COND) && (cond->rhs->type != COND)))
    {
        Value *Cond = cond->Codegen();
        if (Cond == 0) return 0;
        if (haveElse)
            Builder.CreateCondBr(Cond, thenbb, elsebb);
        else 
            Builder.CreateCondBr(Cond, thenbb, endbb);
    }
    else 
    {
        if (haveElse)
            cond->Codegen(thenbb, elsebb);
        else 
            cond->Codegen(thenbb, endbb);
    }


    condbb = Builder.GetInsertBlock();
    
    Builder.SetInsertPoint(thenbb);    
    Value *Then = then->Codegen();
    if (Then == 0) return 0;
    Builder.CreateBr(endbb);
    thenbb = Builder.GetInsertBlock();
    if (haveElse) 
    {
        Builder.SetInsertPoint(elsebb);
        Value *ELSe = Else->Codegen();
        if (ELSe == 0) return 0;
        
        Builder.CreateBr(endbb);
        elsebb = Builder.GetInsertBlock();
    }  
    Builder.SetInsertPoint(endbb);
    return condbb;
}

Value *BlockNode::Codegen(BasicBlock *condbb, BasicBlock *endbb)
{
    BlockDepth++;
    Value *temp = ConstantInt::get(getGlobalContext(), APInt(32, 1));
    for (auto i : decl)
    {
        temp = i->Codegen();
        if (temp == 0) return 0;
    }
    for (auto i : stmts)
    {
        temp = i->Codegen(condbb, endbb);
        if (temp == 0) return 0;
    }
    for (auto i = oldVal.begin(); i != oldVal.end(); ++i)
    {
        if ((*i).second.BlockDepth == BlockDepth - 1)
        {
            table[(*i).first] = (*i).second;
            oldVal.erase(i);
            --i;
        }
    }
    BlockDepth--;
    return temp;
}

Value *BreakNode::Codegen(BasicBlock *condbb, BasicBlock *endbb)
{
    Builder.CreateBr(endbb);
    return ConstantInt::get(mod->getContext(), APInt(32, 1));
}

Value *ContinueNode::Codegen(BasicBlock *condbb, BasicBlock *endbb)
{
    Builder.CreateBr(condbb);
    return ConstantInt::get(mod->getContext(), APInt(32, 1));
}

Value *IfStmtNode::Codegen(BasicBlock *outcondbb, BasicBlock *outendbb)
{
    Function *parent = Builder.GetInsertBlock()->getParent();   
    BasicBlock *condbb = BasicBlock::Create(getGlobalContext(), "if.cond", parent);
    BasicBlock *thenbb = BasicBlock::Create(getGlobalContext(), "if.then", parent);
    BasicBlock *elsebb = 0;
    if (haveElse)
        elsebb = BasicBlock::Create(getGlobalContext(), "if.else", parent);        
    BasicBlock *endbb = BasicBlock::Create(getGlobalContext(), "if.end", parent);
    Builder.CreateBr(condbb);
    Builder.SetInsertPoint(condbb);
    if (cond->op == NOT || ((cond->lhs->type != COND) && (cond->rhs->type != COND)))
    {
        Value *Cond = cond->Codegen();
        if (Cond == 0) return 0;
        if (haveElse)
            Builder.CreateCondBr(Cond, thenbb, elsebb);
        else 
            Builder.CreateCondBr(Cond, thenbb, endbb);
    }
    else 
    {
        if (haveElse)
            cond->Codegen(thenbb, elsebb);
        else 
            cond->Codegen(thenbb, endbb);
    }


    condbb = Builder.GetInsertBlock();
    
    Builder.SetInsertPoint(thenbb);    
    Value *Then = then->Codegen(outcondbb, outendbb);
    if (Then == 0) return 0;
    Builder.CreateBr(endbb);
    thenbb = Builder.GetInsertBlock();
    if (haveElse) 
    {
        Builder.SetInsertPoint(elsebb);
        Value *ELSe = Else->Codegen(outcondbb, outendbb);
        if (ELSe == 0) return 0;
        
        Builder.CreateBr(endbb);
        elsebb = Builder.GetInsertBlock();
    }  
    Builder.SetInsertPoint(endbb);
    return condbb;
}

Value *WhileStmtNode::Codegen(BasicBlock *outcondbb, BasicBlock *outendbb)
{
    Function *parent = Builder.GetInsertBlock()->getParent();

    BasicBlock *condbb = BasicBlock::Create(mod->getContext(), "while.cond", parent);
    BasicBlock *bodybb = BasicBlock::Create(mod->getContext(), "while.body", parent);
    BasicBlock *endbb = BasicBlock::Create(mod->getContext(), "while.end", parent);
    Builder.CreateBr(condbb);
    Builder.SetInsertPoint(condbb);
    if (cond->op == NOT || ((cond->lhs->type != COND) && (cond->rhs->type != COND)))
    {
        Value *Cond = cond->Codegen();
        if (Cond == 0) return 0;
        Builder.CreateCondBr(Cond, bodybb, endbb);
    }
    else 
    {
        cond->Codegen(bodybb, endbb);
    }
    
    Builder.SetInsertPoint(bodybb);
    
    Value *Stmt = stmt->Codegen(condbb, endbb);  
    if (Stmt == 0) return 0;  
    Builder.CreateBr(condbb);
    bodybb = Builder.GetInsertBlock();

    Builder.SetInsertPoint(endbb);
    return Stmt;
}

Value *FuncCallNode::Codegen()
{
    if (functab.find(*name) == functab.end())
    {
        errfactory.append(new errmsg(UndefinedFunc, loc->last_line, loc->last_column, infile_name, false));
        return 0;
    }
    
    return Builder.CreateCall(functab[*name]);
}

Value *BlockNode::Codegen()
{
    BlockDepth++;
    Value *temp = ConstantInt::get(getGlobalContext(), APInt(32, 1));
    for (auto i : decl)
    {
        temp = i->Codegen();
        if (temp == 0) return 0;
    }
    for (auto i : stmts)
    {
        temp = i->Codegen();
        if (temp == 0) return 0;
    }
    for (auto i = oldVal.begin(); i != oldVal.end(); ++i)
    {
        if ((*i).second.BlockDepth == BlockDepth - 1)
        {
            table[(*i).first] = (*i).second;
            oldVal.erase(i);
            --i;
        }
    }
    for (auto i = table.begin(); i != table.end(); ++i)
    {
        if (i->second.BlockDepth >= BlockDepth)
        {
            table.erase(i);
            --i;
        }
    }
    BlockDepth--;
    return temp;
}

Value *ExternDeclNode::Codegen()
{
    for (auto i : decl)
    {
        Value *temp = i->CodegenGlobal(true);    
        if (temp == 0) return 0;
    }
    return ConstantInt::get(mod->getContext(), APInt(32, 1, true));  
}

Value *FuncDefNode::Codegen()
{
    if (functab.find(*name) != functab.end())
    {
        errfactory.append(new errmsg(RedefinedFunc, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    std::vector<Type*> func_args;
    FunctionType *func_type =
        FunctionType::get(Type::getVoidTy(mod->getContext()),
                func_args, false);
    Function *func =
        Function::Create(func_type, GlobalValue::ExternalLinkage, name->c_str(), mod);
    functab[*name] = func;
    BasicBlock *entry = BasicBlock::Create(mod->getContext(), "entry", func, 0);
    Builder.SetInsertPoint(entry);
    Value *Body = block->Codegen();
    if (Body == 0) return 0;
    Builder.CreateRetVoid();
    return func;
}

Value *ExternFuncNode::Codegen()
{
    if (functab.find(*name) != functab.end())
    {
        errfactory.append(new errmsg(RedefinedFunc, loc->first_line, loc->first_column, infile_name, false));
        return 0;
    }
    vector<Type*> func_args;
    FunctionType *func_type =
        FunctionType::get(Type::getVoidTy(mod->getContext()),
                func_args, false);
    Function *func =
        Function::Create(func_type, GlobalValue::ExternalLinkage, name->c_str(), mod);
    functab[*name] = func;
    return func;
}

Value *CompUnitNode::Codegen()
{
    for (auto i : decl)
    {
        Value *temp = i->CodegenGlobal();
        if (temp == 0) return 0;
    }
    
    for (auto i : func)
    {
        Value *temp = i->Codegen();
        if (temp == 0) return 0;
    }
    return ConstantInt::get(mod->getContext(), APInt(32, 1, true));
}

Value *EmptyNode::Codegen() { return ConstantInt::get(mod->getContext(), APInt(32, 1)); }
