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

		answer = 0;
		long n, temp;
		string inner;
		cin>>n>>inner;
		long arr[n];
		
		for(int i=0 ; i<n ; ++i) arr[i] = inner[i]-48;
		long size = (n%2==0)?n/2:n/2+1;

		for(int i=0 ; i<size ; ++i) answer += arr[i];
			
		temp = answer;
		for(int i=size ; i<n ; ++i) {
			temp = temp - arr[i-size] + arr[i];
			answer = max(temp,answer);
		}
		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
