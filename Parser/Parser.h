/**
 *  @author Blurred-9L
 *  @file   Parser.h
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>
using std::string;
#include <stack>
using std::stack;

class ParserTable;
class ParserTableAction;
class SyntaxNode;
class Tokenizer;
class Token;

/**
 *  @class  Parser
 *
 *  @brief  Base class for performing an syntactic analysis
 *          over a set of tokens. A syntax tree can be produced
 *          if the methods are overriden correctly.
 */
class Parser {
protected:
    /// The LR Table to use during parsing.
    ParserTable * table_;
    /// The tokenizer from which to obtain tokens.
    Tokenizer * tokenizer_;
    /// The curren token.
    Token * curToken;
    /// The value of the end-of-input token.
    int endOfInput_;
    /// Flag to signal errors.
    bool errorRaised_;
    /// The stack of states used during parsing.
    stack<int> states;
    /// The stack of symbols used during parsing.
    stack<SyntaxNode *> symbols;
    
    /// Tries to find the action to do with a pair (state, tokenType)
    virtual bool doAction(int state, int tokenType);
    /// Applies an action during parsing.
    virtual bool applyAction(ParserTableAction * action);
    /// Applies a specific reduction.
    virtual bool applyReduction(int ruleNumber);
    /// Gets the SyntaxNode wrapping a given token.
    virtual SyntaxNode * toSyntaxNode(Token * token) = 0;
    /// Reduces the stacks according to a grammar rule.
    virtual SyntaxNode * reduce(int ruleNumber) = 0;
    /// Raises an error.
    virtual void raiseError(const char * what);
    
public:
    /// Parser default constructor.
    Parser();
    /// Parser constructor.
    Parser(ParserTable * table, Tokenizer * tokenizer);
    /// Parser destructor.
    virtual ~Parser();
    /// Gets the parser's LR Table.
    const ParserTable & table() const;
    /// Gets the parser's LR Table.
    ParserTable & table();
    /// Gets the parser's tokenizer object.
    const Tokenizer & tokenizer() const;
    /// Gets the parser's tokenizer object.
    Tokenizer & tokenizer();
    /// Gets the value for the end-of-input token.
    int endOfInput() const;
    /// Sets the parser's LR Table.
    void setTable(ParserTable * table);
    /// Sets the parser's tokenizer object.
    void setTokenizer(Tokenizer * tokenizer);
    /// Sets the value to be used as end-of-input.
    void setEndOfInput(int endOfInput);
    /// Parses the given line.
    virtual bool parse(const string & line);
    /// Gets the root of the syntax tree.
    virtual SyntaxNode * getSyntaxTreeRoot() = 0;
};

#endif /// NOT PARSER_H
