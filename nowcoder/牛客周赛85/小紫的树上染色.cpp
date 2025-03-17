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
#include <climits>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        b >>= 1;
    }
    return ans;
}

/*
 * 最大红色联通块的大小尽可能小，二分
 * 判断能否使得红色联通块最大为mid，即红色联通块的大小最大为mid
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 检查最大联通块的大小最大为mid是否可行
    auto check = [&](int mid) {
        auto dfs = [&](auto&& self, int u, int o) -> pii {
            int cnt = 0; int rst = 1;
            for (auto& v : g[u]) {
                if (v == o) continue;
                auto [cnt1, rst1] = self(self, v, u);
                cnt += cnt1;
                rst += rst1;
            }
            if (rst > mid) {
                cnt++;
                rst = 0;
            }
            return pii(cnt, rst);
        };
        auto [cnt, rst] = dfs(dfs, 0, -1);
        return cnt <= k;
    };


    int pos = n;
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << pos << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









