#ifndef ERROR_DATA_H
#define ERROR_DATA_H

#include <string>
using std::string;

/**
 *  @class  ErrorData
 *
 *  @brief  Class to store data related to an error during
 *          the parser's execution.
 */
class ErrorData {
private:
    /// The error's integer code.
    int errorCode_;
    /// The error's string.
    string errorString_;
    
public:
    /// ErrorData default constructor.
    ErrorData();
    /// ErrorData constructor.
    ErrorData(int errorCode, const string & errorString);
    /// Gets the error's code.
    int errorCode() const;
    /// Gets the error's string.
    const string & errorString() const;
    /// Gets the error's string.
    string & errorString();
    /// Sets the error's code.
    void setErrorCode(int errorCode);
    /// Sets the error's string.
    void setErrorString(const string & errorString);
};

#endif /// NOT ERROR_DATA_H
