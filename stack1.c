//BASIC FUNCTIONS OF STACK
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct STACK
{
	int s[SIZE];     
	int top;
}stack;




void push(stack *p,int item)
{
	if(p->top==SIZE-1)
		printf("stack overflow error");
	else
			p->s[++p->top]=item;
} //end of push function











void pop(stack *p)
{
	if(p->top==-1)
		printf("stack underflow error");
	else
		printf("deleted item=%d",p->s[p->top--]);
}

















void disp(stack *p)
{
	if(p->top==-1)
		printf("stack is empty");
	else
	{
		int i;
		for(i=p->top;i>=0;i--)
			printf("%d\n",p->s[i]);
	}
}//end










void peep(stack *p)
{
	int item;
	if(p->top==-1)
		printf("stack is empty");
	else
	{
		int i;
		printf("Enter item to search:");
		scanf("%d",&item);
		for(i=p->top;i>=0;i--)
		{
			if(p->s[i]==item)
				break;
		}
		if(i<0)
			printf("item not found");
		else
			printf("item found");
	}
}//end






void main()
{
	stack st;
	int ch,item;
	st.top=-1;
	do
	{
		printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.disp");
		printf("\n4.peep");
		printf("\n5.exit");
		printf("\nEnter ur choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter an item:");
					scanf("%d",&item);
					push(&st,item);
					break;
			case 2:	pop(&st);
					break;
			case 3:	disp(&st);
					break;
			case 4: peep(&st);
					break;
			case 5: printf("program end");
					exit(0);
			default:printf("Invalid Choice");
		}
	}while(1);

} //main() end
