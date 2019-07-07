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

		int size, temp;
		cin>>size;
		vector<int> arr;

		for(int i=0 ; i<size ; ++i) {
			cin>>temp;
			arr.push_back(temp);
		}

		long start = 1, end = size;
		bool answer = true;

		while(arr.size() > 2) {
			long pivot = (arr.size()-1)/2;
			
			if(arr[pivot] == start) {
				arr.erase(arr.begin() + pivot);
				start++;
			} else if(arr[pivot] == end) {
				arr.erase(arr.begin() + pivot);
				end--;
			} else {
				answer = false;
				break;
			}
		}

		cout<<"Case #"<<i<<": "<<(answer?"YES":"NO")<<endl;
	}
	return 0;
}
