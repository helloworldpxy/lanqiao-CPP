#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
const int N = 200010;

ll m, d;
struct tree{
    int l, r;
    ll max;
}tree[4 * N];
void build(int i, int l, int r) {
    tree[i].l = l;
    tree[i].r = r;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
}
void insert(int i, ll dis, ll k) {
    if(tree[i].l == tree[i].r) {
        tree[i].max += k;
        return;
    }
    if(tree[i << 1].r >= dis) insert(i << 1, dis, k);
    else insert(i << 1 | 1, dis, k);
    tree[i].max = max(tree[i << 1].max, tree[i << 1 | 1].max);
}
ll search(int i, int l, int r) {
    if(tree[i].l >= l && tree[i].r <= r) return tree[i].max;
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(r <= mid) return search(i << 1, l, r);
    else if(l > mid) return search(i << 1 | 1, l, r);
    else return max(search(i << 1, l, r), search(i << 1 | 1, l, r));
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 0, pos = 0;
    cin >> m >> d;
    build(1, 1, 200000);
    while(m--) {
        char op;
        cin >> op;
        if(op == 'Q') {
            int L;
            cin >> L;
            t = search(1, pos - L + 1, pos);
            cout << t << endl;
        }else {
            ll n, k;
            cin >> n;
            k = (n + t) % d;
            pos += 1;
            insert(1, pos, k);
        }
    }
    return 0;
}
