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

	long tests;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		string arr;
		cin>>arr;
		long cb = 0, cd = 0;
		for(int i=1 ; i<arr.length() ; ++i) {
			if(arr[i] == '.') cd++;
			if(arr[i] == 'B') cb++;
		}

		char answer = 'N';
		if(cd > 0 && cb >= cd) answer = 'Y';
		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
