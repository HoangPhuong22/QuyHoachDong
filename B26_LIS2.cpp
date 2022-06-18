#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n ; cin >> n;
    int a[n];
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    vector<int>v(1 , 1e9 + 1);
    for(int i = 0 ; i < n ; i++)
    {
        auto l = lower_bound(v.begin() , v.end() , a[i]);
        if(l != v.end())
        {
            *l = a[i];
        }
        else v.push_back(a[i]);
    }
    cout << v.size();
}
