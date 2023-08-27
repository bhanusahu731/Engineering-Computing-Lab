#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double fx(double x)
{
    return (4*pow(x,4) - 4*pow(x,2));
}
double dfx(double x)
{
    return (16*pow(x,3) - 8*x) ;
}


int main()
{
    double x, error;
    FILE *fp = fopen("output_problem_5.txt","w");
    fprintf(fp,"Initial guess\tIteration\tRoot value\t\t\tError\n\n");
    for(double i=-1;i<=1.001;i=i+0.001)
    {
    int itr=1; 
    double x0=i;
    do 
    {
        error = 0.0;
        x = x0 - (fx(x0)/dfx(x0)) ;
        error = fabs(x-x0);
        x0=x;
        itr++;
    }while(error>pow(10,(-10)));
   
    fprintf(fp,"%.3lf\t\t\t%d\t\t\t%.10lf\t\t%.10lf\n",i,itr,x,error);
    }   
    printf("Data stored in \"output_problem_5.txt\"\n");
    return 0;
}

