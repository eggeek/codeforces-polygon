#include<iostream>
using namespace std;
int main(){
int n,i=0;long long s=0,x,s1=0,s2=0;
cin>>n;int a[n];
while(i<n){cin>>a[i];s+=a[i];i++;}
if(s%3!=0){cout<<"0"<<endl;return 0;}
else{
i=0;x=s/3;s=0;
while(i<n){s+=a[i];if(s==x)s1++;if(s==(2*x))s2++;i++;}
if(x==0){if(s1>=3){cout<<((s1-2)*(s1-1))/2<<endl;}else cout<<"0"<<endl;return 0;}

cout<<s1*s2<<endl;
}

return 0;
}
