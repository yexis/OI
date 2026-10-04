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
    int n, K; cin >> n >> K;
    if (K > (n + 1) / 2) {
        cout << "No" << "\n";
        return;
    }

    if (K == 1) {
        cout << "Yes" << "\n";
        for (int i = 1; i <= n; i++) cout << i << " "; cout << "\n";
        return;
    }

    // K > 1
    K--;
    int curr = 0;
    vector<int> res(n + 1);
    if (n & 1) {
        int cnt = 1;
        res[(n + 1) / 2] = 1; curr = 1;
        int l = (n + 1) / 2 - 1; 
        int r = (n + 1) / 2 + 1;
        while (curr < K) {
            res[l--] = ++cnt;
            res[r++] = ++cnt;
            curr++;
        }
        for (int i = 1; i <= l; i++) res[i] = ++cnt;
        for (int i = n; i >= r; i--) res[i] = ++cnt;
    } else {
        int cnt = 1; res[n] = 1; 
        res[n / 2] = ++cnt; curr = 1;
        int l = n / 2 - 1; 
        int r = n / 2 + 1;
        while (curr < K) {
            res[l--] = ++cnt;
            res[r++] = ++cnt;
            curr++;
        }
        for (int i = 1; i <= l; i++) res[i] = ++cnt;
        for (int i = n - 1; i >= r; i--) res[i] = ++cnt;
    }

    cout << "Yes" << "\n";
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
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









