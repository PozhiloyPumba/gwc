%language "c++"

%define api.value.type variant

%code requires
{
	#include <iostream>
	#include <fstream>
	
	#include "node.hpp"

	namespace yy {class FrontendDriver;};
}

%code {

#include "driver.hpp"
#include "AST.hpp"

namespace yy {
parser::token_type yylex(parser::semantic_type* yylval, FrontendDriver *driver);
}
}

%param {yy::FrontendDriver* driver}

%token <int> NUMBER
%token <std::string> ID

%type <std::vector<GWC::Node *> *> 	DEF_LIST STATEMENTS ARRAY_ACCESS 
									ARGLIST LISTS NUMBER_LIST

%type <GWC::Node *> LIST FUNCTION_DEF STATEMENT
					SCOPE MATH_EXPRESSION
					EXPRESSION ARRAY_DEF
					IF_OR_WHILE_DEF FOR_DEF
					RETURN_DEF VAR_DEF TYPE_ID

%type <std::vector<int> *> ARRAY_SHAPE ARRAY_SHAPE_PARAMS

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
%left NEQ LTE
%left ADD SUB
%left MUL DIV

%start GWCentry

%%

GWCentry: DEF_LIST
			{
				GWC::NoOpNode *root = new GWC::NoOpNode(GWC::NoOpNode::NoOp_Type::SCOPE);
				std::swap(root->childs_, *($1));
				driver->setRoot(root);
			}
;

DEF_LIST: DEF_LIST FUNCTION_DEF
			{
				$1->push_back($2);
				$$ = $1;
			}
		| FUNCTION_DEF
			{
				$$ = new std::vector<GWC::Node *>;
				$$->push_back($1);
			}
;


FUNCTION_DEF: FUNC_DECL ID FUNC_ARGS RIGHT_ARROW ID SCOPE 
				{
					GWC::FuncNode *node = new GWC::FuncNode(GWC::FuncNode::Func_Type::FUNC_DECL, $2);
					node->childs_.push_back($6);
					$$ = node;
				}
;

FUNC_ARGS 	: OPCIRCBRACK PARAMS CLCIRCBRACK 	{}
			| OPCIRCBRACK CLCIRCBRACK 			{}
;

PARAMS	: PARAMS COMMA ID {}
		| ID {}
;

SCOPE	: OPCURVBRACK STATEMENTS CLCURVBRACK
			{
				auto *node = new GWC::NoOpNode(GWC::NoOpNode::NoOp_Type::SCOPE);
				std::swap(node->childs_, *($2));
				$$ = node;
			}
		| OPCURVBRACK CLCURVBRACK
			{
				$$ = nullptr;
			}
;

STATEMENTS 	: STATEMENTS STATEMENT
				{
					$1->push_back($2);
					$$ = $1;
				}
			| STATEMENT
				{
					$$ = new std::vector<GWC::Node *>;
					$$->push_back($1);
				}
;

STATEMENT	: ARRAY_DEF SEMICOLON
				{
					$$ = $1;
				}
			| FOR_DEF
				{
					$$ = $1;
				}
			| IF_OR_WHILE_DEF
				{
					$$ = $1;
				}
			| CONTINUE SEMICOLON
				{
					$$ = new GWC::NoOpNode(GWC::NoOpNode::NoOp_Type::CONTINUE);
				}
			| EXPRESSION SEMICOLON
				{
					$$ = $1;
				}
			| VAR_DEF SEMICOLON
				{
					$$ = $1;
				}
			| RETURN_DEF SEMICOLON
				{
					$$ = $1;
				}
			| UPDATE_GPU_BUFFER OPCIRCBRACK CLCIRCBRACK SEMICOLON
				{
					$$ = new GWC::GraphicNode(GWC::GraphicNode::Graphic_Type::UPDATE_GPU_BUFFER);
				}
			| FLUSH OPCIRCBRACK CLCIRCBRACK SEMICOLON
				{
					$$ = new GWC::GraphicNode(GWC::GraphicNode::Graphic_Type::FLUSH);
				}
;

EXPRESSION 	: ID ARRAY_ACCESS ASSIGN MATH_EXPRESSION
				{
					auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::ASSIGN);
					auto *varNode = new GWC::VarNode($1);
					std::swap(varNode->childs_, *($2));
					node->childs_.push_back(varNode);
					node->childs_.push_back($4);
					$$ = node;
				}
			| ID ASSIGN MATH_EXPRESSION
				{
					auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::ASSIGN);
					auto *varNode = new GWC::VarNode($1);
					node->childs_.push_back(varNode);
					node->childs_.push_back($3);
					$$ = node;
				}
			| MATH_EXPRESSION
				{
					$$ = $1;
				}
;

ARRAY_ACCESS: ARRAY_ACCESS OPSQBRACK MATH_EXPRESSION CLSQBRACK
				{
					$1->push_back($3);
					$$ = $1;
				}
			| OPSQBRACK MATH_EXPRESSION CLSQBRACK
				{
					$$ = new std::vector<GWC::Node *>;
					$$->push_back($2);
				}
;

MATH_EXPRESSION	: NUMBER
					{
						$$ = new GWC::NumNode($1);
					}
				| ID
					{
						$$ = new GWC::VarNode($1);
					}
				| ID ARRAY_ACCESS   
					{
						auto *varNode = new GWC::VarNode($1);
						std::swap(varNode->childs_, *($2));
						$$ = varNode;
					}
				| SET_PIXEL OPCIRCBRACK ARGLIST CLCIRCBRACK
					{
						auto *node = new GWC::GraphicNode(GWC::GraphicNode::Graphic_Type::SET_PIXEL);
						std::swap(node->childs_, *($3));
						$$ = node;
					}
				| NEQ MATH_EXPRESSION MATH_EXPRESSION
					{
						auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::NEQ);
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
				| LTE MATH_EXPRESSION MATH_EXPRESSION
					{
						auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::LTE);
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
				| ADD MATH_EXPRESSION MATH_EXPRESSION
					{
						auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::ADD);
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
				| SUB MATH_EXPRESSION MATH_EXPRESSION
					{
						auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::SUB);
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
				| MUL MATH_EXPRESSION MATH_EXPRESSION
					{
						auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::MUL);
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
				| DIV MATH_EXPRESSION MATH_EXPRESSION
					{
						auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::DIV);
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
				| OR MATH_EXPRESSION MATH_EXPRESSION
					{
						auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::OR);
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
				| UNARY_MINUS MATH_EXPRESSION
					{
						auto *node = new GWC::UnOpNode(GWC::UnOpNode::UnOp_Type::UNARY_MINUS);
						node->childs_.push_back($2);
						$$ = node;
					}
				| NOT MATH_EXPRESSION
					{
						auto *node = new GWC::UnOpNode(GWC::UnOpNode::UnOp_Type::NOT);
						node->childs_.push_back($2);
						$$ = node;
					}
				| OPCIRCBRACK MATH_EXPRESSION CLCIRCBRACK
					{
						$$ = $2;
					}
;

ARGLIST : ARGLIST COMMA MATH_EXPRESSION
			{
				$1->push_back($3);
				$$ = $1;
			}
		| MATH_EXPRESSION
			{
				$$ = new std::vector<GWC::Node *>();
				$$->push_back($1);
			}
;

VAR_DEF	: VAR_DECL ID TYPE_ID ASSIGN MATH_EXPRESSION
			{
				auto *node = new GWC::BinOpNode(GWC::BinOpNode::BinOp_Type::ASSIGN);
				auto *varNode = new GWC::VarNode($2);
				varNode->childs_.push_back($3);
				node->childs_.push_back(varNode);
				node->childs_.push_back($5);
				$$ = node;
			}
;

IF_OR_WHILE_DEF	: IF MATH_EXPRESSION SCOPE
					{ 
						auto *node = new GWC::CondNode();
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
				| WHILE MATH_EXPRESSION SCOPE
					{ 
						auto *node = new GWC::CycleNode(GWC::CycleNode::Cycle_Type::WHILE);
						node->childs_.push_back($2);
						node->childs_.push_back($3);
						$$ = node;
					}
;

ARRAY_DEF 	: ARRAY_DECL ARRAY_SHAPE ID TYPE_ID ASSIGN LIST
				{
					auto *node = new GWC::ArrayNode($3);
					std::swap(node->sizes, *($2));
					node->childs_.push_back($4);
					node->childs_.push_back($6);
					$$ = node;
				}
;

LISTS	: LISTS COMMA LIST
			{
				$1->push_back($3);
				$$ = $1;
			}
		| LIST
			{
				$$ = new std::vector<GWC::Node *>();
				$$->push_back($1);
			}
;

LIST 	: OPCURVBRACK LISTS CLCURVBRACK
			{
				auto *listNode = new GWC::NoOpNode(GWC::NoOpNode::NoOp_Type::LIST);
				std::swap(listNode->childs_, *($2));
				$$ = listNode;
			}
		| OPCURVBRACK NUMBER_LIST CLCURVBRACK
			{
				auto *listNode = new GWC::NoOpNode(GWC::NoOpNode::NoOp_Type::LIST);
				std::swap(listNode->childs_, *($2));
				$$ = listNode;
			}
		| OPCURVBRACK CLCURVBRACK
			{
				$$ = nullptr;
			}
;

NUMBER_LIST	: NUMBER_LIST COMMA NUMBER
				{
					$1->push_back(new GWC::NumNode($3));
					$$ = $1;
				}
			| NUMBER
				{
					$$ = new std::vector<GWC::Node *>();
					$$->push_back(new GWC::NumNode($1));
				}
;

ARRAY_SHAPE	: OPCIRCBRACK ARRAY_SHAPE_PARAMS CLCIRCBRACK { $$ = $2; }

ARRAY_SHAPE_PARAMS 	: ARRAY_SHAPE_PARAMS COMMA NUMBER
						{
							$1->push_back($3);
							$$ = $1;
						}
					| NUMBER
						{ 
							$$ = new std::vector<int>;
							$$->push_back($1);
						}
;

TYPE_ID	: COLON ID
			{
				$$ = new GWC::TypeNode($2);
			}
;

FOR_DEF	: FOR ID ASSIGN EXPRESSION POINTS EXPRESSION SCOPE
			{
				auto *node = new GWC::CycleNode(GWC::CycleNode::Cycle_Type::FOR);
				node->childs_.push_back(new GWC::VarNode($2));
				node->childs_.push_back($4);
				node->childs_.push_back($6);
				node->childs_.push_back($7);
				$$ = node;
			}
;

RETURN_DEF	: RETURN MATH_EXPRESSION
				{
					auto *node = new GWC::UnOpNode(GWC::UnOpNode::UnOp_Type::RETURN);
					node->childs_.push_back($2);
					$$ = node;
				}
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