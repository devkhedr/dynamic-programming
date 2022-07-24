#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+4;

int n, dp[N], F[N], mx;
int solve(int i)
{
    if(i > mx)
        return 0;
    int &ret = dp[i];
    if(~ret) return ret;
    ret = solve(i+1);
    ret = max(ret, solve(i+2) + i*F[i]);
    return ret;
}

int32_t main()
{       
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        mx = max(mx, x), F[x]++;
    }
    cout << solve(1);
    return 0;
}
