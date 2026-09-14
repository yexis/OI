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

const int N = 1e7;
vector<int> prime;
vector<int> P[8];
bool not_prime[N + 1];

void init() {
    
	not_prime[0] = not_prime[1] = true;
    for (int i = 2; i <= N; ++i) {
        if (!not_prime[i]) {
            prime.push_back(i);
            int x = i, c = 0;
            while (x) { x /= 10; c++;}
            P[c].push_back(i);
        }
        for (int p : prime) {
          	int m = i * p;
            if (m > N) break;
            not_prime[m] = true;
            if (i % p == 0) {
                // i % p == 0
                // 换言之，i 之前被 p 筛过了
                // 由于 prime 里面质数是从小到大的，所以 i 乘上其他的质数的结果 一定会被 p 筛掉
                // 就不需要在这里先筛一次，所以这里直接 break 掉就好了
              	// 证明：
              	// 假设 i / p = k，设 q 为质数，且 q > p 
              	// 那么，m = i * q = p * (k * q)，所以m一定会被 p 和 (k*q) 筛掉
                break;
            }
        }
    }
}

void solve() {
    string S; cin >> S;
    int n = S.size();

    
    auto ex = [&](string s) -> vector<vector<int>> {
        vector<int> vis(n);
        vector<vector<int>> V;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vector<int> tmp = {i};  vis[i] = true;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s[i]) {
                    vis[j] = true;
                    tmp.push_back(j);
                }
            }
            V.push_back(tmp);
        }
        return V;
    };

    auto V = ex(S);

    auto cal = [&](int x) -> bool {
        string t = to_string(x);
        assert(t.size() == S.size());

        auto V2 = ex(t);
        if (V2 == V) return true;
        return false;
    };
    
    for (int& x : P[n]) {
        if (cal(x)) {
            cout << x << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    init();

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









