#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node head=NULL,temp,cur;

node insert(FILE *fp,int n)                                    //UDF TO INSERT A NUMBER IN THE FILE
{
    int d;
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&d);                                              //READING THE VALUE FROM THE FILE
        node newn=(node)malloc(sizeof(struct NODE));                     // ALLOCATING MEMORY FOR THE NEWNODE FOR THE DATA TO BE INSERTED
        newn->data=d;
        newn->next=NULL;
        if(head==NULL)
        {
            head=newn;
        }
        else
        {
            temp=head;
            head=newn;
            head->next=temp;
        }
    }
}

void sort()                                     // UDF TO SORT THE NUMBER IN THE LINKED LIST
{
    cur=head;
    while(cur->next!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data > temp->next->data)
            {
                int x=temp->data;
                temp->data=temp->next->data;
                temp->next->data=x;
            }
            temp=temp->next;
        }
        cur=cur->next;
    }
}

void rad(FILE *fp,int n)                                 // UDF TO WRITE THE RANDOM VARIABLES
{
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d\t",rand()%100);                  //rand() IS AN INBUILT FUNCTION TO GENERATE THE RANDOM VARIABLE
    }
}

void display(node head)                              // UDF TO DISPLAY THE CONTENT OF THE STRUCTURE
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

main()
{
    int n;
    FILE *fp;
    double start,stop;
    printf("Enter the range: ");
    scanf("%d",&n);
    fp=fopen("sort.txt","w");                   // OPENING THE FILE "sort.txt" TO WRITE THE DATA INTO IT
    rad(fp,n);
    fclose(fp);
    fopen("sort.txt","r");                    // OPENING THE FILE "sort.txt" TO READ THE DATA FROM IT
    insert(fp,n);
    start=clock();                            //STORING THE START TIME OF THE CLOCK IN THE VARIABLE "start"
    sort();
    stop=clock();                            //STORING THE STOP TIME OF THE CLOCK IN THE VARIABLE "stop"
    display(head);
    fclose(fp);
    printf("\nTime taken: %lf",(stop-start)/CLOCKS_PER_SEC);
}
