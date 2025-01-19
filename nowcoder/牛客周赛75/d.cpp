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

void solve() {
    string s;
    cin >> s;

    int v[100];
    memset(v, -1, sizeof(v));
    int lst = 99;
    for (int i = 98; i >= 0; i--) {
        v[i] = lst;
        if (i % 10 == i / 10) {
            lst = i;
        }
    }

    int n = s.size();
    if (n & 1) {
        n++;
        string ans;
        for (int i = 1; i <= n / 2; i++) {
            if (i & 1) {
                ans += '1';
                ans += '1';
            } else {
                ans += '0';
                ans += '0';
            }
        }
        cout << ans << "\n";
    } else {
        // 偶数
        bool is = false;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) {
                is = false;
                break;
            }
            if (i - 1 >= 0 && s[i - 1] == s[i]) {
                is = false;
                break;
            }
        }
        if (is) {
            cout << s << "\n";
            return;
        }

        
        // 自身不是
        vector<int> vv;
        string ans;
        for (int i = 0; i < n; i += 2) {
            if (s[i] == s[i + 1] && 
                    (i - 1 < 0 || s[i - 1] != s[i])) {
                string t;
                t += s[i];
                t += s[i + 1];
                vv.push_back(stoi(t));
                continue;
            }
            string t = s.substr(i, 2);
            vv.push_back(stoi(t));
            while (v[vv.back()] == -1) {
                vv.pop_back();
            }
            if (vv.size() == 0) {
                // 进位
                n += 2;
                for (int i = 1; i <= n / 2; i++) {
                    if (i & 1) {
                        ans += '1';
                        ans += '1';
                    } else {
                        ans += '0';
                        ans += '0';
                    }
                }
                cout << ans << "\n";
            } else {
                // 不进位
                int nxt = v[vv.back()];
                vv.push_back(nxt);
                int c = 1;
                while (vv.size() < n / 2) {
                    if (c & 1) {
                        vv.push_back(0);
                    } else {
                        vv.push_back(11);
                    }
                }
            }

            for (auto& e : vv) {
                if (e == 0) {
                    ans += "00";
                } else {
                    ans += to_string(e);
                }
            }
            cout << ans << "\n";
            break;
        }
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    solve();
    return 0;
}