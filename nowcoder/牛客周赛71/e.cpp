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
    int n;
    cin >> n;
    map<double, int> cnt;
    for (int i = 0; i < n; i++) {
        int l, a;
        cin >> l >> a;
        cnt[l] += a;
    }
    
    bool find = false;
    double s = -1;
    for (auto& [k, v] : cnt) {
        if (v < 2) {
            continue;
        }
        // v >= 2
        v -= 2;
        double b = (double)k * sqrt(2);
        auto it = cnt.lower_bound(b);
        bool ok1 = false;
        while (it != cnt.end()) {
            if (it->second > 0 && it->first < 2 * k) {
                ok1 = true;
                break;
            }
            it = next(it);
        }
        if (ok1) {
            double rb = it->first;
            double rb2 = rb / 2;
            double h = sqrt(k * k - rb2 * rb2);
            s = max(s, 0.5 * h * rb);
            find = true;
        }
        
        bool ok2 = false;
        while (it != cnt.begin()) {
            it = prev(it);
            if (it->second > 0 && it->first < 2 * k) {
                ok2 = true;
                break;
            }
        }
        if (ok2) {
            double rb = it->first;
            double rb2 = rb / 2;
            double h = sqrt(k * k - rb2 * rb2);
            s = max(s, 0.5 * h * rb);
            find = true;
        }
        v += 2;
    }
    if (!find) {
        cout << -1 << "\n";
        return;
    }
    cout << s << "\n";
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




