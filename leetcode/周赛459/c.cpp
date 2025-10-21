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

class BIT {
private:
    int n;
    vector<int> tree;
public: 
    BIT(int n) {
    this->n = n;
    tree.resize(n + 1);
    }

    int lowbit(int x) {
        return x & -x;
    }

    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tree[i] += u;
        }
    } 

    int ask(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
    int ask(int x, int y) {
        return ask(y) - ask(x - 1);
    }
};

int cal(ll x) {
    int c = 0;
    while (x > 1) {
        x = __builtin_popcount(x);
        c++;
    }
    return c;
}
class Solution {
public:
    vector<int> popcountDepth(vector<long long>& A, vector<vector<long long>>& qs) {
        int n = A.size();

        vector<BIT> bits;
        for (int i = 0; i <= 5; i++) {
            BIT bit(n);
            bits.push_back(bit);
        }

        vector<int> B(n);
        for (int i = 0; i < n; i++) {
            ll x = A[i];
            B[i] = cal(x);
            if (B[i] <= 5) {
                bits[B[i]].add(i + 1, 1);
            }
        }

        vector<int> res;
        int m = qs.size();
        for (int i = 0; i < m; i++) {
            auto& q = qs[i];
            if (q[0] == 1) {
                ll l = q[1], r = q[2], k = q[3];
                int s = bits[k].ask(l + 1, r + 1);
                res.push_back(s);
            } else if (q[0] == 2) {
                ll j = q[1], v = q[2];

                int c_old = B[j];
                if (c_old <= 5) {
                    bits[c_old].add(j + 1, -1);
                }

                int c_new = cal(v);
                if (c_new <= 5) {
                    bits[c_new].add(j + 1, 1);
                }
                B[j] = c_new;
            }
        }

        return res;
    }
};









