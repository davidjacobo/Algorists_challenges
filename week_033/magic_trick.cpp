#include <iostream>
#include <cstring>
#include <string>

#define MAX_N 4
#define MAX_T 17

using namespace std;

int cards1[MAX_N][MAX_N], cards2[MAX_N][MAX_N];
int count[MAX_T];

string solve(int r1, int r2) {
	memset(count, 0, sizeof count);
	for(int j=0;j<4;++j)
		count[cards1[r1][j]]++;
	for(int j=0;j<4;++j)
		count[cards2[r2][j]]++;

	int matches = 0, number;
	for(int i=1;i<MAX_T;++i)
		if (count[i] == 2) {
			matches++;
			number = i;
		}

	if (matches == 0)
		return "Volunteer cheated!";
	else if (matches ==1)
		return to_string(number);
	return "Bad magician!";
}

int main() {
	int cases = 1, t;
	int r1, r2, temp;
	cin>>t;
	while(t--) {
		cin>>r1;
		for(int i=0;i<4;++i) 
			for(int j=0;j<4;++j)
				cin>>cards1[i][j];

		cin>>r2;
	    for(int i=0;i<4;++i)
	    	for(int j=0;j<4;++j)
	    		cin>>cards2[i][j];
	
	cout<<"Case #"<<cases++<<": "<<solve(r1-1,r2-1)<<endl;
	}
	return 0;
}