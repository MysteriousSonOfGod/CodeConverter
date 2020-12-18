
#include "Listener.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Listener::Listener(ofstream* target, ofstream* header_target, string* text_include)
    : to(target)
    , cpp(target)
    , head(header_target)
    , textToInclude(text_include)
{
}

Listener::~Listener()
{
}

// Helper functions

int Listener::getScriptType()
{
	return this->scriptType;
}

ErrorType Listener::GetErrorType()
{
	return this->err_type;
}

void Listener::SetErrorType(ErrorType type)
{
	this->err_type = type;
}

void Listener::SetBuffer()
{
	if (buffer_level++ == 0)
		to = &buffer;
}

string Listener::ResetBuffer()
{
	if (buffer_level > 0 && --buffer_level == 0) {
		to = cpp;
		string s = buffer.str();
		buffer.str("");
		return s;
	}
	return "";
}

string* Listener::getTOptionType(string& var_type) {
	char* option_type;

	if (var_type == "unsigned long" )
		option_type = "ot_Longword";
	else if (var_type == "int")
		option_type = "ot_Integer";
	else if (var_type == "double")
		option_type = "ot_Double";
	else if (var_type == "char*")
		option_type = "ot_String";
	else if (var_type == "string")
		option_type = "ot_String";
	else if (var_type == "bool")
		option_type = "ot_Boolean";
	else
		option_type = "ot_Reserved0";

	return new string(option_type);
}

void Listener::addIncludeLine()
{
	if (!this->addedInclude) {
		*to << *this->textToInclude;
		this->addedInclude = true;
	}
}

void Listener::WriteEPTypes()
{
	ofstream os("EPTypes.bat", ofstream::out | ofstream::trunc);

	os << "set iniT=\"";
	if(initType == InitType::INIT_UNDEFINED) os << "__INIT_UNDEFINED";
	else if (initType == InitType::INT_ON_INIT) os << "__INT_ON_INIT";
	else if (initType == InitType::VOID_ON_INIT) os << "__VOID_ON_INIT";
	else if (initType == InitType::INT_INIT) os << "__INIT_INT";
	else if (initType == InitType::VOID_INIT) os << "__INIT_VOID";
	os << "\"\n";
	
	os << "set deinT=\"";
	if(deinitType == DeinitType::DEINIIT_UNDEFINED) os << "__DEINIT_UNDEFINED";
	else if (deinitType == DeinitType::VOID_ON_DEINIT) os << "__VOID_ON_DEINIT";
	else if (deinitType == DeinitType::INT_DEINIT) os << "__DEINIT_INT";
	else if (deinitType == DeinitType::VOID_DEINIT) os << "__DEINIT_VOID";
	os << "\"\n";
	
	os << "set stT=\"";
	if(startType == StartType::START_UNDEFINED) os << "__START_UNDEFINED";
	else if (startType == StartType::INT_ON_CALCULATE) os << "__INT_ON_CALCULATE";
	else if (startType == StartType::ON_TICK) os << "__ON_TICK";
	else if (startType == StartType::INT_START) os << "__START_INT";
	else if (startType == StartType::VOID_START) os << "__START_VOID";
	os << "\"\n";

	if(this->isStrict)
	{
		os << "set isStrict=\"MQL2FT_STRICT_MODE\"\n";
	}
	
	if(hooking_funcs_present)
	{
		os << "set Hooking=\"ENABLE_HOOKING\"\n";
	}

	if(on_timer)
	{
		os << "set onTimerT=\"__ON_TIMER\"\n";
	}

	os.close();
}

void Listener::putParameterBefore(string name)
{
	registerOptions_function
		<< "   "
		<< "RegOption(\""
		<< name
		<< "\", "
		;

	//delete option_type;
}

void Listener::setOuterName(string && name)
{
	this->outer_definition_name = name;
}

void Listener::resetOuterName()
{
	this->outer_definition_name = "";
}

void Listener::setOuterType(string && name)
{
	this->outer_type_name = name;
}

void Listener::resetOuterType()
{
	this->outer_type_name = "";
}

inline bool Listener::isInsideFunctionScope()
{
	return this->outer_definition_name != "";
}

inline bool Listener::isOnCalculate()
{
	return  this->outer_definition_name == "OnCalculate";
}

void Listener::appendAddOptionsFunction()
{
	*to << "\nvoid RegisterPotentialOptions(PChar var_name, std::list<PChar> var_options)"
		"\n{\n"
		"	for(auto var_i = var_options.begin(); var_i != var_options.end(); var_i++)\n"
		"		AddOptionValue(var_name, *var_i);"
		"\n}\n"
		;
}

inline void Listener::generateCompilationDTVariables()
{
	*head << "#undef __DATE__\n";
	auto sec = time(NULL);
	tm* gm = gmtime(&sec);
	const int gm_h = gm->tm_hour;
	tm* loc = localtime(&sec);

	sec += (loc->tm_hour - gm_h) * 3600;

	*head << "#define __DATETIME__ " << "datetime((long)" << sec << ")\n";

	time_t dec_sec = loc->tm_hour * 3600 + loc->tm_min * 60 + loc->tm_sec;

	*head << "#define __DATE__ " << "datetime((long)" << sec - dec_sec << ")\n";
}

void Listener::StrategyScript(string&& name)
{
	this->strategy_definitions = true;
	this->strategyFunctionsCalls.insert(name);
}

void Listener::IndicatorScript(string && name)
{
	this->indicator_definitions = true;
	this->indicatorFunctionsCalls.insert(name);
}

string Listener::nameFromSubscript(string & name)
{
	int i = name.find('[', 0);
	if (i > -1)
		return name.substr(0, i - 1);
	else return name;
}

void Listener::SetOutpuTraverse(bool output)
{
	this->isOutputTraverse = output;
}

string Listener::getPadding(bool new_line)
{
	string tab = new_line ? "\n" : "";
	for (size_t i = 0; i < this->scope_level; i++) tab += "\t";
	return tab;
}

inline bool Listener::IsEnumConstant(const string & name) const
{
    return enum_constants.find(name) != enum_constants.end();
}

bool Listener::IsArithmeticType(const std::string& type_name) const
{
    return (type_name == "int"   || type_name == "double" || type_name == "float"
         || type_name == "char"  || type_name == "bool"   || type_name == "long"
         || type_name == "short" || type_name == "uint"   || type_name == "ulong"
         || type_name == "uchar" || type_name == "ushort");
}

void Listener::setImplicitCast(bool declaration)
{
	// initiate implicit casting to number types
	implicit_cast = declaration ? "" : " ";

	switch(assigned_type)
	{
	case Int:
		implicit_cast += "int(";
		break;
	case UInt:
		implicit_cast += "(unsigned int)(";
		break;
	case Long:
		implicit_cast += "long(";
		break;
	case ULong:
		implicit_cast += "(unsigned long)(";
		break;
	case Short:
		implicit_cast += "short(";
		break;
	case UShort:
		implicit_cast += "(unsigned short)(";
		break;
	case Char:
		implicit_cast += "char(";
		break;
	case UChar:
		implicit_cast += "(unsigned char)(";
		break;
	case Double:
		implicit_cast += "double(";
		break;
	case Float:
		implicit_cast += "float(";
		break;
	case Bool:
		implicit_cast += "bool(";
		break;
	default:
		break;
	}
}

// Graph walking functions

void Listener::enterCompileUnit(GrammarParser::CompileUnitContext * ctx)
{
	if (isOutputTraverse) {

		*head << "\n#include \"ExternString.h\"\n#include \"MqlNull.h\"\n\nnamespace mql4\n{\n\n";

		generateCompilationDTVariables();

		*head << endl;

		registerOptions_function << "\nvoid RegisterOptions()\n{\n";

		addIncludeLine();
	}
}

void Listener::exitCompileUnit(GrammarParser::CompileUnitContext * ctx)
{
	if(!isOutputTraverse)
	{
		return;
	}

	if(!this->deinit_found)
	{
		*to << "\nvoid deinit()\n{\n}\n";
	}

	registerOptions_function << "\n";

	if(this->indicator_definitions)
	{
		if(this->strategy_definitions)
		{
			cout << "\n   (warning): Both strategy functions: ";
			const char* comma_separator = ", ";
			const char* separator = "";

			for(const auto& st : strategyFunctionsCalls)
			{
				cout << separator << st;
				separator = comma_separator;
			}
			cout << "\n              and indicator functions(properties): ";

			separator = "";
			for(const auto& ind : indicatorFunctionsCalls)
			{
				cout << separator << ind;
				separator = comma_separator;
			}
			cout << "\n              were found.\n";
		}
		this->scriptType = 2;

		int buffs = visible_ind_buffs > set_ind_buffs ? set_ind_buffs : visible_ind_buffs;
		if(!buffs && set_ind_buffs)
		{
			buffs = 1;
		}
		registerOptions_function << "\n   IndicatorBuffers(" << buffs << ");\n";

		registerOptions_function << set_ind_buffs_calls.str() << endl;

		if(this->stylesToAdd.size() > 0) {
			for(auto i = this->stylesToAdd.begin(); i != this->stylesToAdd.end(); i++)
			{

				registerOptions_function << "\n   SetIndexStyle(" << i->first << ", ";
				if(i->second->Type == "") {
					registerOptions_function << "DRAW_LINE";
				}
				else {
					registerOptions_function << i->second->Type;
				}
				if(i->second->Style != "") registerOptions_function << ", " << i->second->Style;
				else registerOptions_function << ", EMPTY";
				if(i->second->Width != "") registerOptions_function << ", " << i->second->Width;
				else registerOptions_function << ", EMPTY";
				if(i->second->Color != "") registerOptions_function << ", " << i->second->Color;
				else registerOptions_function << ", clrNONE";
				registerOptions_function << " );";
			}
			registerOptions_function << "\n";
		}
	}
	else {
		this->scriptType = 1;
	}

	if(this->scriptType == 1)
		registerOptions_function << "\n   StrategyShortName(\"\");\n";
	else if(this->scriptType == 2)
		registerOptions_function << "\n   IndicatorShortName(\"\");\n";

	if(this->scriptType == 1)
	{
		registerOptions_function << "   StrategyDescription(\"\");\n\n";
	}

	if(prop_lvl_style_set)
	{
		registerOptions_function << "   SetLevelStyle(" << level_style << ", "
			<< level_width << ", " << level_color << ");\n";
	}

	registerOptions_function << property_levels_funcs.str();

	if(prop_min_max_set)
	{
		registerOptions_function << "   SetFixedMinMaxValues(" << indicator_minimum << ", "
			<< indicator_maximum << ");\n";
	}

	registerOptions_function << property_label_funcs.str();

	registerOptions_function << "}";

	if(this->err_type != ErrorType::None) scriptType = -1;

	*to << registerOptions_function.str();

	// Close namespace mql4
	*to << "\n\n}";
	*head << "\n\n}";

	WriteEPTypes();
}

void Listener::enterUnit(GrammarParser::UnitContext * ctx)
{
}

void Listener::exitUnit(GrammarParser::UnitContext * ctx)
{
}

void Listener::enterAppend_scope(GrammarParser::Append_scopeContext * ctx)
{
	if (isOutputTraverse)
	{
		auto spaces = ctx->space();
		for (auto i = spaces.begin(); i != spaces.end(); i++)
		{
			*to << (*i)->getText();
		}
	}
}

void Listener::exitAppend_scope(GrammarParser::Append_scopeContext * ctx)
{
}

void Listener::enterFunction_scope(GrammarParser::Function_scopeContext * ctx)
{
	this->scope_level++;

	if (isOutputTraverse)
	{
		*to << "{";

		if (!isStrict && isInsideFunctionScope() && scope_level == 1)
		{
			if (function_variables.find(outer_definition_name) != function_variables.end())
			{
				auto ls_ptr = function_variables[outer_definition_name];
				*to << "\n";
				for (auto i = ls_ptr->begin(); i != ls_ptr->end(); i++)
				{
					multivar_decl = *i;
					VariableDeclaration* decl = multivar_decl->GetDeclaration();

					while (decl != nullptr)
					{
						*to << getPadding(false);

						if (decl->IsArray())
						{
							if (!GenerateTIndexBufferDecl(decl))
							{
								stringstream ss;

								GenerateArrayType(ss, decl);

								if (multivar_decl->IsReference()) ss << "& " << VariableDeclaration::PrefixedVarName(decl->Name());
								else {
									ss << VariableDeclaration::PrefixedVarName(decl->Name());
									GenerateArrayArguments(ss, decl);
								}

								*to << ss.str();
							}

						}
						else {
							*to << multivar_decl->Type();
							*to << " " << VariableDeclaration::PrefixedVarName(decl->Name());

							if (!decl->HasInitializer() && IsArithmeticType(multivar_decl->Type()))
								*to << "{}";

							if (decl->HasInitializer())
							{
								*to << decl->GetInitializer();
							}
						}

						delete decl;
						decl = multivar_decl->GetDeclaration();

						*to << ";\n";
					}
				}
			}
		}
	}
}

void Listener::exitFunction_scope(GrammarParser::Function_scopeContext * ctx)
{
    if (isInsideFunctionScope() && scope_level == 1)
    {
        isVarNameAndEnumItemTheSame = false;
    }

	this->scope_level--;

	if (isOutputTraverse)
		*to << "}";
}

void Listener::enterScope_content(GrammarParser::Scope_contentContext * ctx)
{
	if (isOutputTraverse) 
	{
		if (ctx->space())
		{
			*to << ctx->getText();
		}
        else if (ctx->color_litteral())
        {
            *to << GenerateColorLiteral(ctx->color_litteral()->rgb_litteral());
        }
	}

}

void Listener::exitScope_content(GrammarParser::Scope_contentContext * ctx)
{
}

void Listener::enterReturn_statement(GrammarParser::Return_statementContext * ctx)
{
}

void Listener::exitReturn_statement(GrammarParser::Return_statementContext * ctx)
{
}


void Listener::enterVoid_return(GrammarParser::Void_returnContext * ctx)
{
	if (isOutputTraverse && isInsideFunctionScope())
	{
		if (outer_type_name != "void") {

			if (isStrict)
			{
				cout << "\n   (error): ";
				this->err_type = ErrorType::ReturnValueNotSpecified;
				*to << ctx->K_RETURN()->getText() << ";";
			}
			else {
				cout << "\n   (warning): ";

				*to << ctx->K_RETURN()->getText() << " ";

				if (outer_type_name == "string") {
					*to << "\"\"";
				}
				else if (
					outer_type_name == "int"
					|| outer_type_name == "uint"
					|| outer_type_name == "long"
					|| outer_type_name == "ulong"
					|| outer_type_name == "short"
					|| outer_type_name == "ushort"
					|| outer_type_name == "char"
					|| outer_type_name == "uchar")
				{
					*to << "0";
				}
				else if (
					outer_type_name == "double"
					|| outer_type_name == "float")
				{
					*to << "0.0";
				}
				else if (outer_type_name == "bool")
				{
					*to << "false";
				}
				else {
					*to << this->outer_type_name << "()";
				}
				*to << ";";
			}

			cout << "Function " << this->outer_definition_name << " must return a value.";
		}
		else {
			*to << ctx->getText();
		}
	}
}

void Listener::exitVoid_return(GrammarParser::Void_returnContext * ctx)
{
}

void Listener::enterStandart_return(GrammarParser::Standart_returnContext * ctx)
{
	if (isOutputTraverse && isInsideFunctionScope())
	{
		if (outer_type_name == "void") {

			if (isStrict)
			{
				cout << "\n   (error): ";
				this->err_type = ErrorType::ReturnValueNotSpecified;
			}
			else {
				cout << "\n   (warning): ";
			}
			*to << ctx->K_RETURN()->getText() << " ";
			
			SetBuffer();

			cout << "Error in function " << this->outer_definition_name << ": \'void\' function returns a value";
		}
		else {
			*to << ctx->K_RETURN()->getText() << " ";
		}
	}
}

void Listener::exitStandart_return(GrammarParser::Standart_returnContext * ctx)
{
	if (isOutputTraverse && isInsideFunctionScope())
	{
		if (outer_type_name == "void") {
			ResetBuffer();
		}
		*to << ";";
	}
}

void Listener::enterFor_loop(GrammarParser::For_loopContext * ctx)
{
	insideForLoop = true;

	bool nonStrictVar = !isStrict && notException;

	if (isOutputTraverse || nonStrictVar)
	{
		
		multivar_decl = new MultivariableDeclaration();
		if (isOutputTraverse)
			*to << "for(";
	}
}

void Listener::exitFor_loop(GrammarParser::For_loopContext * ctx)
{
	insideForLoop = false;

	if (isOutputTraverse)
	{
		*to << ")";

		if (multivar_decl != nullptr)
		{
			delete multivar_decl;
			multivar_decl = nullptr;
		}
	}
}

void Listener::enterFor_loop_declaration(GrammarParser::For_loop_declarationContext * ctx)
{
}

void Listener::exitFor_loop_declaration(GrammarParser::For_loop_declarationContext * ctx)
{
}

void Listener::enterFor_loop_variable_decl(GrammarParser::For_loop_variable_declContext * ctx)
{
}

void Listener::exitFor_loop_variable_decl(GrammarParser::For_loop_variable_declContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << ";";
	}
}

void Listener::enterFor_loop_condition(GrammarParser::For_loop_conditionContext * ctx)
{
}

void Listener::exitFor_loop_condition(GrammarParser::For_loop_conditionContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << ";";
	}
}

void Listener::enterFor_loop_increment(GrammarParser::For_loop_incrementContext * ctx)
{
}

void Listener::exitFor_loop_increment(GrammarParser::For_loop_incrementContext * ctx)
{
}

void Listener::enterFor_loop_append_increment(GrammarParser::For_loop_append_incrementContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << ", ";
	}
}

void Listener::exitFor_loop_append_increment(GrammarParser::For_loop_append_incrementContext * ctx)
{
}

void Listener::enterRvalue(GrammarParser::RvalueContext * ctx)
{
    if (isOutputTraverse /*!isStrict && isInsideFunctionScope() && notException*/)
    {
        if (ctx->name())
        {
            const string name = ctx->name()->getText();
            if (IsEnumConstant(name))
            {
                *to << (isVarNameAndEnumItemTheSame ? VariableDeclaration::CheckVarName(name, isOnCalculate()) : name);
            }
            else
            {
                *to << VariableDeclaration::CheckVarName(name, isOnCalculate());
            }
        }
        else if (ctx->no_parant_comma_sc())
        {
            *to << ctx->no_parant_comma_sc()->getText();
        }
        else if (ctx->color_litteral())
        {
            *to << GenerateColorLiteral(ctx->color_litteral()->rgb_litteral());
        }
    }
}

void Listener::exitRvalue(GrammarParser::RvalueContext * ctx)
{
}

void Listener::enterParantheses_content(GrammarParser::Parantheses_contentContext * ctx)
{
}

void Listener::exitParantheses_content(GrammarParser::Parantheses_contentContext * ctx)
{
}

void Listener::enterParantheses_content_expression(GrammarParser::Parantheses_content_expressionContext * ctx)
{
	if (isOutputTraverse)
	{
		if (ctx->no_parant_sc())
			*to << ctx->no_parant_sc()->getText();
	}
}

void Listener::exitParantheses_content_expression(GrammarParser::Parantheses_content_expressionContext * ctx)
{
}

void Listener::enterNo_parant_comma_sc(GrammarParser::No_parant_comma_scContext * ctx)
{
}

void Listener::exitNo_parant_comma_sc(GrammarParser::No_parant_comma_scContext * ctx)
{
}

void Listener::enterArgument_content(GrammarParser::Argument_contentContext * ctx)
{
	if (isOutputTraverse) {
		if (ctx->space())
		{
			*to << ctx->getText();
		}
		else if (ctx->name())
		{
			*to << VariableDeclaration::CheckVarName(ctx->name()->getText(), isOnCalculate());
		}
	}
}

void Listener::exitArgument_content(GrammarParser::Argument_contentContext * ctx)
{
}

void Listener::enterCommented_block(GrammarParser::Commented_blockContext * ctx)
{
	if (isOutputTraverse)
	{
		if (!( ctx->tryblock_replacement_end() || ctx->tryblock_replacement_end() ))
		{
			*to << ctx->getText();
		}
	}
}

void Listener::exitCommented_block(GrammarParser::Commented_blockContext * ctx)
{
}

void Listener::enterFunction_call(GrammarParser::Function_callContext * ctx)
{
	if (isOutputTraverse) 
	{
		if (
			ctx->return_datetime() ||
			ctx->set_level_style()
			)
		{
			*to << ctx->getText();
		}
	}
}

void Listener::exitFunction_call(GrammarParser::Function_callContext * ctx)
{
}

void Listener::enterAny_function_call(GrammarParser::Any_function_callContext * ctx)
{
	if (isOutputTraverse)
	{
        *to << ctx->name()->getText();
	}
}

void Listener::exitAny_function_call(GrammarParser::Any_function_callContext * ctx)
{
}

void Listener::enterAny_fcall_parantheses_expr(GrammarParser::Any_fcall_parantheses_exprContext * ctx)
{
    if (isOutputTraverse)
    {
        *to << "(";
    }
}

void Listener::exitAny_fcall_parantheses_expr(GrammarParser::Any_fcall_parantheses_exprContext * ctx)
{
    if (isOutputTraverse)
    {
        *to << ")";
    }
}

void Listener::enterAny_fcall_parantheses_content(GrammarParser::Any_fcall_parantheses_contentContext * ctx)
{
}

void Listener::exitAny_fcall_parantheses_content(GrammarParser::Any_fcall_parantheses_contentContext * ctx)
{
}

void Listener::enterAny_fcall_append_argument(GrammarParser::Any_fcall_append_argumentContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << ",";
	}
}

void Listener::exitAny_fcall_append_argument(GrammarParser::Any_fcall_append_argumentContext * ctx)
{
}

void Listener::enterEntry_point(GrammarParser::Entry_pointContext * ctx)
{
	if (this->isOutputTraverse)
	{
		if (!(
			ctx->on_calculate_handler()
			))
		{
			*to << ctx->getText();
		}
	}
}

void Listener::exitEntry_point(GrammarParser::Entry_pointContext * ctx)
{
}

void Listener::enterSingle_name(GrammarParser::Single_nameContext * ctx)
{
	if(isOutputTraverse)
	{
		*to << ctx->getText();

		if(ctx->STRATEGY_ONLY())
		{
			StrategyScript(ctx->STRATEGY_ONLY()->getText());
		}
		if(ctx->INDICATORS_ONLY())
		{
			IndicatorScript(ctx->INDICATORS_ONLY()->getText());
		}
		if(ctx->HOOKING_FUNCS())
		{
			hooking_funcs_present = true;
		}
		if(ctx->ON_TIMER())
		{
			on_timer = true;
		}
	}
}

void Listener::exitSingle_name(GrammarParser::Single_nameContext * ctx)
{
}

void Listener::enterDatetime_litteral(GrammarParser::Datetime_litteralContext * ctx)
{
	if (isOutputTraverse)
	{
		if (ctx->time_litteral())
		{
			time_t t_sec = time(NULL);
			tm* loc = localtime(&t_sec);

			*to << "datetime(" << loc->tm_year + 1900 << ", " << loc->tm_mon + 1 << ", " << loc->tm_mday << ", ";
		}
		else if (ctx->date_litteral())
		{
			*to << "datetime(";
		}
		else {
			*to << "__DATETIME__";
			this->generateCompileDT = true;
		}
	}
}

void Listener::exitDatetime_litteral(GrammarParser::Datetime_litteralContext * ctx)
{
	if (isOutputTraverse)
	{
		if (ctx->time_litteral() || ctx->date_litteral())
			*to << ")";
	}
}

void Listener::enterAppend_time_litteral(GrammarParser::Append_time_litteralContext * ctx)
{
	if (isOutputTraverse)
		*to << ", ";
}

void Listener::exitAppend_time_litteral(GrammarParser::Append_time_litteralContext * ctx)
{
}

void Listener::enterDate_litteral(GrammarParser::Date_litteralContext * ctx)
{
	if (isOutputTraverse)
	{
        string str1 = ctx->DATE_LITERAL()->getText();
        string str2 = str1;
        string str3 = str1;

        str1 = str1.substr(0, str1.find_first_of('.'));
        str2 = str2.substr(str1.length() + 1, str2.find_first_of('.', str1.length() + 1) - str1.length() - 1);
        str3 = str3.substr(str3.find_last_of('.') + 1);

		str1.erase(0, str1.find_first_not_of('0'));
		if (str1.empty()) str1 = "0";
		str2.erase(0, str2.find_first_not_of('0'));
		if (str2.empty()) str2 = "0";
		str3.erase(0, str3.find_first_not_of('0'));
		if (str3.empty()) str3 = "0";


		int len1 = str1.length();
		int len2 = str2.length();
		int len3 = str3.length();

		if ((len1 != 4 && len3 != 4) || (len1 > 2 && len3 > 2) || len2 > 2)
			cout << "\n   (warning): Wrong date format at '" << ctx->getText() << "'";

		if (len1 > len3)
		{
			*to << str1 << ", " << str2 << ", " << str3;
		}
		else
		{
			*to << str3 << ", " << str2 << ", " << str1;
		}
	}
}

void Listener::exitDate_litteral(GrammarParser::Date_litteralContext * ctx)
{
}

void Listener::enterTime_litteral(GrammarParser::Time_litteralContext * ctx)
{
	if (isOutputTraverse)
	{
		const string warning_msg = "\n(warning) : Wrong time format at '" + ctx->getText() + "'";

		string hour = ctx->INTEGER(0)->getText();
		hour.erase(0, hour.find_first_not_of('0'));
		if (hour.empty()) {
			hour = "0";
		}
		if (hour.length() > 2) cout << warning_msg;
		*to << hour;

		*to << ", ";
		auto ptr = ctx->INTEGER(1);
		if (ptr)
		{
			string min = ptr->getText();
			min.erase(0, min.find_first_not_of('0'));
			if (min.empty()) {
				min = "0";
			}
			if (min.length() > 2) cout << warning_msg;
			*to << min;
		}
		else {
			*to << "0";
		}

		*to << ", ";
		ptr = ctx->INTEGER(2);
		if (ptr)
		{
			string sec = ptr->getText();
			sec.erase(0, sec.find_first_not_of('0'));
			if (sec.empty()) {
				sec = "0";
			}
			if (sec.length() > 2) cout << warning_msg;
			*to << sec;
		}
		else {
			*to << "0";
		}
	}
}

void Listener::exitTime_litteral(GrammarParser::Time_litteralContext * ctx)
{
}

void Listener::enterColor_litteral(GrammarParser::Color_litteralContext *ctx)
{
}

void Listener::exitColor_litteral(GrammarParser::Color_litteralContext *ctx)
{
}

void Listener::enterRgb_litteral(GrammarParser::Rgb_litteralContext *ctx)
{
}

void Listener::exitRgb_litteral(GrammarParser::Rgb_litteralContext *ctx)
{
}

void Listener::enterHex_or_regular_integer(GrammarParser::Hex_or_regular_integerContext * ctx)
{
}

void Listener::exitHex_or_regular_integer(GrammarParser::Hex_or_regular_integerContext * ctx)
{
}

void Listener::enterSq_arguments(GrammarParser::Sq_argumentsContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << "[";
	}
}

void Listener::exitSq_arguments(GrammarParser::Sq_argumentsContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << "]";
	}
}

void Listener::enterSq_content(GrammarParser::Sq_contentContext * ctx)
{
}

void Listener::exitSq_content(GrammarParser::Sq_contentContext * ctx)
{
}

void Listener::enterAppend_sq_content(GrammarParser::Append_sq_contentContext * ctx)
{
	if (isOutputTraverse)
		if (ctx->COMMA()) *to << "][";
}

void Listener::exitAppend_sq_content(GrammarParser::Append_sq_contentContext * ctx)
{
}

void Listener::enterSq_brackets_argument(GrammarParser::Sq_brackets_argumentContext * ctx)
{
}

void Listener::exitSq_brackets_argument(GrammarParser::Sq_brackets_argumentContext * ctx)
{
}

void Listener::enterSq_brackets_anyrule(GrammarParser::Sq_brackets_anyruleContext * ctx)
{
	if (isOutputTraverse)
		if (ctx->no_comma_sq_br()) *to << ctx->no_comma_sq_br()->getText();
}

void Listener::exitSq_brackets_anyrule(GrammarParser::Sq_brackets_anyruleContext * ctx)
{
}

void Listener::enterStr(GrammarParser::StrContext * ctx)
{
}

void Listener::exitStr(GrammarParser::StrContext * ctx)
{
}

void Listener::enterDirective(GrammarParser::DirectiveContext * ctx)
{
	if (isOutputTraverse)
		*to << ctx->getText();
}

void Listener::exitDirective(GrammarParser::DirectiveContext * ctx)
{

}

void Listener::enterProperty(GrammarParser::PropertyContext *ctx) 
{

	if (isOutputTraverse)
		*to << "//" << ctx->getText();
}

void Listener::exitProperty(GrammarParser::PropertyContext *ctx) 
{
}

void Listener::enterProperty_content(GrammarParser::Property_contentContext *ctx) 
{
	if (isOutputTraverse) 
	{
		if (ctx->INDICATOR_BUFFERS())
        {
			IndicatorScript(ctx->INDICATOR_BUFFERS()->getText());
		}
		else if (ctx->INDICATOR_CHART_WINDOW())
		{
            IndicatorScript(ctx->INDICATOR_CHART_WINDOW()->getText());
			registerOptions_function << "\n   SetOutputWindow(ow_ChartWindow );\n";
		}
		else if (ctx->INDICATOR_SEPARATE_WINDOW())
		{
            IndicatorScript(ctx->INDICATOR_SEPARATE_WINDOW()->getText());
			registerOptions_function << "\n   SetOutputWindow(ow_SeparateWindow );\n";
		}
	}
	else {
		if (ctx->K_STRICT()) {
			this->isStrict = true;
		}
		if(ctx->INDICATOR_BUFFERS() && ctx->INTEGER())
		{
			visible_ind_buffs = stoi(ctx->INTEGER()->getText());
		}
	}
}
void Listener::exitProperty_content(GrammarParser::Property_contentContext *ctx) 
{

}

void Listener::enterProperty_style_definition(GrammarParser::Property_style_definitionContext * ctx)
{
	string prop = ctx->name(0)->getText();

	if (prop.substr(0, 10) == "indicator_") {
		this->indicator_definitions = true;

		string styletype = prop.substr(10, 4);
		bool istype = false;
		if (styletype == "type") {
			istype = true;
		}
		else{
			styletype = prop.substr(10, 5);
		}

		int id = 0;
		if(styletype == "level")
		{
			if(!(prop[15] >= '0' && prop[15] <= '9'))
			{
				styletype = prop.substr(10, 10);
			}
		}
		else if(styletype == "minim" || styletype == "maxim")
		{
			styletype = prop.substr(10, 7);
		}
		else
		{
			string styleidx = istype ? prop.replace(0, 14, "") : prop.replace(0, 15, "");
			stringstream idx_ss;
			idx_ss << styleidx;
			idx_ss >> id;
			id--;
			if(this->stylesToAdd.find(id) == this->stylesToAdd.end())
				this->stylesToAdd[id] = new PropertyStyle();
		}

		if (istype)
		{
			if (ctx->hex_or_regular_integer())
			{
				this->stylesToAdd[id]->Type = "(ENUM_DRAW_STYLE)" + ctx->hex_or_regular_integer()->getText();
			}
			else {
				this->stylesToAdd[id]->Type = ctx->name(1)->getText();
			}
		}
		else if (styletype == "color") 
		{
            string color_value;
            if (ctx->name(1))
            {
                color_value = ctx->name(1)->getText();
                if (color_value.length() >= 3)
                {
                    string sub = color_value.substr(0, 3);
                    if (sub != "clr") color_value = "clr" + color_value;
                }
            }
            else {
                color_value = ctx->hex_or_regular_integer()->getText();
            }

			this->stylesToAdd[id]->Color = color_value;
			if (isOutputTraverse)
			{
				*to << "\n#define " << ctx->name(0)->getText() << " " << color_value << "\n";
			}
		}
		else if (styletype == "width") 
		{
			this->stylesToAdd[id]->Width = ctx->hex_or_regular_integer()->getText();
		}
		else if (styletype == "style") 
		{
			if (ctx->hex_or_regular_integer()) {
				this->stylesToAdd[id]->Style = "(ENUM_LINE_STYLE)" + ctx->hex_or_regular_integer()->getText();
			}
			else {
				this->stylesToAdd[id]->Style = ctx->name(1)->getText();
			}
		}
		else if(styletype == "level")
		{
			string d = ctx->hex_or_regular_integer() ? ctx->hex_or_regular_integer()->getText()
                                                     : ctx->float_value()->getText();
			if (!isOutputTraverse)
			{
				property_levels_funcs << "   SetLevelValue(" << id << ", " << d << ");\n";
			}
			else
			{
				*to << "\n#define " << ctx->name(0)->getText() << " " << d << "\n";
			}
		}
		else if(styletype == "levelstyle")
		{
			prop_lvl_style_set = true;
			if(ctx->hex_or_regular_integer())
			{
				level_style.replace(0, level_style.size(), "(ENUM_LINE_STYLE)" + ctx->hex_or_regular_integer()->getText());
			}
			else
			{
				level_style.replace(0, level_style.size(), ctx->name(1)->getText());
			}
		}
		else if(styletype == "levelwidth")
		{
			prop_lvl_style_set = true;
			level_width.replace(0, level_width.size(), ctx->hex_or_regular_integer()->getText());
		}
		else if(styletype == "levelcolor")
		{
			prop_lvl_style_set = true;
			string text = ctx->name(1)->getText();
			if(text.length() >= 3)
			{
				string sub = text.substr(0, 3);
				if(sub != string("clr")) text = "clr" + text;
			}

			level_color.replace(0, level_color.size(), text);
		}
		else if(styletype == "maximum")
		{
			prop_min_max_set = true;
			string d = ctx->hex_or_regular_integer() ? ctx->hex_or_regular_integer()->getText()
                                                     : ctx->float_value()->getText();
			indicator_maximum.replace(0, indicator_maximum.size(), d);
		}
		else if(styletype == "minimum")
		{
			prop_min_max_set = true;
			string d = ctx->hex_or_regular_integer() ? ctx->hex_or_regular_integer()->getText()
                                                     : ctx->float_value()->getText();
			indicator_minimum.replace(0, indicator_minimum.size(), d);
		}
		else if(styletype == "label" && !isOutputTraverse)
		{
			property_label_funcs << "   SetIndexLabel(" << id << ", " << ctx->str()->getText() << ");\n";
		}
	}
}

void Listener::exitProperty_style_definition(GrammarParser::Property_style_definitionContext * ctx)
{
}

string multi_assignment_name;

void Listener::enterVariable_change_value_assignment(GrammarParser::Variable_change_value_assignmentContext * ctx)
{
	if (isOutputTraverse)
	{
		multi_assignment_name = ctx->subscript_operator()->getText();

		VariableDeclaration::CheckVarName(multi_assignment_name, assigned_type);
		notException = false;
	}
}

void Listener::exitVariable_change_value_assignment(GrammarParser::Variable_change_value_assignmentContext * ctx)
{
	if (isOutputTraverse)
	{
		notException = true;

		if (ctx->SC())
			*to << ";";
	}
}

void Listener::enterVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext * ctx)
{
}

void Listener::exitVariable_change_value_name_fist(GrammarParser::Variable_change_value_name_fistContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << " " << ctx->unary_operator()->getText();
	}
}

void Listener::enterVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext * ctx)
{
	if (isOutputTraverse) 
	{
		*to << ctx->unary_operator()->getText() << " "; 
	}
}

void Listener::exitVariable_change_value_name_last(GrammarParser::Variable_change_value_name_lastContext * ctx)
{
}

void Listener::enterSubscript_operator(GrammarParser::Subscript_operatorContext * ctx)
{
	if (isOutputTraverse)
	{
		if (notException)
		{
			bool sub = ctx->sq_arguments();
			*to << VariableDeclaration::CheckVarName(ctx->name()->getText(), isOnCalculate() && !sub);
		}
		else {
			*to << VariableDeclaration::CheckVarName(ctx->name()->getText(), assigned_type, isOnCalculate());
		}
	}
}

void Listener::exitSubscript_operator(GrammarParser::Subscript_operatorContext * ctx)
{
}

void Listener::enterMulti_assignment(GrammarParser::Multi_assignmentContext * ctx)
{
	if (isOutputTraverse)
	{
		if (ctx->subscript_operator())
		{
			multi_assignment_name = ctx->subscript_operator()->getText();
			*to << ctx->asssignment_operator()->getText();// << implicit_cast;
		}
		else
		{
			multi_assignment_name = "";
			*to << ctx->asssignment_operator()->getText(); // << implicit_cast;
		}
	}
}

void Listener::exitMulti_assignment(GrammarParser::Multi_assignmentContext * ctx)
{
}

void Listener::enterLast_multi_assignment_rvalue(GrammarParser::Last_multi_assignment_rvalueContext *ctx) 
{
    if (isOutputTraverse)
    {
        setImplicitCast();

        if (ctx->subscript_operator())
        {
            multi_assignment_name = ctx->subscript_operator()->getText();
            *to << ctx->asssignment_operator()->getText() << implicit_cast;
        }
        else
        {
            multi_assignment_name = "";
            *to << ctx->asssignment_operator()->getText() << implicit_cast;
        }
    }
}

void Listener::exitLast_multi_assignment_rvalue(GrammarParser::Last_multi_assignment_rvalueContext *ctx)
{
    if (isOutputTraverse)
    {
        if (implicit_cast != " ")
        {
            *to << ")";
        }
    }
}

void Listener::enterExpression(GrammarParser::ExpressionContext * ctx)
{
    if (isOutputTraverse)
    {
        if (ctx->OP_PARETHESES())  *to << "(";
        if (ctx->OP_BR())          *to << "[";
    }
}

void Listener::exitExpression(GrammarParser::ExpressionContext * ctx)
{
    if (isOutputTraverse)
    {
        if (ctx->CL_PARETHESES())  *to << ")";
        if (ctx->CL_BR())          *to << "]";
        if (ctx->unary_operator()) *to << ctx->unary_operator()->getText();
    }
}

void Listener::enterOp_expr(GrammarParser::Op_exprContext *ctx)
{
    if (isOutputTraverse && ctx->binary_operator())
        *to << ctx->binary_operator()->getText();
}

void Listener::exitOp_expr(GrammarParser::Op_exprContext *ctx)
{
}

void Listener::enterBinary_operator(GrammarParser::Binary_operatorContext * ctx)
{
}

void Listener::exitBinary_operator(GrammarParser::Binary_operatorContext * ctx)
{
}

void Listener::enterUnary_operator(GrammarParser::Unary_operatorContext * ctx)
{
}

void Listener::exitUnary_operator(GrammarParser::Unary_operatorContext * ctx)
{
}

void Listener::enterSingle_expr_space(GrammarParser::Single_expr_spaceContext *ctx)
{
    if (isOutputTraverse && ctx->OP_PARETHESES())
        *to << "(";
}

void Listener::exitSingle_expr_space(GrammarParser::Single_expr_spaceContext *ctx)
{
    if (isOutputTraverse && ctx->CL_PARETHESES())
        *to << ")";
}

void Listener::enterSingle_expr(GrammarParser::Single_exprContext * ctx)
{
    if (isOutputTraverse)
    {
        if (ctx->name())
            *to << VariableDeclaration::CheckVarName(ctx->name()->getText(), isOnCalculate());
        else if (!ctx->sq_arguments())
            *to << ctx->getText();
    }
}

void Listener::exitSingle_expr(GrammarParser::Single_exprContext * ctx)
{
}

void Listener::enterAsssignment_operator(GrammarParser::Asssignment_operatorContext * ctx)
{
}

void Listener::exitAsssignment_operator(GrammarParser::Asssignment_operatorContext * ctx)
{
}

void Listener::enterEnum_extract2header(GrammarParser::Enum_extract2headerContext * ctx)
{
	if (isOutputTraverse)
	{		
		const string name = ctx->enum_declaration()->NAME()->getText();
		
		// Header part
		*head << "\n";
		
		*head << "class " << name << " : public MqlEnum\n";
		*head << "{\npublic:\n";
		*head << "\t" << name << "() : MqlEnum() { m_ep = &m_elems; }\n";
		*head << "\t" << name << "(int v) { m_ep = &m_elems; SetVal(v); }\n\n";
		*head << "\t" << name << "& operator=(int v) { SetVal(v); return *this; }\n";
		*head << "\tstatic std::vector<Element> m_elems;\n};\n\n";

		std::vector<GrammarParser::Enum_itemContext*> items = ctx->enum_declaration()->enum_item_list()->enum_item();

		for(int i = 0, e = 0; i < (int)items.size(); ++i, ++e)
		{
			if(items[i]->INTEGER())
			{
				e = stoi(items[i]->INTEGER()->getText());
			}
			
			*head << "constexpr const int " << items[i]->NAME()->getText() << " = " << e << ";\n";
            enum_constants.insert(items[i]->getText());
		}

		*head << endl;
		
		// Cpp part
		*to << "std::vector<MqlEnum::Element> " << name << "::m_elems\n";
		*to << "{\n";

		for(int i = 0, e = 0; i < (int)items.size(); ++i, ++e)
		{
			if(items[i]->INTEGER())
			{
				e = stoi(items[i]->INTEGER()->getText());
			}

			*to << "\tMqlEnum::Element(" << e << ", \"" << items[i]->NAME()->getText() << "\"),\n";
		}

		*to << "};\n\n";
	}
}

void Listener::exitEnum_extract2header(GrammarParser::Enum_extract2headerContext * ctx)
{
}

void Listener::enterEnum_declaration(GrammarParser::Enum_declarationContext * ctx)
{
}

void Listener::exitEnum_declaration(GrammarParser::Enum_declarationContext * ctx)
{
}

void Listener::enterEnum_item_list(GrammarParser::Enum_item_listContext * ctx)
{
}

void Listener::exitEnum_item_list(GrammarParser::Enum_item_listContext * ctx)
{
}

void Listener::enterEnum_item(GrammarParser::Enum_itemContext * ctx)
{
}

void Listener::exitEnum_item(GrammarParser::Enum_itemContext * ctx)
{
}

void Listener::enterVariable_change_value(GrammarParser::Variable_change_valueContext * ctx)
{
	if (isOutputTraverse && scope_level == 0)
		SetBuffer();
}

void Listener::exitVariable_change_value(GrammarParser::Variable_change_valueContext * ctx)
{
	if (isOutputTraverse && scope_level == 0)
		ResetBuffer();
}

void Listener::enterAdd_brackets(GrammarParser::Add_bracketsContext *ctx)
{
	if (isOutputTraverse) {
		*to << ctx->ADD_BRACKETS_FUNCTIONS()->getText();
		*to << "(";
	}
}

void Listener::exitAdd_brackets(GrammarParser::Add_bracketsContext *ctx) 
{
	if (isOutputTraverse) {
		*to << ")";
	}
}

void Listener::enterChange_brackets(GrammarParser::Change_bracketsContext *ctx) 
{
	if (isOutputTraverse) {
		string name = ctx->CHANGE_BRACKETS_FUNCTIONS()->getText();
		*to << name;
		*to << "( ";
	}
}

void Listener::exitChange_brackets(GrammarParser::Change_bracketsContext *ctx) 
{
	if (isOutputTraverse)
	{
		*to << ") ";
	}
}

void Listener::enterUnsupported_object_types(GrammarParser::Unsupported_object_typesContext *ctx)
{
    static unordered_set<string> unsupported_obj;
    if (unsupported_obj.insert(ctx->UNSUPPORTED_OBJECTS()->getText()).second)
    {
        cout << "\n   (warning): Object type " << ctx->UNSUPPORTED_OBJECTS()->getText()
             << " is not supported in Forex Tester.";
    }
}

void Listener::exitUnsupported_object_types(GrammarParser::Unsupported_object_typesContext *ctx)
{
}

void Listener::enterUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext* ctx)
{
    static unordered_set<string> unsupported_prop;
    if (unsupported_prop.insert(ctx->UNSUPPORTED_PROPERTIES()->getText()).second)
    {
        cout << "\n   (warning): Object property " << ctx->UNSUPPORTED_PROPERTIES()->getText()
             << " is not supported in Forex Tester.";
    }
}

void Listener::exitUnsupported_object_properties(GrammarParser::Unsupported_object_propertiesContext* ctx)
{
}

void Listener::enterReturn_datetime(GrammarParser::Return_datetimeContext* ctx)
{
}

void Listener::exitReturn_datetime(GrammarParser::Return_datetimeContext* ctx)
{
}

void Listener::enterIndicator_buffers_func(GrammarParser::Indicator_buffers_funcContext* ctx)
{
	if (isOutputTraverse)
	{
		if(visible_ind_buffs > 0)
		{
			*to << "//";
		}
		else
		{
			visible_ind_buffs = stoi(ctx->INTEGER()->getText());
		}

		*to << ctx->getText();
	}
}

void Listener::exitIndicator_buffers_func(GrammarParser::Indicator_buffers_funcContext* ctx) {}

void Listener::enterArg_comma(GrammarParser::Arg_commaContext * ctx)
{
}

void Listener::exitArg_comma(GrammarParser::Arg_commaContext * ctx)
{
}

void Listener::enterParantheses_any_expression(GrammarParser::Parantheses_any_expressionContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << "(";
	}	
} 

void Listener::exitParantheses_any_expression(GrammarParser::Parantheses_any_expressionContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << ")";
	}
}

void Listener::enterNo_parant_sc(GrammarParser::No_parant_scContext * ctx)
{
}

void Listener::exitNo_parant_sc(GrammarParser::No_parant_scContext * ctx)
{
}

void Listener::enterModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext * ctx)
{
	// Used both in primary and output traverse
	bool nonStrictVar = !isStrict && notException;

	if (isOutputTraverse || nonStrictVar)
	{
		notException = !ctx->K_STATIC();

		multivar_decl = new MultivariableDeclaration();

		if (ctx->K_STATIC()) multivar_decl->Modifier(ModifierType::M_STATIC);
		else if (ctx->EXTERN()) multivar_decl->Modifier(ModifierType::M_EXTERN);
		else if (ctx->INPUT()) multivar_decl->Modifier(ModifierType::M_INPUT);
	}
}

void Listener::exitModifier_variable_declaration(GrammarParser::Modifier_variable_declarationContext * ctx)
{
	if (isOutputTraverse)
	{
		if (multivar_decl != nullptr)
		{
			delete multivar_decl;
			multivar_decl = nullptr;
		}
	}
	notException = true;
}

void Listener::InitializeDeclaration(GrammarParser::Variable_declarationContext * ctx)
{
	multivar_decl->IsConst((bool)ctx->K_CONST());

	multivar_decl->Type(ctx->type()->getText());
	multivar_decl->NextDeclaration()->SetName(ctx->name()->getText());

	if (ctx->AMPERSAND())
		multivar_decl->IsReference(true);
	else multivar_decl->IsReference(false);
}

void Listener::enterVariable_declaration(GrammarParser::Variable_declarationContext * ctx)
{
	bool nonStrictVar = !isStrict && notException;

	if (isOutputTraverse)
	{
		VariableDeclaration::CheckVarName(ctx->name()->getText(), assigned_type);
		
		InitializeDeclaration(ctx);
	}
	else
	{
		if (nonStrictVar)
		{
			if (multivar_decl->Modifier() == ModifierType::M_FUNC_ARG)
			{
				InitializeDeclaration(ctx);
			}
			else
			{

				list<MultivariableDeclaration*>* vars;
				if (function_variables.find(this->outer_definition_name) == function_variables.end()) {
					vars = new list<MultivariableDeclaration*>();
					function_variables.insert(pair<string, list<MultivariableDeclaration*>*>(this->outer_definition_name, vars));
				}
				else
				{
					vars = function_variables[this->outer_definition_name];
				}

				InitializeDeclaration(ctx);
				vars->push_back(multivar_decl);
			}
		}
	}
}

void Listener::exitVariable_declaration(GrammarParser::Variable_declarationContext * ctx)
{	
	if (isOutputTraverse)
	{
		GenerateDeclaration();
	}
	else
	{		
		last_var_type = Other;

		if(ctx->type()->type_name(0)->K_UNSIGNED())
		{
			if(ctx->type()->type_name(1)->T_INT())
			{
				last_var_type = UInt;
			}
			else if(ctx->type()->type_name(1)->T_LONG())
			{
				last_var_type = ULong;
			}
			else if(ctx->type()->type_name(1)->T_SHORT())
			{
				last_var_type = UShort;
			}
			else if(ctx->type()->type_name(1)->T_CHAR())
			{
				last_var_type = UChar;
			}
		}
		else if(ctx->type()->type_name(0)->T_INT())
		{
			last_var_type = Int;
		}
		else if(ctx->type()->type_name(0)->T_LONG())
		{
			last_var_type = Long;
		}
		else if(ctx->type()->type_name(0)->T_SHORT())
		{
			last_var_type = Short;
		}
		else if(ctx->type()->type_name(0)->T_CHAR())
		{
			last_var_type = Char;
		}
		else if(ctx->type()->type_name(0)->T_DOUBLE())
		{
			last_var_type = Double;
		}
		else if(ctx->type()->type_name(0)->T_FLOAT())
		{
			last_var_type = Float;
		}
		else if(ctx->type()->type_name(0)->T_BOOL())
		{
			last_var_type = Bool;
		}
		
		VariableDeclaration::InsertVarName(ctx->name()->getText(), last_var_type);
	}
}

void Listener::GenerateDeclaration()
{
	bool nonStrictVar = !isStrict && isInsideFunctionScope() && notException;
	if (isInsideFuncDef) nonStrictVar = false;

	VariableDeclaration* decl = multivar_decl->GetDeclaration();

	if (nonStrictVar && !decl->HasInitializer())
		return;

	//if (multivar_decl->IsConst()) *to << "const ";

	if (decl->IsArray())
	{
		if (!GenerateTIndexBufferDecl(decl))
		{
			GenerateArrayDecl(nonStrictVar, decl);
		}

	}
	else {
		GenerateVariableDecl(nonStrictVar, decl);
	}

	if (multivar_decl->Modifier() != ModifierType::M_FUNC_ARG && !insideForLoop) *to << ";\n ";
	delete decl;
}

bool Listener::GenerateTIndexBufferDecl(VariableDeclaration * decl)
{
	if (multivar_decl->Type() == "double"
		&&  indexBuffers.find(decl->Name()) != indexBuffers.end())
	{
		stringstream ss;
		if (multivar_decl->IsConst()) ss << "const ";
		ss << "\nIndexBuffer " << VariableDeclaration::PrefixedVarName(decl->Name());
		if (isInsideFuncDef)
			*head << ss.str();
		*to << ss.str();

		registerOptions_function << "\n   " << VariableDeclaration::PrefixedVarName( decl->Name()) << ".CreateBuffer(); ";
		return true;
	}
	else return false;
}

void Listener::GenerateVariableDecl(bool nonStrictVar, VariableDeclaration * decl)
{
	auto mod = multivar_decl->Modifier();
	bool is_extern = mod == ModifierType::M_EXTERN;
	bool is_input = mod == ModifierType::M_INPUT;
	bool is_static = mod == ModifierType::M_STATIC;
	bool is_func_arg = mod == ModifierType::M_FUNC_ARG;

	if (is_extern || is_input)
	{
		GenerateExternInputVariable(is_input, decl);
	}
	else if (is_static)
	{
		*to << "static " << multivar_decl->Type() << " " << VariableDeclaration::PrefixedVarName( decl->Name());

		if (decl->HasInitializer())
			*to << decl->GetInitializer();
	}
	else if (is_func_arg)
	{
		stringstream cpp_h;
		
		if (multivar_decl->IsConst())
			cpp_h << "const ";

		cpp_h << multivar_decl->Type() 
			<< (multivar_decl->IsReference() ? "& " : " ")
			<< VariableDeclaration::PrefixedVarName(decl->Name());
		*to << cpp_h.str();
		*head << cpp_h.str();

		if (decl->HasInitializer())
		{
			*head << decl->GetInitializer();
		}
	}
	else
	{
		/*if ( nonStrictVar || (insideForLoop && appendVariable)) {}
		else {
			*to << multivar_decl->Type();
		}*/

		if (!nonStrictVar && !(insideForLoop && appendVariable) )
			*to << multivar_decl->Type();

		*to << " " << VariableDeclaration::PrefixedVarName(decl->Name());

        if (isInsideFunctionScope() && scope_level == 1 && IsEnumConstant(decl->Name()))
        {
            isVarNameAndEnumItemTheSame = true;
        }

        if (decl->HasInitializer())
        {
            *to << decl->GetInitializer();
        }
        else
        {
            if (isStrict && isInsideFunctionScope() && notException && IsArithmeticType(multivar_decl->Type()))
                *to << "{}";
        }
	}
}

void Listener::GenerateExternInputVariable(bool is_input, VariableDeclaration * decl)
{
	OtType ot_type = OtType::ot_Reserved0;

	if (is_input) this->input_parameters.insert(
		VariableDeclaration::PrefixedVarName(decl->Name())
	);

	const string type_str = DetermineOtType(ot_type);

	if(ot_type != OtType::ot_EnumType)
	{
		registerOptions_function
			<< "\n   RegOption(\""
			<< decl->Name()
			<< "\", "
			<< type_str
			<< ", &"
			<< VariableDeclaration::PrefixedVarName(decl->Name())
			<< ");\n";
	}
	else
	{
		registerOptions_function << "\n   "
			<< VariableDeclaration::PrefixedVarName(decl->Name()) << ".GenerateExtern(\""
			<< decl->Name() << "\");\n";
	}

	if (multivar_decl->Type() == "string")
	{
		*to << "ExternString";
	}
	else if(multivar_decl->Type() == "datetime")
	{
		*to << "ExternDatetime";
	}
	else if(multivar_decl->Type() == "char" || multivar_decl->Type() == "short")
	{
		*to << "int";
	}
	else if(multivar_decl->Type() == "uchar" || multivar_decl->Type() == "ushort")
	{
		*to << "unsigned int";
	}
	else
	{
		*to << multivar_decl->Type();
		
		if (multivar_decl->Type() == "double")
			registerOptions_function << "   SetOptionDigits(\"" << decl->Name() << "\", " << 8 << ");\n";
	}

	*to << " " << VariableDeclaration::PrefixedVarName(decl->Name());

	if (decl->HasInitializer())
	{
		if (ot_type == OtType::ot_Color)
		{
			registerOptions_function 
				<< "   " 
				<< VariableDeclaration::PrefixedVarName(decl->Name()) 
				<< " = " 
				<< decl->GetInitValue() 
				<< ";\n";
		}
		else
		{
			string init = decl->GetInitializer();
			*to << init;
		}
	}
}

const std::string Listener::DetermineOtType(OtType& ot_type)
{
	string type = multivar_decl->Type();

	if (type == "string")
	{
		ot_type = OtType::ot_String;
		return "(TOptionType)3";
	}
	else if (type == "color")
	{
		ot_type = OtType::ot_Color;
		return "ot_Color";
	}
    else if (type == "datetime")
    {
        ot_type = OtType::ot_DateTime;
        return "ot_DateTime";
    }
	else if (type == "double")
	{
		ot_type = OtType::ot_Double;
		return "ot_Double";
	}
	else if(type == "char")
	{
		ot_type = OtType::ot_Integer;
		return "ot_Integer";
	}
	else if(type == "uchar")
	{
		ot_type = OtType::ot_Longword;
		return "ot_Longword";
	}
	else if(type == "short")
	{
		ot_type = OtType::ot_Integer;
		return "ot_Integer";
	}
	else if(type == "ushort")
	{
		ot_type = OtType::ot_Longword;
		return "ot_Longword";
	}
	else if (type == "int")
	{
		ot_type = OtType::ot_Integer;
		return "ot_Integer";
	}
	else if(type == "uint")
	{
		ot_type = OtType::ot_Longword;
		return "ot_Longword";
	}
	else if(type == "long")
	{
		ot_type = OtType::ot_Integer;
		return "ot_Integer";
	}
	else if(type == "ulong")
	{
		ot_type = OtType::ot_Longword;
		return "ot_Longword";
	}
	else if (type == "bool")
	{
		ot_type = OtType::ot_Boolean;
		return "ot_Boolean";
	}
	else
	{
		if (type.length() > 13)
		{
			string p_unsigned = type.substr(0, 8);
			if (p_unsigned == "unsigned")
			{
				string p_long = type.substr(type.size() - 4);
				if(p_long == "long" || p_long == "int")
				{
					ot_type = OtType::ot_Longword;
					return "ot_Longword";
				}
			}
		}

		ot_type = OtType::ot_EnumType;
		return "ot_EnumType";
	}
}

void Listener::GenerateArrayDecl(bool nonStrictVar, VariableDeclaration * decl)
{
	stringstream ss;

	if (!nonStrictVar) GenerateArrayType(ss, decl);

	if (multivar_decl->IsReference()) ss << "& " << VariableDeclaration::PrefixedVarName(decl->Name());
	else {
		ss << VariableDeclaration::PrefixedVarName(decl->Name());

		if (!isInsideFuncDef)
		{
			if (decl->HasInitializer())
			{
				if(decl->GetDim() > 0 && decl->Is1DInitList() && !nonStrictVar) GenerateArrayArguments(ss, decl, decl->GetInitValue());
				else ss << decl->GetInitializer();
			}
			else GenerateArrayArguments(ss, decl);
		}
	}

	if (multivar_decl->Modifier() == ModifierType::M_FUNC_ARG)
	{
		*head << ss.str();
	}

	*to << ss.str();
}

void Listener::GenerateArrayType(std::stringstream &ss, VariableDeclaration * decl)
{
	if (multivar_decl->IsConst()) ss << "const ";

	ss << "Array"
		<< (decl->GetDim() > 1 ? to_string(decl->GetDim()) + "D" : "")
		<< "<" << multivar_decl->Type() << "> ";
}

void Listener::GenerateArrayArguments(std::stringstream &ss, VariableDeclaration * decl, string init)
{
	ss << "(" << decl->GetDimSize(0);
	for (int i = 1; i < decl->GetDim(); i++) ss << "," << decl->GetDimSize(i);
	if (init != "") ss << ", " << init;
	ss << ")";
}

std::string Listener::GenerateColorLiteral(GrammarParser::Rgb_litteralContext *ctx)
{
    const string warning_msg = "\n    (warning) : Wrong color format at '" + ctx->getText() + "'";
    int R = 0, G = 0, B = 0;

    R = ctx->hex_or_regular_integer(0) && ctx->hex_or_regular_integer(0)->HEX_INTEGER()
        ? stoi(ctx->hex_or_regular_integer(0)->HEX_INTEGER()->getText(), nullptr, 16)
        : stoi(ctx->hex_or_regular_integer(0)->INTEGER()->getText());

    G = ctx->hex_or_regular_integer(1) && ctx->hex_or_regular_integer(1)->HEX_INTEGER()
        ? stoi(ctx->hex_or_regular_integer(1)->HEX_INTEGER()->getText(), nullptr, 16)
        : stoi(ctx->hex_or_regular_integer(1)->INTEGER()->getText());

    B = ctx->hex_or_regular_integer(2) && ctx->hex_or_regular_integer(2)->HEX_INTEGER()
        ? stoi(ctx->hex_or_regular_integer(2)->HEX_INTEGER()->getText(), nullptr, 16)
        : stoi(ctx->hex_or_regular_integer(2)->INTEGER()->getText());

    std::stringstream color_ctor;
    color_ctor << "color(";
    if (R > 255 || G > 255 || B > 255)
    {
        cout << warning_msg;
        color_ctor << "0, 0, 0";
    }
    else color_ctor << R << ", " << G << ", " << B;

    color_ctor << ")";
    return color_ctor.str();
}

void Listener::enterAppend_variable_declaration(GrammarParser::Append_variable_declarationContext * ctx)
{
	if (isOutputTraverse || (!isStrict && isInsideFunctionScope() && notException) )
	{
		multivar_decl->NextDeclaration()->SetName(ctx->name()->getText());
	}

	appendVariable = true;
}

void Listener::exitAppend_variable_declaration(GrammarParser::Append_variable_declarationContext * ctx)
{
	if (isOutputTraverse)
	{
		if (isStrict && insideForLoop)
		{
			*to << ", ";
		}
		GenerateDeclaration();
	}
	else
	{		
		VariableDeclaration::InsertVarName(ctx->name()->getText(), last_var_type);
	}
	appendVariable = false;
}

void Listener::enterInitialization_value(GrammarParser::Initialization_valueContext * ctx)
{
	if (isOutputTraverse)
	{
		buffer.str("");
		if (ctx->array_initialization_list())
		{
			enclosed_initlist = -1;
			initlist_items_counter.clear();
		}
		else
		{
			SetBuffer();
		}
	}
}

void Listener::exitInitialization_value(GrammarParser::Initialization_valueContext * ctx)
{
	if (isOutputTraverse)
	{
		if(ctx->array_initialization_list())
		{
			multivar_decl->SetInitValue(buffer.str());
		}
		else
		{
			string buff_content = ResetBuffer();
			setImplicitCast(true);
			buff_content = implicit_cast + buff_content;
			if(!implicit_cast.empty())
			{
				buff_content += ")";
			}
			multivar_decl->SetInitValue(buff_content);
		}
	}
}


void Listener::enterArray_initialization_list(GrammarParser::Array_initialization_listContext * ctx)
{
	if (isOutputTraverse)
	{
		buffer << "{";

		enclosed_initlist++;
		if (enclosed_initlist > 0) multivar_decl->Set1DInitList(false);

		if (initlist_items_counter.size() <= enclosed_initlist)
			initlist_items_counter.push_back(0);
		else initlist_items_counter[enclosed_initlist] = 0;

		if (ctx->initialization_list_items())
			initlist_items_counter[enclosed_initlist]++;
	}
}

int MulDims(MultivariableDeclaration* mldecl)
{
	if (mldecl->Dimension() > 0) 
	{
		int s = 1;
		for (size_t i = 0; i < mldecl->Dimension(); i++)
		{
			int val = stoi(mldecl->GetSizeAt(i));
			if (val > 0) s *= val;
			else
			{
				s = INT32_MAX;
				break;
			}
		}
		return s;
	}
	else return 0;
}

void Listener::exitArray_initialization_list(GrammarParser::Array_initialization_listContext * ctx)
{
	if (isOutputTraverse)
	{
		buffer << "}";

		int size = -1;
		try {
			string strsize = multivar_decl->GetSizeAt(enclosed_initlist);
			size = stoi(strsize);

			bool out_of_bounds = (size > 0 &&
				initlist_items_counter[enclosed_initlist] > size);

			bool abs_out_of_bounds = (initlist_items_counter.size() > 1
					|| MulDims(multivar_decl) < initlist_items_counter[0]);

			if (out_of_bounds && abs_out_of_bounds)
			{
				int i = MulDims(multivar_decl);

				cout << "\n   (warning): too many initializers for '" << multivar_decl->Type() ;
				for (size_t i = 0; i < multivar_decl->Dimension(); i++)
				{
					cout << "[" << multivar_decl->GetSizeAt(i) << "]";
				}
				auto token = ctx->CL_CRL_BR()->getSymbol();
				cout << "' at line " << token->getLine() << " col " << token->getCharPositionInLine();

			}
		}
		catch (invalid_argument ex) {	}
		
		enclosed_initlist--;
	}
}

void Listener::enterInitialization_list_append_items(GrammarParser::Initialization_list_append_itemsContext * ctx)
{
	if (isOutputTraverse)
	{
		buffer << ",";

		initlist_items_counter[enclosed_initlist]++;
	}
}

void Listener::exitInitialization_list_append_items(GrammarParser::Initialization_list_append_itemsContext * ctx)
{
}

void Listener::enterInitialization_list_items(GrammarParser::Initialization_list_itemsContext * ctx)
{
	if (isOutputTraverse)
	{
		const auto spaces = ctx->space();
		if (!spaces.empty() && !ctx->array_initialization_list())
		{
			buffer << multivar_decl->Type() << "()";
		}
	}
}

void Listener::exitInitialization_list_items(GrammarParser::Initialization_list_itemsContext * ctx)
{
}

void Listener::enterInitialization_list_item(GrammarParser::Initialization_list_itemContext * ctx)
{
	if (isOutputTraverse)
	{
		if (ctx->datetime_litteral())
			SetBuffer();
	}
}

void Listener::exitInitialization_list_item(GrammarParser::Initialization_list_itemContext * ctx)
{
	if (isOutputTraverse)
	{
		if (ctx->datetime_litteral())
			buffer << ResetBuffer();
		else if (ctx->color_litteral())
			buffer << GenerateColorLiteral(ctx->color_litteral()->rgb_litteral());
		else buffer << ctx->getText();
	}
}

void Listener::enterConst_name(GrammarParser::Const_nameContext * ctx)
{
}

void Listener::exitConst_name(GrammarParser::Const_nameContext * ctx)
{
}

void Listener::enterDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext * ctx)
{
	dyn_array_dim = 0;
}

void Listener::exitDynamic_array_brackets_params(GrammarParser::Dynamic_array_brackets_paramsContext * ctx)
{
}

void Listener::enterDynamic_array_brackets_parameter(GrammarParser::Dynamic_array_brackets_parameterContext * ctx)
{
	if (isOutputTraverse || (!isStrict && isInsideFunctionScope() && notException)) {
		dyn_array_dim++;

		if (!ctx->dynamic_array_parameter())
			multivar_decl->AppendSize("0");
		//array_dimentions.push_back("0");
	}
}

void Listener::exitDynamic_array_brackets_parameter(GrammarParser::Dynamic_array_brackets_parameterContext * ctx)
{
}

void Listener::enterDynamic_array_append_parameter(GrammarParser::Dynamic_array_append_parameterContext * ctx)
{
	if (isOutputTraverse || (!isStrict && isInsideFunctionScope() && notException)) 
	{
		dyn_array_dim++;

		if (!ctx->dynamic_array_parameter())
			multivar_decl->AppendSize("0");
	}
}

void Listener::exitDynamic_array_append_parameter(GrammarParser::Dynamic_array_append_parameterContext * ctx)
{
}

void Listener::enterDynamic_array_parameter(GrammarParser::Dynamic_array_parameterContext * ctx)
{
	if (isOutputTraverse || (!isStrict && isInsideFunctionScope() && notException)) {
		auto ptr = ctx->INTEGER();
		multivar_decl->AppendSize((ptr ? ptr->getText() : ctx->NAME()->getText()));
	}
}

void Listener::exitDynamic_array_parameter(GrammarParser::Dynamic_array_parameterContext * ctx)
{
}

void Listener::enterSet_index_buffer(GrammarParser::Set_index_bufferContext * ctx)
{
	if(ctx->rvalue()) this->SetBuffer();
	
	string name = ctx->name()->getText();

	if(addToBuffers)
		indexBuffers.insert(name);
	else if(indexBuffers.find(name) != indexBuffers.end())
		indexBuffers.erase(name);

	static int index;
	if(ctx->INTEGER())
	{
		index = stoi(ctx->INTEGER()->getText());
	}

	if(isOutputTraverse)
	{
		++set_ind_buffs;

		*cpp << "true";
		if(index < visible_ind_buffs || (!visible_ind_buffs && !index))
		{
			set_ind_buffs_calls << "\n   SetIndexBuffer(" << index << ", " 
				<< VariableDeclaration::PrefixedVarName(ctx->name()->getText());
			if(ctx->INDEX_BUFFER_TYPE())
			{
				set_ind_buffs_calls << ", " << ctx->INDEX_BUFFER_TYPE()->getText();
			}
			set_ind_buffs_calls << ");";
		}

		++index;
	}
}

void Listener::exitSet_index_buffer(GrammarParser::Set_index_bufferContext * ctx)
{
	if(ctx->rvalue()) this->ResetBuffer();
}

void Listener::enterSet_level_style(GrammarParser::Set_level_styleContext * ctx)
{
	if (isOutputTraverse)
	{
		if (!isLevelStyleSet) {
			registerOptions_function << "\n   " << ctx->getText() << "\n";
			isLevelStyleSet = true;
		}
	}
}

void Listener::exitSet_level_style(GrammarParser::Set_level_styleContext * ctx)
{

}

void Listener::enterAlert(GrammarParser::AlertContext * ctx)
{
	if (isOutputTraverse)
		*to << "Print(";
}

void Listener::exitAlert(GrammarParser::AlertContext * ctx)
{
}

void Listener::enterFunction_definition(GrammarParser::Function_definitionContext * ctx)
{
	isInsideFuncDef = true;
	setOuterName(ctx->NAME()->getText());
	setOuterType(ctx->type()->getText());
	
	if (this->isOutputTraverse)
	{
		string s = ctx->type()->getText() + " " + this->outer_definition_name + "(";
		*to << s;
		*head << s;
	}
}

void Listener::exitFunction_definition(GrammarParser::Function_definitionContext * ctx)
{
	if (this->isOutputTraverse)
	{
		*to << ")";
		*head << "); \n";
	}

	isInsideFuncDef = false;
}

void Listener::enterType(GrammarParser::TypeContext * ctx)
{
}

void Listener::exitType(GrammarParser::TypeContext * ctx)
{
}

void Listener::enterType_name(GrammarParser::Type_nameContext * ctx)
{
}

void Listener::exitType_name(GrammarParser::Type_nameContext * ctx)
{
}

void Listener::enterParams_list(GrammarParser::Params_listContext * ctx)
{
}

void Listener::exitParams_list(GrammarParser::Params_listContext * ctx)
{
}

void Listener::enterArgument(GrammarParser::ArgumentContext * ctx)
{
	if (isOutputTraverse || !isStrict)
	{
		multivar_decl = new MultivariableDeclaration();

		multivar_decl->Modifier(ModifierType::M_FUNC_ARG);
	}
}

void Listener::exitArgument(GrammarParser::ArgumentContext * ctx)
{
	if (isOutputTraverse)
	{
		delete multivar_decl;
		multivar_decl = nullptr;
	}
}

void Listener::enterAppend_argument(GrammarParser::Append_argumentContext * ctx)
{
	if (this->isOutputTraverse)
	{
		string s = ", ";
		*to << s;
		*head << s;
	}
}

void Listener::exitAppend_argument(GrammarParser::Append_argumentContext * ctx)
{
}

void Listener::enterFcall_argument(GrammarParser::Fcall_argumentContext * ctx)
{
}

void Listener::exitFcall_argument(GrammarParser::Fcall_argumentContext * ctx)
{	
}

void Listener::enterFcall_anyrule(GrammarParser::Fcall_anyruleContext * ctx)
{
	if (isOutputTraverse)
		if (!ctx->argument_content()) *to << ctx->no_comma()->getText();
}

void Listener::exitFcall_anyrule(GrammarParser::Fcall_anyruleContext * ctx)
{
}

void Listener::enterFcall_params(GrammarParser::Fcall_paramsContext * ctx)
{
	if (isOutputTraverse)
		*to << ctx->OP_PARETHESES()->getText();
}

void Listener::exitFcall_params(GrammarParser::Fcall_paramsContext * ctx)
{
	if (isOutputTraverse)
		*to << ctx->CL_PARETHESES()->getText();
}

void Listener::enterFcall_params_list(GrammarParser::Fcall_params_listContext * ctx)
{
}

void Listener::exitFcall_params_list(GrammarParser::Fcall_params_listContext * ctx)
{
}

void Listener::enterAppend_fcall_argument(GrammarParser::Append_fcall_argumentContext * ctx)
{
	if (isOutputTraverse)
		*to << ", ";
}

void Listener::exitAppend_fcall_argument(GrammarParser::Append_fcall_argumentContext * ctx)
{
}

void Listener::enterDeinit_function_call(GrammarParser::Deinit_function_callContext * ctx)
{
	this->deinit_found = true;

	auto t_ptr = ctx->T_INT();
	if (t_ptr)
	{
		this->deinitType = DeinitType::INT_DEINIT;
	}
	else if (t_ptr = ctx->T_VOID(0))
	{
		this->deinitType = DeinitType::VOID_DEINIT;
	}

	setOuterName(ctx->DEINIT()->getText());
	setOuterType(t_ptr->getText());
}

void Listener::exitDeinit_function_call(GrammarParser::Deinit_function_callContext * ctx)
{
}

void Listener::enterInit_function_call(GrammarParser::Init_function_callContext * ctx)
{
	auto t_ptr = ctx->T_INT();

	if (t_ptr) 
	{
		this->initType = InitType::INT_INIT;
	}
	else if (t_ptr = ctx->T_VOID(0))
	{
		this->initType = InitType::VOID_INIT;
	}

	setOuterName(ctx->INIT()->getText());
	setOuterType(t_ptr->getText());
}

void Listener::exitInit_function_call(GrammarParser::Init_function_callContext * ctx)
{
}

void Listener::enterStart_function_call(GrammarParser::Start_function_callContext * ctx)
{
	auto t_ptr = ctx->T_INT();

	if (t_ptr)
	{
		this->startType = StartType::INT_START;
	}
	else if (t_ptr = ctx->T_VOID(0))
	{
		this->startType = StartType::VOID_START;
	}

	setOuterName(ctx->START()->getText());
	setOuterType(t_ptr->getText());
}

void Listener::exitStart_function_call(GrammarParser::Start_function_callContext * ctx)
{
}

void Listener::enterOn_calculate_handler(GrammarParser::On_calculate_handlerContext * ctx)
{
	setOuterName(ctx->ON_CALCULATE()->getText());
	setOuterType("int");
	
	if (this->isOutputTraverse)
	{
		this->startType = StartType::INT_ON_CALCULATE;

		*to << "int OnCalculate (const int rates_total,"
			"\n		const int prev_calculated,"
			"\n		TimeSeries& time,"
			"\n		OpenSeries& open,"
			"\n		HighSeries& high,"
			"\n		LowSeries& low,"
			"\n		CloseSeries& close,"
			"\n		TickVolumeSeries& tick_volume,"
			"\n		VolumeSeries& volume,"
			"\n		SpreadSeries& spread"
			"\n		) ";
	}
}

void Listener::exitOn_calculate_handler(GrammarParser::On_calculate_handlerContext * ctx)
{
}

void Listener::enterOn_tick_handler(GrammarParser::On_tick_handlerContext * ctx)
{
	this->startType = StartType::ON_TICK;

	if(!ctx->type_name()->T_VOID())
	{
		cout << "(warning) OnTick function declared with wrong type or/and parameters!\n";
		setOuterType(ctx->type_name()->getText());
	}
	else
	{
		setOuterType("void");
	}

	setOuterName(ctx->ON_TICK()->getText());
}

void Listener::exitOn_tick_handler(GrammarParser::On_tick_handlerContext * ctx)
{
}

void Listener::enterOn_init_handler(GrammarParser::On_init_handlerContext * ctx)
{
    auto t_ptr = ctx->T_INT();
    if (t_ptr)
    {
        this->initType = InitType::INT_ON_INIT;
    }
    else if (t_ptr = ctx->T_VOID(0))
    {
        this->initType = InitType::VOID_ON_INIT;
    }

    setOuterName(ctx->ON_INIT()->getText());
    setOuterType(t_ptr->getText());
}

void Listener::exitOn_init_handler(GrammarParser::On_init_handlerContext * ctx)
{
}

void Listener::enterOn_deinit_handler(GrammarParser::On_deinit_handlerContext * ctx)
{
	this->deinitType = DeinitType::VOID_ON_DEINIT;
	this->deinit_found = true;

	if(!ctx->type_name()->T_VOID())
	{
		cout << "(warning) OnDeinit function declared with wrong type or/and parameters!\n";
		setOuterType(ctx->type_name()->getText());
	}
	else
	{
		setOuterType("void");
	}

	setOuterName(ctx->ON_DEINIT()->getText());
}

void Listener::exitOn_deinit_handler(GrammarParser::On_deinit_handlerContext * ctx)
{
}

void Listener::enterOn_timer_handler(GrammarParser::On_timer_handlerContext * ctx)
{
}

void Listener::exitOn_timer_handler(GrammarParser::On_timer_handlerContext * ctx)
{
}

void Listener::enterOn_chart_event_handler(GrammarParser::On_chart_event_handlerContext *ctx)
{
	hooking_funcs_present = true;
}

void Listener::exitOn_chart_event_handler(GrammarParser::On_chart_event_handlerContext *ctx)
{
}

void Listener::enterName(GrammarParser::NameContext * ctx)
{
	if (isOutputTraverse)
	{
		if(ctx->STRATEGY_ONLY())
		{
			StrategyScript(ctx->STRATEGY_ONLY()->getText());
		}
		if(ctx->INDICATORS_ONLY())
		{
			IndicatorScript(ctx->INDICATORS_ONLY()->getText());
		}
		if(ctx->HOOKING_FUNCS())
		{
			hooking_funcs_present = true;
		}
		if(ctx->ON_TIMER())
		{
			on_timer = true;
		}
	}
}

void Listener::exitName(GrammarParser::NameContext * ctx)
{
}

void Listener::enterSpace(GrammarParser::SpaceContext *ctx)
{

}

void Listener::exitSpace(GrammarParser::SpaceContext *ctx)
{

}

void Listener::enterFloat_value(GrammarParser::Float_valueContext * ctx)
{
}

void Listener::exitFloat_value(GrammarParser::Float_valueContext * ctx)
{
}

void Listener::enterAny_lex(GrammarParser::Any_lexContext * ctx)
{
	if (isOutputTraverse)
	{
		if (ctx->name())
		{
            const string name = ctx->name()->getText();
            if (IsEnumConstant(name))
            {
			    *to << (isVarNameAndEnumItemTheSame ? VariableDeclaration::CheckVarName(name, isOnCalculate()) : name);
            }
            else
            {
                *to << VariableDeclaration::CheckVarName(name, isOnCalculate());
            }
		}
		else
		{
			*to << ctx->getText();
		}
	}
}

void Listener::exitAny_lex(GrammarParser::Any_lexContext * ctx)
{
}

void Listener::enterInteger(GrammarParser::IntegerContext * ctx)
{
}

void Listener::exitInteger(GrammarParser::IntegerContext * ctx)
{
}

void Listener::enterAny_function_definition(GrammarParser::Any_function_definitionContext * ctx)
{
}

void Listener::exitAny_function_definition(GrammarParser::Any_function_definitionContext * ctx)
{
	resetOuterName();
	resetOuterType();

	if (isOutputTraverse) 
	{
		if (ctx->SC())
			*to << " ;";
	}
}

void Listener::enterParantheses_expression(GrammarParser::Parantheses_expressionContext * ctx)
{
}

void Listener::exitParantheses_expression(GrammarParser::Parantheses_expressionContext * ctx)
{
}

void Listener::enterTryblock_replacement_start(GrammarParser::Tryblock_replacement_startContext * ctx)
{
	if (isOutputTraverse)
	{
		*to << "try \n   {\n";
	}
}

void Listener::exitTryblock_replacement_start(GrammarParser::Tryblock_replacement_startContext * ctx)
{
}

void Listener::enterTryblock_replacement_end(GrammarParser::Tryblock_replacement_endContext * ctx)
{
	if (isOutputTraverse) {
		auto funcName = ctx->NAME()->getText();
		*to << "\n }\n   catch(exception)\n   {\n   Print(\"Function \\\"" + funcName + "\\\" does not work properly\");\n   }\n";
	}
}

void Listener::exitTryblock_replacement_end(GrammarParser::Tryblock_replacement_endContext * ctx)
{
}

void Listener::enterMl_content(GrammarParser::Ml_contentContext *ctx) 
{
}

void Listener::exitMl_content(GrammarParser::Ml_contentContext *ctx) 
{
}

void Listener::enterOl_content(GrammarParser::Ol_contentContext *ctx) 
{
}
void Listener::exitOl_content(GrammarParser::Ol_contentContext *ctx) 
{
}

void Listener::enterNo_cl_parentheses(GrammarParser::No_cl_parenthesesContext * ctx)
{
}

void Listener::exitNo_cl_parentheses(GrammarParser::No_cl_parenthesesContext * ctx)
{
}

void Listener::enterNo_semicolon(GrammarParser::No_semicolonContext * ctx)
{
}

void Listener::exitNo_semicolon(GrammarParser::No_semicolonContext * ctx)
{
}

void Listener::enterNo_comma(GrammarParser::No_commaContext * ctx)
{
}

void Listener::exitNo_comma(GrammarParser::No_commaContext * ctx)
{
}

void Listener::enterNo_comma_sq_br(GrammarParser::No_comma_sq_brContext * ctx)
{
}

void Listener::exitNo_comma_sq_br(GrammarParser::No_comma_sq_brContext * ctx)
{
}

void Listener::enterNo_comma_semicolon(GrammarParser::No_comma_semicolonContext * ctx)
{
}

void Listener::exitNo_comma_semicolon(GrammarParser::No_comma_semicolonContext * ctx)
{
}

void Listener::visitTerminal(TerminalNode * node)
{
}

void Listener::visitErrorNode(ErrorNode * node)
{
}

void Listener::enterEveryRule(ParserRuleContext * ctx)
{
}

void Listener::exitEveryRule(ParserRuleContext * ctx)
{
}