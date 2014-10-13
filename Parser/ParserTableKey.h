/**
 *  @author Blurred-9L
 *  @file   ParserTableKey.h
 */

#ifndef PARSER_TABLE_KEY_H
#define PARSER_TABLE_KEY_H

/**
 *  @class  ParserTableKey
 *
 *  @brief  Convenience class used to store the
 *          key related values on an LR Table entry.
 */
class ParserTableKey {
private:
    /// The current state used by the key.
    int state_;
    /// The related token type.
    int tokenType_;

public:
    /// ParserTableKey default constructor.
    ParserTableKey();
    /// ParserTableKey constructor.
    ParserTableKey(int state, int tokenType);
    /// Gets the key's related state.
    int state() const;
    /// Gets the key's related token type.
    int tokenType() const;
    /// Sets the key's related state.
    void setState(int state);
    /// Sets the key's related token type.
    void setTokenType(int tokenType);
};

#endif /// NOT PARSER_TABLE_KEY_H
