#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int m , n ; cin >> m >> n;
    int a[n];
    for(int i = 0 ; i < n ;i++) 
    {
        cin >> a[i];
    }
    bool dp[m + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = m ; j >= a[i] ; j--)
        {
            if(dp[j - a[i]])
            {
                dp[j] = true;
            }
        }
    }
    for(int i = m ; i >= 1 ; i--)
    {
        if(dp[i])
        {
            cout << i ;
            return 0;
        }
    }
}
