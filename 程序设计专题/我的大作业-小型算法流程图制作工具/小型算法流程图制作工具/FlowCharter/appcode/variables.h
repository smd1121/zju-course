/* File: variables.h
 * -------------
 * This file provides the functions
 * about the variables when running.
 */

#ifndef VARIABLES_H
#define VARIABLES_H

#include "myIncludes.h"

/*
 * Type: Var
 * ------------
 * This structure is the basic form of all variables.
 * 
 * Meanwhile, this structure is also a linked list, which 
 * is designed with pointers to the next/last node of Var.
 */
typedef struct myVariable{
	string name;
	double value;
	struct myVariable *next, *last;
}Var;

/* Global variable: varHead
 * The head of the linked list.
 */
extern Var *varHead, *varTail;

/* Function: CreateVar
 * ------------
 * This function creates a new variable with the given
 * arguments and adds it to the tail of the linked list.
 */
Var *CreateVar(string name, double value);

/* Function: SearchVar
 * -------------------
 * Return the Var searched by the given name.
 */
Var *searchVar(string variable);

/* Function: getVarValue
 * -----------------------
 * Return the value of the given Var.
 * If there is not, create a new Var in the list
 * with default value 0.0.
 */
double getVarValue(string variable);

/* Function: drawVar()
 * ------------------
 * Print all the variables on the window.
 */
void DrawVar();

/* Function: initVar
 * -----------------
 * Delete all Vars.
 */
void initVar();

#endif /* VARIABLES_H */
