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

void solve() {
    string t; cin >> t;
    string u; cin >> u;

    vector<int> ask;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '?') ask.push_back(i);
    }
    
    auto cal = [&](string& s, string& p) -> bool {
        int pn = p.size();
        for (int i = 0; i < s.size(); i++) {
            if (i + pn - 1 >= s.size()) {
                break;
            }
            if (s.substr(i, pn) == p) {
                return true;
            }
        }
        return false;
    };

    for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
        t[ask[0]] = ch1;
        for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
            t[ask[1]] = ch2;
            for (char ch3 = 'a'; ch3 <= 'z'; ch3++) {
                t[ask[2]] = ch3;
                for (char ch4 = 'a'; ch4 <= 'z'; ch4++) {
                    t[ask[3]] = ch4;
                    if (cal(t, u)) {
                        cout << "Yes" << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "No" << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









