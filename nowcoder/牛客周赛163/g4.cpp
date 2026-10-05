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

typedef long long K;
class BIT {
private:
	int n;
	vector<K> tr;
public: 
	BIT(int n) {
		this->n = n;
		tr.resize(n + 1);
	}

	int lowbit(int x) {
		return x & -x;
	}

	void add(int x, K u) {
		for (int i = x; i <= n; i += lowbit(i)) {
			tr[i] += u;
		}
	} 

	K ask(int x) {
		K ans = 0;
        if (x == 0) return 0;
		for (int i = x; i > 0; i -= lowbit(i)) {
			ans += tr[i];
		}
		return ans;
	}

	K ask(int x, int y) {
		return ask(y) - ask(x - 1);
	}
};

void solve() {
    int n, K, T; cin >> n >> K >> T;
    vector<int> P(n + 1); for (int i = 1; i <= n; i++) cin >> P[i];

    // 置换环
    int gid = 0;
    vector<int> G(n + 1, -1);
    vector<int> Mx(n + 1, -INF), Mi(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        if (G[i] != -1) continue;
        int curr = ++gid; G[i] = curr; Mx[curr] = Mi[curr] = i;
        int p = P[i]; 
        while (p != i) {
            G[p] = curr;
            Mx[curr] = max(Mx[curr], p);
            Mi[curr] = min(Mi[curr], p);
            p = P[p];
        }
    }

    vector<int> updates[n + 1];

    vector<int> Diff(n + 2);
    vector<int> Left(n + 1), Right(n + 1);
    for (int i = 1; i <= gid; i++) {
        int mi = Mi[i], mx = Mx[i];
        Right[mi] = mx; Left[mx] = mi;
        Diff[mi]++, Diff[mx]--;

        updates[mi].push_back(mx);
    }

    for (int i = 1; i <= n; i++) {
        Diff[i] += Diff[i - 1];
    } 
    
    BIT bit(n);

    ll ans = 0;
    int pt = n;
    unordered_map<int, int> mp;
    // 将 i 当成 l - 1 进行遍历
    for (int i = n; i >= 1; i--) {
        while (pt > i && bit.ask(i, pt) >= T) {
            mp[Diff[pt]]++;
            pt--;
        }
        
        if (Diff[i] <= K) ans += mp[K - Diff[i]];

        for (auto r : updates[i]) {
            bit.add(r, 1);
        }
    }

    while (pt >= 1 && bit.ask(1, pt) >= T) {
        mp[Diff[pt]]++;
        pt--;
    }
    ans += mp[K];

    cout << ans << "\n";
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









