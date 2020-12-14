/* File: runner.c
 * ------------------
 * This file provides a runner (interpreter)
 * for basic flowchart running.
 */

#include "myIncludes.h"
#include "shape.h"
#include "arrow.h"
#include "buttons.h"
#include "variables.h"

/* Global variable:
 * runningStatus:
 * 		0 - not running
 * 		1 - runnning
 *		2 - debugging
 *		3 - waiting for input
 * startStatus: 
 * 		0 - haven't start
 *		1 - started
 */
int runningStatus = 0, startStatus = 0;
Shape *runningShape = NULL;

/* Function: initRunner()
 * -------------------------
 * Preparation for interpreter and running.
 * -------------------------
 * Return Value:
 * TRUE - successful
 * FALSE - failed: no "START" node.
 */
bool initRunner()
{
	initVar();
	startStatus = 0;
	/* Find "START" node */
	runningShape = shapeTail;
	while(runningShape != NULL)
	{
		if(runningShape->shapeType == 2)
		{
			return TRUE;
		}
		runningShape = runningShape->last;
		DrawAll();
	}
	runningStatus = 0;
	return FALSE;
}

char inputVar[100];
/* Function: nextStep()
 * -------------------
 * Run current shape and go to next step.
 * -------------------
 * Return value:
 * -3: invalid: multi "START" node
 * -2: running shape is NULL
 * -1: invalid expression in next shape
 *  0: success
 *  1: no next shape
 *  2: wait for input
 */
int nextStep()
{
	if(runningShape == NULL)
		return -2;
	
	ArrowPair tempAP = SearchArrowPair(runningShape);
	
	switch(runningShape->shapeType)
	{
		case 1: /* rectangle: expression */
		{
			char tempCont[102];
			strcpy(tempCont, runningShape->contents);
			if(LexcialAnalisis(tempCont) == TRUE)
			{
				FILE *fp = fopen("lexAnaLog.flowcharter", "r");
				char variable[20], op[3];
				double value;
				fscanf(fp, "%s%s%lf", variable, op, &value);
				fclose(fp);
				Var *nowVar = searchVar(variable);
				if(nowVar == NULL)	break;
				switch(op[0])
				{
					case '=':
						nowVar->value = value;
						break;
					case '+':
						nowVar->value += value;
						break;
					case '-':
						nowVar->value -= value;
						break;
					case '*':
						nowVar->value *= value;
						break;
					case '/':
						nowVar->value /= value;
						break;
					case '%':
						nowVar->value = (int)nowVar->value % (int)value;
						break;
					default:
						return -1;
				}
				if(tempAP.arrowOne == NULL)
					return 1;
				else
				{
					Shape *tempS = SearchShape(tempAP.arrowOne->posX + tempAP.arrowOne->sizeX
											  ,tempAP.arrowOne->posY + tempAP.arrowOne->sizeY);
					if(tempS == NULL)
						return 1;
					else
					{
						runningShape = tempS;
						return 0;
					}
				}
			}
			else return -1;
			break;
		}
			
		case 2: /* round rect: START */
		{ 
			if(startStatus == 1)
				return -3;
			else
			{
				if(tempAP.arrowOne == NULL)
					return 1;
				else
				{
					Shape *tempS = SearchShape(tempAP.arrowOne->posX + tempAP.arrowOne->sizeX
											  ,tempAP.arrowOne->posY + tempAP.arrowOne->sizeY);
					if(tempS == NULL)
						return 1;
					else
					{
						runningShape = tempS;
						return 0;
					}
				}
			}
			break;
		} 
			
		case 3: /* lonzenge: judge */
		{
			char tempCont[102];
			strcpy(tempCont, runningShape->contents);
			int judgeResult = JudgeAnalisis(tempCont);
			switch(judgeResult)
			{
				case 1:
				{
					if(tempAP.arrowOne != NULL && tempAP.arrowOne->contents != NULL && tempAP.arrowOne->contents[0] == 'Y')
					{
						runningShape = SearchShape(tempAP.arrowOne->posX + tempAP.arrowOne->sizeX
												  ,tempAP.arrowOne->posY + tempAP.arrowOne->sizeY);
						if(runningShape == NULL)	return 1;
						else return 0;
					}
					else if(tempAP.arrowTwo != NULL && tempAP.arrowTwo->contents != NULL && tempAP.arrowTwo->contents[0] == 'Y')
					{
						runningShape = SearchShape(tempAP.arrowTwo->posX + tempAP.arrowTwo->sizeX
												  ,tempAP.arrowTwo->posY + tempAP.arrowTwo->sizeY);
						if(runningShape == NULL)	return 1;
						else return 0;
					}
					else
						return 1;
				}
				break;
				
				case 0:
				{
					if(tempAP.arrowOne != NULL && tempAP.arrowOne->contents != NULL && tempAP.arrowOne->contents[0] == 'N')
					{
						runningShape = SearchShape(tempAP.arrowOne->posX + tempAP.arrowOne->sizeX
												  ,tempAP.arrowOne->posY + tempAP.arrowOne->sizeY);
						if(runningShape == NULL)	return 1;
						else return 0;
					}
					else if(tempAP.arrowTwo != NULL && tempAP.arrowTwo->contents != NULL && tempAP.arrowTwo->contents[0] == 'N')
					{
						runningShape = SearchShape(tempAP.arrowTwo->posX + tempAP.arrowTwo->sizeX
												  ,tempAP.arrowTwo->posY + tempAP.arrowTwo->sizeY);
						if(runningShape == NULL)	return 1;
						else return 0;
					}
					else
						return 1;
				}
				break;
				
				default:
					return -1;
					break;
			}
			break;
		}
			
		case 4: /* para: input */
		{
			int inputVarTag = 0, i;
			buttons[46].buttonStatus = 1;
			for(i = 0; i < strlen(runningShape->contents); i++)
			{
				if(runningShape->contents[i] != ' ')
				{
					inputVar[inputVarTag++] = runningShape->contents[i];
					inputVar[inputVarTag] = 0;
				}
				else if(inputVarTag != 0)
					return 2;
			}
			return 2;
			break;
		}
		default:
			return -2;
	}
} 
