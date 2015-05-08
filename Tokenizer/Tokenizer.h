/**
 *  @author Blurred-9L
 *  @file   Tokenizer.h
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
using std::string;

#include "../Core/TokenData.h"

class AbstractAutomata;
class KeywordSet;
class LineFileReader;
class ErrorKeeper;
class Token;

#define LEXIC_INPUT_ERROR     -1
#define TOKEN_NO_END_ERROR    -2

/**
 *  @class  Tokenizer
 *
 *  @brief  Object used to obtain tokens from a string
 *          according to an finite automata and a keyword
 *          set.
 */
class Tokenizer {
private:
    /// The tokenizer's related finite automata.
    AbstractAutomata * automata_;
    /// The tokenizer's related keyword set.
    KeywordSet * keywords_;
    /// The tokenizer's related file reader object.
    LineFileReader * lineReader_;
    /// The tokenizer's related error keeper object.
    ErrorKeeper * errorKeeper_;
    /// The line to be tokenized.
    string line_;
    /// The index of the current char analyzed.
    int charIdx;
    /// The index at which the current token started.
    int tokenStartIndex;
    /// The line on which the current token was found.
    int tokenLineNumber_;

    /// Gets the data to partition the line where the next token is found
    TokenData buildToken();
    /// Checks if a string only contains whitespaces.
    bool spaceOnlyLine();
    /// Loads another line
    void loadNextLine();

public:
    /// Tokenizer defualt constructor.
    Tokenizer();
    /// Tokenizer constructor.
    Tokenizer(AbstractAutomata * automata, KeywordSet * keywords,
              LineFileReader * lineReader = 0, ErrorKeeper * errorKeeper = 0);
    /// Tokenizer destructor.
    ~Tokenizer();
    /// Gets the automata used by this tokenizer.
    const AbstractAutomata & automata() const;
    /// Gets the automata used by this tokenizer.
    AbstractAutomata & automata();
    /// Gets the keyword set used by this tokenizer.
    const KeywordSet & keywords() const;
    /// Gets the keyword set used by this tokenizer.
    KeywordSet & keywords();
    /// Gets the line reader used by this tokenizer.
    const LineFileReader * lineReader() const;
    /// Gets the line reader used by this tokenizer.
    LineFileReader * lineReader();
    /// Gets the error keeper used by this tokenizer.
    const ErrorKeeper * errorKeeper() const;
    /// Gets the error keeper usedd by this tokenizer.
    ErrorKeeper * errorKeeper();
    /// Gets the line number.
    int tokenLineNumber() const;
    /// Sets the automata used on this tokenizer.
    void setAutomata(AbstractAutomata * automata);
    /// Sets the keyword set used on this tokenizer
    void setKeywords(KeywordSet * keywords);
    /// Sets the line reader used by this tokenizer.
    void setLineReader(LineFileReader * lineReader);
    /// Sets the error keeper used by this tokenizer.
    void setErrorKeeper(ErrorKeeper * errorKeeper);
    /// Sets the line to be analyzed.
    void setLine(const string & line);
    /// Sets the line number.
    void setTokenLineNumber(int tokenLineNumber);
    /// Gets the next token from the line.
    Token * getToken();
    /// Checks if an error has ocurred.
    bool hasError() const;
};

#endif /// NOT TOKENIZER_H
