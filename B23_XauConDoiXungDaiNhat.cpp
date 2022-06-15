#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dp[1001][1001];
int main()
{
    string s ; cin >> s;
    s = "1" + s;
    int res = 1;
    int n = s.length();
    for(int i =1 ; i <= n ; i++)
    {
        dp[i][i] = true;
    }
    for(int k = 2 ; k <= n ; k++)
    {
        for(int i = 1 ; i <= n - k + 1 ; i++)
        {
            int j = i + k - 1;
            if(k == 2 && s[i] == s[j]) dp[i][j] = true;
            else dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            
            if(dp[i][j]) res = max(res , j - i + 1);
        }
    }
    cout << res;
}
