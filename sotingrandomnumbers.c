
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    int r,a[100],temp;
    fp=fopen("array.txt","w+");        //OPENING THE FILE TO READ AND WRITE THE INTO IT
    for(int i=0;i<100;i++)
    {
        r=rand();
        r=r%100;
        fprintf(fp,"%d ",r);
    }
    rewind(fp);                      //INITIALIZE THE POINTER TO THE START OF THE FILE
    for(int i=0;i<100;i++)
    {
        fscanf(fp,"%d",&a[i]);              //INITIALIZING THE INTERGERS IN THE FILE TO THE ARRAY
    }
    fclose(fp);
    for(int i=0;i<99;i++)
    {
        for(int j=0;j<99-i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
