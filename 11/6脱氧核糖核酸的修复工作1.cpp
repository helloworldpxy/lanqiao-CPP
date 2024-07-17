#include <iostream>
#include<string>
#include<algorithm>
using namespace std;


const long int maxsize = 100000;
struct protein_link
{
    char c[maxsize];
    long int length;
};

void assign(protein_link &p,string s)
{
    long int i = 0;
    p.length = s.length();
    for (i = 0; i < s.length(); i++)
        p.c[i] = s[i];
}

void reverse(protein_link p ,protein_link &r_p)
{
    long int i = 0;
    for (i = 0; i < p.length; i++)
    {
        r_p.c[i] = p.c[p.length - i - 1];
    }
    r_p.length = p.length;
}
void replace(protein_link& p, long int i, char x)
{
    p.c[i - 1] = x;
}

void disp_protein_link(protein_link p)
{
    for (long int i = 0; i < p.length; i++)
        cout << p.c[i];
    cout << endl;
}
void mate_num(protein_link p1, protein_link p2,long int &num)
{
    num = 0;
    for (long int i = 0; i < p1.length; i++)
    {
        if (p1.c[i] == 'A' && p2.c[i] == 'T')
            num++;
        if (p1.c[i] == 'T' && p2.c[i] == 'A')
            num++;
        if (p1.c[i] == 'G' && p2.c[i] == 'C')
            num++;
        if (p1.c[i] == 'C' && p2.c[i] == 'G')
            num++;
    }
}
int main()
{
    void assign(protein_link & p, string s);
    void reverse(protein_link p,protein_link &r_p);
    void replace(protein_link & p, long int i, char x);
    void disp_protein_link(protein_link p);
    void mate_num(protein_link p1, protein_link p2,long int &num);
    // 请在此输入您的代码
    string s1, s2;
    cin >> s1 >> s2;
    long int a, b, c, d;
    
    cin >> a >> b >> c >> d;
    protein_link p1, p2,p3;
    assign(p1, s1);
    assign(p2, s2);


    long int res=0;
    long int u, v;
    if (a > b)
        u = b;
    else
        u = a;
    if (c > d)
        v = d;
    else
        v = c;

    long int mate_n=0, new_n = 0;
    mate_num(p1, p2,mate_n);
    reverse(p1, p3);
    mate_num(p2, p3, new_n);
    res += min((p1.length - new_n) * v + u, (p1.length - mate_n) * v);
    cout << res << endl;

    return 0;
}
