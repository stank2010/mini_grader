#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/*

addition : debug temp on function run 

*/

void working();
bool run(char *name,char *add);
char read(char *sol);
void ToString(char *No,int a);
bool ChNULL(char a); // Add


int main()
{	
	working();
	scanf(" ");
	return 0;
}

void working()
{
	char a[100],b[100];
	int n;
	printf("Enter Your File name ( .exe ) : "); scanf("%s",a);
	printf("Enter Number Of testcase : "); scanf("%d",&n);
	
	printf("\nAnswer : ");
	for(int i=1;i<=n;i++)
	{
		//system("cls");
		char No[50];
		ToString(No,i);
		//printf("\n%s %s\n",a,No);		
		if(!run(a,No))break;
		printf("%c",read(No));	
	}
}


bool ChNULL(char a)
{
	return a!='\0'&&a!='\n'&&a!=' ';
}

void ToString(char *No,int a)
{
	int k=0;
	
	while(a>0)
	{
		No[k++]='0'+a%10;
		a/=10;
	}
	
	No[k]=0;
	
	for(int i=0;i<k/2;i++)
	{
		char c=No[i];
		No[i]=No[k-i-1];
		No[k-i-1]=c;
	}
}

bool run(char *name,char *add)
{
	char temp[1000]="";
	strcat(temp,name);
	strcat(temp,".exe < submission\\");
	strcat(temp,add);
	strcat(temp,".in > ans.test");
	
	//puts(temp);
	
	if(system(temp))
	{
		printf("Your file not found!");
		return 0;
	}
	return 1;
}

char read(char *sol)
{
	FILE *ans=fopen("ans.test","r");
	
	char path[200] = "submission\\";
	strcat(path,sol);
	strcat(path,".sol");
	FILE *comp = fopen(path,"r");
	
	if(comp==NULL || ans == NULL)return 'X';
	
	char ex_sol[1001],ex_ans[1001];
	

	while( fgets(ex_sol,1000,comp)!=NULL && fgets(ex_ans,1000,ans)!=NULL )
	{
		//puts(ex_sol);puts(ex_ans);
		for(int i=0;ex_sol[i]!=0 || ex_ans[i]!=0 ; i++)
		{
			if(ex_sol[i]!=ex_ans[i] && ChNULL(ex_ans[i]))
				return '-';	
		}
	}
	
	return 'P';
}
