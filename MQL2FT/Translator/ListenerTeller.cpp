#include "ListenerTeller.h"

ListenerTeller::ListenerTeller(
	ofstream* target, 
	ofstream* header_target,
	string* text_include, 
	ostream* output
	) : Listener(target, header_target, text_include)
{
	lexer = std::make_unique<GrammarLexer>(nullptr);
	out = output;
}


ListenerTeller::~ListenerTeller()
{
}

void ListenerTeller::Padd() {
	*this->out << std::string(2*p, ' ');
}

void ListenerTeller::PrintEnter(const string& text) {
	Padd();
	*this->out << text << " {" << endl;
	p++;
}

void ListenerTeller::PrintClose() {
	p--;
	Padd();
	*this->out << "}" << endl;
}

void ListenerTeller::enterCompileUnit(GrammarParser::CompileUnitContext * ctx)
{
	this->Listener::enterCompileUnit(ctx);
	PrintEnter("CompileUnit");
}

void ListenerTeller::exitCompileUnit(GrammarParser::CompileUnitContext * ctx)
{
	this->Listener::exitCompileUnit(ctx);
	PrintClose();
}

void ListenerTeller::enterUnit(GrammarParser::UnitContext * ctx)
{
	PrintEnter("Unit");

	Listener::enterUnit(ctx);
}

void ListenerTeller::exitUnit(GrammarParser::UnitContext * ctx)
{
	Listener::exitUnit(ctx);

	PrintClose();
}

void ListenerTeller::enterFunction_scope(GrammarParser::Function_scopeContext * ctx)
{
	PrintEnter("FunctionScope");

	Listener::enterFunction_scope(ctx);
}

void ListenerTeller::exitFunction_scope(GrammarParser::Function_scopeContext * ctx)
{
	Listener::exitFunction_scope(ctx);

	PrintClose();
}

void ListenerTeller::enterScope_content(GrammarParser::Scope_contentContext * ctx)
{
	//PrintEnter("ScopeContent");

	Listener::enterScope_content(ctx);
}

void ListenerTeller::exitScope_content(GrammarParser::Scope_contentContext * ctx)
{
	Listener::exitScope_content(ctx);

	//PrintClose();
}

void ListenerTeller::enterFor_loop(GrammarParser::For_loopContext * ctx)
{
	PrintEnter("ForLoop");

	Listener::enterFor_loop(ctx);
}

void ListenerTeller::exitFor_loop(GrammarParser::For_loopContext * ctx)
{
	Listener::exitFor_loop(ctx);

	PrintClose();
}

void ListenerTeller::enterRvalue(GrammarParser::RvalueContext * ctx)
{
	PrintEnter("RValue");

	Listener::enterRvalue(ctx);
}

void ListenerTeller::exitRvalue(GrammarParser::RvalueContext * ctx)
{
	Listener::exitRvalue(ctx);

	PrintClose();
}

void ListenerTeller::enterParantheses_content(GrammarParser::Parantheses_contentContext * ctx)
{
	PrintEnter("ParanthesesContent");

	Listener::enterParantheses_content(ctx);
}

void ListenerTeller::exitParantheses_content(GrammarParser::Parantheses_contentContext * ctx)
{
	Listener::exitParantheses_content(ctx);

	PrintClose();
}

void ListenerTeller::enterArgument_content(GrammarParser::Argument_contentContext * ctx)
{
	PrintEnter("ArgumentContent");

	Listener::enterArgument_content(ctx);
}

void ListenerTeller::exitArgument_content(GrammarParser::Argument_contentContext * ctx)
{
	Listener::exitArgument_content(ctx);

	PrintClose();
}

void ListenerTeller::enterFunction_call(GrammarParser::Function_callContext * ctx)
{
	PrintEnter("FunctionCall");

	Listener::enterFunction_call(ctx);
}

void ListenerTeller::exitFunction_call(GrammarParser::Function_callContext * ctx)
{
	Listener::exitFunction_call(ctx);

	PrintClose();
}

void ListenerTeller::enterEntry_point(GrammarParser::Entry_pointContext * ctx)
{
	PrintEnter("EntryPoint");

	Listener::enterEntry_point(ctx);
}

void ListenerTeller::exitEntry_point(GrammarParser::Entry_pointContext * ctx)
{
	Listener::exitEntry_point(ctx);

	PrintClose();
}

void ListenerTeller::enterSq_arguments(GrammarParser::Sq_argumentsContext * ctx)
{
	Listener::enterSq_arguments(ctx);

	PrintEnter("Sq_arguments");
}

void ListenerTeller::exitSq_arguments(GrammarParser::Sq_argumentsContext * ctx)
{
	Listener::exitSq_arguments(ctx);

	PrintClose();
}

void ListenerTeller::enterSq_content(GrammarParser::Sq_contentContext * ctx)
{
Listener::enterSq_content(ctx);
	PrintEnter("Sq_content");
}

void ListenerTeller::exitSq_content(GrammarParser::Sq_contentContext * ctx)
{
Listener::exitSq_content(ctx);
	PrintClose();
}

void ListenerTeller::enterStr(GrammarParser::StrContext * ctx)
{
Listener::enterStr(ctx);
	PrintEnter("Str");
}

void ListenerTeller::exitStr(GrammarParser::StrContext * ctx)
{
Listener::exitStr(ctx);
	PrintClose();
}

void ListenerTeller::enterDirective(GrammarParser::DirectiveContext * ctx)
{
	Listener::enterDirective(ctx);

	PrintEnter("Directive");
}

void ListenerTeller::exitDirective(GrammarParser::DirectiveContext * ctx)
{
	Listener::exitDirective(ctx);

	PrintClose();
}

void ListenerTeller::enterProperty(GrammarParser::PropertyContext *ctx) 
{
	PrintEnter("Property");

	Listener::enterProperty(ctx);
}

void ListenerTeller::exitProperty(GrammarParser::PropertyContext *ctx) {

	Listener::exitProperty(ctx);

	PrintClose();
}

void ListenerTeller::enterProperty_content(GrammarParser::Property_contentContext * ctx)
{
	PrintEnter("PropertyContent");

	Listener::enterProperty_content(ctx);
}

void ListenerTeller::exitProperty_content(GrammarParser::Property_contentContext * ctx)
{
	Listener::exitProperty_content(ctx);

	PrintClose();
}

void ListenerTeller::enterProperty_style_definition(GrammarParser::Property_style_definitionContext * ctx)
{
	PrintEnter("PropertyStyleDefinition");

	Listener::enterProperty_style_definition(ctx);
}

void ListenerTeller::exitProperty_style_definition(GrammarParser::Property_style_definitionContext * ctx)
{
	Listener::exitProperty_style_definition(ctx);

	PrintClose();
}

void ListenerTeller::enterVariable_change_value_assignment(GrammarParser::Variable_change_value_assignmentContext * ctx)
{
	PrintEnter("VariableChangeValueAssignement");

	Listener::enterVariable_change_value_assignment(ctx);
}

void ListenerTeller::exitVariable_change_value_assiment(GrammarParser::Variable_change_value_assignmentContext * ctx)
{
	Listener::exitVariable_change_value_assignment(ctx);

	PrintClose();
}

void ListenerTeller::enterVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext * ctx)
{
	PrintEnter("VariableChangeValueNameFirst");

	Listener::enterVariable_change_value_name_fist(ctx);
}

void ListenerTeller::exitVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext * ctx)
{
	Listener::exitVariable_change_value_name_fist(ctx);

	PrintClose();
}

void ListenerTeller::enterVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext * ctx)
{
	PrintEnter("VariableChangeValueNameLast");

	Listener::enterVariable_change_value_name_last(ctx);
}

void ListenerTeller::exitVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext * ctx)
{
	Listener::exitVariable_change_value_name_last(ctx);

	PrintClose();
}

void ListenerTeller::enterSubscript_operator(GrammarParser::Subscript_operatorContext * ctx)
{
	PrintEnter("SubscriptOperator");

	Listener::enterSubscript_operator(ctx);
}

void ListenerTeller::exitSubscript_operator(GrammarParser::Subscript_operatorContext * ctx)
{
	Listener::exitSubscript_operator(ctx);

	PrintClose();
}

void ListenerTeller::enterExpression(GrammarParser::ExpressionContext * ctx)
{
	PrintEnter("Expression");

	Listener::enterExpression(ctx);
}

void ListenerTeller::exitExpression(GrammarParser::ExpressionContext * ctx)
{
	Listener::exitExpression(ctx);

	PrintClose();
}

void ListenerTeller::enterAdd_brackets(GrammarParser::Add_bracketsContext *ctx)
{
	Listener::enterAdd_brackets(ctx);

	PrintEnter("AddBrackets");
}

void ListenerTeller::exitAdd_brackets(GrammarParser::Add_bracketsContext *ctx) 
{
	Listener::exitAdd_brackets(ctx);

	PrintClose();
}

void ListenerTeller::enterChange_brackets(GrammarParser::Change_bracketsContext *ctx) 
{
	Listener::enterChange_brackets(ctx);

	PrintEnter("ChangeBrackets");
}

void ListenerTeller::exitChange_brackets(GrammarParser::Change_bracketsContext *ctx) 
{
	Listener::exitChange_brackets(ctx);

	PrintClose();
}

void ListenerTeller::enterUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext * ctx)
{
	Listener::enterUnsupported_object_properties(ctx);

	PrintEnter("UnsupportedObjectProperties");
}

void ListenerTeller::exitUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext * ctx)
{
	Listener::exitUnsupported_object_properties(ctx);

	PrintClose();
}

void ListenerTeller::enterModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext * ctx)
{
	PrintEnter("ModifierVariableDeclaration");

	Listener::enterModifier_variable_declaration(ctx);
}

void ListenerTeller::exitModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext * ctx)
{
	Listener::exitModifier_variable_declaration(ctx);

	PrintClose();
}

void ListenerTeller::enterVariable_declaration(GrammarParser::Variable_declarationContext * ctx)
{
	PrintEnter("VariableDeclaration");

	Listener::enterVariable_declaration(ctx);
}

void ListenerTeller::exitVariable_declaration(GrammarParser::Variable_declarationContext * ctx)
{
	Listener::exitVariable_declaration(ctx);

	PrintClose();
}

void ListenerTeller::enterInitialization_value(GrammarParser::Initialization_valueContext * ctx)
{
	PrintEnter("InitializationValue");

	Listener::enterInitialization_value(ctx);
}

void ListenerTeller::exitInitialization_value(GrammarParser::Initialization_valueContext * ctx)
{
	Listener::exitInitialization_value(ctx);

	PrintClose();
}

void ListenerTeller::enterArray_initialization_list(GrammarParser::Array_initialization_listContext * ctx)
{
	PrintEnter("ArrayInitializationList");

	Listener::enterArray_initialization_list(ctx);
}

void ListenerTeller::exitArray_initialization_list(GrammarParser::Array_initialization_listContext * ctx)
{
	Listener::exitArray_initialization_list(ctx);

	PrintClose();
}

void ListenerTeller::enterDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext * ctx)
{
	PrintEnter("DynamicArrayBracketsParams");

	Listener::enterDynamic_array_brackets_params(ctx);
}

void ListenerTeller::exitDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext * ctx)
{
	Listener::exitDynamic_array_brackets_params(ctx);

	PrintClose();
}

void ListenerTeller::enterSet_index_buffer(GrammarParser::Set_index_bufferContext * ctx)
{
	Listener::enterSet_index_buffer(ctx);

	PrintEnter("SetIndexBuffer");
}

void ListenerTeller::exitSet_index_buffer(GrammarParser::Set_index_bufferContext * ctx)
{
	Listener::exitSet_index_buffer(ctx);

	PrintClose();
}

void ListenerTeller::enterSet_level_style(GrammarParser::Set_level_styleContext * ctx)
{
	Listener::enterSet_level_style(ctx);

	PrintEnter("SetLevelStyle");
}

void ListenerTeller::exitSet_level_style(GrammarParser::Set_level_styleContext * ctx)
{
	Listener::exitSet_level_style(ctx);

	PrintClose();
}

void ListenerTeller::enterFunction_definition(GrammarParser::Function_definitionContext * ctx)
{
	Listener::enterFunction_definition(ctx);

	PrintEnter("FunctionDefinition");
}

void ListenerTeller::exitFunction_definition(GrammarParser::Function_definitionContext * ctx)
{
	Listener::exitFunction_definition(ctx);

	PrintClose();
}

void ListenerTeller::enterFcall_argument(GrammarParser::Fcall_argumentContext * ctx)
{
	Listener::enterFcall_argument(ctx);

	PrintEnter("FCallArgument");
}

void ListenerTeller::exitFcall_argument(GrammarParser::Fcall_argumentContext * ctx)
{
	Listener::exitFcall_argument(ctx);

	PrintClose();
}

void ListenerTeller::enterUnsupported_object_types(GrammarParser::Unsupported_object_typesContext *ctx) 
{
	Listener::enterUnsupported_object_types(ctx);

	PrintEnter("UnsupportedObjectTypes");
}

void ListenerTeller::exitUnsupported_object_types(GrammarParser::Unsupported_object_typesContext *ctx) 
{
	Listener::exitUnsupported_object_types(ctx);

	PrintClose();
}

void ListenerTeller::enterAny_lex(GrammarParser::Any_lexContext * ctx)
{
	PrintEnter("AnyLex");

	Listener::enterAny_lex(ctx);
}

void ListenerTeller::exitAny_lex(GrammarParser::Any_lexContext * ctx)
{
	Listener::exitAny_lex(ctx);

	PrintClose();
}

void ListenerTeller::enterMl_content(GrammarParser::Ml_contentContext *ctx)
{
	Listener::enterMl_content(ctx);
}

void ListenerTeller::exitMl_content(GrammarParser::Ml_contentContext *ctx)
{
	Listener::exitMl_content(ctx);
}

void ListenerTeller::enterOl_content(GrammarParser::Ol_contentContext *ctx)
{
	Listener::enterOl_content(ctx);
}
void ListenerTeller::exitOl_content(GrammarParser::Ol_contentContext *ctx)
{
	Listener::exitOl_content(ctx);
}

void ListenerTeller::enterNo_comma_sq_br(GrammarParser::No_comma_sq_brContext * ctx)
{
	PrintEnter("NoCommaSqBr");

	Listener::enterNo_comma_sq_br(ctx);
}

void ListenerTeller::exitNo_comma_sq_br(GrammarParser::No_comma_sq_brContext * ctx)
{
	Listener::exitNo_comma_sq_br(ctx);

	PrintClose();
}

void ListenerTeller::visitTerminal(TerminalNode * node)
{
	size_t node_type = node->getSymbol()->getType();
	string node_text = (node_type == GrammarLexer::NEWLINE ? "\\n" : node->getText());
	string node_name = lexer->getVocabulary().getSymbolicName(node_type);

	Padd();
	*out << node_name << " : \"" << node_text << "\"" << endl;
}

void ListenerTeller::visitErrorNode(ErrorNode * node)
{

}

void ListenerTeller::enterEveryRule(ParserRuleContext * ctx)
{

}

void ListenerTeller::exitEveryRule(ParserRuleContext * ctx)
{

}