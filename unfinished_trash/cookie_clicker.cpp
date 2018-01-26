#include <cstdio>
#include <iostream>
#include <cstdio>

using namespace std;

long double solve(long double c, long double f, long double x) {
  long double s0 = 2.0;
  long double t0 = x / s0, t1;
  int i = 1;
  long double sum = 0.0;

  while(1) {
    sum = sum + c/(s0 + f*(i-1));
    t1 = sum + x/(s0 + f*i);
    if (t1 > t0) break;
    t0 = t1;
    ++i;
  }

  return t0;
}

int main() {
  long double c,f,x;
  int t, counter = 1;
  cin>>t;
  while(t--) {
    cin>>c>>f>>x;
    printf("Case #%d: %.7Lf\n",counter++, solve(c,f,x));
  }
  return 0;
}
