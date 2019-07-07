#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define INF 1000000000000007
#define MOD 1000000007
#define pb push_back
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

template<typename T>
void prn(T first) {
    cout << first << "\n";
}

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		long size, odd, maxxer;
		cin>>size>>odd>>maxxer;

		long arr[size], oc[size], ori[size], a, b, c, l, m;
		cin>>arr[0]>>arr[1]>>a>>b>>c>>m>>l;

		arr[0] += l;
		arr[1] += l;

		ori[0] =arr[0];
		ori[1] = arr[1];

		for(int i=2 ; i<size ; ++i) {
			arr[i] = ((a*(arr[i-1]-l)+b*(arr[i-2]-l)+c)%m)+l;
			ori[i] = arr[i];
		}

		// for(int i=0 ; i<size ; ++i) cout<<ori[i]<<" ";
		// cout<<endl;

		oc[0] = arr[0]%2==0?0:1;
		for(int i=1 ; i<size ; ++i) {
			oc[i] = (arr[i]%2!=0)?oc[i-1]+1:oc[i-1];
			arr[i] += arr[i-1];
		}

		// for(int i=0 ; i<size ; ++i) cout<<arr[i]<<" ";
		// cout<<endl;

		// for(int i=0 ; i<size ; ++i) cout<<oc[i]<<" ";
		// cout<<endl<<endl;

		answer = INT_MIN;
		for(int i=0 ; i<size ; ++i) {
			for(int j=i ; j<size ; ++j) {
				long sum = arr[j]-arr[i]+ori[i];
				long odds = oc[j]-oc[i]+(ori[i]%2!=0?1:0);

				//cout<<i<<" "<<j<<" sum="<<sum<<" odds="<<odds<<endl;
				if(sum <= maxxer && odds <= odd)
					answer = max(answer, sum);
			}
		}

		if(answer == INT_MIN) cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
		else cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
