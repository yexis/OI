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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.push_back(0);
    a.push_back(m + 1);
    // 排除相同元素的影响
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    // n - 2
    
    vector<int> b(n);
    for (int i = 0; i + 1 < n; i++) {
        b[i] = a[i + 1] - a[i] - 1;
    }
    b[n - 1] = 0;

    auto check = [&]() {
        int ans = 1;
        int l = 0, r = -1;
        int cur = 0;
        while (l < n) {
            while (r < n && cur <= k) {
                r++;
                if (r == n) break;
                cur += b[r];
            }
            
            if (r == n) {
                // cur < b[r]
                int now = cur + r - l;
                if (l == 0) now--;
                if (r == n) now--;
                ans = max(ans, now);
                break;
            } else {
                // r < n
                int lst = cur - b[r];
                int rst = k - lst;
                rst = max(rst, 0);
                int now = lst + (r - l + 1) + rst;
                if (l == 0) now--;
                if (r == n) now--;
                ans = max(ans, now);
            }
            cur -= b[l];
            l++;
        }
        return ans;
    };

    int ans = check();
    // 从大到小
    reverse(a.begin(), a.end());
    for (int i = 0; i + 1 < n; i++) {
        b[i] = a[i] - a[i + 1] - 1;
    } 
    b[n - 1] = 0;
    ans = max(ans, check());
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}