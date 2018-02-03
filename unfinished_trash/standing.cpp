#include <iostream>

using namespace std;

int solve(string input) {
	int len = input.size();
	int total = input[0] - '0';
	int acarreados = 0;

	for(int i=1;i<len;++i) {
		int ppl = input[i] - '0';
		// If we need to bring 'acarreados' do it here.
		int acarreados_i = max(0, i - total);
		total += (ppl + acarreados_i);
		acarreados += acarreados_i;
	}

	return acarreados;
}

int main() {
	int counter = 1;
	int t, s;
	string config;
	cin>>t;

	while(t--) {
		cin>>s>>config;
		cout<<"Case #"<<counter++<<": "<<solve(config)<<endl;
	}
	return 0;
}
