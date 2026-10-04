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
 * 
*/

class CountIntervals {
    public:
        using pii = pair<int, int>;
        int sum = 0;
          // 由于要按照右端点查询lower_bound
          // 故right填充first，left填充second
        set<pii> st;
        CountIntervals() {
              sum = 0;
        }
        
        void add(int left, int right) {
            int L = left, R = right;
            auto it = st.lower_bound(pii(L - 1, -1));
            while (it != st.end()) {
                if (it->second > R + 1) {
                    break;
                }
                // it->left <= right + 1
                L = min(L, it->second);
                R = max(R, it->first);
                sum -= it->first - it->second + 1;
                it = st.erase(it);
            }
            st.insert(pii(R, L));
            sum += R - L + 1;
        }
        
        int count() {
            return sum;
        }
    };
    
    

void solve() {
    int n, q; cin >> n >> q;

    const int N = 200010;
    vector<CountIntervals> cis(N);

    while (q--) {
        int l, r, x; cin >> l >> r >> x; l--, r--;
        cis[x].add(l, r);
    }

    vector<int> D(N);
    for (int i = 1; i < N; i++) {
        for (auto [r, l] : cis[i].st) {
            D[l]++, D[r + 1]--;
        }
    }

    for (int i = 0; i < n; i++) {
        D[i] += (i - 1 >= 0 ? D[i - 1] : 0);
        cout << D[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









