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
#define debugE(x) cerr << (#x) << " = " << (x) << endl;

template<typename... Args> void debug_print(const char* names, Args&&... args) { cout << names << " = "; ((cout << args << " "), ...); cout << endl; }
template<typename... Args> void debug_err_print(const char* names, Args&&... args) { cerr << names << " = "; ((cerr << args << " "), ...); cerr << endl; }
#define debugs(...) debug_print(#__VA_ARGS__, __VA_ARGS__)
#define debugsE(...) debug_err_print(#__VA_ARGS__, __VA_ARGS__)

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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

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
    int n, m, a, b, s, t; cin >> n >> m >> a >> b >> s >> t;
    a--, b--, s--, t--;

    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist1(n, INF), dist2(n, INF);
    auto bfs = [&](vector<int>& dist, int s) -> void {
        queue<int> q; q.push(s); dist[s] = 0;
        while (q.size()) {
            auto u = q.front(); q.pop();
            for (auto& v : g[u]) {
                if (dist[v] != INF) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    };
    bfs(dist1, a); 
    bfs(dist2, b);

    auto cal = [&](int mid) -> bool {
        vector<int> dist(n, INF);
        
        priority_queue<pii, vector<pii>, greater<> > pq;
        dist[s] = abs(dist1[s] - dist2[s]); pq.push(pii(dist[s], s));
        if (dist[s] > mid) return false;

        while (pq.size()) {
            auto [ds, u] = pq.top(); pq.pop();
            if (dist[u] < ds) continue;
            for (auto& v : g[u]) {
                int dv = abs(dist1[v] - dist2[v]);
                if (dv > mid) continue;
                dv = max(ds, dv);
                if (dv < dist[v]) {
                    dist[v] = dv;
                    pq.push(pii(dist[v], v));
                }
            }
        }
        if (dist[t] != INF) return true;
        return false;
    };

    int l = 0, r = n, ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (cal(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    cout << ans << "\n";
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









