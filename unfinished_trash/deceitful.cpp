#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 1001
#define INF 2.0

using namespace std;

double a_nums[MAX_N], b_nums[MAX_N];
bool used[MAX_N];

int find_bigger_than(double val) {
	// There is an INF at the end, no need to provide bounds.
	int i = 0;
	while(b_nums[i] < val) ++i;

	while(b_nums[i] != INF) {
		if (!used[i]) break;
		++i;
	}

	// Never test like this for real numbers.
	return b_nums[i] != INF ? i : -1;
}

int find_smaller() {
	int i = 0;
	while(used[i]) ++i;

	return i;
}

void mark_biggest(int n) {
	int i =  n - 1;
	while(used[i]) --i;

	used[i] = true;
}

int solve_war(int n) {
	memset(used, false, sizeof used);
	int out = 0;
	for(int i=0;i<n;++i) {
		int index = find_bigger_than(a_nums[i]);
	  if (index != -1) {
			used[index] = true;
		}	else {
			++out;
			int j = find_smaller();
			used[j] = true;
		}
	}
	return out;
}

int solve_deceitful(int n) {
	memset(used, false, sizeof used);
	int out = 0;
	for(int i=0;i<n;++i) {
		int index = find_bigger_than(a_nums[i]);
		if (index != -1) {
			int j = find_smaller();
			if (a_nums[i] > b_nums[j]) {
				used[j] = true;
				++out;
			} else {
				mark_biggest(n);
			}
		} else {
			++out;
			int j = find_smaller();
			used[j] = true;
		}
	}
	return out;
}

void capture(int n) {
	for(int i=0;i<n;++i) cin >> a_nums[i];

	for(int i=0;i<n;++i) cin >> b_nums[i];
	sort(a_nums, a_nums+n);
	sort(b_nums, b_nums+n);
	a_nums[n] = INF;
	b_nums[n] = INF;
}

int main() {
	int counter = 1;
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		capture(n);
		cout<<"Case #"<<counter++<<": "<<solve_deceitful(n)<<" "<<solve_war(n)<<endl;
	}
	return 1;
}
