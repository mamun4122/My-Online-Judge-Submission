#include <iostream>
#include<cstdio>
using namespace std;

struct node
{
    int val;
    node *next;
};
class list
{
    node *head;
    int sz=0;
public:
    list()
    {
        head=new node;
        head->next= NULL;
    }
    void insert(int x)
    {
        node *z=new node;
        z->val=x;
        z->next=head->next;
        head->next=z;
        sz++;
    }
    void result()
    {
        node *cur=new node;
        cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        node *z=new node;
        z=head->next;
        cout<<"Discarded cards:";
        if(sz>1)
            cout<<" ";
        while(sz!=1)
        {
            cout<<z->val;
            sz--;
            if(sz!=1)
            {
                cout<<", ";
            }
            z=z->next;
            node *y=new node;
            y->val=z->val;
            y->next=cur->next;
            cur->next=y;
            cur=cur->next;
            z=z->next;
            head->next=z;

        }
        cout<<endl;
        cout<<"Remaining card: "<<cur->val<<endl;
    }
    void del()
    {
        head->next=NULL;
    }
};

int main()
{
    //freopen("file.txt","r",stdin);
    int x;
    cin>>x;
    while(x)
    {
        list a;
        for(int i=x; i>0; i--)
        {
            a.insert(i);
        }
        a.result();
        a.del();
        cin>>x;
    }
    return 0;
}

