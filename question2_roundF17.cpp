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

		long size, energy, temp;
		cin>>energy>>size;
		vector<long> arr;
		answer = 0;

		for(int i=0 ; i<size ; ++i) {
			cin>>temp;
			arr.push_back(temp);
		}

		sort(arr.begin(), arr.end());

		long start = 0, end = size-1;
		while(start != end && energy + arr[end] > arr[start]) {
			if(energy > arr[start]) {
				energy -= arr[start++];
				answer++;
			} else if(answer > 0) {
				energy += arr[end--];
				answer--;
			} else {
				break;
			}
		}

		if(start == end) {
			if(energy > arr[start])
				answer++;
		}

		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
