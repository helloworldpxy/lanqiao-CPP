#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n=0,i,A=0,B=0,P=0,Q=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&A,&B,&P,&Q);
        if(A==P&&B==Q)
        printf("0\n");
        else if((A+B+P+Q)%2==0)
        printf("2\n");
        else if ((A+B+P+Q)%2==1)
        printf("1\n");
    }
  return 0;
}
