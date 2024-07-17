#include <stdio.h>
#include <stdlib.h>
int f(int a, int b)
{
    int i;
    for(i=a;;i = i+a)
    {
        if(i%b==0) return i;
    }
}
int main(int argc, char* argv[])
{
    printf("%d\n", f(12,15));
    return 0;
}
