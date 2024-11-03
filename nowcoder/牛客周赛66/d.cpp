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
    int n, m;
    cin >> n >> m;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<double> b = a;

    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        L[i] = i;
        R[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int x = n, y = -1;
            for (int j = l; j <= r; j++) {
                L[j] = min(L[j], l);
                R[j] = max(R[j], r);
                x = min(x, L[j]);
                y = max(y, R[j]);
            }
            double sum = 0;
            for (int j = x; j <= y; j++) {
                sum += a[j];
            }

            double ave = sum / (y - x + 1);
            cout << ave << "\n";
            for (int j = x; j <= y; j++) {
                b[j] = ave;
            }
        } else if(op == 2) {
            int x;
            cin >> x;
            x--;
            cout << b[x] << "\n";
        }
    }
}

int main() {
    cout << fixed << setprecision(15);
    solve();
    return 0;
}