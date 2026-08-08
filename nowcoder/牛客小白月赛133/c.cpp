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

void solve() {
    int n, K; cin >> n >> K;
    const int N1 = 5;
    const int N2 = 12;

    string s; cin >> s;
    if (n < 17) {
        cout << "No" << "\n";
        return;
    }

    
    string p1 = "awdec";
    string p2 = "Fantasy_Blue";
    vector<int> f1(n, INF), f2(n, INF);
    for (int i = 0; i < n; i++) {
        if (i < N1 - 1) continue;
        int c = 0;
        for (int j = 0; j < N1; j++) {
            if (s[i - j] != p1[N1 - 1 - j]) c++;
        }
        f1[i] = min(f1[i - 1], c);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (i > n - N1) continue;
        int c = 0;
        for (int j = 0; j < N1; j++) {
            if (s[i + j] != p1[j]) c++;
        }
        f2[i] = min(f2[i + 1], c);
    }

    vector<int> g1(n, INF), g2(n, INF);
    for (int i = 0; i < n; i++) {
        if (i < N2 - 1) continue;
        int c = 0;
        for (int j = 0; j < N2; j++) {
            if (s[i - j] != p2[N2 - 1 - j]) c++;
        }
        g1[i] = min(g1[i - 1], c);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i > n - N2) continue;
        int c = 0;
        for (int j = 0; j < N2; j++) {
            if (s[i + j] != p2[j]) c++;
        }
        g2[i] = min(g2[i + 1], c);
    }

//     for (int i = 0; i < n; i++) cout << f2[i] << " "; cout << "\n";
    
    for (int i = 0; i < n - 1; i++) {
        if (f1[i] + g2[i + 1] <= K) {
            cout << "Yes" << "\n";
            return;
        }
        if (g1[i] + f2[i + 1] <= K) {
            cout << "Yes" << "\n";
            return;
        }
    }
    cout << "No" << "\n";
}

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









