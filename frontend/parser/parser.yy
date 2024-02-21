%language "c++"

%define api.value.type variant

%code requires
{
	#include <iostream>
	#include <fstream>
	namespace yy {class FrontendDriver;};
}

%code {

#include "driver.hpp"

namespace yy {
parser::token_type yylex(parser::semantic_type* yylval, FrontendDriver *driver);
}
}

%param {yy::FrontendDriver* driver}

%token <int> NUMBER
%token <std::string> ID
%token  IF WHILE COMMA SEMICOLON
		OPCIRCBRACK CLCIRCBRACK
		OPSQBRACK CLSQBRACK
		OPCURVBRACK CLCURVBRACK
		ADD SUB MUL DIV OR NOT
		RIGHT_ARROW NEQ LTE
		ASSIGN COLON POINTS
		FUNC_DECL VAR_DECL ARRAY_DECL
		RETURN CONTINUE LEXERR END

%start GWCentry

%%

GWCentry: { }
;


%%
namespace yy {

parser::token_type yylex (parser::semantic_type* yylval, FrontendDriver* driver) {
    try {
        return driver->yylex (yylval);
    } catch (std::runtime_error& err) {
        std::cout << err.what () << std::endl;
        throw err; 
    }
}
void yyerror(char const *message){
  printf("Error: %s\n", message);
}

}