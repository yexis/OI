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

class Solution {
public:
    char processStr(string s, long long K) {
        int n = s.size();
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                tot -= 1;
            } else if (s[i] == '#') {
                tot *= 2;
            } else if (s[i] == '%') {
                // no change
            } else {
                tot += 1;
            }
        }      
        cout << "tot:" << tot << "\n";

        if (K >= tot) {
            return '.';
        }

        char ans = '.';

        map<ll, char>  mp;
        map<ll, ll> mp2;

        int curr = K - 1;
        ll l = 0, r = K - 1;
        ll ind = K - 1;
        ll len = r - l + 1;
        int par = 0;
        
        deque<char> q;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') {
                len += 1;
                r += 1;

            } else if (s[i] == '#') {
                len = len / 2;
                r -= len;
                
            } else if (s[i] == '%') {
                ind = (l + r - ind);
                if (r - ind + 1 <= q.size()) {
                    int diff = r - ind;
                    ans = q[diff];
                    break;
                }
            } else {
                q.push_back(s[i]);
            }
        }


        return ans;
    }
};








