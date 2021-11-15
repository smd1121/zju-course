#include "myHeader.h"

void CharEventProcess(char c) {
	if (!isTextboxInput)	return;
	
	switch(c) {
		case '\x08':
			if (!textboxLength) break;
			buttonContents[TEXTBOX][--textboxLength] = 0;
			break;
		case '\r': case '\n':
			isTextboxInput = FALSE;
			break;
		default:
			buttonContents[TEXTBOX][textboxLength++] = c;
			buttonContents[TEXTBOX][textboxLength] = 0;
	}
}
