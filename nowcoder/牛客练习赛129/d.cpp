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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    vector<int> index(n);
    iota(index.begin(), index.end(), 0);

    ll ans = 0;
    ll buf = m * k;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(index.begin(), index.end(), , [&](const auto& aa, const auto& bb) {

        }) - index.begin();

    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}