#include<iostream>
#include<cstring>
using namespace std;
int main(){
   string str;
   getline(cin,str);//可以将带有空格的string输入
   for(int i=0;i<str.size();i++){
     if(i==0&&str[i]>='a'&&str[i]<='z') str[i]-=32;//单词首字母小写变大写
       if(str[i]==' '){
           int j=i+1;
           while(str[j]==' '){  //去除多个空格，只保留一个空格
               str.erase(j,1);
       }
           if(str[j]>='a'&&str[j]<='z') str[j]-=32;//小写变大写
     }
       
       if((str[i]-'0')>=0&&(str[i]-'0')<=9&&str[i+1]>='a'&&str[i+1]<='z') 
        str.insert(i+1,"_");//数字在单词前面
       if((str[i]-'0')>=0&&(str[i]-'0')<=9&&((str[i-1]>='a'&&str[i-1]<='z')||(str[i-1]>='A'&&str[i-1]<='Z')))  
        str.insert(i,"_");//数字在单词后面(注意大写单词后面接数字的情况)
   }
   cout<<str<<endl;
    return 0;
}
