#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // cout << "物品个数和背包体积：";
    int n, m;
    cin >> n >> m;
    // cout << "\n";

    // cout << "各个物品的体积和价值：\n";
    vector<int> w(n), v(n), dp(m + 1); //w代表体积, v代表价值，dp[i]表式容量为i的背包能够装入的最大价值
    // cout << "重量：\n";
    for(int i = 0; i < n; i++ ) {
        // cout << "物品" << i + 1 << ": ";
        cin >> w[i];
    }
    // cout << "\n";

    // cout << "体积：\n";
    for(int i = 0; i < n; i ++) {
        // cout << "物品" << i + 1 << ": ";
        cin >> v[i];
    }
    // cout << "\n";

    //状态转移
    for(int i = 0; i < n; i ++) {
        for(int j = m; j >= w[i]; j --) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    //求解向量
    vector<bool> is_selected(n);
    int V = m;
    for(int i = n - 1; i >= 0; i --) {
        if(dp[V] == dp[V - w[i]] + v[i]) {
            is_selected[i] = true;
            V -= w[i];
        } else if(dp[V] == dp[V - w[i]]) {
            is_selected[i] = false;
        }
    }

    cout << "动态规划解决01背包问题：\n\n";
    cout << "物品个数：" << n << "  背包体积：" << m << "\n\n";
    for(int i = 0; i < n; i ++) {
        cout << "物品" << i + 1 << "体积价值: ";
        cout << w[i] << " " << v[i];
        cout << "\n";
    }
    cout << '\n';

    cout << "最大价值为：" << dp[m] << '\n';

    cout << "解向量为：";
    for(auto c : is_selected) {
        cout << c << ' ';
    }
    cout << '\n';

    return 0;
}