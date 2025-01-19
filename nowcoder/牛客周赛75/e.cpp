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
    int n, C, m;
    cin >> n >> C >> m;

    typedef array<ll, 3> ar3;
    vector<ar3> pr;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    vector<int> dou(n);
    for (int i = 0; i < m; i++) {
        ll x, y, v;
        cin >> x >> y >> v;
        x--, y--;
        dou[x] = true;
        dou[y] = true;
        pr.push_back({2, a[x] + a[y], b[x] + b[y] + v});
        pr.push_back({1, a[x], b[x]});
        pr.push_back({1, a[y], b[y]});
    }
    for (int i = 0; i < n; i++) {
        if (!dou[i]) {
            pr.push_back({1, a[i], b[i]});
        }
    }

    int nn = pr.size();
    ll f[nn][5][C + 1];
    memset(f, -1, sizeof(f));
    auto dfs = [&](auto&& dfs, int idx, int pe, int co) -> ll {
        if (idx >= nn) {
            return 0;
        }
        if (pe == 0 || co == 0) {
            return 0;
        }

        if (f[idx][pe][co] != -1) {
            return f[idx][pe][co];
        }

        ll ans = 0;
        auto [pp, aa, bb] = pr[idx];
        if (pp == 1) {
            ans = dfs(dfs, idx + 1, pe, co);
            if (pe >= 1 && co >= aa) {
                ans = max(ans, bb + dfs(dfs, idx + 1, pe - 1, co - aa));
            }
        } else {
            auto [pp1, aa1, bb1] = pr[idx + 1];
            auto [pp2, aa2, bb2] = pr[idx + 2];
            
            ans = dfs(dfs, idx + 1, pe, co);
            if (pe >= 1 && co >= aa1) {
                ans = max(ans, bb1 + dfs(dfs, idx + 1, pe - 1, co - aa1));
            }
            if (pe >= 1 && co >= aa2) {
                ans = max(ans, bb2 + dfs(dfs, idx + 1, pe - 1, co - aa2));
            }
            if (pe >= 2 && co >= aa1 + aa2) {
                ans = max(ans, bb + dfs(dfs, idx + 3, pe - 2, co - aa1 - aa2));
            }
        }
        return f[idx][pe][co] = ans;
    };
    ll ans = dfs(dfs, 0, 4, C);
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    solve();
    return 0;
}