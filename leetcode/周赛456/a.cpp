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

using ull = unsigned long long;
constexpr static int N = 1e6 + 5;
struct Hash {
    vector<ull> h, f;
    ull b, m;
    Hash(string& s, ull base = 131, ull mod = 2147483647) {
        this->b = base, this->m = mod;
        
        int n = s.size();
        h.resize(n);
        f.resize(n);
        
        h[0] = 0, f[0] = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                h[i] = s[i];
                continue;
            }
            h[i] = (h[i - 1] * b % m + s[i]) % m;
            f[i] = f[i - 1] * b % m;
        }
    }
    ull get(int l, int r) {
        if (l == 0) {
            return h[r];
        }
        return (h[r] - h[l - 1] * f[r - l + 1] % m + m) % m;
    }
};

class Solution {
public:
    vector<string> partitionString(string s) {
        set<ull> st;
        vector<string> res;

        int n = s.size();
        Hash ha(s);
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n) {
                ull h = ha.get(i, j);
                if (!st.count(h)) {
                    st.insert(h);
                    res.push_back(s.substr(i, j - i + 1));
                    i = j;
                    break;
                }
                j++;
            }
        }
        return res;
    }
};









