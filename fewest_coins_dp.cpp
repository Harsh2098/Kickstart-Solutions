#include<bits/stdc++.h>

using namespace std;

long getFewestCoins(vector<long> coins, long total) {

	long arr[coins.size()][total+1];

	for(int i=0 ; i<coins.size() ; ++i) arr[i][0] = 0;
	for(int i=0 ; i<=total ; ++i) arr[0][i] = i % coins[0] == 0 ? i/coins[0] : LONG_MAX;

	for(int i=1 ; i<coins.size() ; ++i) {
		for(int j=1 ; j<=total ; ++j) {
			if(coins[i] > j)
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = min(1 + arr[i][j-coins[i]], arr[i-1][j]);
		}
	}	

	if(arr[coins.size()-1][total] == LONG_MAX) return -1;
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

	long answer = getFewestCoins(coins, total);
	cout<<"Least coin count = "<<answer;

	return 0;
}
