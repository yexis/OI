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
 * 01子序列
 * 如何快速计算区间[l,r]中01子序列的数量
 * 设sum[i+1]表示区间[0,i]中01子序列的数量
 * 设L[i][0]表示区间[0,i-1]中0的数量
 * 设L[i][1]表示区间[0,i-1]中1的数量
 * 采用前缀和的思想，那么区间[l,r]中01子序列的数量是
 * sum[r + 1] - sum[l] - L[l][0] * (L[r + 1][1] - L[l][1])
 * 即可在O(1)的时间复杂度内快速计算区间01子序列数量
*/

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> v;
    vector<vector<ll> > L(n + 1, vector<ll>(2));
    int one = 0, zero = 0;
    for (int i = 0; i <= n; i++) {
        L[i][0] = zero;
        L[i][1] = one;
        if (i == n) break;
        if (s[i] == '1') {
            one++;
        } else {
            zero++;
        }
        if (s[i] == '1') {
            v.push_back(i);
        }
    }

    int m = v.size();
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i];
        if (s[i] == '1') {
            sum[i + 1] += L[i][0];
        }
    }
    
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        ll j = -1, rs = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            ll t = (sum[mid + 1] - sum[i]) - ( L[i][0] * (L[mid + 1][1] - L[i][1]) ) ;
            if (t >= k) {
                rs = t;
                j = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (rs == k) {
            cout << i + 1 << " " << j + 1 << "\n";
            return;
        }
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

