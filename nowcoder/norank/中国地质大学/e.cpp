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
    int n, A;
    cin >> n >> A;
    vector<int> D(n);
    for (int i = 0; i < n; i++) cin >> D[i];

    ll f[20][3][3][3][3][20][2];
    memset(f, -1, sizeof(f));
    auto dfs = [&](auto&& dfs, int idx, int a, int b, int c, int d, int ti, int db) -> ll {
        if (idx == n) {
            return 0;
        }
        if (f[n][a][b][c][d][ti][db] != -1) {
            return f[n][a][n][c][d][ti][db];
        }
        ll ans = 0;
        // 1
        if (a == 0) {
            ans = max(ans, (db ? 2 : 1 ) * D[idx] + dfs(dfs, idx + 1, 2, max(b - 1, 0), max(c - 1, 0), max(d - 1, 0), ti, false));
        }
        // 2
        if (b == 0) {
            ans = max(ans, dfs(dfs, idx + 1, max(a - 1, 0), 2, max(c - 1, 0), max(d - 1, 0), ti + 1, false));
        }
        // 3
        if (c == 0) {
            ans = max(ans, (db ? 2 : 1) * (ll)ti * A + dfs(dfs, idx + 1, max(a - 1, 0), max(b - 1, 0), 2, max(d - 1, 0), ti, false));
        }
        // 4
        if (d == 0) {
            ans = max(ans, dfs(dfs, idx + 1, max(a - 1, 0), max(b - 1, 0), max(c - 1, 0), 2, ti, true));
        }
        return f[idx][a][b][c][d][ti][db] = ans;
    };
    cout << dfs(dfs, 0, 0, 0, 0, 0, 0, false) << "\n";
    return;
}

int main() {
    solve();
    return 0;
}