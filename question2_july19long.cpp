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

		ull n,k;
		cin>>n>>k;

		ull temp = k%n;
		if(temp > n/2) temp = n - temp;
		if(temp == n/2) temp = temp*2-1;
		else temp*=2;
		cout<<temp<<endl;
	}

	return 0;
}
