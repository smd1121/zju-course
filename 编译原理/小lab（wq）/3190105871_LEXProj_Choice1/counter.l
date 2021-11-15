%option noyywrap
%{
	int lineCount = 0, charCount = 0, wordCount = 0, isLastBlank = 1;
%}
wordChar	[0-9a-zA-Z]
otherChar	[^{wordChar}]

%%

\n		lineCount++; charCount++; isLastBlank = 1;
{wordChar}	{
			charCount++;
			if (isLastBlank)
				wordCount++;
			isLastBlank = 0;
		}
{otherChar}	charCount++; isLastBlank = 1;

%%
int main() {
	yylex();
	printf("There are %d chars, %d words and %d lines.\n", charCount, wordCount, lineCount);
	return 0;
}
				
