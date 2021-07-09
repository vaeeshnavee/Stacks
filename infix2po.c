#include<stdio.h>
#include<conio.h>
#define max 30
void push (char ch);
char pop(void);
int prec(char op);
int top=-1;
char infix[max],stack[max],postfix[max];
void main()
{
	int i,j;
	char ch;
	printf("\nEnter Infix Notation : ");
	scanf("%s", infix);
	for(i=0,j=0;infix[i]!='\0';i++)
	{
		switch(infix[i])
		{
			case '(': push(infix[i]);
						break;
			case ')': while((ch=pop()) != '(')
						 postfix[j++] = ch;
					  break;
			case '+':
			case '-' :
			case '*' :
			case '/':
			case '$': if(top ==-1 || stack[top] == '(' || (prec(infix[i])>prec(stack[top])))
							push(infix[i]);
						 else
						 {
							while(prec(infix[i])<=prec(stack[top]))
							{
								ch = pop();
								postfix[j++] = ch;
							}
							push(infix[i]);
						 }
						 break;
				default: postfix[j++]=infix[i];
			}	/* switch ends*/
		}	/* for ends */
		while(top!= -1)
			postfix[j++]=pop();
		postfix[j]='\0';
		printf("The postfix expression is :\n\t\t\t\t %s ",postfix);
} //main() end
void push(char ch)
{
	if(top ==max-1)
		printf("\noverflow");
	else
	{
		top++;
		stack[top]=ch;
	}
}
char pop(void)
{
	char ch;
	if(top==-1)
		printf("\n underflow error");
	else
	{
		ch=stack[top];
		top--;
	}
	return(ch);
} //pop() end

int prec(char op)
{
	int pre;
	switch(op)
	{
		case '+':
		case '-':pre =0;
					break;
		case '*':
		case '/':
					pre=1;
					break;
		case '$':
					pre=2;
					break;
		default:
					pre =-1;
		}
	return(pre);
}
