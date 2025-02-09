#include <iostream>
#include "clang/AST/ASTConsumer.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/ASTContext.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "llvm/Support/CommandLine.h"
#include "clang/Tooling/Tooling.h"

static llvm::cl::OptionCategory MyToolingCategory("my-tooling");

class MyVisitor : public clang::RecursiveASTVisitor<MyVisitor> {
public:
    bool VisitFunctionDecl(clang::FunctionDecl *f) {
        std::cout << "Found function: " << f->getNameAsString() << std::endl;
        return true;
    }
};

class MyConsumer : public clang::ASTConsumer {
public:
    void HandleTranslationUnit(clang::ASTContext &Context) override {
        MyVisitor visitor;
        visitor.TraverseDecl(Context.getTranslationUnitDecl());
    }
};

class MyFrontendAction : public clang::ASTFrontendAction {
public:
    std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &CI,
                                                           llvm::StringRef InFile) override {
        (void)CI; // CI and InFile are not used, so we silence the warning.
        (void)InFile;
        return std::make_unique<MyConsumer>();
    }
};

int main(int argc, const char **argv) {
    auto ExpectedParser = clang::tooling::CommonOptionsParser::create(argc, argv, MyToolingCategory);
    if (!ExpectedParser) {
        llvm::errs() << ExpectedParser.takeError();
        return 1;
    }
    clang::tooling::CommonOptionsParser &OptionsParser = ExpectedParser.get();
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                    OptionsParser.getSourcePathList());

    // Use newFrontendActionFactory to create the action and pass it to run.
    return Tool.run(clang::tooling::newFrontendActionFactory<MyFrontendAction>().get());
}