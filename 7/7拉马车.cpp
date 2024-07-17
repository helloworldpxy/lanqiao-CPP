#include <bits/stdc++.h>
using namespace std; 
bool a[128]; // a[i]表示牌堆中是否存在i这张牌 
int main() { 
  string A,B; 
  cin>>A>>B; 
  stack<char> S; // 用栈作为牌堆
  S.push(A[0]); a[A[0]-0]=1; A.erase(0,1); // A先出牌
  bool flag=1; // flag控制到谁出牌 
  int times=0; // times表示出牌次数，超过10000认为会无限循环 
  while(A.length() && B.length() && times<10000){ 
    //cout<<A<<","<<B<<endl; 
    string* sp=flag?&B:&A; // flag为1时B出牌，将string指针指向B，方便实现B的出牌和收牌 
    char tmp=(*sp)[0];
    S.push(tmp); sp->erase(0,1); // 玩家出牌 
    if(a[tmp-0]==0) { a[tmp-0]=1; flag = !flag; } // 牌堆中没有当前出的牌，牌权更换 
    else{ // 若包含当前字符，收回一部分牌 
      *sp += S.top(); S.pop(); // 收回刚出的那张牌，位于栈顶 
      while(S.top()!=tmp){ *sp += S.top(); a[S.top()-0] = 0; S.pop(); } //一直收牌到与所出牌相同的另一张牌处 
      *sp += S.top(); a[S.top()-0] = 0; S.pop(); 
    } 
    times++; 
  } 
  if(times>=10000) return -1; 
  if(A.length()) cout<<A; else cout<<B; 
  return 0; 
}
