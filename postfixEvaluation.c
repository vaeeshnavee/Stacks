
#include<stdio.h>
#include<math.h>
#define pf printf
#define max 30
void push(int ch);
int pop(void);
int top=-1;
char postfix[max];
int stack[max];
void main()
{
	int i,j,a,b;	
	char ch;
	pf("\nEnter the postfix expression :");
	gets(postfix);                   
	for(i=0;postfix[i]!=0;i++)       
	{
		switch(postfix[i])
		{
			case ',': continue;
			case '+':
					 b=pop();a=pop();
					 push(a+b);break;
			case '-':b=pop();a=pop();
					 push(a-b);break;
			case '*':b=pop();a=pop();
					 push(a*b);break;
			case '/':b=pop();a=pop();
					 push(a/b);break;
			case '$':b=pop();a=pop();
					 push((int)(pow(a,b)));
					 break;
			default :push((int)(postfix[i])-48);                             
		}//end of switch
	}//end of for loop
	printf("%d",stack[top]);
}
void push(int ch)
{
	if(top ==max-1)
		printf("\n\n Overflow error");
	else
	{
		top++;
		stack[top]=ch;
	}
}
int pop(void)
{
	int item;
	if(top==-1)
		printf("\n\n Underflow error");
	else
	{
		item=stack[top];
		top--;
	}
	return(item);
}

/*
#include<stdio.h>
#include<math.h>
#define pf printf
#define max 30
void push(int ch);
int pop(void);
int top=-1;
int postfix[max];
int stack[max];
char temp[max];
void main()
{
	int i,j,a,b;	
	char ch;
	pf("\nEnter the postfix expression :");
	gets(temp);
	for(i=0,j=0;temp[i];i++)
	{
		if(temp[i]!=',')
		{
			postfix[j]=postfix[j]*10+(temp[i]-48);
			postfix[j++]=postfix[j]*10+(temp[++i]-48);
		}
	}
	postfix[j]=0;
	
	for(i=0;postfix[i]!=0;i++)       
	{
	//	printf("%d\n",postfix[i]);
		switch(postfix[i])
		{
			case ',':continue;
			case '+':
					 b=pop();a=pop();
					 push(a+b);break;
			case '-':b=pop();a=pop();
					 push(a-b);break;
			case '*':b=pop();a=pop();
					 push(a*b);break;
			case '/':b=pop();a=pop();
					 push(a/b);break;
			case '$':b=pop();a=pop();
					 push((int)(pow(a,b)));
					 break;
			default :push((int)(postfix[i])-48);                             
		}//end of switch
	}//end of for loop
	printf("%d",stack[top]);
}
void push(int ch)
{
	if(top ==max-1)
		printf("\n\n Overflow error");
	else
	{
		top++;
		stack[top]=ch;
	}
}
int pop(void)
{
	int item;
	if(top==-1)
		printf("\n\n Underflow error");
	else
	{
		item=stack[top];
		top--;
	}
	return(item);
}
*/
  
   
