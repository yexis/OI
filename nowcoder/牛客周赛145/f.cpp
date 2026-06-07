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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

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
 * 根据数据量找规律 
*/

void solve() {
    int n, K; cin >> n >> K;
    string s(n, 'b');
    // a bbbbb c
    if (K == n - 1) {
        s[0] = 'a';
        cout << s << "\n";
        return;
    }

    // 2(n - 2)
    s[0] = 'a', s[n - 1] = 'c';
    int left = 1, right = n - 2, cnt = 1;

    // 'd' ~ 'z'
    char curr_c = 'd';
    int curr = 2 * (n - 2);
    while (curr > K) {
        if (cnt & 1) {
            s[left++] = curr_c; 
            if (curr_c == 'z') curr_c = 'd'; else curr_c++;
        } else {
            s[right--] = curr_c;
            if (curr_c == 'z') curr_c = 'd'; else curr_c++;
        }
        cnt++;
        curr--;
    }
    cout << s << "\n";
}

// abbbbba 10
// acbbbca 2 + 7 = 9
// acbbbda 2 + 6 = 8
// acd b dca 4 + 3 = 7
// acd b eca 4 + 2 = 6

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









