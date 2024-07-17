#include <bits/stdc++.h>
int main(int argc, char *argv[])
{
  int t,x,y;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    scanf("%d%d",&x,&y);
    printf("%d\n",x/y+x%y);
  }
  return 0;
}
