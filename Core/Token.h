/**
 *  @author Blurred-9L
 *  @file   Token.h
 */

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using std::string;

/**
 *  @class  Token
 *
 *  @brief  Stores values to identify the type and
 *          related string to the token.
 */
class Token {
private:
    /// The token's type.
    int type_;
    /// The index on which the token starts.
    int start_;
    /// The line on which the token is found.
    int lineNumber_;
    /// The token's string.
    string symbol_;
    
public:
    /// Token constructor.
    Token(int type, int start, int lineNumber, const string & symbol);
    /// Gets the token's type.
    int type() const;
    /// Gets the token's start.
    int start() const;
    /// Gets the token's line number.
    int lineNumber() const;
    /// Gets the token's symbol.
    const string & symbol() const;
    /// Gets the token's symbol.
    string & symbol();
    /// Sets the token's type.
    void setType(int type);
    /// Sets the token's start.
    void setStart(int start);
    /// Sets the token's line number.
    void setLineNumber(int lineNumber);
    /// Sets the token's symbol.
    void setSymbol(const string & symbol);
};

#endif /// NOT TOKEN_H
