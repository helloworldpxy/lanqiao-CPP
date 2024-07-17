#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    vector<bool>visited(n, false);
    for (int i = 0; i < n; ++ i)
    {
        string s; cin >> s;
        if (s[1] >= '1' && s[1] <= '9')
        {
            a[i] = s[1] - '0';
            visited[a[i] - 1] = true;
        }
        else
            a[i]=0;
    }
    int start = 1;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            start = i+1;
            break;
        }
    }
    while (a[start-1])
    {
        cout << start << "->";
        start = a[start-1];
    }
    cout << start << endl;
    return 0;
}
