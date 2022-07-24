#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 1e5+1, M = 10001;

ll n,x, w[1001], v[1001];
ll dp[1001][100001];
ll solve(ll i, ll sum)
{
    if(i == n)
        return 0;
    ll &ret = dp[i][sum];
    if(~ret) return ret;
    if(sum-w[i]>=0)
        ret = max(ret, solve(i+1, sum-w[i]) + v[i]);
    ret = max(ret, solve(i+1,sum));
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> n >> x;
    for(int i=0;i<n;i++)
        cin >> w[i]  >> v[i];
    cout << solve(0, x);
    return 0;
}
