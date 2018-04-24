#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool c,vf=1;
    int cnt,k,kk=0,y=0;
    double val=0,x=2.0;
    vector<char> st;
    string s;
    cout<<"Enter the Set: ";
    getline(cin,s);
    for(int i=0;i<(int)s.size();++i)
        if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'))
            st.push_back(s[i]);
    double f[(int)st.size()+1];
    pair<double,double> m[(int)st.size()+1];
    f[0]=0;
    m[0]={0,1};
    cout<<"Enter 0 for  the probabilities or 1 for the CDF: ";
    cin>>c;
    if(c)
    {
        cout<<"Enter the CDF: ";
        for(int i=1;i<=(int)st.size();++i)
        {
            cin>>f[i];
            x=min(x,f[i]-f[i-1]);
        }
    }
    else
    {
        cout<<"Enter the probabilities: ";
        for(int i=1;i<=(int)st.size();++i)
        {
            cin>>f[i];
            f[i]+=f[i-1];
            x=min(x,f[i]-f[i-1]);
        }
    }
    k=ceil(log2(1/x));
    cout<<"Enter the Tag: ";
    cin>>s;
    for(int i=0;i<k;++i)
        if(s[i]-'0') val+=pow(2,-(i+1));
    while(vf)
    {
        ++y;
        for(int i=0;i<(int)st.size();++i)
        {
            m[y].first=m[y-1].first+(m[y-1].second-m[y-1].first)*f[i];
            m[y].second=m[y-1].first+(m[y-1].second-m[y-1].first)*f[i+1];
            if(val>=m[y].first&&val<=m[y].second)
            {
                cout<<st[i];
                if(val==0.5)
                {
                    vf=0;
                    break;
                }
                cnt=0;
                while(cnt<10)
                {
                    ++cnt;
                    if(m[y].first>=0&&m[y].second<0.5)
                    {
                        val=0;
                        ++kk;
                        for(int j=kk;(j<(k+kk))&&(j<(int)s.size());++j)
                            if(s[j]-'0') val+=pow(2,-(j-kk+1));
                        m[y].first=2*(m[y].first);
                        m[y].second=2*(m[y].second);
                    }
                    else if(m[y].first>0.5&&m[y].second<=1)
                    {
                        val=0;
                        ++kk;
                        for(int j=kk;(j<(k+kk))&&(j<(int)s.size());++j)
                            if(s[j]-'0') val+=pow(2,-(j-kk+1));
                        m[y].first=2*(m[y].first-0.5);
                        m[y].second=2*(m[y].second-0.5);
                    }
                    else break;
                }
                break;
            }
        }
    }
    return 0;
}
