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
    vector<pii> pr(n); for (auto& [fi, se] : pr) cin >> fi >> se;
    
    vector<int> ob, V;
    for (auto& [fi, se] : pr) {
        ob.push_back(fi); ob.push_back(fi + K);
        ob.push_back(se); ob.push_back(se + K);
        
        // 按照贪心的思想，为了重合尽可能多的区间
        // 选择的区间一定是给定n个区间中某个区间的右端点
        V.push_back(se);
    }
    sort(V.begin(), V.end()); V.erase(unique(V.begin(), V.end()), V.end());
    sort(ob.begin(), ob.end()); ob.erase(unique(ob.begin(), ob.end()), ob.end());
    auto get = [&](int x) -> int {
        return lower_bound(ob.begin(), ob.end(), x) - ob.begin() + 1;
    };
    int m = V.size();

    sort(pr.begin(), pr.end());
    priority_queue<pii, vector<pii>, greater<>> pq;

    int ans = 0;
    int j; j = 0;
    for (int i = 1; i <= m; i++) {
        // 这里get(V[i - 1])不等于 L 吗？
        // 卧槽，不等，因为L不再是ob的下标了
        int L = get(V[i - 1]);
        int R = get(V[i - 1] + K);
        while (pq.size() && get(pq.top().first) < L) {
            pq.pop();
        }
        while (j < n && get(pr[j].first) <= R) {
            pq.push(pii(pr[j].second, pr[j].first));
            j++;
        }
        ans = max(ans, (int)pq.size());
    }
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









