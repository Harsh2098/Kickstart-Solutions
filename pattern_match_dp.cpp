#include<bits/stdc++.h>

using namespace std;

int main() {

	string pattern, input;
	cin>>input>>pattern;

	bool arr[input.length()][pattern.length()];

	for(int i=0 ; i<input.length() ; ++i) {
		if(pattern[0] == input[i] || pattern[0]=='?' || pattern[0]=='*')
			arr[i][0] = true;
		else
			arr[i][0] = false;
	}

	for(int i=0 ; i<pattern.length() ; ++i) {
		if(input[0] == pattern[i] || pattern[i]=='?' || pattern[i]=='*')
			arr[0][i] = true;
		else
			arr[0][i] = false;
	}

	for(int i=1 ; i<input.length() ; ++i) {
		for(int j=1 ; j<pattern.length() ; ++j) {
			if(input[i] != pattern[j])
				arr[i][j] = false;
			else if(pattern[j] == '?' || input[i] == pattern[j]) {
				cout<<arr[i-1][j-1]<<endl;
				arr[i][j] = arr[i-1][j-1];
			} else {
				arr[i][j] = arr[i-1][j] || arr[i][j-1];
			}
		}
	}

	for(int i=0 ; i<input.length() ; ++i) {
		for(int j=0 ; j<pattern.length() ; ++j) {
			cout<<(int)arr[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<endl<<(arr[input.length()-1][pattern.length()-1]?"It is a match!":"Don't match")<<endl;

	return 0;
}
