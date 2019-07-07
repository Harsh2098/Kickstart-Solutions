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

class item {
	public:
		long x,y,dist;
		item(long xx, long yy, long d) {
			x = xx;
			y = yy;
			dist = d;
		}
};

long getWorst() {
	long worst = 0;
	while(!q.empty()) {
			item current = q.front();
			q.pop();
			if(current.x>0 && arr[current.x-1][current.y] == -1) {
				arr[current.x-1][current.y] = current.dist+1;
				q.push(item(current.x-1, current.y, current.dist+1));
				worst = max(worst, current.dist + 1);
			}

			if(current.x<r-1 && arr[current.x+1][current.y] == -1) {
				arr[current.x+1][current.y] = current.dist+1;
				q.push(item(current.x+1, current.y, current.dist+1));
				worst = max(worst, current.dist + 1);
			}

			if(current.y>0 && arr[current.x][current.y-1] == -1) {
				arr[current.x][current.y-1] = current.dist+1;
				q.push(item(current.x, current.y-1, current.dist+1));
				worst = max(worst, current.dist + 1);
			}

			if(current.y<c-1 && arr[current.x][current.y+1] == -1) {
				arr[current.x][current.y+1] = current.dist+1;
				q.push(item(current.x, current.y+1, current.dist+1));
				worst = max(worst, current.dist + 1);
			}
		}
}

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		long r,c, worst = INF;
		queue<item> q;
		cin>>r>>c;
		long arr[r][c];
		string str;
		for(int i=0 ; i<r ; ++i) {
			cin>>str;
			for(int j=0 ; j<c ; ++j) {
				arr[i][j] = str[j]-48;
				if(arr[i][j] == 1) q.push(item(i,j,0));
				else arr[i][j] = -1;
			}
		}

		for(int i = 0 ; i<r ; ++i) {
			for(int j=0 ; j<c ; ++j) {
				queue<item> tempQ = q;
				tempArr = arr;
				if(arr[i][j] == -1) {
					q.push(item(i,j,0));
					worst = min(worst, getWorst(tempArr, tempQ));
				}
			}
		}

		// long locX = 0, locY = 0, count = 0;
		// for(int i=0 ; i<r ; ++i) {
		// 	for(int j=0 ; j<c ; ++j) {
		// 		if(arr[i][j] == worst) {
		// 			locX += i;
		// 			locY += j;
		// 			count++;
		// 		}
		// 	}
		// }

		// locX /= count;
		// locY /= count;

		// arr[locX][locY] = 0;
		// q.push(item(locX, locY, 0));

		// while(!q.empty()) {
		// 	item current = q.front();
		// 	q.pop();
		// 	if(current.x>0 && arr[current.x-1][current.y] > current.dist+1) {
		// 		arr[current.x-1][current.y] = current.dist+1;
		// 		q.push(item(current.x-1, current.y, current.dist+1));
		// 	}

		// 	if(current.x<r-1 && arr[current.x+1][current.y] > current.dist+1) {
		// 		arr[current.x+1][current.y] = current.dist+1;
		// 		q.push(item(current.x+1, current.y, current.dist+1));
		// 	}

		// 	if(current.y>0 && arr[current.x][current.y-1] > current.dist+1) {
		// 		arr[current.x][current.y-1] = current.dist+1;
		// 		q.push(item(current.x, current.y-1, current.dist+1));
		// 	}

		// 	if(current.y<c-1 && arr[current.x][current.y+1] > current.dist+1) {
		// 		arr[current.x][current.y+1] = current.dist+1;
		// 		q.push(item(current.x, current.y+1, current.dist+1));
		// 	}
		// }

		// worst = 0;
		// for(int i=0 ; i<r ; ++i) {
		// 	for(int j=0 ; j<c ; ++j) {
		// 		worst = max(worst, arr[i][j]);
		// 	}
		// }

		cout<<"Case #"<<i<<": "<<worst<<endl;
	}
	return 0;
}
