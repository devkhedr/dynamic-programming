#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 998244353;
const int OO = 1e12;
const int N  = 1000, M = 1000;

int add(int a, int b)
{
    return (a%mod) + (b%mod) % mod;
}
int n;
int a[101], dp[101][101][101];
int solve(int i, int sum, int rem, int& m)
{
    if(rem < 0)return 0;
    if(i == n) return (sum== 0&&rem == 0);
    int &ret = dp[i][sum][rem];
    if(~ret)
        return ret;
    ret = 0;
    ret = add(ret, solve(i+1,sum, rem, m));
    ret = add(ret, solve(i+1, (sum+a[i])%m, rem-1, m));
    return ret;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        clr(dp, -1);
        ans = add(ans, solve(0, 0, i, i));
    }
    cout << ans;
    return 0;
}
