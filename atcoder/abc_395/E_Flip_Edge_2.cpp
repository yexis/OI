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
 * dijkstra
 * 加点法，将反图中的点u抽象成新的点u+n，将反图中的点v抽象成新的新v+n
 * 如果 u->v = 1， 那么 (v+n)->(u+n) = 1
 * 另外对于任意点u，u->(u+n) = x, (u+n)->u = x
*/

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    
    vector<pii> g[n << 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v, 1});
        g[v + n].push_back({u + n, 1});
    }
    for (int u = 0; u < n; u++) {
        g[u].push_back({u + n, x});
        g[u + n].push_back({u, x});
    }

    vector<ll> dist(2 * n, LLINF);
    priority_queue<pll, vector<pll>, greater<> > pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) {
            continue;
        }
        for (auto& [v, w] : g[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    cout << min(dist[n - 1], dist[n + n - 1]) << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









