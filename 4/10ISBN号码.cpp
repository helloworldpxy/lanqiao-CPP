#include <iostream>
using namespace std;
int main(){
    string a;
    int sum=0,k=1,i;
    cin>>a;
    for(i=0;i<11;i++){//前9个数加上两个分隔符
        if(a[i]!='-')sum+=(a[i]-'0')*k++;
    }int x=sum%11;//取模
    if(x==10){
        if(a[12]=='X') cout<<"Right";//如果验证码对了就输出Right
        else {
            a[12]='X';//把验证码改对
            cout<<a;
        }
    }else {
        if(a[12]-'0'==x) cout<<"Right";//验证码对了就输出Right
        else{
            a[12]=x+'0';//把验证码改对
            cout<<a;
        }
    }
}
