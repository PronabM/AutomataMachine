#include<stdio.h>
#define MAX 500

/*int stack[MAX];
int top=-1;

void push(int x)
{
	if(top<=MAX-1)
	{
		stack[++top]=x;	
	}	
}

void pop()
{
	if(top>=0)
		top--;
}*/


int main()
{
	int inp[MAX][3];
	int i,n,s;
	
	printf("Enter the number of states: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d %d %d",&inp[i][0],&inp[i][1],&inp[i][2]);
	
	printf("Enter the state for which lambda closure will be calculated: ");
	scanf("%d",&s);
	
	printf("{ %c ",s+64);
	
	do
	{
		s=inp[s-1][2];
		printf(" %c ",s+64);
	}while(inp[s-1][2]!=0);
	
	printf(" }");
	return 0;	
}
