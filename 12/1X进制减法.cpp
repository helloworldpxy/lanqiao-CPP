#include<iostream>
#include<math.h>
using namespace std;
const int M = 1E9 + 7;
typedef long long ll;
int n;
ll a[500005];//存储每个位置上的数 
ll b[500005];//存储每个位置上的数 
ll c[500005];//确定各个位置的进制 
ll pre[500005];
ll result = 0;
int main()
{
    cin >> n;
    int m1, m2;
    cin >> m1;
    for (int i = 1; i <= m1; i++)cin >> a[i];
    cin >> m2;
    for (int i = 1; i <= m2; i++)cin >> b[i];
    //要使得A尽可能大，B尽可能小
    for (int i = 1; i <= min(m1, m2); i++)
    {
        ll x = max(a[i], b[i]) + 1;
        if (x < 2)
        {
            x = 2;
            c[i] = x;
        }
        else
        {
            c[i] = x;
        }
    }
    if (m1 >= m2)
    {
        for (int i = m2 + 1; i <= m1; i++)
        {
            ll x = a[i] + 1;
            if (x < 2)
            {
                x = 2;
                c[i] = x;
            }
            else
            {
                c[i] = x;
            }
        }
        ll A = 0, B = 0;
        //求各个位置的乘积数
        pre[m1] = 1;
        for (int i = m1 - 1; i >= 1; i--)
        {
            pre[i] = ((c[i + 1] % M) * (pre[i + 1] % M)) % M;
        }
        for (int i = 1; i <= m1; i++)
        {
            a[i] = a[i] - b[i];
        }
        for (int i = 1; i <= m1; i++)
        {
            result = (result%M+(a[i] * pre[i]) % M)%M;
        }
    }
    cout << (result + M) % M;
    return 0;
}
