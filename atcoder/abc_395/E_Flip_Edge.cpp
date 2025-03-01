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
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> g[n];
    vector<int> g2[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g2[v].push_back(u);
    }

    using arr = array<ll, 3>;
    priority_queue<arr, vector<arr>, greater<> > q;

    ll dist[n][2];
    memset(dist, LLINF, sizeof(dist));
    dist[0][0] = 0;
    q.push({dist[0][0], 0, 0});

    while (q.size()) {
        auto [d, u, r] = q.top();
        q.pop();
        if (dist[u][r] < d) {
            continue;
        }
        if (r == 0) {
            for (auto& v : g[u]) {
                if (d + 1 < dist[v][r]) {
                    dist[v][r] = d + 1;
                    q.push({dist[v][r], v, r});
                }
            }
            for (auto& v : g2[u]) {
                if (d + x + 1 < dist[v][1 - r]) {
                    dist[v][1 - r] = d + x + 1;
                    q.push({dist[v][1 - r], v, 1 - r});
                }
            }
        } else if(r == 1) {
            for (auto& v : g2[u]) {
                if (d + 1 < dist[v][r]) {
                    dist[v][r] = d + 1;
                    q.push({dist[v][r], v, r});
                }
            }
            for (auto& v : g[u]) {
                if (d + x + 1 < dist[v][1 - r]) {
                    dist[v][1 - r] = d + x + 1;
                    q.push({dist[v][1 - r], v, 1 - r});
                }
            }
        }
    }
    
    cout << min(dist[n - 1][0], dist[n - 1][1]) << "\n";

}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









