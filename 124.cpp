
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ttt template <typename T>
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int INF = 0x3f3f3f3f;
ttt inline T rd(T& x) {
  x = 0;
  T neg = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  x *= neg;
  return x;
}
// -------- Item Get Border Line! -----------
// Don't forget to use long long if needed!
int n;
const int N = 1000100;
LL a[N], sum;
int main() {
  rd(n);
  repn(i, n) {
    rd(a[i]);
    sum += a[i];
  }
  LL avg = sum / n;
  repn(i, n) {
    a[i] = a[i] - avg;  // a[i] - T/M
    a[i] += a[i - 1]; // prefix sum
  }
  sort(a + 1, a + n + 1);
  LL res = 0;
  repn(i, n) {
    res += abs(a[i] - a[(n + 1) / 2]);
  }
  cout << res << endl;
}