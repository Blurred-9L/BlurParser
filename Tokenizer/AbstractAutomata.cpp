/**
 *  @author Blurred-9L
 *  @file   AbstractAutomata.cpp
 */

#include "AbstractAutomata.h"

#include <fstream>
using std::ifstream;

/**
 *  @details    Constructs an AbstractAutomata object.
 */
AbstractAutomata::AbstractAutomata() :
    transitions(0), nStates_(0), nInputs_(0), nTerminalStates_(0)
{
}

/**
 *  @details    Destroys the AbstractAutomata object.
 */
AbstractAutomata::~AbstractAutomata()
{
    if (transitions != 0) {
        for (int i = 0; i < nStates_; i++) {
            delete [] transitions[i];
        }
        delete [] transitions;
    }
}

/**
 *  @details    Loads the matrix of transitions from a file onto this
 *              object. This method must be called before trying to
 *              use any of this object's methods.
 *
 *  @param[in]  filename        The name of the file containing the transtions matrix.
 *
 *  @return     A boolean value indicating if the matrix was properly loaded.
 */
bool AbstractAutomata::loadMatrix(const char * filename)
{
    ifstream matrixFile(filename);
    bool matrixLoaded = false;
    
    if (matrixFile.is_open()) {
        matrixFile >> nStates_ >> nInputs_;
        matrixFile >> nTerminalStates_;
        transitions = new int * [nStates_];
        for (int i = 0; i < nStates_; i++) {
            transitions[i] = new int [nInputs_];
            for (int j = 0; j < nInputs_; j++) {
                matrixFile >> transitions[i][j];
            }
        }
        matrixLoaded = true;
        matrixFile.close();
    }
    
    return matrixLoaded;
}

/**
 *  @details    Gets the number of possible states available on the transitions
 *              matrix.
 *
 *  @return     The number of possible states.
 */
unsigned AbstractAutomata::nStates() const
{
    return nStates_;
}

/**
 *  @detials    Gets the number of possible inputs on the transitions matrix.
 *              The number of input in no way indicates the kind of inputs
 *              that are accepted on the automata.
 *
 *  @return     The number of possible types of input.
 */
unsigned AbstractAutomata::nInputs() const
{
    return nInputs_;
}

/**
 *  @details    Gets the number of states considered to be terminal on the
 *              transitions matrix.
 *
 *  @return     The number of terminal states.
 */
unsigned AbstractAutomata::nTerminalStates() const
{
    return nTerminalStates_;
}

/**
 *  @details    Default definition of the includeNextChar() method. This method
 *              will check if the next character on the input can be added to
 *              the current token.
 *
 *  @param[in]  state           The current state on the automata.
 *  @param[in]  line            The line being currently analyzed.
 *  @param[in]  charIdx         The current index on the line string.
 *
 *  @return     Returns a boolean value indicating if the following character
 *              on the input can be added to the current token.
 */
bool AbstractAutomata::includeNextChar(int state, const string & line, int charIdx) const
{
    bool ok = false;
    int newState;
    
    if (charIdx + 1 < line.length()) {
        newState = nextState(state, line[charIdx + 1]);
        if (newState > 0) {
            ok = true;
        }
    }
    
    return ok;
}
