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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) {
        vector<char> res(n, '.');
        for (char c : res) cout << c << ""; cout << "\n";
        return;
    }

    int o = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') o++;
    }
    
    // 剩余0个位置
    int rest = k - o;
    if (rest == 0) {
        vector<char> res(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                res[i] = '.';
            } else {
                res[i] = s[i];
            }
        }
        for (char c : res) cout << c << ""; cout << "\n";
        return;
    }

    // 有剩余位置， rest > 0
    vector<int> index;
    vector<char> res(n, '?');
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            index.push_back(i);
        }
        if (s[i] != '?') {
            res[i] = s[i];
        }
    }
    for (int idx : index) {
        if (idx - 1 >= 0 && s[idx - 1] == '?') {
            res[idx - 1] = '.';
        }
        if (idx + 1 < n && s[idx + 1] == '?') {
            res[idx + 1] = '.';
        }
    }
    int can = 0;
    for (int i = 0; i < n; i++) {
        if (res[i] != '?') continue;
        int j = i;
        while (j < n && res[j] == '?') {
            j++;
        }
        int len = j - i;
        can += (len + 1) / 2;
        i = j - 1;
    }

    if (can == rest) {
        for (int i = 0; i < n; i++) {
            if (res[i] != '?') continue;
            int j = i;
            while (j < n && res[j] == '?') {
                j++;
            }
            int len = j - i;
            if (len & 1) {
                bool fg = 1;
                for (int i1 = i; i1 < j; i1++) {
                    if (fg) res[i1] = 'o';
                    else res[i1] = '.';
                    fg ^= 1;
                }
            }
            i = j - 1;
        }
    }
    for (char c : res) cout << c << ""; cout << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









