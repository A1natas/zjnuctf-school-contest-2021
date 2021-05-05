#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int n, m, k, L;
vector<P> G[850];
int dis[850][850];
int u[850], v[850], w[850];
int a[2050], b[2050];

void dijkstra(int st)
{
    priority_queue<P> pq;
    for (int i = 1; i <= n; i++)
        dis[st][i] = 1e9;
    dis[st][st] = 0;
    pq.push(P(0, st));
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        for (P pd : G[v])
            if (dis[st][v] + pd.second < dis[st][pd.first])
            {
                dis[st][pd.first] = dis[st][v] + pd.second;
                pq.push(P(-dis[st][pd.first], pd.first));
            }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &L);

    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        G[u[i]].push_back(P(v[i], w[i]));
        G[v[i]].push_back(P(u[i], w[i]));
    }

    for (int i = 1; i <= k; i++)
        scanf("%d%d", &a[i], &b[i]);

    for (int i = 1; i <= n; i++)
        dijkstra(i);

    int ans = 2e9;
    for (int i = 1; i <= m; i++)
    {
        int sum = 0;
        for (int j = 1; j <= k; j++)
            sum += min({dis[a[j]][b[j]],
                        dis[a[j]][u[i]] + dis[v[i]][b[j]] + max(dis[u[i]][v[i]] - L, 0),
                        dis[a[j]][v[i]] + dis[u[i]][b[j]] + max(dis[u[i]][v[i]] - L, 0)});
        ans = min(ans, sum);
    }
    printf("%d\n", ans);

    return 0;
}