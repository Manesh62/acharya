// project on parking management system

#include<stdio.h>// for including printf and scanf function
#include<conio.h>// for using getch() and unformatted output
#include<stdlib.h>

struct number{
	int nubu,num,nub;
};

int options();
void tb(struct number n);
int bus(int);
int micro();
int bike();
void showdetail();
void Delete();

int main(){

    struct number n;
    int a,sw;
	n.nubu=0;
	n.num=0;
	n.nub=0;
    top:
    printf("\n\t\t\t******welcome to the Parking System******\n\n\n");
    tb(n);
	sw = options();
	
	switch(sw)
	{
		case 1:
            system("cls");
			n.nubu=bus(n.nubu);
			break;
		case 2:
			system("cls");
            //micro();
			break;
		case 3:
		    system("cls");
            //bike();
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

    system("cls");
    goto top;

    return 0;
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

void tb(struct number n){
    printf("\n\t\t\t [1] BUS");
    printf("\t [2] MICRO");
    printf("\t [3] BIKE\n");
    printf("\t\t\t ----------------------------------------\n");
    printf("\t\t\t     %d\t\t     %d\t\t     %d\n",n.nubu,n.num,n.nub);
}

int bus(int nobu)
{    
	printf("\n Successfully the data is entered\n");
	nobu++;
	return nobu;
}
