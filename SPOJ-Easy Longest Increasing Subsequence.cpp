#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N  = 1e5+1, M = 10001;

int n;
int dp[10][21], a[10];
int solve(int i, int prev)
{
    if(i == n)return 0;
    int &ret = dp[i][prev];
    if(~ret)
        return ret;
    ret = solve(i+1, prev);
    if(a[i] > prev)
        ret = max(ret, 1 + solve(i+1, a[i]));
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    clr(dp, -1);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << solve(0,0);
    return 0;
}
