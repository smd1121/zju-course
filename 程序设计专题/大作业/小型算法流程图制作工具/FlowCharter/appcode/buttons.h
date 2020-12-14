/* File: buttons.h
 * ---------------
 * Provides the buttons and functions on it.
 */
#ifndef BUTTONS_H
#define BUTTONS_H

#include "myIncludes.h"
#include "arrow.h"
#include "shape.h"

#define BUTTON_NUM 45

/* Global Variable: buttons[]
 * -----------
 * This array contains all the buttons needed
 * in the project.
 *
 * buttonStatus: 0 - invisiable, 1 - normal,
 * 2 - overed, 3 - chosen
 */
struct myButtons
{
	bool isFilled;
	int buttonIndex, buttonStatus;
	double posX, posY, sizeX, sizeY;
	string contents, color;
};
extern struct myButtons buttons[BUTTON_NUM];

/* Global Variables:
 * ----------------
 * isFilledStatus: TRUE or FALSE.
 *
 * DrawStatus: 0~6. Each for: select, rectangle,
 * rounded rectangle, lozenge, parallelogram,
 * arrow, dotted arrow.
 * 
 * SizeStatus: 0~2. Each for: thin, middle, thick.
 * 
 * ColorStatus: one in the color table.
 */
extern bool isFilledStatus;
extern int DrawStatus, SizeStatus;
extern string ColorStatus;

/* Function: setButton
 * -------------------
 * Set buttons[buttonIndex] with given arguments.
 */
void setButton(bool isFilled, int buttonIndex, int buttonStatus,
			   double posX, double posY, double sizeX, double sizeY,
			   string contents, string color);

/* Function: initButtons()
 * --------------------
 * Set the buttons as their default status.
 */
void initButtons();

/* Function: DrawButtons()
 * -----------------------
 * Draw all the buttons.
 */
void DrawButtons();

/* Function: drawSpecialButtons
 * ----------------------------
 * There are several buttons that has
 * special shapes in it. This function
 * is used to draw these shapes.
 */
void drawSpecialButtons(int index, double posX, double posY);

/* Function: SearchButton
 * ----------------------
 * Given (x, y), search a visiable button
 * that contains this point.
 * If there is not, return -1.
 */
int SearchButton(double x, double y);

/* Function: OverButton
 * --------------------
 * Change the status of the button overed
 * by mouse, meanwhile reset the original
 * overed button to normal status.
 */
void OverButton(double mx, double my);

/* Function: ClickButton
 * ---------------------
 * When a click happens, check whether there is
 * a button selected. If there is, change the 
 * status and the global variables related.
 */
void ClickButton(double mx, double my);

/* Function: RelatedVisiability
 * ----------------------------
 * Given a change on the status of a button, 
 * automatically change the status of its 
 * related buttons.
 */
void RelatedVisiability(int buttonIndex, int changedStatus);

/* Function: ButtonEvent
 * ----------------------
 * All the event of drop-down menus
 * and short cut keys.
 */
void ButtonEvent(int index);

#endif /* BUTTONS_H */
