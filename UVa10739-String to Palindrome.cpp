#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));

const int mod = 1e9 + 7;
const int OO = 0x3F3F3F3F;
const int N  = 100, M = 1000;

string s;

int dp[1000][1000];
int solve(int i, int j)
{
    if(i>=j) return 0;
    int &ret = dp[i][j];
    if(~ret)
        return ret;
    if(s[i]==s[j])
        ret = solve(i+1,j-1);
    else
    {
        ret = min(solve(i+1, j) + 1, solve(i,j-1)+1);
        ret = min(ret, solve(i+1,j-1)+1); 
    }
    return ret;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, rc=0;
    cin >> t;
    while(t--)
    {
        cin >> s;
        clr(dp, -1);
        cout << "Case " << ++rc << ": " << solve(0,s.length()-1) << '\n';
    }
    return 0;
}
