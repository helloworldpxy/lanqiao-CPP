#include <bits/stdc++.h>
using namespace std;
string add(string a,string b)
{
    string s;int c=0;
    for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||c>0;i--,j--)
    {
        if(i>=0)    c+=a[i]-'0';
        if(j>=0)    c+=b[j]-'0';
        s+=c%10+'0';
        c/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string mul(string a,string b)
{
    if(a=="0"||b=="0")    return "0";
    string s="0";
    int c=0;
    for(int i=a.size()-1,k=0;i>=0;i--,k++)
    {
        string temp;
        int kk=k;
        for(int j=b.size()-1;j>=0||c>0;j--)
        {
            if(j>=0)    c+=(a[i]-'0')*(b[j]-'0');
            temp+=c%10+'0';
            c/=10;
        }
        reverse(temp.begin(),temp.end());
        while(kk--)    temp+='0';
        s=add(s,temp);
    }
    return s;
}
int main()
{
  unsigned long long ans = (1<<64)-1;
  cout<<ans;
}
