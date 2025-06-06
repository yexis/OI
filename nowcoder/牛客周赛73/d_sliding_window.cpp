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
 * 滑动窗口计算子序列
*/

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    ll cur = 0;
    int zero = 0, one = 0;
    int l = 0, r = -1;
    while (l < n) {
        while (r < n && cur < k) {
            r++;
            if (r == n) {
                break;
            }
            if (s[r] == '1') {
                one++;
                cur += (ll)zero;
            } else {
                zero++;
            }
        }
        if (cur == k) {
            cout << l + 1 << " " << r + 1 << "\n";
            return;
        }
        if (s[l] == '1') {
            one--;
        } else {
            cur -= one;
            zero--;
        }
        l++;
    }

    cout << -1 << "\n";
    return;
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}