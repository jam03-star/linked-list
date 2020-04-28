#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert();
void delete();
void reverse();
struct node
{
    int elem;
    struct node *next;
};
struct node *head=0,*newnode,*temp,*p,*g;
int c=0,i,d,n,ch,m,dtt;
int main()
{
    int con=1;
    while(con==1)
    {
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:create();
    break;
    case 2:
    display();
    break;
    case 3:
    insert();
    break;
    case 4:
    delete();
    break;
    case 5:
    printf("h");
    reverse();
    break;
    }
    printf("\ndo u want to continue(0/1) : ");
    scanf("%d",&con);
    printf("%d",con);
    }
    return 0;
}
void create()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&d);
    newnode->elem=d;
    newnode->next=0;
    if(head==0){
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    ++c;
    }
    printf("nodes created successfully");
    printf("\nlength of nodes : %d",c);
}
void display()
{
    printf("\ndisplaying nodes :\n");
    temp=head;
while(temp!=0)
{
    printf("%d ",temp->elem);
    temp=temp->next;
}
}
void insert()
{
    int pos,dt,co=0,i=1;
    scanf("%d",&pos);
    scanf("%d",&dt);
    pos=pos-1;
    if(pos==0)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->elem=dt;
        newnode->next=head;
        head=newnode;
    }
    
    else if(pos>0 && pos<c)
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            ++i;
        }
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->elem=dt;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else if(pos>=c)
    {
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->elem=dt;
        newnode->next=0;
        temp->next=newnode;
    }
    printf("\nafter insertion of element %d at position %d:",dt,pos+1);
    display();
}
    void delete()
    {
        scanf("%d",&dtt);
        temp=head;
        p=temp;
        if(p->elem==dtt){
            head=p->next;
            free(p);
        }
        else
        {
        while(p->next->elem!=dtt)
        {
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        free(temp);
        }
        printf("\nafter deletion of element %d:",dtt);
        display();
    }
void reverse()
{
    
    printf("\nAfter reversing : \n");
    for(i=1;i<=c;i++)
    {
        temp=head;
        int b=i;
        if(b!=c)
        {
        while(temp->next!=0 && b<c)
        {
            temp=temp->next;
            ++b;
        }
        printf("%d ",temp->elem);
        }
        else
        printf("%d ",temp->elem);
    }
}
