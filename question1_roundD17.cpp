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

class bus {
	public:
	long start, freq, duration;
	bus(long s, long f, long d) {
		start = s;
		duration = d;
		freq = f;
	}
};

long n=0, sight = 0, total = 0;
vector<bus> arr;

long getNext(long c, long s, long f) {
	long answer = s;
	while(answer<c) answer +=f;
	return answer;
}

long getMaxCity(long currentTime, long city, long numCity) {
	if(currentTime > total && city != n-1) return 0;
	if(currentTime <=total && city == n-1) return numCity;

	long nextBus = getNext(currentTime + sight, arr[city].start, arr[city].freq);
	long routeVisit = getMaxCity(nextBus + arr[city].duration, city+1, numCity+1);


	nextBus = getNext(currentTime, arr[city].start, arr[city].freq);
	long routeNotVisit = getMaxCity(nextBus + arr[city].duration, city+1, numCity);

	return max(routeVisit, routeNotVisit);
}

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		long t1, t2, t3;
		arr.clear();

		cin>>n>>sight>>total;

		for(int i=0 ; i<n-1 ; ++i) {
			cin>>t1>>t2>>t3;
			arr.push_back(bus(t1,t2,t3));
		}

		long answer = getMaxCity(0, 0, 0);

		if(answer == -1)
			cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
		else
			cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
