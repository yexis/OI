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

// vector<int> bfs(vector<vector<pair<int, int>>>& g, int s) {
//     int n = grid.size();
//     vector<int> dis(n);
//     deque<int> q;
//     dis[s] = 0;
//     q.emplace(s);
//     while (!q.empty()) {
//         auto u = q.front();
//         q.pop_front();
//         for (auto [v, w] : g[u]) {
//             if (d + w < dis[v]) {
//                 dis[v] = d + w;
//                 if (w) {
//                     q.emplace_back(v);
//                 } else {
//                     q.emplace_back(v);
//                 }
//             }
//         }
//     }
//     return dis;
// }

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) {
        cin >> g[i];
    }
    auto valid = [&](int r, int c) {
        return r >= 0 && r < h && c >= 0 && c < w;
    };
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--, B--, C--, D--;
    vector<vector<int> > dis(h, vector<int>(w, INF));
    deque<pii> q;
    dis[A][B] = 0;
    q.emplace_back(pii(A, B));
    while (!q.empty()) {
        auto [r, c] = q.front();
        // cout << r << " " << c <<  " " << dis[r][c] << "\n";
        q.pop_front();
        for (int d = 0; d < 4; d++) {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            int nrr = nr + dir[d][0];
            int ncc = nc + dir[d][1];
            if (!valid(nr, nc)) continue;
            // if (dis[nr][nc] != INF) continue;
            if (g[nr][nc] == '.') {
                if (dis[nr][nc] <= dis[r][c]) continue;
                dis[nr][nc] = dis[r][c];
                q.push_front(pii(nr, nc));
            } else {
                if (dis[nr][nc] > dis[r][c] + 1) {
                    dis[nr][nc] = dis[r][c] + 1;
                    q.push_back(pii(nr, nc));
                }
                if (valid(nrr, ncc) && dis[nrr][ncc] > dis[r][c] + 1) {
                    dis[nrr][ncc] = dis[r][c] + 1;
                    q.push_back(pii(nrr, ncc));
                }
                
            }
        }
    }
    cout << dis[C][D] << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









