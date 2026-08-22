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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    char g[n][m]; for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];

    int mask = 0, base = 1;
    for (int i = 0; i < 3; i++) mask += (s[i] - 'a') * base, base *= 3;

    // reverse
    int dist[n * m][27]; 
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < 27; k++) dist[i * m + j][k] = INF;

    // 最后一步移动k步 s(n - 1, m - 1)
    // priority_queue<arr, vector<arr>, greater<>> pq;
    queue<arr> pq;
    for (int msk = 0; msk < 27; msk++) {
        dist[n * m - 1][msk] = 0;
        pq.push({0, n * m - 1, msk});
    }

    while (pq.size()) {
        // (i, j, msk)
        auto [d, o, msk] = pq.front(); pq.pop();
        if (dist[o][msk] < d) continue;

        int i = o / m, j = o % m;
        int x = g[i][j] - 'a';
        
        int nxt = (msk % 9) * 3 + msk / 9;
        for (int k = 1, sub = nxt; k <= 3; k++, sub /= 3) {
            int y = sub % 3;
            if (x != y) continue;
            for (int dr = 0; dr < 4; dr++) {
                int ni = i + k * dir[dr][0], nj = j + k * dir[dr][1], no = ni * m + nj;
                if (!(ni >= 0 && ni < n && nj >= 0 && nj < m)) continue;

                if (d + 1 < dist[no][nxt]) {
                    dist[no][nxt] = d + 1; 
                    pq.push({dist[no][nxt], no, nxt});
                }
            }    
        }
    }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            if (dist[i * m + j][mask] == INF) cout << -1 << " ";
            else cout << dist[i * m + j][mask] << " ";  
        }
        cout << "\n"; 
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}


