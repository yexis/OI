//
// Created by liguoyang on 2023/5/8.
//
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <array>
using namespace std;
using ll = long long;
using lll = __int128;

/*
 * 树形DP
 */
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) {
        cin >> e;
    }
    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 0;
    auto dfs = [&](auto&& dfs, int u, int o) -> array<ll, 10> {
        array<ll, 10> cnt{};

        for (auto& v : g[u]) {
            if (v == o) continue;
            auto cnt_v = dfs(dfs, v, u);
            // 自己
            for (int i = 0; i <= 9; i++) {
                if (i + a[u] > 9) break;
                ans += cnt_v[i];
            }
            // 孩子与孩子
            for (int i = 0; i <= 9; i++) {
                for (int ii = 0; ii <= 9; ii++) {
                    if (i + ii + a[u] > 9) break;
                    ans += cnt[i] * cnt_v[ii];
                }
            }
            // 合并
            for (int i = 0; i <= 9; i++) {
                cnt[i] += cnt_v[i];
            }
        }
        array<ll, 10> res{};
        for (int i = 0; i <= 9; i++) {
            if (a[u] + i > 9) break;
            res[a[u] + i] += cnt[i];
        }
        res[a[u]] += 1;
        return res;
    };
    dfs(dfs, 0, -1);
    cout << ans << "\n";
}

int main() {
    solve();
}