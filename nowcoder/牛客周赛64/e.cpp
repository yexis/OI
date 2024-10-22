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
    int n = s.size();
    int mx = 0;
    vector<int> cnt(26);
    vector pos(26, vector<int>());
    for (int i = 0; i < n; i++) {
        auto ch = s[i] - 'a';
        cnt[ch]++;
        mx = max(mx, cnt[ch]);
        pos[ch].emplace_back(i);
    }

    if (mx > n / 2) {
        cout << -1 << '\n';
        return;
    }

    string sta;
    vector<int> idx;
    for (int i = 0; i < 26; i++) {
        for (auto& ii : pos[i]) {
            idx.emplace_back(ii);
        }
        sta += string(pos[i].size(), 'a' + i);
    }

    string t(n, '?');
    for (int i = 0; i < n; i++) {
        t[idx[i]] = sta[(i + mx) % n];
    }
    cout << t << "\n";
}

int main() {
    solve();
    return 0;
}