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
 * 
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        if (st.count(a[i])) {
            cout << "NO" << "\n";
            return;
        }
        st.insert(a[i]);
    }


    // vector<int> l_max(n, -1), l_min(n, inf);
    // vector<int> r_max(n, -1), r_min(n, inf);
    // for (int i = 1; i < n; i++) {
    //     l_max[i] = max(l_max[i - 1], a[i - 1]);
    //     l_min[i] = min(l_min[i - 1], a[i - 1]);
    // }
    // for (int i = n - 2; i >= 0; i--) {
    //     r_max[i] = max(r_max[i + 1], a[i + 1]);
    //     r_min[i] = min(r_min[i + 1], a[i + 1]);
    // }


    auto cal = [&]() -> bool {
        vector<int> v(n);
        v[0] = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                v[i] = 1;
            } else if (a[i] > a[i - 1]) {
                v[i] = v[i - 1] + 1;
            }
        }
//         for (auto& e : v) cout << e << " "; cout << "\n";
        
        set<int> st2{a.begin(), a.end()};
        for (int i = 0; i < n; i++) {
            st2.erase(a[i]);
            if (i - m >= 0) {
                st2.insert(a[i - m]);
            }
            
            if (v[i] < m) {
                continue;
            }
//             cout << "i:" << i << " " << st2.size() << "\n";
            int be = a[i - m + 1], en = a[i];
            auto it = st2.lower_bound(en);
            if ( (it == st2.end() || en < *it) && 
                (it == st2.begin() || *prev(it) < be) ) {
                return true;
            }
        }
        return false;
    };

    if (cal()) {
        cout << "YES" << "\n";
        return;
    }

    reverse(a.begin(), a.end());
    if (cal()) {
        cout << "YES" << "\n";
        return;
    }
    cout << "NO" << "\n";
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