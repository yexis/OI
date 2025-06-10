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
#define debug(x) cerr << (#x) << " = " << (x) << endl;

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

void solve() {

}

int main() {
    ios;
    cout << fixed << setprecision(20);
    ll d, p; cin >> d >> p;

    int g = gcd(d, p);
    ll step = p / g;
    // step * d = p * delta
    // step = p / d * delta

    // ll tmp = d;
    // for (int i = 1; i < step; i++) {
    //     ll ctmp;
    //     ctmp = (tmp + d) % p;
    //     if (ctmp == 1) {
    //         step = i;
    //         break;
    //     }
    // }

    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        ll len = (r - l + 1);
        if (p == 1) {
            if (l == 1) {
                if (r > 1) {
                    cout << 2 << "\n";
                } else {
                    cout << 1 << "\n";
                }
            } else {
                cout << 1 << "\n";
            }
            continue;
        }
        if (len >= step) {
            cout << step << "\n";
        } else {
            cout << len << "\n";
        }
    }
    return 0;
}









