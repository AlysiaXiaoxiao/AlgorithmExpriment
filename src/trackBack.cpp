#include <bits/stdc++.h>

using namespace std;

struct Node {
    int w, v;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Node> g(n);
    for(int i = 0; i < n; i ++) {
        cin >> g[i].w;
    }
    for(int i = 0; i < n; i ++) {
        cin >> g[i].v;
        g[i].id = i;
    }

    //按照单位质量的价值从达到小排序
    ranges::sort(g, [](const Node &a, const Node &b) {
        return 1.0 * a.v / a.w > 1.0 * b.v / b.w;
    });

    int curW = 0, curV = 0;
    auto bound = [&](int x) {
        int Wleft = m - curW;
        int upV = curV;

        //往左下角搜
        while(x < n && Wleft >= g[x].w) {
            upV += g[x].v;
            Wleft -= g[x].w;
            x ++;
        }

        if(x < n) {
            upV += g[x].v / g[x].w * Wleft;
        }

        return upV;
    };

    int maxV = 0;
    vector<bool> curState(n), bestState(n);
    auto backTrack = [&](auto self, int x) {
        if(x >= n) {
            maxV = curV;
            for(int i = 0; i < n; i ++) {
                bestState[i] = curState[i];
            }
            return;
        }

        if(curW + g[x].w <= m) {
            curState[g[x].id] = true;
            curW += g[x].w;
            curV += g[x].v;

            self(self, x + 1);

            curState[g[x].id] = false;
            curW -= g[x].w;
            curV -= g[x].v;
        }

        if(bound(x + 1) > maxV) {
            curState[g[x].id] = false;
            self(self, x + 1);
        }
    };

    cout << "回溯法解决01背包问题：\n\n";
    cout << "物品数量：" << n << "背包体积：" << m << "\n\n";
    for(int i = 0; i < n; i ++) {
        cout << "物品" << i << "的体积和价值为：" << g[i].w << ' ' << g[i].v << '\n';
    }
    cout << '\n';

    backTrack(backTrack, 0);

    cout << "背包能装下的最大物品价值为：" << maxV << '\n';

    cout << "解向量为：";
    for(auto c : bestState) cout << c << ' ';
    cout << '\n';

    return 0;
}