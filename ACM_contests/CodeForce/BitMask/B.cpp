#include <iostream>
#include <cmath>

using namespace std;

int main()
{

int t;
int c=0;
cin>>t;

long long output = 0;

int ks = 0;
int kf = 0;
long long ans=pow(10,13);

for (int n=2; n<12; n+=2)
{
	for (long long x = 0; x < (1<<n); x++)
	{
		for (int i = 0; i < n; ++i)
		{
			c = (x&(1ll<<i));
			if (c>0)
			{
				output=output*10+7;
				ks++;

			}
			else
			{
				output=output*10+4;
				kf++;

			}
		}

		if (ks == kf && output>=t)
		{
			ans=min(ans,output);

		}
		output=0;
		ks=0;
		kf=0;

	}

}

    cout<<ans;
}
