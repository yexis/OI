#include <iostream>
#include <vector>
#include <string>
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
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

template<class KT, class VT = null_type>
using RBTree = tree<KT, VT, std::less<KT>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 1000;
struct Tree {
    struct Node {
        int left, right;
        int val;
    } seg[MAX * 400];
    int A[100000]{};
};

void solve() {
    Tree tr;
    for (int i = 0; i < 100000; i++) {
        cout << tr.seg[i].left << " " << tr.seg[i].right << " " << tr.seg[i].val << "\n";
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

// https://ac.nowcoder.com/acm/contest/