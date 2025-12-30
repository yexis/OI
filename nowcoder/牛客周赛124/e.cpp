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
    int n; cin >> n;
    auto cal_mex = [&](vector<int>& a) -> int {
        int m = a.size();
        sort(a.begin(), a.end());  

        for (int i = 0; i < m; i++) {
            if (i != a[i]) {
                return i;
            }
        }
        return m;
    };
    auto cal = [&](int m) {
        vector<int> a(m); for (int i = 0; i < m; i++) a[i] = i;
        
        int mx = 0;
        unordered_map<int, int> mp;
        do {
            // for (auto& e : a) cout << e << " "; cout << "------------------------" << "\n";
            int sm = 0;
            for (int i = 0; i < m; i++) {
                vector<int> t;
                for (int j = i; j < m; j++) {
                    t.push_back(a[j]);
                    // cout << "t:" << " "; for (int e : t) cout << e << " "; cout << "\n";
                    int ans = cal_mex(t);
                    sm += ans;
                    // cout << "ans:" << ans << "\n";
                }
            }
            mp[sm]++;
            mx = max(mx, sm);
        } while (next_permutation(a.begin(), a.end()));
        cout << m << " " << mx << " " << mp[mx] << "\n";
    };

    // cal(4);
    for (int i = 1; i <= 17; i++) {
        cal(i);
    }

}

void solve2() {
    int n; cin >> n;
    cout << power(2, n / 2) << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve2();
    }
    return 0;
}









