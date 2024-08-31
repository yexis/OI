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

/*
 * 
*/

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

void solve() {

}

int main() {
    int n, k, b;
    cin >> n >> k >> b;
    vector<pair<int, int>> po;
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        cin >> x >> y;
        po.emplace_back(x, y);
    }

    vector<int> pos, neg, on;
    for (int i = 0; i < po.size(); i++) {
        auto [x, y] = po[i];
        int z = y - k * x;
        if (z < b) {
            neg.push_back(i + 1);
        } else if (z > b) {
            pos.push_back(i + 1);
        } else {
            on.push_back(i + 1);
        }
    }

    // pn <= nn
    int pn = pos.size(), nn = neg.size(), no = on.size();
    if (pn > nn) {
        swap(neg, pos);
        swap(pn, nn);
    }

    vector<pair<int, int>> pr, npr;
    for (int i = 0; i < pn; i++) {
        pr.emplace_back(pos[i], neg[i]);
    }
    int j = pn, oj = 0;
    for (j = pn; j < nn && oj < no; j++) {
        pr.emplace_back(neg[j], on[oj]);
        oj++;
    }
    for (; oj < no; oj += 2) {
        pr.emplace_back(on[oj], on[oj + 1]);
    }
    for (; j < nn; j += 2) {
        npr.emplace_back(neg[j], neg[j + 1]);
    }
    cout << pr.size() << "\n";
    for (auto [x, y] : pr) {
        if (x > y) swap(x, y);
        cout << x << " " << y << " " << "Y" << "\n";
    }
    for (auto& [x, y] : npr) {
        if (x > y) swap(x, y);
        cout << x << " " << y << " " << "N" << "\n";
    }

    return 0;
}