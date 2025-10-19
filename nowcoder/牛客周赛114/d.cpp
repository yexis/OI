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

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

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

bool cmp(const arr& a, const arr& b) -> bool {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] > b[0];
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& e : a) cin >> e;

    auto get = [&](int i, int j) -> int {
        int adj = 0;
        if (i - 1 >= 0) adj += a[i - 1];
        if (i + 1 < n) adj += a[i + 1];
        return adj;
    };
    auto set = [&](int i) {
        a[i] = 0;
        if (i - 1 >= 0) a[i - 1] = 0;
        if (i + 1 < n) a[i + 1] = 0;
    };

    vector<arr> ps;
    for (int i = 0; i < n; i++) {
        int adj = get(i - 1, i + 1);
        ps.push_back(a[i], adj, i);
    }
    
    priority_queue<arr, vector<arr>, delctype(cmp)> pq(cmp);
    for (auto& e : ps) pq.push(e);
    
    // bool del[n]; memset(del, 0, sizeof(del));
    while (pq.size()) {
        auto [v, s, i] = pq.top();
        cout << v << " " << s << " " << i << "\n";
        
        pq.pop();
        if (v != a[i]) {
            continue;
        }
        int adj = get(i - 1, i + 1);
        if (s != adj) {
            pq.push_back(v, adj, i);
            continue;
        }
        ans += v;
        set(i);
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









