/* File: variables.c
 * -------------
 * This file provides the functions
 * about the variables when running.
 */

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
Var *varHead = NULL, *varTail = NULL;

/* Function: CreateVar
 * ------------
 * This function creates a new variable with the given
 * arguments and adds it to the tail of the linked list.
 */

Var *CreateVar(string name, double value)
{
	/* linked list operation */
	if(varHead == NULL)
	{
		varHead = varTail = (Var*)malloc(sizeof(Var));
		varTail->last = NULL;
	}
	else
	{
		varTail->next = (Var*)malloc(sizeof(Var));
		varTail->next->last = varTail;
		varTail = varTail->next;
	}
	
	/* initialize the Var*/
	varTail->next = NULL;
	varTail->value = value;
	varTail->name = (char *)malloc(sizeof(char) * strlen(name));
	strcpy(varTail->name, name);
	
	return varTail;
}

/* Function: SearchVar
 * -------------------
 * Return the Var searched by the given name.
 */
Var *searchVar(string variable)
{
	Var *temp = varHead;
	while(temp != NULL)
	{
		if(strcmp(variable, temp->name) == 0)
			return temp;
		temp = temp->next;
	}
	return CreateVar(variable, 0);
}

/* Function: getVarValue
 * -----------------------
 * Return the value of the given Var.
 * If there is not, create a new Var in the list
 * with default value 0.0.
 */
double getVarValue(string variable)
{ 
	Var *temp = searchVar(variable);
	if(temp != NULL)	
	{
		return temp->value;
	}
	CreateVar(variable, 0);
	return 0;
}

/* Function: DrawVar()
 * ------------------
 * Print all the variables on the window.
 */
void DrawVar()
{
	SetPenColor("Black");
	
	double varPenX = 0.2;
	MovePen(varPenX, 0.6);
	DrawTextString("Variable");
	MovePen(varPenX, 0.2);
	DrawTextString(" Value ");
	
	Var *temp = varHead;
	while(temp != NULL)
	{
		varPenX += 1.5;
		MovePen(varPenX, 0.6);
		DrawTextString(temp->name);
		MovePen(varPenX, 0.2);
		char valueStr[12];
		sprintf(valueStr, "%-.6lf", temp->value);
		DrawTextString(valueStr);
		temp = temp->next;
	}
} 

/* Function: initVar
 * -----------------
 * Delete all Vars.
 */
void initVar()
{
	Var *tempV;
	while(varHead != NULL)
	{
		tempV = varHead;
		varHead = varHead->next;
		free(tempV);
	}
	varTail = varHead = NULL;
}
