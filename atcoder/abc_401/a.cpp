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
    int N = 1500;
    vector<int> a;
    for (int i = 1; i <= N; i++) {
        a.push_back(i);
    }
    for (auto& e : a) cout << e << ",";
    
    set<int> st;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) {
                st.insert(a[i] ^ a[j] ^ a[k]);
            }
        }
        cout << st.size() << "\n";
    }
    cout << st.size() << "\n";
}


void solve2() {
    ll fac[30];
    memset(fac, 0, sizeof(fac));
    fac[0] = 1;
    for (int i = 1; i <= 21; i++) {
        fac[i] = fac[i - 1] * i;
    }
    for (int i = 0; i <= 21; i++) {
        cout << i << "! = " << fac[i] << "\n";
    }
}
int main() {
    ios;
    cout << fixed << setprecision(20);
    solve2();
    return 0;
}









