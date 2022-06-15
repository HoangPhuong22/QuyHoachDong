#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s1 , s2 ; cin >> s1 >> s2;
    int n = s1.length() , m = s2.length();
    int dp[n + 1][m + 1];
    for(int i =0 ; i <= n ; i++)
    {
        for(int j = 0 ;j <= m ; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = i + j;
            }
            else if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] , min(dp[i - 1][j] , dp[i][j - 1])) + 1;
            }
        }
    }
    cout << dp[n][m];
}
