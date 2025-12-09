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
using arr = array<int, 5>;
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
 * https://ac.nowcoder.com/acm/contest/124143/E
 * 分层图最短路
 * 在特殊的操作上，理解有点问题；
 * 时停，可以让幽灵等待2s；其实不应该一次考虑让人物移动两步；
 * 反例，如果在最后距离终点为1的点上开始时停，那么就走不到终点了
 * 而是应该分成两步考虑，每次走一步，这样才不会遗漏所有状态
*/

void solve() {
    int n, m, k; cin >> n >> m >> k;

    // 幽灵第一秒在(1,1)
    int goast[n + 1][m + 1][2]; memset(goast, 0, sizeof goast);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        goast[x1][y1][1] = 1;
        goast[x2][y2][0] = 1;
    }
    

    auto valid = [&](int r, int c) -> bool {
        return r >= 1 && r <= n && c >= 1 && c <= m;
    };

    int dist[n + 1][m + 1][3][2]; 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k1 = 0; k1 < 3; k1++) {
                for (int k2 = 0; k2 < 2; k2++) {
                    dist[i][j][k1][k2] = 1e9;
                }
            }
        }
    }
    priority_queue<arr, vector<arr>, greater<> > pq; 
    dist[1][1][0][1] = 0;
    pq.push({0, 1, 1, 0, 1});
    while (pq.size()) {
        auto [dst, r, c, use, tag] = pq.top(); pq.pop();
        if (dist[r][c][use][tag] < dst) {
            continue;
        }
        
        // 如果当前处于时停中的第一步
        if (use == 1) {
            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                if (!valid(nr, nc)) continue;
                if (goast[nr][nc][tag]) continue;
                if (dst + 1 < dist[nr][nc][use][tag]) {
                    dist[nr][nc][use][tag] = dst + 1;
                    pq.push({dst + 1, nr, nc, use, tag});    
                }
            }
            continue;
        }

        // 未开始时停，或者处于时停两步，或者已经结束
        for (int d = 0; d < 4; d++) {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            if (!valid(nr, nc)) continue;
            if (goast[nr][nc][tag^1]) continue;
            if (dst + 1 < dist[nr][nc][use][tag^1]) {
                dist[nr][nc][use][tag^1] = dst + 1;
                pq.push({dst + 1, nr, nc, use, tag^1});    
            }
        }

        // 还没开始时停
        // 可以进入 时停一步 或者 时停两步
        if (!use) {
            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                if (!valid(nr, nc)) continue;
                if (goast[nr][nc][tag]) continue;
                if (dst + 1 < dist[nr][nc][1][tag]) {
                    dist[nr][nc][1][tag] = dst + 1;
                    pq.push({dst + 2, nr, nc, 1, tag});
                }    
                for (int d2 = 0; d2 < 4; d2++) {
                    int nnr = nr + dir[d2][0];
                    int nnc = nc + dir[d2][1];
                    if (!valid(nnr, nnc)) continue;
                    if (goast[nnr][nnc][tag]) continue;
                    if (dst + 2 < dist[nnr][nnc][2][tag]) {
                        dist[nnr][nnc][2][tag] = dst + 2;
                        pq.push({dst + 2, nnr, nnc, 2, tag});
                    }    
                }
            }
        }
    }
    
    int ans = 1e9;
    auto judge = [&](int x) {
        ans = min(ans, x);
    };
    for (int k1 = 0; k1 < 3; k1++) {
        for (int k2 = 0; k2 < 2; k2++) {
            judge(dist[n][m][k1][k2]);
        }
    }
    if (ans == 1e9) {
        cout << -1 << "\n";
        return;
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









