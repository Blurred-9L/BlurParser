/**
 *  @author Blurred-9L
 *  @file   Tokenizer.h
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
using std::string;

class AbstractAutomata;
class KeywordSet;
class Token;

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
    /// The line to be tokenized.
    string line_;
    /// The index of the current char analyzed.
    int charIdx;

    /// Gets the string to be used on the next token.
    int getTokenString(string & symbol);

public:
    /// Tokenizer defualt constructor.
    Tokenizer();
    /// Tokenizer constructor.
    Tokenizer(AbstractAutomata * automata, KeywordSet * keywords);
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
    /// Sets the automata used on this tokenizer.
    void setAutomata(AbstractAutomata * automata);
    /// Sets the keyword set used on this tokenizer
    void setKeywords(KeywordSet * keywords);
    /// Sets the line to be analyzed.
    void setLine(const string & line);
    /// Gets the next token from the line.
    Token * getToken();
};

#endif /// NOT TOKENIZER_H