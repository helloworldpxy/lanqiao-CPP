#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int>rows;//存储所有合法的行,每个元素的二进制代表该行的组成 
map<pair<int,int> ,ll>memory;//记忆化数组
int n,m;

bool is_valid(int row)//判断一个行是否合法 
{
    //若合法，即没有相邻的1,则其二进制与其左移一位,右移一位再相与,均为0 
    if((row&(row<<1))==0&&(row&(row>>1))==0)return true;
    else return false;    
}

ll dfs(int row,int last_row)//row为当前处理到第几行,last_row为其上一行(以二进制的形式处理) 
{
    if(row==n)return 1;//已经处理到第n行,返回一个计数值1,代表一个合法的矩阵 
    ll cnt=0;
    for(int i=0;i<rows.size();i++)//枚举所有合法行,尝试将其放入当前行之后 
    {
        int r=rows[i];
        if((r&last_row)==0)//判断是否可以放入:当前行与上一行同列不能出现两个1 
        {
            //若可以放入,则记录之 
            if(memory.find(make_pair(row+1,r))==memory.end())//之前未记忆化,则记忆化    
            {
                memory[{row+1,r}]=dfs(row+1,r);
                //以放入的行作为上一行,继续验证下一行并保存合法情况数 
            }
            cnt+=memory[{row+1,r}];//记忆化完毕,累加这个状态的合法情况数 
        }    
    }    
    return cnt;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<(1<<m);i++)//m列对应长度为m的二进制数,大小为0~2^m-1 
    {
        //枚举所有的二进制组合,判断其是否是一个合法的行,若是则记录 
        if(is_valid(i))rows.push_back(i);
    }
    
    ll ans=0;
    for(int i=0;i<rows.size();i++)//枚举所有合法的行 
    {
        //将每个合法行作为第一行,进行一次dfs,累加返回值,即此种情况下交错矩阵的数量 
        ans=ans+dfs(1,rows[i]);
    }
    cout<<ans<<endl;//输出最终的累加结果即可 
    return 0;
}
