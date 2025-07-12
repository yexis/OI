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
 * 
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> g[n * k];
    for (int i = 0; i < n * k - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    using pbi = pair<bool, int>;
    function<pbi(int, int)> dfs = [&](int u, int o) -> pbi {
        bool ok = true;
        int rst = 1;
        vector<int> vv;
        for (auto& v : g[u]) {
            if (v == o) continue;
            auto [ok1, rst1] = dfs(v, u);
            if (!ok1) {
                return pbi(false, -1);
            }
            
            if (rst1 > 0) {
                vv.push_back(rst1);
            }
        }

        int m = vv.size();
        if (m > 2) {
            return pbi(false, -1);
        }
        if (m == 0) {
            return pbi(true, 1 % k);
        }
        if (m == 1) {
            rst = (1 + vv[0]) % k;
            return pbi(true, rst);
        }
        if (vv[0] + vv[1] + 1 == k) {
            return pbi(true, 0);
        } else {
            return pbi(false, -1);
        }
        return pbi(ok, rst % k);
    };

    auto [ok, rst] = dfs(0, -1);
    if (!ok || rst > 0) {
        cout << "No" << "\n";
        return;
    }
    cout << "Yes" << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









