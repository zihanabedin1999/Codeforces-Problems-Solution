
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int INF = (int)1e9;
const int N = 303;
int n;
pii a[N], b[N];
int dp[N][N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &b[i].first, &b[i].second);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	for (int x = 0; x <= n; x++)
		for (int y = 0; y <= n; y++) {
			if (dp[x][y] == INF) continue;
			if (x < n)
				dp[x + 1][y] = min(dp[x + 1][y], dp[x][y] + a[x].second);
			if (y < n)
				dp[x][y + 1] = min(dp[x][y + 1], dp[x][y] + b[y].second);
			int p = x, q = y;
			int t1 = dp[x][y], t2 = dp[x][y];
			bool ok = true;
			while(ok && p < n && q < n) {
				if (t1 < t2) {
					if (t1 < t2 && a[p].first == b[q - 1].first) {
						ok = false;
						break;
					}
					t1 += a[p].second;
					p++;
				} else {
					if (t2 < t1 && a[p - 1].first == b[q].first) {
						ok = false;
						break;
					}
					t2 += b[q].second;
					q++;
				}
				dp[p][q] = min(dp[p][q], max(t1, t2));
			}
			while(ok && p < n) {
				if (t1 < t2 && a[p].first == b[n - 1].first) {
					ok = false;
					break;
				}
				t1 += a[p].second;
				p++;
				dp[p][q] = min(dp[p][q], max(t1, t2));
			}
			while(ok && q < n) {
				if (t2 < t1 && b[q].first == a[n - 1].first) {
					ok = false;
					break;
				}
				t2 += b[q].second;
				q++;
				dp[p][q] = min(dp[p][q], max(t1, t2));
			}
		}
	printf("%d\n", dp[n][n]);
}

int main()
{
	startTime = clock();
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}