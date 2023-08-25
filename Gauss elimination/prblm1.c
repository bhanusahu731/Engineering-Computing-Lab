#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{  int m,n;
   printf("enter the dimension of augmented matrix\n");
   scanf("%d\t%d",&m,&n);


   float a[m][n],x[m];
   int i,j,k;
    FILE*read_mat;
    read_mat=fopen("input_1e.txt","r");
  for(i=1;i<n;i++){
 for (j=1;j<n+1;j++){
    fscanf(read_mat,"%f",&a[i][j]);
  }
} 
for(i=1;i<=n;i++){
 for(j=1;j<=n+1;j++){
  printf("%f\t",a[i][j]);
 }
printf("\n");
}
fclose(read_mat);


    //forward substitution
    for(j=1;j<=n;j++)
    {
        for(i=j+1;i<=m;i++)
        {
            float ratio = a[i][j]/a[j][j];
            for(k=1;k<=n;k++)
            {
                a[i][k]=a[i][k]-ratio*a[j][k];
            }
        }
    }
     printf("The Echelon form is\n");

     for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%f\t",a[i][j]);
        }
        printf("\n");
    }

     //backward substitution
    FILE*out_mat;
    out_mat=fopen("output_1e.txt","w");

     fprintf(out_mat,"The Echelon form is\n");

     for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            fprintf(out_mat,"%f\t",a[i][j]);
        }
        fprintf(out_mat,"\n");
    }
     if(a[m][m]!=0)
     {   fprintf(out_mat,"The solution of the given set of equation is\n");

         x[m] = a[m][n]/a[m][m];

         fprintf(out_mat,"x%d = %f\n",m,x[m]);

         for(i=(m-1);i>=1;i--)
         {
            float sum = 0;
            for(j=(i+1);j<=n;j++)
            {
                sum = sum + a[i][j]*x[j];
            }

            x[i] = (a[i][n]-sum)/a[i][i];

             fprintf(out_mat,"x%d = %f\n",i,x[i]);
         }
     }
     else if (a[m][m]==0 && a[m][n]!=0)
     {
         fprintf(out_mat,"There is NO solution");
     }
     else
     {
         fprintf(out_mat,"There is MULTIPLE solution");
     }
     printf("There is an output file created");
fclose(out_mat);
    return 0;
}
