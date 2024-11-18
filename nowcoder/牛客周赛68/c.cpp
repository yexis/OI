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
 * 分情况讨论
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    set<int> cnt1, cnt2;
    for (auto& e : a) cnt1.insert(e);
    for (auto& e : b) cnt2.insert(e);
    int del1 = n - cnt1.size();
    int del2 = n - cnt2.size();
    int ans = max(del1, del2);
    if (cnt1.size() == cnt2.size()) {
        int c = 0;
        for (auto& e : cnt1) {
            if (cnt2.count(e)) {
                c++;
            }
        }
        ans += (c + 1) / 2;
    } else if (cnt1.size() > cnt2.size()) {
        int need = cnt1.size() - cnt2.size();
        for (auto it = cnt1.begin(); it != cnt1.end() && need > 0; ) {
            auto e = *it;
            if (cnt2.count(e)) {
                it = cnt1.erase(it);
                need--;
            } else {
                it++;
            }
        }
        while (need > 0) {
            cnt1.erase(cnt1.begin());
            need--;
        }
        int c = 0;
        for (auto& e : cnt1) {
            if (cnt2.count(e)) {
                c++;
            }
        }
        ans += (c + 1) / 2;
    } else {
        int need = cnt2.size() - cnt1.size();
        for (auto it = cnt2.begin(); it != cnt2.end() && need > 0; ) {
            auto e = *it;
            if (cnt1.count(e)) {
                it = cnt2.erase(it);
                need--;
            } else {
                it++;
            }
        }
        while (need > 0) {
            cnt2.erase(cnt2.begin());
            need--;
        }

        int c = 0;
        for (auto& e : cnt1) {
            if (cnt2.count(e)) {
                c++;
            }
        }
        ans += (c + 1) / 2;
    }
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}