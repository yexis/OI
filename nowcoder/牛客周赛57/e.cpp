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

/*
 * 
*/

using ll = long long;
using ull = unsigned long long;
using lll = __int128;
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

void solve() {
    ll k1, k2;
    cin >> k1 >> k2;
    auto check = [&](ll k, ll n) -> bool {
        if (k < 2) return false;
        while (n) {
            if (n % k > 1) {
                return false;
            }
            n /= k;
        }
        return true;
    };

    // k1 < 7 && k2 < 7
    vector<vector<int>> a(10, vector<int>(10, 2));
    for (int i = 2; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            while (!(check(i, a[i][j]) && check(j, a[i][j])) ) {
                a[i][j]++;
            }
        }
    }
    if (k2 < 7) {
        cout << "YES" << "\n";
        cout << a[k1][k2] << "\n";
        return;
    }

    auto cal = [&](ll a, ll b) -> lll {
        lll res = 0, power = 1;
        while (a) {
            if (a & 1) {
                res *= power;
            }
            a >>= 1;
            power = power * b;
        }
        return res;
    };

    int cnt = 2;
    while (true) {
        lll num = cal(cnt, k2);
        if (num > 1e18) {
            cout << "NO" << "\n";
            return;
        }
        if (check(k1, num) && check(k2, num)) {
            cout << "YES" << "\n";
            cout << (ll)num << "\n";
            return;
        }
        cnt++;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}