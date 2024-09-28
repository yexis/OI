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
    string s;
    cin >> s;
    int m = s.size();
    int n;
    cin >> n;
    vector<pii> pr(n);
    for (int i = 0; i < n; i++) {
        cin >> pr[i].first >> pr[i].second;
    }

    string ans;
    int lt = n;
    int st = 0, en = m - 1;
    for (int i = n; i >= 0; i--) {
        auto [t, p] = pr[i];
        int len = lt - t;
        if (p == 1) {
            ans = s.substr(st, len) + ans;
            st += len;
        } else if (p == 2) {
            ans = s.substr(en - len, len) + ans;
            en -= len;
        }
        lt = t;
    }
    if (st <= en) {
        ans = s.substr(st, en - st + 1) + ans;
    }
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}