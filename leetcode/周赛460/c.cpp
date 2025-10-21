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

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

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

class Solution {
public:
    map<int, set<int>> can;
    
    void smallestValue(int n, int idx) {   
        int x = n;
        for (int i = 2; i * i <= x; i++) {
        // 满足 x % i == 0 的 i 一定是质数
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            can[x].insert(idx);
        }
        }
        // x的判断一定要放在for循环外面 
        if (x > 1) {
            can[x].insert(idx);
        }
    }
    
    int minJumps(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            smallestValue(a[i], i);
        }

        vector<int> dis(n, INF);
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push(pii(0, 0));
        dis[0] = 0;
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) {
                continue;
            }
            if (u - 1 >= 0 && d + 1 < dis[u - 1]) {
                dis[u - 1] = d + 1;
                pq.push(pii(dis[u - 1], u - 1));
            }
            if (u + 1 < n && d + 1 < dis[u + 1]) {
                dis[u + 1] = d + 1;
                pq.push(pii(dis[u + 1], u + 1));
            }
            if (can.count(a[u])) {
                for (auto& v : can[u]) {
                    if (d + 1 < dis[v]) {
                        dis[v] = d + 1;
                        pq.push(pii(dis[v], v));
                    }
                }
            }
        }
        return dis[n - 1];
    }
};








