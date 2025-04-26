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
 * https://ac.nowcoder.com/acm/contest/107879/E
 * 对于每个魔法师，只需要考虑其吟唱的时间点time的左右两个节点
 * ... time - 1, time, time + 1 ...
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    // -1: 冰冻
    // 0: 无状态 
    // 1: 燃烧
    priority_queue<pii, vector<pii>, greater<> > pq;
    priority_queue<pii, vector<pii>, greater<> > pq2;
    for (int i = 0; i < n; i++) {
        pq.emplace(a[i], 0);
    }
    
    map<int, int> occ;
    int now = 1;
    while (pq.size() || pq2.size()) {
//         cout << "now:" << now << " sz1:" << pq.size() << " sz2:" << pq2.size() << "\n";
        if (pq2.size()) {
            auto [time, sta] = pq2.top();
            if (now > time) {
                cout << "NO" << "\n";
                return;
            } else if (now < time) {
                // to deal no sta
            } else if (now == time) {
                pq2.pop();
                now++;
                continue;
            }
        }
    
        // 无状态
        if (pq.size()) {
            auto [time, sta] = pq.top();
            assert(sta == 0);
            pq.pop();
            if (now >= time + 1) {
                cout << "NO" << "\n";
                return;
            }
            // now < time + 1
            // can only to behind
            if (now >= time - 1) {
                if (occ[time + 1]) {
                    cout << "NO" << "\n";
                    return;
                }
                pq2.emplace(time + 1, 1);
                occ[time + 1] = 1;
                now++;
                continue;
            }
            // now < time - 1
            // can to front or to behind
            if (!occ[time - 1]) {
                pq2.emplace(time - 1, -1);
                occ[time - 1] = 1;
                now++;
            } else if (!occ[time + 1]) {
                pq2.emplace(time + 1, 1);
                occ[time + 1] = 1;
                now++;
            } else {
                cout << "NO" << "\n";
                return;
            }
        } else {
            // 全部安排完了
            now = pq2.top().first;
            cout << "YES" << "\n";
            return;
        }       
    }
    cout << "YES" << "\n";
    
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

/*
... time - 1, time, time + 1 ...
*/







