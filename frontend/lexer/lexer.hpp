#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#ifndef yyFlexLexer
#include <FlexLexer.h>
#endif

class GWCLexer final : public yyFlexLexer {
public:
    GWCLexer() = default;
    int yylex() override;
};

#endif