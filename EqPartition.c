#include<stdio.h>
#define MAXSTATE 100
#define MAXGROUP 100

int max_g,nos,temp,ku;

typedef struct state_table_rows
{
	char ps_name,ns_name_o,ns_name_i;
	int out1,out0,role,grp;
}st;

st table[MAXSTATE];

int main()
{
	int i,j;
	printf("Enter the number of steps involved: ");
	scanf("%d",&nos);
	
	i=0;
	while(i<nos)
	{
		
		printf("\nEnter the PS, NSx0, Zx0 NSx1 and Zx1: ");
		fflush(stdin);
		scanf("%c",&table[i].ps_name);
		fflush(stdin);
		scanf("%c",&table[i].ns_name_o);
		fflush(stdin);
		scanf("%d",&table[i].out0);
		fflush(stdin);
		scanf("%c",&table[i].ns_name_i);
		fflush(stdin);
		scanf("%d",&table[i].out1);
		table[i].role=0;
		table[i].grp=0;
	//	printf("%c %c %d %c %d",table[i].ps_name,table[i].ns_name_o,table[i].out0,table[i].ns_name_i,table[i].out1);
		i++;
	}
	
	i=0;
	while(i<nos)
	{
		if(table[i].role==0)
		{
				table[i].role=i+1;
			for(j=i+1;j<nos;j++)
			{
				if((table[i].out0==table[j].out0)&&(table[i].out1==table[j].out1))
				{
					table[j].role=i+1;
					if(max_g<i+1)
						max_g=i+1;
				}
			}
		}
		i++;	
	}
	//BUBBLE SORT IS NEEDED TO REFINE
	ku=1;
	i=0;
	while((i<nos)&&(ku))
	{
			ku=0;
			
			while((j<nos)&&(table[j].grp==0))
			{
				if(table[j].ns_name_o==table[i].ns_name_o)&&(table[j].ns_name_i==table[i].ns_name_i)
			}	
		
	}
	i=0;
	while(i<nos)
	{
		printf("%d",table[i].role);
		i++;
	}	
	
			
}
