#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

//Beware 0 case (all code below deals with it)

vi k;
int n;

int bs(int e) {//binary search called from nlogn solution
	int l=0,u=e;
	while (l!=u) {
		int mid=(l+u)/2;
		if (mid==e || k[mid]>=e-mid) u=mid;
		else l=mid+1;
	}
	return e-l;
}


//check for elements less than 0 or greater than n
int nlogn(int n,const vi& k) {
	if (n==0) return 0;
	if (k[0]<0 || k.back()>n) return -1;
	if (k[0]==n) return n;
	int M=-1;
	int Mx,Mcx,My,Mcy;
	for (int z=0;z<=k[0];z++) {
		//rl=lower_bound(k.begin(),k.end(),z)-k.begin(); rl==0 always
		//ru=rl+z;ru==z always (except bounds check)
		//if (ru>n) break;

		Mcy=min(k[z],n-z);
		Mcx=min(k[z],int(upper_bound(k.begin()+z,k.end(),n-z)-k.begin())-z);

		//if (n==2 && k[0]==1 && k[1]==2) printf("bs(2): %d\n",bs(2));
//printf("bs(2): %d\n",bs(1));

		My=min(bs(n),n-z);
		Mx=min(bs(upper_bound(k.begin(),k.end(),n-z)-k.begin()),
				int(upper_bound(k.begin()+z,k.end(),n-z)-k.begin())-z);

		if (Mcy+Mx+z>=n) M=max(M,Mx);
		if (Mcx+My+z>=n) M=max(M,Mcx);
	}

	return M;
}

//This is the test generation code
//inc() is kind of like next permutation but for sorted lists of numbers with
//repeated values.
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        k.push_back(x);
    }
    sort(k.begin(), k.end());
    printf("%d\n", nlogn(n, k));
}
