#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
vector<int> ifuse;
set<vector<int>> fin;
vector<int> tmp;
void dfs(int dep, int sum, int target) {
    if (sum == target) {
        for (int i = 0; i < ifuse.size(); i++) {
            if (ifuse[i] == 1) {
                tmp.push_back(nums[i]);
            }
        }
        fin.insert(tmp);
        tmp.resize(0);
        return;
    }
    if (dep == nums.size())
        return;
    ifuse[dep] = 1;
    dfs(dep + 1, sum + nums[dep], target);
    ifuse[dep] = 0;
    dfs(dep + 1, sum, target);
}

int main()
{
    int target, num, sum = 0;
    cin >> target >> num;
    nums.resize(num);
    ifuse.resize(num, 0);
    for (int i = 0; i < num; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    sort(nums.begin(), nums.end());
    dfs(0, 0, sum - target);
    for (auto& m : fin) {
        for (auto& n : m) {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}