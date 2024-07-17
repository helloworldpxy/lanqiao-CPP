#include<bits/stdc++.h>

using namespace std;

int n;
string s;
stack<char> st;

bool judge()
{
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
          st.push(s[i]);
        if(s[i]==')')
        {
            if(st.empty())
              return false;
            st.pop();
        }
    }
    if(st.empty())
      return true;
    else
      return false;
}

int main()
{
    cin>>n;
    cin>>s;
    if(judge())
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
      
    return 0;
}
