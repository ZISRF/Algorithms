#include <fstream>
#include <vector>
 
using namespace std;
 
const long long INF = 1e18;
 
int main()
{
    ifstream cin("pathmgep.in");
    ofstream cout("pathmgep.out");
 
    int n, s, f;
    cin >> n >> s >> f;
    --s;
    --f;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
 
    vector<long long> dist(n, INF);
    vector<bool> used(n);
    dist[s] = 0;
    int u = s;
    while (u != -1)
    {
        used[u] = true;
 
        for (int v = 0; v < n; ++v)
            if (g[u][v] != -1 && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
         
        u = -1;
        for (int v = 0; v < n; ++v)
            if (!used[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
    }
 
    if (dist[f] != INF)
        cout << dist[f] << endl;
    else
        cout << -1 << endl;
 
    return 0;
}