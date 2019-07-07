// Small and large test cases passed

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

class queries {
	public:
	int l, r;
	queries(int l, int r) {
		this->l = l;
		this->r = r;
	}
};

bool checkPalindrome(map<char,long> main, map<char, long> sub, char ch) {

	long counter = 0;
	if(main.count(ch) > 0) main[ch]++;
	else main[ch] = 1;
	
	for(auto it = main.begin() ; it!=main.end() ; ++it) {
		if(sub.count(it->first) > 0)
			main[it->first] -= sub[it->first];

		if(main[it->first] % 2 == 1)
			counter++;

		if(counter == 2) {
			return false;
		}
	}

	return true;
}

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		answer = 0;
		string str;
		long length, num_q, tl, tr;
		vector<queries> ques;

		cin>>length>>num_q;
		cin>>str;
		for(int i=0 ; i<num_q ; ++i) {
			cin>>tl>>tr;
			ques.push_back(queries(tl,tr));
		}

		map<char, long> look[length];
		map<char, long> tempMap;

		look[0] = tempMap;

		for(int i=1 ; i<str.length() ; ++i) {
			char ch = str[i-1];
			if(tempMap.count(ch) > 0) tempMap[ch]++;
			else tempMap[ch] = 1;
			look[i] = tempMap;
		}

		for(int i=0 ; i<ques.size() ; ++i) {
			if(checkPalindrome(look[ques[i].r-1], look[ques[i].l - 1], str[ques[i].r - 1]))
				answer++;
		}


		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
