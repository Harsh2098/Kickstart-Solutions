#include<bits/stdc++.h>

using namespace std;

int main() {

	string a,b, answer = "";
	cin>>a>>b;

	int arr[a.length()][b.length()];

	for(int i=0 ; i<a.length() ; ++i) {
		if(b[0] == a[i]) {
			while(i<a.length()) {
				arr[i][0] = 1;
				i++;
			}
		} else
			arr[i][0] = 0;
	}

	for(int i=0 ; i<b.length() ; ++i) {
		if(a[0] == b[i]) {
			while(i<b.length()) {
				arr[0][i] = 1;
				i++;
			}
		} else
			arr[0][i] = 0;
	}

	for(int i=1 ; i<a.length() ; ++i) {
		for (int j=1; j<b.length(); ++j) {
			if(a[i] == b[j])
				arr[i][j] = 1 + arr[i-1][j-1];
			else
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
		}
	}

	// Finding actual common subsequence
	int x=a.length()-1, y=b.length()-1;
	while(x>=0 && y>=0) {
		if(x-1>=0 && arr[x][y] == arr[x-1][y])
			x--;
		else if(y-1>=0 && arr[x][y] == arr[x][y-1])
			y--;
		else {
			answer += a[x];
			x--;
			y--;
		}
	}

	reverse(answer.begin(), answer.end());

	cout<<"Longest common subsequence = "<<arr[a.length()-1][b.length()-1]<<endl<<answer;

	return 0;
}
