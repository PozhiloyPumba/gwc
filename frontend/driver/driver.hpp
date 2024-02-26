#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__

#include <FlexLexer.h>

#include <memory>
#include <string>
#include <vector>

#include "AST.hpp"
#include "grammar.tab.hh"
#include "lexer.hpp"
#include "node.hpp"

namespace yy {
class FrontendDriver final {
    std::unique_ptr<GWCLexer> lexer_;
    std::vector<std::string> code_;
    GWC::AST<GWC::Node *> tree_;

public:
    FrontendDriver(const char *input)
        : lexer_(std::unique_ptr<GWCLexer>{new GWCLexer}), tree_() {
        std::fstream inputFile(input, std::ios_base::in);
        while (inputFile) {
            std::string newLine;
            std::getline(inputFile, newLine);
            code_.push_back(newLine);
        }
    }
    parser::token_type yylex(parser::semantic_type *yylval) {
        parser::token_type tokenT =
            static_cast<parser::token_type>(lexer_->yylex());

        switch (tokenT) {
        case yy::parser::token_type::NUMBER: {
            yylval->build<int>() = std::stoi(lexer_->YYText());
            break;
        }
        case yy::parser::token_type::ID: {
            yylval->build<std::string>() = lexer_->YYText();
            break;
        }
        case yy::parser::token_type::LEXERR: {
            throw std::runtime_error("Unexpected word");
        }
        default:;
        }

        return tokenT;
    }

    bool parse() {
        parser parser(this);
        bool res = parser.parse();
        return !res;
    }

    void setRoot(GWC::Node *root) { tree_.setRoot(root); }
    void dump(std::ostream &out) { tree_.dumpTree(out); }
};

} // namespace yy

#endif