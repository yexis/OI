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
 * DP逆推
 * 背包问题
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sm = 0;
    for (int i = 0; i < n; i++) {
        sm += a[i];
    }

    if (sm & 1) {
        cout << -1 << "\n";
        return;
    }
    
    int hf = sm / 2;
    int dp[n + 1][hf + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int d = hf; d >= 0; d--) {
            dp[i][d] = dp[i - 1][d];
        }
        int x = a[i - 1];
        for (int d = hf; d >= x; d--) {
            dp[i][d] |= dp[i - 1][d - x];
        }
    }

    if (!dp[n][hf]) {
        cout << -1 << "\n";
        return;
    }

    // 逆推
    vector<int> A, B;
    int v = hf;
    for (int i = n; i >= 1; i--) {
        if (dp[i][v] == dp[i - 1][v]) {
            // 不选
            B.push_back(i - 1);
        } else {
            A.push_back(i - 1);
            v -= a[i - 1];
        }
    }

    cout << hf << "\n";
    for (auto& u : A) {
        if (a[u]) {
            for (auto& v : B) {
                if (a[u] && a[v]) {
                    cout << u + 1 << " " << v + 1 << "\n";
                    a[u]--;
                    a[v]--;
                }
                if (!a[u]) break;
            }
        }
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}