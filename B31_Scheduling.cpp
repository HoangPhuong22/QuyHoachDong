#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define ms(a,n) memset(a , n , sizeof(a))
#define FOR(i,a,b) for(int i = a ; i <= b ;i++)
#define RFOR(i,a,b) for(int i = b ; i >= a ; i--)
#define factphuongdz() ios::sync_with_stdio(NULL);cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll>pl;
typedef vector<ll>vll;
typedef vector<int>vii;
typedef pair<int,int>pi;
const int MOD = 1e9 + 7;

struct Fly
{
    int f , s , w;
};

int flyCamp(Fly a[] , int n)
{
    int l = 0 , r = n - 1 , res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m].s < a[n].f)
        {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(NULL);cout.tie(NULL);
    int n ; cin >> n;
    Fly a[n];
    for(int i = 0 ;i < n ;i++)
    {
        cin >> a[i].f >> a[i].s >> a[i].w;
    }
    sort(a , a + n , [](Fly a , Fly b)->bool
    {
        return a.s < b.s;    
    });
    ll ans[n];
    ans[0] = a[0].w;
    for(int i = 1 ; i < n ; i++)
    {
        ll res = a[i].w;
        int l = flyCamp(a , i);
        if(l != -1)
        {
            res += ans[l];
        }
        ans[i] = max(res , ans[i - 1]);
    }
    ll kq = ans[n - 1];
    cout << kq;
    return 0;
}
