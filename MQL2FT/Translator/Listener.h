#pragma once

#include "GrammarListener.h"
#include "src\tree\ErrorNode.h"
#include "src\tree\TerminalNode.h"
#include "src\ParserRuleContext.h"
#include "GrammarParser.h"
#include "PropertyStyle.h"
#include "IndicatorType.h"

#include "InitType.h"
#include "StartType.h"
#include "DeinitType.h"
#include "ErrorType.h"
#include "VariableDeclaration.h"
#include "MultivariableDeclaration.h"
#include "OtType.h"

#include <iostream>
#include <list>
#include <queue>
#include <set>

using namespace antlr4;
using namespace antlr4::tree;

using namespace std;

class Listener : public GrammarListener {
protected:
	bool addedInclude = false;
	int scriptType = 1;
	bool strategy_definitions = false;
	bool indicator_definitions = false;
	bool hooking_funcs_present = false;
	bool on_timer = false;
	bool deinit_found = false;
	int visible_ind_buffs = 0; // Number of visible indicator buffers specified in #property
	int set_ind_buffs = 0; // Number of indicator buffers set via SetIndexBuffer function

	stringstream set_ind_buffs_calls;

	bool generateCompileDT = false;
	
	ErrorType err_type = ErrorType::None;

	InitType initType = InitType::INIT_UNDEFINED;
	DeinitType deinitType = DeinitType::DEINIIT_UNDEFINED;
    StartType startType = StartType::START_UNDEFINED;

	set<string> strategyFunctionsCalls;
	set<string> indicatorFunctionsCalls;
	set<string> input_parameters;
	string* textToInclude;
	stringstream registerOptions_function;

	MultivariableDeclaration* multivar_decl;
	VarType last_var_type = Other;
	VarType assigned_type = Other;
	string implicit_cast = " ";
	stringstream buffer;
	int buffer_level = 0;

	ostream* to;
	ofstream* head;
	ofstream* cpp;

	set<string> indexBuffers;
	map<int, PropertyStyle*> stylesToAdd;
	bool isLevelStyleSet = false;
	bool isStrict = false;

	int comment_counter = 0;

	int scope_level = 0;
	bool isInsideFuncDef = false;
	bool insideForLoop = false;
	bool appendVariable = false;
	string outer_type_name = "";
	string outer_definition_name = "";
	bool isOutputTraverse = false;
	bool notException = true;
	bool output_sq_brackets = true;
    bool isVarNameAndEnumItemTheSame = false;
	unordered_map<string, list<MultivariableDeclaration* >* > function_variables;
    unordered_set<string> enum_constants;

	int dyn_array_dim;
	std::vector<unsigned int> initlist_items_counter;
	unsigned int enclosed_initlist;

	stringstream ind_args_key;
	string shift_parameter;
	vector<string> ind_args;

	// Property level variables
	bool prop_lvl_style_set = false; // Property level style set
	stringstream property_levels_funcs;
	string level_style = "STYLE_DOT";
	string level_width = "1";
	string level_color = "clrSilver";

	// Property minimum/maximum vairables
	bool prop_min_max_set = false;
	string indicator_maximum = "0.0";
	string indicator_minimum = "0.0";

	stringstream property_label_funcs;
protected:
	void SetBuffer();
	string ResetBuffer();

	string* getTOptionType(string& var_type);
	void addIncludeLine();
	void WriteEPTypes();
	void putParameterBefore(string name);
	void setOuterName(string&& name);
	void resetOuterName();
	void setOuterType(string&& name);
	void resetOuterType();
	inline bool isInsideFunctionScope();
	inline bool isOnCalculate();
	void appendAddOptionsFunction();
	inline void generateCompilationDTVariables();

	void GenerateDeclaration();
	void InitializeDeclaration(GrammarParser::Variable_declarationContext * ctx);
	const std::string DetermineOtType(OtType& ot_type);
	void GenerateVariableDecl(bool nonStrictVar, VariableDeclaration * decl);
	void GenerateExternInputVariable(bool is_input, VariableDeclaration * decl);
	bool GenerateTIndexBufferDecl(VariableDeclaration * decl);
	void GenerateArrayDecl(bool nonStrictVar, VariableDeclaration * decl);
	void GenerateArrayType(std::stringstream &ss, VariableDeclaration * decl);
	void GenerateArrayArguments(std::stringstream &ss, VariableDeclaration * decl, string init = "");

    std::string GenerateColorLiteral(GrammarParser::Rgb_litteralContext *ctx);

	void StrategyScript(string&& name);
	void IndicatorScript(string&& name);

	string nameFromSubscript(string& name);

	string getPadding(bool new_line = true);

    inline bool IsEnumConstant(const string& name) const;
    inline bool IsArithmeticType(const string& type_name) const;
	void setImplicitCast(bool declaration = false);

public:
	bool addToBuffers = true;
public:
	Listener(ofstream* target, ofstream* header_target, string* text_include);
	virtual ~Listener();

	int getScriptType();
	ErrorType GetErrorType();
	void SetErrorType(ErrorType type);

	void SetOutpuTraverse(bool output = true);

	void enterCompileUnit(GrammarParser::CompileUnitContext *ctx);
	void exitCompileUnit(GrammarParser::CompileUnitContext *ctx);

	void enterUnit(GrammarParser::UnitContext *ctx);
	void exitUnit(GrammarParser::UnitContext *ctx);

	void enterAny_function_definition(GrammarParser::Any_function_definitionContext *ctx);
	void exitAny_function_definition(GrammarParser::Any_function_definitionContext *ctx);

	void enterAppend_scope(GrammarParser::Append_scopeContext *ctx);
	void exitAppend_scope(GrammarParser::Append_scopeContext *ctx);

	void enterFunction_scope(GrammarParser::Function_scopeContext *ctx);
	void exitFunction_scope(GrammarParser::Function_scopeContext *ctx);

	void enterScope_content(GrammarParser::Scope_contentContext *ctx);
	void exitScope_content(GrammarParser::Scope_contentContext *ctx);

	void enterReturn_statement(GrammarParser::Return_statementContext *ctx);
	void exitReturn_statement(GrammarParser::Return_statementContext *ctx);

	void enterVoid_return(GrammarParser::Void_returnContext * ctx);
	void exitVoid_return(GrammarParser::Void_returnContext * ctx);

	void enterStandart_return(GrammarParser::Standart_returnContext * ctx);
	void exitStandart_return(GrammarParser::Standart_returnContext * ctx);

	void enterFor_loop(GrammarParser::For_loopContext *ctx);
	void exitFor_loop(GrammarParser::For_loopContext *ctx);

	void enterFor_loop_declaration(GrammarParser::For_loop_declarationContext *ctx);
	void exitFor_loop_declaration(GrammarParser::For_loop_declarationContext *ctx);

	void enterFor_loop_variable_decl(GrammarParser::For_loop_variable_declContext *ctx);
	void exitFor_loop_variable_decl(GrammarParser::For_loop_variable_declContext *ctx);

	void enterFor_loop_condition(GrammarParser::For_loop_conditionContext *ctx);
	void exitFor_loop_condition(GrammarParser::For_loop_conditionContext *ctx);

	void enterFor_loop_increment(GrammarParser::For_loop_incrementContext *ctx);
	void exitFor_loop_increment(GrammarParser::For_loop_incrementContext *ctx);

	void enterFor_loop_append_increment(GrammarParser::For_loop_append_incrementContext *ctx);
	void exitFor_loop_append_increment(GrammarParser::For_loop_append_incrementContext *ctx);

	void enterRvalue(GrammarParser::RvalueContext *ctx);
	void exitRvalue(GrammarParser::RvalueContext *ctx);

	void enterParantheses_content(GrammarParser::Parantheses_contentContext *ctx);
	void exitParantheses_content(GrammarParser::Parantheses_contentContext *ctx);

	void enterParantheses_content_expression(GrammarParser::Parantheses_content_expressionContext *ctx);
	void exitParantheses_content_expression(GrammarParser::Parantheses_content_expressionContext *ctx);

	void enterNo_parant_comma_sc(GrammarParser::No_parant_comma_scContext *ctx);
	void exitNo_parant_comma_sc(GrammarParser::No_parant_comma_scContext *ctx);

	void enterArgument_content(GrammarParser::Argument_contentContext *ctx);
	void exitArgument_content(GrammarParser::Argument_contentContext *ctx);

	void enterCommented_block(GrammarParser::Commented_blockContext *ctx); 
	void exitCommented_block(GrammarParser::Commented_blockContext *ctx); 

	void enterFunction_call(GrammarParser::Function_callContext *ctx); 
	void exitFunction_call(GrammarParser::Function_callContext *ctx); 

	void enterAny_function_call(GrammarParser::Any_function_callContext *ctx);
	void exitAny_function_call(GrammarParser::Any_function_callContext *ctx);

    void enterAny_fcall_parantheses_expr(GrammarParser::Any_fcall_parantheses_exprContext * ctx);
    void exitAny_fcall_parantheses_expr(GrammarParser::Any_fcall_parantheses_exprContext * ctx);
    
	void enterAny_fcall_parantheses_content(GrammarParser::Any_fcall_parantheses_contentContext *ctx);
	void exitAny_fcall_parantheses_content(GrammarParser::Any_fcall_parantheses_contentContext *ctx);

	void enterAny_fcall_append_argument(GrammarParser::Any_fcall_append_argumentContext *ctx);
	void exitAny_fcall_append_argument(GrammarParser::Any_fcall_append_argumentContext *ctx);

	void enterEntry_point(GrammarParser::Entry_pointContext *ctx); 
	void exitEntry_point(GrammarParser::Entry_pointContext *ctx); 
	
	void enterSingle_name(GrammarParser::Single_nameContext *ctx); 
	void exitSingle_name(GrammarParser::Single_nameContext *ctx); 

	void enterDatetime_litteral(GrammarParser::Datetime_litteralContext *ctx);
	void exitDatetime_litteral(GrammarParser::Datetime_litteralContext *ctx);

	void enterAppend_time_litteral(GrammarParser::Append_time_litteralContext *ctx);
	void exitAppend_time_litteral(GrammarParser::Append_time_litteralContext *ctx);

	void enterDate_litteral(GrammarParser::Date_litteralContext *ctx);
	void exitDate_litteral(GrammarParser::Date_litteralContext *ctx);

	void enterTime_litteral(GrammarParser::Time_litteralContext *ctx);
	void exitTime_litteral(GrammarParser::Time_litteralContext *ctx);

	void enterColor_litteral(GrammarParser::Color_litteralContext *ctx);
	void exitColor_litteral(GrammarParser::Color_litteralContext *ctx);

	void enterRgb_litteral(GrammarParser::Rgb_litteralContext *ctx);
    void exitRgb_litteral(GrammarParser::Rgb_litteralContext *ctx);

	void enterHex_or_regular_integer(GrammarParser::Hex_or_regular_integerContext *ctx);
	void exitHex_or_regular_integer(GrammarParser::Hex_or_regular_integerContext *ctx);

	void enterSq_arguments(GrammarParser::Sq_argumentsContext *ctx);
	void exitSq_arguments(GrammarParser::Sq_argumentsContext *ctx);

	void enterSq_content(GrammarParser::Sq_contentContext *ctx);
	void exitSq_content(GrammarParser::Sq_contentContext *ctx);

	void enterAppend_sq_content(GrammarParser::Append_sq_contentContext *ctx);
	void exitAppend_sq_content(GrammarParser::Append_sq_contentContext *ctx);

	void enterSq_brackets_argument(GrammarParser::Sq_brackets_argumentContext *ctx);
	void exitSq_brackets_argument(GrammarParser::Sq_brackets_argumentContext *ctx);

	void enterSq_brackets_anyrule(GrammarParser::Sq_brackets_anyruleContext *ctx);
	void exitSq_brackets_anyrule(GrammarParser::Sq_brackets_anyruleContext *ctx);

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
	void exitVariable_change_value_assignment(GrammarParser::Variable_change_value_assignmentContext *ctx);

	void enterVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext *ctx);
	void exitVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext *ctx);

	void enterVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext *ctx);
	void exitVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext *ctx);

	void enterSubscript_operator(GrammarParser::Subscript_operatorContext *ctx);
	void exitSubscript_operator(GrammarParser::Subscript_operatorContext *ctx);

	void enterMulti_assignment(GrammarParser::Multi_assignmentContext *ctx);
	void exitMulti_assignment(GrammarParser::Multi_assignmentContext *ctx);

    void enterLast_multi_assignment_rvalue(GrammarParser::Last_multi_assignment_rvalueContext *ctx);
    void exitLast_multi_assignment_rvalue(GrammarParser::Last_multi_assignment_rvalueContext *ctx);

	void enterExpression(GrammarParser::ExpressionContext *ctx);
	void exitExpression(GrammarParser::ExpressionContext *ctx);

    void enterOp_expr(GrammarParser::Op_exprContext *ctx);
    void exitOp_expr(GrammarParser::Op_exprContext *ctx);

	void enterBinary_operator(GrammarParser::Binary_operatorContext *ctx);
	void exitBinary_operator(GrammarParser::Binary_operatorContext *ctx);

	void enterUnary_operator(GrammarParser::Unary_operatorContext *ctx);
	void exitUnary_operator(GrammarParser::Unary_operatorContext *ctx);

    void enterSingle_expr_space(GrammarParser::Single_expr_spaceContext *ctx);
    void exitSingle_expr_space(GrammarParser::Single_expr_spaceContext *ctx);

	void enterSingle_expr(GrammarParser::Single_exprContext *ctx);
	void exitSingle_expr(GrammarParser::Single_exprContext *ctx);
	
	void enterAsssignment_operator(GrammarParser::Asssignment_operatorContext *ctx);
	void exitAsssignment_operator(GrammarParser::Asssignment_operatorContext *ctx);

	void enterEnum_extract2header(GrammarParser::Enum_extract2headerContext *ctx);
	void exitEnum_extract2header(GrammarParser::Enum_extract2headerContext *ctx);

	void enterEnum_declaration(GrammarParser::Enum_declarationContext *ctx);
	void exitEnum_declaration(GrammarParser::Enum_declarationContext *ctx);

	void enterEnum_item_list(GrammarParser::Enum_item_listContext *ctx);
	void exitEnum_item_list(GrammarParser::Enum_item_listContext *ctx);

	void enterEnum_item(GrammarParser::Enum_itemContext *ctx);
	void exitEnum_item(GrammarParser::Enum_itemContext *ctx);

	void enterVariable_change_value(GrammarParser::Variable_change_valueContext *ctx);
	void exitVariable_change_value(GrammarParser::Variable_change_valueContext *ctx);

	void enterAdd_brackets(GrammarParser::Add_bracketsContext *ctx);
	void exitAdd_brackets(GrammarParser::Add_bracketsContext *ctx);

	void enterChange_brackets(GrammarParser::Change_bracketsContext *ctx);
	void exitChange_brackets(GrammarParser::Change_bracketsContext *ctx);

	void enterUnsupported_object_types(GrammarParser::Unsupported_object_typesContext *ctx);
	void exitUnsupported_object_types(GrammarParser::Unsupported_object_typesContext *ctx);

	void enterUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext *ctx);
	void exitUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext *ctx);

	void enterReturn_datetime(GrammarParser::Return_datetimeContext *ctx);
	void exitReturn_datetime(GrammarParser::Return_datetimeContext *ctx);

	void enterIndicator_buffers_func(GrammarParser::Indicator_buffers_funcContext *ctx);
	void exitIndicator_buffers_func(GrammarParser::Indicator_buffers_funcContext *ctx);

	void enterArg_comma(GrammarParser::Arg_commaContext *ctx);
	void exitArg_comma(GrammarParser::Arg_commaContext *ctx);

	void enterParantheses_any_expression(GrammarParser::Parantheses_any_expressionContext *ctx);
	void exitParantheses_any_expression(GrammarParser::Parantheses_any_expressionContext *ctx);

	void enterNo_parant_sc(GrammarParser::No_parant_scContext *ctx);
	void exitNo_parant_sc(GrammarParser::No_parant_scContext *ctx);

	void enterModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext *ctx);
	void exitModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext *ctx);

	void enterVariable_declaration(GrammarParser::Variable_declarationContext *ctx);
	void exitVariable_declaration(GrammarParser::Variable_declarationContext *ctx);

	void enterAppend_variable_declaration(GrammarParser::Append_variable_declarationContext *ctx);
	void exitAppend_variable_declaration(GrammarParser::Append_variable_declarationContext *ctx);

	void enterInitialization_value(GrammarParser::Initialization_valueContext *ctx);
	void exitInitialization_value(GrammarParser::Initialization_valueContext *ctx);

	void enterArray_initialization_list(GrammarParser::Array_initialization_listContext *ctx);
	void exitArray_initialization_list(GrammarParser::Array_initialization_listContext *ctx);

	void enterInitialization_list_append_items(GrammarParser::Initialization_list_append_itemsContext *ctx);
	void exitInitialization_list_append_items(GrammarParser::Initialization_list_append_itemsContext *ctx);

	void enterInitialization_list_items(GrammarParser::Initialization_list_itemsContext *ctx);
	void exitInitialization_list_items(GrammarParser::Initialization_list_itemsContext *ctx);

	void enterInitialization_list_item(GrammarParser::Initialization_list_itemContext *ctx);
	void exitInitialization_list_item(GrammarParser::Initialization_list_itemContext *ctx);

	void enterConst_name(GrammarParser::Const_nameContext *ctx);
	void exitConst_name(GrammarParser::Const_nameContext *ctx);

	void enterDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext *ctx);
	void exitDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext *ctx);

	void enterDynamic_array_brackets_parameter(GrammarParser::Dynamic_array_brackets_parameterContext *ctx);
	void exitDynamic_array_brackets_parameter(GrammarParser::Dynamic_array_brackets_parameterContext *ctx);

	void enterDynamic_array_append_parameter(GrammarParser::Dynamic_array_append_parameterContext *ctx);
	void exitDynamic_array_append_parameter(GrammarParser::Dynamic_array_append_parameterContext *ctx);

	void enterDynamic_array_parameter(GrammarParser::Dynamic_array_parameterContext *ctx);
	void exitDynamic_array_parameter(GrammarParser::Dynamic_array_parameterContext *ctx);

	void enterSet_index_buffer(GrammarParser::Set_index_bufferContext *ctx);
	void exitSet_index_buffer(GrammarParser::Set_index_bufferContext *ctx);

	void enterSet_level_style(GrammarParser::Set_level_styleContext *ctx);
	void exitSet_level_style(GrammarParser::Set_level_styleContext *ctx);
    
	void enterAlert(GrammarParser::AlertContext *ctx);
	void exitAlert(GrammarParser::AlertContext *ctx);

	void enterFunction_definition(GrammarParser::Function_definitionContext *ctx);
	void exitFunction_definition(GrammarParser::Function_definitionContext *ctx);

	void enterType(GrammarParser::TypeContext *ctx);
	void exitType(GrammarParser::TypeContext *ctx);

	void enterType_name(GrammarParser::Type_nameContext *ctx) ;
	void exitType_name(GrammarParser::Type_nameContext *ctx) ;

	void enterParams_list(GrammarParser::Params_listContext *ctx);
	void exitParams_list(GrammarParser::Params_listContext *ctx);

	void enterAppend_argument(GrammarParser::Append_argumentContext *ctx);
	void exitAppend_argument(GrammarParser::Append_argumentContext *ctx);

	void enterArgument(GrammarParser::ArgumentContext *ctx);
	void exitArgument(GrammarParser::ArgumentContext *ctx);

	void enterFcall_argument(GrammarParser::Fcall_argumentContext *ctx);
	void exitFcall_argument(GrammarParser::Fcall_argumentContext *ctx);

	void enterFcall_anyrule(GrammarParser::Fcall_anyruleContext *ctx);
	void exitFcall_anyrule(GrammarParser::Fcall_anyruleContext *ctx);

	void enterFcall_params(GrammarParser::Fcall_paramsContext *ctx);
	void exitFcall_params(GrammarParser::Fcall_paramsContext *ctx);

	void enterFcall_params_list(GrammarParser::Fcall_params_listContext *ctx);
	void exitFcall_params_list(GrammarParser::Fcall_params_listContext *ctx);

	void enterAppend_fcall_argument(GrammarParser::Append_fcall_argumentContext *ctx);
	void exitAppend_fcall_argument(GrammarParser::Append_fcall_argumentContext *ctx);

	void enterDeinit_function_call(GrammarParser::Deinit_function_callContext *ctx);
	void exitDeinit_function_call(GrammarParser::Deinit_function_callContext *ctx);

	void enterInit_function_call(GrammarParser::Init_function_callContext *ctx);
	void exitInit_function_call(GrammarParser::Init_function_callContext *ctx);

	void enterStart_function_call(GrammarParser::Start_function_callContext *ctx);
	void exitStart_function_call(GrammarParser::Start_function_callContext *ctx);

	void enterOn_calculate_handler(GrammarParser::On_calculate_handlerContext *ctx);
	void exitOn_calculate_handler(GrammarParser::On_calculate_handlerContext *ctx);

	void enterOn_tick_handler(GrammarParser::On_tick_handlerContext *ctx);
	void exitOn_tick_handler(GrammarParser::On_tick_handlerContext *ctx);

	void enterOn_init_handler(GrammarParser::On_init_handlerContext *ctx);
	void exitOn_init_handler(GrammarParser::On_init_handlerContext *ctx);

	void enterOn_deinit_handler(GrammarParser::On_deinit_handlerContext *ctx);
	void exitOn_deinit_handler(GrammarParser::On_deinit_handlerContext *ctx);

	void enterOn_timer_handler(GrammarParser::On_timer_handlerContext *ctx);
	void exitOn_timer_handler(GrammarParser::On_timer_handlerContext *ctx);

	void enterOn_chart_event_handler(GrammarParser::On_chart_event_handlerContext *ctx);
	void exitOn_chart_event_handler(GrammarParser::On_chart_event_handlerContext *ctx);

	void enterName(GrammarParser::NameContext *ctx);
	void exitName(GrammarParser::NameContext *ctx);

	void enterSpace(GrammarParser::SpaceContext *ctx);
	void exitSpace(GrammarParser::SpaceContext *ctx);

	void enterInteger(GrammarParser::IntegerContext *ctx);
	void exitInteger(GrammarParser::IntegerContext *ctx);

	void enterFloat_value(GrammarParser::Float_valueContext *ctx);
	void exitFloat_value(GrammarParser::Float_valueContext *ctx);

	void enterAny_lex(GrammarParser::Any_lexContext *ctx);
	void exitAny_lex(GrammarParser::Any_lexContext *ctx);

	void enterParantheses_expression(GrammarParser::Parantheses_expressionContext *ctx);
	void exitParantheses_expression(GrammarParser::Parantheses_expressionContext *ctx);

	void enterTryblock_replacement_start(GrammarParser::Tryblock_replacement_startContext *ctx);
	void exitTryblock_replacement_start(GrammarParser::Tryblock_replacement_startContext *ctx);

	void enterTryblock_replacement_end(GrammarParser::Tryblock_replacement_endContext *ctx);
	void exitTryblock_replacement_end(GrammarParser::Tryblock_replacement_endContext *ctx);

	void enterMl_content(GrammarParser::Ml_contentContext *ctx);
	void exitMl_content(GrammarParser::Ml_contentContext *ctx);

	void enterOl_content(GrammarParser::Ol_contentContext *ctx);
	void exitOl_content(GrammarParser::Ol_contentContext *ctx);

	void enterNo_cl_parentheses(GrammarParser::No_cl_parenthesesContext *ctx);
	void exitNo_cl_parentheses(GrammarParser::No_cl_parenthesesContext *ctx);

	void enterNo_semicolon(GrammarParser::No_semicolonContext *ctx);
	void exitNo_semicolon(GrammarParser::No_semicolonContext *ctx);

	void enterNo_comma(GrammarParser::No_commaContext *ctx);
	void exitNo_comma(GrammarParser::No_commaContext *ctx);

	void enterNo_comma_sq_br(GrammarParser::No_comma_sq_brContext *ctx);
	void exitNo_comma_sq_br(GrammarParser::No_comma_sq_brContext *ctx);

	void enterNo_comma_semicolon(GrammarParser::No_comma_semicolonContext *ctx);
	void exitNo_comma_semicolon(GrammarParser::No_comma_semicolonContext *ctx);

	void visitTerminal(TerminalNode *node);
	void visitErrorNode(ErrorNode *node);

	void enterEveryRule(ParserRuleContext *ctx);
	void exitEveryRule(ParserRuleContext *ctx);
};

