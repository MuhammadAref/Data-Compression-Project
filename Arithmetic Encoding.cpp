#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool c;
    int cnt,p=0;
    double val=0;
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
            cin>>f[i];
    }
    else
    {
        cout<<"Enter the probabilities: ";
        for(int i=1;i<=(int)st.size();++i)
        {
            cin>>f[i];
            f[i]+=f[i-1];
        }
    }
    cout<<"Enter the sequence: ";
    cin>>s;
    for(int i=0;i<(int)s.size();++i)
    {
        if(s[i]>='a'&&s[i]<='z')
            s[i]-='a'+1;
        else if(s[i]>='A'&&s[i]<='Z')
            s[i]-='A'+1;
    }
    for(int i=1;i<=(int)s.size();++i)
    {
        m[i].first=m[i-1].first+(m[i-1].second-m[i-1].first)*f[s[i-1]-'0'-1];
        m[i].second=m[i-1].first+(m[i-1].second-m[i-1].first)*f[s[i-1]-'0'];
        cnt=0;
        while(cnt<10)
        {
            ++cnt;
            if(m[i].first>=0&&m[i].second<0.5)
            {
                --p;
                m[i].first=2*(m[i].first);
                m[i].second=2*(m[i].second);
            }
            else if(m[i].first>=0.5&&m[i].second<=1)
            {
                --p;
                val+=pow(2,p);
                m[i].first=2*(m[i].first-0.5);
                m[i].second=2*(m[i].second-0.5);
            }
            else break;
        }
    }
    cout<<"The real value Tag is: "<<fixed<<setprecision(6)<<val;
    return 0;
}
