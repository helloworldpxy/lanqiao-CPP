#include <iostream>
#include <math.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
int main()
{
    int n, k = 0, num,j=0;
    cin >> n; 
    int flag[100005] = { 0 },flag1[100005],sum,maxx=0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);

    }
    sort(a.begin(), a.end());
    while (j < a.size()) {
        flag[k] = 1;
        flag1[k] = a[j];
        while (j<a.size()-1&&a[j] == a[j+1]) {
            flag[k]++;
            j++;
         }
        k++;
        j++;
    }
   /* for (int i = 0; i < k; i++) {
        cout << flag1[i];
    }*/
    for (int i = 0; i < k; i++) {
        sum= flag[i];
        if (((i-1)!=-1)&&flag1[i] - flag1[i - 1] == 1) {
            sum += flag[i - 1];

        }
        if (((i+1)!=k)&&flag1[i+1] - flag1[i] == 1) {
            sum += flag[i + 1];

        }
        if (sum > maxx) {
            maxx = sum;
        }
    }
    cout << maxx;
   

}
