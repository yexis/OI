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
    int n, T; cin >> n >> T;
    vector<int> L(n), R(n); for (int i = 0; i < n; i++) cin >> L[i] >> R[i];

    vector<int> del(n);
    for (int i = 0; i < n; i++) {
        int l = L[i], r = R[i];
        if (r - l == T) del[i] = 1; 
        else if (r - l > T) del[i] = 2;
    }
    
    vector<int> ob;
    // 长度大于T的弦不可能，直接删除即可
    for (int i = 0; i < n; i++) {
        if (del[i]) continue;
        int l = L[i], r = R[i];
        ob.push_back(l); ob.push_back(l + T);
        ob.push_back(r); ob.push_back(r - T);
    }
    sort(ob.begin(), ob.end());
    ob.erase(unique(ob.begin(), ob.end()), ob.end());
    int m = ob.size();
    auto get = [&](int x) -> int {
        return lower_bound(ob.begin(), ob.end(), x) - ob.begin();
    };

    
    vector<int> VL[m], VR[m];
    for (int i = 0; i < n; i++) {
        if (del[i]) continue;
        int l = get(L[i]), r = get(R[i]);
        VL[l].push_back(r);
        VR[r].push_back(l);
    }
    for (int i = 0; i < m; i++) {
        auto& vec = VL[i]; sort(vec.begin(), vec.end());
        auto& vec2 = VR[i]; sort(vec2.begin(), vec2.end());
    }

    ll ans = 0;
    // 长度小于T的弦，可以两两配对，最后除以2
    for (int i = 0; i < n; i++) {
        if (del[i]) continue;
        int l = get(L[i]), r = get(R[i]);
        
        // right
        int p = get(L[i] + T); 
        auto& vec = VR[p];
        int k1 = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
        int k2 = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
        ans += max(k2 - k1, 0);

        // left
        p = get(R[i] - T);
        auto& vec2 = VL[p];
        int k3 = lower_bound(vec2.begin(), vec2.end(), l) - vec2.begin();
        int k4 = lower_bound(vec2.begin(), vec2.end(), r) - vec2.begin();
        ans += max(k4 - k3, 0);
    }

    ans /= 2;

    // 长度等于T的弦，比较特殊；位于该弦区间内的所有弦都能与之配对，所以采用滑动窗口
    vector<arr> pr; for (int i = 0; i < n; i++) pr.push_back(arr{L[i], R[i], i});
    sort(pr.begin(), pr.end(), [&](auto& aa, auto& bb) {
        // 对于相同右端点
        // 为了保证在处理长度为T的弦时，长度小于T的弦都已经被处理
        if (aa[1] == bb[1]) {
            return aa[0] > bb[0];
        }
        return aa[1] < bb[1];
    });

    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int l = pr[i][0], r = pr[i][1], idx = pr[i][2];
        if (del[idx] > 1) continue;
        if (del[idx] == 1) {
            // ==
            while (st.size() && *st.begin() < l) {
                st.erase(st.begin());
            }
            ans += (int)st.size();
        }
        st.insert(l);
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









