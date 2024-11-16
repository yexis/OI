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
// 公式:	g90[i][j] = g[h - 1 - j][i];
template<class T>
vector<vector<T>> to_90(vector<vector<T>>& g) {
    int h = g.size(), w = g[0].size();
    vector g90(w, vector<T>(h));
    for (int i = 0; i < w; i++) {
        for (int j = 0 ; j < h; j++) {
            g90[i][j] = g[h - 1 - j][i];
        }
    }
    return g90;
}

template<class T>
vector<vector<T>> to_180(vector<vector<T>>& g) {
    int h = g.size(), w = g[0].size();
    vector g180(h, vector<T>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0 ; j < w; j++) {
            g180[i][j] = g[h - 1 - i][w - 1 - j];
        }
    }
    return g180;
}

template<class T>
vector<vector<T>> to_270(vector<vector<T>>& g) {
    int h = g.size(), w = g[0].size();
    vector g270(w, vector<T>(h));
    for (int i = 0; i < h; i++) {
        for (int j = 0 ; j < w; j++) {
            g270[i][j] = g[j][w - 1 - i];
        }
    }
    return g270;
}

void solve() {
    int n;
    cin >> n;
    int mm = n * 2;
    vector g(mm, vector<char>(mm));
    for (int i = 0; i < mm; i++) {
        for (int j = 0; j < mm; j++) {
            cin >> g[i][j];
        }
    }
    auto call = [&](int x1, int y1, int x2, int y2, int start_i, int start_j, int end_i, int end_j) {
        int h = end_i - start_i;
        int w = end_j - start_j;
        if (x1 == start_i) {
            return end_j - y1 + x2 - start_i;
        } else if (x1 == end_i) {
            return y1 - start_j + h + w + x2 - start_i;
        } else if (y1 == end_j) {
            if (x1 <= x2) {
                return x2 - x1;
            } else {
                return end_i - x1 + w + h + w + x2 - start_i;
            }
        } else if (y1 == start_j) {
            return x1 - start_i + w + x2 - start_i;
        } else {
            return 0;
        }
    };

    auto cal1 = [&](vector<vector<char>>& g) {
        int ans = 0;
        int len = 2 * n - 1;
        for (int level = 1; level <= n; level++) {
            int start_i = level - 1, end_i = mm - level;
            int start_j = level - 1, end_j = mm - level;
            bool find = false;
            // 终点
            int ei = n - 1, ej = mm - level;
            // 起点
            int si, sj;
            for (int j = start_j; j <= end_j && !find; j++) {
                if (g[start_i][j] == 'X') {
                    if (j == end_j) {
                        if (g[start_i + 1][j] == 'O') {
                            find = true;
                            si = start_i, sj = j;
                        }
                    } else {
                        if (g[start_i][j + 1] == 'O') {
                            find = true;
                            si = start_i, sj = j;
                        }
                    }
                }
            }
            for (int j = end_j; j >= start_j && !find; j--) {
                if (g[end_i][j] == 'X') {
                    if (j == start_j) {
                        if (g[end_i - 1][j] == 'O') {
                            find = true;
                            si = end_i, sj = j;
                        }
                    } else {
                        if (g[end_i][j - 1] == 'O') {
                            find = true;
                            si = end_i, sj = j;
                        }
                    }    
                }
            }
            
            for (int i = start_i; i <= end_i && !find; i++) {
                if (g[i][end_j] == 'X') {
                    if (i == end_i) {
                        if (g[i][end_j - 1] == 'O') {
                            find = true;
                            si = i, sj = end_j;
                        }
                    } else {
                        if (g[i + 1][end_j] == 'O') {
                            find = true;
                            si = i, sj = end_j;
                        }
                    }
                }
            }
            for (int i = end_i; i >= start_i && !find; i--) {
                if (g[i][start_j] == 'X') {
                    if (i == start_i) {
                        if (g[i][start_j + 1] == 'O') {
                            find = true;
                            si = i, sj = start_j;
                        }
                    } else {
                        if (g[i - 1][start_j] == 'O') {
                            find = true;
                            si = i, sj = start_j;
                        }
                    }
                }
            }
            assert(find == true);
            ans += call(si, sj, ei, ej, start_i, start_j, end_i, end_j);
            len -= 2;
        }
        return ans;
    };

    auto g1 = to_90(g);
    auto g2 = to_180(g);
    auto g3 = to_270(g);
    cout << min({cal1(g), cal1(g1), cal1(g2), cal1(g3)}) << "\n";
}

int main() {
    solve();
    return 0;
}