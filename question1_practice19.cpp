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

		long a,b,n,guess;
		string res;
		cin>>a>>b>>n;
		a++;

		while(a<=b) {
			guess = (a+b)/2;
			cout<<guess<<endl;
			cin>>res;
			if(res=="TOO_BIG") {
				b=guess-1;
			} else if(res=="TOO_SMALL") {
				a=guess+1;
			} else {
				break;
			}
		}
	}
	return 0;
}
