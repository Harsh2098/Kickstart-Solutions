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

class stone {
	public:
		long energy, loss, time;

		stone(long time, long energy, long loss) {
			this->time = time;
			this->energy = energy;
			this->loss = loss;
		}

		bool operator < (const stone& stn) const {
			if(stn.loss == 0 && loss == 0) {
				return stn.time > time;
			} else if(stn.loss == 0) {
				return false;
			} else if(loss == 0) {
				return true;
			}

			return (double)stn.time/(double)stn.loss > (double)time/(double)loss;
		}
};

class data {
	public:
		long energy, start;
		bool eating;

		data() {
			energy = 0;
			start = 0;
			eating = false;
		}
};

int main() {

	long tests, answer = 0;

	cin>>tests;

	for(int i=1 ; i<=tests ; ++i) {

		long size, t1, t2, t3, totalTime = 0;
		vector<stone> stones;
		
		answer = 0;
		cin>>size;
		for(int i=0 ; i<size ; ++i) {
			cin>>t1>>t2>>t3;
			totalTime += t1;
			stones.push_back(stone(t1, t2, t3));
		}

		sort(stones.begin(), stones.end());
		// for(stone stn : stones) {
		// 	cout<<stn.time<<" "<<stn.energy<<" "<<stn.loss<<endl;
		// }

		cout<<endl;
		data look[size+1][totalTime + 1];

		for(int i=1 ; i<=size ; ++i) {
			for(int j=1 ; j<=totalTime ; ++j) {
				long index = i-1;
				if(!look[i-1][j].eating) {
					int x;
					for(x=j ; x<j+stones[index].time ; ++x) {
						if(stones[index].energy < (j-1)*stones[index].loss) {
							look[i][x].energy = look[i-1][j-1].energy;
							look[i][x].eating = false;
							look[i][x].start = j;
						} else {
							look[i][x].energy = stones[index].energy - (j-1)*stones[index].loss + look[i-1][j-1].energy;
							look[i][x].eating = true;
							look[i][x].start = j;
						}
					}
					j = x;
					break;
				} else {
					if(stones[index].energy - (j-1)*stones[index].loss > look[i-1][look[i-1][j].start].energy) {
						int x;
						for(x=j ; x<j+stones[index].time ; ++x) {
							if(stones[index].energy < (j-1)*stones[index].loss) {
							look[i][x].energy = look[i-1][j-1].energy;
							look[i][x].eating = false;
							look[i][x].start = j;
						} else {
							look[i][x].energy = stones[index].energy - (j-1)*stones[index].loss + look[i-1][j-1].energy;
							look[i][x].eating = true;
							look[i][x].start = j;
						}
						}
						j=x;
						break;
					} else {
						look[i][j].energy = look[i-1][j].energy;
						look[i][j].start = j;
						look[i][j].eating = true;
					}
				}
			}
		}

		for(int i=0 ; i<=size ; ++i) {
			for(int j=0 ; j<=totalTime ; ++j) {
				cout<<look[i][j].energy<<(look[i][j].eating?"t":"f")<<" ";
			}
			cout<<endl;
		}

		cout<<"Case #"<<i<<": "<<look[size][totalTime].energy<<endl;
	}
	return 0;
}
