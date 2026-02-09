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
const int mod = 1e9 + 7;
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
    vector<int> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> pos(n + 1); for (int i = 1; i <= n; i++) pos[a[i]] = i;

    int same = 0; for (int i = 1; i <= n; i++) if (a[i] == i) same++;

    int id = 0;
    map<int, int> size;
    vector<int> loop(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            continue;
        }
        if (loop[i] != -1) {
            continue;
        }
        int now = ++id, sz = 0;
        int x = a[i]; 
        while (x != i) {
            loop[x] = now; sz++;
            x = a[x];
        }
        loop[x] = now; sz++;
        size[now] = sz;
    }

    int cnt = 0; for (auto& [id, sz] : size) cnt += (sz - 1);
    
    // 混乱度需要是2，所有只能是 1 + 1
    // 只能考虑相邻的两个点

    int ans = 1e9;
    // 不考虑最后一个
    for (int i = 1; i < n; i++) {
        // 两个点都不在环上
        if (loop[i] == -1 && loop[i + 1] == -1) {
            ans = min(ans, cnt + 1);
        } else if (loop[i] == -1) {
            // 点i不在环上，i + 1在环上
            ans = min(ans, cnt + 1 );
        } else if (loop[i + 1] == -1) {
            // 点i在环上，i + 1不在环上
            ans = min(ans, cnt + 1);
        } else {
            // 两个点 都在环上
            // 区分是不是同一个环
            int id1 = loop[i], id2 = loop[i + 1];
            int sz1 = size[id1], sz2 = size[id2];
            if (id1 == id2) {
                // 相同环
                // if (a[i] == i + 1 && a[i + 1] == i) {
                //     ans = min(ans, cnt - 1);
                // } else if (a[i] == i + 1) {
                //     ans = min(ans, cnt - 1);
                // } else if (a[i + 1] == i) {
                //     ans = min(ans, cnt - 1);
                // } else {
                //     ans = min(ans, cnt - 1);
                // }
                // 找规律发现，其实都是 cnt - 1
                ans = min(ans, cnt - 1);
            } else {
                // 不同环
                ans = min(ans, cnt + 1);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









