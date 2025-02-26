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
 * 逆向思维
 * 双点bfs: 一个点走原图，一个点走反图
*/
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    vector<vector<char>> g2(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g2[i][j] = g[j][i];
        }
    }

    vector<vector<int>> res(n, vector<int>(n, INF));
    using tup = array<int, 3>;
    queue<tup> q;
    for (int i = 0; i < n; i++) {
        res[i][i] = 0;
        q.push({i, i, 0});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (g[i][j] != '-') {
                res[i][j] = 1;
                q.push({i, j, 1});
            }
        }
    }

    while (q.size()) {
        auto [i, j, d] = q.front();
        q.pop();
        for (int ii = 0; ii < n; ii++) {
            if (g2[i][ii] == '-') continue;
            for (int jj = 0; jj < n; jj++) {
                if (g[j][jj] == '-') continue;
                if (g2[i][ii] != g[j][jj]) continue;
                // 这一行很重要
                if (res[ii][jj] < d + 2) continue;
                res[ii][jj] = d + 2;
                q.push({ii, jj, res[ii][jj]});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (res[i][j] == INF ? -1 : res[i][j]) << " ";
        }
        cout << "\n";
    }
    return;
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}
