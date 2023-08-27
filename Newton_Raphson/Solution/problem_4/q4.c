#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//functions
double f1(double x,double y,double z)
{
    return exp(x) - (8*x*(sin(y))) ; 
}
double f2(double x,double y,double z)
{
    return (x + y -1) ;
}
double f3(double x,double y,double z)
{
    return pow((z-1),3);
}

//derivatives of functions
//-------df1-------//
double df1x(double x,double y,double z)
{
    return ( exp(x) - 8*sin(y) );
}
double df1y(double x,double y,double z)
{
    return ( -8*x*cos(y) );
}
double df1z(double x,double y,double z)
{
    return 0.0;
}
//-----df2--------//
double df2x(double x,double y,double z)
{
    return 1.0;
}
double df2y(double x,double y,double z)
{
    return 1.0;
}
double df2z(double x,double y,double z)
{
    return 0.0;
}

//-------df3-------//
double df3x(double x,double y,double z)
{
    return 0.0;
}
double df3y(double x,double y,double z)
{
    return 0.0;
}
double df3z(double x,double y,double z)
{
    return ( 3*pow((z-1),2) );
}

//-----main function--------//
int main()
{
    double x0,y0,z0,x1,y1,z1;
    double a11,a12,a13,a21,a22,a23,a31,a32,a33,modJ,error;
    
    printf("Entre the initial guesses x,y,z value\n");
    scanf("%lf\n%lf\n%lf",&x0,&y0,&z0);
    FILE *fp = fopen("output_problem_4.txt","w");
    fprintf(fp,"\nInitial guesses are-\nx1 = %lf\nx2 = %lf\nx3 = %lf\n\n",x0,y0,z0);
    fprintf(fp,"\nIteration\t\t\tx\t\t\t\ty\t\t\t\tz\t\t\tError\n\n");
    int itr = 1;
    do
    {
        error = 0.0;
        modJ = df1x(x0,y0,z0)*(df2y(x0,y0,z0)*df3z(x0,y0,z0) - df2z(x0,y0,z0)*df3y(x0,y0,z0))
               +df1y(x0,y0,z0)*(df2z(x0,y0,z0)*df3x(x0,y0,z0) - df2x(x0,y0,z0)*df3z(x0,y0,z0))
               +df1z(x0,y0,z0)*(df2x(x0,y0,z0)*df3y(x0,y0,z0) - df2y(x0,y0,z0)*df3x(x0,y0,z0)) ;
        
        a11 = (df2y(x0,y0,z0)*df3z(x0,y0,z0) - df2z(x0,y0,z0)*df3y(x0,y0,z0))/modJ ;
        a12 = (df1z(x0,y0,z0)*df3y(x0,y0,z0) - df1y(x0,y0,z0)*df3z(x0,y0,z0))/modJ ;
        a13 = (df1y(x0,y0,z0)*df2z(x0,y0,z0) - df1z(x0,y0,z0)*df2y(x0,y0,z0))/modJ ;
        
        a21 = (df2z(x0,y0,z0)*df3x(x0,y0,z0) - df2x(x0,y0,z0)*df3z(x0,y0,z0))/modJ ;
        a22 = (df1x(x0,y0,z0)*df3z(x0,y0,z0) - df1z(x0,y0,z0)*df3x(x0,y0,z0))/modJ ;
        a23 = (df1z(x0,y0,z0)*df2x(x0,y0,z0) - df1x(x0,y0,z0)*df2z(x0,y0,z0))/modJ ;
        
        a31 = (df2x(x0,y0,z0)*df3y(x0,y0,z0) - df3y(x0,y0,z0)*df3x(x0,y0,z0))/modJ ;
        a32 = (df1y(x0,y0,z0)*df3x(x0,y0,z0) - df1x(x0,y0,z0)*df3y(x0,y0,z0))/modJ ;
        a33 = (df1x(x0,y0,z0)*df2y(x0,y0,z0) - df1y(x0,y0,z0)*df2x(x0,y0,z0))/modJ ;
        
        x1 = x0 - (a11*f1(x0,y0,z0) + a12*f2(x0,y0,z0) + a13*f3(x0,y0,z0)) ;
        y1 = y0 - (a21*f1(x0,y0,z0) + a22*f2(x0,y0,z0) + a23*f3(x0,y0,z0)) ;
        z1 = z0 - (a31*f1(x0,y0,z0) + a32*f2(x0,y0,z0) + a33*f3(x0,y0,z0)) ;
        
        error = fabs((x1+y1+z1)-(x0+y0+z0));
        
        fprintf(fp,"%d\t\t\t\t%.10lf\t%.10lf\t%.10lf\t%.10lf\n",itr,x1,y1,z1,error);
        
        x0 = x1;
        y0 = y1;
        z0 = z1;
        
        itr++;
        
    }while(error> pow(10,(-10)));
    
    fprintf(fp,"\n\nAnswer -\nx1 = %.10lf\nx2 = %.10lf\nx3 = %.10lf\n\n",x0,y0,z0);
    printf("\nNumber of iteraions: %d\nAnswer -\nx1 = %.10lf\nx2 = %.10lf\nx3 = %.10lf\n\n",itr,x0,y0,z0);
    printf("Data saved in \"output_problem_4.txt\"");
    
     return 0;
}


