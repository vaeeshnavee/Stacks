#include<stdio.h>
#define pf printf
#define max 30
void push(char ch);
char pop(void);
int prec(char op);

int top=-1;
char infix[max],stack[max],prefix[max];

void main()
{
	int i,j;	
	char ch;
	pf("\nEnter infix notation :");
	scanf("%s", infix);
	for(i=0;infix[i]!='\0';i++); //self ending loop
	
	for(--i,j=0;i>=0;i--)       
	{
		switch(infix[i])
		{
			case ')':	push(infix[i]);   break;
			case '(':
				while((ch = pop()) != ')')	
					prefix[j++] = ch;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '$':
				if(top ==-1 || stack[top] == ')' || (prec(infix[i])>=prec(stack[top])))
					push(infix[i]);
				else
				{
					while(top!=-1 && (prec(infix[i]) < prec(stack[top]))) 
					{
						ch = pop();
						prefix[j++] = ch;
					}
					push(infix[i]);
				}
				break;
			default:prefix[j++]=infix[i];
		}
	}//end of for loop
	while(top!=-1)	
		prefix[j++] = pop();
	prefix[j]='\0';	
	pf("The prefix expression is :\n\t\t\t\t");
	for(i=j-1; i>=0; i--)	
		printf("%c", prefix[i]);
}

void push(char ch)
{
	if(top ==max-1)
		printf("\n\n overflow");
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
		printf("\n\n underflow error");
	else
	{
		ch=stack[top];
		top--;
	}
	return(ch);
}

int prec(char op)
{
	int pre;
	switch(op)
	{
		case '+':
		case '-':
			pre =0;
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
