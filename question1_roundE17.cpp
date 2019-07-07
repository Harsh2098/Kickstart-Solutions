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

bool searchInString(string str, string suber) {
	for(int i=0; i<str.length()-suber.length() ; ++i) {
		if(str.substr(i, suber.length()) == suber) return true;
	}
	return false;
}

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		int done = 0;
		string arr, lastFound = "";
		cin>>arr;
		answer = 0;

		while(true) {
			int x=arr.length()-1;
			if(x < 0) break;

			while(x >= arr.length()/2) {
				string searcher = arr.substr(x);
				bool found = searchInString(arr.substr(0, arr.length()-searcher.length()), searcher);
				cout<<arr<<" "<<searcher<<" "<<found<<endl;
				if(found && x > arr.length()/2+1) x--;
				else {
					if(searcher.length() == 1) {
						answer++;
						arr = arr.substr(0, arr.length()-1);
						done++;
						continue;
					} else if(x != arr.length()/2+1) {
						searcher.erase(searcher.end()-1);
					}

					if(lastFound != searcher) answer++;
					lastFound = searcher;
					done += searcher.length();
					arr.erase(arr.end() - searcher.length(), arr.end());
					answer++;
				}
			}
		}

		cout<<"\nCase #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
