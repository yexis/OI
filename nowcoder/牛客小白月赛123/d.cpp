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
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * 
*/

void solve() {
    int n, m; cin >> n >> m;
    vector<pli> g[n];
    vector<ll> shortest(n, LLINF);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        g[u].push_back(pli(w, v));
        g[v].push_back(pli(w, u));
        shortest[u] = min(shortest[u], (ll)w);
        shortest[v] = min(shortest[v], (ll)w);
    }
    
    auto dijk = [&](int s) -> void {
        vector<ll> dist(n, LLINF);
        priority_queue<pli, vector<pli>, greater<> > pq;
        dist[s] = 0; pq.push(pli(0, 0));
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u] < d) {
                continue;
            }
            for (auto& [w, v] : g[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.emplace(pli(dist[v], v));
                }
                if (d + shortest[u] * 2 < dist[v]) {
                    dist[v] = d + shortest[u] * 2;
                    pq.emplace(pli(dist[v], v));
                }
            }
        }
        if (dist[n - 1] < LLINF) {
            cout << dist[n - 1] << "\n";
            return;
        }
        cout << -1 << "\n";
    };
    dijk(0);
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









