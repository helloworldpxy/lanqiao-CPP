#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int N,i,j,t,flag=0,k,g,h;
  int m,n;
  int c[7]={1,2,4,8,16,32,64};
  scanf("%d",&N);
  int a[N][N],b[N][N];
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      scanf("%d",&a[i][j]);
      b[i][j]=a[i][j];
    }
  }
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      t=a[i][j];
      if(t%2==0 || t==1)
        for(k=0;k<7;k++)
        {
          if(t==c[k])
          {
            m=i;
            n=j;
            for(g=0;g<N;g++)
            {
              for(h=0;h<N;h++)
              {
                if(g==m||h==n)
                b[g][h]=1;
              }
            }
          }
        }
    }
  }

  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
      printf("%d ",b[i][j]);
    putchar('\n');
  }

  return 0;
}
