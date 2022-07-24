#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 1e9 + 7;
const int OO = LLONG_MAX;
const int N  = 10000, M = 1000;

int n,all;
int dp[102][50004], a[N];
int solve(int i, int s2)
{
    if(i == n) return abs(s2-abs(all-s2));
    int &ret = dp[i][s2];
    if(~ret) return ret;
    ret = min(solve(i+1,s2), solve(i+1,s2+a[i]));
    return ret; 
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        clr(dp, -1);
        all = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            all += a[i];
        }
        cout << solve(0,0) << '\n'; 
    }
    return 0;
}
