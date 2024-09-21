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

/*
 * 
*/

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


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> b;
    for (auto& e : a) {
        if (e <= n) {
            b.push_back(e);
        }
    }

    int i = 0;
    ll sum = 0, t = 1;
    while (t <= n) {
        while (i < b.size() && b[i] <= t) {
            sum += b[i];
            i++;
        }
        if (sum < t) {
            cout << t << "\n";
            return;
        }
        t++;
    }

    cout << "Cool!" << "\n";
}

// 方法一:
// 维护区间[1,x]，表示可以被表示的区间
// 分情况讨论：
// 如果 a_i > x + 1: 说明 x + 1 无法被表示
// 如果 a_i <= x + 1: 说明[1, x + a_i]可被表示，则更新x
void solve_() {
    int n;
    cin >> n;
    vector<int> a(n);
    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i : a) {
        if (i > sum + 1 && sum < n) {
            cout << sum + 1 << "\n";
            return;
        }
        sum += i;
    }
    if (sum < n) {
        cout << sum + 1 << "\n";
        return;
    }
    cout << "Cool!" << "\n";
}

// 方法2：bitset优化0/1背包
void solve2() {
    int n;
     cin >> n;
     bitset<100001> dp;
     dp[0] = true;
     for (int i = 0; i < n; i++) {
         int x;
         cin >> x;
         dp |= (dp << x);
         dp[x] = true;
     }
     for (int i = 1; i <= n; i++) {
         if (!dp[i]) {
             cout << i << "\n";
             return;
         }
     }
     cout << "Cool!" << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve2();
    }
    return 0;
}