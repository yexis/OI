#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

template<class KT, class VT = null_type>
using RBTree = tree <KT, VT, std::less<KT>, rb_tree_tag, tree_order_statistics_node_update>;

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
 * 并查集
*/

struct DJ {
    int n;
    vector<int> fa;
    vector<int> count;
    DJ(int nn) {
        n = nn;
        fa.resize(n);
        count.resize(n, 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return;
        }
        fa[ry] = rx;
        count[rx] += count[ry];
    }
};

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll mx = *max_element(a.begin(), a.end());
    mx = max(mx, k);

    DJ dj(n);

    vector<bool> del(n);
    int b = 64 - __builtin_clzll(mx) - 1;
    for (int i = b; i >= 0; i--) {
        int sub = (k >> i & 1);
        if (sub == 0) {
            vector<int> st;
            for (int j = 0; j < n; j++) {
                if (del[j]) continue;
                if (a[j] >> i & 1) {
                    st.push_back(j);
                } else if (i == 0) {
                    st.push_back(j);
                }
            }
            if (st.size() > 1) {
                for (int j = 1; j < (int)st.size(); j++) {
                    dj.merge(st[0], st[j]);
                }
            }
        } else if (sub == 1) {
            vector<int> st;
            for (int j = 0; j < n; j++) {
                if (del[j]) continue;
                if (a[j] >> i & 1) {
                    if (i == 0) {
                        st.push_back(j);
                    }
                } else {
                    del[j] = true;
                }
            }
            if (st.size() > 1) {
                for (int j = 1; j < (int)st.size(); j++) {
                    dj.merge(st[0], st[j]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dj.count[dj.find(i)]);
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
/*
00001

00101
10101
00001
01000
01010
*/


/*
0100

0101
0011
0111
1010
1111
*/