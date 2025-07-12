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
 * meet in middle
 * 在两个有序列表中 a = [...], b = [...], 所有元素均小于m
 * 
 * 如何查询 (a_i + b_j) 最接近target的值
 * - 二分，遍历 a_i，lower_bound(m - b_j)
 * 
 * 如何查询 (a_i + b_j) % m 最接近target的值
 * 1. 和不超过m 二分，遍历 a_i，lower_bound(m - b_j)
 * 2. 和可能超过m, (a_j + *b.rbegin() ) % m
 * 
*/

void solve() {
    int n, m;
    cin >> n >> m;
    ll g[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    if (n == 1) {
        cout << g[0][0] % m << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dis = (n - i - 1) + (n - j - 1);
            g[i][j] = g[i][j] * power(10, dis, m) % m;
        }
    }
    
    set<ll> dp[n][n];
    dp[0][0].insert(g[0][0] % m);
    for (int i = 1; i < n; i++) {
        for (auto& e : dp[i - 1][0]) {
            dp[i][0].insert((e + g[i][0]) % m);
        }
    }
    for (int j = 1; j < n; j++) {
        for (auto& e : dp[0][j - 1]) {
            dp[0][j].insert((e + g[0][j]) % m);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i + j > n - 1) {
                continue;
            }
            for (auto& e : dp[i - 1][j]) {
                dp[i][j].insert((e + g[i][j]) % m);
            }
            for (auto& e : dp[i][j - 1]) {
                dp[i][j].insert((e + g[i][j]) % m);
            }
        }
    }

    set<ll> dp2[n][n];
    dp2[n - 1][n - 1].insert(g[n - 1][n - 1] % m);
    for (int i = n - 2; i >= 0; i--) {
        for (auto& e : dp2[i + 1][n - 1]) {
            dp2[i][n - 1].insert((e + g[i][n - 1]) % m);
        }
    }
    for (int j = n - 2; j >= 0; j--) {
        for (auto& e : dp2[n - 1][j + 1]) {
            dp2[n - 1][j].insert((e + g[n - 1][j]) % m);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (n - i - 1 + n - j - 1 > n - 1) {
                continue;
            }
            for (auto& e : dp2[i + 1][j]) {
                dp2[i][j].insert((e + g[i][j]) % m);
            }
            for (auto& e : dp2[i][j + 1]) {
                dp2[i][j].insert((e + g[i][j]) % m);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1) {
                for (auto& e : dp[i][j]) {
                    if (i + 1 < n) {
                        // e + f 超过 m 的情况
                        ans = max(ans, (e + *dp2[i + 1][j].rbegin()) % m);
                        // e + f 不超过 m 的情况
                        auto it = dp2[i + 1][j].lower_bound(m - e);
                        if (it != dp2[i + 1][j].begin()) {
                            ans = max(ans, e + *prev(it));
                        }
                    }
                    if (j + 1 < n) {
                        // e + f 超过 m 的情况
                        ans = max(ans, (e + *dp2[i][j + 1].rbegin()) % m);
                        // e + f 不超过 m 的情况
                        auto it = dp2[i][j + 1].lower_bound(m - e);
                        if (it != dp2[i][j + 1].begin()) {
                            ans = max(ans, e + *prev(it));
                        }
                    }
                }
            }
        }
    } 
    cout << ans << "\n";
}

// 打印杨辉三角(预估数据量)
void init() {
    int N = 20;
    // 正三角
    vector<ll> g[2 * N + 1];
    for (int len = 1; len <= N; len++) {
        g[len].resize(len);
        g[len][0] = g[len][len - 1] = 1;
        for (int i = 1; i < len - 1; i++) {
            g[len][i] = g[len - 1][i - 1] + g[len - 1][i];
        }
    }

    // 反三角
    for (int len = N + 1; len <= 2 * N; len++) {
        int l = g[len - 1].size() - 1;
        if (l <= 0) break;
        g[len].resize(l);
        for (int i = 0; i < l; i++) {
            g[len][i] = g[len - 1][i] + g[len - 1][i + 1];
        }
    }
    for (int i = 1; i <= 2 * N; i++) {
        cout << "level:" << i << " --- ";
        for (auto& e : g[i]) {
            cout << e << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    init();
    // solve();
    return 0;
}









