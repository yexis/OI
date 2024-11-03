#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

template<class KT, class VT = null_type>
using RBTree = tree<KT, VT, std::less<KT>, rb_tree_tag, tree_order_statistics_node_update>;

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
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        string ss;
        cin >> ss;
        int mask = 0;
        for (int j = 0; j < m; j++) {
            int ch = ss[j] - '0';
            if (ch) {
                mask |= (1 << j);
            }
        }
        s[i] = mask;
    }

    int k;
    cin >> k;
    vector<int> me(k);
    for (int i = 0; i < k; i++) {
        string tt;
        cin >> tt;
        int mask = 0;
        for (int j = 0; j < m; j++) {
            int ch = tt[j] - '0';
            if (ch) {
                mask |= (1 << j);
            }
        }
        me[i] = mask;
    }

    int dp[1 << k];
    memset(dp, 0, sizeof(dp));
    for (int mask = 1; mask < (1 << k); mask++) {
        int v = 0;
        for (int d = 0; d < k; d++) {
            if (mask >> d & 1) {
                v |= me[d];
            }
        }
        dp[mask] = v;
    }

    for (int i = 0; i < n; i++) {
        int v = s[i], t = INF;
        for (int mask = 0; mask < (1 << k); mask++) {
            int c = __builtin_popcount(mask);
            if ((dp[mask] & v) == v) {
                t = min(t, c);
            }
        }
        if (t == INF) {
            cout << -1 << "\n";
        } else {
            cout << t << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}