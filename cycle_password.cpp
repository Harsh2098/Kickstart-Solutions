#include<bits/stdc++.h>

#define INF 100000

using namespace std;

class node {
	
	public:
	
	int data, digits;
	vector<node*> children;
	string current;
};

node* createNode(int data, int digits, string upto) {
	node* temp = new node;
	temp->data = data;
	temp->children = vector<node*>{};
	temp->digits = digits;
	temp->current = upto + (char)(data+49-1);
	return temp;
}

int getWays(int length, int digits) {
	set<string> answer;
	stack<node*> s;

	s.push(createNode(INF, length, ""));

	while(!s.empty()) {
		node* temp = s.top();
		s.pop();

		for(int i=temp->data-1 ; i>temp->digits-1 ; --i) {
			if(i == INF - 1) i = digits;

			if(temp->digits-1 >= 0) {
				node* newChild = createNode(i, temp->digits-1, temp->current);
				(temp->children).push_back(newChild);
				s.push(newChild);
			} else {
				answer.insert(temp->current);
			}
		}
	}

	for(auto it=answer.begin() ; it!=answer.end() ; ++it) {
		cout<<(*it).substr(1)<<endl;
	}

	return answer.size();
}

int main() {

	int length, digits;
	cin>>length>>digits;
	
	for(int i=length ; i<=length ; ++i) {
		cout<<"Total ways for length("<<i<<") = "<<getWays(i, digits)<<endl;
	}

	return 0;
}
