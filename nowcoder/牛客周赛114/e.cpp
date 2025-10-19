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

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
        cout << 0 << "\n";
        cout << "" << "\n";
        return;
    }
    
    vector<int> A(a + 2);
    int len = a + 2;
    int gid = 0;
    
    if (b > a || c > a) {
        cout << -1 << "\n";
        return;
    }
    
    int n6 = min(b, c);
    
    // 放6
    if (n6 > 0) {
        int cpn6 = n6;
        A[0] = 1, A[1] = 2;
        gid = 2;
        for (; gid < len && cpn6 > 0; gid++) {
            int pre = A[gid - 1] + A[gid - 2];
            if (6 - pre >= 1) {
                A[gid] = 6 - pre;
                cpn6--;
            }
        } 
        // 最后两位和不能是4
        while (A[gid - 1] + A[gid - 2] != 5) {
            int t = A[gid - 1];
            for (int i = gid - 1; i > 0; i--) {
                A[i] = A[i - 1];
            }
            A[0] = 6 - A[1] - A[2];
        }
        b -= n6;
        c -= n6;
    }

    
    if (b > 0) {
        // 放2
        if (n6 == 0) {
            A[0] = A[1] = 3;
            gid = 2;
        }
        for (; gid < len && b > 0; gid++) {
            int pre = A[gid - 1] + A[gid - 2];
            if (8 - pre >= 1 && 8 - pre <= 3) {
                A[gid] = 8 - pre;
                b--;
            }
        }   
    } else if (c > 0) {
        if (n6 == 0) {
            A[0] = 3, A[1] = 3;
            gid = 2;
        }
        for (; gid < len && c > 0; gid++) {
            int pre = A[gid - 1] + A[gid - 2];
            int kt = 3;
            while (true) {
                if (kt > pre && kt % 2 > 0) {
                    break;
                }
                kt *= 3;
            }
            A[gid] = kt - pre;
            c--;
        }
    }

    for (; gid < len; gid++) {
        if (A[gid]) continue;
        if (gid < 2) {
            A[gid] = 3;
            continue;
        }
        int pre = A[gid - 1] + A[gid - 2];
        A[gid] = 77777777 - pre;
    }
    
    cout << a + 2 << "\n";
    for (auto& e : A) cout << e << " "; cout << "\n";
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









