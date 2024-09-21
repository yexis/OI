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

void solve() {

}

int main() {
    string s1 = "https://www.nowcoder.com";
    string s2 = "www.nowcoder.com";
    string t1 = "https://ac.nowcoder.com";
    string t2 = "ac.nowcoder.com";
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.size() >= s1.size() && s.substr(0, s1.size()) == s1) {
            cout << "Nowcoder" << "\n";
            continue;
        }
        if (s.size() >= s2.size() && s.substr(0, s2.size()) == s2) {
            cout << "Nowcoder" << "\n";
            continue;
        }
        if (s.size() >= t1.size() && s.substr(0, t1.size()) == t1) {
            cout << "Ac" << "\n";
            continue;
        }
        if (s.size() >= t2.size() && s.substr(0, t2.size()) == t2) {
            cout << "Ac" << "\n";
            continue;
        }

        cout << "No" << "\n";
    }
    return 0;
}