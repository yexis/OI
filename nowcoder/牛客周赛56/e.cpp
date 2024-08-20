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
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int trans(string s) {
    int h = atoi(s.substr(0, 2).c_str());
    int m = atoi(s.substr(3, 2).c_str());
    return h * 60 + m;
}


int main() {
    int S = 0, E = 60 + 59;
    bool all = false;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ps;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        int start = trans(s.substr(0, 5));
        int end = trans(t.substr(0, 5));
        if (start == end) {
            start = 0, end = 23 * 60 + 59;
            all = true;
        }
        // 跨天
        if (end < start) {
            end = 23 * 60 + 59;
        }
        ps.emplace_back(start, end);
    }
    sort(ps.begin(), ps.end());


    // 去重
    int pn = 0;
    for(int i = 0; i < ps.size(); i++) {
        auto [L, R] = ps[i];
        int j = i + 1;
        while (j < n && ps[j].first <= R) {
            R = max(R, ps[j].second);
            j++;
        }
        ps[pn] = {L, R};
        pn++;
        i = j - 1;
    }
    ps.resize(pn);
//    cout << "pn:" << pn << "\n";
//    for (auto& [k, v] : ps) {
//        cout << k << " " << v << "\n";
//    }

    int happy[24 * 60 + 5];
    memset(happy, 0, sizeof(happy));
    for (auto& [s, t] : ps) {
        for (int i = s; i <= t; i++) {
            happy[i] = 1;
        }
    }

    // like
    unordered_set<string> like;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        like.insert(s);
    }


    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        int inv = trans(s);

        string t1, t2;
        cin >> t1 >> t2;
        int arr_s = trans(t1.substr(0, 5));
        int arr_c = trans(t2.substr(0, 5));

        string tea;
        cin >> tea;
        bool succ = false, left = false;
        if (happy[inv] && inv >= S && inv <= E) succ = true;
        if (arr_s > arr_c || !like.count(tea)) left = true;
        if (!succ) {
            cout << "Loser xqq" << "\n";
            continue;
        }
        if (left) {
            cout << "Joker xqq" << "\n";
            continue;
        }
        cout << "Winner xqq" << "\n";
    }


    return 0;
}