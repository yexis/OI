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
const int mod = 998244353;
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
    int n;
    cin >> n;
    vector<int> pre(n);
    for (auto& e : pre) cin >> e;
    if (pre.back() != 1) {
        cout << 0 << "\n";
        return;
    }

    vector<pii> pr;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && pre[i] == pre[j]) {
            j++;
        }
        pr.emplace_back(pre[i], j - i);
        i = j - 1;
    }
    // for (auto& [e, cnt] : pr) cout << e << " " << cnt << "\n";

    ll ans = 1;
    int last = n + 1;
    int rest = 0;
    for (int i = 0; i < (int)pr.size(); i++) {
        auto [e, cnt] = pr[i];
        if (i > 0 && e > pr[i - 1].first) {
            cout << 0 << "\n";
            return;
        }
        rest += last - e - 1;
        int cnt1 = cnt - 1;
        if (rest < cnt1) {
            cout << 0 << "\n";
            return;
        }
//         cout << cnt1 << " " << rest << "\n";
        while (cnt1) {
            ans *= rest;
            ans %= mod;
            rest--;
            cnt1--;
        }
        last = e;
    }

    cout << ans << "\n";
    return;
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}









