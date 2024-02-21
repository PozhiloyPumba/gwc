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
%token  IF WHILE FOR COMMA SEMICOLON
		OPCIRCBRACK CLCIRCBRACK
		OPSQBRACK CLSQBRACK
		OPCURVBRACK CLCURVBRACK
		ADD SUB MUL DIV OR NOT
		RIGHT_ARROW NEQ LTE
		ASSIGN COLON POINTS
		FUNC_DECL VAR_DECL ARRAY_DECL
		UNARY_MINUS RETURN CONTINUE
		SET_PIXEL UPDATE_GPU_BUFFER FLUSH
		LEXERR END

%right ASSIGN
%left OR
%left NEQ
%left LTE
%left ADD SUB
%left MUL DIV

%start GWCentry

%%

GWCentry: GWCentry FUNCTION_DEF { }
		| FUNCTION_DEF {}
;

FUNCTION_DEF: FUNC_DECL ID FUNC_ARGS RIGHT_ARROW ID SCOPE {}

FUNC_ARGS 	: OPCIRCBRACK PARAMS CLCIRCBRACK 	{}
			| OPCIRCBRACK CLCIRCBRACK 			{}
;

PARAMS	: PARAMS COMMA ID {}
		| ID {}
;

SCOPE	: OPCURVBRACK STATEMENTS CLCURVBRACK {}
		| OPCURVBRACK CLCURVBRACK {}
;

STATEMENTS 	: STATEMENTS STATEMENT {}
			| STATEMENT {}
;

STATEMENT	: ARRAY_DEF SEMICOLON {}
			| FOR_DEF {}
			| IF_OR_WHILE_DEF {}
			| CONTINUE SEMICOLON {}
			| EXPRESSION SEMICOLON {}
			| VAR_DEF SEMICOLON {}
			| RETURN_DEF SEMICOLON {}
			| UPDATE_GPU_BUFFER OPCIRCBRACK CLCIRCBRACK SEMICOLON {}
			| FLUSH OPCIRCBRACK CLCIRCBRACK SEMICOLON {}
;

EXPRESSION 	: ID ARRAY_ACCESS ASSIGN MATH_EXPRESSION {}
			| ID ASSIGN MATH_EXPRESSION {}
			| MATH_EXPRESSION {}
;

ARRAY_ACCESS: ARRAY_ACCESS OPSQBRACK MATH_EXPRESSION CLSQBRACK {}
			| OPSQBRACK MATH_EXPRESSION CLSQBRACK {}
;

MATH_EXPRESSION	: NUMBER {}
				| ID {}
				| ID ARRAY_ACCESS {}
				| SET_PIXEL OPCIRCBRACK ARGLIST CLCIRCBRACK {}
				| NEQ MATH_EXPRESSION MATH_EXPRESSION {}
				| LTE MATH_EXPRESSION MATH_EXPRESSION {}
				| ADD MATH_EXPRESSION MATH_EXPRESSION {}
				| SUB MATH_EXPRESSION MATH_EXPRESSION {}
				| MUL MATH_EXPRESSION MATH_EXPRESSION {}
				| DIV MATH_EXPRESSION MATH_EXPRESSION {}
				| OR MATH_EXPRESSION MATH_EXPRESSION {}
				| UNARY_MINUS MATH_EXPRESSION {}
				| NOT MATH_EXPRESSION {}
				| OPCIRCBRACK MATH_EXPRESSION CLCIRCBRACK {}
;

ARGLIST : MATH_EXPRESSION COMMA ARGLIST {}
		| MATH_EXPRESSION {}
;

VAR_DEF	: VAR_DECL ID TYPE_ID ASSIGN MATH_EXPRESSION {}
;

IF_OR_WHILE_DEF	: IF MATH_EXPRESSION SCOPE {}
				| WHILE MATH_EXPRESSION SCOPE {}
;

ARRAY_DEF 	: ARRAY_DECL ARRAY_SHAPE ID TYPE_ID ASSIGN LISTS {}
;

LISTS	: LIST COMMA LISTS {}
		| LIST {}
;

LIST 	: OPCURVBRACK LISTS CLCURVBRACK {}
		| OPCURVBRACK NUMBER_LIST CLCURVBRACK {}
		| OPCURVBRACK CLCURVBRACK {}
;

NUMBER_LIST	: NUMBER COMMA NUMBER_LIST {}
			| NUMBER {}
;

ARRAY_SHAPE	: OPCIRCBRACK ARRAY_SHAPE_PARAMS CLCIRCBRACK {}

ARRAY_SHAPE_PARAMS 	: ARRAY_SHAPE_PARAMS COMMA NUMBER 	{}
					| NUMBER {}
;

TYPE_ID	: COLON ID {}
;

FOR_DEF	: FOR ID ASSIGN EXPRESSION POINTS EXPRESSION SCOPE {}

RETURN_DEF	: RETURN MATH_EXPRESSION {}
;

%%
namespace yy {

parser::token_type yylex(parser::semantic_type* yylval, FrontendDriver* driver) {
    try {
        return driver->yylex (yylval);
    } catch (std::runtime_error& err) {
        std::cout << err.what () << std::endl;
        throw err; 
    }
}

void parser::error([[maybe_unused]] const std::string& what) {
}

}