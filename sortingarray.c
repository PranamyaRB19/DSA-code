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
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    fclose(fp);
    fopen("array1.txt","w");                 //OPENING THE FILE "array1.txt" TO WRITE THE SORTED ARRAY INTO IT
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d  ",a[i]);
    }
    fclose(fp);
}
