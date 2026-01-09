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
#define debug(x) cerr << (#x) << " = " << (x) << endl;

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

void solve() {
    int h, w;
    cin >> h >> w;
    char g[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<char>> res(h, vector<char>(w, '?'));

    queue<pii> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == 'E') {
                q.push(pii(i, j));
                res[i][j] = 'E';
            } else if (g[i][j] == '#') {
                res[i][j] = '#'; 
            }
        }
    }
    auto valid = [&](int r, int c) {
        return r >= 0 && r < h && c >= 0 && c < w;
    };
    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            if (!valid(ni, nj)) continue;
            if (g[ni][nj] == '#' || g[ni][nj] == 'E') continue;
            if (res[ni][nj] != '?') continue;
            if (d == 0) {
                res[ni][nj] = 'v';
            } else if (d == 1) {
                res[ni][nj] = '^';
            } else if (d == 2) {
                res[ni][nj] = '>';
            } else if (d == 3) {
                res[ni][nj] = '<';
            }
            q.push(pii(ni, nj));
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









