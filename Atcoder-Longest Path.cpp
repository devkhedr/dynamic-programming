#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 1e9 + 7;
const int OO = 1e18;
const int N  = 1e5+5, M = 1000;

int n,m , dp[N]; vector<int>adj[N]; bool vis[N];
int dfs(int u)
{
    if(dp[u] != -1)
        return dp[u];
    int longest_path_for_child = 0;
    for(int x: adj[u])
    {
        longest_path_for_child = max(longest_path_for_child, dfs(x));
    }
    return dp[u] = 1 + longest_path_for_child;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> n >> m;
    while(m--)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }
    int mx = 0;
    for(int i=1;i<=n;i++)
        mx = max(mx, dfs(i));
    cout << mx - 1;
    return 0;
}
