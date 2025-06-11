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

ll cal(int x, int b) {
    return (power(x, b) - 1 + mod) % mod;
}
/*
 * 
*/

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    sort(a.begin(), a.end());

    vector<int> ob;
    map<int, int> cnt;
    for (auto& e : a) {
        cnt[e]++;
        ob.push_back(e);
    }
    vector<pii> pr;
    for (auto& [k, v] : cnt) {
        pr.emplace_back(k, v);
    }

    int con_mx = -1;
    sort(ob.begin(), ob.end());
    ob.erase(unique(ob.begin(), ob.end()), ob.end());
    for (int i = 0; i < ob.size(); i++) {
        if (ob[i] == i) {
            con_mx = i;
        }
    }

    int m = pr.size();
    ll ans = 0;
    // mex = 0; 0不出现，其他出现相同数字
    for (auto [k, v] : cnt) {
        if (k == 0) continue;
        ans += cal(2, v);
        ans %= mod;
    }
    
    int n0 = cnt[0];
    if (n0 == 0) {
        cout << ans << "\n";
        return;
    }

    if (con_mx == -1) {
        cout << ans << "\n";
        return;
    }

    // mex = 1 ，只能出现0
    ans += cal(2, n0); ans %= mod;

    // mex >= 2
    int n1 = cnt[1];
    if (n1 == 0) {
        cout << ans << "\n";
        return;   
    }

    // cout << ans << "\n";

    ll pre = cal(2, n0) * cal(2, n1) % mod;
    for (int mex = 2; mex <= con_mx + 1; mex++) {
        ans += pre;
        ans %= mod;
        pre *= cal(2, cnt[mex]);
        pre %= mod;
    }
    
    cout << ans << "\n";

}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









