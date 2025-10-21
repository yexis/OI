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

const int Base = 10000;

// 水平
unordered_map<int, int> A;
int sumA;
// 垂直
unordered_map<int, int> B; 
int sumB;
// 普通
map<int, map<int, int> > C;
map<int, int> sumC;

// k (x, y)  b
void cal(int x1, int y1, int x2, int y2) {
    pii k, b;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int g = gcd(dx, dy);
    dx /= g, dy /= g;

    if (dx < 0) dx *= -1, dy *= -1;
    k.first = dx, k.second = dy;
    int s1 = k.first * Base + k.second;

    // 垂直
    if (dx == 0) {
        B[x1]++;
        return;
    }
    if (dy == 0) {
        B[y1]++;
        return;
    }

    // b = y - (dy / dx) * x = y * dx - dy * x / dx
    b.first = dx, b.second = y1 * dx - dy * x1;
    g = gcd(b.first, b.second);
    b.first /= g, b.second /= g;
    int s2 = b.first * Base + b.second;
    C[s1][s2]++;

    return;
}

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& ps) {
        int n = ps.size();

        A.clear();
        B.clear();
        C.clear();
        sumA = 0;
        sumB = 0;
        sumC.clear();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x1 = ps[i][0], y1 = ps[i][1];
            int z = x1 * Base + y1;
            mp[z]++;
        }

        for (int i = 0; i < n; i++) {
            int x1 = ps[i][0], y1 = ps[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = ps[j][0], y2 = ps[j][1];
                cal(x1, y1, x2, y2);
            }
        }

        int ans = 0;

        int t = 0;
        for (auto& [k, v] : A) {
            sumA += v;
        } 
        for (auto& [k, v] : A) {
            t += v * (sumA - v);
        }
        t /= 2; ans += t;

        t = 0;
        for (auto& [k, v] : B) {
            sumB += v;
        }
        for (auto& [k, v] : B) {
            t += v * (sumB - v);
        }
        t /= 2; ans += t;


        for (auto& [k, v] : C) {
            for (auto& [b, vv] : v) {
                sumC[k] += vv;
            } 
        }

        t = 0;
        for (auto& [k, v] : C) {
            for (auto& [b, vv] : v) {
                t += vv * (sumC[k] - vv); 
            }
        }
        t /= 2; ans += t;

        // filter
        for (int i = 0; i < n; i++) {
            int x1 = ps[i][0], y1 = ps[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = ps[j][0], y2 = ps[j][1];
                int dx = x2 - x1, dy = y2 - y1;
                for (int k = j + 1; k < n; k++) {
                    int x3 = ps[k][0], y3 = ps[k][1];
                    int dx2 = x3 - x1, dy2 = y3 - y1;
                    int x4 = 0, y4 = 0;
                    x4 = x2 + dx2, y4 = y2 + dy2;
                    int z = x4 * Base + y4;
                    if (mp.count(z)) {
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};







