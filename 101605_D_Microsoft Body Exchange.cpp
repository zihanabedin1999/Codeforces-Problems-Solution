#include<bits\stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) for(int i = 0; i < int(n); ++i)

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))
#define x first
#define y second

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
 return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
 out << "[";
 forn(i, sz(v)) {
  if(i > 0)
   out << ", ";
  out << v[i];
 };
 return out << "]";
}

mt19937 myRand(time(NULL));

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const double EPS = 1e-9;
const int N = 100043;

vector<pt> ans;
int a[N];
int n, m;
int u[N];

void clear()
{
 ans.clear();
 forn(i, n + 2) a[i] = i;
 forn(i, n) u[i] = 0;
}

inline bool read() {
 if(scanf("%d", &n) != 1)
  return false;
 if (!n) return false;
 clear();
 scanf("%d", &m);
 forn(i, m)
 {
  int x, y;
  scanf("%d %d", &x, &y);
  swap(a[x], a[y]);
 }
 return true;
}

void query(int x, int y)
{
 ans.pb(mp(x, y));
 swap(a[x], a[y]);
}

inline void solve() {
 vector<pt> z;
 int lst = -1;
 forn(i, n)
 {
  if(u[i]) continue;
  u[i] = 1;
  int cur = a[i];
  if(cur == i)
   continue;
  int cnt = 1;
  while(cur != i)
  {
   u[cur] = 1;
   cnt++;
   lst = cur;
   cur = a[cur];
  }
  z.pb(mp(cur, cnt));
 }
 if (lst == -1)
 {
  puts("");
  return;
 }
 query(n, n + 1);
 forn(i, sz(z))
 {
  int k = z[i].y;
  if (i == sz(z) - 1)
   k--;
  query(n, z[i].x);
  forn(j, k - 1)
   query(n, a[n]);
 }
 query(n + 1, lst);
 while(a[n + 1] != n + 1)
  query(n + 1, a[n + 1]);
 query(n, a[n]);
 for(auto x : ans) printf("%d %d ", x.x, x.y);
 puts("");
 forn(i, n + 2) assert(a[i] == i);
}

int main() {
#ifdef _DEBUG
 freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 int tt = clock();
#endif
 cout << fixed << setprecision(15);
 cerr << fixed << setprecision(15);

 while(read()) {
  solve();
  
#ifdef _DEBUG
  cerr << "TIME = " << clock() - tt << endl;
  tt = clock();
#endif
 }
 
 return 0;
}