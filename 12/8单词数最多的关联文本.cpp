#include <bits/stdc++.h>

using namespace std;

const int maxn=30;
const int maxx=2e6; 
string word[maxn];
int first[maxn];//first[i]存储第i个字符串的首字母 
int last[maxn];//last[i]存储第i个字符串的末尾字母 
int dp[maxx][maxn];
//dp[i][j]表示从word[0]到word[i]区间内以字符j结尾的关联字符串的最大数量
 
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>word[i];
        first[i]=word[i][0]-'a';//存储该字符串的首字符 
        last[i]=word[i][word[i].size()-1]-'a'; //存储该字符串的末尾字符 
    }

    for(int i=0;i<(1<<N);i++)//枚举N个字符串(视为N位二进制数)的所有状态00..000~11...111 
    {
        //若某位为0，代表不选择该字符串；若为1，代表选择该字符串 
        for(int j=0;j<N;j++)//枚举N位二进制数的每一位j,即是否能选择第j个字符串作为最末的字符串 
        {
            if(i&(1<<j))//取当前二进制数的第j位，若为1，则其可以作为最后选择的字符串 
            {
                //若选择该字符串，则上一个状态的关联字符串以first[j]结尾，
                //由于i的第j位是1,故i^(1<<j)的第j位是0,代表上一个状态一定没选第j个字符串
                //选择j以后关联字符串的数量加1,即为dp[i^(1<<j)][first[j]]+1
                //若其比dp[i][last[j]]更大，则更新dp[i][last[j]]即可 
                dp[i][last[j]]=max(dp[i][last[j]],dp[i^(1<<j)][first[j]]+1); 
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<26;i++)//枚举所有可能的末尾字符i 
    {
        //dp[(1<<N)-1][i]即对于全部的字符串，以字符i结尾的关联字符串的最大数量
        //对于不同的i，不断比较得出其中的最大值即为最终答案 
        ans=max(ans,dp[(1<<N)-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}
