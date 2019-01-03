#ifndef EXPLAIN_CODEGEN_HH
#define EXPLAIN_CODEGEN_HH

#include <map>
#include <memory>
#include <string>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>

#include "ast.hh"

namespace explain {

namespace CodeGen {

class Context {
public:
    llvm::LLVMContext TheContext;
    llvm::IRBuilder<> Builder;
    std::unique_ptr<llvm::Module> TheModule;
    std::unique_ptr<llvm::legacy::FunctionPassManager> TheFPM;
    std::map<std::string, llvm::AllocaInst *> LocalVars;

    std::string ScopeName;
    llvm::BasicBlock *currentBlock;

    Context()
        : Builder(llvm::IRBuilder<>(TheContext)), currentBlock(nullptr) {}

    void initialize();

    llvm::Function *GetCurrentFunction();
    llvm::AllocaInst *EmitEntryBlockAlloca(llvm::Function *TheFunction, std::string VarName);
    llvm::Value *LogErrorV(std::string str);
};

} // end namespace CodeGen
} // end namespace explain

#endif //EXPLAIN_CODEGEN_HH
