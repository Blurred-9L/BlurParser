#ifndef ERROR_KEEPER_H
#define ERROR_KEEPER_H

class ErrorData;

/**
 *  @class  ErrorKeeper
 *
 *  @brief  Class used as an interface to store
 *          data about errors that might occur during
 *          the parser's execution.
 */
class ErrorKeeper {
public:
    /// ErrorHandler default constructor.
    ErrorKeeper();
    /// ErrorHandler destructor.
    virtual ~ErrorKeeper();
    /// Adds an error to the error keeper
    virtual void addError(const ErrorData & error) const = 0;
    /// Tells if there was an error or not.
    virtual bool hasError() const = 0;
    /// Extracts an error from the error keeper.
    virtual ErrorData & nextError() = 0;
    /// Removes all errors from the keeper.
    virtual void clear() = 0;
};

#endif /// NOT ERROR_KEEPER_H
