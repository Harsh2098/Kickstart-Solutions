#include<bits/stdc++.h>

using namespace std;

long getWays(vector<long> coins, long total) {
	
	long arr[coins.size()][total+1];

	for(int i=0 ; i<coins.size() ; ++i) arr[i][0] = 1;
	for(int i=0 ; i<=total ; ++i) arr[0][i] = i % coins[0] == 0;

	for(int i=1 ; i<coins.size() ; ++i) {
		for(int j=1 ; j<=total ; ++j) {
			if(coins[i] > j)
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = arr[i-1][j] + arr[i][j-coins[i]];
		}
	}	

	// for(int a=0 ; a<coins.size() ; ++a) {
	// 	for(int b=0 ; b<=total ; ++b) {
	// 		cout<<arr[a][b]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return arr[coins.size()-1][total];
}

int main() {

	vector<long> coins;
	long size, temp, total;

	cin>>size>>total;
	for(int i=0 ; i<size ; ++i) {
		cin>>temp;
		coins.push_back(temp);
	}

	long answer = getWays(coins, total);
	cout<<"Total ways = "<<answer;

	return 0;
}
