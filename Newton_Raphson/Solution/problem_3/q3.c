#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//--------given function and its derivative-----------//
double fx(double x)
{
    return x*x*(1+pow(sin(x),2));
}
double dfx(double x)
{
    return x*x*sin(2*x) + 2*x*(1+pow(sin(x),2)) ;
}
double d2fx(double x)
{
    return 2*x*x*cos(2*x) + 4*x*sin(2*x) + 2*(1+pow(sin(x),2)) ;
}
//---------functon for NR method---------//
double gx(double x)
{
    return 2*(x-2) + 2*fx(x)*dfx(x) ;
}
double dgx(double x)
{
    return 2 + 2*(fx(x)*d2fx(x) + 2*pow(dfx(x),2)) ;
}


int main()
{
    double x0=0.0,x1,error,d;

    FILE *fp = fopen("output_problem_3.txt","w");

    fprintf(fp,"Iteraton\t\tStroke\t\t\tError\n\n");
    int itr=1;
    do 
    {
        error = 0.0;  
        x1 = x0 - (gx(x0)/dgx(x0)) ;
        error = fabs(x1-x0);
        d = sqrt(pow((x1-2),2) + pow(fx(x1),2)) ;
        fprintf(fp,"%d\t\t\t\t%.5lf         %lf\n",itr,d,error);
        x0 = x1;
        itr++;
       
    }while(error > pow(10,(-6)));

    fprintf(fp,"\n\nValue of stroke = %.5lf\nDiametre of circle = %.5lf\n",d,2*d);
    printf("\nValue of stroke = %.5lf\nDiametre of circle = %.5lf\n",d,2*d);
    printf("Data saved in \"output_problem_3.txt\"\n");
    
    fclose(fp);
    return 0;
}
