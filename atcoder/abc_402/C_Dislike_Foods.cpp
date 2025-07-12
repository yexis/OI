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

// struct DJSet {
//     int n;
//     int count;
//     vector<int> fa;
//     DJSet(int nn) {
//         count = nn;
//         n = nn;
//         fa.resize(n);
//         iota(fa.begin(), fa.end(), 0);
//     }
//     int find(int x) {
//         if (x != fa[x]) {
//             fa[x] = find(fa[x]);
//         }
//         return fa[x];
//     }
//     void merge(int x, int y) {
//         int rx = find(x);
//         int ry = find(y);
//         if (rx == ry) {
//             return;
//         }
//         fa[ry] = rx;
//     }
//     int get() {
//         return count;
//     }
// };

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int> > st(n);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int A;
            cin >> A;
            A--;
            st[A].insert(i);
        }
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    set<int> dis;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = m - dis.size();
        int x = b[i];
        for (auto& e : st[x]) {
            dis.insert(e);
        }
    }

    for (auto& e : ans) {
        cout << e << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









