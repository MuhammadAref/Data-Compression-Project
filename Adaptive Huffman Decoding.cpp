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
                for(int i=0;i<(int)ch[n].size();++i)
                {
                    if(ch[n][i]-'0') curr=curr->r;
                    else curr=curr->l;
                }
                ++(curr->cnt);
            }
            else
            {
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
    int b,c,r,e;
    string s,ss,sss;
    cout<<"Enter 1 for char or 2 for numbers: ";
    cin>>c;
    if(c)
    {
        if(c==1)
        {
            e=4;
            r=10;
        }
        else
        {
            e=3;
            r=2;
        }
        cout<<"Enter the set: ";
        cin>>s;
        for(int i=-1;i<(int)s.size();++i)
        {
            if(nyt.empty())
            {
                b=0;
                sss="";
                while(sss.size()<e)
                    sss.push_back(s[++i]);
                for(int j=0;j<(int)sss.size();++j)
                    b+=(sss[j]-'0')*pow(2,(int)sss.size()-1-j);
                if(b<r)
                {
                    sss.push_back(s[++i]);
                    b=0;
                    for(int j=0;j<(int)sss.size();++j)
                        b+=(sss[j]-'0')*pow(2,(int)sss.size()-1-j);
                    if(c==1)
                    {
                        tr.Insert((char)(b+'a'));
                        cout<<(char)(b+'a');
                    }
                    else
                    {
                        tr.Insert((char)(b+'0'));
                        cout<<b;
                    }
                }
                else
                {
                    if(c==1)
                    {
                        tr.Insert((char)(b+r+'a'));
                        cout<<(char)(b+r+'a');
                    }
                    else
                    {
                        tr.Insert(b+r+'0');
                        cout<<b+r;
                    }
                }
            }
            else
            {
                ss.push_back(s[i]);
                if(nyt==ss)
                {
                    ss="";
                    b=0;
                    sss="";
                    while(sss.size()<e)
                        sss.push_back(s[++i]);
                    for(int j=0;j<(int)sss.size();++j)
                        b+=(sss[j]-'0')*pow(2,(int)sss.size()-1-j);
                    if(b<r)
                    {
                        sss.push_back(s[++i]);
                        b=0;
                        for(int j=0;j<(int)sss.size();++j)
                            b+=(sss[j]-'0')*pow(2,(int)sss.size()-1-j);
                        if(c==1)
                        {
                            tr.Insert((char)(b+'a'));
                            cout<<(char)(b+'a');
                        }
                        else
                        {
                            tr.Insert((char)(b+'0'));
                            cout<<b;
                        }
                    }
                    else
                    {
                        if(c==1)
                        {
                            tr.Insert(b+r+'a');
                            cout<<(char)(b+r+'a');
                        }
                        else
                        {
                            tr.Insert(b+r+'0');
                            cout<<b+r;
                        }
                    }
                }
                else
                {
                    for(int j=0;j<300;++j)
                    {
                        if(ch[j]==ss)
                        {
                            tr.Insert((char)j);
                            cout<<(char)j;
                            ss="";
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
