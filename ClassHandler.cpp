//
//  ClassHandler.cpp
//  insights
//
//  Created by Jon Nermut on 17/2/19.
//

#include "ClassHandler.h"

#include <iostream>

#include "FunctionDeclHandler.h"
#include "ClangCompat.h"
#include "CodeGenerator.h"
#include "DPrint.h"
#include "InsightsHelpers.h"
#include "InsightsMatchers.h"
#include "OutputFormatHelper.h"
//-----------------------------------------------------------------------------

using namespace clang;
using namespace clang::ast_matchers;
//-----------------------------------------------------------------------------

namespace clang::insights {

    ClassHandler::ClassHandler(Rewriter& rewrite, MatchFinder& matcher)
    : InsightsBase(rewrite)
    {
        matcher.addMatcher(cxxRecordDecl() 
                           .bind("recordDecl"),
                           this);

    }
    //-----------------------------------------------------------------------------

    void ClassHandler::run(const MatchFinder::MatchResult& result)
    {
        if(const auto* recordDecl = result.Nodes.getNodeAs<CXXRecordDecl>("recordDecl")) {
            const auto         columnNr = GetSM(result).getSpellingColumnNumber(GetBeginLoc(recordDecl)) - 1;
            OutputFormatHelper outputFormatHelper{columnNr};
            CodeGenerator      codeGenerator{outputFormatHelper};

            codeGenerator.InsertArg(recordDecl);

            //auto sr = recordDecl->getSourceRange();

            std::cout << outputFormatHelper.GetString() << std::endl;

            /*
            if(sr.getBegin() != sr.getEnd()) {

                mRewrite.ReplaceText(sr, outputFormatHelper.GetString());
            } else {
                // special handling for at least using Base::Base for inheriting ctors from Base class.
                const auto ssr = GetSourceRangeAfterSemi(recordDecl->getSourceRange(), result);
                InsertIndentedText(ssr.getEnd(), outputFormatHelper);
            }
             */

        }
    }
    //-----------------------------------------------------------------------------

}  // namespace clang::insights
