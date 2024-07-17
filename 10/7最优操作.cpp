//尽管这道题放在c++无忧班的图论一章的题目集中,但貌似跟图论没什么关系
//事实上本题只是一道考察思维的题 
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N=1e5+10;

struct Opt//操作指令类 
{
    int x;//当前指令最多改变x个数的值 
    int y;//可以把当前数字改成y 
};

bool cmp(Opt op1,Opt op2)//将操作指令排序(按目标值y从大到小排序) 
{
    return op1.y>op2.y;    
}

Opt opt[N];//存储指令序列 
int arr[N];//存储原始数组 

int main()
{
    int n,m;
    ull sum=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)//输入原始数组 
    {
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=m;i++)//输入m条指令 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        opt[i].x=x;
        opt[i].y=y;
    }
    
    sort(opt+1,opt+1+m,cmp);//将指令序列按y从大到小排列 
    sort(arr+1,arr+n+1);//将原数组从小到大排列
    //由于一个数字可以多次修改,故直接将其修改为指令序列中给出的最大值即可
    //为了使新数组中的数字尽可能的大,应该优先将原数组最小值修改为最大值 
    int idx=1;//下标指针 
    for(int i=1;i<=m;i++)//遍历m条指令 
    {
        int cnt=opt[i].x;//取出当前指令最多改变数字的次数 
        int value=opt[i].y;//取出新的值value
        //下标指针未超范围,次数未递减至0,当前值小于value,循环操作 
        while(idx<=n&&cnt&&arr[idx]<value)
        {
            arr[idx]=value;//修改值 
            idx++;//下标指针后移 
            cnt--;//可修改次数减1 
        }
    }
    
    for(int i=1;i<=n;i++)//累加新数组中的全部元素求值即可 
    {
        sum+=arr[i];
    }
    printf("%llu\n",sum);
    return 0;
}
