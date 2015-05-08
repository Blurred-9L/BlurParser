/**
 *  @author Blurred-9L
 *  @file   Tokenizer.cpp
 */

#include "Tokenizer.h"
#include "AbstractAutomata.h"
#include "KeywordSet.h"

#include "../Core/Token.h"
#include "../Core/LineFileReader.h"
#include "../Core/ErrorKeeper.h"

#include <cctype>
#include <iostream>

/**
 *  @details    Constructs a Tokenizer object. The object constructed
 *              does not have a set automata, keyword set or line reader,
 *              so the user should remember to set them before calling
 *              getToken().
 */
Tokenizer::Tokenizer() :
    automata_(0), keywords_(0), lineReader_(0), errorKeeper_(0), line_(),
    charIdx(-1), tokenStartIndex(-1), tokenLineNumber_(0)
{
}

/**
 *  @details    Constructs a Tokenizer object with the given automata,
 *              keyword set and line reader.
 *
 *  @param[in]  automata        The automata to use. Should be dynamically
 *                              allocated.
 *  @param[in]  keywords        The keyword set to use. Should be dynamically
 *                              allocated.
 *  @param[in]  lineReader      The lineReader set to use. Should be dynamically
 *                              allocated.
 *  @param[in]  errorKeeper     The errorKeeper set to use. Should be dynamically
 *                              allocated.
 */
Tokenizer::Tokenizer(AbstractAutomata * automata, KeywordSet * keywords,
                     LineFileReader * lineReader, ErrorKeeper * errorKeeper) :
    automata_(automata), keywords_(keywords), lineReader_(lineReader),
    errorKeeper_(errorKeeper), line_(), charIdx(-1), tokenStartIndex(-1)
{
}

/**
 *  @details    Destroys the Tokenizer object.
 */
Tokenizer::~Tokenizer()
{
    if (automata_ != 0) {
        delete automata_;
    }
    if (keywords_ != 0) {
        delete keywords_;
    }
    if (lineReader_ != 0) {
        delete lineReader_;
    }
    if (errorKeeper_ != 0) {
        delete errorKeeper_;
    }
}

/**
 *  @details    Gets the automata attribute from the Tokenizer.
 *
 *  @return     A constant reference to the automata attribute.
 */
const AbstractAutomata & Tokenizer::automata() const
{
    return *automata_;
}

/**
 *  @details    Gets the automata attribute from the Tokenizer.
 *
 *  @return     A reference to the automata attribute.
 */
AbstractAutomata & Tokenizer::automata()
{
    return *automata_;
}

/**
 *  @details    Gets the keywords attribute from the Tokenizer.
 *
 *  @return     A constant reference to the keywords attribute.
 */
const KeywordSet & Tokenizer::keywords() const
{
    return *keywords_;
}

/**
 *  @details    Gets the keywords attribute from the Tokenizer.
 *
 *  @return     A reference to the keywords attribute.
 */
KeywordSet & Tokenizer::keywords()
{
    return *keywords_;
}

/**
 *  @details    Gets the lineReader attribute from the Tokenizer.
 *
 *  @return     A constant pointer to the lineReader attribute.
 */
const LineFileReader * Tokenizer::lineReader() const
{
    return lineReader_;
}

/**
 *  @details    Gets the lineReader attribute from the Tokenizer.
 *
 *  @return     A pointer to the lineReader attribute.
 */
LineFileReader * Tokenizer::lineReader()
{
    return lineReader_;
}

/**
 *  @details    Gets the errorKeeper attribute from the Tokenizer.
 *
 *  @return     A constant pointer to the errorKeeper attribute.
 */
const ErrorKeeper * Tokenizer::errorKeeper() const
{
    return errorKeeper_;
}

/**
 *  @details    Gets the errorKeeper attribute from the Tokenizer.
 *
 *  @return     A pointer to the errorKeeper attribute.
 */
ErrorKeeper * Tokenizer::errorKeeper()
{
    return errorKeeper_;
}

/**
 *  @details    Gets the tokenLineNumber attribute of the tokenizer.
 *
 *  @return     The value of the tokenLineNumber attribute.
 */
int Tokenizer::tokenLineNumber() const
{
    return tokenLineNumber_;
}

/**
 *  @details    Sets the automata to be used when tokenizing
 *              the given input string. The automata passed
 *              should be dynamically allocated. If a previous
 *              automata had been set, it will be deleted.
 *
 *  @param[in]  automata        The automata to use.
 */
void Tokenizer::setAutomata(AbstractAutomata * automata)
{
    if (automata != 0) {
        if (automata_ != 0) {
            delete automata_;
        }
        automata_ = automata;
    }
}

/**
 *  @details    Sets the keyword set to be used when tokenizing
 *              the given input string. The keyword set passed
 *              should have been dynamically allocated. If a
 *              previous keyword set had been set, it will be
 *              deleted.
 *
 *  @param[in]  keywords        The keyword set to use.
 */
void Tokenizer::setKeywords(KeywordSet * keywords)
{
    if (keywords != 0) {
        if (keywords_ != 0) {
            delete keywords_;
        }
        keywords_ = keywords;
    }
}

/**
 *  @details    Sets the line reader to be used when this tokenizer
 *              consumes a line. The lineReader passed should have
 *              been dynamically allocated. If a previous line reader
 *              had been set, it will be deleted. Since the line reader
 *              is not strictly necessary for the Tokenizer to
 *              function properly, it can be set to a 0 value.
 *
 *  @param[in]  lineReader      The lineReader to use.
 */
void Tokenizer::setLineReader(LineFileReader * lineReader)
{
    if (lineReader_ != 0) {
        delete lineReader_;
    }
    lineReader_ = lineReader;
}

/**
 *  @details    Sets the error keeper to be used whenever an error is
 *              raised by this tokenizer. The errorKeeper passed should
 *              have been dynamically allocated. If a previous error keeper
 *              had been set, it will be deleted. Since the error keeper
 *              is not strictly necessary for the Tokenizer to
 *              function properly, it can be set to a 0 value.
 *
 *  @param[in]  errorKeeper     The errorKeeper to use.
 */
void Tokenizer::setErrorKeeper(ErrorKeeper * errorKeeper)
{
    if (errorKeeper_ != 0) {
        delete errorKeeper_;
    }
    errorKeeper_ = errorKeeper;
}

/**
 *  @details    Sets the line to use when tokenizing and also
 *              resets the index used when iterating over it.
 *
 *  @param[in]  line            The line to be tokenized.
 */
void Tokenizer::setLine(const string & line)
{
    line_ = line;
    charIdx = 0;
}

/**
 *  @details    Sets the line number on which the given tokens
 *              were found.
 *
 *  @param[in]  tokenLineNumber The line number.
 */
void Tokenizer::setTokenLineNumber(int tokenLineNumber)
{
    tokenLineNumber_ = tokenLineNumber;
}

/**
 *  @details    Gets the next token from the given input string.
 *              The token returned will be dynamically allocated,
 *              so one should remember to deallocate it later.
 *
 *  @return     The token found or 0 if no more tokens can be
 *              extracted. 0 is also returned if an error ocurred.
 */
Token * Tokenizer::getToken()
{
    Token * token = 0;
    TokenData tokenData;
    string symbol;
    int lineLength;
    
    if (lineReader_ != 0) {
        loadNextLine();
    }
    
    lineLength = line_.length();
    if (charIdx < lineLength && automata_ != 0 && keywords_ != 0) {
        tokenData = buildToken();
        if (tokenData.length() > 0) {
            symbol = line_.substr(tokenData.start(), tokenData.length());
            if (keywords_->isKeyword(symbol)) {
                token = new Token(keywords_->getKeywordId(symbol), tokenData.start(),
                                  tokenLineNumber_, symbol);
            } else if (automata_->isAcceptState(tokenData.state())) {
                token = new Token(automata_->getTokenType(tokenData.state()), tokenData.start(),
                                  tokenLineNumber_, symbol);
            }
            charIdx = tokenData.start() + tokenData.length();
        }
    }
    
    return token;
}

/**
 *  @details    Checks if an error has ocurred during the execution
 *              of the tokenizer.
 *
 *  @return     A boolean value indicating if an error has occur.
 */
bool Tokenizer::hasError() const
{
    bool errorExists = false;
    
    if (errorKeeper_ != 0) {
        errorExists = errorKeeper_->hasError();
    }
    
    return errorExists;
}

/////////////
// Private //
/////////////

/**
 *  @details    Algorithm used to build the substring of the
 *              input string to be included on the next token. At each
 *              step a TokenData object is modified so that it can be
 *              used later to extract the token from the line.
 *
 *  @return     Returns a TokenData object containing the start, length
 *              and final state visited which will be used to get the
 *              next token.
 */
TokenData Tokenizer::buildToken()
{
    int start = charIdx, state = 0, end = start;
    int lineLength = line_.length();
    TokenData tokenData(start, 0, 0);
    bool done = false, error = false;
    
    while ((!done) && (!error) && end < lineLength) {
        state = automata_->nextState(state, line_[end]);
        if (state > 0) {
            tokenData = TokenData(tokenData.start(), tokenData.length() + 1, state);
            if (automata_->isAcceptState(state)) {
                if (!automata_->includeNextChar(state, line_, end)) {
                    done = true;
                }
            }
        } else if (state < 0) {
            error = true;
        } else {
            tokenData = TokenData(tokenData.start() + 1, tokenData.length(), state);
        }
        end++;
        if (end >= lineLength && tokenData.length() == 0) {
            if (lineReader_ != 0 && lineReader_->hasNext()) {
                lineReader_->sendNextLine(*this);
                lineLength = line_.length();
                tokenData = TokenData(0, tokenData.length(), state);
                end = 0;
            }
        }
    }
    
    if (error) {
        if (errorKeeper_ != 0) {
            errorKeeper_->addError(LEXIC_INPUT_ERROR, "Lexic Error: Wrong token formation | Unexpected symbol.");
        } else {
            std::cerr << "Lexic Error: Wrong token formation | Unexpected symbol." << std::endl;
        }
    } else if (!done && tokenData.length() > 0) {
        if (errorKeeper_ != 0) {
            errorKeeper_->addError(TOKEN_NO_END_ERROR, "Lexic Error: Could not finish building last token.");
        } else {
            std::cerr << "Lexic Error: Could not finish building last token." << std::endl;
        }
    }
    
    return tokenData;
}

/**
 *  @details    Checks if the line to be tokenized only has whitespaces.
 *
 *  @return     A boolean value indicating if a whitespace only line has
 *              been set or read.
 */
bool Tokenizer::spaceOnlyLine()
{
    int size = line_.size();
    bool spaceOnly = true;
    
    for (int i = 0; i < size && spaceOnly; i++) {
        if (!isspace(line_[i])) {
            spaceOnly = false;
        }
    }
    
    return spaceOnly;
}

/**
 *  @details    Tries to get another line to continue the tokenizing by
 *              asking the LineFileReader object to send the next line.
 */
void Tokenizer::loadNextLine()
{
    while ((charIdx >= (int)line_.length() || spaceOnlyLine()) && lineReader_->hasNext()) {
        lineReader_->sendNextLine(*this);
    }
}
