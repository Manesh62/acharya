// project on parking management system
#include<stdio.h>// for including printf and scanf function
#include<conio.h>// for using getch() and unformatted output
#include<stdlib.h>
struct number
{
	int nobu,nom,nob;
};
int amount=0,count=0,nobu,nom,nob;
void bus();
void micro();
void bike();
void Delete();
void showdetail();
void main()
{   
   clrscr();
   char option;
   FILE  *fptr;
   fptr=fopen("man.txt","r+b");
   if(fptr==NULL)
   {
   	  fptr=fopen("man.txt","w+b");
   	  if(fptr==NULL)
   	  {
   	  	printf("File cannot be created !!!!!!!!\n");
   	  	exit(1);
		 }
	  }	
	while(1)
	{
		printf("\n ******welcome to the Parking System******");
		options();
		option= getch();
		printf("%c \n",option);
	
		switch(option)
		{
			case 'a':
				bus();
				break;
			case 'b':
				micro();
				break;
			case 'c':
			    bike();
				break;	
			case 'd':
				showdetail();
				break;
			case 'e':
			   Delete();
			   break;	
			case 'x':
			  return 0;
			  break;
			 case 'r':
			 system("cls");
			 break; 
			 default:
			 printf("pls enter the required choice");
			 break;	
				
		}
	}
	  
	  
	  
	  
	  
}
void options()
{
	printf("\n Enter a for entering the data  of the bus ");
	printf("\n Enter b for entering data of  the micro number");
	printf("\n Enter c for entering the data of  the cycle");
	printf("\n Enter d for showing the  status");
	printf("\n Enter e for deleting data");
	printf("\n Enter the x for exit");
	printf("\n Enter the r for clear screen");
	printf("\n\n");
}
void bus()
{    
    printf("\n Successfully the data is entered\n");
	nobu++;
	amount=amount+100;
	count++;
	
}
void micro()
{   printf("\n Successfully the data is entered\n");
	nom++;
	amount=amount+750;
	count++;
}
void bike()
{   printf("\n Successfully the data is entered\n");
	nob++;
	amount=amount+500;
	count++;
}
void showdetail()
{
	printf("Number of bus is %d\n",nobu);
	printf("Number of micro is %d\n",nom);
	printf("Number of bike is %d\n",nob);
	printf("total number of vehicles is %d\n",count);
	printf("Total amount gain is %d\n",amount);
}
void Delete()
{
	nobu=0;
	nom=0;
	nob=0;
	amount=0;
	count=0;
}