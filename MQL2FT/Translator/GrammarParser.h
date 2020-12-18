
// Generated from c:\Projects\ForexTester\MQL2FT_REPO\MQL2FT\MQL2FT\Translator\Grammar.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  GrammarParser : public antlr4::Parser {
public:
  enum {
    HASH = 1, COMMA = 2, DOT = 3, OP_BR = 4, CL_BR = 5, OP_PARETHESES = 6, 
    CL_PARETHESES = 7, OP_CRL_BR = 8, CL_CRL_BR = 9, COLON = 10, SC = 11, 
    D_QUOTE = 12, S_QUOTE = 13, EQ = 14, COMPARISSON = 15, COMPARISSON_NOT = 16, 
    MORE_OR_EQUAL = 17, LESS_OR_EQUAL = 18, INCREMENT = 19, DECREMENT = 20, 
    PLUS = 21, MINUS = 22, ASTRISK = 23, SLASH = 24, AMPERSAND = 25, NEWLINE = 26, 
    BD_SLASH = 27, OP_COMMENT = 28, CL_COMMENT = 29, MULTILINE_COMMENT = 30, 
    ONELINE_COMMENT = 31, WS = 32, DEINIT = 33, INIT = 34, START = 35, ON_CALCULATE = 36, 
    ON_TICK = 37, ON_INIT = 38, ON_DEINIT = 39, ON_TIMER = 40, ON_CHART_EVENT = 41, 
    TRY_BLOCK_DASH = 42, TRY_BLOCK_START = 43, TRY_BLOCK_END = 44, INDEX_BUFFER_TYPE = 45, 
    EXTERN = 46, INPUT = 47, SINPUT = 48, K_STATIC = 49, K_STRICT = 50, 
    K_NULL = 51, K_CONST = 52, K_UNSIGNED = 53, K_ENUM = 54, K_ELSE = 55, 
    K_SWITCH = 56, K_CASE = 57, K_RETURN = 58, K_FOR = 59, K_IF = 60, T_DOUBLE = 61, 
    T_FLOAT = 62, T_VOID = 63, T_INT = 64, T_BOOL = 65, T_LONG = 66, T_SHORT = 67, 
    T_CHAR = 68, T_STRING = 69, T_COLOR = 70, T_ULONG = 71, T_DATETIME = 72, 
    PROPERTY = 73, INDICATOR_SEPARATE_WINDOW = 74, INDICATOR_CHART_WINDOW = 75, 
    ALERT = 76, GET_LAST_ERROR = 77, PLAY_SOUND = 78, ADD_BRACKETS_FUNCTIONS = 79, 
    CHANGE_BRACKETS_FUNCTIONS = 80, SET_INDEX_BUFFER = 81, SET_LEVEL_STYLE = 82, 
    INDICATOR_BUFFERS = 83, INDICATOR_BUFFERS_FUNC = 84, INDICATORS_ONLY = 85, 
    STRATEGY_ONLY = 86, HOOKING_FUNCS = 87, TIME_CURRENT = 88, ORDER_OPEN_TIME = 89, 
    ORDER_CLOSE_TIME = 90, UNSUPPORTED_OBJECTS = 91, UNSUPPORTED_PROPERTIES = 92, 
    INDICATOR_LINE_IDENTIFIER_MODE = 93, IMA_MODE = 94, PRICE_TYPE = 95, 
    TIMEFRAME = 96, DT_LITTERAL_ST = 97, CLR_LITTERAL = 98, REGULAR_STRING = 99, 
    CHAR_LITTERAL = 100, NAME = 101, INTEGER = 102, HEX_INTEGER = 103, DATE_LITERAL = 104, 
    FLOATING_LITERAL = 105, LETTER = 106, DIGIT = 107, ANY = 108, MANY = 109
  };

  enum {
    RuleCompileUnit = 0, RuleUnit = 1, RuleAny_function_definition = 2, 
    RuleAppend_scope = 3, RuleFunction_scope = 4, RuleScope_content = 5, 
    RuleReturn_statement = 6, RuleVoid_return = 7, RuleStandart_return = 8, 
    RuleFor_loop = 9, RuleFor_loop_declaration = 10, RuleFor_loop_variable_decl = 11, 
    RuleFor_loop_condition = 12, RuleFor_loop_increment = 13, RuleFor_loop_append_increment = 14, 
    RuleRvalue = 15, RuleParantheses_any_expression = 16, RuleParantheses_content = 17, 
    RuleParantheses_content_expression = 18, RuleNo_parant_comma_sc = 19, 
    RuleNo_parant_sc = 20, RuleArgument_content = 21, RuleCommented_block = 22, 
    RuleFunction_call = 23, RuleAny_function_call = 24, RuleAny_fcall_parantheses_expr = 25, 
    RuleAny_fcall_parantheses_content = 26, RuleAny_fcall_append_argument = 27, 
    RuleEntry_point = 28, RuleSingle_name = 29, RuleDatetime_litteral = 30, 
    RuleAppend_time_litteral = 31, RuleDate_litteral = 32, RuleTime_litteral = 33, 
    RuleColor_litteral = 34, RuleRgb_litteral = 35, RuleHex_or_regular_integer = 36, 
    RuleAny_lex = 37, RuleSq_arguments = 38, RuleSq_content = 39, RuleAppend_sq_content = 40, 
    RuleSq_brackets_argument = 41, RuleSq_brackets_anyrule = 42, RuleDirective = 43, 
    RuleProperty = 44, RuleStr = 45, RuleProperty_content = 46, RuleProperty_style_definition = 47, 
    RuleEnum_extract2header = 48, RuleEnum_declaration = 49, RuleEnum_item_list = 50, 
    RuleEnum_item = 51, RuleVariable_change_value = 52, RuleVariable_modify_rules = 53, 
    RuleSubscript_operator = 54, RuleMulti_assignment = 55, RuleLast_multi_assignment_rvalue = 56, 
    RuleExpression = 57, RuleOp_expr = 58, RuleBinary_operator = 59, RuleUnary_operator = 60, 
    RuleSingle_expr_space = 61, RuleSingle_expr = 62, RuleAsssignment_operator = 63, 
    RuleAdd_brackets = 64, RuleChange_brackets = 65, RuleUnsupported_object_types = 66, 
    RuleUnsupported_object_properties = 67, RuleReturn_datetime = 68, RuleIndicator_buffers_func = 69, 
    RuleArg_comma = 70, RuleModifier_variable_declaration = 71, RuleVariable_declaration = 72, 
    RuleAppend_variable_declaration = 73, RuleInitialization_value = 74, 
    RuleArray_initialization_list = 75, RuleInitialization_list_append_items = 76, 
    RuleInitialization_list_items = 77, RuleInitialization_list_item = 78, 
    RuleConst_name = 79, RuleDynamic_array_brackets_params = 80, RuleDynamic_array_brackets_parameter = 81, 
    RuleDynamic_array_append_parameter = 82, RuleDynamic_array_parameter = 83, 
    RuleSet_index_buffer = 84, RuleSet_level_style = 85, RuleAlert = 86, 
    RuleFunction_definition = 87, RuleType = 88, RuleType_name = 89, RuleParams_list = 90, 
    RuleAppend_argument = 91, RuleArgument = 92, RuleFcall_argument = 93, 
    RuleFcall_anyrule = 94, RuleFcall_params = 95, RuleFcall_params_list = 96, 
    RuleAppend_fcall_argument = 97, RuleDeinit_function_call = 98, RuleInit_function_call = 99, 
    RuleStart_function_call = 100, RuleOn_calculate_handler = 101, RuleOn_tick_handler = 102, 
    RuleOn_init_handler = 103, RuleOn_deinit_handler = 104, RuleOn_timer_handler = 105, 
    RuleOn_chart_event_handler = 106, RuleName = 107, RuleSpace = 108, RuleInteger = 109, 
    RuleFloat_value = 110, RuleTryblock_replacement_start = 111, RuleTryblock_replacement_end = 112, 
    RuleParantheses_expression = 113, RuleMl_content = 114, RuleOl_content = 115, 
    RuleNo_cl_parentheses = 116, RuleNo_semicolon = 117, RuleNo_comma = 118, 
    RuleNo_comma_sq_br = 119, RuleNo_comma_semicolon = 120
  };

  GrammarParser(antlr4::TokenStream *input);
  ~GrammarParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompileUnitContext;
  class UnitContext;
  class Any_function_definitionContext;
  class Append_scopeContext;
  class Function_scopeContext;
  class Scope_contentContext;
  class Return_statementContext;
  class Void_returnContext;
  class Standart_returnContext;
  class For_loopContext;
  class For_loop_declarationContext;
  class For_loop_variable_declContext;
  class For_loop_conditionContext;
  class For_loop_incrementContext;
  class For_loop_append_incrementContext;
  class RvalueContext;
  class Parantheses_any_expressionContext;
  class Parantheses_contentContext;
  class Parantheses_content_expressionContext;
  class No_parant_comma_scContext;
  class No_parant_scContext;
  class Argument_contentContext;
  class Commented_blockContext;
  class Function_callContext;
  class Any_function_callContext;
  class Any_fcall_parantheses_exprContext;
  class Any_fcall_parantheses_contentContext;
  class Any_fcall_append_argumentContext;
  class Entry_pointContext;
  class Single_nameContext;
  class Datetime_litteralContext;
  class Append_time_litteralContext;
  class Date_litteralContext;
  class Time_litteralContext;
  class Color_litteralContext;
  class Rgb_litteralContext;
  class Hex_or_regular_integerContext;
  class Any_lexContext;
  class Sq_argumentsContext;
  class Sq_contentContext;
  class Append_sq_contentContext;
  class Sq_brackets_argumentContext;
  class Sq_brackets_anyruleContext;
  class DirectiveContext;
  class PropertyContext;
  class StrContext;
  class Property_contentContext;
  class Property_style_definitionContext;
  class Enum_extract2headerContext;
  class Enum_declarationContext;
  class Enum_item_listContext;
  class Enum_itemContext;
  class Variable_change_valueContext;
  class Variable_modify_rulesContext;
  class Subscript_operatorContext;
  class Multi_assignmentContext;
  class Last_multi_assignment_rvalueContext;
  class ExpressionContext;
  class Op_exprContext;
  class Binary_operatorContext;
  class Unary_operatorContext;
  class Single_expr_spaceContext;
  class Single_exprContext;
  class Asssignment_operatorContext;
  class Add_bracketsContext;
  class Change_bracketsContext;
  class Unsupported_object_typesContext;
  class Unsupported_object_propertiesContext;
  class Return_datetimeContext;
  class Indicator_buffers_funcContext;
  class Arg_commaContext;
  class Modifier_variable_declarationContext;
  class Variable_declarationContext;
  class Append_variable_declarationContext;
  class Initialization_valueContext;
  class Array_initialization_listContext;
  class Initialization_list_append_itemsContext;
  class Initialization_list_itemsContext;
  class Initialization_list_itemContext;
  class Const_nameContext;
  class Dynamic_array_brackets_paramsContext;
  class Dynamic_array_brackets_parameterContext;
  class Dynamic_array_append_parameterContext;
  class Dynamic_array_parameterContext;
  class Set_index_bufferContext;
  class Set_level_styleContext;
  class AlertContext;
  class Function_definitionContext;
  class TypeContext;
  class Type_nameContext;
  class Params_listContext;
  class Append_argumentContext;
  class ArgumentContext;
  class Fcall_argumentContext;
  class Fcall_anyruleContext;
  class Fcall_paramsContext;
  class Fcall_params_listContext;
  class Append_fcall_argumentContext;
  class Deinit_function_callContext;
  class Init_function_callContext;
  class Start_function_callContext;
  class On_calculate_handlerContext;
  class On_tick_handlerContext;
  class On_init_handlerContext;
  class On_deinit_handlerContext;
  class On_timer_handlerContext;
  class On_chart_event_handlerContext;
  class NameContext;
  class SpaceContext;
  class IntegerContext;
  class Float_valueContext;
  class Tryblock_replacement_startContext;
  class Tryblock_replacement_endContext;
  class Parantheses_expressionContext;
  class Ml_contentContext;
  class Ol_contentContext;
  class No_cl_parenthesesContext;
  class No_semicolonContext;
  class No_commaContext;
  class No_comma_sq_brContext;
  class No_comma_semicolonContext; 

  class  CompileUnitContext : public antlr4::ParserRuleContext {
  public:
    CompileUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<UnitContext *> unit();
    UnitContext* unit(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CompileUnitContext* compileUnit();

  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropertyContext *property();
    DirectiveContext *directive();
    Enum_extract2headerContext *enum_extract2header();
    Any_function_definitionContext *any_function_definition();
    Scope_contentContext *scope_content();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  Any_function_definitionContext : public antlr4::ParserRuleContext {
  public:
    Any_function_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_definitionContext *function_definition();
    Append_scopeContext *append_scope();
    antlr4::tree::TerminalNode *SC();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Entry_pointContext *entry_point();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Any_function_definitionContext* any_function_definition();

  class  Append_scopeContext : public antlr4::ParserRuleContext {
  public:
    Append_scopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_scopeContext *function_scope();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Append_scopeContext* append_scope();

  class  Function_scopeContext : public antlr4::ParserRuleContext {
  public:
    Function_scopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_CRL_BR();
    antlr4::tree::TerminalNode *CL_CRL_BR();
    std::vector<Scope_contentContext *> scope_content();
    Scope_contentContext* scope_content(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_scopeContext* function_scope();

  class  Scope_contentContext : public antlr4::ParserRuleContext {
  public:
    Scope_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Return_statementContext *return_statement();
    Function_scopeContext *function_scope();
    Commented_blockContext *commented_block();
    Modifier_variable_declarationContext *modifier_variable_declaration();
    For_loopContext *for_loop();
    Function_callContext *function_call();
    Variable_change_valueContext *variable_change_value();
    Subscript_operatorContext *subscript_operator();
    Sq_argumentsContext *sq_arguments();
    Single_nameContext *single_name();
    DirectiveContext *directive();
    Datetime_litteralContext *datetime_litteral();
    Color_litteralContext *color_litteral();
    SpaceContext *space();
    PropertyContext *property();
    Any_lexContext *any_lex();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Scope_contentContext* scope_content();

  class  Return_statementContext : public antlr4::ParserRuleContext {
  public:
    Return_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Void_returnContext *void_return();
    Standart_returnContext *standart_return();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Return_statementContext* return_statement();

  class  Void_returnContext : public antlr4::ParserRuleContext {
  public:
    Void_returnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_RETURN();
    antlr4::tree::TerminalNode *SC();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Void_returnContext* void_return();

  class  Standart_returnContext : public antlr4::ParserRuleContext {
  public:
    Standart_returnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_RETURN();
    Parantheses_any_expressionContext *parantheses_any_expression();
    antlr4::tree::TerminalNode *SC();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Standart_returnContext* standart_return();

  class  For_loopContext : public antlr4::ParserRuleContext {
  public:
    For_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_FOR();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    For_loop_declarationContext *for_loop_declaration();
    For_loop_conditionContext *for_loop_condition();
    For_loop_incrementContext *for_loop_increment();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_loopContext* for_loop();

  class  For_loop_declarationContext : public antlr4::ParserRuleContext {
  public:
    For_loop_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    For_loop_variable_declContext *for_loop_variable_decl();
    Variable_change_valueContext *variable_change_value();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_loop_declarationContext* for_loop_declaration();

  class  For_loop_variable_declContext : public antlr4::ParserRuleContext {
  public:
    For_loop_variable_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SC();
    Variable_declarationContext *variable_declaration();
    std::vector<Append_variable_declarationContext *> append_variable_declaration();
    Append_variable_declarationContext* append_variable_declaration(size_t i);
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_loop_variable_declContext* for_loop_variable_decl();

  class  For_loop_conditionContext : public antlr4::ParserRuleContext {
  public:
    For_loop_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SC();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_loop_conditionContext* for_loop_condition();

  class  For_loop_incrementContext : public antlr4::ParserRuleContext {
  public:
    For_loop_incrementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Variable_modify_rulesContext *variable_modify_rules();
    std::vector<For_loop_append_incrementContext *> for_loop_append_increment();
    For_loop_append_incrementContext* for_loop_append_increment(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_loop_incrementContext* for_loop_increment();

  class  For_loop_append_incrementContext : public antlr4::ParserRuleContext {
  public:
    For_loop_append_incrementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    Variable_modify_rulesContext *variable_modify_rules();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  For_loop_append_incrementContext* for_loop_append_increment();

  class  RvalueContext : public antlr4::ParserRuleContext {
  public:
    RvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_callContext *function_call();
    Subscript_operatorContext *subscript_operator();
    Sq_argumentsContext *sq_arguments();
    Datetime_litteralContext *datetime_litteral();
    Variable_change_valueContext *variable_change_value();
    Color_litteralContext *color_litteral();
    Parantheses_any_expressionContext *parantheses_any_expression();
    NameContext *name();
    Single_nameContext *single_name();
    No_parant_comma_scContext *no_parant_comma_sc();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RvalueContext* rvalue();

  class  Parantheses_any_expressionContext : public antlr4::ParserRuleContext {
  public:
    Parantheses_any_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    Parantheses_contentContext *parantheses_content();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parantheses_any_expressionContext* parantheses_any_expression();

  class  Parantheses_contentContext : public antlr4::ParserRuleContext {
  public:
    Parantheses_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Parantheses_content_expressionContext *> parantheses_content_expression();
    Parantheses_content_expressionContext* parantheses_content_expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parantheses_contentContext* parantheses_content();

  class  Parantheses_content_expressionContext : public antlr4::ParserRuleContext {
  public:
    Parantheses_content_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RvalueContext *rvalue();
    No_parant_scContext *no_parant_sc();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parantheses_content_expressionContext* parantheses_content_expression();

  class  No_parant_comma_scContext : public antlr4::ParserRuleContext {
  public:
    No_parant_comma_scContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *SC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  No_parant_comma_scContext* no_parant_comma_sc();

  class  No_parant_scContext : public antlr4::ParserRuleContext {
  public:
    No_parant_scContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    antlr4::tree::TerminalNode *SC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  No_parant_scContext* no_parant_sc();

  class  Argument_contentContext : public antlr4::ParserRuleContext {
  public:
    Argument_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Commented_blockContext *commented_block();
    Function_callContext *function_call();
    Subscript_operatorContext *subscript_operator();
    Sq_argumentsContext *sq_arguments();
    Single_nameContext *single_name();
    NameContext *name();
    Variable_change_valueContext *variable_change_value();
    SpaceContext *space();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_contentContext* argument_content();

  class  Commented_blockContext : public antlr4::ParserRuleContext {
  public:
    Commented_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Tryblock_replacement_startContext *tryblock_replacement_start();
    Tryblock_replacement_endContext *tryblock_replacement_end();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Commented_blockContext* commented_block();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AlertContext *alert();
    Add_bracketsContext *add_brackets();
    Change_bracketsContext *change_brackets();
    Return_datetimeContext *return_datetime();
    Indicator_buffers_funcContext *indicator_buffers_func();
    Set_index_bufferContext *set_index_buffer();
    Set_level_styleContext *set_level_style();
    Any_function_callContext *any_function_call();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_callContext* function_call();

  class  Any_function_callContext : public antlr4::ParserRuleContext {
  public:
    Any_function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    Any_fcall_parantheses_exprContext *any_fcall_parantheses_expr();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Any_function_callContext* any_function_call();

  class  Any_fcall_parantheses_exprContext : public antlr4::ParserRuleContext {
  public:
    Any_fcall_parantheses_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    Any_fcall_parantheses_contentContext *any_fcall_parantheses_content();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Any_fcall_parantheses_exprContext* any_fcall_parantheses_expr();

  class  Any_fcall_parantheses_contentContext : public antlr4::ParserRuleContext {
  public:
    Any_fcall_parantheses_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RvalueContext *rvalue();
    std::vector<Any_fcall_append_argumentContext *> any_fcall_append_argument();
    Any_fcall_append_argumentContext* any_fcall_append_argument(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Any_fcall_parantheses_contentContext* any_fcall_parantheses_content();

  class  Any_fcall_append_argumentContext : public antlr4::ParserRuleContext {
  public:
    Any_fcall_append_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    RvalueContext *rvalue();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Any_fcall_append_argumentContext* any_fcall_append_argument();

  class  Entry_pointContext : public antlr4::ParserRuleContext {
  public:
    Entry_pointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Deinit_function_callContext *deinit_function_call();
    Init_function_callContext *init_function_call();
    Start_function_callContext *start_function_call();
    On_calculate_handlerContext *on_calculate_handler();
    On_tick_handlerContext *on_tick_handler();
    On_init_handlerContext *on_init_handler();
    On_deinit_handlerContext *on_deinit_handler();
    On_timer_handlerContext *on_timer_handler();
    On_chart_event_handlerContext *on_chart_event_handler();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_pointContext* entry_point();

  class  Single_nameContext : public antlr4::ParserRuleContext {
  public:
    Single_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INDICATORS_ONLY();
    antlr4::tree::TerminalNode *STRATEGY_ONLY();
    antlr4::tree::TerminalNode *HOOKING_FUNCS();
    antlr4::tree::TerminalNode *ON_TIMER();
    Unsupported_object_typesContext *unsupported_object_types();
    Unsupported_object_propertiesContext *unsupported_object_properties();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Single_nameContext* single_name();

  class  Datetime_litteralContext : public antlr4::ParserRuleContext {
  public:
    Datetime_litteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DT_LITTERAL_ST();
    antlr4::tree::TerminalNode *S_QUOTE();
    Time_litteralContext *time_litteral();
    Date_litteralContext *date_litteral();
    Append_time_litteralContext *append_time_litteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Datetime_litteralContext* datetime_litteral();

  class  Append_time_litteralContext : public antlr4::ParserRuleContext {
  public:
    Append_time_litteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Time_litteralContext *time_litteral();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Append_time_litteralContext* append_time_litteral();

  class  Date_litteralContext : public antlr4::ParserRuleContext {
  public:
    Date_litteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATE_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Date_litteralContext* date_litteral();

  class  Time_litteralContext : public antlr4::ParserRuleContext {
  public:
    Time_litteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Time_litteralContext* time_litteral();

  class  Color_litteralContext : public antlr4::ParserRuleContext {
  public:
    Color_litteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLR_LITTERAL();
    Rgb_litteralContext *rgb_litteral();
    antlr4::tree::TerminalNode *S_QUOTE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Color_litteralContext* color_litteral();

  class  Rgb_litteralContext : public antlr4::ParserRuleContext {
  public:
    Rgb_litteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Hex_or_regular_integerContext *> hex_or_regular_integer();
    Hex_or_regular_integerContext* hex_or_regular_integer(size_t i);
    std::vector<Arg_commaContext *> arg_comma();
    Arg_commaContext* arg_comma(size_t i);
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rgb_litteralContext* rgb_litteral();

  class  Hex_or_regular_integerContext : public antlr4::ParserRuleContext {
  public:
    Hex_or_regular_integerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *HEX_INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Hex_or_regular_integerContext* hex_or_regular_integer();

  class  Any_lexContext : public antlr4::ParserRuleContext {
  public:
    Any_lexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MANY();
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *SC();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *HASH();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *INCREMENT();
    antlr4::tree::TerminalNode *DECREMENT();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *ASTRISK();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    antlr4::tree::TerminalNode *COMPARISSON();
    antlr4::tree::TerminalNode *COMPARISSON_NOT();
    antlr4::tree::TerminalNode *MORE_OR_EQUAL();
    antlr4::tree::TerminalNode *LESS_OR_EQUAL();
    antlr4::tree::TerminalNode *CHAR_LITTERAL();
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *SINPUT();
    antlr4::tree::TerminalNode *EXTERN();
    antlr4::tree::TerminalNode *K_STATIC();
    antlr4::tree::TerminalNode *K_STRICT();
    antlr4::tree::TerminalNode *K_CONST();
    antlr4::tree::TerminalNode *K_NULL();
    antlr4::tree::TerminalNode *K_UNSIGNED();
    antlr4::tree::TerminalNode *K_ENUM();
    antlr4::tree::TerminalNode *K_ELSE();
    antlr4::tree::TerminalNode *K_RETURN();
    antlr4::tree::TerminalNode *K_SWITCH();
    antlr4::tree::TerminalNode *K_CASE();
    antlr4::tree::TerminalNode *K_IF();
    antlr4::tree::TerminalNode *K_FOR();
    antlr4::tree::TerminalNode *T_VOID();
    antlr4::tree::TerminalNode *T_BOOL();
    antlr4::tree::TerminalNode *T_LONG();
    antlr4::tree::TerminalNode *T_DATETIME();
    antlr4::tree::TerminalNode *T_DOUBLE();
    antlr4::tree::TerminalNode *T_CHAR();
    antlr4::tree::TerminalNode *T_STRING();
    antlr4::tree::TerminalNode *T_INT();
    antlr4::tree::TerminalNode *T_COLOR();
    antlr4::tree::TerminalNode *T_ULONG();
    antlr4::tree::TerminalNode *DT_LITTERAL_ST();
    antlr4::tree::TerminalNode *CLR_LITTERAL();
    antlr4::tree::TerminalNode *DATE_LITERAL();
    antlr4::tree::TerminalNode *S_QUOTE();
    Hex_or_regular_integerContext *hex_or_regular_integer();
    Float_valueContext *float_value();
    antlr4::tree::TerminalNode *INDICATOR_LINE_IDENTIFIER_MODE();
    antlr4::tree::TerminalNode *TIMEFRAME();
    antlr4::tree::TerminalNode *IMA_MODE();
    antlr4::tree::TerminalNode *PRICE_TYPE();
    NameContext *name();
    StrContext *str();
    antlr4::tree::TerminalNode *PROPERTY();
    antlr4::tree::TerminalNode *INDICATOR_BUFFERS();
    antlr4::tree::TerminalNode *INDICATOR_CHART_WINDOW();
    antlr4::tree::TerminalNode *INDICATOR_SEPARATE_WINDOW();
    antlr4::tree::TerminalNode *ADD_BRACKETS_FUNCTIONS();
    antlr4::tree::TerminalNode *CHANGE_BRACKETS_FUNCTIONS();
    antlr4::tree::TerminalNode *INDICATOR_BUFFERS_FUNC();
    antlr4::tree::TerminalNode *SET_INDEX_BUFFER();
    antlr4::tree::TerminalNode *SET_LEVEL_STYLE();
    antlr4::tree::TerminalNode *TIME_CURRENT();
    antlr4::tree::TerminalNode *ORDER_OPEN_TIME();
    antlr4::tree::TerminalNode *ORDER_CLOSE_TIME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Any_lexContext* any_lex();

  class  Sq_argumentsContext : public antlr4::ParserRuleContext {
  public:
    Sq_argumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_BR();
    antlr4::tree::TerminalNode *CL_BR();
    Sq_contentContext *sq_content();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sq_argumentsContext* sq_arguments();

  class  Sq_contentContext : public antlr4::ParserRuleContext {
  public:
    Sq_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sq_brackets_argumentContext *sq_brackets_argument();
    std::vector<Append_sq_contentContext *> append_sq_content();
    Append_sq_contentContext* append_sq_content(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sq_contentContext* sq_content();

  class  Append_sq_contentContext : public antlr4::ParserRuleContext {
  public:
    Append_sq_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    Sq_brackets_argumentContext *sq_brackets_argument();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Append_sq_contentContext* append_sq_content();

  class  Sq_brackets_argumentContext : public antlr4::ParserRuleContext {
  public:
    Sq_brackets_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Sq_brackets_anyruleContext *> sq_brackets_anyrule();
    Sq_brackets_anyruleContext* sq_brackets_anyrule(size_t i);
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    std::vector<Fcall_paramsContext *> fcall_params();
    Fcall_paramsContext* fcall_params(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sq_brackets_argumentContext* sq_brackets_argument();

  class  Sq_brackets_anyruleContext : public antlr4::ParserRuleContext {
  public:
    Sq_brackets_anyruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Argument_contentContext *argument_content();
    Parantheses_any_expressionContext *parantheses_any_expression();
    No_comma_sq_brContext *no_comma_sq_br();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sq_brackets_anyruleContext* sq_brackets_anyrule();

  class  DirectiveContext : public antlr4::ParserRuleContext {
  public:
    DirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HASH();
    NameContext *name();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    Ol_contentContext *ol_content();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DirectiveContext* directive();

  class  PropertyContext : public antlr4::ParserRuleContext {
  public:
    PropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HASH();
    antlr4::tree::TerminalNode *PROPERTY();
    Property_contentContext *property_content();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PropertyContext* property();

  class  StrContext : public antlr4::ParserRuleContext {
  public:
    StrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REGULAR_STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StrContext* str();

  class  Property_contentContext : public antlr4::ParserRuleContext {
  public:
    Property_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INDICATOR_BUFFERS();
    antlr4::tree::TerminalNode *INTEGER();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    antlr4::tree::TerminalNode *INDICATOR_CHART_WINDOW();
    antlr4::tree::TerminalNode *INDICATOR_SEPARATE_WINDOW();
    antlr4::tree::TerminalNode *K_STRICT();
    Property_style_definitionContext *property_style_definition();
    Ol_contentContext *ol_content();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Property_contentContext* property_content();

  class  Property_style_definitionContext : public antlr4::ParserRuleContext {
  public:
    Property_style_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    StrContext *str();
    Float_valueContext *float_value();
    Hex_or_regular_integerContext *hex_or_regular_integer();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Property_style_definitionContext* property_style_definition();

  class  Enum_extract2headerContext : public antlr4::ParserRuleContext {
  public:
    Enum_extract2headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Enum_declarationContext *enum_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enum_extract2headerContext* enum_extract2header();

  class  Enum_declarationContext : public antlr4::ParserRuleContext {
  public:
    Enum_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_ENUM();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *OP_CRL_BR();
    antlr4::tree::TerminalNode *CL_CRL_BR();
    antlr4::tree::TerminalNode *SC();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Enum_item_listContext *enum_item_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enum_declarationContext* enum_declaration();

  class  Enum_item_listContext : public antlr4::ParserRuleContext {
  public:
    Enum_item_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Enum_itemContext *> enum_item();
    Enum_itemContext* enum_item(size_t i);
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enum_item_listContext* enum_item_list();

  class  Enum_itemContext : public antlr4::ParserRuleContext {
  public:
    Enum_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enum_itemContext* enum_item();

  class  Variable_change_valueContext : public antlr4::ParserRuleContext {
  public:
    Variable_change_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_modify_rulesContext *variable_modify_rules();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Variable_change_valueContext* variable_change_value();

  class  Variable_modify_rulesContext : public antlr4::ParserRuleContext {
  public:
    Variable_modify_rulesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Variable_modify_rulesContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Variable_modify_rulesContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Variable_change_value_assignmentContext : public Variable_modify_rulesContext {
  public:
    Variable_change_value_assignmentContext(Variable_modify_rulesContext *ctx);

    Subscript_operatorContext *subscript_operator();
    Last_multi_assignment_rvalueContext *last_multi_assignment_rvalue();
    antlr4::tree::TerminalNode *SC();
    std::vector<Multi_assignmentContext *> multi_assignment();
    Multi_assignmentContext* multi_assignment(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Variable_change_value_name_fistContext : public Variable_modify_rulesContext {
  public:
    Variable_change_value_name_fistContext(Variable_modify_rulesContext *ctx);

    Subscript_operatorContext *subscript_operator();
    Unary_operatorContext *unary_operator();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Variable_change_value_name_lastContext : public Variable_modify_rulesContext {
  public:
    Variable_change_value_name_lastContext(Variable_modify_rulesContext *ctx);

    Unary_operatorContext *unary_operator();
    Subscript_operatorContext *subscript_operator();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Variable_modify_rulesContext* variable_modify_rules();

  class  Subscript_operatorContext : public antlr4::ParserRuleContext {
  public:
    Subscript_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    Sq_argumentsContext *sq_arguments();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subscript_operatorContext* subscript_operator();

  class  Multi_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Multi_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Asssignment_operatorContext *asssignment_operator();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Subscript_operatorContext *subscript_operator();
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Multi_assignmentContext* multi_assignment();

  class  Last_multi_assignment_rvalueContext : public antlr4::ParserRuleContext {
  public:
    Last_multi_assignment_rvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Asssignment_operatorContext *asssignment_operator();
    Subscript_operatorContext *subscript_operator();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Last_multi_assignment_rvalueContext* last_multi_assignment_rvalue();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Single_expr_spaceContext *single_expr_space();
    Unary_operatorContext *unary_operator();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *OP_BR();
    antlr4::tree::TerminalNode *CL_BR();
    Op_exprContext *op_expr();
    antlr4::tree::TerminalNode *CL_PARETHESES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  Op_exprContext : public antlr4::ParserRuleContext {
  public:
    Op_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Binary_operatorContext *binary_operator();
    Single_expr_spaceContext *single_expr_space();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Op_exprContext* op_expr();

  class  Binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *ASTRISK();
    antlr4::tree::TerminalNode *SLASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Binary_operatorContext* binary_operator();

  class  Unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCREMENT();
    antlr4::tree::TerminalNode *DECREMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_operatorContext* unary_operator();

  class  Single_expr_spaceContext : public antlr4::ParserRuleContext {
  public:
    Single_expr_spaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Single_exprContext *single_expr();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    antlr4::tree::TerminalNode *CL_PARETHESES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Single_expr_spaceContext* single_expr_space();

  class  Single_exprContext : public antlr4::ParserRuleContext {
  public:
    Single_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    Sq_argumentsContext *sq_arguments();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Float_valueContext *float_value();
    IntegerContext *integer();
    StrContext *str();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Single_exprContext* single_expr();

  class  Asssignment_operatorContext : public antlr4::ParserRuleContext {
  public:
    Asssignment_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *ASTRISK();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *ANY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Asssignment_operatorContext* asssignment_operator();

  class  Add_bracketsContext : public antlr4::ParserRuleContext {
  public:
    Add_bracketsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD_BRACKETS_FUNCTIONS();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Add_bracketsContext* add_brackets();

  class  Change_bracketsContext : public antlr4::ParserRuleContext {
  public:
    Change_bracketsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHANGE_BRACKETS_FUNCTIONS();
    antlr4::tree::TerminalNode *OP_BR();
    Sq_contentContext *sq_content();
    antlr4::tree::TerminalNode *CL_BR();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Change_bracketsContext* change_brackets();

  class  Unsupported_object_typesContext : public antlr4::ParserRuleContext {
  public:
    Unsupported_object_typesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNSUPPORTED_OBJECTS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unsupported_object_typesContext* unsupported_object_types();

  class  Unsupported_object_propertiesContext : public antlr4::ParserRuleContext {
  public:
    Unsupported_object_propertiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNSUPPORTED_PROPERTIES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unsupported_object_propertiesContext* unsupported_object_properties();

  class  Return_datetimeContext : public antlr4::ParserRuleContext {
  public:
    Return_datetimeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIME_CURRENT();
    antlr4::tree::TerminalNode *ORDER_OPEN_TIME();
    antlr4::tree::TerminalNode *ORDER_CLOSE_TIME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Return_datetimeContext* return_datetime();

  class  Indicator_buffers_funcContext : public antlr4::ParserRuleContext {
  public:
    Indicator_buffers_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INDICATOR_BUFFERS_FUNC();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Indicator_buffers_funcContext* indicator_buffers_func();

  class  Arg_commaContext : public antlr4::ParserRuleContext {
  public:
    Arg_commaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Arg_commaContext* arg_comma();

  class  Modifier_variable_declarationContext : public antlr4::ParserRuleContext {
  public:
    Modifier_variable_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_declarationContext *variable_declaration();
    std::vector<Append_variable_declarationContext *> append_variable_declaration();
    Append_variable_declarationContext* append_variable_declaration(size_t i);
    antlr4::tree::TerminalNode *SC();
    antlr4::tree::TerminalNode *K_STATIC();
    antlr4::tree::TerminalNode *EXTERN();
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *SINPUT();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Modifier_variable_declarationContext* modifier_variable_declaration();

  class  Variable_declarationContext : public antlr4::ParserRuleContext {
  public:
    Variable_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    NameContext *name();
    antlr4::tree::TerminalNode *K_CONST();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    antlr4::tree::TerminalNode *AMPERSAND();
    Dynamic_array_brackets_paramsContext *dynamic_array_brackets_params();
    Initialization_valueContext *initialization_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Variable_declarationContext* variable_declaration();

  class  Append_variable_declarationContext : public antlr4::ParserRuleContext {
  public:
    Append_variable_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    NameContext *name();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Dynamic_array_brackets_paramsContext *dynamic_array_brackets_params();
    Initialization_valueContext *initialization_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Append_variable_declarationContext* append_variable_declaration();

  class  Initialization_valueContext : public antlr4::ParserRuleContext {
  public:
    Initialization_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    Array_initialization_listContext *array_initialization_list();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    std::vector<RvalueContext *> rvalue();
    RvalueContext* rvalue(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Initialization_valueContext* initialization_value();

  class  Array_initialization_listContext : public antlr4::ParserRuleContext {
  public:
    Array_initialization_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_CRL_BR();
    antlr4::tree::TerminalNode *CL_CRL_BR();
    Initialization_list_itemsContext *initialization_list_items();
    std::vector<Initialization_list_append_itemsContext *> initialization_list_append_items();
    Initialization_list_append_itemsContext* initialization_list_append_items(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_initialization_listContext* array_initialization_list();

  class  Initialization_list_append_itemsContext : public antlr4::ParserRuleContext {
  public:
    Initialization_list_append_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    Initialization_list_itemsContext *initialization_list_items();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Initialization_list_append_itemsContext* initialization_list_append_items();

  class  Initialization_list_itemsContext : public antlr4::ParserRuleContext {
  public:
    Initialization_list_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Array_initialization_listContext *array_initialization_list();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    std::vector<Initialization_list_itemContext *> initialization_list_item();
    Initialization_list_itemContext* initialization_list_item(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Initialization_list_itemsContext* initialization_list_items();

  class  Initialization_list_itemContext : public antlr4::ParserRuleContext {
  public:
    Initialization_list_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    IntegerContext *integer();
    Float_valueContext *float_value();
    antlr4::tree::TerminalNode *NAME();
    StrContext *str();
    antlr4::tree::TerminalNode *CHAR_LITTERAL();
    antlr4::tree::TerminalNode *K_NULL();
    Const_nameContext *const_name();
    Date_litteralContext *date_litteral();
    Datetime_litteralContext *datetime_litteral();
    Color_litteralContext *color_litteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Initialization_list_itemContext* initialization_list_item();

  class  Const_nameContext : public antlr4::ParserRuleContext {
  public:
    Const_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIMEFRAME();
    antlr4::tree::TerminalNode *PRICE_TYPE();
    antlr4::tree::TerminalNode *IMA_MODE();
    antlr4::tree::TerminalNode *INDICATOR_LINE_IDENTIFIER_MODE();
    antlr4::tree::TerminalNode *UNSUPPORTED_PROPERTIES();
    antlr4::tree::TerminalNode *UNSUPPORTED_OBJECTS();
    antlr4::tree::TerminalNode *INDEX_BUFFER_TYPE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Const_nameContext* const_name();

  class  Dynamic_array_brackets_paramsContext : public antlr4::ParserRuleContext {
  public:
    Dynamic_array_brackets_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Dynamic_array_brackets_parameterContext *> dynamic_array_brackets_parameter();
    Dynamic_array_brackets_parameterContext* dynamic_array_brackets_parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dynamic_array_brackets_paramsContext* dynamic_array_brackets_params();

  class  Dynamic_array_brackets_parameterContext : public antlr4::ParserRuleContext {
  public:
    Dynamic_array_brackets_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_BR();
    antlr4::tree::TerminalNode *CL_BR();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Dynamic_array_parameterContext *dynamic_array_parameter();
    std::vector<Dynamic_array_append_parameterContext *> dynamic_array_append_parameter();
    Dynamic_array_append_parameterContext* dynamic_array_append_parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dynamic_array_brackets_parameterContext* dynamic_array_brackets_parameter();

  class  Dynamic_array_append_parameterContext : public antlr4::ParserRuleContext {
  public:
    Dynamic_array_append_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Dynamic_array_parameterContext *dynamic_array_parameter();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dynamic_array_append_parameterContext* dynamic_array_append_parameter();

  class  Dynamic_array_parameterContext : public antlr4::ParserRuleContext {
  public:
    Dynamic_array_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dynamic_array_parameterContext* dynamic_array_parameter();

  class  Set_index_bufferContext : public antlr4::ParserRuleContext {
  public:
    Set_index_bufferContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET_INDEX_BUFFER();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    NameContext *name();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    antlr4::tree::TerminalNode *INTEGER();
    RvalueContext *rvalue();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    antlr4::tree::TerminalNode *INDEX_BUFFER_TYPE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Set_index_bufferContext* set_index_buffer();

  class  Set_level_styleContext : public antlr4::ParserRuleContext {
  public:
    Set_level_styleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET_LEVEL_STYLE();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    No_semicolonContext *no_semicolon();
    antlr4::tree::TerminalNode *SC();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Set_level_styleContext* set_level_style();

  class  AlertContext : public antlr4::ParserRuleContext {
  public:
    AlertContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALERT();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AlertContext* alert();

  class  Function_definitionContext : public antlr4::ParserRuleContext {
  public:
    Function_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    antlr4::tree::TerminalNode *AMPERSAND();
    Params_listContext *params_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_definitionContext* function_definition();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_nameContext *> type_name();
    Type_nameContext* type_name(size_t i);
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  Type_nameContext : public antlr4::ParserRuleContext {
  public:
    Type_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *T_VOID();
    antlr4::tree::TerminalNode *T_INT();
    antlr4::tree::TerminalNode *T_DOUBLE();
    antlr4::tree::TerminalNode *T_FLOAT();
    antlr4::tree::TerminalNode *K_CONST();
    antlr4::tree::TerminalNode *T_BOOL();
    antlr4::tree::TerminalNode *T_CHAR();
    antlr4::tree::TerminalNode *K_UNSIGNED();
    antlr4::tree::TerminalNode *T_LONG();
    antlr4::tree::TerminalNode *T_SHORT();
    antlr4::tree::TerminalNode *T_STRING();
    antlr4::tree::TerminalNode *T_COLOR();
    antlr4::tree::TerminalNode *T_ULONG();
    antlr4::tree::TerminalNode *T_DATETIME();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_nameContext* type_name();

  class  Params_listContext : public antlr4::ParserRuleContext {
  public:
    Params_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentContext *argument();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    Params_listContext *params_list();
    Append_argumentContext *append_argument();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Params_listContext* params_list();
  Params_listContext* params_list(int precedence);
  class  Append_argumentContext : public antlr4::ParserRuleContext {
  public:
    Append_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    ArgumentContext *argument();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Append_argumentContext* append_argument();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_declarationContext *variable_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentContext* argument();

  class  Fcall_argumentContext : public antlr4::ParserRuleContext {
  public:
    Fcall_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Fcall_anyruleContext *> fcall_anyrule();
    Fcall_anyruleContext* fcall_anyrule(size_t i);
    std::vector<Fcall_paramsContext *> fcall_params();
    Fcall_paramsContext* fcall_params(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Fcall_argumentContext* fcall_argument();

  class  Fcall_anyruleContext : public antlr4::ParserRuleContext {
  public:
    Fcall_anyruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Argument_contentContext *argument_content();
    No_commaContext *no_comma();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Fcall_anyruleContext* fcall_anyrule();

  class  Fcall_paramsContext : public antlr4::ParserRuleContext {
  public:
    Fcall_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    Fcall_params_listContext *fcall_params_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Fcall_paramsContext* fcall_params();

  class  Fcall_params_listContext : public antlr4::ParserRuleContext {
  public:
    Fcall_params_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Fcall_argumentContext *fcall_argument();
    Fcall_params_listContext *fcall_params_list();
    Append_fcall_argumentContext *append_fcall_argument();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Fcall_params_listContext* fcall_params_list();
  Fcall_params_listContext* fcall_params_list(int precedence);
  class  Append_fcall_argumentContext : public antlr4::ParserRuleContext {
  public:
    Append_fcall_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    Fcall_argumentContext *fcall_argument();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Append_fcall_argumentContext* append_fcall_argument();

  class  Deinit_function_callContext : public antlr4::ParserRuleContext {
  public:
    Deinit_function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEINIT();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<antlr4::tree::TerminalNode *> T_VOID();
    antlr4::tree::TerminalNode* T_VOID(size_t i);
    antlr4::tree::TerminalNode *T_INT();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Deinit_function_callContext* deinit_function_call();

  class  Init_function_callContext : public antlr4::ParserRuleContext {
  public:
    Init_function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INIT();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<antlr4::tree::TerminalNode *> T_VOID();
    antlr4::tree::TerminalNode* T_VOID(size_t i);
    antlr4::tree::TerminalNode *T_INT();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Init_function_callContext* init_function_call();

  class  Start_function_callContext : public antlr4::ParserRuleContext {
  public:
    Start_function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<antlr4::tree::TerminalNode *> T_VOID();
    antlr4::tree::TerminalNode* T_VOID(size_t i);
    antlr4::tree::TerminalNode *T_INT();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Start_function_callContext* start_function_call();

  class  On_calculate_handlerContext : public antlr4::ParserRuleContext {
  public:
    On_calculate_handlerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *T_INT();
    antlr4::tree::TerminalNode *ON_CALCULATE();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    No_cl_parenthesesContext *no_cl_parentheses();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  On_calculate_handlerContext* on_calculate_handler();

  class  On_tick_handlerContext : public antlr4::ParserRuleContext {
  public:
    On_tick_handlerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();
    antlr4::tree::TerminalNode *ON_TICK();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);
    antlr4::tree::TerminalNode *T_VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  On_tick_handlerContext* on_tick_handler();

  class  On_init_handlerContext : public antlr4::ParserRuleContext {
  public:
    On_init_handlerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ON_INIT();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<antlr4::tree::TerminalNode *> T_VOID();
    antlr4::tree::TerminalNode* T_VOID(size_t i);
    antlr4::tree::TerminalNode *T_INT();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  On_init_handlerContext* on_init_handler();

  class  On_deinit_handlerContext : public antlr4::ParserRuleContext {
  public:
    On_deinit_handlerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();
    antlr4::tree::TerminalNode *ON_DEINIT();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *K_CONST();
    antlr4::tree::TerminalNode *T_INT();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  On_deinit_handlerContext* on_deinit_handler();

  class  On_timer_handlerContext : public antlr4::ParserRuleContext {
  public:
    On_timer_handlerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ON_TIMER();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    std::vector<antlr4::tree::TerminalNode *> T_VOID();
    antlr4::tree::TerminalNode* T_VOID(size_t i);
    antlr4::tree::TerminalNode *T_INT();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  On_timer_handlerContext* on_timer_handler();

  class  On_chart_event_handlerContext : public antlr4::ParserRuleContext {
  public:
    On_chart_event_handlerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ON_CHART_EVENT();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    std::vector<antlr4::tree::TerminalNode *> K_CONST();
    antlr4::tree::TerminalNode* K_CONST(size_t i);
    std::vector<antlr4::tree::TerminalNode *> T_INT();
    antlr4::tree::TerminalNode* T_INT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *T_LONG();
    std::vector<antlr4::tree::TerminalNode *> AMPERSAND();
    antlr4::tree::TerminalNode* AMPERSAND(size_t i);
    antlr4::tree::TerminalNode *T_DOUBLE();
    antlr4::tree::TerminalNode *T_STRING();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    antlr4::tree::TerminalNode *T_VOID();
    std::vector<SpaceContext *> space();
    SpaceContext* space(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  On_chart_event_handlerContext* on_chart_event_handler();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *DEINIT();
    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *INIT();
    antlr4::tree::TerminalNode *ON_CALCULATE();
    antlr4::tree::TerminalNode *ON_TICK();
    antlr4::tree::TerminalNode *ON_INIT();
    antlr4::tree::TerminalNode *ON_DEINIT();
    antlr4::tree::TerminalNode *ON_TIMER();
    antlr4::tree::TerminalNode *INDEX_BUFFER_TYPE();
    antlr4::tree::TerminalNode *ALERT();
    antlr4::tree::TerminalNode *GET_LAST_ERROR();
    antlr4::tree::TerminalNode *PLAY_SOUND();
    antlr4::tree::TerminalNode *STRATEGY_ONLY();
    antlr4::tree::TerminalNode *HOOKING_FUNCS();
    antlr4::tree::TerminalNode *INDICATORS_ONLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NameContext* name();

  class  SpaceContext : public antlr4::ParserRuleContext {
  public:
    SpaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WS();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SpaceContext* space();

  class  IntegerContext : public antlr4::ParserRuleContext {
  public:
    IntegerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *PLUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntegerContext* integer();

  class  Float_valueContext : public antlr4::ParserRuleContext {
  public:
    Float_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOATING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Float_valueContext* float_value();

  class  Tryblock_replacement_startContext : public antlr4::ParserRuleContext {
  public:
    Tryblock_replacement_startContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BD_SLASH();
    std::vector<antlr4::tree::TerminalNode *> TRY_BLOCK_DASH();
    antlr4::tree::TerminalNode* TRY_BLOCK_DASH(size_t i);
    antlr4::tree::TerminalNode *TRY_BLOCK_START();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Tryblock_replacement_startContext* tryblock_replacement_start();

  class  Tryblock_replacement_endContext : public antlr4::ParserRuleContext {
  public:
    Tryblock_replacement_endContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BD_SLASH();
    std::vector<antlr4::tree::TerminalNode *> TRY_BLOCK_DASH();
    antlr4::tree::TerminalNode* TRY_BLOCK_DASH(size_t i);
    antlr4::tree::TerminalNode *TRY_BLOCK_END();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Tryblock_replacement_endContext* tryblock_replacement_end();

  class  Parantheses_expressionContext : public antlr4::ParserRuleContext {
  public:
    Parantheses_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_PARETHESES();
    std::vector<antlr4::tree::TerminalNode *> CL_PARETHESES();
    antlr4::tree::TerminalNode* CL_PARETHESES(size_t i);
    Parantheses_expressionContext *parantheses_expression();
    std::vector<antlr4::tree::TerminalNode *> EOF();
    antlr4::tree::TerminalNode* EOF(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parantheses_expressionContext* parantheses_expression();

  class  Ml_contentContext : public antlr4::ParserRuleContext {
  public:
    Ml_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CL_COMMENT();
    antlr4::tree::TerminalNode* CL_COMMENT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ml_contentContext* ml_content();

  class  Ol_contentContext : public antlr4::ParserRuleContext {
  public:
    Ol_contentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EOF();
    antlr4::tree::TerminalNode* EOF(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ol_contentContext* ol_content();

  class  No_cl_parenthesesContext : public antlr4::ParserRuleContext {
  public:
    No_cl_parenthesesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CL_PARETHESES();
    antlr4::tree::TerminalNode* CL_PARETHESES(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EOF();
    antlr4::tree::TerminalNode* EOF(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  No_cl_parenthesesContext* no_cl_parentheses();

  class  No_semicolonContext : public antlr4::ParserRuleContext {
  public:
    No_semicolonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EOF();
    antlr4::tree::TerminalNode* EOF(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  No_semicolonContext* no_semicolon();

  class  No_commaContext : public antlr4::ParserRuleContext {
  public:
    No_commaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *OP_PARETHESES();
    antlr4::tree::TerminalNode *CL_PARETHESES();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  No_commaContext* no_comma();

  class  No_comma_sq_brContext : public antlr4::ParserRuleContext {
  public:
    No_comma_sq_brContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *OP_BR();
    antlr4::tree::TerminalNode *CL_BR();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  No_comma_sq_brContext* no_comma_sq_br();

  class  No_comma_semicolonContext : public antlr4::ParserRuleContext {
  public:
    No_comma_semicolonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *SC();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  No_comma_semicolonContext* no_comma_semicolon();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool params_listSempred(Params_listContext *_localctx, size_t predicateIndex);
  bool fcall_params_listSempred(Fcall_params_listContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

