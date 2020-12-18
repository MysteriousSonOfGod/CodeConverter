
// Generated from c:\Projects\ForexTester\MQL2FT_REPO\MQL2FT\MQL2FT\Translator\Grammar.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  GrammarLexer : public antlr4::Lexer {
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

  GrammarLexer(antlr4::CharStream *input);
  ~GrammarLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

