#include "CountIRPassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
using namespace llvm;

//===---------------------------------------------------------------------------------------------------------------------------------------------------------------===//
//																			PASS 
//===---------------------------------------------------------------------------------------------------------------------------------------------------------------===//

PreservedAnalyses CountIRPassPlugin::run(Function &F, FunctionAnalysisManager &FAM){

    for(auto &BB : F){
      for(auto &I : BB){
          errs() << I.getOpcodeName() << "\n";
    } }
        return PreservedAnalyses::all();

}

// Registration for new PassManager
extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK
llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "countirpassplugin", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "countirpassplugin") {
                    FPM.addPass(CountIRPassPlugin());
                    return true;
                  }
                  return false;
                });
          }};
}