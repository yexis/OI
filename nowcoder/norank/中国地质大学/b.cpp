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


using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
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
    int n, m;
    cin >> n >> m;

    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        stk.push(i);
    }

    // 借书
    vector<int> B(1010);
    // 预约
    // 哪天有预约
    set<int> pq;
    // 预约人的名单
    vector<queue<int> > pres(2010);
    // 人是否有预约
    vector<int> pre(1010);

    for (int i = 0; i < m; i++) {
        int t;
        string op;
        cin >> t;
        cin >> op;
        // 处理预约的情况
        while (pq.size() && *pq.begin() <= t) {
            auto day = *pq.begin();
            pq.erase(day);

            auto& q = pres[day];
            while (q.size()) {
                auto pid = q.front();
                q.pop();
                pre[pid] = 0;
                // 取书
                if (stk.size()) {
                    auto book = stk.top();
                    B[pid] = book;
                    stk.pop();
                }
            }
        }

        if (op == "RESERVE") {
            int id, d;
            cin >> id >> d;
            // 借了书 或者 已经有预约
            if (B[id] || pre[id]) {
                cout << 0 << "\n";
            } else {
                int te = t + d;
                pre[id] = te;
                pres[te].push(id);
                pq.insert(te);
                cout << 1 << "\n";
            }
        } else if (op == "BORROW") {
            int id;
            cin >> id;
            // 借了书 或者 已经有预约
            if (B[id] || pre[id]) {
                cout << 0 << "\n";
            } else {
                if (stk.size()) {
                    B[id] = stk.top();
                    stk.pop();
                    cout << B[id] << "\n";
                } else {
                    cout << 0 << "\n";
                }
            }

        } else if (op == "RETURN") {
            int id;
            cin >> id;
            if (B[id]) {
                stk.push(B[id]);
                cout << B[id] << "\n";
            } else {
                cout << 0 << "\n";
            }
            B[id] = 0;
        } else if (op == "QUERY") {
            int id;
            cin >> id;
            if (B[id]) {
                cout << B[id] << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
}

int main() {
    solve();
    return 0;
}