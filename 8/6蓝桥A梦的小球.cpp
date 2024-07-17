#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
const int N=200005;
vector<int> e[N];
int n,q;
int u[N],d[N],cnt[N];

int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;++i)
    {
        u[i]=d[i]=i; // 初始化每个竹筒的上边界和下边界为自己的编号
        cnt[i]=1; // 初始化每个竹筒中小球的数量为1
    }

    // 开始进行q次操作
    for (int x,y;q--;d[x]=u[x]=0) // 将d[x]和u[x]都置为0表示x这个竹筒为空
    {
        scanf("%d%d",&x,&y);
        if (cnt[x]==0) continue; // 如果竹筒x内部没有小球，则不进行操作，直接继续下一次操作
        cnt[y]+=cnt[x]; // 将竹筒x的小球全部倒入竹筒y，因此y的小球数量要加上x的小球数量
        cnt[x]=0; // 将竹筒x的小球数量置为0，表示x内部没有小球了

        // 判断y的上边界是否已经确定，如果没有确定，就把x的上边界赋值给y，并将x的上边界更新为x的下边界
        if (u[y]==0)
        {
            u[y]=d[x];
            d[y]=u[x];
            continue;
        }

        // 如果y的上边界已经确定，则将x的上边界和y的上边界相邻的两个竹筒加入到e[x]和e[y]中，表示它们在同一个环中
        e[u[x]].push_back(u[y]);
        e[u[y]].push_back(u[x]);
        u[y]=d[x]; // 将x的上边界更新为x的下边界
    }

    // 输出最终所有竹筒内部的小球情况
    for (int i=1;i<=n;++i,printf("\n"))
    {
        printf("%d",cnt[i]); // 输出竹筒i中小球的数量
        if (cnt[i]==0) continue;
        printf(" ");
        for (int j=d[i],fa=0,flg=1;flg;) // 输出竹筒i内部的小球编号
        {
            printf("%d ",j);
            flg=0;
            for (auto v:e[j])
                if (v!=fa)
                {
                    flg=1;
                    fa=j;
                    j=v;
                    break;
                }
        }
    }
    return 0;
}
