/**
 *  @author Blurred-9L
 *  @file   KeywordSet.h
 */

#ifndef KEYWORD_SET_H
#define KEYWORD_SET_H

#include <string>
using std::string;

/**
 *  @class  KeywordSet
 *
 *  @brief  Base class used to abstract basic operations over
 *          a keyword set used on a tokenizer of parser. Subclass
 *          this class to implement your own keyword set.
 */
class KeywordSet {
public:
    /// Constant for an invalid id.
    static const int INVALID_ID;

    /// KeywordSet constructor
    KeywordSet();
    /// KeywordSet destructor.
    virtual ~KeywordSet();
    /// Checks if the symbol given is a keyword.
    virtual bool isKeyword(const string & symbol) const;
    /// Gets the keyword id-value of the symbol given.
    virtual int getKeywordId(const string & symbol) const;
};

#endif /// NOT KEYWORD_SET_H
