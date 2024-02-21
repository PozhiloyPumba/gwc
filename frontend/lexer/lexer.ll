%option c++

%option yylineno
%option yyclass="GWCLexer"
%option noyywrap

%{
    #include "grammar.tab.hh"
    
    #include "lexer.hpp"
    #include <iostream>

    // #define YY_USER_ACTION setLocation ();
    #define yyterminate() return yy::parser::token_type::END

%}

TRASH_SYMBS             [ \t\r\n\v]+
DIGIT                   [0-9]

ALPHA                   [a-zA-Z]

WORD                    ({ALPHA}|"_")({ALPHA}|{DIGIT}|"_")*

%%

{TRASH_SYMBS}           {   /*skip*/    }

{DIGIT}*                {   return yy::parser::token_type::NUMBER; }

","                     {   return yy::parser::token_type::COMMA;       }
";"                     {   return yy::parser::token_type::SEMICOLON;   }

"("                     {   return yy::parser::token_type::OPCIRCBRACK; }
")"                     {   return yy::parser::token_type::CLCIRCBRACK; }

"["                     {   return yy::parser::token_type::OPSQBRACK;   }
"]"                     {   return yy::parser::token_type::CLSQBRACK;   }

"{"                     {   return yy::parser::token_type::OPCURVBRACK; }
"}"                     {   return yy::parser::token_type::CLCURVBRACK; }

"+"                     {   return yy::parser::token_type::ADD;         }
"-"                     {   return yy::parser::token_type::SUB;         }
"*"                     {   return yy::parser::token_type::MUL;         }
"/"                     {   return yy::parser::token_type::DIV;         }
"|"                     {   return yy::parser::token_type::OR;          }
"~"                     {   return yy::parser::token_type::NOT;         }

"->"                    {   return yy::parser::token_type::RIGHT_ARROW; }
"!="                    {   return yy::parser::token_type::NEQ;         }
"<="                    {   return yy::parser::token_type::LTE;         }

"="                     {   return yy::parser::token_type::ASSIGN;      }
":"                     {   return yy::parser::token_type::COLON;       }
".."                    {   return yy::parser::token_type::POINTS;      }

"If"                    {   return yy::parser::token_type::IF;          }
"While"                 {   return yy::parser::token_type::WHILE;       }
"Fn"                    {   return yy::parser::token_type::FUNC_DECL;   }
"Let"                   {   return yy::parser::token_type::VAR_DECL;    }
"Array"                 {   return yy::parser::token_type::ARRAY_DECL;  }
"Return"                {   return yy::parser::token_type::RETURN;      }
"Continue"              {   return yy::parser::token_type::CONTINUE;    }

{WORD}                  {   return yy::parser::token_type::ID;          }

.                       {   std::cout << "Cringe" << std::endl; return yy::parser::token_type::LEXERR;        }

%%