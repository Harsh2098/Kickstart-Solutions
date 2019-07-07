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

	long n,target,p;
	cin>>n>>p>>target;
	target %= p; 
	long arr[n];
	for(int i=0 ; i<n ; ++i) cin>>arr[i];

	long answer = 0;
	for(int i=0 ; i<n ; ++i) {
		for(int j=i ; j<n ; ++j) {
			if(pow(arr[i],3)+pow(arr[j],3)+(arr[i]+arr[j])*arr[i]*arr[j]%p == target) answer++;
		}	
	}

	cout<<answer;

	return 0;
}
