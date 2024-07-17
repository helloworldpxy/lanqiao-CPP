# include <iostream>
# include <algorithm>
# include <cstring>
using namespace std;

const int N = 30;
int res = 0;
int n;
string words[N];
int used[N]; //记录单词使用次数
int g[N][N]; //记录单词结合中间的单词数，越少越好

void dfs(string dragon, int x)
{
    res = max(res, (int)dragon.size());
    used[x]++; //该单词使用次数加一
    for (int i = 0; i < n; i++)
    {
        if (used[i] < 2 && g[x][i]) //保证使用次数不超过两次，并且两个单词有连接，也就是g[x][i]不能为0
        {
            dfs(dragon + words[i].substr(g[x][i]),i); //两个单词相加连起来
        }
    }
    used[x]--;//恢复现场
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    char start; //首单词
    cin >> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string a = words[i], b = words[j]; //第i个单词和第j个单词
            for (int k = 1; k < min(a.size(), b.size()); k++) // 开始应该从第二个单词开始，因为两个单词不能包含
            {
                if (a.substr(a.size() - k, k) == b.substr(0, k))// a从后面 连 b从前面接
                {
                    g[i][j] = k; // 相同字母个数
                    break; // 取相同字母个数最小的，及时break
                }
            }
        }
    }
    for (int i = 0; i < n; i++) //枚举第i个单词首字母是start
    {
        if (words[i][0] == start)
        {
            dfs(words[i], i);
        }
    }
    cout << res << endl;
    return 0;
}
