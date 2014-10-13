/**
 *  @author Blurred-9L
 *  @file   ParserTableKey.cpp
 */

#include "ParserTableKey.h"

/**
 *  @details    Constructs a ParserTableKey object with invalid
 *              values on its attributes.
 */
ParserTableKey::ParserTableKey() :
    state_(-1), tokenType_(-1)
{
}

/**
 *  @details    Constructs a ParserTableKey object with the given
 *              state and token type.
 *
 *  @param[in]  state           The related state of the key.
 *  @param[in}  tokenType       The related token type of the key.
 */
ParserTableKey::ParserTableKey(int state, int tokenType) :
    state_(state), tokenType_(tokenType)
{
}

/**
 *  @details    Gets the key's state attribute.
 *
 *  @return     The value of the key's state attribute.
 */
int ParserTableKey::state() const
{
    return state_;
}

/**
 *  @details    Gets the key's token type attribute.
 *
 *  @return     The value of the key's token type attribute.
 */
int ParserTableKey::tokenType() const
{
    return tokenType_;
}

/**
 *  @details    Sets the key's state attribute.
 *
 *  @param[in]  state           The related state of the key.
 */
void ParserTableKey::setState(int state)
{
    state_ = state;
}

/**
 *  @details    Sets the key's token type attribute.
 *
 *  @param[in]  tokenType       The related token type of the key.
 */
void ParserTableKey::setTokenType(int tokenType)
{
    tokenType_ = tokenType;
}
