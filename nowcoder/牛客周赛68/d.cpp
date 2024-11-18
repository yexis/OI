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
 * 495的因数 分桶
 * 思维题
 * 贡献法
*/
int cal(int x) {
    int a, b, c;
    a = b = c = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                if (i == 3) a++;
                else if (i == 5) b++;
                else if (i == 11) c++;
            }
        }
    }
    // x的判断一定要放在for循环外面
    if (x > 1) {
        if (x == 3) a++;
        else if (x == 5) b++;
        else if (x == 11) c++;
    }
    a = min(a, 2);
    b = min(b, 1);
    c = min(c, 1);
    int ans = 1;
    for (int i = 0; i < a; i++) ans *= 3;
    for (int i = 0; i < b; i++) ans *= 5;
    for (int i = 0; i < c; i++) ans *= 11;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    // 3 3 5 11
    vector<int> v = {1, 3, 5, 9, 11, 15, 33, 45, 55, 99, 165, 495};
    auto get = [&](int x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    };

    vector<ll> f(496);
    ll base = 0;
    for (int i = 0; i < n; i++) {
        int x = cal(A[i]);
        base += f[495 / x];
        for (auto& e : v) {
            if (x % e == 0) {
                f[e]++;
            }
        }
    }

    int m = v.size();
    vector<int> cnt(m);
    for (auto e : A) {
        for (auto ee : v) {
            if (e % ee == 0) {
                cnt[get(ee)]++;
            }
        }
    }

    ll ans = base;
    // 枚举操作每个数的变化量
    for (int i = 0; i < n; i++) {
        ll t = base;
        // 减去操作之前的影响
        int x = cal(A[i]);
        int y = 495 / x;
        int c = cnt[get(y)];
        if (x % y == 0) c--;
        t -= c;
        
        // 加上操作之后的影响
        int xx = cal(A[i] + 1);
        int yy = 495 / xx;
        int cc = cnt[get(yy)];
        if (x % yy == 0) cc--;
        t += cc;
        
        ans = max(ans, t);
    }

    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}




