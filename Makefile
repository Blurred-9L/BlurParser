CORE_OBJECTS = Core/ErrorData.o \
			   Core/ErrorKeeper.o \
			   Core/LineFileReader.o \
			   Core/SyntaxNode.o \
			   Core/Token.o \
			   Core/TokenData.o

TOKENIZER_OBJS = Tokenizer/AbstractAutomata.o \
				 Tokenizer/KeywordSet.o \
				 Tokenizer/Tokenizer.o
				 
PARSER_OBJS = Parser/Parser.o \
              Parser/ParserTable.o \
              Parser/ParserTableAction.o \
              Parser/ParserTableKey.o
				 
OBJECTS = ErrorData.o \
          ErrorKeeper.o \
          LineFileReader.o \
          SyntaxNode.o \
          Token.o \
          TokenData.o \
          AbstractAutomata.o \
          KeywordSet.o \
          Tokenizer.o \
          Parser.o \
          ParserTable.o \
          ParserTableAction.o \
          ParserTableKey.o \
               
CFLAGS = -Wall -Wextra

all: core tokenizer parser

core: $(CORE_OBJECTS)

tokenizer: $(TOKENIZER_OBJS)

parser: $(PARSER_OBJS)

Core/ErrorData.o: Core/ErrorData.cpp
	g++ -c $(CFLAGS) Core/ErrorData.cpp

Core/ErrorKeeper.o: Core/ErrorKeeper.cpp
	g++ -c $(CFLAGS) Core/ErrorKeeper.cpp

Core/LineFileReader.o: Core/LineFileReader.cpp
	g++ -c $(CFLAGS) Core/LineFileReader.cpp

Core/SyntaxNode.o: Core/SyntaxNode.cpp
	g++ -c $(CFLAGS) Core/SyntaxNode.cpp

Core/Token.o: Core/Token.cpp
	g++ -c $(CFLAGS) Core/Token.cpp

Core/TokenData.o: Core/TokenData.cpp
	g++ -c $(CFLAGS) Core/TokenData.cpp

Tokenizer/AbstractAutomata.o: Tokenizer/AbstractAutomata.cpp
	g++ -c $(CFLAGS) Tokenizer/AbstractAutomata.cpp

Tokenizer/KeywordSet.o: Tokenizer/KeywordSet.cpp
	g++ -c Tokenizer/KeywordSet.cpp

Tokenizer/Tokenizer.o: Tokenizer/Tokenizer.cpp
	g++ -c $(CFLAGS) Tokenizer/Tokenizer.cpp
	
Parser/Parser.o: Parser/Parser.cpp
	g++ -c Parser/Parser.cpp
	
Parser/ParserTable.o: Parser/ParserTable.cpp
	g++ -c $(CFLAGS) Parser/ParserTable.cpp
	
Parser/ParserTableAction.o: Parser/ParserTableAction.cpp
	g++ -c $(CFLAGS) Parser/ParserTableAction.cpp
	
Parser/ParserTableKey.o: Parser/ParserTableKey.cpp
	g++ -c $(CFLAGS) Parser/ParserTableKey.cpp

clean:
	rm -f $(OBJECTS)

