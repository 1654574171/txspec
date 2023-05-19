
// Generated from BindingLexer.g4 by ANTLR 4.9.3


#include "BindingLexer.h"


using namespace antlr4;


BindingLexer::BindingLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

BindingLexer::~BindingLexer() {
  delete _interpreter;
}

std::string BindingLexer::getGrammarFileName() const {
  return "BindingLexer.g4";
}

const std::vector<std::string>& BindingLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& BindingLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& BindingLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& BindingLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& BindingLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> BindingLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& BindingLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> BindingLexer::_decisionToDFA;
atn::PredictionContextCache BindingLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BindingLexer::_atn;
std::vector<uint16_t> BindingLexer::_serializedATN;

std::vector<std::string> BindingLexer::_ruleNames = {
  "RULES", "L_CURLY", "R_CURLY", "L_BRACKET", "R_BRACKET", "MAP", "DOT", 
  "COMMA", "SEMI", "WS", "COMMENT", "TERMINATOR", "LINE_COMMENT", "IDENTIFIER", 
  "LETTER", "UNICODE_DIGIT", "UNICODE_LETTER"
};

std::vector<std::string> BindingLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> BindingLexer::_modeNames = {
  "DEFAULT_MODE"
};

std::vector<std::string> BindingLexer::_literalNames = {
  "", "", "'{'", "'}'", "'['", "']'", "'->'", "'.'", "','", "';'"
};

std::vector<std::string> BindingLexer::_symbolicNames = {
  "", "RULES", "L_CURLY", "R_CURLY", "L_BRACKET", "R_BRACKET", "MAP", "DOT", 
  "COMMA", "SEMI", "WS", "COMMENT", "TERMINATOR", "LINE_COMMENT", "IDENTIFIER"
};

dfa::Vocabulary BindingLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> BindingLexer::_tokenNames;

BindingLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x2, 0x10, 0x79, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 
       0x4, 0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 
       0x7, 0x9, 0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 
       0x9, 0xa, 0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 
       0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 
       0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x5, 0x2, 0x30, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xb, 0x6, 0xb, 0x44, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 
       0x45, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x7, 0xc, 0x4e, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x51, 0xb, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x6, 0xd, 
       0x59, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x5a, 0x3, 0xd, 0x3, 0xd, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x63, 0xa, 0xe, 0xc, 
       0xe, 0xe, 0xe, 0x66, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x7, 0xf, 0x6d, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x70, 
       0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x74, 0xa, 0x10, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x4f, 0x2, 0x13, 0x3, 
       0x3, 0x5, 0x4, 0x7, 0x5, 0x9, 0x6, 0xb, 0x7, 0xd, 0x8, 0xf, 0x9, 
       0x11, 0xa, 0x13, 0xb, 0x15, 0xc, 0x17, 0xd, 0x19, 0xe, 0x1b, 0xf, 
       0x1d, 0x10, 0x1f, 0x2, 0x21, 0x2, 0x23, 0x2, 0x3, 0x2, 0x4, 0x4, 
       0x2, 0xb, 0xb, 0x22, 0x22, 0x4, 0x2, 0xc, 0xc, 0xf, 0xf, 0x4, 0x3f, 
       0x2, 0x32, 0x2, 0x3b, 0x2, 0x662, 0x2, 0x66b, 0x2, 0x6f2, 0x2, 0x6fb, 
       0x2, 0x7c2, 0x2, 0x7cb, 0x2, 0x968, 0x2, 0x971, 0x2, 0x9e8, 0x2, 
       0x9f1, 0x2, 0xa68, 0x2, 0xa71, 0x2, 0xae8, 0x2, 0xaf1, 0x2, 0xb68, 
       0x2, 0xb71, 0x2, 0xbe8, 0x2, 0xbf1, 0x2, 0xc68, 0x2, 0xc71, 0x2, 
       0xce8, 0x2, 0xcf1, 0x2, 0xd68, 0x2, 0xd71, 0x2, 0xde8, 0x2, 0xdf1, 
       0x2, 0xe52, 0x2, 0xe5b, 0x2, 0xed2, 0x2, 0xedb, 0x2, 0xf22, 0x2, 
       0xf2b, 0x2, 0x1042, 0x2, 0x104b, 0x2, 0x1092, 0x2, 0x109b, 0x2, 0x17e2, 
       0x2, 0x17eb, 0x2, 0x1812, 0x2, 0x181b, 0x2, 0x1948, 0x2, 0x1951, 
       0x2, 0x19d2, 0x2, 0x19db, 0x2, 0x1a82, 0x2, 0x1a8b, 0x2, 0x1a92, 
       0x2, 0x1a9b, 0x2, 0x1b52, 0x2, 0x1b5b, 0x2, 0x1bb2, 0x2, 0x1bbb, 
       0x2, 0x1c42, 0x2, 0x1c4b, 0x2, 0x1c52, 0x2, 0x1c5b, 0x2, 0xa622, 
       0x2, 0xa62b, 0x2, 0xa8d2, 0x2, 0xa8db, 0x2, 0xa902, 0x2, 0xa90b, 
       0x2, 0xa9d2, 0x2, 0xa9db, 0x2, 0xa9f2, 0x2, 0xa9fb, 0x2, 0xaa52, 
       0x2, 0xaa5b, 0x2, 0xabf2, 0x2, 0xabfb, 0x2, 0xff12, 0x2, 0xff1b, 
       0x2, 0x4a2, 0x3, 0x4ab, 0x3, 0xd32, 0x3, 0xd3b, 0x3, 0x1068, 0x3, 
       0x1071, 0x3, 0x10f2, 0x3, 0x10fb, 0x3, 0x1138, 0x3, 0x1141, 0x3, 
       0x11d2, 0x3, 0x11db, 0x3, 0x12f2, 0x3, 0x12fb, 0x3, 0x1452, 0x3, 
       0x145b, 0x3, 0x14d2, 0x3, 0x14db, 0x3, 0x1652, 0x3, 0x165b, 0x3, 
       0x16c2, 0x3, 0x16cb, 0x3, 0x1732, 0x3, 0x173b, 0x3, 0x18e2, 0x3, 
       0x18eb, 0x3, 0x1952, 0x3, 0x195b, 0x3, 0x1c52, 0x3, 0x1c5b, 0x3, 
       0x1d52, 0x3, 0x1d5b, 0x3, 0x1da2, 0x3, 0x1dab, 0x3, 0x6a62, 0x3, 
       0x6a6b, 0x3, 0x6b52, 0x3, 0x6b5b, 0x3, 0xd7d0, 0x3, 0xd801, 0x3, 
       0xe142, 0x3, 0xe14b, 0x3, 0xe2f2, 0x3, 0xe2fb, 0x3, 0xe952, 0x3, 
       0xe95b, 0x3, 0xfbf2, 0x3, 0xfbfb, 0x3, 0x270, 0x2, 0x43, 0x2, 0x5c, 
       0x2, 0x63, 0x2, 0x7c, 0x2, 0xac, 0x2, 0xac, 0x2, 0xb7, 0x2, 0xb7, 
       0x2, 0xbc, 0x2, 0xbc, 0x2, 0xc2, 0x2, 0xd8, 0x2, 0xda, 0x2, 0xf8, 
       0x2, 0xfa, 0x2, 0x2c3, 0x2, 0x2c8, 0x2, 0x2d3, 0x2, 0x2e2, 0x2, 0x2e6, 
       0x2, 0x2ee, 0x2, 0x2ee, 0x2, 0x2f0, 0x2, 0x2f0, 0x2, 0x372, 0x2, 
       0x376, 0x2, 0x378, 0x2, 0x379, 0x2, 0x37c, 0x2, 0x37f, 0x2, 0x381, 
       0x2, 0x381, 0x2, 0x388, 0x2, 0x388, 0x2, 0x38a, 0x2, 0x38c, 0x2, 
       0x38e, 0x2, 0x38e, 0x2, 0x390, 0x2, 0x3a3, 0x2, 0x3a5, 0x2, 0x3f7, 
       0x2, 0x3f9, 0x2, 0x483, 0x2, 0x48c, 0x2, 0x531, 0x2, 0x533, 0x2, 
       0x558, 0x2, 0x55b, 0x2, 0x55b, 0x2, 0x562, 0x2, 0x58a, 0x2, 0x5d2, 
       0x2, 0x5ec, 0x2, 0x5f1, 0x2, 0x5f4, 0x2, 0x622, 0x2, 0x64c, 0x2, 
       0x670, 0x2, 0x671, 0x2, 0x673, 0x2, 0x6d5, 0x2, 0x6d7, 0x2, 0x6d7, 
       0x2, 0x6e7, 0x2, 0x6e8, 0x2, 0x6f0, 0x2, 0x6f1, 0x2, 0x6fc, 0x2, 
       0x6fe, 0x2, 0x701, 0x2, 0x701, 0x2, 0x712, 0x2, 0x712, 0x2, 0x714, 
       0x2, 0x731, 0x2, 0x74f, 0x2, 0x7a7, 0x2, 0x7b3, 0x2, 0x7b3, 0x2, 
       0x7cc, 0x2, 0x7ec, 0x2, 0x7f6, 0x2, 0x7f7, 0x2, 0x7fc, 0x2, 0x7fc, 
       0x2, 0x802, 0x2, 0x817, 0x2, 0x81c, 0x2, 0x81c, 0x2, 0x826, 0x2, 
       0x826, 0x2, 0x82a, 0x2, 0x82a, 0x2, 0x842, 0x2, 0x85a, 0x2, 0x862, 
       0x2, 0x86c, 0x2, 0x8a2, 0x2, 0x8b6, 0x2, 0x8b8, 0x2, 0x8c9, 0x2, 
       0x906, 0x2, 0x93b, 0x2, 0x93f, 0x2, 0x93f, 0x2, 0x952, 0x2, 0x952, 
       0x2, 0x95a, 0x2, 0x963, 0x2, 0x973, 0x2, 0x982, 0x2, 0x987, 0x2, 
       0x98e, 0x2, 0x991, 0x2, 0x992, 0x2, 0x995, 0x2, 0x9aa, 0x2, 0x9ac, 
       0x2, 0x9b2, 0x2, 0x9b4, 0x2, 0x9b4, 0x2, 0x9b8, 0x2, 0x9bb, 0x2, 
       0x9bf, 0x2, 0x9bf, 0x2, 0x9d0, 0x2, 0x9d0, 0x2, 0x9de, 0x2, 0x9df, 
       0x2, 0x9e1, 0x2, 0x9e3, 0x2, 0x9f2, 0x2, 0x9f3, 0x2, 0x9fe, 0x2, 
       0x9fe, 0x2, 0xa07, 0x2, 0xa0c, 0x2, 0xa11, 0x2, 0xa12, 0x2, 0xa15, 
       0x2, 0xa2a, 0x2, 0xa2c, 0x2, 0xa32, 0x2, 0xa34, 0x2, 0xa35, 0x2, 
       0xa37, 0x2, 0xa38, 0x2, 0xa3a, 0x2, 0xa3b, 0x2, 0xa5b, 0x2, 0xa5e, 
       0x2, 0xa60, 0x2, 0xa60, 0x2, 0xa74, 0x2, 0xa76, 0x2, 0xa87, 0x2, 
       0xa8f, 0x2, 0xa91, 0x2, 0xa93, 0x2, 0xa95, 0x2, 0xaaa, 0x2, 0xaac, 
       0x2, 0xab2, 0x2, 0xab4, 0x2, 0xab5, 0x2, 0xab7, 0x2, 0xabb, 0x2, 
       0xabf, 0x2, 0xabf, 0x2, 0xad2, 0x2, 0xad2, 0x2, 0xae2, 0x2, 0xae3, 
       0x2, 0xafb, 0x2, 0xafb, 0x2, 0xb07, 0x2, 0xb0e, 0x2, 0xb11, 0x2, 
       0xb12, 0x2, 0xb15, 0x2, 0xb2a, 0x2, 0xb2c, 0x2, 0xb32, 0x2, 0xb34, 
       0x2, 0xb35, 0x2, 0xb37, 0x2, 0xb3b, 0x2, 0xb3f, 0x2, 0xb3f, 0x2, 
       0xb5e, 0x2, 0xb5f, 0x2, 0xb61, 0x2, 0xb63, 0x2, 0xb73, 0x2, 0xb73, 
       0x2, 0xb85, 0x2, 0xb85, 0x2, 0xb87, 0x2, 0xb8c, 0x2, 0xb90, 0x2, 
       0xb92, 0x2, 0xb94, 0x2, 0xb97, 0x2, 0xb9b, 0x2, 0xb9c, 0x2, 0xb9e, 
       0x2, 0xb9e, 0x2, 0xba0, 0x2, 0xba1, 0x2, 0xba5, 0x2, 0xba6, 0x2, 
       0xbaa, 0x2, 0xbac, 0x2, 0xbb0, 0x2, 0xbbb, 0x2, 0xbd2, 0x2, 0xbd2, 
       0x2, 0xc07, 0x2, 0xc0e, 0x2, 0xc10, 0x2, 0xc12, 0x2, 0xc14, 0x2, 
       0xc2a, 0x2, 0xc2c, 0x2, 0xc3b, 0x2, 0xc3f, 0x2, 0xc3f, 0x2, 0xc5a, 
       0x2, 0xc5c, 0x2, 0xc62, 0x2, 0xc63, 0x2, 0xc82, 0x2, 0xc82, 0x2, 
       0xc87, 0x2, 0xc8e, 0x2, 0xc90, 0x2, 0xc92, 0x2, 0xc94, 0x2, 0xcaa, 
       0x2, 0xcac, 0x2, 0xcb5, 0x2, 0xcb7, 0x2, 0xcbb, 0x2, 0xcbf, 0x2, 
       0xcbf, 0x2, 0xce0, 0x2, 0xce0, 0x2, 0xce2, 0x2, 0xce3, 0x2, 0xcf3, 
       0x2, 0xcf4, 0x2, 0xd06, 0x2, 0xd0e, 0x2, 0xd10, 0x2, 0xd12, 0x2, 
       0xd14, 0x2, 0xd3c, 0x2, 0xd3f, 0x2, 0xd3f, 0x2, 0xd50, 0x2, 0xd50, 
       0x2, 0xd56, 0x2, 0xd58, 0x2, 0xd61, 0x2, 0xd63, 0x2, 0xd7c, 0x2, 
       0xd81, 0x2, 0xd87, 0x2, 0xd98, 0x2, 0xd9c, 0x2, 0xdb3, 0x2, 0xdb5, 
       0x2, 0xdbd, 0x2, 0xdbf, 0x2, 0xdbf, 0x2, 0xdc2, 0x2, 0xdc8, 0x2, 
       0xe03, 0x2, 0xe32, 0x2, 0xe34, 0x2, 0xe35, 0x2, 0xe42, 0x2, 0xe48, 
       0x2, 0xe83, 0x2, 0xe84, 0x2, 0xe86, 0x2, 0xe86, 0x2, 0xe88, 0x2, 
       0xe8c, 0x2, 0xe8e, 0x2, 0xea5, 0x2, 0xea7, 0x2, 0xea7, 0x2, 0xea9, 
       0x2, 0xeb2, 0x2, 0xeb4, 0x2, 0xeb5, 0x2, 0xebf, 0x2, 0xebf, 0x2, 
       0xec2, 0x2, 0xec6, 0x2, 0xec8, 0x2, 0xec8, 0x2, 0xede, 0x2, 0xee1, 
       0x2, 0xf02, 0x2, 0xf02, 0x2, 0xf42, 0x2, 0xf49, 0x2, 0xf4b, 0x2, 
       0xf6e, 0x2, 0xf8a, 0x2, 0xf8e, 0x2, 0x1002, 0x2, 0x102c, 0x2, 0x1041, 
       0x2, 0x1041, 0x2, 0x1052, 0x2, 0x1057, 0x2, 0x105c, 0x2, 0x105f, 
       0x2, 0x1063, 0x2, 0x1063, 0x2, 0x1067, 0x2, 0x1068, 0x2, 0x1070, 
       0x2, 0x1072, 0x2, 0x1077, 0x2, 0x1083, 0x2, 0x1090, 0x2, 0x1090, 
       0x2, 0x10a2, 0x2, 0x10c7, 0x2, 0x10c9, 0x2, 0x10c9, 0x2, 0x10cf, 
       0x2, 0x10cf, 0x2, 0x10d2, 0x2, 0x10fc, 0x2, 0x10fe, 0x2, 0x124a, 
       0x2, 0x124c, 0x2, 0x124f, 0x2, 0x1252, 0x2, 0x1258, 0x2, 0x125a, 
       0x2, 0x125a, 0x2, 0x125c, 0x2, 0x125f, 0x2, 0x1262, 0x2, 0x128a, 
       0x2, 0x128c, 0x2, 0x128f, 0x2, 0x1292, 0x2, 0x12b2, 0x2, 0x12b4, 
       0x2, 0x12b7, 0x2, 0x12ba, 0x2, 0x12c0, 0x2, 0x12c2, 0x2, 0x12c2, 
       0x2, 0x12c4, 0x2, 0x12c7, 0x2, 0x12ca, 0x2, 0x12d8, 0x2, 0x12da, 
       0x2, 0x1312, 0x2, 0x1314, 0x2, 0x1317, 0x2, 0x131a, 0x2, 0x135c, 
       0x2, 0x1382, 0x2, 0x1391, 0x2, 0x13a2, 0x2, 0x13f7, 0x2, 0x13fa, 
       0x2, 0x13ff, 0x2, 0x1403, 0x2, 0x166e, 0x2, 0x1671, 0x2, 0x1681, 
       0x2, 0x1683, 0x2, 0x169c, 0x2, 0x16a2, 0x2, 0x16ec, 0x2, 0x16f3, 
       0x2, 0x16fa, 0x2, 0x1702, 0x2, 0x170e, 0x2, 0x1710, 0x2, 0x1713, 
       0x2, 0x1722, 0x2, 0x1733, 0x2, 0x1742, 0x2, 0x1753, 0x2, 0x1762, 
       0x2, 0x176e, 0x2, 0x1770, 0x2, 0x1772, 0x2, 0x1782, 0x2, 0x17b5, 
       0x2, 0x17d9, 0x2, 0x17d9, 0x2, 0x17de, 0x2, 0x17de, 0x2, 0x1822, 
       0x2, 0x187a, 0x2, 0x1882, 0x2, 0x1886, 0x2, 0x1889, 0x2, 0x18aa, 
       0x2, 0x18ac, 0x2, 0x18ac, 0x2, 0x18b2, 0x2, 0x18f7, 0x2, 0x1902, 
       0x2, 0x1920, 0x2, 0x1952, 0x2, 0x196f, 0x2, 0x1972, 0x2, 0x1976, 
       0x2, 0x1982, 0x2, 0x19ad, 0x2, 0x19b2, 0x2, 0x19cb, 0x2, 0x1a02, 
       0x2, 0x1a18, 0x2, 0x1a22, 0x2, 0x1a56, 0x2, 0x1aa9, 0x2, 0x1aa9, 
       0x2, 0x1b07, 0x2, 0x1b35, 0x2, 0x1b47, 0x2, 0x1b4d, 0x2, 0x1b85, 
       0x2, 0x1ba2, 0x2, 0x1bb0, 0x2, 0x1bb1, 0x2, 0x1bbc, 0x2, 0x1be7, 
       0x2, 0x1c02, 0x2, 0x1c25, 0x2, 0x1c4f, 0x2, 0x1c51, 0x2, 0x1c5c, 
       0x2, 0x1c7f, 0x2, 0x1c82, 0x2, 0x1c8a, 0x2, 0x1c92, 0x2, 0x1cbc, 
       0x2, 0x1cbf, 0x2, 0x1cc1, 0x2, 0x1ceb, 0x2, 0x1cee, 0x2, 0x1cf0, 
       0x2, 0x1cf5, 0x2, 0x1cf7, 0x2, 0x1cf8, 0x2, 0x1cfc, 0x2, 0x1cfc, 
       0x2, 0x1d02, 0x2, 0x1dc1, 0x2, 0x1e02, 0x2, 0x1f17, 0x2, 0x1f1a, 
       0x2, 0x1f1f, 0x2, 0x1f22, 0x2, 0x1f47, 0x2, 0x1f4a, 0x2, 0x1f4f, 
       0x2, 0x1f52, 0x2, 0x1f59, 0x2, 0x1f5b, 0x2, 0x1f5b, 0x2, 0x1f5d, 
       0x2, 0x1f5d, 0x2, 0x1f5f, 0x2, 0x1f5f, 0x2, 0x1f61, 0x2, 0x1f7f, 
       0x2, 0x1f82, 0x2, 0x1fb6, 0x2, 0x1fb8, 0x2, 0x1fbe, 0x2, 0x1fc0, 
       0x2, 0x1fc0, 0x2, 0x1fc4, 0x2, 0x1fc6, 0x2, 0x1fc8, 0x2, 0x1fce, 
       0x2, 0x1fd2, 0x2, 0x1fd5, 0x2, 0x1fd8, 0x2, 0x1fdd, 0x2, 0x1fe2, 
       0x2, 0x1fee, 0x2, 0x1ff4, 0x2, 0x1ff6, 0x2, 0x1ff8, 0x2, 0x1ffe, 
       0x2, 0x2073, 0x2, 0x2073, 0x2, 0x2081, 0x2, 0x2081, 0x2, 0x2092, 
       0x2, 0x209e, 0x2, 0x2104, 0x2, 0x2104, 0x2, 0x2109, 0x2, 0x2109, 
       0x2, 0x210c, 0x2, 0x2115, 0x2, 0x2117, 0x2, 0x2117, 0x2, 0x211b, 
       0x2, 0x211f, 0x2, 0x2126, 0x2, 0x2126, 0x2, 0x2128, 0x2, 0x2128, 
       0x2, 0x212a, 0x2, 0x212a, 0x2, 0x212c, 0x2, 0x212f, 0x2, 0x2131, 
       0x2, 0x213b, 0x2, 0x213e, 0x2, 0x2141, 0x2, 0x2147, 0x2, 0x214b, 
       0x2, 0x2150, 0x2, 0x2150, 0x2, 0x2185, 0x2, 0x2186, 0x2, 0x2c02, 
       0x2, 0x2c30, 0x2, 0x2c32, 0x2, 0x2c60, 0x2, 0x2c62, 0x2, 0x2ce6, 
       0x2, 0x2ced, 0x2, 0x2cf0, 0x2, 0x2cf4, 0x2, 0x2cf5, 0x2, 0x2d02, 
       0x2, 0x2d27, 0x2, 0x2d29, 0x2, 0x2d29, 0x2, 0x2d2f, 0x2, 0x2d2f, 
       0x2, 0x2d32, 0x2, 0x2d69, 0x2, 0x2d71, 0x2, 0x2d71, 0x2, 0x2d82, 
       0x2, 0x2d98, 0x2, 0x2da2, 0x2, 0x2da8, 0x2, 0x2daa, 0x2, 0x2db0, 
       0x2, 0x2db2, 0x2, 0x2db8, 0x2, 0x2dba, 0x2, 0x2dc0, 0x2, 0x2dc2, 
       0x2, 0x2dc8, 0x2, 0x2dca, 0x2, 0x2dd0, 0x2, 0x2dd2, 0x2, 0x2dd8, 
       0x2, 0x2dda, 0x2, 0x2de0, 0x2, 0x2e31, 0x2, 0x2e31, 0x2, 0x3007, 
       0x2, 0x3008, 0x2, 0x3033, 0x2, 0x3037, 0x2, 0x303d, 0x2, 0x303e, 
       0x2, 0x3043, 0x2, 0x3098, 0x2, 0x309f, 0x2, 0x30a1, 0x2, 0x30a3, 
       0x2, 0x30fc, 0x2, 0x30fe, 0x2, 0x3101, 0x2, 0x3107, 0x2, 0x3131, 
       0x2, 0x3133, 0x2, 0x3190, 0x2, 0x31a2, 0x2, 0x31c1, 0x2, 0x31f2, 
       0x2, 0x3201, 0x2, 0x3402, 0x2, 0x4dc1, 0x2, 0x4e02, 0x2, 0x9ffe, 
       0x2, 0xa002, 0x2, 0xa48e, 0x2, 0xa4d2, 0x2, 0xa4ff, 0x2, 0xa502, 
       0x2, 0xa60e, 0x2, 0xa612, 0x2, 0xa621, 0x2, 0xa62c, 0x2, 0xa62d, 
       0x2, 0xa642, 0x2, 0xa670, 0x2, 0xa681, 0x2, 0xa69f, 0x2, 0xa6a2, 
       0x2, 0xa6e7, 0x2, 0xa719, 0x2, 0xa721, 0x2, 0xa724, 0x2, 0xa78a, 
       0x2, 0xa78d, 0x2, 0xa7c1, 0x2, 0xa7c4, 0x2, 0xa7cc, 0x2, 0xa7f7, 
       0x2, 0xa803, 0x2, 0xa805, 0x2, 0xa807, 0x2, 0xa809, 0x2, 0xa80c, 
       0x2, 0xa80e, 0x2, 0xa824, 0x2, 0xa842, 0x2, 0xa875, 0x2, 0xa884, 
       0x2, 0xa8b5, 0x2, 0xa8f4, 0x2, 0xa8f9, 0x2, 0xa8fd, 0x2, 0xa8fd, 
       0x2, 0xa8ff, 0x2, 0xa900, 0x2, 0xa90c, 0x2, 0xa927, 0x2, 0xa932, 
       0x2, 0xa948, 0x2, 0xa962, 0x2, 0xa97e, 0x2, 0xa986, 0x2, 0xa9b4, 
       0x2, 0xa9d1, 0x2, 0xa9d1, 0x2, 0xa9e2, 0x2, 0xa9e6, 0x2, 0xa9e8, 
       0x2, 0xa9f1, 0x2, 0xa9fc, 0x2, 0xaa00, 0x2, 0xaa02, 0x2, 0xaa2a, 
       0x2, 0xaa42, 0x2, 0xaa44, 0x2, 0xaa46, 0x2, 0xaa4d, 0x2, 0xaa62, 
       0x2, 0xaa78, 0x2, 0xaa7c, 0x2, 0xaa7c, 0x2, 0xaa80, 0x2, 0xaab1, 
       0x2, 0xaab3, 0x2, 0xaab3, 0x2, 0xaab7, 0x2, 0xaab8, 0x2, 0xaabb, 
       0x2, 0xaabf, 0x2, 0xaac2, 0x2, 0xaac2, 0x2, 0xaac4, 0x2, 0xaac4, 
       0x2, 0xaadd, 0x2, 0xaadf, 0x2, 0xaae2, 0x2, 0xaaec, 0x2, 0xaaf4, 
       0x2, 0xaaf6, 0x2, 0xab03, 0x2, 0xab08, 0x2, 0xab0b, 0x2, 0xab10, 
       0x2, 0xab13, 0x2, 0xab18, 0x2, 0xab22, 0x2, 0xab28, 0x2, 0xab2a, 
       0x2, 0xab30, 0x2, 0xab32, 0x2, 0xab5c, 0x2, 0xab5e, 0x2, 0xab6b, 
       0x2, 0xab72, 0x2, 0xabe4, 0x2, 0xac02, 0x2, 0xd7a5, 0x2, 0xd7b2, 
       0x2, 0xd7c8, 0x2, 0xd7cd, 0x2, 0xd7fd, 0x2, 0xf902, 0x2, 0xfa6f, 
       0x2, 0xfa72, 0x2, 0xfadb, 0x2, 0xfb02, 0x2, 0xfb08, 0x2, 0xfb15, 
       0x2, 0xfb19, 0x2, 0xfb1f, 0x2, 0xfb1f, 0x2, 0xfb21, 0x2, 0xfb2a, 
       0x2, 0xfb2c, 0x2, 0xfb38, 0x2, 0xfb3a, 0x2, 0xfb3e, 0x2, 0xfb40, 
       0x2, 0xfb40, 0x2, 0xfb42, 0x2, 0xfb43, 0x2, 0xfb45, 0x2, 0xfb46, 
       0x2, 0xfb48, 0x2, 0xfbb3, 0x2, 0xfbd5, 0x2, 0xfd3f, 0x2, 0xfd52, 
       0x2, 0xfd91, 0x2, 0xfd94, 0x2, 0xfdc9, 0x2, 0xfdf2, 0x2, 0xfdfd, 
       0x2, 0xfe72, 0x2, 0xfe76, 0x2, 0xfe78, 0x2, 0xfefe, 0x2, 0xff23, 
       0x2, 0xff3c, 0x2, 0xff43, 0x2, 0xff5c, 0x2, 0xff68, 0x2, 0xffc0, 
       0x2, 0xffc4, 0x2, 0xffc9, 0x2, 0xffcc, 0x2, 0xffd1, 0x2, 0xffd4, 
       0x2, 0xffd9, 0x2, 0xffdc, 0x2, 0xffde, 0x2, 0x2, 0x3, 0xd, 0x3, 0xf, 
       0x3, 0x28, 0x3, 0x2a, 0x3, 0x3c, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x41, 
       0x3, 0x4f, 0x3, 0x52, 0x3, 0x5f, 0x3, 0x82, 0x3, 0xfc, 0x3, 0x282, 
       0x3, 0x29e, 0x3, 0x2a2, 0x3, 0x2d2, 0x3, 0x302, 0x3, 0x321, 0x3, 
       0x32f, 0x3, 0x342, 0x3, 0x344, 0x3, 0x34b, 0x3, 0x352, 0x3, 0x377, 
       0x3, 0x382, 0x3, 0x39f, 0x3, 0x3a2, 0x3, 0x3c5, 0x3, 0x3ca, 0x3, 
       0x3d1, 0x3, 0x402, 0x3, 0x49f, 0x3, 0x4b2, 0x3, 0x4d5, 0x3, 0x4da, 
       0x3, 0x4fd, 0x3, 0x502, 0x3, 0x529, 0x3, 0x532, 0x3, 0x565, 0x3, 
       0x602, 0x3, 0x738, 0x3, 0x742, 0x3, 0x757, 0x3, 0x762, 0x3, 0x769, 
       0x3, 0x802, 0x3, 0x807, 0x3, 0x80a, 0x3, 0x80a, 0x3, 0x80c, 0x3, 
       0x837, 0x3, 0x839, 0x3, 0x83a, 0x3, 0x83e, 0x3, 0x83e, 0x3, 0x841, 
       0x3, 0x857, 0x3, 0x862, 0x3, 0x878, 0x3, 0x882, 0x3, 0x8a0, 0x3, 
       0x8e2, 0x3, 0x8f4, 0x3, 0x8f6, 0x3, 0x8f7, 0x3, 0x902, 0x3, 0x917, 
       0x3, 0x922, 0x3, 0x93b, 0x3, 0x982, 0x3, 0x9b9, 0x3, 0x9c0, 0x3, 
       0x9c1, 0x3, 0xa02, 0x3, 0xa02, 0x3, 0xa12, 0x3, 0xa15, 0x3, 0xa17, 
       0x3, 0xa19, 0x3, 0xa1b, 0x3, 0xa37, 0x3, 0xa62, 0x3, 0xa7e, 0x3, 
       0xa82, 0x3, 0xa9e, 0x3, 0xac2, 0x3, 0xac9, 0x3, 0xacb, 0x3, 0xae6, 
       0x3, 0xb02, 0x3, 0xb37, 0x3, 0xb42, 0x3, 0xb57, 0x3, 0xb62, 0x3, 
       0xb74, 0x3, 0xb82, 0x3, 0xb93, 0x3, 0xc02, 0x3, 0xc4a, 0x3, 0xc82, 
       0x3, 0xcb4, 0x3, 0xcc2, 0x3, 0xcf4, 0x3, 0xd02, 0x3, 0xd25, 0x3, 
       0xe82, 0x3, 0xeab, 0x3, 0xeb2, 0x3, 0xeb3, 0x3, 0xf02, 0x3, 0xf1e, 
       0x3, 0xf29, 0x3, 0xf29, 0x3, 0xf32, 0x3, 0xf47, 0x3, 0xfb2, 0x3, 
       0xfc6, 0x3, 0xfe2, 0x3, 0xff8, 0x3, 0x1005, 0x3, 0x1039, 0x3, 0x1085, 
       0x3, 0x10b1, 0x3, 0x10d2, 0x3, 0x10ea, 0x3, 0x1105, 0x3, 0x1128, 
       0x3, 0x1146, 0x3, 0x1146, 0x3, 0x1149, 0x3, 0x1149, 0x3, 0x1152, 
       0x3, 0x1174, 0x3, 0x1178, 0x3, 0x1178, 0x3, 0x1185, 0x3, 0x11b4, 
       0x3, 0x11c3, 0x3, 0x11c6, 0x3, 0x11dc, 0x3, 0x11dc, 0x3, 0x11de, 
       0x3, 0x11de, 0x3, 0x1202, 0x3, 0x1213, 0x3, 0x1215, 0x3, 0x122d, 
       0x3, 0x1282, 0x3, 0x1288, 0x3, 0x128a, 0x3, 0x128a, 0x3, 0x128c, 
       0x3, 0x128f, 0x3, 0x1291, 0x3, 0x129f, 0x3, 0x12a1, 0x3, 0x12aa, 
       0x3, 0x12b2, 0x3, 0x12e0, 0x3, 0x1307, 0x3, 0x130e, 0x3, 0x1311, 
       0x3, 0x1312, 0x3, 0x1315, 0x3, 0x132a, 0x3, 0x132c, 0x3, 0x1332, 
       0x3, 0x1334, 0x3, 0x1335, 0x3, 0x1337, 0x3, 0x133b, 0x3, 0x133f, 
       0x3, 0x133f, 0x3, 0x1352, 0x3, 0x1352, 0x3, 0x135f, 0x3, 0x1363, 
       0x3, 0x1402, 0x3, 0x1436, 0x3, 0x1449, 0x3, 0x144c, 0x3, 0x1461, 
       0x3, 0x1463, 0x3, 0x1482, 0x3, 0x14b1, 0x3, 0x14c6, 0x3, 0x14c7, 
       0x3, 0x14c9, 0x3, 0x14c9, 0x3, 0x1582, 0x3, 0x15b0, 0x3, 0x15da, 
       0x3, 0x15dd, 0x3, 0x1602, 0x3, 0x1631, 0x3, 0x1646, 0x3, 0x1646, 
       0x3, 0x1682, 0x3, 0x16ac, 0x3, 0x16ba, 0x3, 0x16ba, 0x3, 0x1702, 
       0x3, 0x171c, 0x3, 0x1802, 0x3, 0x182d, 0x3, 0x18a2, 0x3, 0x18e1, 
       0x3, 0x1901, 0x3, 0x1908, 0x3, 0x190b, 0x3, 0x190b, 0x3, 0x190e, 
       0x3, 0x1915, 0x3, 0x1917, 0x3, 0x1918, 0x3, 0x191a, 0x3, 0x1931, 
       0x3, 0x1941, 0x3, 0x1941, 0x3, 0x1943, 0x3, 0x1943, 0x3, 0x19a2, 
       0x3, 0x19a9, 0x3, 0x19ac, 0x3, 0x19d2, 0x3, 0x19e3, 0x3, 0x19e3, 
       0x3, 0x19e5, 0x3, 0x19e5, 0x3, 0x1a02, 0x3, 0x1a02, 0x3, 0x1a0d, 
       0x3, 0x1a34, 0x3, 0x1a3c, 0x3, 0x1a3c, 0x3, 0x1a52, 0x3, 0x1a52, 
       0x3, 0x1a5e, 0x3, 0x1a8b, 0x3, 0x1a9f, 0x3, 0x1a9f, 0x3, 0x1ac2, 
       0x3, 0x1afa, 0x3, 0x1c02, 0x3, 0x1c0a, 0x3, 0x1c0c, 0x3, 0x1c30, 
       0x3, 0x1c42, 0x3, 0x1c42, 0x3, 0x1c74, 0x3, 0x1c91, 0x3, 0x1d02, 
       0x3, 0x1d08, 0x3, 0x1d0a, 0x3, 0x1d0b, 0x3, 0x1d0d, 0x3, 0x1d32, 
       0x3, 0x1d48, 0x3, 0x1d48, 0x3, 0x1d62, 0x3, 0x1d67, 0x3, 0x1d69, 
       0x3, 0x1d6a, 0x3, 0x1d6c, 0x3, 0x1d8b, 0x3, 0x1d9a, 0x3, 0x1d9a, 
       0x3, 0x1ee2, 0x3, 0x1ef4, 0x3, 0x1fb2, 0x3, 0x1fb2, 0x3, 0x2002, 
       0x3, 0x239b, 0x3, 0x2482, 0x3, 0x2545, 0x3, 0x3002, 0x3, 0x3430, 
       0x3, 0x4402, 0x3, 0x4648, 0x3, 0x6802, 0x3, 0x6a3a, 0x3, 0x6a42, 
       0x3, 0x6a60, 0x3, 0x6ad2, 0x3, 0x6aef, 0x3, 0x6b02, 0x3, 0x6b31, 
       0x3, 0x6b42, 0x3, 0x6b45, 0x3, 0x6b65, 0x3, 0x6b79, 0x3, 0x6b7f, 
       0x3, 0x6b91, 0x3, 0x6e42, 0x3, 0x6e81, 0x3, 0x6f02, 0x3, 0x6f4c, 
       0x3, 0x6f52, 0x3, 0x6f52, 0x3, 0x6f95, 0x3, 0x6fa1, 0x3, 0x6fe2, 
       0x3, 0x6fe3, 0x3, 0x6fe5, 0x3, 0x6fe5, 0x3, 0x7002, 0x3, 0x87f9, 
       0x3, 0x8802, 0x3, 0x8cd7, 0x3, 0x8d02, 0x3, 0x8d0a, 0x3, 0xb002, 
       0x3, 0xb120, 0x3, 0xb152, 0x3, 0xb154, 0x3, 0xb166, 0x3, 0xb169, 
       0x3, 0xb172, 0x3, 0xb2fd, 0x3, 0xbc02, 0x3, 0xbc6c, 0x3, 0xbc72, 
       0x3, 0xbc7e, 0x3, 0xbc82, 0x3, 0xbc8a, 0x3, 0xbc92, 0x3, 0xbc9b, 
       0x3, 0xd402, 0x3, 0xd456, 0x3, 0xd458, 0x3, 0xd49e, 0x3, 0xd4a0, 
       0x3, 0xd4a1, 0x3, 0xd4a4, 0x3, 0xd4a4, 0x3, 0xd4a7, 0x3, 0xd4a8, 
       0x3, 0xd4ab, 0x3, 0xd4ae, 0x3, 0xd4b0, 0x3, 0xd4bb, 0x3, 0xd4bd, 
       0x3, 0xd4bd, 0x3, 0xd4bf, 0x3, 0xd4c5, 0x3, 0xd4c7, 0x3, 0xd507, 
       0x3, 0xd509, 0x3, 0xd50c, 0x3, 0xd50f, 0x3, 0xd516, 0x3, 0xd518, 
       0x3, 0xd51e, 0x3, 0xd520, 0x3, 0xd53b, 0x3, 0xd53d, 0x3, 0xd540, 
       0x3, 0xd542, 0x3, 0xd546, 0x3, 0xd548, 0x3, 0xd548, 0x3, 0xd54c, 
       0x3, 0xd552, 0x3, 0xd554, 0x3, 0xd6a7, 0x3, 0xd6aa, 0x3, 0xd6c2, 
       0x3, 0xd6c4, 0x3, 0xd6dc, 0x3, 0xd6de, 0x3, 0xd6fc, 0x3, 0xd6fe, 
       0x3, 0xd716, 0x3, 0xd718, 0x3, 0xd736, 0x3, 0xd738, 0x3, 0xd750, 
       0x3, 0xd752, 0x3, 0xd770, 0x3, 0xd772, 0x3, 0xd78a, 0x3, 0xd78c, 
       0x3, 0xd7aa, 0x3, 0xd7ac, 0x3, 0xd7c4, 0x3, 0xd7c6, 0x3, 0xd7cd, 
       0x3, 0xe102, 0x3, 0xe12e, 0x3, 0xe139, 0x3, 0xe13f, 0x3, 0xe150, 
       0x3, 0xe150, 0x3, 0xe2c2, 0x3, 0xe2ed, 0x3, 0xe802, 0x3, 0xe8c6, 
       0x3, 0xe902, 0x3, 0xe945, 0x3, 0xe94d, 0x3, 0xe94d, 0x3, 0xee02, 
       0x3, 0xee05, 0x3, 0xee07, 0x3, 0xee21, 0x3, 0xee23, 0x3, 0xee24, 
       0x3, 0xee26, 0x3, 0xee26, 0x3, 0xee29, 0x3, 0xee29, 0x3, 0xee2b, 
       0x3, 0xee34, 0x3, 0xee36, 0x3, 0xee39, 0x3, 0xee3b, 0x3, 0xee3b, 
       0x3, 0xee3d, 0x3, 0xee3d, 0x3, 0xee44, 0x3, 0xee44, 0x3, 0xee49, 
       0x3, 0xee49, 0x3, 0xee4b, 0x3, 0xee4b, 0x3, 0xee4d, 0x3, 0xee4d, 
       0x3, 0xee4f, 0x3, 0xee51, 0x3, 0xee53, 0x3, 0xee54, 0x3, 0xee56, 
       0x3, 0xee56, 0x3, 0xee59, 0x3, 0xee59, 0x3, 0xee5b, 0x3, 0xee5b, 
       0x3, 0xee5d, 0x3, 0xee5d, 0x3, 0xee5f, 0x3, 0xee5f, 0x3, 0xee61, 
       0x3, 0xee61, 0x3, 0xee63, 0x3, 0xee64, 0x3, 0xee66, 0x3, 0xee66, 
       0x3, 0xee69, 0x3, 0xee6c, 0x3, 0xee6e, 0x3, 0xee74, 0x3, 0xee76, 
       0x3, 0xee79, 0x3, 0xee7b, 0x3, 0xee7e, 0x3, 0xee80, 0x3, 0xee80, 
       0x3, 0xee82, 0x3, 0xee8b, 0x3, 0xee8d, 0x3, 0xee9d, 0x3, 0xeea3, 
       0x3, 0xeea5, 0x3, 0xeea7, 0x3, 0xeeab, 0x3, 0xeead, 0x3, 0xeebd, 
       0x3, 0x2, 0x4, 0xa6df, 0x4, 0xa702, 0x4, 0xb736, 0x4, 0xb742, 0x4, 
       0xb81f, 0x4, 0xb822, 0x4, 0xcea3, 0x4, 0xceb2, 0x4, 0xebe2, 0x4, 
       0xf802, 0x4, 0xfa1f, 0x4, 0x2, 0x5, 0x134c, 0x5, 0x7d, 0x2, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 0x3, 
       0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x3, 0x2, 
       0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 0xf, 0x3, 0x2, 0x2, 
       0x2, 0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 
       0x2, 0x15, 0x3, 0x2, 0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x2, 
       0x19, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1d, 
       0x3, 0x2, 0x2, 0x2, 0x3, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x5, 0x31, 0x3, 
       0x2, 0x2, 0x2, 0x7, 0x33, 0x3, 0x2, 0x2, 0x2, 0x9, 0x35, 0x3, 0x2, 
       0x2, 0x2, 0xb, 0x37, 0x3, 0x2, 0x2, 0x2, 0xd, 0x39, 0x3, 0x2, 0x2, 
       0x2, 0xf, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x11, 0x3e, 0x3, 0x2, 0x2, 0x2, 
       0x13, 0x40, 0x3, 0x2, 0x2, 0x2, 0x15, 0x43, 0x3, 0x2, 0x2, 0x2, 0x17, 
       0x49, 0x3, 0x2, 0x2, 0x2, 0x19, 0x58, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x5e, 
       0x3, 0x2, 0x2, 0x2, 0x1d, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x73, 0x3, 
       0x2, 0x2, 0x2, 0x21, 0x75, 0x3, 0x2, 0x2, 0x2, 0x23, 0x77, 0x3, 0x2, 
       0x2, 0x2, 0x25, 0x26, 0x7, 0x54, 0x2, 0x2, 0x26, 0x27, 0x7, 0x77, 
       0x2, 0x2, 0x27, 0x28, 0x7, 0x6e, 0x2, 0x2, 0x28, 0x29, 0x7, 0x67, 
       0x2, 0x2, 0x29, 0x30, 0x7, 0x75, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x74, 
       0x2, 0x2, 0x2b, 0x2c, 0x7, 0x77, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x6e, 
       0x2, 0x2, 0x2d, 0x2e, 0x7, 0x67, 0x2, 0x2, 0x2e, 0x30, 0x7, 0x75, 
       0x2, 0x2, 0x2f, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2a, 0x3, 0x2, 0x2, 
       0x2, 0x30, 0x4, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x7d, 0x2, 0x2, 
       0x32, 0x6, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x7f, 0x2, 0x2, 0x34, 
       0x8, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x7, 0x5d, 0x2, 0x2, 0x36, 0xa, 
       0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x5f, 0x2, 0x2, 0x38, 0xc, 0x3, 
       0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x2f, 0x2, 0x2, 0x3a, 0x3b, 0x7, 
       0x40, 0x2, 0x2, 0x3b, 0xe, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x30, 
       0x2, 0x2, 0x3d, 0x10, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x2e, 
       0x2, 0x2, 0x3f, 0x12, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x7, 0x3d, 
       0x2, 0x2, 0x41, 0x14, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 0x9, 0x2, 0x2, 
       0x2, 0x43, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 
       0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x8, 0xb, 0x2, 0x2, 0x48, 0x16, 
       0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x31, 0x2, 0x2, 0x4a, 0x4b, 
       0x7, 0x2c, 0x2, 0x2, 0x4b, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 
       0xb, 0x2, 0x2, 0x2, 0x4d, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x3, 
       0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 
       0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 
       0x2, 0x52, 0x53, 0x7, 0x2c, 0x2, 0x2, 0x53, 0x54, 0x7, 0x31, 0x2, 
       0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x8, 0xc, 0x2, 0x2, 
       0x56, 0x18, 0x3, 0x2, 0x2, 0x2, 0x57, 0x59, 0x9, 0x3, 0x2, 0x2, 0x58, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 
       0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 
       0x2, 0x2, 0x2, 0x5c, 0x5d, 0x8, 0xd, 0x2, 0x2, 0x5d, 0x1a, 0x3, 0x2, 
       0x2, 0x2, 0x5e, 0x5f, 0x7, 0x31, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x31, 
       0x2, 0x2, 0x60, 0x64, 0x3, 0x2, 0x2, 0x2, 0x61, 0x63, 0xa, 0x3, 0x2, 
       0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 
       0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 
       0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
       0x8, 0xe, 0x2, 0x2, 0x68, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6e, 0x5, 
       0x1f, 0x10, 0x2, 0x6a, 0x6d, 0x5, 0x1f, 0x10, 0x2, 0x6b, 0x6d, 0x5, 
       0x21, 0x11, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6b, 0x3, 
       0x2, 0x2, 0x2, 0x6d, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 
       0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x1e, 0x3, 0x2, 0x2, 
       0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x74, 0x5, 0x23, 0x12, 
       0x2, 0x72, 0x74, 0x7, 0x61, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 
       0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x20, 0x3, 0x2, 0x2, 0x2, 
       0x75, 0x76, 0x9, 0x4, 0x2, 0x2, 0x76, 0x22, 0x3, 0x2, 0x2, 0x2, 0x77, 
       0x78, 0x9, 0x5, 0x2, 0x2, 0x78, 0x24, 0x3, 0x2, 0x2, 0x2, 0xb, 0x2, 
       0x2f, 0x45, 0x4f, 0x5a, 0x64, 0x6c, 0x6e, 0x73, 0x3, 0x2, 0x3, 0x2, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

BindingLexer::Initializer BindingLexer::_init;