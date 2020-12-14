/* File: lexcialAnalisis.c
 * -----------------------
 * Core Function: 
 * LexcialAnalisis(expression)
 * 		Given an expression in string, calculate
 * 		the anaAnswer and save it to lexAna.log
 * 		Return FALSE if the expression is invalid
 * JudgeAnalisis(expression)
 *		Given an expression in string, return 
 * 		its truth-value (1 or 0)
 *		Return -1 if the expression is invalid
 * -----------------------
 */
#include "myIncludes.h"
#include "variables.h"
#include "shape.h"

#define FILE_NAME "lexAnaLog.flowcharter" 

char RPN[200];	/* Postfix Expression */
char anaStr[200];	/* Infix expression */
char ex[200];	/* Original Expression */
char vari[20];	/* Name of variable */
double answer;

void initAna()
{
	int i;
	for(i = 0; i < 200; i++)
		RPN[i] = anaStr[i] = ex[i] = 0;
	for(i = 0; i < 20; i++)
		vari[i] = 0;
	answer = 0;
}

/* Function: trans()
 * ----------------
 * Convert infix expression to postfix expression.
 */
int trans()
{
	char stack[100];
	char ch;
	int len1=strlen(anaStr);
	int top,t,i;
	int last=0;
	/* Record last output:
	 * last==1 	+ * / %
	 * last==2 	a~z OR A~Z
	 * last==3 	0~9 
	 * last==4 	(
	 * last==5 	)
	 * last==6 	-
	 */
	top=0;i=0;t=0;
	
	/* CHECK START: if there is invaild char, return 0 */
	int j;
	char c;
	for(j=0;j<strlen(anaStr);j++)
	{
		c=anaStr[j];
		if(c>'9'||c<'0')
		{if(c>'Z'||c<'A'){
			if(c>'z'||c<'a'){
				if(c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='%'){
					if(c!='('&&c!=')'&&c!='_'&&c!='.'){
						if(c!=' '&&c!='\0')
						return 0;}}}}}
	} 
	/* CHECK END */
	
	ch=anaStr[i];
	i++;
	
	while(ch!='\0')
	{
		switch(ch)
		{
			case '(':	top++;
						stack[top]=ch;
						if(anaStr[i]=='+'||anaStr[i]=='/'||anaStr[i]=='*'||anaStr[i]=='%'||anaStr[i]==')')//不允许后面与这类符号接触 
							return 0;
						last=4; 
						break;
			case ')':	if(last==1||last==6) 
							return 0;
						while(stack[top]!='(') /* pop */
						{
							RPN[t]=stack[top];
							t++;
							RPN[t]=' ';
							t++;
							top--;
							if(top==-1)  /* bracket mismatch */ 
								return 0;
						}
						top--;
						last=5;
						break;
			case '+':	if(last==1)
							return 0;
						last=1;
						while(top!=0&&stack[top]!='(')
						{
							RPN[t]=stack[top];
							t++;
							RPN[t]=' ';
							t++;
							top--;
						}
						top++;
						stack[top]=ch;
						break;
			case '-':	if(last==1)
							return 0;/* minus OR negative sign */
							
						if((last==0)||(last==4&&((anaStr[i]>='0'&&anaStr[i]<='9')||(anaStr[i]>='a'&&anaStr[i]<='z')||anaStr[i]=='_'||(anaStr[i]>='A'&&anaStr[i]<='Z'))))
						{
							RPN[t]=ch;
							ch=anaStr[i];
							t++;
							i++;
							continue; 
						}
						else if(last==4)
							return 0;
							
						last=6;
						while(top!=0&&stack[top]!='(')
						{
							RPN[t]=stack[top];
							t++;
							RPN[t]=' ';
							t++;
							top--;
						}
						top++;stack[top]=ch;break;
			case '%':
			case '*':
			case '/':   if(last==1)
						return 0; 
						last=1;
						while(stack[top]=='*'||stack[top]=='/'||stack[top]=='%')
						{
							RPN[t]=stack[top];
							t++;
							RPN[t]=' ';
							t++;
							top--;
						}
						top++;
						stack[top]=ch;
						break;
	
			default:	if((ch<'0'||ch>'9')&&ch!='.'&&(ch<'a'||ch>'z')&&ch!='_'&&(ch<'A'||ch>'Z'))
						{
							strcpy(anaStr + i, anaStr + i + 1);
							break;
						}
						while((ch>='0'&&ch<='9')||ch=='.')
						{
							RPN[t]=ch;
							ch=anaStr[i];
							t++;
							i++;
							if(last==2)
								return 0;
							last=3;
						}
						while((ch>='a'&&ch<='z')||ch=='_'||(ch>='A'&&ch<='Z'))
						{
							RPN[t]=ch;
							ch=anaStr[i];
							t++;
							i++;
							if(last==3)
								return 0;
							last=2;
						}
						i--;
						RPN[t]=' ';
						t++;
		}/* end of switch */ 
		ch=anaStr[i];i++;
	}
		while(top!=0) 
		{
			RPN[t]=stack[top];
			t++;
			RPN[t]=' ';
			t++;
			top--;
		}
		anaStr[t]=' ';
		return 1;
}

int compvalue()
{
	double stack[200],d,lac;
	//d - literal number; lac - variable 
	char ch;
	int point,num_po; 
	int t=0,top=0;
	ch=RPN[t];
	t++;
	while(ch!='\0')
	{
		point=0;num_po=0;
		double a=0,b=0,n=0,m=0;
		switch(ch)
		{
			case '+':
				stack[top-1]=stack[top-1]+stack[top];
				top--;
				break;
			case '-':
				if((t==1)||(((RPN[t]>='0'&&RPN[t]<='9')||(RPN[t]>='a'&&RPN[t]<='z')||RPN[t]=='_'||(RPN[t]>='A'&&RPN[t]<='Z'))))
				{
					ch=RPN[t];
					t++;	
					d=0;
					lac=0; 
					if((ch>='0'&&ch<='9')||ch=='.')
					{
						while((ch>='0'&&ch<='9')||ch=='.')
						{
							if(ch=='.')
							{
								point=1;
								/* double dots */
								if(num_po!=0)	return 0;
									else
								{
									num_po++;
									ch=RPN[t];
									t++;
								}
							}
							if(point==0)
							{
								d=10*d+ch-'0';
								ch=RPN[t];
								t++;
							}
							if(point==1)
							{
								double little=ch-'0';
								int m;
								for(m=1;m<=num_po;m++)
									little=little/10;
								d=d+little;
								ch=RPN[t];
								t++;
								num_po++;
							} 
						}
						top++;
						stack[top]=-d;
					}
					char current[10]={0};
					if((ch>='a'&&ch<='z')||ch=='_'||(ch>='A'&&ch<='Z'))
					{ 
						int l=0;
						while((ch>='a'&&ch<='z')||ch=='_'||(ch>='A'&&ch<='Z'))
						{
							current[l]=ch;
							ch=RPN[t];
							t++;
							l++;
						}
						lac=getVarValue(current);
						top++;
						stack[top]=-lac;
					} 
				}
				else
				{
					stack[top-1]=stack[top-1]-stack[top];
					top--;
				}
				break;
			case '%':
				a=stack[top-1];
				b=stack[top];
				if(b == 0)
					return 0;
				stack[top-1]=(int)stack[top-1]%(int)stack[top];
				top--;
				break;
			case '*':
				stack[top-1]=stack[top-1]*stack[top];
				top--;
				break;
			case '/':
				if(stack[top]!=0)
				{ 
					stack[top-1]=stack[top-1]/stack[top];}else{
					return 0;
				} 
				top--;
				break;
			default:
				d=0;
				lac=0; 
				if((ch>='0'&&ch<='9')||ch=='.')
				{ 
					while((ch>='0'&&ch<='9')||ch=='.')
					{
						if(ch=='.')
						{
							point=1;
							if(num_po!=0)
								return 0;
							else
							{
								num_po++;
								ch=RPN[t];
								t++;
							}
						}
						if(point==0)
						{
							d=10*d+ch-'0';
							ch=RPN[t];
							t++;
						}
						if(point==1)
						{
							double little=ch-'0';
							int m;
							for(m=1;m<=num_po;m++)
								little=little/10;
							d=d+little;
							ch=RPN[t];
							t++;
							num_po++;
						} 
					}
				top++;
				stack[top]=d;
				}
				char current[10]={0};
				if((ch>='a'&&ch<='z')||ch=='_'||(ch>='A'&&ch<='Z'))
				{
					int l=0; 
					while((ch>='a'&&ch<='z')||ch=='_'||(ch>='A'&&ch<='Z'))
					{
						current[l]=ch;
						ch=RPN[t];
						t++;
						l++;
					}
					lac=getVarValue(current);
					top++;
					stack[top]=lac;
				} 
			}
		ch=RPN[t];
		t++;
	}
	answer=stack[top]; 
	printf("%f\n",answer);
	return 1;
}

/* Function: LexcialAnalisis
 * -------------------------
 * Analisis the expression "ex" and
 * save the result to the file.
 */
bool LexcialAnalisis(string tex)
{
	initAna();
	strcpy(ex, tex);
	FILE *fp = fopen(FILE_NAME,"w+");
	int assignment=-1;
	int way,j=0; 
	int len=strlen(ex);
	
	/* search for assignment operator */
	int i;
	for(i=0;i<len;i++) 
	{
		if(*(ex+i)=='=')
		{
			assignment = i;
			break;
		}
	}
	/* if there is no assignment operator */
	if(assignment==-1)
	{
		fclose(fp);
		return FALSE;
	}
	
	char b;
	switch(b=*(ex+assignment-1)) 
	{
		case '+':way=1;break;
		case '-':way=2;break;
		case '*':way=3;break;
		case '/':way=4;break;
		case '%':way=5;break;
		default:way=0;break;
	}
	
	if(way)
	{
		int t=0;
		for(i=0;i<assignment-1;i++)
		{
			fputc(*(ex+i),fp);
			if(*(ex+i)!=' ')
			{
				vari[t]=*(ex+i); 
				t++;
			}
		}
		fputc('\n',fp);
		fputc(*(ex+assignment-1),fp);
		fputc(*(ex+assignment),fp);
		fputc('\n',fp);
	}
	else
	{
		int t=0; 
		for(i=0;i<assignment;i++)
		{
			fputc(*(ex+i),fp);
			if(*(ex+i)!=' ')
			{
				vari[t]=*(ex+i); 
				t++;
			}
		}
		fputc('\n',fp);
		fputc(*(ex+assignment),fp);
		fputc('\n',fp);
	}
	
	len = strlen(ex);
	/* get the right expression and delete the blank */
	for(i=assignment+1;i<len;i++) 
	{
		if(*(ex+i)!=' ')
		{
			anaStr[j]=*(ex+i);
			j++;
		}
		anaStr[j] = 0;
	}
		
	if(trans()==1){
		if(compvalue()==1){
			fprintf(fp, "%f", answer);
			fclose(fp);
			return TRUE;
		}else{
			fclose(fp);
			return FALSE;
		}
	}else{
		fclose(fp);
		return FALSE;
	}
	fclose(fp);
	return FALSE;
}

/* Function: JudgeAnalisis
 * -----------------------
 * Given an expression in string, return 
 * its truth-value (1 or 0)
 * Return -1 if the expression is invalid
 */
int JudgeAnalisis(string jex)
{
	double valOne, valTwo;
	char variable[20], op[3], optor[5];
	char exOne[105] = "jaTemp = ", exTwo[105] = "jaTemp = ";
	
	int i;
	for(i = 0; i < 20; i++)	variable[i] = 0;
	for(i = 0; i < 3; i++)	op[i] = 0;
	for(i = 0; i < 5; i++)	optor[i] = 0;
	
	int tagOne = -1, tagTwo = -1;
	for(i = 0; i < strlen(jex); i++)
	{
		if(jex[i] == '>' || jex[i] == '<')
		{
			tagOne = i;
			optor[0] = jex[i];
			i++;
			if(jex[i] == '=')
			{
				tagTwo = i + 1;
				optor[1] = '=';
				optor[2] = 0;
			}
			else
			{
				tagTwo = i;
				optor[1] = 0;
			}
			break;
		}
		else if(jex[i] == '!' || jex[i] == '=')
		{
			tagOne = i;
			optor[0] = jex[i];
			i++;
			if(jex[i] == '=')
			{
				tagTwo = i + 1;
				optor[1] = '=';
				optor[2] = 0;
			}
			else
				return -1;
			break;
		}
	}
	if(tagOne == -1)	return -1;
	
	strcat(exOne, jex);
	exOne[tagOne + 9] = 0;
	strcat(exTwo, jex + tagTwo);
	
	LexcialAnalisis(exOne);
	
	FILE *fp = fopen("lexAnaLog.flowcharter", "r");
	fscanf(fp, "%s%s%lf", variable, op, &valOne);
	fclose(fp);
	
	LexcialAnalisis(exTwo);
	
	fp = fopen("lexAnaLog.flowcharter", "r");
	fscanf(fp, "%s%s%lf", variable, op, &valTwo);
	fclose(fp);
	
	switch(optor[0])
	{
		case '>':
			if(optor[1] == '=')
			{
				if(valOne >= valTwo)
					return 1;
				else
					return 0;
			}
			else
			{
				if(valOne > valTwo)
					return 1;
				else
					return 0;
			}
			break;
			
		case '<':
			if(optor[1] == '=')
			{
				if(valOne <= valTwo)
					return 1;
				else
					return 0;
			}
			else
			{
				if(valOne < valTwo)
					return 1;
				else
					return 0;
			}
			break;
		
		case '!':
			if(valOne != valTwo)
				return 1;
			else
				return 0;
			break;
		
		case '=':
			if(valOne == valTwo)
				return 1;
			else
				return 0;
			break;
		
		default:
			return -1;
	}
}
