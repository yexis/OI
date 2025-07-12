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

void solve() {
    int n;
    cin >> n;
    vector<int> A(2 * n);
    unordered_set<int> app;
    for (int i = 0; i < 2 * n; i++) {
        cin >> A[i];
        A[i]--;
        if (app.count(A[i])) {
            A[i] += n;
        }
        app.insert(A[i]);
    }   

    unordered_set<int> forbid;
    for (int i = 0; i < 2 * n; i++) {
        if (i + 1 < 2 * n && abs(A[i] - A[i + 1]) == n) {
            forbid.insert(A[i]);
            forbid.insert(A[i + 1]);
        }
    }

    auto get = [&](int x) {
        if (x >= n) {
            return x - n;
        } else {
            return x + n;
        }
    };

    int ans = 0;
    set<pii> st;
    for (int i = 0; i < 2 * n; i++) {
        if (i + 1 >= 2 * n) break;
        int x = A[i], y = A[i + 1];
        if (x > y) swap(x, y);
        if (forbid.count(x) || forbid.count(y)) {
            continue;
        }

        int x1 = get(x), y1 = get(y);
        if (x1 > y1) swap(x1, y1);
        if (forbid.count(x1) || forbid.count(y1)) {
            continue;
        }

        if (st.count(pii(x1, y1))) {
            ans++;
        }
        st.insert(pii(x, y));

    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}









