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

class person {
	public:
	int f,h,s;
	person(int f1, int h1, int s1) {
		f = f1;
		h = h1;
		s = s1;
	}
};

int findNextSlush(int slush[], int m) {
	for(int i=0 ; i<m ; ++i) {
		if(slush[i] > 0) {
			slush[i]--;
			return i+1;
		}
	}
	return -1;
}

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		int n,m, temp1, temp2, temp3;
		cin>>n>>m;

		int slush[m];
		vector<person> people;
		int answer[n];
		int drink[n];

		for(int i=0 ; i<m ; ++i) {
			cin>>slush[i];
		}

		for(int i=0 ; i<n ; ++i) {
			cin>>temp1>>temp2>>temp3;
			people.push_back(person(temp1, temp2, temp3));
		}

		for(int i=0 ; i<n ; ++i) {
			if(slush[people[i].f-1] > 0) {
				answer[i] = people[i].h;
				drink[i] = people[i].f;
				slush[people[i].f-1]--;
			} else {
				answer[i] = -1;
			}
		}

		long sum = 0;
		for(int i=0 ; i<n ; ++i) {
			if(answer[i] == -1) {
				answer[i] = people[i].s;
				drink[i] = findNextSlush(slush, m);
			}
			sum += answer[i];
		}

		cout<<sum<<endl;
		for(int i=0 ; i<n ; ++i) {
			cout<<drink[i]<<" ";
		}

	}
	return 0;
}
