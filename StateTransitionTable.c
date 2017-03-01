#include<stdio.h>
#define MAXSTATES 100

int n;

typedef struct block
{
	int ns,z;
}blk;

typedef struct partition
{
	blk b[MAXSTATES][2];
	int role[MAXSTATES]; 
}prt;

prt p;

int getDecimalized(int x)
{
	x=x-65;
	return(x);
}


int getAlpha(int x)
{
	x=x+65;
	return(x);
}

int main()
{
	//p0 i.e. creation						:WORKING
	int i,j,max_g=0,ku=1,t;
	printf("Enter the number of states:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&p.b[i][0].ns,&p.b[i][0].z,&p.b[i][1].ns,&p.b[i][1].z);
		p.role[i]=0;	
	}
	
	//p1 i.e primitive sorting				:WORKING
	for(i=0;i<n;i++)
	{
		if(p.role[i]==0)
		{
			p.role[i]=i+1;
			for(j=i+1;j<n;j++)
			{
				if((p.b[j][0].z==p.b[i][0].z)&&(p.b[j][1].z==p.b[i][1].z))
				{
					p.role[j]=p.role[i];
					if(max_g<p.role[j])
						max_g=p.role[j];
				}
			}
		}
	} 
	
	for(i=0;((i<n)&&(ku));i++)
	{
		ku=0;
		for(j=i+1;j<n;j++)
		{
			if(p.role[j]==p.role[i])
			{
				if((p.role[(p.b[j][0].ns)]==p.role[(p.b[i][0].ns)])&&(p.role[(p.b[j][1].ns)]==p.role[(p.b[i][1].ns)]))
				{
					p.role[j]=p.role[i];
					ku=1;	
				}
				else
					p.role[j]=p.role[j]*(j+1)+19;	
			}	
		}
	}
	int k=1000;
	for(i=0;i<n;i++)
	{
		if(p.role[i]<1000)
		{
			t=p.role[i];
			p.role[i]=k;
			printf("(%c",getAlpha(i));
			for(j=i+1;j<n;j++)
			{
				if(p.role[j]==t)
				{
					printf(" %c",getAlpha(j));
					p.role[j]=k;		
				}	
			}
			k+=50;
			k++;
			printf(")");
		}
			
	}
	printf("\nOptimized Table: ");
	printf("\nPS\tNS@0\tZ@0\tNS@1\tZ@1");
	j=1000;
	for(i=0;i<n;i++,j+=50)
	{
		if(p.role[i]>=j)
			printf("\n%c\t%c\t%d\t%c\t%d",p.role[i]%10+97,p.role[(p.b[i][0].ns)]%10+97,p.b[i][0].z,p.role[(p.b[i][1].ns)]%10+97,p.b[i][1].z);
		else
			j-=50;
	}
	
	//printing table needed for debugging
	for(i=0;i<n;i++)
		printf("%d ",p.role[i]);	
	
	return(0);
}
