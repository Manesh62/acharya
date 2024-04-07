// project on parking management system

#include<stdio.h>// for including printf and scanf function
#include<conio.h>// for using getch() and unformatted output
#include<stdlib.h>
#include<string.h>

struct number{
	int nubu,num,nub,*bu_amount,*m_amount,*b_amount;
};

int count1=0,count2=0,count3=0,number=0;
char name[10];

int options(int*);
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
    int a,sw,*chk=0;
    	
	n.nubu=0;
	n.num=0;
	n.nub=0;
	n.bu_amount=0;
	n.m_amount=0;
	n.b_amount=0;
    top:
    printf("\n\t\t\t******welcome to the Parking System******\n\n\n");
    tb(n);
	sw = options(&chk);//chk is a checking variable in case of default
	
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
            showdetail();
			break;
		case 5:
		   system("cls");
           Delete();
		   break;	
		case 6:
		    system("cls");
            return 0;
		    break;
		 default:
            system("cls");
		    chk=1;
		    break;		
	}
	if (sw==1 || sw==2 || sw==3)//file specified to be created only when inputing value so it wont recreate a file after deleting it.
	{
		fi(n);
	}
    system("cls");
    goto top;
	
    return 0;
}



int options(int *chk1)
{
	int opt;
    printf("\n [1] Enter Bus records ");
	printf("\n [2] Enter Micro records");
	printf("\n [3] Enter Bike records");
	printf("\n [4] View Details");
	printf("\n [5] Delete Data");
	printf("\n [6] Exit");
	if(*chk1==1) //pointer variable used in case if the option inputted by user isnt valid.
	{
		printf("\n\nplease enter valid option");
		*chk1=0;
	}
	printf("\n\n --> ");
    scanf("%d",&opt);
    return opt;
}



void fi(struct number n)
{
	FILE *file;
    char filename[] = "log.txt";
    int amount;
    if(strcmp(name,"Bus")==0)
    {
    	amount=1000;
	}
	if(strcmp(name,"Micro")==0)
    {
    	amount=1000;
	}
	if(strcmp(name,"Bike")==0)
    {
    	amount=1500;
	}
    number++;
    file = fopen(filename, "a+");//read and write, creates new if file doesnt exist
    //number	vehicle     cost";
    fprintf(file, "%d\t%s\t%d\n",number,name,amount);   
   	fclose(file);
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
	strcpy(name,"Bus");
	count1++;
	nobu++;
	*amount1=*amount1+1000;
	return nobu;
}



int micro(int nom,int *amount2)
{    
	strcpy(name,"Micro");
	count2++;
	nom++;
	*amount2=*amount2+1000;
	return nom;
}



int bike(int nob,int *amount3)
{    
	strcpy(name,"Bike");
	nob++;
	*amount3=*amount3+1500;
	return nob;
}

void Delete()
{
	char a;
	printf("Do you want to delete the records?(y/n) - ");
	a=getch();
	
	if(a=='y')
	{
		FILE *fp;
		fp=fopen("log.txt","w");	
        fclose(fp);
	}

}


void showdetail()
{
	FILE *file;
	int nmb, amnt, counter=0;
	char veh[10], a;
	file = fopen("log.txt", "r");
	printf("\nnumber\tvehicle\tamount\n");
	printf("----------------------\n");
	if(file==NULL)
	{
		printf("\n record file doesnt exist\n");
	}
	else
	{
		while((fscanf(file,"%d%s%d",&nmb,&veh,&amnt))!=EOF)
		{
			printf("%d\t%s\t%d\n",nmb,veh,amnt);
			counter++;
		}
	}
	if(counter==0)
	{
		printf("\n");
		printf("Sorry, no records found.\n");
	}
	fclose(file);
	printf("\ncontinue?(press any button)");
	a=getch();
}
