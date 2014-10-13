/**
 *  @author Blurred-9L
 *  @file   ParserTable.h
 */

#ifndef PARSER_TABLE_H
#define PARSER_TABLE_H

class ParserTableKey;
class ParserTableAction;

/**
 *  @class  ParserTable
 *
 *  @brief  Base class used to abstract the required operations
 *          for the implementation of an LR Table.
 */
class ParserTable {
protected:
    /// Fills the LR Table.
    virtual void fillTable() = 0;
    
public:
    /**
     *  @enum   ActionType
     *
     *  @brief  Defines values for all 4 action types : shift,
     *          reduce, change and accept.
     */
    enum ActionType {
        SHIFT,
        REDUCE,
        CHANGE,
        ACCEPT
    };

    /// ParserTable constructor.
    ParserTable();
    /// Checks if the table has the given key.
    virtual bool hasKey(const ParserTableKey & key) const = 0;
    /// Gets the action related to the given key.
    virtual ParserTableAction * getAction(const ParserTableKey & key) const = 0;
    /// Gets the length of a rule on the grammar used.
    virtual int getRuleLength(int ruleNumber) = 0;
    /// Gets the non-terminal type on the left side of the production on a rule.
    virtual int getNonTerminalType(int ruleNumber) = 0;
};

#endif /// NOT PARSER_TABLE_H
