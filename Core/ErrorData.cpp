#include "ErrorData.h"

/**
 *  @details    Constructs an ErrorData object with default attributes.
 */
ErrorData::ErrorData() :
    errorCode_(0), errorString_()
{
}

/**
 *  @details    Constructs an ErrorData object and sets its attributes
 *              to the specified error code and string.
 *
 *  @param[in]  errorCode       The error code.
 *  @param[in]  errorString     The error description.
 */
ErrorData::ErrorData(int errorCode, const char * errorString) :
    errorCode_(errorCode), errorString_(errorString)
{
}

/**
 *  @details    Gets the error's error code attribute.
 *
 *  @return     The value of the error's error code
 */
int ErrorData::errorCode() const
{
    return errorCode_;
}

/**
 *  @details    Gets the error's error string attribute.
 *
 *  @return     A const pointer to the error's error string.
 */
const char * ErrorData::errorString() const
{
    return errorString_;
}
