#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define LL long long int
#define ULL unsigned LL

const int inf=1<<30;
const LL INF=1e18;
const int MOD=1e9+7;

int main()
{
	int n;
	scanf("%d", &n);
	int ar[n+5];
	LL tot=0;
	for(int i=0; i<n; i++)
	{
		scanf("%d", &ar[i]);
		tot+=(ar[i]);
	}

	LL cnt, sum, res;
	cnt=sum=res=0;

	for(int i=0; i<n-1; i++)
	{
		sum+=(ar[i]);

		if(sum == 2*tot/3) res+=cnt;
		if(sum == tot/3) cnt+=1;
	}

	printf("%lld\n", res);
	return 0;
}
