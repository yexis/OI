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
 * 数论:https://ac.nowcoder.com/acm/contest/97017/F
 * 注意：a和b同时加上x时，其差是不变的
 * 
 * 题意：a中任意两个相邻元素都存在整除关系，即对于任意的a[i]和a[i+1]，都存在关系:a[i] | a[i + 1] 或者 a[i + 1] | a[i]
 * 令 d = a[i + 1] - a[i]
 * 假设加上x后，存在整除关系 (a[i + 1] + x) / (a[i + x]) = t
 * a[i + 1] + x = t * (a[i] + x)
 * a[i + 1] + x - (a[i] + x) = (t - 1) * (a[i] + x)
 * 故 d = (t - 1) * (a[i] + x)
 * 那么可以枚举d的因子，进而求出所有满足 (a[i + 1] + x) | (a[i] + x) 的 x，然后判断该x对于其他位置的元素是否满足条件
*/ 

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    
    int m = st.size();
    if (m == 1) {
        cout << k << " " << k * (k + 1) / 2 << "\n";
        return;
    }

    auto check = [&](ll x) {
        if (x < 1 || x > k) return false;
        for (int i = 0; i + 1 < n; i++) {
            ll aa = a[i] + x;
            ll bb = a[i + 1] + x;
            if (max(aa, bb) % min(aa, bb) > 0) {
                return false;
            }
        }
        return true;
    };
    // 任意取一个相邻的元素差，计算其因子
    // 这里一定要选两个不相等的元素
    int x, y;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] != a[i + 1]) {
            x = a[i];
            y = a[i + 1];
            break;
        }
    }
    if (x > y) swap(x, y);
    
    ll ct = 0, sm = 0;
    ll d = y - x;
    ll ba = x;
    for (ll i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            // i
            ll x = i - ba;
            if (check(x)) {
                ct += 1;
                sm += x;
            }
            // d / i
            x = d / i - ba;
            if (i != d / i && check(x)) {
                ct += 1;
                sm += x;
            }
        }
    }
    cout << ct << " " << sm << "\n";
}

int main() {
    ios;
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}