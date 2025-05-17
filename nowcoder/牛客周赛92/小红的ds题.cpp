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

/*
 * 
*/

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& e : a) cin >> e;

    int curr = 0;
    vector<int> L(n, -1), R(n, -1);
    vector<vector<int>> dep;
    for (int i = n - 1; i >= 0; i--) {
        cout << "\n";
        int x = a[i];
        vector<int> tmp;
        if (i == n - 1) {
            while (x) {
                tmp.push_back(curr);
                curr++;
                x--;
            }
            dep.push_back(tmp);
            continue;
        }
        // i > 0
        int idx = 0;
        auto& nxt = dep.back();
        while (x) {
            tmp.push_back(curr);
            if (idx == nxt.size()) {
                // no node
            } else if (idx + 1 < nxt.size()) {
                int left = nxt[idx], right = nxt[idx + 1];
                L[curr] = left, R[curr] = right;
                idx += 2;
            } else if (idx + 1 == nxt.size()) {
                int left = nxt[idx];
                L[curr] = left;
                idx += 1;
            }
            x--;
            curr++;
        }
        dep.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        cout << L[i] << " " << R[i] << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









