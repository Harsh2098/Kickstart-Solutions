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

	long tests, total = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		long n, total = 0;
		string answer, chef;
		cin>>n>>answer>>chef;

		for(int i=0 ; i<answer.length() ; ++i) {
			if(chef[i] == 'N') continue;
			if(answer[i] != chef[i]) i++;
			else total++;
		}

		cout<<total<<endl;
	}
	return 0;
}
