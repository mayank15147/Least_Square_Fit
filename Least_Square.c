#include <stdio.h>
#include <math.h>

void Linear_Eq_Solver(float A[20][20], float x[10],int n)
{
    int i,j,k;
    float c,sum=0.0;
    
    for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    /* this loop is for backward substitution*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    
}

float return_power_sum(float X[9], int n)
{
	float sum=0;
	int i=0;
	for(i=0;i<9;i++)
	{
		sum = sum + pow(X[i],n);
	}
	return sum;
}

float product_sum(float X[9], int x_pow, float Y[9])
{
	float sum = 0;
	int i = 0;
	for(i=0;i<9;i++)
	{
		float tmp;
		tmp = pow(X[i],x_pow)*Y[i];
		sum = sum + tmp;
	}
	return sum;
}

void Linear(float X[9], float Y[9])
{
	float A[20][20], x[10];
	float x_sum = return_power_sum(X,1);
	float x_2_sum = return_power_sum(X,2);
	float y_sum = return_power_sum(Y,1);
	float xy_sum = product_sum(X,1,Y);
	float a,b,y;
	
	
	printf("\nx_sum  = %f",x_sum);
	
	printf("\nx_2_sum  = %f",x_2_sum);
	printf("\ny_sum  = %f",y_sum);
	printf("\nxy_sum  = %f",xy_sum);	
	

	a = ((9*xy_sum) - (x_sum*y_sum))/((9*x_2_sum) - (x_sum*x_sum));
	b = ((y_sum*x_2_sum) - (x_sum*xy_sum))/((9*x_2_sum) - (x_sum*x_sum));
	
	printf("\n\nLinear Equation : ");
	printf("\ny = %f + %fx",b,a);
	printf("\n");
	
	int i;
	printf("\n\nValues Calculated from Linear Equation : ");
	for(i=0;i<9;i++)
	{
		printf("\nY(%f) = %f",X[i],b+(a*X[i]));
	}
	printf("\n");

} 

void Quadratic(float X[9], float Y[9])
{

	float A[20][20], x[10];
	float x_sum = return_power_sum(X,1);
	float x_2_sum = return_power_sum(X,2);
	float x_3_sum = return_power_sum(X,3);
	float x_4_sum = return_power_sum(X,4);
	float y_sum = return_power_sum(Y,1);
	float xy_sum = product_sum(X,1,Y);
	float x2y_sum = product_sum(X,2,Y);
	
	A[1][1] = 9;
	A[1][2] = x_sum;
	A[1][3] = x_2_sum;
	A[1][4] = y_sum;
	A[2][1] = x_sum;
	A[2][2] = x_2_sum;
	A[2][3] = x_3_sum;
	A[2][4] = xy_sum;
	A[3][1] = x_2_sum;
	A[3][2] = x_3_sum;
	A[3][3] = x_4_sum;
	A[3][4] = x2y_sum;

	Linear_Eq_Solver(A,x,3);

	printf("\n\nQuadratic Equation is : ");
	printf("\ny = %f + %fx + %fx2",x[1],x[2],x[3]);
	printf("\n");
	
	int i;
	printf("\n\nValues Calculated from Linear Equation : ");
	for(i=1;i<=9;i++)
	{
		printf("\nY(%f) = %f",X[i-1],(x[1]+(x[2]*X[i-1])+(x[3]*X[i-1]*X[i-1])));
	}
	printf("\n");

}
void Cubic(float X[9], float Y[9])
{

	float A[20][20], x[10];
	float x_sum = return_power_sum(X,1);
	float x_2_sum = return_power_sum(X,2);
	float x_3_sum = return_power_sum(X,3);
	float x_4_sum = return_power_sum(X,4);
	float x_5_sum = return_power_sum(X,5);
	float x_6_sum = return_power_sum(X,6);
	float y_sum = return_power_sum(Y,1);
	float xy_sum = product_sum(X,1,Y);
	float x2y_sum = product_sum(X,2,Y);
	float x3y_sum = product_sum(X,3,Y);
	
	A[1][1] = 9;
	A[1][2] = x_sum;
	A[1][3] = x_2_sum;
	A[1][4] = x_3_sum;
	A[1][5] = y_sum;

	A[2][1] = x_sum;
	A[2][2] = x_2_sum;
	A[2][3] = x_3_sum;
	A[2][4] = x_4_sum;
	A[2][5] = xy_sum;

	A[3][1] = x_2_sum;
	A[3][2] = x_3_sum;
	A[3][3] = x_4_sum;
	A[3][4] = x_5_sum;
	A[3][5] = x2y_sum;

	A[4][1] = x_3_sum;
	A[4][2] = x_4_sum;
	A[4][3] = x_5_sum;
	A[4][4] = x_6_sum;
	A[4][5] = x3y_sum;
	
	Linear_Eq_Solver(A,x,4);

	printf("\n\nCubic Equation is : ");
	printf("\ny = %f + %fx + %fx2 +%fx3",x[1],x[2],x[3],x[4]);
	printf("\n");
	
	int i;
	printf("\n\nValues Calculated from Linear Equation : ");
	for(i=1;i<=9;i++)
	{
		printf("\nY(%f) = %f",X[i-1],(x[1]+(x[2]*X[i-1])+(x[3]*X[i-1]*X[i-1])+(x[4]*X[i-1]*X[i-1]*X[i-1])));
	}
	printf("\n");

}
int main()
{
	
	int ch;
	float X[9] = {-4, -3, -2, -1, 0, 1 ,2, 3, 4};
	float Y[9] = {0, 0, 0, 0 ,1, 0, 0 ,0 ,0};
	
	printf("\n\t\t\tLeast Square Fit ");
	printf("\n1. Linear Fit");
	printf("\n2. Quadratic Fit");
	printf("\n3. Cubic Fit");
	printf("\n\tEnter the choice : ");
	scanf("%d",&ch);
	
	switch(ch) {
	case 1:	Linear(X,Y);
		break;
	case 2: Quadratic(X,Y);
		break;
	case 3: Cubic(X,Y);
		;break;
	default : printf("Invalid Choice");
	}
	return 0;
}
