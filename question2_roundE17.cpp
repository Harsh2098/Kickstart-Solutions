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

		long size, temp;
		map<long, long> sticks;

		cin>>size;
		for(int i=0 ; i<size ; ++i) {
			cin>>temp;
			if(sticks.count(temp) > 0)
				sticks[temp]++;
			else
				sticks[temp] = 1;
		}
		


		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
