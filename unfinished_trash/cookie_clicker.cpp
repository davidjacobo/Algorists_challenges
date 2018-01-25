#include <cstdio>
#include <iostream>
#include <cstdio>

#define INF 1<<20

using namespace std;

long double solve(long double speed, long double c, long double f, long double x) {
  if (x <= c) return x / speed;
  if (speed > x) return INF;  // This shit is too fast.

  // Two options, either solve right away without further increasing the speed.
  long double sol_a = x / speed;
  
  // Otherwise increase the speed by one ASAP
  long double sol_b = c / speed;
  sol_b+= solve(speed + f, c, f, x);

  return min(sol_a, sol_b);
}

int main() {
  long double c,f,x;
  int t, counter = 1;
  cin>>t;
  while(t--) {
    cin>>c>>f>>x;
    printf("Case #%d: %.7Lf\n",counter++, solve(2.0, c,f,x));
  }
  return 0;
}
