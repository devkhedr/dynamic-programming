#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9+7;

int n,k,d;
int dp[101][2];

int solve(int n, int takeD)
{
    if(n < 0)
        return 0;
    if(n == 0)
        return takeD;
    int &ret = dp[n][takeD];
    if(~ret)
        return ret;
    ret = 0;
    for(int i=1;i<=k;i++)
    {
        if(i >= d) takeD = 1;
        ret += solve(n-i, takeD), ret %= mod; 
    }
    return ret;
}
int32_t main()
{       
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;    
    cout << solve(n, 0);
    return 0;
}
