#ifndef Pass_Prac_H
#define Pass_Prac_H

#include "llvm/IR/PassManager.h"



class CountIRPassPlugin : public llvm::PassInfoMixin<CountIRPassPlugin> {
    
public:
    llvm::PreservedAnalyses run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM);
    static bool isRequired() { return true; }
    
};



#endif

