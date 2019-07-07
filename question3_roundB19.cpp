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

	long tests, answer = 0, laster = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		laster = 0;
		answer = 0;
		long startFrom = 0;
		vector<long> arr;
		map<long, vector<long>> look;
		long size, n, temp;
		cin>>size>>n;

		for(int i=0 ; i<size ; ++i) {
			cin>>temp;
			arr.push_back(temp);
		}

		for(int i=0 ; i<size ; ++i) {
			long current = arr[i];
			look[current].push_back(i);

			if(look.count(current) > 0) {
				sort(look[current].begin(), look[current].end());

				if(look[current].size() > n) {
					laster = look[current][0]+1;
					startFrom = answer<i-look[current][0]?look[current][0]:startFrom;
					answer = max(answer, i - look[current][0]);
					look[current].erase(look[current].begin());

					for(auto it=look.begin() ; it!=look.end() ; ++it) {
						for(int x=0 ; x<(it->second).size() ; ++x) {
							if((it->second)[x] < laster) {
								(it->second).erase((it->second).begin() + x);
							}
						}
					}

				} else {
					startFrom = answer<i-laster?laster:startFrom;
					answer = max(answer, i-laster);
				}
			} else {
				startFrom = answer<i-laster?laster:startFrom;
				answer = max(answer, i-laster);
			}

			// for(auto it=look.begin() ; it!=look.end() ; ++it) {
			// 	cout<<it->first<<"->{";
			// 	for(int x=0 ; x<(it->second).size() ; ++x) {
			// 		cout<<" "<<(it->second)[x];
			// 	}
			// 	cout<<" }"<<" ";
			// }
			// cout<<"  answer="<<answer+1;
			// cout<<endl<<endl;
		}

		long r = startFrom + answer, l = startFrom;

		map<long, long> hello;
		for(int i=l ; i<=r ; ++i) {
			if(hello.count(arr[i]) > 0)
				hello[arr[i]]++;
			else
				hello[arr[i]] = 1;
		}

		cout<<l<<" "<<r<<endl;
		for(auto it=hello.begin() ; it!=hello.end() ; ++it) {
			cout<<it->first<<"->"<<it->second<<" ";
		}

		map<long, long> tempo = hello;
		answer = r - l + 1;
		long fuked = answer;
		for(int i=startFrom-1 ; i>=0 ; --i) {
			if(tempo.count(arr[i]) > 0) {
				tempo[arr[i]]++;
			} else {
				tempo[arr[i]] = 1;
			}

			if(tempo.count(arr[i]) == n+1) {
				answer -= hello[arr[i]];
			} else if(tempo.count(arr[i]) <= n) {
				answer++;
			}
			fuked = max(answer, fuked);
		}

		//cout<<endl<<"$"<<fuked<<endl;;

		tempo = hello;
		answer = fuked;
		for(int i=r+1 ; i<size ; ++i) {
			if(tempo.count(arr[i]) > 0) {
				tempo[arr[i]]++;
			} else {
				tempo[arr[i]] = 1;
			}

			if(tempo[arr[i]] == n+1) {
				answer -= hello[arr[i]];
			} else if(tempo.count(arr[i]) <= n) {
				answer++;
			}
			fuked = max(answer, fuked);
		}

		cout<<"Case #"<<i<<": "<<fuked<<endl;
	}
	return 0;
}
