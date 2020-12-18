#include "GrammarLexer.h"
#include "Listener.h"

#pragma once

class ListenerTeller : public Listener
{
private:
	ostream* out;
	int p = 0;
	std::unique_ptr<GrammarLexer> lexer;

	void Padd();
	void PrintEnter(const string& text);
	void PrintClose();
public:
	ListenerTeller(ofstream* target, ofstream* header_target, string* text_include, ostream* output);
	~ListenerTeller();

	void enterCompileUnit(GrammarParser::CompileUnitContext *ctx);
	void exitCompileUnit(GrammarParser::CompileUnitContext *ctx);

	void enterUnit(GrammarParser::UnitContext *ctx);
	void exitUnit(GrammarParser::UnitContext *ctx);

	void enterFunction_scope(GrammarParser::Function_scopeContext *ctx);
	void exitFunction_scope(GrammarParser::Function_scopeContext *ctx);

	void enterScope_content(GrammarParser::Scope_contentContext *ctx);
	void exitScope_content(GrammarParser::Scope_contentContext *ctx);

	void enterFor_loop(GrammarParser::For_loopContext *ctx);
	void exitFor_loop(GrammarParser::For_loopContext *ctx);

	void enterRvalue(GrammarParser::RvalueContext *ctx);
	void exitRvalue(GrammarParser::RvalueContext *ctx);

	void enterParantheses_content(GrammarParser::Parantheses_contentContext *ctx);
	void exitParantheses_content(GrammarParser::Parantheses_contentContext *ctx);

	void enterArgument_content(GrammarParser::Argument_contentContext *ctx);
	void exitArgument_content(GrammarParser::Argument_contentContext *ctx);

	void enterFunction_call(GrammarParser::Function_callContext *ctx);
	void exitFunction_call(GrammarParser::Function_callContext *ctx);

	void enterEntry_point(GrammarParser::Entry_pointContext *ctx);
	void exitEntry_point(GrammarParser::Entry_pointContext *ctx);

	void enterSq_arguments(GrammarParser::Sq_argumentsContext *ctx);
	void exitSq_arguments(GrammarParser::Sq_argumentsContext *ctx);

	void enterSq_content(GrammarParser::Sq_contentContext *ctx);
	void exitSq_content(GrammarParser::Sq_contentContext *ctx);

	void enterStr(GrammarParser::StrContext *ctx);
	void exitStr(GrammarParser::StrContext *ctx);

	void enterDirective(GrammarParser::DirectiveContext *ctx);
	void exitDirective(GrammarParser::DirectiveContext *ctx);

	void enterProperty(GrammarParser::PropertyContext *ctx);
	void exitProperty(GrammarParser::PropertyContext *ctx);

	void enterProperty_content(GrammarParser::Property_contentContext *ctx);
	void exitProperty_content(GrammarParser::Property_contentContext *ctx);

	void enterProperty_style_definition(GrammarParser::Property_style_definitionContext *ctx);
	void exitProperty_style_definition(GrammarParser::Property_style_definitionContext *ctx);
	
	void enterVariable_change_value_assignment(GrammarParser::Variable_change_value_assignmentContext *ctx);
	void exitVariable_change_value_assiment(GrammarParser::Variable_change_value_assignmentContext *ctx);

	void enterVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext *ctx);
	void exitVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext *ctx);

	void enterVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext *ctx);
	void exitVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext *ctx);

	void enterSubscript_operator(GrammarParser::Subscript_operatorContext *ctx);
	void exitSubscript_operator(GrammarParser::Subscript_operatorContext *ctx);

	void enterExpression(GrammarParser::ExpressionContext *ctx);
	void exitExpression(GrammarParser::ExpressionContext *ctx);

	void enterAdd_brackets(GrammarParser::Add_bracketsContext *ctx);
	void exitAdd_brackets(GrammarParser::Add_bracketsContext *ctx);

	void enterChange_brackets(GrammarParser::Change_bracketsContext *ctx);
	void exitChange_brackets(GrammarParser::Change_bracketsContext *ctx);

	void enterUnsupported_object_types(GrammarParser::Unsupported_object_typesContext *ctx);
	void exitUnsupported_object_types(GrammarParser::Unsupported_object_typesContext *ctx);

	void enterUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext *ctx);
	void exitUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext *ctx);

	void enterModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext *ctx);
	void exitModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext *ctx);

	void enterVariable_declaration(GrammarParser::Variable_declarationContext *ctx);
	void exitVariable_declaration(GrammarParser::Variable_declarationContext *ctx);

	void enterInitialization_value(GrammarParser::Initialization_valueContext *ctx);
	void exitInitialization_value(GrammarParser::Initialization_valueContext *ctx);

	void enterArray_initialization_list(GrammarParser::Array_initialization_listContext *ctx);
	void exitArray_initialization_list(GrammarParser::Array_initialization_listContext *ctx);

	void enterDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext *ctx);
	void exitDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext *ctx);

	void enterSet_index_buffer(GrammarParser::Set_index_bufferContext *ctx);
	void exitSet_index_buffer(GrammarParser::Set_index_bufferContext *ctx);

	void enterSet_level_style(GrammarParser::Set_level_styleContext *ctx);
	void exitSet_level_style(GrammarParser::Set_level_styleContext *ctx);

	void enterFunction_definition(GrammarParser::Function_definitionContext *ctx);
	void exitFunction_definition(GrammarParser::Function_definitionContext *ctx);

	void enterFcall_argument(GrammarParser::Fcall_argumentContext *ctx);
	void exitFcall_argument(GrammarParser::Fcall_argumentContext *ctx);

	void enterAny_lex(GrammarParser::Any_lexContext *ctx);
	void exitAny_lex(GrammarParser::Any_lexContext *ctx);

	void enterMl_content(GrammarParser::Ml_contentContext *ctx);
	void exitMl_content(GrammarParser::Ml_contentContext *ctx);

	void enterOl_content(GrammarParser::Ol_contentContext *ctx);
	void exitOl_content(GrammarParser::Ol_contentContext *ctx);

	void enterNo_comma_sq_br(GrammarParser::No_comma_sq_brContext *ctx);
	void exitNo_comma_sq_br(GrammarParser::No_comma_sq_brContext *ctx);

	void visitTerminal(TerminalNode *node);
	void visitErrorNode(ErrorNode *node);

	void enterEveryRule(ParserRuleContext *ctx);
	void exitEveryRule(ParserRuleContext *ctx);
};

