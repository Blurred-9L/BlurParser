#ifndef ERROR_DATA_H
#define ERROR_DATA_H

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
    const char * errorString_;
    
public:
    /// ErrorData default constructor.
    ErrorData();
    /// ErrorData constructor.
    ErrorData(int errorCode, const char * errorString);
    /// Gets the error's code.
    int errorCode() const;
    /// Gets the error's string.
    const char * errorString() const;
};

#endif /// NOT ERROR_DATA_H
