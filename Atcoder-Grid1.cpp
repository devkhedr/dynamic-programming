#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N = 1005, M = 301;
 
int n,m;
vector<vector<char>>grid;
ll dp[N][N];
bool valid(int i, int j)
{
    return i>=0&&j>=0&&i<n&&j<m&&grid[i][j]=='.'; 
}
ll solve(ll i, ll j)
{
    if(!valid(i,j))return 0;
    if(i == n-1&&j==m-1)
        return 1;
    ll &ret = dp[i][j]; 
    if(~ret)
        return dp[i][j];
    ret = 0;
    ret += solve(i+1,j);
    ret%=mod;
    ret += solve(i,j+1);
    return ret%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> n >> m;
    grid = vector<vector<char>> (n, vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];
    cout << solve(0,0);
    return 0;
}
Footer
© 2022 GitHub, Inc.
