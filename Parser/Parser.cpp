/**
 *  @author Blurred-9L
 *  @file   Parser.cpp
 */

#include "Parser.h"
#include "ParserTable.h"
#include "ParserTableKey.h"
#include "ParserTableAction.h"
#include "../Tokenizer/Tokenizer.h"
#include "../Core/Token.h"
#include "../Core/SyntaxNode.h"

/**
 *  @details    Constructs a Parser object without any tokenizer or
 *              LR table to use. These should be set before a call
 *              to the parse() method, as well as the end-of-input
 *              value to be used during parsing.
 */
Parser::Parser() :
    table_(0), tokenizer_(0), curToken(0), endOfInput_(-1), errorRaised_(false)
{
}

/**
 *  @details    Constructs a Parser object with the given LR Table and
 *              Tokenizer objects. These two objects should be dynamically
 *              allocated, as this object will make sure they are properly
 *              deleted when this object is destroyed. The end-of-input
 *              value should still be set before calling parse().
 *
 *  @param[in]  table           The LR Table to use.
 *  @param[in]  tokenizer       The Tokenizer to use.
 */
Parser::Parser(ParserTable * table, Tokenizer * tokenizer) :
    table_(table), tokenizer_(tokenizer), curToken(0), endOfInput_(-1), errorRaised_(false)
{
}

/**
 *  @details    Destroys a Parser object. Deallocates the table and
 *              tokenizer attributes, as well as emptying both the
 *              states and symbols stacks. If the syntax tree root
 *              was recovered, the user should make sure it is popped
 *              from the symbols stack or its value is set to 0,
 *              as the destructor will try to deallocate all SyntaxNode
 *              objects on the symbols stack.
 */
Parser::~Parser()
{
    if (table_ != 0) {
        delete table_;
    }
    if (tokenizer_ != 0) {
        delete tokenizer_;
    }
    while (!states.empty()) { states.pop(); }
    while (!symbols.empty()) {
        SyntaxNode * node = symbols.top();
        if (node != 0) { delete node; }
        symbols.pop(); 
    }
}

/**
 *  @details    Gets the LR Table related to this Parser.
 *
 *  @return     A constant reference to the ParserTable object.
 */
const ParserTable & Parser::table() const
{
    return *table_;
}

/**
 *  @details    Gets the LR Table related to this Parser.
 *
 *  @return     A reference to the ParserTable object.
 */
ParserTable & Parser::table()
{
    return *table_;
}

/**
 *  @details    Gets the Tokenizer object related to this Parser.
 *
 *  @return     A constant reference to the Tokenizer object.
 */
const Tokenizer & Parser::tokenizer() const
{
    return *tokenizer_;
}

/**
 *  @details    Gets the Tokenizer object related to this Parser.
 *
 *  @return     A reference to the Tokenizer object.
 */
Tokenizer & Parser::tokenizer()
{
    return *tokenizer_;
}

/**
 *  @details    Gets the value used as the end-of-input on this Parser.
 *
 *  @return     The value used as end-of-input.
 */
int Parser::endOfInput() const
{
    return endOfInput_;
}

/**
 *  @details    Sets the LR Table to be used during parsing. This object
 *              should be dynamically allocated, as the Parser will
 *              own this object. The previous ParserTable object will
 *              be deallocated if possible.
 *
 *  @param[in]  table           The LR Table to use.
 */
void Parser::setTable(ParserTable * table)
{
    if (table != 0) {
        if (table_ != 0) {
            delete table_;
        }
        table_ = table;
    }
}

/**
 *  @details    Sets the Tokenizer to be used during parsing. This object
 *              should be dynamically allocated, as the Parser will
 *              own this object. The previous Tokenizer object will be
 *              deallocated if possible.
 *
 *  @param[in]  tokenizer       The tokenizer to use.
 */
void Parser::setTokenizer(Tokenizer * tokenizer)
{
    if (tokenizer != 0) {
        if (tokenizer_ != 0) {
            delete tokenizer_;
        }
        tokenizer_ = tokenizer;
    }
}

/**
 *  @details    Sets the end-of-input value to be used during parsing.
 *
 *  @param[in]  endOfInput      The end-of-input value.
 */
void Parser::setEndOfInput(int endOfInput)
{
    endOfInput_ = endOfInput;
}

/**
 *  @details    Parses the input, determining if it is properly written
 *              according to the syntax represented on the LR table.
 *              A tokenizer is used to obtain tokens from the input.
 *              If the proper methods are overriden properly, it will
 *              also create a SyntaxTree as a result of the parsing,
 *              and it will be available on the top of the symbols
 *              stack. This method can be overriden.
 *
 *  @return     A boolean value indicating if the line was syntactically
 *              correct.
 */
bool Parser::parse()
{
    bool done = false;
    bool ok;
    
    while (!states.empty()) { states.pop(); }
    while (!symbols.empty()) { symbols.pop(); }
    states.push(0);
    errorRaised_ = false;
    
    curToken = tokenizer_->getToken();
    while (!errorRaised_ && !done) {
        if (curToken != 0) {
            done = doAction(states.top(), curToken->type());
        } else {
            done = doAction(states.top(), endOfInput_);
        }
    }
    
    if (errorRaised_) {
        ok = false;
    } else if (done) {
        ok = true;
    }
    
    return ok;
}

///////////////
// Protected //
///////////////

/**
 *  @details    Tries to find the action related to the given
 *              state and token type, and tries to apply it.
 *
 *  @param[in]  state           The current state used to create a key.
 *  @param[in]  tokenType       The current token type used to create a key.
 *
 *  @return     A boolean value indicating if applying the action
 *              resulted in determining that the line was parsed correctly.
 */
bool Parser::doAction(int state, int tokenType) {
    ParserTableKey key(state, tokenType);
    ParserTableAction * action;
    bool done = false;
    
    if (table_->hasKey(key)) {
        action = table_->getAction(key);
        done = applyAction(action);
        delete action;
    } else {
        raiseError(UNEXPECTED_TOKEN_ERROR, "Could not find transition according to input given.");
    }
    
    return done;
}

/**
 *  @details    Applies an action obtained, either by accepting the
 *              line, pushing states and symbols onto the stacks or
 *              reducing the stacks.
 *
 *  @param[in]  action          The action to be applied.
 *
 *  @return     A boolean value indicating if the action applied
 *              was the ACCEPT action.
 */
bool Parser::applyAction(ParserTableAction * action)
{
    bool done = false;
    
    switch (action->type()) {
    case ParserTable::SHIFT:
        states.push(action->value());
        symbols.push(toSyntaxNode(curToken));
        curToken = tokenizer_->getToken();
        break;
    case ParserTable::REDUCE:
        done = applyReduction(action->value());
        break;
    case ParserTable::CHANGE:
        raiseError(FATAL_ERROR, "Reached part of code that shouldn't be reached.");
        break;
    case ParserTable::ACCEPT:
        done = true;
        break;
    }
    
    return done;
}

/**
 *  @details    Applies the reduction to the stacks by removing
 *              an amount of elements depending on the rule given.
 *              The amount of elements removed depends on the
 *              length of the rule applied.
 *
 *  @param[in]  ruleNumber      The number of the rule used for reduction.
 *
 *  @return     Returns false.
 */
bool Parser::applyReduction(int ruleNumber)
{
    ParserTableKey key;
    ParserTableAction * action;
    SyntaxNode * nextNode;
    int i, nonTermType, ruleLength;
    bool done = false;
    
    ruleLength = table_->getRuleLength(ruleNumber);
    for (i = 0; i < ruleLength; i++) {
        states.pop();
    }
    nextNode = reduce(ruleNumber);
    nonTermType = table_->getNonTerminalType(ruleNumber);
    
    key.setState(states.top());
    key.setTokenType(nonTermType);
    if (table_->hasKey(key)) {
        action = table_->getAction(key);
        states.push(action->value());
        symbols.push(nextNode);
        delete action;
    } else {
        raiseError(UNKNOWN_TRANSITION_ERROR, "Could not find transiton after applying reduction.");
    }
    
    return done;
}

/**
 *  @details    Raises an error by specifying an error code and
 *              a string describing the reason for the error. This method
 *              can be overriden and it is recommended to do so.
 *
 *  @param[in]  errorCode       The error code.
 *  @param[in]  what            The description of the error.
 */
void Parser::raiseError(int errorCode, const char * what)
{
    errorRaised_ = true;
}
