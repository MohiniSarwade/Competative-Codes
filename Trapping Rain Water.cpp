#include <iostream>
using namespace std;
int trappedWater(int a[], int n)
{
    int maxl[n],maxR[n];
    maxl[0]=a[0];
    maxR[n-1]=a[n-1];
    for(int i=1;i<n;i++)
        maxl[i]=max(a[i],maxl[i-1]);
    for(int i=n-2;i>=0;i--)
        maxR[i]=max(a[i],maxR[i+1]);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=min(maxl[i],maxR[i])-a[i];
    }
    return sum;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<trappedWater(a,n)<<endl;
	}
	return 0;
}
