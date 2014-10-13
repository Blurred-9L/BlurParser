/**
 *  @author Blurred-9L
 *  @file   ParserTableAction.h
 */

#ifndef PARSER_TABLE_ACTION_H
#define PARSER_TABLE_ACTION_H

/**
 *  @class  ParserTableAction
 *
 *  @brief  Convenience class for storing the action values to
 *          be performed after accessing a LR Table by its
 *          key.
 */
class ParserTableAction {
private:
    /// The type of the action.
    int type_;
    /// The value related to the action.
    int value_;

public:
    /// ParserTableAction default constructor.
    ParserTableAction();
    /// ParserTableAction constructor.
    ParserTableAction(int type, int value);
    /// Gets the action's type.
    int type() const;
    /// Gets the action's value.
    int value() const;
    /// Sets the action's type.
    void setType(int type);
    /// Sets the action's value.
    void setValue(int value);
};

#endif /// NOT PARSER_TABLE_ACTION_H
