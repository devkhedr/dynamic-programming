#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 1e9 + 7;
const int OO = 0x3F3F3F3F;
const int N  = 100, M = 1000;

int n;
int w[100], c[100], dp[100][100001];
int solve(int i, int val)
{
    if(i == n) return (val == 0 ? 0: OO);
    int &ret = dp[i][val];
    if(~ret) return ret;
    ret = solve(i+1, val);
    if(val-c[i] >= 0)
        ret = min(ret, solve(i+1, val-c[i])+w[i]);
    return ret;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int W;
    cin >> n >> W;
    for(int i=0;i<n;i++)
        cin >> w[i] >> c[i];
    clr(dp, -1);
    int mx = 0;
    for(int i=0;i<=100000;i++)
    {
        if(solve(0, i)<=W)
            mx = i;
    }
    cout << mx;
    return 0;
}
