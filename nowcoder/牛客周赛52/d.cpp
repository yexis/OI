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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const ll M = 1e9;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = to_string(a[i]);
    }

    priority_queue<tuple<int, string, int> > pq;
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        pq.emplace(s[i][0], s[i].substr(1), i);
    }

    string t;
    while (pq.size()) {
        auto [c, next, i] = pq.top();
        pq.pop();
        t += c;
        ++idx[i];
        if (next.size() == 0) {
            continue;
        }
        if (idx[i] < s[i].size()) {
            pq.emplace(s[i][idx[i]], next.substr(1), i);
        }
    }
    cout << t << "\n";
    return 0;
}