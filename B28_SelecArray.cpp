#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[100001][100];
const int MOD = 1e9 + 7;
int main()
{
    int n , m ; cin >> n >> m;
    int a[n + 1];
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    
    if(a[0] != 0)
    {
        v[0][a[0]] = 1;
    }
    else
    {
        for(int i = 1 ; i <= m ; i++)
        {
            v[0][i] = 1;
        }
    }
    for(int i = 1 ; i < n ; i++)
    {
        if(a[i] == 0)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                for(int k = -1 ; k <= 1 ; k++)
                {
                    int ans = j + k;
                    if(ans >= 1 && ans <= m)
                    {
                        v[i][j] += v[i - 1][ans];
                         v[i][j] %= MOD;
                    }
                }
            }
        }
        else
        {
            for(int k = -1 ; k <= 1 ; k++)
            {
                int ans = a[i] + k;
                if(ans >= 1 && ans <= m)
                {
                    v[i][a[i]] += v[i - 1][ans];
                    v[i][a[i]] %= MOD;
                }
            }
        }
    }
    ll sum = 0;
    for(int i = 1 ; i <= m ; i++)
    {
        sum += v[n - 1][i];
        sum %= MOD;
    }
    cout << sum;
}
