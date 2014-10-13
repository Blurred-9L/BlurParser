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
    /// The token's string.
    string symbol_;
    
public:
    /// Token constructor.
    Token(int type, const string & symbol);
    /// Gets the token's type.
    int type() const;
    /// Gets the token's symbol.
    const string & symbol() const;
    /// Gets the token's symbol.
    string & symbol();
    /// Sets the token's type.
    void setType(int type);
    /// Sets the token's symbol.
    void setSymbol(const string & symbol);
};

#endif /// NOT TOKEN_H
