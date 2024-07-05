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

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ull = unsigned long long;

int que[100010];
ull hq[100010];

// 字符串哈希
const int maxn = 10000;
const int P = 131;
ull p[100010];
// 将h定义成ull，当溢出后 等价于 自动取模
ull h[100010];
void init_p() {
    p[0] = 1;
    for (int i = 1; i < maxn; i++) {
        p[i] = p[i - 1] * P;
    }
}
void init(const string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        h[i + 1] = h[i] * P + s[i];
    }
}
ull get(int l, int r) {
    return h[r]  - h[l - 1] * p[r - l + 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    init_p();
    string s;
    cin >> s;
    vector<int> b;
    string t;
    for (int i = 1; i <= q; i++) {
        cin >> t >> que[i];
        init(t);
        // t的hash值
        hq[i] = get(1, t.size());
        // find(g, hq[i] * p[que[i]]) = i;
    }
    return 0;
}