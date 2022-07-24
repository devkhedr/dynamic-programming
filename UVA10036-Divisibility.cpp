#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 1e9 + 7;
const int OO = LLONG_MAX;
const int N  = 10000, M = 1000;

int n, k;
int a[N], dp[N][100];
int solve(int i, int sum)
{
    if(i == n) return (sum%k==0?0: OO);
    int &ret = dp[i][sum];
    if(~ret)
        return ret;
    ret = solve(i+1, (sum-a[i]+k)%k);
    ret = min(ret, solve(i+1, (sum+a[i])%k));
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
        cin >> n >> k;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            a[i] += (10000*k); // to handle negatives
            a[i] %= k;
        }
        int x = solve(1,a[0]);    
        cout << (x == 0? "Divisible": "Not divisible") << '\n';
    }
    return 0;
}
