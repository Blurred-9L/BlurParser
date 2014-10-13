/**
 *  @author Blurred-9L
 *  @file   ParserTableAction.cpp
 */

#include "ParserTableAction.h"

/**
 *  @details    Constructs a ParserTableAction object with invalid
 *              values for its attributes.
 */
ParserTableAction::ParserTableAction() :
    type_(-1), value_(-1)
{
}

/**
 *  @details    Constructs a ParserTableAction object with the given
 *              action type and related value.
 *
 *  @param[in]  type            The type of the action.
 *  @param[in]  value           The related value for the action.
 */
ParserTableAction::ParserTableAction(int type, int value) :
    type_(type), value_(value)
{
}

/**
 *  @details    Gets the type attribute from the action.
 *
 *  @return     The value of the action's type attribute.
 */
int ParserTableAction::type() const
{
    return type_;
}

/**
 *  @details    Gets the value attribute from the action.
 *
 *  @return     The value related to this object's action.
 */
int ParserTableAction::value() const
{
    return value_;
}

/**
 *  @details    Sets the type attribute for the action.
 *
 *  @param[in]  type            The type of the action.
 */
void ParserTableAction::setType(int type)
{
    type_ = type;
}

/**
 *  @details    Sets the value attribute for the action.
 *
 *  @param[in]  value           The related value of the action.
 */
void ParserTableAction::setValue(int value)
{
    value_ = value;
}
