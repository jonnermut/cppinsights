//
//  TypeMapping.hpp
//  insights
//
//  Created by Jon Nermut on 18/2/19.
//

#ifndef TypeMapping_hpp
#define TypeMapping_hpp

#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"


#include <string>

namespace clang::insights {

    std::string GetSwiftName(const QualType& t);
}

#endif /* TypeMapping_hpp */
