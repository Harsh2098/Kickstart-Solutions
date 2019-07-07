#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define INF 1000000000000007
#define MOD 1000000007
#define pb push_back
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main() {

	long tests, n, p, temp;
	
	sync

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		vector<long> skills;
		long cost = 0, answer = 0;

		cin>>n>>p;

		for (int i = 0; i < n; ++i) {
			cin>>temp;
			skills.push_back(temp);
		}

		sort(skills.begin(), skills.end());

		for(int i=0 ; i<p-1 ; ++i) 
			answer += (skills[p-1] - skills[i]);
		
		cost = answer;

		for(int i=p ; i<n ; ++i) {
			cost = cost - (skills[i-1]-skills[i-p]) + (p-1)*(skills[i]-skills[i-1]);
			if(cost < answer)
				answer = cost;
		}

		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
