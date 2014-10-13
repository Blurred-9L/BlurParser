/**
 *  @author Blurred-9L
 *  @file   Token.cpp
 */

#include "Token.h"

/**
 *  @details    Constructs a Token object.
 *
 *  @param[in]  type            The token's type.
 *  @param[in]  symbol          The token's string.
 */
Token::Token(int type, const string & symbol) :
    type_(type), symbol_(symbol)
{
}

/**
 *  @details    Gets the type attribute from the token.
 *
 *  @return     The value of the type attribute.
 */
int Token::type() const
{
    return type_;
}

/**
 *  @details    Gets the attribute field from the token.
 *
 *  @return     A constant reference to the token's symbol attribute. 
 */
const string & Token::symbol() const
{
    return symbol_;
}

/**
 *  @details    Gets the symbol attribute from the token.
 *
 *  @return     A reference to the token's symbol attribute.
 */
string & Token::symbol()
{
    return symbol_;
}

/**
 *  @details    Sets the token's type attribute.
 *
 *  @param[in]  type            The type of the token.
 */
void Token::setType(int type)
{
    type_ = type;
}

/**
 *  @details    Sets the token's symbol attribute.
 *
 *  @param[in]  symbol          The string of the token.
 */
void Token::setSymbol(const string & symbol)
{
    symbol_ = symbol;
}
