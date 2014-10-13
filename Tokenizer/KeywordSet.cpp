/**
 *  @author Blurred-9L
 *  @file   KeywordSet.cpp
 */

#include "KeywordSet.h"

const int KeywordSet::INVALID_ID = -1;

/**
 *  @details    Constructs a KeywordSet object.
 */
KeywordSet::KeywordSet()
{
}

/**
 *  @details    Destroys a KeywordSet object.
 */
KeywordSet::~KeywordSet()
{
}

/**
 *  @details    Checks if the given string is a keyword contained
 *              on the set.
 *
 *  @return     A boolean value indicating if symbol was found on the set or not.
 */
bool KeywordSet::isKeyword(const string & symbol) const
{
    return false;
}

/**
 *  @details    Gets the integer id-value related to the given string.
 *              This value should be defined on a subclass. If the
 *              given string is not a keyword contained in the set,
 *              this method should return #INVALID_ID. If the keyword set
 *              is to be used along the Tokenizer class, one must make sure
 *              the returned id does not conflict with the ids of tokens
 *              returned by the AbstractAutomata subclass used.
 *
 *  @return     The id of 
 */
int KeywordSet::getKeywordId(const string & symbol) const
{
    return INVALID_ID;
}
