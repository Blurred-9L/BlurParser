/**
 *  @author Blurred-9L
 *  @file   AbstractAutomata.h
 */

#ifndef ABSTRACT_AUTOMATA_H
#define ABSTRACT_AUTOMATA_H

#include <string>
using std::string;

/**
 *  @class  AbstractAutomata
 *
 *  @brief  Base class used to handle operations required by
 *          the Tokenizer class that involve querying the data
 *          on the transition matrix. 
 */
class AbstractAutomata {
protected:
    /// The matrix of transitions.
    int ** transitions;
    /// The number of possible states.
    unsigned nStates_;
    /// The number of possible inputs.
    unsigned nInputs_;
    /// The number of terminal states.
    unsigned nTerminalStates_;

public:
    /// AbstractAutomata constructor.
    AbstractAutomata();
    /// AbstractAutomata destructor.
    virtual ~AbstractAutomata();
    /// Loads the matrix of transitions.
    bool loadMatrix(const char * filename);
    /// Gets the number of possible states.
    unsigned nStates() const;
    /// Gets the number of possible inputs.
    unsigned nInputs() const;
    /// Gets the number of terminal states.
    unsigned nTerminalStates() const;
    /// Gets the next state based on input.
    virtual int nextState(int state, char input) const = 0;
    /// Checks if a state is a terminal state.
    virtual bool isAcceptState(int state) const = 0;
    /// Checks if the state remains valid on next character.
    virtual bool includeNextChar(int state, const string & line, int charIdx) const = 0;
    /// Gets the type of the token recognized at the given state.
    virtual int getTokenType(int state) = 0;
};

#endif /// NOT ABSTRACT_AUTOMATA_H
