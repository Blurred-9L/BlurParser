#ifndef TOKEN_DATA_H
#define TOKEN_DATA_H

/**
 *  @class  TokenData
 *
 *  @brief  Class used to contain start index and length of
 *          a token on a current line.
 */
class TokenData {
private:
    /// The start of the token
    int start_;
    /// The length of the token
    int length_;
    /// The state signalling the token's end
    int state_;
    
public:
    /// Default Constructor
    TokenData();
    /// Constructor
    TokenData(int start, int length, int state);
    /// Gets the start index
    int start() const;
    /// Gets the length value
    int length() const;
    /// Gets the state value
    int state() const;
};

#endif /// NOT TOKEN_DATA_H
