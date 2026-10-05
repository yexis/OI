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
    int n, K, T; cin >> n >> K >> T;
    vector<int> P(n + 1); for (int i = 1; i <= n; i++) cin >> P[i];

    // 置换环
    int gid = 0;
    vector<int> G(n + 1, -1);
    vector<int> Mx(n + 1, -INF), Mi(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        if (G[i] != -1) continue;
        int curr = ++gid; G[i] = curr; Mx[curr] = Mi[curr] = i;
        int p = P[i]; 
        while (p != i) {
            G[p] = curr;
            Mx[curr] = max(Mx[curr], p);
            Mi[curr] = min(Mi[curr], p);
            p = P[p];
        }
    }

    vector<int> Diff(n + 2);
    vector<int> Left(n + 1), Right(n + 1);
    for (int i = 1; i <= gid; i++) {
        int mi = Mi[i], mx = Mx[i];
        Right[mi] = mx; Left[mx] = mi;
        Diff[mi]++, Diff[mx]--;
    }
    vector<int> W(n + 1);
    for (int i = 1; i <= n; i++) {
        Diff[i] += Diff[i - 1];
        W[i] = Diff[i];
    }

    unordered_map<int, int> mp;
    // for (int i = 1; i <= n; i++) mp[W[i]]++;

    ll ans = 0;
    unordered_set<int> st;
    // 位于区间[l, r]内的组数
    int l = 1, r = 1, cnt = 0;
    while (r <= n) {
        if (Right[r]) st.insert(Right[r]);
        if (st.count(r)) cnt++;
        while (l <= r && cnt >= T) {
            if (Right[l]) {
                st.erase(Right[l]);
                if (Right[l] <= r) cnt--;
            }
            mp[W[l - 1]]++;
            l++;
        }
        if (cnt < T) ans += mp[K - W[r]];
        r++;
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









