#include "myIncludes.h"
#include "buttons.h"
#include "shape.h"

/* Global Variables:
 * -----------------
 * Meanings are apparent.
 */ 
bool isGettingStr = FALSE, isEditingText = FALSE, 
	 keyboardCtrlPlus = FALSE, isEditingTextBox = FALSE,
	 isEditingInput = FALSE;
int textTag = 0;
Shape *changeTextShape;

extern Shape textBox, inputBox;

void CharEventProcess(char c)
{
	if(changeTextShape != NULL)
	{
		switch(c)
		{
			case '\x08':
				textTag = strlen(changeTextShape->contents);
				if(textTag == 0)	break;
				changeTextShape->contents[textTag - 1] = '\0';
				break;
			case '\r': case '\n':
				changeTextShape = NULL;
				break;
			default:
				if(changeTextShape != NULL)
				{
					textTag = strlen(changeTextShape->contents);
					if(textTag > 99)	break;
					changeTextShape->contents[textTag] = c;
					changeTextShape->contents[textTag + 1] = '\0';
				}
				break;
		}
		DrawAll();
	}
	else if(isEditingInput != FALSE)
	{
		switch(c)
		{
			case '\x08':
				textTag = strlen(inputBox.contents);
				if(textTag == 0)	break;
				inputBox.contents[textTag - 1] = '\0';
				break;
			case '\r': case '\n':
				if(buttons[46].buttonStatus != 0)
					ButtonEvent(20);
				break;
			default:
				if( isEditingInput != FALSE
				 && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') 
				  || (c >= '0' && c <= '9') || c == '.' || c == '-'))
				{
					textTag = strlen(inputBox.contents);
					if(textTag > 12)	break;
					inputBox.contents[textTag] = c;
					inputBox.contents[textTag + 1] = '\0';
				}
				break;
		}
		DrawAll();
	}
	else if(isEditingTextBox != FALSE)
	{
		switch(c)
		{
			case '\x08':
				textTag = strlen(textBox.contents);
				if(textTag == 0)	break;
				textBox.contents[textTag - 1] = '\0';
				break;
			case '\r': case '\n':
				if(buttons[45].buttonStatus != 0)
					ButtonEvent(-1);
				break;
			default:
				if( isEditingTextBox != FALSE
				 && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
				{
					textTag = strlen(textBox.contents);
					if(textTag > 12)	break;
					textBox.contents[textTag] = c;
					textBox.contents[textTag + 1] = '\0';
				}
				break;
		}
		DrawAll();
	}
}

void KeyboardEventProcess(int key,int event)
{
	switch(event) 
	{
		case KEY_DOWN:
			if(keyboardCtrlPlus == TRUE)
			{
				switch(key)
				{
					case 'N': case 'n':
						ButtonEvent(0);
						break;
					case 'O': case 'o': 
						ButtonEvent(1);
						break;
					case 'S': case 's': 
						ButtonEvent(2);					
						break;
					case 'W': case 'w': 
						ButtonEvent(3);
						break;
					case 'C': case 'c': 
						ButtonEvent(5);
						break;
					case 'V': case 'v': 
						ButtonEvent(6);
						break;
					case 'D': case 'd': 
						ButtonEvent(7);
						break;
					default:
						break;
				}
			}
			switch(key) 
			{
				case VK_LCONTROL: case VK_RCONTROL: case VK_CONTROL:
					keyboardCtrlPlus = TRUE;
					break;
				case VK_F11:
					ButtonEvent(15);
					break;
				case VK_F5:
					ButtonEvent(16);
					break;
				case VK_F9:
					ButtonEvent(17);
					break;
				case VK_F1:
					ButtonEvent(19);
					break;
				default:
					break;
			}
			break;
		case KEY_UP:
			switch(key)
			{
				case VK_LCONTROL: case VK_RCONTROL: case VK_CONTROL:
					keyboardCtrlPlus = FALSE;
			}
	}
	DrawAll();
}		 		
