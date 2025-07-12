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
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
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

const int N = 2e5;
struct BIT {
    int n;
    vector<int> tr;
    BIT(int _n) : n(_n), tr(_n + 1) {
        
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
            tr[i] += u;
        }
    }
    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += tr[i];
        }
        return ans;
    }
    int ask(int x, int y) {
        if (x > y) return 0; 
        return ask(y) - ask(x - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());

    BIT bit(N);
    ll base = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        base += bit.ask(x + 1 + 1, mx + 1);
        bit.add(x + 1, 1);
    }
    cout << base << "\n";

    vector<vector<int> > t(m + 1);
    for (int i = 0; i < n; i++) {
        int diff = m - a[i];
        t[diff].push_back(i);
    }
    
    for (int k = 1; k <= m - 1; k++) {
        auto& vs = t[k];
        int kn = vs.size();
        for (int i = 0; i < kn; i++) {
            int idx = vs[i]; 
            base -= (n - idx - 1) - (kn - i - 1);
            base += idx - i;
        }
        cout << base << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









