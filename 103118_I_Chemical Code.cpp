#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <set>
#ifdef XLor
  #define dbg(args...) cout << #args << " -> ", err(args)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
using ll = long long;
using PII = pair<int,int>;
const int mod = 985151223;
const int maxn = 200000 + 5;
 
int n, q;
 
struct DS {
  static const int S = 3;
 
  struct Info {
    int cnt = 0, val = 1;
 
    void clear() {
      cnt = 0; val = 1;
    }
  };
 
  struct SegT {
    #define lson l, m, rt << 1
    #define rson m + 1, r, rt << 1 | 1
 
    int mod, K, P;
    Info a[maxn << 2], tag[maxn << 2];
 
    int pow(int c) { // P^c % mod
      if (c >= K) {
        return 0;
      } else {
        int r = 1;
        for (int i = 0; i < c; i++) {
          r *= P;
        }
        assert(r < mod);
        return r;
      }
    }
 
    int inverse(int a) { // u * a = 1
      a %= mod;
      if (a < 0) {
        a += mod;
      }
      int b = mod, u = 0, v = 1;
      while (a) {
        int t = b / a;
        b -= a * t;
        swap(a, b);
        u -= v * t;
        swap(u, v);
      }
      if (u < 0) {
        u += mod;
      }
      return u;
    }
    
    void build(int val, int l = 1, int r = n, int rt = 1) {
      tag[rt].clear();
      if (l == r) {
        a[rt].cnt = 0;
        a[rt].val = val;
        return ;
      }
      int m = (l + r) / 2;
      build(val, lson); build(val, rson);
      pushup(rt);
    }
 
    void pushup(int rt) {
      Info& lhs = a[rt << 1];
      Info& rhs = a[rt << 1 | 1];
      if (lhs.cnt == rhs.cnt) {
        a[rt].cnt = lhs.cnt;
        a[rt].val = (lhs.val + rhs.val) % mod;
      } else if (lhs.cnt < rhs.cnt) {
        a[rt].cnt = lhs.cnt;
        a[rt].val = (lhs.val + 1ll * pow(rhs.cnt - lhs.cnt) * rhs.val) % mod;
      } else {
        a[rt].cnt = rhs.cnt;
        a[rt].val = (1ll * pow(lhs.cnt - rhs.cnt) * lhs.val + rhs.val) % mod;
      }
    }
    void apply(int rt, const Info& x) {
      a[rt].cnt += x.cnt;
      a[rt].val = 1ll * a[rt].val * x.val % mod;
      tag[rt].cnt += x.cnt;
      tag[rt].val = 1ll * tag[rt].val * x.val % mod;
    }
    void pushdown(int rt) {
      apply(rt << 1, tag[rt]);
      apply(rt << 1 | 1, tag[rt]);
      tag[rt].clear();
    }
    void set(int i, const Info& x, int l = 1, int r = n, int rt = 1) {
      if (l == r) {
        a[rt].cnt = x.cnt;
        a[rt].val = x.val;
        return ;
      }
      int m = (l + r) / 2;
      pushdown(rt);
      if (i <= m) set(i, x, lson);
      else set(i, x, rson);
      pushup(rt);
    }
    void update(int L, int R, const Info& x, int l = 1, int r = n, int rt = 1) {
      if (L <= l && r <= R) {
        apply(rt, x);
        return ;
      }
      int m = (l + r) / 2;
      pushdown(rt);
      if (L <= m) update(L, R, x, lson);
      if (R > m) update(L, R, x, rson);
      pushup(rt);
    }
 
    Info query(int i, int l = 1, int r = n, int rt = 1) {
      if (l == r) {
        return a[rt];
      }
      int m = (l + r) / 2;
      pushdown(rt);
      if (i <= m) return query(i, lson);
      else return query(i, rson);
    }
  } f[S];
 
  void build(int val) {
    f[0].P = 3; f[0].K = 2; f[0].mod = 9;
    f[1].P = 7; f[1].K = 3; f[1].mod = 343;
    f[2].P = 319129; f[2].K = 1; f[2].mod = 319129;
    for (int i = 0; i < S; i++) {
      f[i].build(val);
    }
  }
 
  void set(int pos, DS& g) {
    for (int i = 0; i < S; i++) {
      f[i].set(pos, g.f[i].query(pos));
    }
  }
 
  void div(int L, int R, int d) {
    for (int i = 0; i < S; i++) {
      Info tag;
      int x = d;
      while (x % f[i].P == 0) {
        tag.cnt--;
        x /= f[i].P;
      }
      tag.val = f[i].inverse(x);
      f[i].update(L, R, tag);
    }
  }
 
  void mul(int L, int R, int d) {
    for (int i = 0; i < S; i++) {
      Info tag;
      int x = d;
      while (x % f[i].P == 0) {
        tag.cnt++;
        x /= f[i].P;
      }
      tag.val = x;
      f[i].update(L, R, tag);
    }
  }
 
  int sum() {
    int ans = 0;
    for (int i = 0; i < S; i++) {
      int x = 1ll * f[i].pow(f[i].a[1].cnt) * f[i].a[1].val % f[i].mod;
      int M = mod / f[i].mod;
      int N = f[i].inverse(M);
      int cur = 1ll * x * M * N % mod;
      ans = (ans + cur) % mod;
    }
    return ans;
  }
} f, g;
 
set<int> ok;
int matchL[maxn];
char buf[maxn];
 
bool isDigit(int pos) {
  return '0' <= buf[pos] && buf[pos] <= '9';
}
 
int getV(int pos) {
  char ch = buf[pos];
  if (ch == 'C') return 12;
  if (ch == 'H') return 1;
  if (ch == 'O') return 16;
  return 0;
}
 
void remove(int Rpos, int d) {
  if (buf[Rpos] == ')') {
    g.div(matchL[Rpos], Rpos, d);
    f.div(matchL[Rpos], Rpos, d);
  } else {
    g.div(Rpos, Rpos, d);
    f.div(Rpos, Rpos, d);
  }
}
 
void insertX(int pos, int val) {
  auto it = ok.upper_bound(pos);
  if (it != ok.end() && isDigit(*it)) {
    assert(it != ok.begin());
    int d = buf[*it] - '0';
    it--;
    remove(*it, d);
    g.mul(pos, pos, d);
  }
  f.set(pos, g);
  f.mul(pos, pos, val);
}
 
void insertD(int pos, int d) {
  auto it = ok.upper_bound(pos);
  assert(it != ok.begin());
  it--;
  if (buf[*it] == ')') {
    g.mul(matchL[*it], *it, d);
    f.mul(matchL[*it], *it, d);
  } else {
    g.mul(*it, *it, d);
    f.mul(*it, *it, d);
  }
}
 
void insertP(int L, int R) {
  auto it = ok.upper_bound(R);
  if (it != ok.end() && isDigit(*it)) {
    assert(it != ok.begin());
    int d = buf[*it] - '0';
    it--;
    remove(*it, d);
    g.mul(L, R, d);
    f.mul(L, R, d);
  }
}
 
int main() {
  scanf("%d%d", &n, &q);
  f.build(0); g.build(1);
  for (int i = 1; i <= q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      char ch[4];
      int pos;
      scanf("%s%d", ch, &pos);
      if (ch[0] == 'C') {
        insertX(pos, 12);
      } else if (ch[0] == 'H') {
        insertX(pos, 1);
      } else if (ch[0] == 'O') {
        insertX(pos, 16);
      } else {
        insertD(pos, ch[0] - '0');
      }
      ok.insert(pos);
      buf[pos] = ch[0];
    } else if (op == 2) {
      int L, R;
      scanf("%d%d", &L, &R);
      insertP(L, R);
      ok.insert(L);
      ok.insert(R);
      buf[L] = '(';
      buf[R] = ')';
      matchL[R] = L;
    }
    printf("%d\n", f.sum());
  }
  return 0;
}