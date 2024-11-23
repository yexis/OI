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
vector<string> cal(string s) {
    int n = s.size();
    bool ok = false;
    string l, r;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            ok = true;
            continue;
        }
        if (ok) {
            r += s[i];
        } else {
            l += s[i];
        }
    }
    if (r.size() > 6) {
        r = r.substr(0, 6);
    }
    while (r.size() < 6) {
        r += '0';
    }
    return {l, r};
}
bool check(vector<string>& a, vector<string>& b) {
    return a[0] == b[0] && a[1] == b[1];
}

void solve() {
    string a, b;
    cin >> a >> b;
    auto res1 = cal(a);
    auto res2 = cal(b);
    if (check(res1, res2)) {
        cout << YES << "\n";
    } else {
        cout << NO << "\n";
    }
}

int main() {
    solve();
    return 0;
}