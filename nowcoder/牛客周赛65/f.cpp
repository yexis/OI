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

int MI = -500000000;
int MX = 500000000;
int SPE = -999999999;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    b.insert(b.begin(), MI);
    b.insert(b.end(), MX);
    int nb = b.size();

    int ans1 = 0;
    vector<int> nor;
    for (int i = 0; i < nb; i++) {
        if (b[i] != SPE) {
            nor.push_back(i);
        }
        if (i > 0 && b[i] != SPE && b[i - 1] != SPE && b[i - 1] - b[i] >= x) {
            ans1++;
        }
    }

    // max
    int ans2 = 0;
    for (int i = 0; i < nor.size() - 1; i++) {
        int idx = nor[i];
        int j = idx + 1;
        for (; j < nb && j < nor[i + 1]; j++) {
            if (b[j - 1] - x >= MI) {
                b[j] = b[j - 1] - x;
                ans2++;
            } else {
                b[j] = MX;
            }
        }
        if (j == nor[i + 1] && j - 1 >= 0 && b[j - 1] - b[j] >= x) {
            ans2++;
        }
    }

    // min
    vector<int> c = a;
    b.insert(b.begin(), MI);
    c.insert(c.end(), MX);
    int nc = c.size();

    int ans3 = 0;
    for (int i = 0; i < nor.size() - 1; i++) {
        int idx = nor[i];
        int j = idx + 1;
        for (; j < nc && j < nor[i + 1]; j++) {
            b[j] = b[j - 1];
        }
        if (j == nor[i + 1] && j - 1 >= 0 && b[j - 1] - b[j] >= x) {
            ans3++;
        }
    }
    cout << ans1 + ans2 << " " << ans1 + ans3 << "\n";
}

int main() {
    solve();
    return 0;
}