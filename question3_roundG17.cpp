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

const long N = 40, M = 40;

long getMaxCoins(long top, long left, long bottom, long right, long arr[][M], long look[][M][N][M]) {
	if(look[top][left][bottom][right] != -1)
		return look[top][left][bottom][right];
	if(top == bottom && left == right) return 0;

	long answer = INF;

	for(long i=top ; i<=bottom ; ++i) {
		for(long j=left ; j<=right ; ++j) {
			if(arr[i][j] < answer) answer = arr[i][j];
		}
	}

	long cutter = 0;
	for(long i=top ; i<bottom ; ++i) {
		long temp = getMaxCoins(top, left, i, right, arr, look) + getMaxCoins(i+1, left, bottom, right, arr, look);
		if(temp > cutter) cutter = temp;
	}
	for(long i=left ; i<right ; ++i) {
		long temp = getMaxCoins(top, left, bottom, i, arr, look) + getMaxCoins(top, i+1, bottom, right, arr, look);
		if(temp > cutter) cutter = temp;
	}

	answer += cutter;
	look[top][left][bottom][right] = answer;

	//cout<<top<<" "<<bottom<<" "<<left<<" "<<right<<" -> "<<answer<<" - "<<cutter<<endl;
	return answer;
}

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(long i=1 ; i<=tests ; ++i) {

		long n,m;
		cin>>n>>m;

		long arr[N][M] = (long**)malloc(sizeof(long)*1600);
		long**** look = (long****)malloc(sizeof(long)*1600*1600);

		for(long i=0 ; i<n ; ++i) for(long j=0 ; j<m ; ++j) for(long k=0 ; k<n ; ++k) for(long l=0 ; l<m ; ++l) look[i][j][k][l] = -1;

		for(long i=0 ; i<n ; ++i) for(long j=0 ; j<m ; ++j) cin>>arr[i][j];

		cout<<"Case #"<<i<<": "<<getMaxCoins(0, 0, n-1, m-1, arr, look)<<endl;
	}
	return 0;
}
