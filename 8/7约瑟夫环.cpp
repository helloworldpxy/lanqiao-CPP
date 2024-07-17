// 引入输入输出流头文件
#include <iostream>
// 引入循环链表头文件
#include <list>
using namespace std;

int main()
{
    // 定义三个整数变量，分别存储n, k, m的值
    int n, k, m;
    // 从标准输入读取n, k, m的值
    cin >> n >> k >> m;
    // 定义一个循环链表，存储n个人的编号
    list<int> circle;
    // 用一个循环，将1到n的整数依次插入链表尾部
    for (int i = 1; i <= n; i++)
    {
        circle.push_back(i);
    }
    // 定义一个迭代器，指向链表中的第k个元素
    list<int>::iterator it = circle.begin();
    for (int i = 1; i < k; i++)
    {
        it++;
        // 如果迭代器到达链表尾部，就让它回到链表头部
        if (it == circle.end())
        {
            it = circle.begin();
        }
    }
    // 用一个循环，重复n次，每次删除一个元素
    for (int i = 0; i < n; i++)
    {
        // 用一个循环，让迭代器向前移动m-1次
        for (int j = 0; j < m - 1; j++)
        {
            it++;
            // 如果迭代器到达链表尾部，就让它回到链表头部
            if (it == circle.end())
            {
                it = circle.begin();
            }
        }
        // 输出迭代器所指向的元素，即要删除的元素
        cout << *it << endl;
        // 删除迭代器所指向的元素，并让迭代器指向下一个元素
        it = circle.erase(it);
        // 如果迭代器到达链表尾部，就让它回到链表头部
        if (it == circle.end())
        {
            it = circle.begin();
        }
    }
    return 0;
}
