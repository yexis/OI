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
};

void output(vector<arr>& pr) {
    for (auto& [x, y, i] : pr) {
        cout << x << " " << y << " " << i << "\n";
    }
}

void solve() {
    int n, m; cin >> n >> m;
    int n2 = n << 1;
    vector<arr> seg_even, seg_even_2;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        seg_even.push_back({x, y, i});
        seg_even_2.push_back({y, x, i});
    }
    sort(seg_even.begin(), seg_even.end());
    sort(seg_even_2.begin(), seg_even_2.end(), greater());
    
    BIT bit1(n2);
    BIT bit2(n2);

    vector<arr> seg_odd, seg_odd_2;
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        seg_odd.push_back({x, y, i});
        seg_odd_2.push_back({y, x, i});
    }
    sort(seg_odd.begin(), seg_odd.end());
    sort(seg_odd_2.begin(), seg_odd_2.end(), greater());

    vector<int> res(q);
    for (int i = 0, j = 0; i < q; i++) {
        auto [x, y, idx] = seg_odd[i];
        while (j < m && seg_even[j][0] <= x) {
            auto [x1, y1, idx1] = seg_even[j];
            bit1.add(y1, 1);
            j++;
        }
        int t = 0;
        t += bit1.ask(y);
        t -= x - 1 > 0 ? bit1.ask(x - 1) : 0;
        res[idx] += t;
    }


    for (int i = 0, j = 0; i < q; i++) {
        auto [y, x, idx] = seg_odd_2[i];
        while (j < m && seg_even_2[j][0] >= y) {
            auto [y1, x1, idx1] = seg_even_2[j];
            bit2.add(x1, 1);
            j++;
        }
        int t = 0;
        t += bit2.ask(y);
        t -= x - 1 > 0 ? bit2.ask(x - 1) : 0;

        res[idx] += t;
    }

    for (auto& e : res) cout << e << "\n"; 
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









