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
        if (r - l > T) del[i] = 1; 
    }
    
    vector<int> ob;
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
    for (int i = 0; i < n; i++) {
        if (del[i]) continue;
        if (R[i] - L[i] == T) {
            continue;
        }
        int l = get(L[i]), r = get(R[i]);
        // right
        int p = get(L[i] + T); 
        // VR[p]
        auto& vec = VR[p];
        int k1 = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
        int k2 = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
        ans += max(k2 - k1, 0);
        
        p = get(R[i] - T);
        // VL[p]
        auto& vec2 = VL[p];
        int k3 = lower_bound(vec2.begin(), vec2.end(), l) - vec2.begin();
        int k4 = lower_bound(vec2.begin(), vec2.end(), r) - vec2.begin();
        ans += max(k4 - k3, 0);
    }



    cout << ans / 2 << "\n";
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









