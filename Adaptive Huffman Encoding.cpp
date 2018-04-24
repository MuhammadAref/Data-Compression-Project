#include <bits/stdc++.h>

using namespace std;

string nyt,ch[300];
int c;

class Node
{
    public:
        int cnt,no;
        char name;
        Node *r,*l,*p;
};

class Tree
{
    private:
        Node* head;
    public:
        Tree()
        {
            head=new Node;
            head->name='0';
            head->no=-1;
            head->cnt=0;
            head->p=head->r=head->l=NULL;
        }
        ~Tree(){ del(head); }
        void del(Node *curr)
        {
            Node *currR,*currL;
            if(curr->r==NULL)
            {
                delete curr;
                return;
            }
            currR=curr->r;
            currL=curr->l;
            delete curr;
            del(currR);
            del(currL);
        }
        void Insert(char n)
        {
            Node* curr = head;
            if((int)ch[n].size())
            {
                cout<<ch[n];
                for(int i=0;i<(int)ch[n].size();++i)
                {
                    if(ch[n][i]-'0') curr=curr->r;
                    else curr=curr->l;
                }
                ++(curr->cnt);
            }
            else
            {
                cout<<nyt;
                for(int i=0;i<(int)nyt.size();++i)
                {
                    if(nyt[i]-'0') curr=curr->r;
                    else curr=curr->l;
                }
                Node* newNode = new Node;
                Node* newNyt = new Node;
                newNode->p=newNyt->p=curr;
                newNode->name = n;
                newNode->cnt=1;
                newNode->no=newNyt->no=(curr->no)+1;
                newNyt->name = '0';
                newNyt->cnt=0;
                newNode->r =newNode->l =newNyt->r =newNyt->l= NULL;
                curr->r=newNode;
                curr->l=newNyt;
                curr->name='1';
                curr->cnt=1;
                ch[n]=nyt;
                ch[n].push_back('1');
                nyt.push_back('0');
            }
            while(curr!=head)
            {
                curr=curr->p;
                ++(curr->cnt);
            }
            check(head);
        }
        void check(Node *curr)
        {
            if(curr->r==NULL) return;
            if(curr->l->cnt > curr->r->cnt)
            {
                swap(curr->r , curr->l);
                c=curr->r->no;
                update(curr->r);
                update(curr->l);
            }
            check(curr->r);
            check(curr->l);
        }
        void update(Node *curr)
        {
            if(curr->r==NULL)
            {
                if(curr->name=='0'&&curr->cnt==0)
                {
                    if(nyt[c]-'0')
                        nyt[c]='0';
                    else
                        nyt[c]='1';
                }
                else
                {
                    if(ch[curr->name][c]-'0')
                        ch[curr->name][c]='0';
                    else
                        ch[curr->name][c]='1';
                }
            }
            else
            {
                update(curr->r);
                update(curr->l);
            }
        }
};

int main()
{
    Tree tr;
    int m,e,r,k,d;
    string str;
    cout<<"Enter the set: ";
    bool f;
    getline(cin,str);
    for(int i=0;i<(int)str.size();++i)
    {
        if(str[i]!=' ')
        {
            vector<char> v;
            if(ch[str[i]].empty()) f=1;
            else f=0;
            tr.Insert(str[i]);
            if(f)
            {
                if(str[i]>='0'&&str[i]<='9')
                {
                    e=3;
                    r=2;
                    k=str[i]-'0'+1;
                }
                else
                {
                    e=4;
                    r=10;
                    k=tolower(str[i])-'a'+1;
                }
                if(k<=2*r)
                {
                    --k;
                    if(k) d=1+log2(k);
                    else d=1;
                    for(int j=0;j<d;++j)
                    {
                        if(k&(1<<j)) v.push_back('1');
                        else v.push_back('0');
                    }
                    for(int j=0;j<e+1-d;++j)
                        v.push_back('0');
                }
                else
                {
                    k=k-r-1;
                    if(k) d=1+log2(k);
                    else d=1;
                    for(int j=0;j<d;++j)
                    {
                        if(k&(1<<j)) v.push_back('1');
                        else v.push_back('0');
                    }
                    for(int j=0;j<e-d;++j)
                        v.push_back('0');
                }
                for(int j=(int)v.size()-1;j>-1;--j)
                    cout<<v[j];
            }
        }
    }
    return 0;
}
