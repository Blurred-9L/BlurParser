/**
 *  @author Blurred-9L
 *  @file   SyntaxNode.h
 */

#ifndef SYNTAX_NODE_H
#define SYNTAX_NODE_H

/**
 *  @class  SyntaxNode
 *
 *  @brief  Base class used for creating the structure
 *          of the Syntax Tree.
 */
class SyntaxNode {
public:
    /// SyntaxNode constructor.
    SyntaxNode();
    /// SyntaxNode destructor.
    virtual ~SyntaxNode();
};

#endif /// NOT SYNTAX_NODE_H
