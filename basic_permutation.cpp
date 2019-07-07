#include<bits/stdc++.h>

using namespace std;

class node {
	public:
		string arr;
		int level;
};

node* createNode(string s, int l) {
	node* temp = new node;
	temp->arr = s;
	temp->level = l;
	return temp;
}

int main() {

	stack<node*> s;
	int max, count = 0;
	string name;

	cin>>name;
	max = name.size() - 1;

	s.push(createNode(name, 0));
	
	while(!s.empty()) {
		node* temp = s.top();
		s.pop();

		if(temp->level == max) {
			cout<<temp->arr<<endl;
			count++;
		}
		else {
			for(int i=temp->level ; i<=max ; ++i) {
				string newString = temp->arr;
				swap(newString[temp->level], newString[i]);
				s.push(createNode(newString, temp->level+1));
			}
		}
	}

	cout<<"Total count = "<<count<<endl;

	return 0;
}
