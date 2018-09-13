#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n,m,flag;
int c[100005];

long long quickpower(int x,long long mi)
{
	long long now=x;
	long long ans=1;
	while (mi)
	{
		if (mi&1) ans=ans*now%mod;
		mi=mi>>1;
		now=(now*now)%mod;
	}
	return ans;
}

void solve()
{
	flag=0;
	for (int i=1;i<=m;i++)
		if (c[i]>0) flag++;
	if (flag>0)
	{
		long long ans;
		ans=quickpower(2,n*m-m)%mod*(quickpower(2,n)%mod+mod-1)%mod;
		cout<<ans<<endl;
	}
	else
	{
		long long ans;
		ans=quickpower(2,n*m-m)%mod*(quickpower(2,n)%mod+mod-1)%mod;
		ans=(ans+quickpower(2,n*m))%mod;
		cout<<ans<<endl;
	}
}
int main()
{
	while (cin>>n>>m)
	{
		for (int i=1;i<=m;i++) cin>>c[i];
		solve();
	}
}
