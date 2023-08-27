#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fx(double x)
{
    return (pow(x,3) - 11) ;
}

double dfx(double x)
{
    return 3*pow(x,2) ;
}

int main()
{
    double x0,tol;
    int N;
    printf("Entre the value of initial guess\n");
    scanf("%lf",&x0);
    printf("\nEntre the value of Tolerence\n");
    scanf("%lf",&tol);
    printf("\nEntre the value of maximum number of iteratons\n");
    scanf("%d",&N);
    FILE *fp = fopen("output_problem_1.txt","w"); 
    fprintf(fp,"The Roots and Error for-\ninitial guess: %lf\nTolerence value: %lf\n\n",x0,tol);
    int i = 1;
    fprintf(fp,"\niteraton\tRoot\t\t\tError\n");
    
    while(i<=N)
    { 
        double e = 0.0; 
        double x = x0 - (fx(x0)/dfx(x0)) ;   
        e=fabs(x-x0);
        fprintf(fp,"%d\t\t\t%lf\t\t%lf\n",i,x,e);
        if(e<=tol)
        {   
            fprintf(fp,"\nThe procedure was successful\nAns: %lf\n",x);
            printf("\nThe procedure was successful\nAns: %lf\n",x);
            break;
        }
        
        else
        {
            i=i+1;
            x0=x;
        }
        
        if(i==N+1)
        {
        printf("The method failed after %d iterations\n",N);
        }
    }
    
    printf("The output data \"saved in output_problrm_1.txt\"");
    
return 0;
}