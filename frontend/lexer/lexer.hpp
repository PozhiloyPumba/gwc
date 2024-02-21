#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#ifndef yyFlexLexer
#include <FlexLexer.h>
#endif

// #include "location.hh"

class GWCLexer final : public yyFlexLexer {
    // yy::location location_{};

public:
    GWCLexer() = default;

    // void setLocation();

    // yy::location getLocation() const { return location_; }

    int yylex() override;
};

#endif