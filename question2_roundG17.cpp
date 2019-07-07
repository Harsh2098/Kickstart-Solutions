#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define INF -1
#define MOD 1000000007
#define pb push_back
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

template<typename T>
void prn(T first) {
    cout << first << "\n";
}

class edge {
	public:
		long weight, red, blue;
		edge(long w, long r, long b) {
			weight = w;
			red = r;
			blue = b;
		}
		bool operator < (const edge& e) const {
        	return (weight < e.weight);
    	}
};

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(long i=1 ; i<=tests ; ++i) {

		long n;
		cin>>n;
		long red[n], blue[n];
		for(long i=0 ; i<n ; ++i) cin>>red[i];
		for(long i=0 ; i<n ; ++i) cin>>blue[i];

		vector<edge> arr;

		for(long i=0 ; i<n ; ++i) {
			for(long j=i+1 ; j<n ; ++j) {
				if((red[i]^blue[j]) < (red[j]^blue[i])) {
					arr.push_back(edge(red[i]^blue[j], i, j));
				} else {
					arr.push_back(edge(red[j]^blue[i], j, i));
				}
			}
		}

		sort(arr.begin(), arr.end());
		set<long> done;

		answer = 0;
		for(long i=0 ; i<arr.size() ; ++i) {
			if(done.size() >= n) break;

			if(done.count(arr[i].red) < 1 || done.count(arr[i].blue) < 1) {
				answer += arr[i].weight;
				done.insert(arr[i].red);
				done.insert(arr[i].blue);
				cout<<arr[i].red<<" "<<arr[i].blue<<" "<<arr[i].weight<<endl;
			}
		}

		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
