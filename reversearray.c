
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    int n,a[100],temp;
    fp=fopen("array.txt","r");              //OPENING THE FILE "array.txt" TO READ THE DATA FROM  IT
    fscanf(fp,"%d",&n);                     // CONSIDERING THE FIRST VALUE TO BE THE SIZE OF THE ARRAY
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
    for(int i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-i];
        a[n-i]=temp;
    }
    fclose(fp);
    fopen("array1.txt","w");                 //OPENING THE FILE "array1.txt" TO WRITE THE REVERSED ARRAY INTO IT
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d  ",a[i]);
    }
    fclose(fp);
}
