#include <iostream>
#include <cmath>
#define MAX_N 1001

using namespace std;

int input[MAX_N];

int calculate_cuts(int d, double stack_size) {
	int cuts = 0;
	for(int i=0;i<d;++i)
		cuts += ceil(input[i]/stack_size) - 1;
	return cuts;
}

int solve(int d) {
	int pancakes, max_value = 0;

	//capture data
	for(int i=0;i<d;++i) {
		cin>>input[i];
		max_value = max(max_value, input[i]);
	}

	int best_time = max_value;
	// Lets propose a max stack size, split every plate with more pancakes than
	// this limit, count the splits.
	for(int i = 1;i<= max_value;++i) {
		int cuts = calculate_cuts(d, i);
		best_time = min(best_time, (cuts ? cuts + i : max_value));
	}
	return best_time;
}

int main() {
	int t, counter =1, d;
	cin>>t;
	
	while(t--) {
		cin>>d;
		cout<<"Case #"<<counter++<<": "<<solve(d)<<endl;
	}
	return 0;
}
