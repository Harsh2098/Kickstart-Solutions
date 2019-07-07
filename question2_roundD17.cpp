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

		long n,k,a1,b1,c,d,e1,e2,f;
		cin>>n;
		long a[n], b[n], r[n], s[n], x[n], y[n];

		cin>>k>>a[0]>>b[0]>>c>>d>>e1>>e2>>f;
		
		x[0] = a[0];
		y[0] = b[0];
		r[0] = s[0] = 0;

		for(int i=1; i<n ; ++i) {
			x[i] = (c*x[i-1]+d*y[i-1]+e1)%f;
			y[i] = (d*x[i-1]+c*y[i-1]+e2)%f;

			r[i] = (c*r[i-1]+d*s[i-1]+e1)%2;
			s[i] = (d*r[i-1]+c*s[i-1]+e2)%2;

			a[i] = pow(-1,r[i])*x[i];
			b[i] = pow(-1,s[i])*y[i];
		}

		long summ[n][n];
		vector<long> arr;

		summ[0][0] = a[0]*b[0];
		for(int i=1 ; i<n ; ++i) {
			summ[0][i] = a[0]*b[i] + summ[0][i-1];
			summ[i][0] = a[i]*b[0] + summ[i-1][0];
		}

		for(int i=1 ; i<n ; ++i) {
			for(int j=1 ; j<n ; ++j) {
				summ[i][j] = a[i]*b[j] + summ[i-1][j] + summ[i][j-1] - summ[i-1][j-1];
			}
		}

		for(int i=0 ; i<n ; ++i) {
			for(int j=0 ; j<n ; ++j) {
				for(int k=0 ; k<=i ; ++k) {
					for(int l=0 ; l<=j ; ++l) {
						long temp = summ[i][j];
						if(k>0) temp -= summ[k-1][j];	
						if(l>0) temp -= summ[i][l-1];
						if(k>0&&l>0) temp += summ[k-1][j-1];
						arr.push_back(temp);
					}
				}
			}
		}

		sort(arr.begin(), arr.end(), greater<int>());

		// for(int i=0 ; i<n ; ++i) {
		// 	for(int j=0 ; j<n ; ++j) {
		// 		cout<<summ[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		// cout<<endl;

		// for(int i=0 ; i<arr.size() ; ++i) {
		// 	cout<<arr[i]<<" ";
		// }

		// cout<<endl;

		cout<<"Case #"<<i<<": "<<arr[k-1]<<endl;
	}
	return 0;
}
