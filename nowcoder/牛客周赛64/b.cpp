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

using ll = long long;
bool fg = false;
constexpr static int maxn = 1e5;
vector<int> fac[maxn + 5];
void init() {
    for (int i = 1; i <= maxn; i++) {
        for (int j = i; j <= maxn; j += i) {
            fac[j].push_back(i);
        }
    }
}

void solve() {
    int x;
    cin >> x;
//    int p = 1;
    cout << x << "\n";
//    while (x) {
//        bool find = false;
//        cout << "=" << x << "^" << p << "\n";
//        for (int d = 2; d * d <= x; d++) {
//            if (d * d == x) {
//                x = d;
//                find = true;
//            }
//        }
//        if (not find) {
//            break;
//        }
//        p *= 2;
//    }


    auto f = fac[x];
    int m = f.size();
    for (int i = m - 1; i >= 0; i--) {
        int d = f[i];
        if (d < 2) continue;
        int p = 1, dd = d;
        while (dd < x) {
            dd *= d;
            p++;
        }
        if (dd == x) {
            cout << "=" << d << "^" << p << "\n";
        }
    }
}

int main() {
    init();
    solve();
    return 0;
}