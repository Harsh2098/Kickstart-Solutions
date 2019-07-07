#include<bits/stdc++.h>

using namespace std;

/* INPUTS - size */

// class node {
// 	public:
// 		string arr;
// 		int level;
// };

// node* createNode(string s, int l) {
// 	node* temp = new node;
// 	temp->arr = s;
// 	temp->level = l;
// 	return temp;
// }

// bool checkValid(string s) {
// 	int count = 0, i=0;
// 	for(i=0 ; count >= 0 && i<s.size(); ++i) {
// 		if(s[i] == '(')
// 			count++;
// 		else
// 			count--;

// 		if(count < 0) return false;
// 	}

// 	return count == 0;
// }
vector<string> answer;
int limit;

void backtrack(string current, int open, int close) {
    if(current.length() == limit*2) {
        answer.push_back(current);
        return;
    }
        
    if(open == close) {
        backtrack(current + "(", open + 1, close);
    } else if(open == limit) {
        backtrack(current + ")", open, close + 1);
    } else {
        backtrack(current + "(", open + 1, close);
        backtrack(current + ")", open, close + 1);
    }
}

vector<string> generateParenthesis(int n) {
    limit = n;
    backtrack("", 0, 0);
    return answer;
}

int main() {

    cin>>limit;
    vector<string> answer = generateParenthesis(limit);
    for(int i=0 ; i<answer.size() ; ++i) cout<<answer[i]<<endl;

    return 0;
}

	// stack<node*> s;
	// set<string> answer;
	// int max, size;

	// cin>>size;
	// max = 2*size-1;
	// string name = "";
	// for(int i=0 ; i<size ; i++, name+="()");

	// s.push(createNode(name, 0));
	
	// while(!s.empty()) {
	// 	node* temp = s.top();
	// 	s.pop();

	// 	if(temp->level == max && checkValid(temp->arr)) {
	// 		answer.insert(temp->arr);
	// 	}
	// 	else {
	// 		for(int i=temp->level ; i<=max ; ++i) {
	// 			string newString = temp->arr;
	// 			swap(newString[temp->level], newString[i]);
	// 			s.push(createNode(newString, temp->level+1));
	// 		}
	// 	}
	// }

	// for(auto it = answer.begin() ; it != answer.end() ; ++it) {
	// 	cout<<*it<<endl;
	// }

	// cout<<"Total count = "<<answer.size()<<endl;
