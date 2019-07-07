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

		long m, vertex, pokemon, t1, t2, d1;
		cin>>vertex>>m>>pokemon;
		long dist[vertex][vertex];

		for(int i=0 ; i<vertex ; ++i) {
			for(int j=0 ; j<vertex ; ++j) {
				if(i==j) dist[i][j] = 0;
				else dist[i][j] = INF;
			}
		}

		for(int i=0 ; i<m ; ++i) {
			cin>>t1>>t2>>d1;
			dist[t1-1][t2-1] = dist[t2-1][t1-1] = d1;
		}

		for(int i=0 ; i<vertex ; ++i) {
			for(int j=0 ; j<vertex ; ++j) {
				for(int k=0 ; k<vertex ; ++k) {
					if(dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		for(int i=0 ; i<vertex ; ++i) {
			for(int j=0 ; j<vertex ; ++j) {
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

		double dp[vertex][pokemon];
		long sum = 0;
		for(int j=0 ; j<vertex ; ++j) {
			sum += dist[j][0];
		}
		dp[0][0] = (double)sum / (double)(vertex-1);
		for(int i=1 ; i<vertex ; ++i) dp[i][0] = 0;

		for(int i=1 ; i<pokemon ; ++i) {
			for(int j=0 ; j<vertex ; ++j) {
				double sum = 0.0;
				for(int k=0 ; k<vertex ; ++k) {
					if(k==j) continue;
					sum += (dp[k][i-1] + (double)dist[k][j]);
				}
				dp[j][i]=sum/(double)(vertex-1);
			}
		}

		for(int i=0 ; i<vertex ; ++i) {
			for(int j=0 ; j<pokemon ; ++j) {
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<"Case #"<<i<<": "<<dp[0][0]<<endl;
	}
	return 0;
}
