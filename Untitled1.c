// project on parking management system

#include<stdio.h>// for including printf and scanf function
#include<conio.h>// for using getch() and unformatted output
#include<stdlib.h>
#include<string.h>

struct number{
	int nubu,num,nub,*bu_amount,*m_amount,*b_amount;
};

int count1=0,count2=0,count3=0;

int options();
void tb(struct number n);
int bus(int,int *);
int micro(int,int *);
void fi();
int bike(int,int *);
void showdetail();
void Delete();

int main()
{
    
	struct number n;
    int a,sw;
    	
	n.nubu=0;
	n.num=0;
	n.nub=0;
	n.bu_amount=0;
	n.m_amount=0;
	n.b_amount=0;
    top:
    printf("\n\t\t\t******welcome to the Parking System******\n\n\n");
    tb(n);
	sw = options();
	
	switch(sw)
	{
		case 1:
            system("cls");
			n.nubu=bus(n.nubu,&n.bu_amount);
			break;
		case 2:
			system("cls");
            n.num=micro(n.num,&n.m_amount);
			break;
		case 3:
		    system("cls");
            n.nub=bike(n.nub,&n.b_amount);
			break;	
		case 4:
			system("cls");
            //showdetail();
			break;
		case 5:
		   system("cls");
           //Delete();
		   break;	
		case 6:
		    system("cls");
            return 0;
		    break;
		 default:
            system("cls");
		    printf("pls enter the required choice");
		    break;		
	}

	fi(n);
    system("cls");
    goto top;
	
    return 0;
}

void fi(struct number n)
{
	FILE *file;
    char filename[] = "output.txt";
    char text[] = "vehicle    number    cost";
    file = fopen(filename, "r+");
    if(file==NULL)
    {
   	    file=fopen("output.txt","w+");
   	    fprintf(file, "%s\n", text);
    }
    fprintf(file, "%d\n",n.bu_amount);   
   	fclose(file);
}

int options()
{
	int opt;
    printf("\n [1] Enter Bus records ");
	printf("\n [2] Enter Micro records");
	printf("\n [3] Enter Bike records");
	printf("\n [4] View Details");
	printf("\n [5] Delete Data");
	printf("\n [6] Exit");
	printf("\n\n --> ");
    scanf("%d",&opt);
    return opt;
}

void tb(struct number n)
{
    printf("\n\t\t\t [1] BUS");
    printf("\t [2] MICRO");
    printf("\t [3] BIKE\n");
    printf("\t\t\t ----------------------------------------\n");
    printf("\tvehicle count:-\t     %d\t\t     %d\t\t     %d\n",n.nubu,n.num,n.nub);
    if(count1==0 && count2==0 && count3==0)
    {
    	printf("\t         cost:-\t     %d\t\t     %d\t\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	if(count1>0 && count2==0 && count3==0)
	{
    	printf("\t         cost:-\t   %d\t\t     %d\t\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	if(count1==0 && count2>0 && count3==0)
	{
    	printf("\t         cost:-\t     %d\t\t   %d\t\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	if(count1==0 && count2==0 && count3>0)
	{
    	printf("\t         cost:-\t     %d\t\t   %d\t\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	if(count1>0 && count2>0)
	{
    	printf("\t         cost:-\t   %d\t\t    %d\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	printf("\n");
	
}

int bus(int nobu,int *amount1)
{    
	count1++;
	nobu++;
	*amount1=*amount1+1000;
	return nobu;
}

int micro(int nom,int *amount2)
{    
	count2++;
	nom++;
	*amount2=*amount2+1050;
	return nom;
}

int bike(int nob,int *amount3)
{    
	nob++;
	*amount3=*amount3+1500;
	return nob;
}
