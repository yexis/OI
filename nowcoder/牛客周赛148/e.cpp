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
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * 
*/

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    int m = 32 - __builtin_clz(mx);

    vector<int> v(n);
    int ans = 0;
    for (int d = m - 1; d >= 0; d--) {
        fill(v.begin(), v.end(), 0);
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (!(a[i] >> d & 1)) continue;
            v[i] = 1;
            cnt1++;
        }

        // 奇数
        if (cnt1 & 1) {
            cout << -1 << "\n";
            return;
        }
        // 无
        if (cnt1 == 0) continue;

        int first_idx = 0, last_idx = n - 1;
        while (first_idx < n && v[first_idx] == 0) first_idx++;
        while (last_idx >= 0 && v[last_idx] == 0) last_idx--;

        // 最多只有一个元素能跨过尾部边界
        vector<int> L(n);
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                L[i] = L[i - 1];
            } else {
                if (last > 0) {
                    L[i] = L[last - 1] + i - last;
                } else if (last == 0) {
                    L[i] = i - last;
                } else {
                    
                }
                last = i;
            }
        }
        vector<int> R(n);
        last = n;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == 0) {
                R[i] = R[i + 1];
            } else {
                if (last < n - 1) {
                    R[i] = R[last + 1] + last - i;
                } else if (last == n - 1) {
                    R[i] = last - i;
                } else {

                }
                last = i;
            }
        }
        int c = 0;
        int t = min(R[0], L[n - 1]);
        for (int i = 0; i < n - 1; i++) {
            if (v[i]) c++;
            int curr = L[i] + R[i + 1];
            if (c & 1) curr += n - last_idx + first_idx;
            t = min(t, curr);
        }
        ans += t;
    }

    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









