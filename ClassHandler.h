//
//  ClassHandler.hpp
//  insights
//
//  Created by Jon Nermut on 17/2/19.
//

#ifndef ClassHandler_hpp
#define ClassHandler_hpp

#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include "InsightsBase.h"
//-----------------------------------------------------------------------------

namespace clang::insights {

    /// \brief Match function decls
    ///
    /// To get a broader rewrite of statements match the entire function and rewrite it.
    class ClassHandler final : public ast_matchers::MatchFinder::MatchCallback, public InsightsBase
    {
    public:
        ClassHandler(Rewriter& rewrite, ast_matchers::MatchFinder& matcher);
        void run(const ast_matchers::MatchFinder::MatchResult& result) override;
    };
    //-----------------------------------------------------------------------------

}  // namespace clang::insights


#endif /* ClassHandler_hpp */
