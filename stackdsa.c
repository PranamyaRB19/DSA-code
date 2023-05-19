#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
FILE *fp1,*fp2,*fp3,*fp4,*fp5;
void push(FILE *fp1,FILE *fp2,FILE *fp3)
{
    int ele;
    fp2=fopen("stack.txt","w");
    if(top==MAX)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        fscanf(fp1,"%d",&ele);
        stack[top]=ele;
        //printf("%d",stack[top]);
        fprintf(fp3,"%d\n",stack[top]);
    }
    for(int i=0;i<=top;i++)
    {
        //printf("%d ",stack[i]);
        fprintf(fp2,"%d\n",stack[i]);
    }
    fclose(fp2);
}
void pop(FILE *fp2,FILE *fp4)
{
    int ele;
    if(top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        ele=stack[top];
        top--;
        fprintf(fp4,"%d\t",ele);
    }
    fp2=fopen("stack.txt","w");
    for(int i=0;i<=top;i++)
    {
        fprintf(fp2,"%d\n",stack[i]);
    }
    fclose(fp2);
}
main()
{

    int r,flag=1,ch;
    fp1=fopen("random.txt","w+");

    fp3=fopen("push.txt","w+");
    fp4=fopen("pop.txt","w+");
    fp5=fopen("operation.txt","w+");
    for(int i=0;i<1000;i++)
    {
        fprintf(fp1,"%d\t",rand()%1000);
    }
    fclose(fp1);
    fp1=fopen("random.txt","r");
    while(flag)
    {
        printf("1.Push,2.Pop,3.Exit\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(fp1,fp2,fp3);
            fprintf(fp5,"Push\n");
            break;
            case 2: pop(fp2,fp4);
            fprintf(fp5,"Pop\n");
            break;
            case 3: flag=0;
            break;
            default: break;
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
}
