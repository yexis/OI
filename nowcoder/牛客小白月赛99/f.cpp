#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
#include <limits>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

/*
 * 完全背包问题
*/
void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    if (t < n) {
        cout << 0 << "\n";
        return;
    }
    int diff = t - n;
    if (diff == 0) {cout << n << "\n"; return;}

    set<int> dfs;
    for (int i = 1; i < m; i++) {
        dfs.insert(2 * (a[i] - a[i - 1]));
    }

    // 完全背包
    vector<int> dd(dfs.begin(), dfs.end());
    vector<int> dp(diff + 1);
    dp[0] = true;
    for (auto& d : dd) {
        for (int i = d; i <= diff; i++) {
            if (dp[i - d]) dp[i] = true;
        }
    }

    int ans = n;
    for (int i = diff; i >= 0; i--) {
        if (dp[i]) {
            ans += i;
            break;
        }
    }
    cout << ans << "\n";

}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}