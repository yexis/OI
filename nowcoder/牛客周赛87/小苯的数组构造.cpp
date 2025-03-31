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
    int n, x, y;
    cin >> n >> x >> y;
    if (n == 1 && x != y) {
        cout << "NO" << "\n";
        return;
    }
    vector<int> cnt(31);
    vector<int> v(n);
    for (int i = 0; i < 31; i++) {
        int d1 = (x >> i & 1);
        int d2 = (y >> i & 1);
        if (d1 == 0 && d2 == 1) {
            cout << "NO" << "\n";
            return;
        } else if (d1 == 0 && d2 == 0) {
            // all 0
            cnt[i] = 0;
        } else if (d1 == 1 && d2 == 0) {
            cnt[i] = 2;
        } else if (d1 == 1 && d2 == 1) {
            cnt[i] = 1;
        }
    }

    set<int> st, st2;
    for (int i = 0; i < n; i++) {
        st.insert(i);
    }

    for (int i = 0; i < 31; i++) {
        if (cnt[i] == 0) {
            // all 0
        } else if (cnt[i] == 1) {
            // odd
            int sz = st.size();
            if (sz == 0) {
                for (int j = 0; j < cnt[i]; j++) {
                    v[j] |= 1 << i;
                }
                continue;
            }
            if (sz & 1) {
                for (auto it = st.begin(); it != st.end(); ) {
                    int idx = *it;
                    v[idx] |= 1 << i;
                    it = st.erase(it);
                    st2.insert(idx);
                }
            } else {
                if (sz < n) {
                    v[*st2.begin()] |= 1 << i;
                    for (auto it = st.begin(); it != st.end(); ) {
                        int idx = *it;
                        v[idx] |= 1 << i;
                        it = st.erase(it);
                        st2.insert(idx);
                    }
                } else {
                    for (auto it = next(st.begin()); it != st.end(); ) {
                        int idx = *it;
                        v[idx] |= 1 << i;
                        it = st.erase(it);
                        st2.insert(idx);
                    }
                }
                
            }
        } else if (cnt[i] == 2) {
            int sz = st.size();
            if (sz == 0) {
                for (int j = 0; j < cnt[i]; j++) {
                    v[j] |= 1 << i;
                }
                continue;
            }
            if ((sz & 1) == 0) {
                for (auto it = st.begin(); it != st.end(); ) {
                    int idx = *it;
                    v[idx] |= 1 << i;
                    it = st.erase(it);
                    st2.insert(idx);
                }
            } else {
                if (sz < n) {
                    v[*st2.begin()] |= 1 << i;
                    for (auto it = st.begin(); it != st.end(); ) {
                        int idx = *it;
                        v[idx] |= 1 << i;
                        it = st.erase(it);
                        st2.insert(idx);
                    }
                } else {
                    for (auto it = next(st.begin()); it != st.end(); ) {
                        int idx = *it;
                        v[idx] |= 1 << i;
                        it = st.erase(it);
                        st2.insert(idx);
                    }
                }
                
            }
        }
    }

    if (st.size() > 0) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    for (auto& e : v) cout << e << " "; 
    cout << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}









