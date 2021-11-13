#include <bits/stdc++.h>
using namespace std;
int to_check(int arr[], int n, int mx)
{
    for(int x=0; x <= mx; x++)
    {
        int xr = 0;
        for(int i=0; i < n; i++)
        {
            xr = (xr ^ (x + arr[i]));
        }
        if(xr == 0) return x;
    }
    return -1;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	    int v[n]; int mx = 0;
	    for(int i=0; i < n; i++)
	    {
	        scanf("%d", &v[i]);
	        mx = max(mx, v[i]);
	    }
	    int ans = to_check(v, n, mx);
	    printf("%d\n", ans);
	}
	return 0;
}