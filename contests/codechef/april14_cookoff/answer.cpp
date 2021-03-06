#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
 
using namespace std;
 
double a[7][7], coeff[7];
 
long double f(long double x) {
  return coeff[3] * x * x * x + coeff[2] * x * x + coeff[1] * x + coeff[0];
}
 
void do_search(long double low, long double high, vector <long double> &roots)
{
  long double fl = f(low);
  //long double fh = f(high);
  for (int it = 0; it < 100; it++)
  {
    long double mid = (low + high) * 0.5;
    long double fm = f(mid);
    if ((fl > 0 && fm > 0) || (fl < 0 && fm < 0))
      low = mid;
    else
      high = mid;
  }
  roots.push_back(0.5 * (low + high));
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < 4; i++)
	{
      int ct, cv;
      scanf("%d %d", &ct, &cv);
      a[i][0] = 1;
      for (int j = 1; j < 4; j++) a[i][j] = a[i][j - 1] * ct;
      a[i][4] = cv;
    }
    for (int e = 0; e < 4; e++) {
      for (int i = e; i < 4; i++)
        if (fabsl(a[i][e]) > 1e-9) {
          if (i != e) {
            for (int j = 0; j <= 4; j++) {
              swap(a[i][j], a[e][j]);
            }
          }
          break;
        }
      for (int i = 0; i < 4; i++) {
        if (i == e) {
          continue;
        }
        long double co = -a[i][e] / a[e][e];
        for (int j = 0; j <= 4; j++) a[i][j] += a[e][j] * co;
      }
    }
    for (int i = 0; i < 4; i++) coeff[i] = a[i][4] / a[i][i];
    vector <long double> roots;
    double A = 3 * coeff[3];
    double B = 2 * coeff[2];
    double C = 1 * coeff[1];
    double D = B * B - 4 * A * C;
    if (D > 0) {
      double xa = (-B + sqrtl(D)) / (2 * A);
      double xb = (-B - sqrtl(D)) / (2 * A);
      if (xa > xb) {
        swap(xa, xb);
      }
      if (xa < 0) xa = 0;
      if (xb < 0) xb = 0;
      if (xa > t) xa = t;
      if (xb > t) xb = t;
      do_search(0, xa, roots);
      do_search(xa, xb, roots);
      do_search(xb, t, roots);
    } else {
      do_search(0, t, roots);
    }
    roots.push_back(0);
    roots.push_back(t);
    sort(roots.begin(), roots.end());
    int sz = roots.size();
    long double ans = 0;
    for (int i = 0; i < sz - 1; i++) {
      long double t = roots[i + 1];
      long double cur = coeff[3] * t * t * t * t / 4 + coeff[2] * t * t * t / 3 + coeff[1] * t * t / 2 + coeff[0] * t;
      t = roots[i];
      cur -= coeff[3] * t * t * t * t / 4 + coeff[2] * t * t * t / 3 + coeff[1] * t * t / 2 + coeff[0] * t;
      if (cur > 0) ans += cur;
      else ans -= cur;
    }
    printf("%.17lf\n", (double)ans);
  }
  return 0;
}
