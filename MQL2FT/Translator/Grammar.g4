grammar Grammar;

options
{
	//language = Cpp;
}

/*
 * Parser Rules
 */

compileUnit:  unit+  EOF ;

unit :		 
			property
		|	directive
		|	enum_extract2header
		|	any_function_definition	
		|	scope_content
		;

any_function_definition : 
						function_definition (append_scope | space* SC)
					|	entry_point append_scope
					;

append_scope : space* function_scope ;

function_scope : OP_CRL_BR scope_content* CL_CRL_BR ;

scope_content : 
					return_statement		// e
				|	function_scope			// e
				
				|	commented_block			// e
				|	modifier_variable_declaration // e

                |   for_loop                // e
				|	function_call			// e

                |	variable_change_value	// e

                |   subscript_operator      // e
				|	sq_arguments			// e
				|	single_name				// e

				|	directive

				

				|	datetime_litteral		// e
				|   color_litteral
				|	space
				|	property
				|	any_lex
				;

return_statement : void_return | standart_return ;

void_return : K_RETURN space* SC ;

standart_return : K_RETURN space* parantheses_any_expression space* SC ;

for_loop :   K_FOR space*  OP_PARETHESES 
					for_loop_declaration
					for_loop_condition
					for_loop_increment
				    CL_PARETHESES 
					;

for_loop_declaration :  space* 
                        (
                            for_loop_variable_decl
                        |   variable_change_value
                        )
                        ;

for_loop_variable_decl :  (variable_declaration append_variable_declaration* space* )? SC ;

for_loop_condition : space* (rvalue+ space*)? SC ;

for_loop_increment : space* (variable_modify_rules for_loop_append_increment* space* )? ;
for_loop_append_increment : space* COMMA space* variable_modify_rules;

rvalue :			function_call
            |       subscript_operator
			|		sq_arguments
			|		datetime_litteral
			|		variable_change_value 
			|   	color_litteral
			|		parantheses_any_expression
			|		name
			|       single_name
			|		no_parant_comma_sc 
			;

parantheses_any_expression : OP_PARETHESES parantheses_content? CL_PARETHESES ;

parantheses_content : parantheses_content_expression+ ;

parantheses_content_expression : 		//parantheses_any_expression 
							rvalue
						|	no_parant_sc
						;

no_parant_comma_sc : ~(OP_PARETHESES | CL_PARETHESES | COMMA | SC) ;

no_parant_sc : (~(OP_PARETHESES | CL_PARETHESES | SC )) ;

argument_content :	
				commented_block
			|	function_call
            |   subscript_operator
			|	sq_arguments
			|	single_name
			|	name
			|	variable_change_value
			|	space
			;

commented_block :
				tryblock_replacement_start	// e
			|	tryblock_replacement_end	// e
			;

function_call :
				alert					// e
			
			|	add_brackets			// e
			|	change_brackets			// e

			|	return_datetime			// both

			|	indicator_buffers_func

			|	set_index_buffer		// e
			|	set_level_style

			|	any_function_call
			;

any_function_call : name space* any_fcall_parantheses_expr ;

any_fcall_parantheses_expr : OP_PARETHESES any_fcall_parantheses_content? CL_PARETHESES ;

any_fcall_parantheses_content : rvalue any_fcall_append_argument* ;

any_fcall_append_argument : space* COMMA space* rvalue ;


entry_point :
				deinit_function_call
			|	init_function_call
			|	start_function_call
			|	on_calculate_handler	// e
			|	on_tick_handler
			|	on_init_handler
			|	on_deinit_handler
			|   on_timer_handler
			|	on_chart_event_handler
			;

single_name	:	INDICATORS_ONLY
			|	STRATEGY_ONLY
			|	HOOKING_FUNCS
			|	ON_TIMER
			|	unsupported_object_types
			|	unsupported_object_properties
			;

datetime_litteral : DT_LITTERAL_ST 
					( 
						time_litteral 
					|	date_litteral append_time_litteral?
					) ?
					S_QUOTE 
					;

append_time_litteral : space+ time_litteral ;

date_litteral : DATE_LITERAL ;
time_litteral : INTEGER ( COLON INTEGER (COLON INTEGER)? )?  ;

color_litteral : CLR_LITTERAL rgb_litteral S_QUOTE ;
rgb_litteral : space* hex_or_regular_integer arg_comma hex_or_regular_integer arg_comma hex_or_regular_integer space* ;

hex_or_regular_integer : INTEGER | HEX_INTEGER ;

any_lex :		MANY
			|	ANY
			|	SC
			|	COLON
			|	COMMA
			|	DOT
			|	AMPERSAND
			|	HASH
			|	EQ
			|	INCREMENT
			|	DECREMENT
			|	PLUS
			|	MINUS
			|	ASTRISK
			|	SLASH
			|	OP_PARETHESES
			|	CL_PARETHESES

			|	COMPARISSON
			|	COMPARISSON_NOT
			|	MORE_OR_EQUAL
			|	LESS_OR_EQUAL

			|	CHAR_LITTERAL

			|	INPUT
			|	SINPUT
			|	EXTERN
			|	K_STATIC
			|	K_STRICT
			|	K_CONST
			|	K_NULL
			|	K_UNSIGNED
			|	K_ENUM
			|	K_ELSE
			|	K_RETURN
			|	K_SWITCH
			|	K_CASE
			|	K_IF 
			|	K_FOR

			|	T_VOID
			|	T_BOOL
			|	T_LONG
			|	T_DATETIME
			|	T_DOUBLE
			|	T_CHAR
			|	T_STRING
			|	T_INT
			|	T_COLOR
			|	T_ULONG

			|	DT_LITTERAL_ST
			|   CLR_LITTERAL
			|	DATE_LITERAL
			|	S_QUOTE

			|   hex_or_regular_integer
			|	float_value

			|	INDICATOR_LINE_IDENTIFIER_MODE
			|	TIMEFRAME
			|	IMA_MODE
			|	PRICE_TYPE
			|	name
			|	str

			|	PROPERTY
			|	INDICATOR_BUFFERS
			|	INDICATOR_CHART_WINDOW
			|	INDICATOR_SEPARATE_WINDOW

			|	ADD_BRACKETS_FUNCTIONS
			|	CHANGE_BRACKETS_FUNCTIONS

			|	INDICATOR_BUFFERS_FUNC

			|	SET_INDEX_BUFFER
			|	SET_LEVEL_STYLE

			|	TIME_CURRENT
			|	ORDER_OPEN_TIME
			|	ORDER_CLOSE_TIME
			;

/* 
 * Begin square brackets block
*/

sq_arguments : OP_BR sq_content? CL_BR ;

sq_content : sq_brackets_argument append_sq_content* ;

append_sq_content : COMMA sq_brackets_argument ;


sq_brackets_argument :	sq_brackets_anyrule space* (fcall_params sq_brackets_anyrule* )+ 
					 |	sq_brackets_anyrule+
				     ;

sq_brackets_anyrule : argument_content | parantheses_any_expression | no_comma_sq_br ;

/* 
 * End square brackets block
*/ 

directive :	HASH WS* name ol_content?;
property  : HASH WS* PROPERTY property_content;

str : REGULAR_STRING ;	 

/*property_indicator_buffers :	HASH WS* NAME (NEWLINE | EOF);*/
property_content :				WS+ INDICATOR_BUFFERS WS+ INTEGER  WS*
							|	WS+ INDICATOR_CHART_WINDOW WS*
							|	WS+ INDICATOR_SEPARATE_WINDOW WS*
							|	WS+ K_STRICT
							|	property_style_definition
							|	ol_content?
							;

property_style_definition :	WS+ name WS+ (str | name | float_value | hex_or_regular_integer) WS* ;


/* 
 * Begin Enum block
*/

enum_extract2header : enum_declaration ;

enum_declaration : K_ENUM space+ NAME space* OP_CRL_BR space* enum_item_list? space* CL_CRL_BR space* SC ;

enum_item_list : enum_item space* COMMA? (space* enum_item space* COMMA)* space* enum_item?;

enum_item : NAME space* (EQ space* INTEGER)? ;

/* 
 * End Enum block
*/

variable_change_value : variable_modify_rules ;

variable_modify_rules :	
                        	subscript_operator multi_assignment* last_multi_assignment_rvalue SC		#variable_change_value_assignment
						|	subscript_operator space* unary_operator		#variable_change_value_name_fist
						|	unary_operator space* subscript_operator		#variable_change_value_name_last
                        ;

subscript_operator :   name ( space* sq_arguments )? ;

multi_assignment : space* asssignment_operator space* ( subscript_operator | rvalue+ )? ;

last_multi_assignment_rvalue : space* asssignment_operator space* ( subscript_operator | rvalue+ ) ;

// expression : 	single_expr
// 			|	expression space* binary_operator space* single_expr
// 			|	expression space* unary_operator
// 			|	unary_operator space* expression
// 			|	OP_BR expression CL_BR
// 			;

expression  :	single_expr_space
			|   expression op_expr
            |   expression unary_operator CL_PARETHESES?
            |   OP_PARETHESES? unary_operator expression
            |   OP_BR expression CL_BR
            ;

op_expr : binary_operator single_expr_space ;

binary_operator :	PLUS | MINUS | ASTRISK | SLASH ;
unary_operator  :   INCREMENT | DECREMENT ;

single_expr_space : OP_PARETHESES? space* single_expr space* (CL_PARETHESES space*)? ;

single_expr :	name (space* sq_arguments)?
			|	float_value
			|	integer 
			|	str
			;


asssignment_operator :		EQ
						|	PLUS EQ
						|	MINUS EQ
						|	ASTRISK EQ
						|	SLASH EQ
						|	AMPERSAND EQ
						|	ANY EQ
						;

//add_brackets_exception	:	ADD_BRACKETS_FUNCTIONS space* OP_PARETHESES space* CL_PARETHESES ;
add_brackets 	:	ADD_BRACKETS_FUNCTIONS ( space* OP_PARETHESES space* CL_PARETHESES )? ;
change_brackets :	CHANGE_BRACKETS_FUNCTIONS space* OP_BR sq_content CL_BR ;

unsupported_object_types :	UNSUPPORTED_OBJECTS ;
unsupported_object_properties : UNSUPPORTED_PROPERTIES ;

return_datetime :	TIME_CURRENT 
				|	ORDER_OPEN_TIME
				|	ORDER_CLOSE_TIME
				;

indicator_buffers_func : INDICATOR_BUFFERS_FUNC space* OP_PARETHESES space* INTEGER space* CL_PARETHESES ;

arg_comma : space* COMMA space* ;

/* 
 * Begin variable declaration block
*/

modifier_variable_declaration :	
				(
					(K_STATIC | EXTERN | INPUT | SINPUT) 
					space+
				)?
				variable_declaration append_variable_declaration* (space* SC)?
				;

variable_declaration :
					(
						K_CONST space+
					)?
					type space* (AMPERSAND space*)? name 
					(space* dynamic_array_brackets_params )?
					(space* initialization_value)? 
					;

append_variable_declaration :   space* COMMA space* name 
								(space* dynamic_array_brackets_params )?
								space* initialization_value?
								;

initialization_value :  EQ space*
						( 
								array_initialization_list 
							|	rvalue+
						);

array_initialization_list : OP_CRL_BR 
							(
								initialization_list_items
								initialization_list_append_items* 
							)?
							CL_CRL_BR 
							;

initialization_list_append_items : COMMA initialization_list_items ;

initialization_list_items : 
							(
								   space* array_initialization_list space*
								|  space+
								|  initialization_list_item+ 
							)
							;

initialization_list_item :
						  space+ 
						| integer 
						| float_value 
						| NAME 
						| str 
						| CHAR_LITTERAL
                        | K_NULL
                        | const_name
						| date_litteral
                        | datetime_litteral
						| color_litteral
						| float_value
						;

const_name :   
                TIMEFRAME
            |   PRICE_TYPE
            |   IMA_MODE
            |   INDICATOR_LINE_IDENTIFIER_MODE
            |   UNSUPPORTED_PROPERTIES
            |   UNSUPPORTED_OBJECTS
            |   INDEX_BUFFER_TYPE
            ;

dynamic_array_brackets_params : dynamic_array_brackets_parameter+ ;

dynamic_array_brackets_parameter :
									OP_BR space*
									(       dynamic_array_parameter dynamic_array_append_parameter*
								        |   dynamic_array_parameter? dynamic_array_append_parameter+
                                    ) ?
									space* CL_BR ;

dynamic_array_append_parameter : space* COMMA space* dynamic_array_parameter? ;

dynamic_array_parameter : NAME | INTEGER ;

/* 
 * End variable declaration block
*/

set_index_buffer : 	SET_INDEX_BUFFER space* 
					OP_PARETHESES space*
						(INTEGER | rvalue) space* COMMA space* name space* 
						(COMMA space* INDEX_BUFFER_TYPE space*)? 
					CL_PARETHESES
				;

set_level_style  :  SET_LEVEL_STYLE space* OP_PARETHESES no_semicolon SC ;

alert : ALERT space* OP_PARETHESES ;

function_definition : type space* AMPERSAND? space* NAME space* OP_PARETHESES space* params_list? CL_PARETHESES ;

type : type_name  (space* type_name)* ;

type_name : T_VOID | T_INT | T_DOUBLE | T_FLOAT | K_CONST | T_BOOL | T_CHAR | K_UNSIGNED |
			T_LONG | T_SHORT | T_STRING | T_COLOR | T_ULONG | T_DATETIME | NAME ;

params_list : 		argument space*
				|	params_list append_argument
				;

append_argument : COMMA space* argument space* ;

argument :	variable_declaration ;

fcall_argument : 	fcall_anyrule+
				|	fcall_anyrule* (fcall_params fcall_anyrule* )+ ;

fcall_anyrule :		argument_content | no_comma ;

fcall_params :	OP_PARETHESES fcall_params_list? CL_PARETHESES ;

fcall_params_list :		fcall_argument
					|	fcall_params_list append_fcall_argument
				;

append_fcall_argument :	COMMA fcall_argument ;

/* Entry points */

deinit_function_call : (T_VOID | T_INT) space+ DEINIT space* OP_PARETHESES space* (T_VOID space*)? CL_PARETHESES ;
init_function_call : (T_VOID | T_INT) space+ INIT space* OP_PARETHESES space* (T_VOID space*)? CL_PARETHESES ;
start_function_call : (T_VOID | T_INT) space+ START space* OP_PARETHESES space* (T_VOID space*)? CL_PARETHESES ;

on_calculate_handler : T_INT space+ ON_CALCULATE space* OP_PARETHESES no_cl_parentheses CL_PARETHESES;
on_tick_handler : type_name space+ ON_TICK space* OP_PARETHESES space* (T_VOID space*)? CL_PARETHESES ;
on_init_handler : (T_VOID | T_INT) space+ ON_INIT space* OP_PARETHESES space* (T_VOID space*)? CL_PARETHESES ;
on_deinit_handler :  type_name space+ ON_DEINIT space* OP_PARETHESES space* K_CONST space* T_INT space* NAME space* CL_PARETHESES ;
on_timer_handler : (T_VOID | T_INT) space+ ON_TIMER space* OP_PARETHESES space* (T_VOID space*)? CL_PARETHESES;
on_chart_event_handler : (T_VOID | T_INT) space+ ON_CHART_EVENT space* OP_PARETHESES space* K_CONST space* T_INT
						space* NAME space* COMMA space* K_CONST space* T_LONG space* AMPERSAND space* NAME space* COMMA space*
						K_CONST space* T_DOUBLE space* AMPERSAND space* NAME space* COMMA space* K_CONST 
						space* T_STRING space* AMPERSAND space* NAME space* CL_PARETHESES;

name: 		NAME 
		|	DEINIT 
		|	START 
		|	INIT 
		|	ON_CALCULATE 
		|	ON_TICK 
		|	ON_INIT 
		|	ON_DEINIT 
		|	ON_TIMER
		|	INDEX_BUFFER_TYPE 
		|	ALERT 
		|	GET_LAST_ERROR
		|	PLAY_SOUND
		
		|	STRATEGY_ONLY
		|	HOOKING_FUNCS
		|	INDICATORS_ONLY
		;

space		:		WS 
				| 	NEWLINE 
				;
integer		:	(MINUS | PLUS)? INTEGER ;

float_value :	FLOATING_LITERAL ;

/*
VerbatiumString: '\'' (~'\'' | SQuote)* '\'';
FLOAT : '.' INTEGER ExponentPart? | INTEGER '.' INTEGER+ ExponentPart?;
HEX_INTEGER: '0' [xX] HexDigit+;
NAME : (Char | Digit)* Char (Char | Digit)*;
*/


tryblock_replacement_start  : BD_SLASH TRY_BLOCK_DASH TRY_BLOCK_START NAME TRY_BLOCK_DASH;
/*BD_SLASH TryBlockDash TryBlock Start Function EQ NAME TryBlockDash;*/
tryblock_replacement_end : BD_SLASH TRY_BLOCK_DASH TRY_BLOCK_END NAME TRY_BLOCK_DASH;
/*BD_SLASH TryBlockDash TryBlock End Function EQ NAME TryBlockDash;*/


parantheses_expression : OP_PARETHESES ( (~(CL_PARETHESES | EOF))+ | parantheses_expression) CL_PARETHESES ;
ml_content : (~(CL_COMMENT))+ ;    // Multiline Content
ol_content : (~(NEWLINE | EOF))+ ; // One Line Content
no_cl_parentheses : (~(CL_PARETHESES | SC | EOF))+ ;
no_semicolon :	(~(SC | EOF))+ ;
no_comma :	(~(COMMA | OP_PARETHESES | CL_PARETHESES | EOF)) ;
no_comma_sq_br : (~(COMMA | OP_BR | CL_BR | EOF)) ;
no_comma_semicolon :  ~(COMMA | SC | EOF) ;

/*
 * Lexer Rules
 */

/* symbols and operators */

HASH	:	'#' ;

COMMA 	:	',' ;
DOT		:	'.' ;

OP_BR :		  '[' ;
CL_BR :		  ']' ;

OP_PARETHESES : '(' ;
CL_PARETHESES : ')' ;

OP_CRL_BR :		'{' ;
CL_CRL_BR :		'}' ;

COLON :		':' ;
SC	:		';' ;

D_QUOTE :	  '"' ;
S_QUOTE :     '\'' ;

EQ :		'=' ;

COMPARISSON :		'==' ;
COMPARISSON_NOT :	'!=' ;
MORE_OR_EQUAL :		'>=' ;
LESS_OR_EQUAL :		'<=' ;

INCREMENT : '++' ;
DECREMENT : '--' ;

PLUS	:	'+' ;
MINUS	:	'-' ;
ASTRISK	:	'*' ;
SLASH	:	'/' ;

AMPERSAND : '&' ;

NEWLINE    : '\n' | '\r' '\n'? ;

BD_SLASH   :  '//' ;
OP_COMMENT :  '/*' ;
CL_COMMENT :  '*/' ;

MULTILINE_COMMENT : OP_COMMENT .*? CL_COMMENT            -> skip ;
ONELINE_COMMENT   : BD_SLASH ( ~[\r\n]* | NEWLINE ) EOF? -> skip ;

WS		:	(' ' | '\t')+ ;

/* entry points */

DEINIT : 'deinit' ;
INIT : 'init' ;
START : 'start' ;

ON_CALCULATE : 'OnCalculate' ;
ON_TICK : 'OnTick' ;
ON_INIT : 'OnInit' ;
ON_DEINIT : 'OnDeinit' ;
ON_TIMER : 'OnTimer' ;
ON_CHART_EVENT : 'OnChartEvent' ;
TRY_BLOCK_DASH : '----' ;
TRY_BLOCK_START : 'try block start function=' ;
TRY_BLOCK_END : 'try block end function=' ;

INDEX_BUFFER_TYPE : 'INDICATOR_DATA' |  'INDICATOR_COLOR_INDEX' | 'INDICATOR_CALCULATIONS' ;

/* types and modifiers */

EXTERN		:  'extern' ;
INPUT		:  'input' ;
SINPUT		:  'sinput' ;

K_STATIC	:  'static' ;
K_STRICT	:  'strict' ;
K_NULL		:  'NULL' ;
K_CONST		:  'const' ;
K_UNSIGNED	:  'unsigned' ;
K_ENUM		:  'enum' ;
K_ELSE		:  'else' ;
K_SWITCH	:  'switch' ;
K_CASE		:  'case' ;
K_RETURN	:  'return' ;
K_FOR		:  'for' ; 
K_IF		:  'if' ; 

T_DOUBLE	:  'double' ;
T_FLOAT		:  'float' ;
T_VOID		:  'void' ;
T_INT		:  'int' ;
T_BOOL		:  'bool' ;
T_LONG		:  'long' ;
T_SHORT		:  'short' ;
T_CHAR		:  'char' ;
T_STRING	:  'string' ;
T_COLOR		:  'color' ;
T_ULONG		:  'ulong' ;
T_DATETIME  :  'datetime' ;

/* directives and properties */

PROPERTY 		:  'property';

INDICATOR_SEPARATE_WINDOW : 'indicator_separate_window';
INDICATOR_CHART_WINDOW	  : 'indicator_chart_window';

/* function names */

ALERT			: 'Alert' ;
GET_LAST_ERROR  : 'GetLastError' ;
PLAY_SOUND		: 'PlaySound' ;

ADD_BRACKETS_FUNCTIONS	:	('Ask' | 'Bars' | 'Bid' | 'Digits' | 'Point' | 'Symbol');
CHANGE_BRACKETS_FUNCTIONS	:	('Close' | 'High' | 'Low' | 'Open' | 'Time' | 'Volume');

SET_INDEX_BUFFER :	'SetIndexBuffer';
SET_LEVEL_STYLE  :  'SetLevelStyle';

INDICATOR_BUFFERS :	'indicator_buffers' ;
INDICATOR_BUFFERS_FUNC : 'IndicatorBuffers' ;
INDICATORS_ONLY	:	('IndicatorBuffers' | 'SetIndexBuffer' | 'SetIndexStyle' | 'IndicatorCounted');
STRATEGY_ONLY   :   ('OrderModify' | 'OrderDelete' | 'OrderClose' | 'OrderSend' | 'AccountBalance' | 'AccountEquity');
HOOKING_FUNCS   :   ('WindowPriceMax' | 'WindowPriceMin' | 'WindowBarsPerChart');

TIME_CURRENT :      'TimeCurrent' ;
ORDER_OPEN_TIME :   'OrderOpenTime' ;
ORDER_CLOSE_TIME :   'OrderCloseTime' ;

/* enums and constans */

UNSUPPORTED_OBJECTS : 	( 'OBJ_FIBOCHANNEL' 
						| 'OBJ_PITCHFORK' 
						| 'OBJ_TRENDBYANGLE' 
						| 'OBJ_CYCLES' 
						| 'OBJ_CHANNEL' 
                        | 'OBJ_CHART' 
						| 'OBJ_STDDEVCHANNEL' 
						| 'OBJ_REGRESSION' 
						| 'OBJ_GANNLINE' 
						| 'OBJ_GANNFAN' 
						| 'OBJ_GANNGRID' 
						| 'OBJ_EXPANSION' 
						| 'OBJ_ARROW_THUMB_UP' 
						| 'OBJ_ARROW_THUMB_DOWN' 
						| 'OBJ_ARROW_UP' 
						| 'OBJ_ARROW_DOWN' 
						| 'OBJ_ARROW_STOP' 
						| 'OBJ_ARROW_CHECK' 
						| 'OBJ_ARROW_LEFT_PRICE' 
						| 'OBJ_ARROW_RIGHT_PRICE' 
						| 'OBJ_ARROW_BUY' 
						| 'OBJ_ARROW_SELL' 
						| 'OBJ_BUTTON' 
                        | 'OBJ_BITMAP' 
						| 'OBJ_BITMAP_LABEL' 
						| 'OBJ_EDIT' 
						| 'OBJ_EVENT' 
						| 'OBJ_RECTANGLE_LABEL' )
						;

UNSUPPORTED_PROPERTIES	:	
						( 'OBJPROP_SCALE'
						| 'OBJPROP_ZORDER'
						| 'OBJPROP_HIDDEN'
						| 'OBJPROP_SELECTED'
						| 'OBJPROP_READONLY'
						| 'OBJPROP_TYPE'
						| 'OBJPROP_TIME'
						| 'OBJPROP_SELECTABLE'
						| 'OBJPROP_CREATETIME'
						| 'OBJPROP_ALIGN'
						| 'OBJPROP_TIMEFRAMES'
						| 'OBJPROP_DRAWLINES'
						| 'OBJPROP_STATE'
						| 'OBJPROP_XSIZE'
						| 'OBJPROP_YSIZE'
						| 'OBJPROP_XOFFSET'
						| 'OBJPROP_YOFFSET'
						| 'OBJPROP_BGCOLOR'
						| 'OBJPROP_CORNER'
						| 'OBJPROP_BORDER_TYPE'
						| 'OBJPROP_BORDER_COLOR'
						| 'BORDER_FLAT'
						| 'BORDER_RAISED'
						| 'BORDER_SUNKEN'
						| 'OBJPROP_PRICE'
						| 'OBJPROP_DEVIATION'
						| 'OBJPROP_TOOLTIP'
						| 'OBJPROP_LEVELTEXT'
						| 'OBJPROP_BMPFILE'
						| 'OBJPROP_SYMBOL'
						| 'ALIGN_LEFT'
						| 'ALIGN_CENTER'
						| 'ALIGN_RIGHT' )
						;

INDICATOR_LINE_IDENTIFIER_MODE : (
								'MODE_SIGNAL'
							|	'MODE_MAIN'
							);
					
IMA_MODE : (
			'MODE_SMA'
		|	'MODE_EMA'
		|	'MODE_LWMA'
		|	'MODE_SMMA'
		);

PRICE_TYPE : (
		'PRICE_CLOSE'
	|	'PRICE_OPEN'
	|	'PRICE_HIGH'
	|	'PRICE_LOW'
	|	'PRICE_MEDIAN'
	|	'PRICE_TYPICAL'
	|	'PRICE_WEIGHTED'
	);

TIMEFRAME :
		  'PERIOD_CURRENT'
		| 'PERIOD_M1'
		| 'PERIOD_M5'
		| 'PERIOD_M15'
		| 'PERIOD_M30'
		| 'PERIOD_M39'
		| 'PERIOD_H1'
		| 'PERIOD_H2'
		| 'PERIOD_H3'
		| 'PERIOD_H4'
		| 'PERIOD_H5'
		| 'PERIOD_H6'
		| 'PERIOD_H7'
		| 'PERIOD_H8'
		| 'PERIOD_H9'
		| 'PERIOD_H10'
		| 'PERIOD_H11'
		| 'PERIOD_H12'
		| 'PERIOD_H13'
		| 'PERIOD_H14'
		| 'PERIOD_H15'
		| 'PERIOD_H16'
		| 'PERIOD_H17'
		| 'PERIOD_H18'
		| 'PERIOD_H19'
		| 'PERIOD_H20'
		| 'PERIOD_H21'
		| 'PERIOD_H23'
		| 'PERIOD_D1'
		| 'PERIOD_W1'
		| 'PERIOD_MN'
		| 'PERIOD_MN1'
		| 'PERIOD_H22'
		;

/* other */

DT_LITTERAL_ST : 'D\'' ;

CLR_LITTERAL : 'C\'' ;

REGULAR_STRING :  D_QUOTE (~["\\\u0085\u2028\u2029] | EscapeSequences)* D_QUOTE ;

CHAR_LITTERAL : S_QUOTE  (~["\\\u0085\u2028\u2029] | EscapeSequences | S_QUOTE) S_QUOTE ;

NAME	:	LETTER (LETTER | DIGIT)* ;

INTEGER	:		DIGIT+ ;

HEX_INTEGER : Hex_prefix HexDigit+ ;

DATE_LITERAL : INTEGER DOT INTEGER DOT INTEGER ;

FLOATING_LITERAL : (MINUS | PLUS)? (INTEGER? DOT INTEGER | INTEGER DOT) ExponentPart? FloatingSuffix?
				|	(MINUS | PLUS)? INTEGER ExponentPart FloatingSuffix? ;

LETTER			: [A-Za-z_] ;
DIGIT			: [0-9] ;

ANY : 		
				NotToMatch
			| 	'/' NotToMatch
			| 	'\\' '"'
			|	'*' NotToMatch
			|	'©'
			;

MANY : ANY+ ;

/*
 *  Fragments
 */

fragment FloatingSuffix : [FLfl] ;

fragment ExponentPart : [eE][-+]?[0-9]+ ;

fragment NotToMatch: ~('"' | '\'' | '*' | '/' | '[' | ']' | '\n' | '\r' | '#' | [A-Za-z_0-9] | ' ' | '\t' | ';' | '(' | ')' | '{' | '}' | ',' | '.' | '&' | '=' | ':') ;

fragment EscapeSequences :
		SimpleEscapeSequence
	| 	HexEscapeSequence
	;
	
fragment SimpleEscapeSequence
	: '\\\''
	| '\\"'
	| '\\\\'
	| '\\0'
	| '\\a'
	| '\\b'
	| '\\f'
	| '\\n'
	| '\\r'
	| '\\t'
	| '\\v'
	| '\\u' // DHTODO: Change /u and /U to //u and //U in output mql4.cpp via parser
	| '\\U' // Make /u and /U into separate tokens for that
	;
	
fragment HexEscapeSequence
	: '\\x' HexDigit
	| '\\x' HexDigit HexDigit
	| '\\x' HexDigit HexDigit HexDigit
	| '\\x' HexDigit HexDigit HexDigit HexDigit
	;

fragment Hex_prefix : '0x' ;
	
fragment HexDigit : [0-9] | [A-F] | [a-f];