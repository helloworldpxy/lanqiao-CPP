#include <iostream>
using namespace std;
int main()
{    
      char ch[7] = {'I','V','X','L','C','D','M'};//存罗马字母
      int  it[7] = {1,5,10,50,100,500,1000};//存对应的数字
      int a,m1,m2;
      cin >> a;
      while(a--)
      {
          int num=0;
          string s;
          cin >> s;
          for(int i=0;i<s.size();i++)
          {
              for(int j=0;j<7;j++)
            {
                if(ch[j] == s[i])
                {
                    m1 = it[j];//获取当前罗马字母的值
                }
                if(ch[j] == s[i+1])
                {
                    m2 = it[j];//获取下一个罗马字母的值
                }
            } 
//如果下一个大于当前则在总和上减去当前，否则加上
            if(m1<m2)
            {
                num-=m1;
            }else{
                num+=m1;
            }
        }
        cout << num << endl;
      }
  return 0;
}
