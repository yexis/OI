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
 * 从左往右，如果 a[i] > a[i - 1]，则i为起点
 * 从右往左，如果 a[j - 1] > a[j]，则j-1为终点 
 * (i,j)两两成对，则组成最少需要的次数方案
*/

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& e : a) cin >> e;

    

    ll cnt = 0, sum = 0;
    cnt = a[0], sum = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            cnt += a[i] - a[i - 1];
        }
        sum += a[i];
    }

    if (m < cnt || m > sum) {
        cout << -1 << "\n";
        return;
    }

    a.insert(a.begin(), 0);
    a.insert(a.end(), 0);
    
    vector<int> adds;
    vector<int> dels;
    for (int i = 1; i < n + 2; i++) {
        if (a[i] > a[i - 1]) {
            int c = a[i] - a[i - 1];
            while (c--) {
                adds.push_back(i);
            }
        } else {
            int c = a[i - 1] - a[i];
            while (c--) {
                dels.push_back(i - 1);
            }
        }
    }

    vector<pii> ans;
    int delta = m - cnt;
    for (int i = 0; i < adds.size(); i++) {
        int l = adds[i], r = dels[i];
        while (l < r && delta) {
            ans.push_back(pii(l, l));
            l++;
            delta--;
        }
        ans.push_back(pii(l, r));
    }
    for (auto [l, r] : ans) {
        cout << l << " " << r << "\n";
    }
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









