#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s, s1, s2;
    int b, count;
    cin >> s;
    cin >> b;
    while (b--)
    {
        int x = s.length();
        count = 1;
        s2 = "";
        for (int i = 0; i < x; i++)
        {
            s1 = "";
            if (s[i + 1] == s[i])
            {
                count++;
            }
            else
            {
                s1 += to_string(count) + s[i];
                count = 1;
                s2 += s1;
            }
        }
        s = s2;
    }
    cout << s;
    return 0;
}
