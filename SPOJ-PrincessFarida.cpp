#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 1e9 + 7;
const int OO = 0x3F3F3F3F;
const int N  = 1e4+3, M = 10001;

int n;
int a[N], dp[N];
int solve(int i)
{
    if(i >= n) return 0;
    int &ret = dp[i];
    if(~ret)
        return ret;
    ret = max(solve(i+1), a[i]+solve(i+2));
    return ret;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];

        clr(dp, -1);
        cout << "Case "<<++tc<<": " << solve(0) << '\n';
    }
    return 0;
}
