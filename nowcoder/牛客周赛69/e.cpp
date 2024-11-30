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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sm = 0;
    for (auto& e : a) sm += e;
    if (sm % 3 != 0) {
        cout << 0 << "\n";
        return;
    }
    ll mm = sm / 3;
    
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    vector<int> can;
    for (int i = 1; i <= n; i++) {
        if (sum[i] == mm) {
            can.push_back(i);
        }
    }

    vector<ll> suf(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suf[i] = a[i];
        } else {
            suf[i] = suf[i + 1] + a[i];
        }
    }
    vector<int> can2;
    for (int i = n - 1; i >= 0; i--) {
        if (suf[i] == mm) {
            can2.push_back(i);
        }
    }
    reverse(can2.begin(), can2.end());

    // 最左边的正数
    // 最右边的正数
    int zl = n;
    int zr = -1;

    vector<int> R(n, n);
    int lst = n;
    for (int i = n - 1; i >= 0; i--) {
        R[i] = lst;
        if (a[i] > 0) {
            lst = i;
        }
        if (a[i] > 0 && zr == -1) {
            zr = i;
        }
        if (a[i] > 0) {
            zl = i;
        }
    }
    cout << "mm:" << mm << "\n";
    cout << "z:" << zl << " " << zr << " " << "\n";
    
    if (zl == n || zr == -1)  {
        cout << 0 << "\n";
        return;
    }

    ll ans = 0;
    // bool find = false;
    for (int i = 0; i < n; i++) {
        if (sum[i + 1] != mm) continue;
        if (i < zl) continue;
        int r = R[i];
        int start = lower_bound(can2.begin(), can2.end(), r) - can2.begin();
        if (start == n) continue;
        int end = lower_bound(can2.begin(), can2.end(), zr) - can2.begin();
        if (end == n) continue;
        cout << start << " " << end << "\n";
        ans += (end - start);
    }
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}


// 从a中选k个数，从b中选n-k个数，求最大和
int select(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    // 先全部选b
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[i];
    }
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        diff.emplace_back(a[i] - b[i]);
    }
    sort(diff.begin(), diff.end(), greater());
    for (int i = 0; i < k; i++) {
        sum += diff;
    }
    return sum;
}


// 从a中选k个数，从b中选n-k个数，求最大和
int select2(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    // 先全部选b
    int sum = 0;
    vector<pair<int, int> > diff;
    for (int i = 0; i < n; i++) {
        diff.emplace_back(a[i] - b[i], i);
    }
    sort(diff.begin(), diff.end(), greater());
    for (int i = 0; i < k; i++) {
        auto [df, ii] = diff[i];
        if (i < k) {
            sum += b[ii] + df;
        } else {
            sum += b[ii];
        }
    }
    return sum;
}
