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

const int dx[8][2] = {{-1, -2},
                       {-1,  2},
                       {-2,  -1},
                       {-2,  1},
                       {1, -2},
                       {1,  2},
                       {2,  -1},
                       {2,  1}};
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
 * 分层图最短路 + 反向求路径
*/

void solve() {
    int n, m, K; cin >> n >> m >> K;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    auto valid = [&](int r, int c) -> bool {
        return r <= n && r > 0 && c <= m && c > 0;
    };

    if (x1 == x1  && y1 == y2) {
        if (K & 1) {
            cout << "No" << "\n";
        } else {
            pii nxt(-1, -1);
            for (int k = 0; k < 8; k++) {
                int x = x1 + dx[k][0], y = y1 + dx[k][1];
                if (valid(x, y)) {
                    nxt = {x, y};
                    break;
                }
            }
            if (nxt == pii(-1, -1)) {
                cout << "No" << "\n";
                return;
            }
            cout << "Yes" << "\n";
            for (int i = 0; i < K; i += 2) {
                cout << x1 << " " << y1 << "\n";
                cout << nxt.first << " " << nxt.second << "\n";
            }
        }
        return;
    }


    pii pre[n + 1][m + 1][2];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 2; k++) {
                pre[i][j][k] = pii(-1, -1);
            }
        }
    }

    vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(m + 1, vector<int>(2, INF)));
    priority_queue<arr, vector<arr>, greater<> > pq;
    dist[x1][y1][0] = 0; pq.push({0, x1, y1});
    while (pq.size()) {
        auto [d, r, c] = pq.top();
        int fg = (d & 1);
        pq.pop();
        if (dist[r][c][fg] < d) {
            continue;
        }
        
        for (int k = 0; k < 8; k++) {
            int nr = r + dx[k][0];
            int nc = c + dx[k][1];
            if (!valid(nr, nc)) continue;
            if (d + 1 < dist[nr][nc][fg ^ 1]) {
                dist[nr][nc][fg ^ 1] = d + 1;
                pre[nr][nc][fg ^ 1] = pii(r, c);
                pq.push({d + 1, nr, nc});
            }
        }
    }

    auto cal = [&](int fg) -> void {
        int delta = K - dist[x2][y2][fg];
        assert(delta % 2 == 0);

        vector<pii> ans;
        while (delta > 0) {
            ans.push_back(pii(x2, y2));
            ans.push_back(pre[x2][y2][fg]);
            delta -= 2;
        }

        int mfg = fg;
        int nx = x2, ny = y2;
        while (!(nx == -1 && ny == -1)) {
            ans.push_back(pii(nx, ny));
            int nnx = pre[nx][ny][mfg].first;
            int nny = pre[nx][ny][mfg].second;
            nx = nnx, ny = nny, mfg = (mfg ^ 1);
        }

        ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << "Yes" << "\n";
        for (auto& [l, r] : ans) {
            cout << l << " " << r << "\n";
        }
    };
    
    if (dist[x2][y2][0] <= K && (K - dist[x2][y2][0]) % 2 == 0) {
        cal(0);
    } else if (dist[x2][y2][1] <= K && (K - dist[x2][y2][1]) % 2 == 0) {
        cal(1);
    } else {
        cout << "No" << "\n";
    }
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









