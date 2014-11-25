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
ErrorData::ErrorData(int errorCode, const string & errorString) :
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
 *  @return     A constant reference to the error's error string.
 */
const string & ErrorData::errorString() const
{
    return errorString_;
}

/**
 *  @details    Gets the error's error string attribute.
 *
 *  @return     A reference to the error's error string.
 */
string & ErrorData::errorString()
{
    return errorString_;
}

/**
 *  @details    Sets the error's error code attribute.
 *
 *  @param[in]  errorCode       The new error code.
 */
void ErrorData::setErrorCode(int errorCode)
{
    errorCode_ = errorCode;
}

/**
 *  @details    Sets the error's error string attribute.
 *
 *  @param[in]  errorString     The new error string.
 */
void ErrorData::setErrorString(const string & errorString)
{
    errorString_ = errorString;
}
