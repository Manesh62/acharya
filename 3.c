// wap to finds if two  matrices are suitable for addition.
// one function to read the order and values in matrix.
// another function for checking the suitbaility for addition of matrix.
#include<stdio.h>
void read(int ,int *,int *);
int check(int ,int ,int ,int );

int main()
{
	int row1,col1,row2,col2;
	int a[15][15],b[15][15];
	printf("For the First matrix\n");
	read(a,&row1,&col1);
	
	printf("For the First matrix\n");
	read(b,&row2,&col2);
	// for checking addition of matrix
	 // if (areMatricesSuitable(rows1, cols1, rows2, cols2))
	if(check(row1,col1,row2,col2))
	{
		printf(" Two Matrix is suitable For addtion");
	}
	else
	{
		printf("Not suitable");
	}
	return 0;
}
//void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols)
void read(int x[15][15],int *r,int *c)
{
	printf("enter the rows and coloums in matrix");
	scanf("%d %d",r,c);
	for(int i=0;i<*r;i++)
	{
		for(int j=0;j<*c;j++)
		{
			printf("Entered element [%d][%d]",i+1,j+1);
			scanf("%d",&x[i][j]);
		}
	}
}
int check(int r1,int c1,int r2,int c2)
{
	return (r1=r2 && c1=c2);
}