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
    int n, m, q;
    cin >> n >> m >> q;
    char g[n][m]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    char qq[q][n][m];
    for (int k = 0; k < q; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> qq[k][i][j];
            }
        }
    }

    int ans = INF;
    vector<int> res;
    for (int mask = 0; mask < (1 << q); mask++) {
        bool ok = false;
        int cnt = __builtin_popcount(mask);

        bool h[n][m];
        memset(h, 0, sizeof(h));
        for (int d = 0; d < q; d++) {
            if (mask >> d & 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (qq[d][i][j] == '1') {
                            h[i][j] = true;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '1' && h[i][j] == false) {
                    ok = false;
                }
                if (g[i][j] == '0' && h[i][j] == true) {
                    ok = false;
                }
            }
        }

        if (ok && cnt < ans) {
            ans = cnt;
            res.clear();
            for (int d = 0; d < q; d++) {
                res.push_back(d + 1);
            }
        }
    }
    if (ans == INF) {
        cout << -1 << "\n";
        return;
    }
    
    cout << ans << "\n";
    for (auto& e : res) {
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}




