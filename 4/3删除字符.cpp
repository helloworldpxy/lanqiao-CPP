//删除字符
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//思路：
//从左边开始向右遍历，遇到逆序的就删除，
//再对新的串从头遍历找逆序，不停地重复整个过程是为了保证删除的尽可能靠前（贪心），
//如果整个字符串都顺序了，但是还要删，那么就从后面开始删，保留前面小的
int main(int argc, char *argv[])
{
    char arr[100];
    int t;
    int i = 0;
    int j = 0;
    scanf("%s", arr);//也可以用gets(a)来接收字符串
    scanf("%d", &t);
    int len = strlen(arr);//获取字符串长度
    while (t--) {
        int flag = 0;
        for (int i = 0;i < len - 1;i++)
            if (arr[i] > arr[i + 1]) {
                arr[i]=0;//直接置空，后面遇到0不打印即可
                flag = 1;
                break;
            }
        if (!flag) break;
    }
    for (i = 0;i < len-t-1;i++)
    {
        if (arr[i] != 0)
        {
            printf("%c", arr[i]);
        }
    }
    return 0;
}
