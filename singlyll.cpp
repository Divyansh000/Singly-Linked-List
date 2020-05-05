#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *newnode=0,*head=0,*tail=0,*temp=0;
int n=0;
void enter()
{
    int a=0;
    while(1)
    {
        cout<<"\nenter 1 to insert a node and 0 to display \n";
        cin>>a;
        if(a!=1)
        {
            break;
        }
        else
        {
            newnode=new node();
            cout<<"\nenter the data :- ";
            cin>>newnode->data;
            newnode->next=0;
            if(head==0)
            {
                head=tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
        }
    }
}
void display()
{
    cout<<endl;
    if(head==0)
    {
        cout<<"no node are present ";
        return;
    }
    else
    {

        temp=head;
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            n++;
            temp=temp->next;
        }
    }
}
void rev()
{
    node *curr=0,*nextnode=0,*prev=0;
    curr=nextnode=head;
    while(curr!=0)
    {
        nextnode=nextnode->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;

    }
    tail=head;
    head=prev;
}
void insertatbeg()
{
    newnode=new node();
    cout<<"\nenter the data :- ";
    cin>>newnode->data;
    newnode->next=0;
    if(head==0)
    {
       head=tail=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insertatend()
{
    newnode=new node();
    cout<<"\nenter the data :- ";
    cin>>newnode->data;
    newnode->next=0;
    if(head==0)
    {
       head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;

    }
}
void insertatpos()
{
    if(head==0)
    {
        cout<<"no node are present\n";
        return;
    }
    else
    {
        int k=1,pos=0;
        cout<<"\nenter the pos at which you want to insert a node \n";
        cin>>pos;
        if(pos>n)
        {
            cout<<"\ninvalid pos";
            return;
        }
        else
        {
            newnode=new node();
            cout<<"\nenter the data :- ";
            cin>>newnode->data;
            newnode->next=0;
            temp=head;
            if(pos==1)
            {
                newnode->next=head;
                head=newnode;

            }
            else
            {

                while(k<pos-1)
                {
                    temp=temp->next;
                    k++;

                }
                newnode->next=temp->next;
                temp->next=newnode;

            }




        }
    }
}
void deleteatbeg()
{
    if(head==0)
    {
        cout<<"no nodes are present";
        return;
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void deleteatend()
{
    if(head==0)
    {
        cout<<"no nodes are present";
        return;
    }
    else
    {
        temp=head;
        node *prev=temp;

        while(temp->next!=0)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==head)
        {
            deleteatbeg();
            return;
        }
        else
        {
            prev->next=0;
            free(temp);

        }

    }
}
void deleteatpos()
{
    if(head==0)
    {
        cout<<"no node are present\n";
        return;
    }
    else
    {
        int k=1,pos=0;
        cout<<"\nenter the pos at which you want to delete a node \n";
        cin>>pos;
        if(pos>n)
        {
            cout<<"\ninvalid pos";
            return;
        }
        else
        {
            temp=head;
            node *prev=head;
            if(pos==1)
            {
                deleteatbeg();
                return;

            }
            else if(pos==n)
            {
                deleteatend();
                return;
            }
            else
            {

                while(k<pos)
                {
                    prev=temp;
                    temp=temp->next;
                    k++;

                }
                prev->next=temp->next;
                //temp->next=newnode;
                free(temp);
            }




        }
    }
}
int main()
{
    enter();
    display();
    /*rev();
    display();
    insertatbeg();
    display();
    insertatend();
    display();
    insertatpos();
    display();
    deleteatbeg();
    display();
    deleteatend();
    display();*/
    deleteatpos();
    display();
    return 0;
}
