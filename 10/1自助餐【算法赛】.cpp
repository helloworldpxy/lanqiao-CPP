#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
  int sum=0;
  string str;
  cin>>n;
       for(int i=0;i<n;i++)
       {
       cin>>str;
        if(str=="yuanxing")
        sum=sum+1;
        if(str=="zhengfangxing")
        sum=sum+2;
        if(str=="changfangxing")sum=sum+3;
        if(str=="sanjiaoxing")sum=sum+4;
        if(str=="tuoyuanxing")sum=sum+5;
        if(str=="liubianxing")sum=sum+6;
    }
cout<<sum;
}
