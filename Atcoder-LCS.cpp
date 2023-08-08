#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define clr(v,val) memset(v,val,sizeof(v));
 
const int mod = 1e9 + 7;
const int OO = 1e17;
const int N  = 100001, M = 1000;
 
string s, t;
int dp[3005][3005];
int solve(int i, int j)
{
    if (i == s.size() || j == t.size())
        return 0;
    if (dp[i][j] != -1)return dp[i][j];
 
    int p1 = 0, p2 = 0, p3 = 0;
    if (s[i] == t[j])
        p1 = solve(i + 1, j + 1) + 1;
    p2 = solve(i + 1, j);
    p3 = solve(i, j + 1);
 
    return dp[i][j] = max(p1, max(p2, p3));
}
string build(int i, int j)
{
    if (i == s.size() || j == t.size())
        return "";
    if (s[i] == t[j])
        return s[i] + build(i + 1, j + 1);
    if (solve(i + 1,j) > solve(i,j + 1)) 
        return build(i + 1, j);
    return build(i, j + 1);
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    clr(dp, -1);
    int x = solve(0, 0);
    cout << build(0, 0);
    return 0;
}
