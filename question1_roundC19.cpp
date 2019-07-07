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

class sq {
public:
	long x, y, top, bottom, left, right;
	sq(long x, long y, long top, long bottom, long left, long right) {
		this->x = x;
		this->y = y;
		this->top = top;
		this->bottom = bottom;
		this->left = left;
		this->right = right;
	}
}

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		map<pair<long,long>, sq> look;
		long n, r, c, sx, sy;
		string commands;
		cin>>n>>r>>c>>sx>>sy>>commands;

		look[make_pair(sx, sy)] = sq(sx, sy, sx-1, sx+1, sy-1, sy+1);
		for(int i=0 ; i<n ; ++i) {
			char ch = commands[i];
			switch(ch) {
				case 'E': {
					if(look.count(make_pair(sx, sy+1)) > 0) {
						sq temp = look[make_pair(sx, sy+1)];
						look[make_pair(sx, temp.y, )]
					}
					break;
				}
				case 'W': {
					pair<long,long> temp = make_pair(sx, --sy);
					while(look.count(temp) > 0)
						(temp.second)--;
					look.insert(make_pair(temp.first,temp.second));
					sx = temp.first;
					sy = temp.second;
					break;
				}

				case 'N': {
					pair<long,long> temp = make_pair(--sx, sy);
					while(look.count(temp) > 0)
						(temp.first)--;
					look.insert(make_pair(temp.first,temp.second));
					sx = temp.first;
					sy = temp.second;
					break;
				}

				case 'S': {
					pair<long,long> temp = make_pair(++sx, sy);
					while(look.count(temp) > 0)
						(temp.first)++;
					look.insert(make_pair(temp.first,temp.second));
					sx = temp.first;
					sy = temp.second;
					break;
				}
			}
		}

		cout<<"Case #"<<i<<": "<<sx<<" "<<sy<<endl;
	}
	return 0;
}
