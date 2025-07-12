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
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

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

void test(int x, int y) {
    vector<pii> a;
    a.push_back({x, 0});
    a.push_back({y, 0});
    int ans = INF;
    while (true) {
        vector<pii> b = a;
        for (int i = 0; i < a.size(); i++) {
            auto [e1, t1] = a[i];
            for (int j = i + 1; j < a.size(); j++) {
                auto [e2, t2] = a[j];
                int t = max(t1, t2) + 1;
                b.emplace_back(e1 & e2, t);
                b.emplace_back(e1 | e2, t);
                b.emplace_back(e1 ^ e2, t);
                b.emplace_back(gcd(e1, e2), t);
            }
        }
        for (auto& [e, t] : b) {
            if (e == 0) {
                ans = min(ans, t);
            }
        }
        if (ans != INF) {
            cout << x << " " << y << " " << ans << "\n";
            return;
        }
        a.swap(b);
    }
}
void solve() {
    int x, y;
    cin >> x >> y;
    vector<pii> a;
    a.push_back({x, 0});
    a.push_back({y, 0});
    int ans = INF;
    while (true) {
        vector<pii> b = a;
        for (int i = 0; i < a.size(); i++) {
            auto [e1, t1] = a[i];
            for (int j = i + 1; j < a.size(); j++) {
                auto [e2, t2] = a[j];
                int t = max(t1, t2) + 1;
                b.emplace_back(e1 & e2, t);
                b.emplace_back(e1 | e2, t);
                b.emplace_back(e1 ^ e2, t);
                b.emplace_back(gcd(e1, e2), t);
            }
        }
        for (auto& [e, t] : b) {
            if (e == 0) {
                ans = min(ans, t);
            }
        }
        if (ans != INF) {
            cout << ans << "\n";
            return;
        }
        a.swap(b);
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 1; j <= 10000; j++) {
            test(i, j);
        }
    }
    return 0;
}









