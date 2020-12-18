
// Generated from c:\Projects\ForexTester\MQL2FT_REPO\MQL2FT\MQL2FT\Translator\Grammar.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "GrammarListener.h"


/**
 * This class provides an empty implementation of GrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GrammarBaseListener : public GrammarListener {
public:

  virtual void enterCompileUnit(GrammarParser::CompileUnitContext * /*ctx*/) override { }
  virtual void exitCompileUnit(GrammarParser::CompileUnitContext * /*ctx*/) override { }

  virtual void enterUnit(GrammarParser::UnitContext * /*ctx*/) override { }
  virtual void exitUnit(GrammarParser::UnitContext * /*ctx*/) override { }

  virtual void enterAny_function_definition(GrammarParser::Any_function_definitionContext * /*ctx*/) override { }
  virtual void exitAny_function_definition(GrammarParser::Any_function_definitionContext * /*ctx*/) override { }

  virtual void enterAppend_scope(GrammarParser::Append_scopeContext * /*ctx*/) override { }
  virtual void exitAppend_scope(GrammarParser::Append_scopeContext * /*ctx*/) override { }

  virtual void enterFunction_scope(GrammarParser::Function_scopeContext * /*ctx*/) override { }
  virtual void exitFunction_scope(GrammarParser::Function_scopeContext * /*ctx*/) override { }

  virtual void enterScope_content(GrammarParser::Scope_contentContext * /*ctx*/) override { }
  virtual void exitScope_content(GrammarParser::Scope_contentContext * /*ctx*/) override { }

  virtual void enterReturn_statement(GrammarParser::Return_statementContext * /*ctx*/) override { }
  virtual void exitReturn_statement(GrammarParser::Return_statementContext * /*ctx*/) override { }

  virtual void enterVoid_return(GrammarParser::Void_returnContext * /*ctx*/) override { }
  virtual void exitVoid_return(GrammarParser::Void_returnContext * /*ctx*/) override { }

  virtual void enterStandart_return(GrammarParser::Standart_returnContext * /*ctx*/) override { }
  virtual void exitStandart_return(GrammarParser::Standart_returnContext * /*ctx*/) override { }

  virtual void enterFor_loop(GrammarParser::For_loopContext * /*ctx*/) override { }
  virtual void exitFor_loop(GrammarParser::For_loopContext * /*ctx*/) override { }

  virtual void enterFor_loop_declaration(GrammarParser::For_loop_declarationContext * /*ctx*/) override { }
  virtual void exitFor_loop_declaration(GrammarParser::For_loop_declarationContext * /*ctx*/) override { }

  virtual void enterFor_loop_variable_decl(GrammarParser::For_loop_variable_declContext * /*ctx*/) override { }
  virtual void exitFor_loop_variable_decl(GrammarParser::For_loop_variable_declContext * /*ctx*/) override { }

  virtual void enterFor_loop_condition(GrammarParser::For_loop_conditionContext * /*ctx*/) override { }
  virtual void exitFor_loop_condition(GrammarParser::For_loop_conditionContext * /*ctx*/) override { }

  virtual void enterFor_loop_increment(GrammarParser::For_loop_incrementContext * /*ctx*/) override { }
  virtual void exitFor_loop_increment(GrammarParser::For_loop_incrementContext * /*ctx*/) override { }

  virtual void enterFor_loop_append_increment(GrammarParser::For_loop_append_incrementContext * /*ctx*/) override { }
  virtual void exitFor_loop_append_increment(GrammarParser::For_loop_append_incrementContext * /*ctx*/) override { }

  virtual void enterRvalue(GrammarParser::RvalueContext * /*ctx*/) override { }
  virtual void exitRvalue(GrammarParser::RvalueContext * /*ctx*/) override { }

  virtual void enterParantheses_any_expression(GrammarParser::Parantheses_any_expressionContext * /*ctx*/) override { }
  virtual void exitParantheses_any_expression(GrammarParser::Parantheses_any_expressionContext * /*ctx*/) override { }

  virtual void enterParantheses_content(GrammarParser::Parantheses_contentContext * /*ctx*/) override { }
  virtual void exitParantheses_content(GrammarParser::Parantheses_contentContext * /*ctx*/) override { }

  virtual void enterParantheses_content_expression(GrammarParser::Parantheses_content_expressionContext * /*ctx*/) override { }
  virtual void exitParantheses_content_expression(GrammarParser::Parantheses_content_expressionContext * /*ctx*/) override { }

  virtual void enterNo_parant_comma_sc(GrammarParser::No_parant_comma_scContext * /*ctx*/) override { }
  virtual void exitNo_parant_comma_sc(GrammarParser::No_parant_comma_scContext * /*ctx*/) override { }

  virtual void enterNo_parant_sc(GrammarParser::No_parant_scContext * /*ctx*/) override { }
  virtual void exitNo_parant_sc(GrammarParser::No_parant_scContext * /*ctx*/) override { }

  virtual void enterArgument_content(GrammarParser::Argument_contentContext * /*ctx*/) override { }
  virtual void exitArgument_content(GrammarParser::Argument_contentContext * /*ctx*/) override { }

  virtual void enterCommented_block(GrammarParser::Commented_blockContext * /*ctx*/) override { }
  virtual void exitCommented_block(GrammarParser::Commented_blockContext * /*ctx*/) override { }

  virtual void enterFunction_call(GrammarParser::Function_callContext * /*ctx*/) override { }
  virtual void exitFunction_call(GrammarParser::Function_callContext * /*ctx*/) override { }

  virtual void enterAny_function_call(GrammarParser::Any_function_callContext * /*ctx*/) override { }
  virtual void exitAny_function_call(GrammarParser::Any_function_callContext * /*ctx*/) override { }

  virtual void enterAny_fcall_parantheses_expr(GrammarParser::Any_fcall_parantheses_exprContext * /*ctx*/) override { }
  virtual void exitAny_fcall_parantheses_expr(GrammarParser::Any_fcall_parantheses_exprContext * /*ctx*/) override { }

  virtual void enterAny_fcall_parantheses_content(GrammarParser::Any_fcall_parantheses_contentContext * /*ctx*/) override { }
  virtual void exitAny_fcall_parantheses_content(GrammarParser::Any_fcall_parantheses_contentContext * /*ctx*/) override { }

  virtual void enterAny_fcall_append_argument(GrammarParser::Any_fcall_append_argumentContext * /*ctx*/) override { }
  virtual void exitAny_fcall_append_argument(GrammarParser::Any_fcall_append_argumentContext * /*ctx*/) override { }

  virtual void enterEntry_point(GrammarParser::Entry_pointContext * /*ctx*/) override { }
  virtual void exitEntry_point(GrammarParser::Entry_pointContext * /*ctx*/) override { }

  virtual void enterSingle_name(GrammarParser::Single_nameContext * /*ctx*/) override { }
  virtual void exitSingle_name(GrammarParser::Single_nameContext * /*ctx*/) override { }

  virtual void enterDatetime_litteral(GrammarParser::Datetime_litteralContext * /*ctx*/) override { }
  virtual void exitDatetime_litteral(GrammarParser::Datetime_litteralContext * /*ctx*/) override { }

  virtual void enterAppend_time_litteral(GrammarParser::Append_time_litteralContext * /*ctx*/) override { }
  virtual void exitAppend_time_litteral(GrammarParser::Append_time_litteralContext * /*ctx*/) override { }

  virtual void enterDate_litteral(GrammarParser::Date_litteralContext * /*ctx*/) override { }
  virtual void exitDate_litteral(GrammarParser::Date_litteralContext * /*ctx*/) override { }

  virtual void enterTime_litteral(GrammarParser::Time_litteralContext * /*ctx*/) override { }
  virtual void exitTime_litteral(GrammarParser::Time_litteralContext * /*ctx*/) override { }

  virtual void enterColor_litteral(GrammarParser::Color_litteralContext * /*ctx*/) override { }
  virtual void exitColor_litteral(GrammarParser::Color_litteralContext * /*ctx*/) override { }

  virtual void enterRgb_litteral(GrammarParser::Rgb_litteralContext * /*ctx*/) override { }
  virtual void exitRgb_litteral(GrammarParser::Rgb_litteralContext * /*ctx*/) override { }

  virtual void enterHex_or_regular_integer(GrammarParser::Hex_or_regular_integerContext * /*ctx*/) override { }
  virtual void exitHex_or_regular_integer(GrammarParser::Hex_or_regular_integerContext * /*ctx*/) override { }

  virtual void enterAny_lex(GrammarParser::Any_lexContext * /*ctx*/) override { }
  virtual void exitAny_lex(GrammarParser::Any_lexContext * /*ctx*/) override { }

  virtual void enterSq_arguments(GrammarParser::Sq_argumentsContext * /*ctx*/) override { }
  virtual void exitSq_arguments(GrammarParser::Sq_argumentsContext * /*ctx*/) override { }

  virtual void enterSq_content(GrammarParser::Sq_contentContext * /*ctx*/) override { }
  virtual void exitSq_content(GrammarParser::Sq_contentContext * /*ctx*/) override { }

  virtual void enterAppend_sq_content(GrammarParser::Append_sq_contentContext * /*ctx*/) override { }
  virtual void exitAppend_sq_content(GrammarParser::Append_sq_contentContext * /*ctx*/) override { }

  virtual void enterSq_brackets_argument(GrammarParser::Sq_brackets_argumentContext * /*ctx*/) override { }
  virtual void exitSq_brackets_argument(GrammarParser::Sq_brackets_argumentContext * /*ctx*/) override { }

  virtual void enterSq_brackets_anyrule(GrammarParser::Sq_brackets_anyruleContext * /*ctx*/) override { }
  virtual void exitSq_brackets_anyrule(GrammarParser::Sq_brackets_anyruleContext * /*ctx*/) override { }

  virtual void enterDirective(GrammarParser::DirectiveContext * /*ctx*/) override { }
  virtual void exitDirective(GrammarParser::DirectiveContext * /*ctx*/) override { }

  virtual void enterProperty(GrammarParser::PropertyContext * /*ctx*/) override { }
  virtual void exitProperty(GrammarParser::PropertyContext * /*ctx*/) override { }

  virtual void enterStr(GrammarParser::StrContext * /*ctx*/) override { }
  virtual void exitStr(GrammarParser::StrContext * /*ctx*/) override { }

  virtual void enterProperty_content(GrammarParser::Property_contentContext * /*ctx*/) override { }
  virtual void exitProperty_content(GrammarParser::Property_contentContext * /*ctx*/) override { }

  virtual void enterProperty_style_definition(GrammarParser::Property_style_definitionContext * /*ctx*/) override { }
  virtual void exitProperty_style_definition(GrammarParser::Property_style_definitionContext * /*ctx*/) override { }

  virtual void enterEnum_extract2header(GrammarParser::Enum_extract2headerContext * /*ctx*/) override { }
  virtual void exitEnum_extract2header(GrammarParser::Enum_extract2headerContext * /*ctx*/) override { }

  virtual void enterEnum_declaration(GrammarParser::Enum_declarationContext * /*ctx*/) override { }
  virtual void exitEnum_declaration(GrammarParser::Enum_declarationContext * /*ctx*/) override { }

  virtual void enterEnum_item_list(GrammarParser::Enum_item_listContext * /*ctx*/) override { }
  virtual void exitEnum_item_list(GrammarParser::Enum_item_listContext * /*ctx*/) override { }

  virtual void enterEnum_item(GrammarParser::Enum_itemContext * /*ctx*/) override { }
  virtual void exitEnum_item(GrammarParser::Enum_itemContext * /*ctx*/) override { }

  virtual void enterVariable_change_value(GrammarParser::Variable_change_valueContext * /*ctx*/) override { }
  virtual void exitVariable_change_value(GrammarParser::Variable_change_valueContext * /*ctx*/) override { }

  virtual void enterVariable_change_value_assignment(GrammarParser::Variable_change_value_assignmentContext * /*ctx*/) override { }
  virtual void exitVariable_change_value_assignment(GrammarParser::Variable_change_value_assignmentContext * /*ctx*/) override { }

  virtual void enterVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext * /*ctx*/) override { }
  virtual void exitVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext * /*ctx*/) override { }

  virtual void enterVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext * /*ctx*/) override { }
  virtual void exitVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext * /*ctx*/) override { }

  virtual void enterSubscript_operator(GrammarParser::Subscript_operatorContext * /*ctx*/) override { }
  virtual void exitSubscript_operator(GrammarParser::Subscript_operatorContext * /*ctx*/) override { }

  virtual void enterMulti_assignment(GrammarParser::Multi_assignmentContext * /*ctx*/) override { }
  virtual void exitMulti_assignment(GrammarParser::Multi_assignmentContext * /*ctx*/) override { }

  virtual void enterLast_multi_assignment_rvalue(GrammarParser::Last_multi_assignment_rvalueContext * /*ctx*/) override { }
  virtual void exitLast_multi_assignment_rvalue(GrammarParser::Last_multi_assignment_rvalueContext * /*ctx*/) override { }

  virtual void enterExpression(GrammarParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(GrammarParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterOp_expr(GrammarParser::Op_exprContext * /*ctx*/) override { }
  virtual void exitOp_expr(GrammarParser::Op_exprContext * /*ctx*/) override { }

  virtual void enterBinary_operator(GrammarParser::Binary_operatorContext * /*ctx*/) override { }
  virtual void exitBinary_operator(GrammarParser::Binary_operatorContext * /*ctx*/) override { }

  virtual void enterUnary_operator(GrammarParser::Unary_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_operator(GrammarParser::Unary_operatorContext * /*ctx*/) override { }

  virtual void enterSingle_expr_space(GrammarParser::Single_expr_spaceContext * /*ctx*/) override { }
  virtual void exitSingle_expr_space(GrammarParser::Single_expr_spaceContext * /*ctx*/) override { }

  virtual void enterSingle_expr(GrammarParser::Single_exprContext * /*ctx*/) override { }
  virtual void exitSingle_expr(GrammarParser::Single_exprContext * /*ctx*/) override { }

  virtual void enterAsssignment_operator(GrammarParser::Asssignment_operatorContext * /*ctx*/) override { }
  virtual void exitAsssignment_operator(GrammarParser::Asssignment_operatorContext * /*ctx*/) override { }

  virtual void enterAdd_brackets(GrammarParser::Add_bracketsContext * /*ctx*/) override { }
  virtual void exitAdd_brackets(GrammarParser::Add_bracketsContext * /*ctx*/) override { }

  virtual void enterChange_brackets(GrammarParser::Change_bracketsContext * /*ctx*/) override { }
  virtual void exitChange_brackets(GrammarParser::Change_bracketsContext * /*ctx*/) override { }

  virtual void enterUnsupported_object_types(GrammarParser::Unsupported_object_typesContext * /*ctx*/) override { }
  virtual void exitUnsupported_object_types(GrammarParser::Unsupported_object_typesContext * /*ctx*/) override { }

  virtual void enterUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext * /*ctx*/) override { }
  virtual void exitUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext * /*ctx*/) override { }

  virtual void enterReturn_datetime(GrammarParser::Return_datetimeContext * /*ctx*/) override { }
  virtual void exitReturn_datetime(GrammarParser::Return_datetimeContext * /*ctx*/) override { }

  virtual void enterIndicator_buffers_func(GrammarParser::Indicator_buffers_funcContext * /*ctx*/) override { }
  virtual void exitIndicator_buffers_func(GrammarParser::Indicator_buffers_funcContext * /*ctx*/) override { }

  virtual void enterArg_comma(GrammarParser::Arg_commaContext * /*ctx*/) override { }
  virtual void exitArg_comma(GrammarParser::Arg_commaContext * /*ctx*/) override { }

  virtual void enterModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext * /*ctx*/) override { }
  virtual void exitModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext * /*ctx*/) override { }

  virtual void enterVariable_declaration(GrammarParser::Variable_declarationContext * /*ctx*/) override { }
  virtual void exitVariable_declaration(GrammarParser::Variable_declarationContext * /*ctx*/) override { }

  virtual void enterAppend_variable_declaration(GrammarParser::Append_variable_declarationContext * /*ctx*/) override { }
  virtual void exitAppend_variable_declaration(GrammarParser::Append_variable_declarationContext * /*ctx*/) override { }

  virtual void enterInitialization_value(GrammarParser::Initialization_valueContext * /*ctx*/) override { }
  virtual void exitInitialization_value(GrammarParser::Initialization_valueContext * /*ctx*/) override { }

  virtual void enterArray_initialization_list(GrammarParser::Array_initialization_listContext * /*ctx*/) override { }
  virtual void exitArray_initialization_list(GrammarParser::Array_initialization_listContext * /*ctx*/) override { }

  virtual void enterInitialization_list_append_items(GrammarParser::Initialization_list_append_itemsContext * /*ctx*/) override { }
  virtual void exitInitialization_list_append_items(GrammarParser::Initialization_list_append_itemsContext * /*ctx*/) override { }

  virtual void enterInitialization_list_items(GrammarParser::Initialization_list_itemsContext * /*ctx*/) override { }
  virtual void exitInitialization_list_items(GrammarParser::Initialization_list_itemsContext * /*ctx*/) override { }

  virtual void enterInitialization_list_item(GrammarParser::Initialization_list_itemContext * /*ctx*/) override { }
  virtual void exitInitialization_list_item(GrammarParser::Initialization_list_itemContext * /*ctx*/) override { }

  virtual void enterConst_name(GrammarParser::Const_nameContext * /*ctx*/) override { }
  virtual void exitConst_name(GrammarParser::Const_nameContext * /*ctx*/) override { }

  virtual void enterDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext * /*ctx*/) override { }
  virtual void exitDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext * /*ctx*/) override { }

  virtual void enterDynamic_array_brackets_parameter(GrammarParser::Dynamic_array_brackets_parameterContext * /*ctx*/) override { }
  virtual void exitDynamic_array_brackets_parameter(GrammarParser::Dynamic_array_brackets_parameterContext * /*ctx*/) override { }

  virtual void enterDynamic_array_append_parameter(GrammarParser::Dynamic_array_append_parameterContext * /*ctx*/) override { }
  virtual void exitDynamic_array_append_parameter(GrammarParser::Dynamic_array_append_parameterContext * /*ctx*/) override { }

  virtual void enterDynamic_array_parameter(GrammarParser::Dynamic_array_parameterContext * /*ctx*/) override { }
  virtual void exitDynamic_array_parameter(GrammarParser::Dynamic_array_parameterContext * /*ctx*/) override { }

  virtual void enterSet_index_buffer(GrammarParser::Set_index_bufferContext * /*ctx*/) override { }
  virtual void exitSet_index_buffer(GrammarParser::Set_index_bufferContext * /*ctx*/) override { }

  virtual void enterSet_level_style(GrammarParser::Set_level_styleContext * /*ctx*/) override { }
  virtual void exitSet_level_style(GrammarParser::Set_level_styleContext * /*ctx*/) override { }

  virtual void enterAlert(GrammarParser::AlertContext * /*ctx*/) override { }
  virtual void exitAlert(GrammarParser::AlertContext * /*ctx*/) override { }

  virtual void enterFunction_definition(GrammarParser::Function_definitionContext * /*ctx*/) override { }
  virtual void exitFunction_definition(GrammarParser::Function_definitionContext * /*ctx*/) override { }

  virtual void enterType(GrammarParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(GrammarParser::TypeContext * /*ctx*/) override { }

  virtual void enterType_name(GrammarParser::Type_nameContext * /*ctx*/) override { }
  virtual void exitType_name(GrammarParser::Type_nameContext * /*ctx*/) override { }

  virtual void enterParams_list(GrammarParser::Params_listContext * /*ctx*/) override { }
  virtual void exitParams_list(GrammarParser::Params_listContext * /*ctx*/) override { }

  virtual void enterAppend_argument(GrammarParser::Append_argumentContext * /*ctx*/) override { }
  virtual void exitAppend_argument(GrammarParser::Append_argumentContext * /*ctx*/) override { }

  virtual void enterArgument(GrammarParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(GrammarParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterFcall_argument(GrammarParser::Fcall_argumentContext * /*ctx*/) override { }
  virtual void exitFcall_argument(GrammarParser::Fcall_argumentContext * /*ctx*/) override { }

  virtual void enterFcall_anyrule(GrammarParser::Fcall_anyruleContext * /*ctx*/) override { }
  virtual void exitFcall_anyrule(GrammarParser::Fcall_anyruleContext * /*ctx*/) override { }

  virtual void enterFcall_params(GrammarParser::Fcall_paramsContext * /*ctx*/) override { }
  virtual void exitFcall_params(GrammarParser::Fcall_paramsContext * /*ctx*/) override { }

  virtual void enterFcall_params_list(GrammarParser::Fcall_params_listContext * /*ctx*/) override { }
  virtual void exitFcall_params_list(GrammarParser::Fcall_params_listContext * /*ctx*/) override { }

  virtual void enterAppend_fcall_argument(GrammarParser::Append_fcall_argumentContext * /*ctx*/) override { }
  virtual void exitAppend_fcall_argument(GrammarParser::Append_fcall_argumentContext * /*ctx*/) override { }

  virtual void enterDeinit_function_call(GrammarParser::Deinit_function_callContext * /*ctx*/) override { }
  virtual void exitDeinit_function_call(GrammarParser::Deinit_function_callContext * /*ctx*/) override { }

  virtual void enterInit_function_call(GrammarParser::Init_function_callContext * /*ctx*/) override { }
  virtual void exitInit_function_call(GrammarParser::Init_function_callContext * /*ctx*/) override { }

  virtual void enterStart_function_call(GrammarParser::Start_function_callContext * /*ctx*/) override { }
  virtual void exitStart_function_call(GrammarParser::Start_function_callContext * /*ctx*/) override { }

  virtual void enterOn_calculate_handler(GrammarParser::On_calculate_handlerContext * /*ctx*/) override { }
  virtual void exitOn_calculate_handler(GrammarParser::On_calculate_handlerContext * /*ctx*/) override { }

  virtual void enterOn_tick_handler(GrammarParser::On_tick_handlerContext * /*ctx*/) override { }
  virtual void exitOn_tick_handler(GrammarParser::On_tick_handlerContext * /*ctx*/) override { }

  virtual void enterOn_init_handler(GrammarParser::On_init_handlerContext * /*ctx*/) override { }
  virtual void exitOn_init_handler(GrammarParser::On_init_handlerContext * /*ctx*/) override { }

  virtual void enterOn_deinit_handler(GrammarParser::On_deinit_handlerContext * /*ctx*/) override { }
  virtual void exitOn_deinit_handler(GrammarParser::On_deinit_handlerContext * /*ctx*/) override { }

  virtual void enterOn_timer_handler(GrammarParser::On_timer_handlerContext * /*ctx*/) override { }
  virtual void exitOn_timer_handler(GrammarParser::On_timer_handlerContext * /*ctx*/) override { }

  virtual void enterOn_chart_event_handler(GrammarParser::On_chart_event_handlerContext * /*ctx*/) override { }
  virtual void exitOn_chart_event_handler(GrammarParser::On_chart_event_handlerContext * /*ctx*/) override { }

  virtual void enterName(GrammarParser::NameContext * /*ctx*/) override { }
  virtual void exitName(GrammarParser::NameContext * /*ctx*/) override { }

  virtual void enterSpace(GrammarParser::SpaceContext * /*ctx*/) override { }
  virtual void exitSpace(GrammarParser::SpaceContext * /*ctx*/) override { }

  virtual void enterInteger(GrammarParser::IntegerContext * /*ctx*/) override { }
  virtual void exitInteger(GrammarParser::IntegerContext * /*ctx*/) override { }

  virtual void enterFloat_value(GrammarParser::Float_valueContext * /*ctx*/) override { }
  virtual void exitFloat_value(GrammarParser::Float_valueContext * /*ctx*/) override { }

  virtual void enterTryblock_replacement_start(GrammarParser::Tryblock_replacement_startContext * /*ctx*/) override { }
  virtual void exitTryblock_replacement_start(GrammarParser::Tryblock_replacement_startContext * /*ctx*/) override { }

  virtual void enterTryblock_replacement_end(GrammarParser::Tryblock_replacement_endContext * /*ctx*/) override { }
  virtual void exitTryblock_replacement_end(GrammarParser::Tryblock_replacement_endContext * /*ctx*/) override { }

  virtual void enterParantheses_expression(GrammarParser::Parantheses_expressionContext * /*ctx*/) override { }
  virtual void exitParantheses_expression(GrammarParser::Parantheses_expressionContext * /*ctx*/) override { }

  virtual void enterMl_content(GrammarParser::Ml_contentContext * /*ctx*/) override { }
  virtual void exitMl_content(GrammarParser::Ml_contentContext * /*ctx*/) override { }

  virtual void enterOl_content(GrammarParser::Ol_contentContext * /*ctx*/) override { }
  virtual void exitOl_content(GrammarParser::Ol_contentContext * /*ctx*/) override { }

  virtual void enterNo_cl_parentheses(GrammarParser::No_cl_parenthesesContext * /*ctx*/) override { }
  virtual void exitNo_cl_parentheses(GrammarParser::No_cl_parenthesesContext * /*ctx*/) override { }

  virtual void enterNo_semicolon(GrammarParser::No_semicolonContext * /*ctx*/) override { }
  virtual void exitNo_semicolon(GrammarParser::No_semicolonContext * /*ctx*/) override { }

  virtual void enterNo_comma(GrammarParser::No_commaContext * /*ctx*/) override { }
  virtual void exitNo_comma(GrammarParser::No_commaContext * /*ctx*/) override { }

  virtual void enterNo_comma_sq_br(GrammarParser::No_comma_sq_brContext * /*ctx*/) override { }
  virtual void exitNo_comma_sq_br(GrammarParser::No_comma_sq_brContext * /*ctx*/) override { }

  virtual void enterNo_comma_semicolon(GrammarParser::No_comma_semicolonContext * /*ctx*/) override { }
  virtual void exitNo_comma_semicolon(GrammarParser::No_comma_semicolonContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

