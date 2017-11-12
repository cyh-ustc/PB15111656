#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>



#include <memory>

using namespace llvm;

int main()
{
    LLVMContext context;
    IRBuilder<> builder(context);

    auto module = new Module("fib", context);

    auto func = Function::Create(FunctionType::get(Type::getInt32Ty(context),  std::vector<Type*> (1, Type::getInt32Ty(context)), false), GlobalValue::LinkageTypes::ExternalLinkage, "fib", module);
    for (auto &Arg : func->args())
        Arg.setName("n");
  
    
    auto b0 = BasicBlock::Create(context, "", func);
    auto b1 = BasicBlock::Create(context, "Equal0", func);
    auto b2 = BasicBlock::Create(context, "NotEqual0", func);
    auto b3 = BasicBlock::Create(context, "Equal1", func);
    auto b4 = BasicBlock::Create(context, "NotEqual1", func);
    builder.SetInsertPoint(b0);
    Value *V;
    for (auto &Arg : func->args())
        V = &Arg;
    auto cond = builder.CreateICmpEQ(V,ConstantInt::get(Type::getInt32Ty(context), 0),"cond");
    builder.CreateCondBr(cond, b1, b2);


    builder.SetInsertPoint(b1);
    builder.CreateRet(ConstantInt::get(Type::getInt32Ty(context), 0));


    builder.SetInsertPoint(b2);
    auto cond1 = builder.CreateICmpEQ(V,ConstantInt::get(Type::getInt32Ty(context), 1),"cond1");
    builder.CreateCondBr(cond1, b3, b4);

    builder.SetInsertPoint(b3);
    builder.CreateRet(ConstantInt::get(Type::getInt32Ty(context), 1));

    builder.SetInsertPoint(b4);
    auto t0 = builder.CreateSub(V,ConstantInt::get(Type::getInt32Ty(context), 1),"t0");
    auto t1 = builder.CreateCall(func, t0,"t1");
    auto t2 = builder.CreateSub(V,ConstantInt::get(Type::getInt32Ty(context), 2),"t2");
    auto t3 = builder.CreateCall(func, t2,"t3");
    auto t4 = builder.CreateAdd(t1,t3,"t4");
    builder.CreateRet(t4);

    builder.ClearInsertionPoint();




    auto mainfunc = Function::Create(FunctionType::get(Type::getInt32Ty(context), std::vector<Type *>(), false), GlobalValue::LinkageTypes::ExternalLinkage, "main", module);
    auto mb0 = BasicBlock::Create(context, "", mainfunc);
    auto mb1 = BasicBlock::Create(context, "forcond", mainfunc);
    auto mb2 = BasicBlock::Create(context, "forexpr", mainfunc);
    auto mb3 = BasicBlock::Create(context, "forfini", mainfunc);

    builder.SetInsertPoint(mb0);
    auto x = builder.CreateAlloca(Type::getInt32Ty(context),ConstantInt::get(Type::getInt32Ty(context), 1),"x");
    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), 0),x);
    auto i = builder.CreateAlloca(Type::getInt32Ty(context),ConstantInt::get(Type::getInt32Ty(context), 1),"i");
    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), 0),i);
    builder.CreateBr(mb1);

    builder.SetInsertPoint(mb1);
    auto mt0 = builder.CreateLoad(i,"t0");
    auto mcond = builder.CreateICmpSLT(mt0,ConstantInt::get(Type::getInt32Ty(context), 10));
    builder.CreateCondBr(mcond, mb2, mb3);

    builder.SetInsertPoint(mb2);
    auto mt1 = builder.CreateLoad(x,"t1");
    auto mt2 = builder.CreateLoad(i,"t2");
    auto mt3 = builder.CreateCall(func, mt2, "t3");
    auto mt4 = builder.CreateAdd(mt1, mt3, "t4");
    builder.CreateStore(mt4, x);
    auto mt5 = builder.CreateLoad(i, "t5");
    auto mt6 = builder.CreateAdd(mt5, ConstantInt::get(Type::getInt32Ty(context), 1), "t6");
    builder.CreateStore(mt6, i);
    builder.CreateBr(mb1);

    builder.SetInsertPoint(mb3);
    auto mt7 = builder.CreateLoad(x, "t7");
    builder.CreateRet(mt7);

    builder.ClearInsertionPoint();
    module->print(outs(), nullptr);
    delete module;
    return 0;
}

