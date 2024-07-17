void solve() {
    int n = read();
    string a, b;
    cin >> a >> b;
    a += a;
    a = " " + a, b = " " + b;
    int m = n;
    n <<= 1;
    for(int i = 1; i <= n; i++) {
        if(islower(a[i])) a[i] = toupper(a[i]);
        else a[i] = tolower(a[i]);
    }
//     cout << a << endl;
    vector<int> ne(m + 1);
    for(int i = 2, j = 0; i <= m; i++) {
        while(j && b[j + 1] != b[i]) j = ne[j];
        j += b[j + 1] == b[i];
        ne[i] = j;
    }
    int ans = inf;
    for(int i = 1, j = 0; i <= n; i++) {
        while(j && b[j + 1] != a[i]) j = ne[j];
        j += b[j + 1] == a[i];
        if(j == m) {
            ans = min({ans, i - m, 2 * m - i});
        }
    }
    if(ans == inf) puts("No");
    else {
        puts("Yes");
        cout << ans << endl;
    }
}
