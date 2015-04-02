CORE_OBJECTS = Core/ErrorData.o \
			   Core/ErrorKeeper.o \
			   Core/LineFileReader.o \
			   Core/SyntaxNode.o \
			   Core/Token.o \
			   Core/TokenData.o

TOKENIZER_OBJS = Tokenizer/AbstractAutomata.o \
				 Tokenizer/KeywordSet.o \
				 Tokenizer/Tokenizer.o
				 
OBJECTS = ErrorData.o \
          ErrorKeeper.o \
          LineFileReader.o \
          SyntaxNode.o \
          Token.o \
          TokenData.o \
          AbstractAutomata.o \
          KeywordSet.o \
          Tokenizer.o
               
CFLAGS = -Wall -Wextra

all: core tokenizer

core: $(CORE_OBJECTS)

tokenizer: $(TOKENIZER_OBJS)

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

clean:
	rm -f $(OBJECTS)

