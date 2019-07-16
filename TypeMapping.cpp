//
//  TypeMapping.cpp
//  insights
//
//  Created by Jon Nermut on 18/2/19.
//

#include "TypeMapping.hpp"
#include "InsightsHelpers.h"

using std::string;

class TypeMapping
{
public:

    string cType;
    string swiftType;

    TypeMapping(const string& _cType, const string& _swiftType): cType(_cType), swiftType(_swiftType)
    {

    };

    string getSwiftType()
    {
        return swiftType;
    }

};

std::map<std::string, TypeMapping> mappings = {
    // simples
    {     "void",          { "void",       "()"} },
    {     "bool",          { "bool",       "Bool" } },
    {     "double",        { "double",     "Double"} },
    {     "float",         { "float",      "Float"} },
    {     "int",           { "int",        "Int32"} }, // 32 bit
    {     "int32_t",       { "int",        "Int32"} }, // 32 bit
    {     "int64_t",       { "long long",  "Int64" } }, // 64 bit
    {     "uint64_t",      { "unsigned long long", "UInt64" } },
    {     "value_t",       { "long long",  "Int64" } },
    {     "size_t",        { "size_t",  "Int" } }, // 32/64 bit
    {     "long",          { "long",  "Int" } }, // 32/64 bit
    {     "EventId",       { "long long",  "Int64" } },
    {     "HandlerId",     { "long long",  "Int64" } },
    {     "CallbackId",    { "long long",  "Int64" } },
    {     "HashCode",      { "long long",  "Int64" } },
    {     "PortNumber",    { "int",  "Int32" } },


    // non shared_ptr complex types

    {     "string",        { "string", "String" } },

};





namespace clang::insights {

    static TypeMapping GetMapping(const QualType& t)
    {
        string typeName = GetName(t, Unqualified::Yes);

        if (mappings.count(typeName) > 0)
        {
            auto&& ret = mappings.at(typeName);
            return ret;
        }

        // fallback is a 1-1 mapping
        auto ret = TypeMapping(typeName, typeName);
        return ret;
    }

    std::string GetSwiftName(const QualType& t)
    {
        return GetMapping(t).getSwiftType();


    }
}
