#include "TokenData.h"

/**
 *  @details    Constructs a TokenData object in an invalid state.
 */
TokenData::TokenData() : start_(-1), length_(-1), state_(-1) {}

/**
 *  @details    Constructs a TokenData object.
 *
 *  @param[in]  start           The start index of the token
 *  @param[in]  length          The length of the token
 *  @param[in]  state           The last state before ending the token
 */
TokenData::TokenData(int start, int length, int state) :
    start_(start), length_(length), state_(state) {}
    
/**
 *  @details    Gets the start attribute of the TokenData object.
 *
 *  @return     The start index of the token.
 */
int TokenData::start() const
{
    return start_;
}

/**
 *  @details    Gets the length attribute of the TokenData object.
 *
 *  @return     The length of the token.
 */
int TokenData::length() const
{
    return length_;
}

/**
 *  @details    Gets the state attribute of the TokenData object.
 *
 *  @return     The last visited state before finding an invalid state for the token creation.
 */
int TokenData::state() const
{
    return state_;
}
