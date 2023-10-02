/**                         _       _______
                           | |     |____   /
                           | |          / /
                           | |         / /
                           | |____    / /
                           |______|  /_/
**/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef         long long ll;
typedef         long double ld;
typedef         vector<int>vl;
typedef         deque<int>dq;
typedef         pair<int,int>pl;
#define         ordered_set tree<int, nuint_type,less<int>, rb_tree_tag,tre
#define         yes {cout<<"YES"<<endl;return;}
#define         no {cout<<"NO"<<endl;return;}
#define         CR(_) {cout<<_<<endl;return;}
#define         F first
#define         S second
#define         pb push_back
#define         ppb pop_back
#define         pf push_front
#define         ppf pop_front
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         aint(v) v.begin(), v.end()
#define         raint(v) v.rbegin(), v.rend()
//const           int MOD = intONG_MAX;
//const           int MOD = 998244353;
const           int MOD=1000000007;
const           ld eps=1e-7;
const           double PI=acos(-1);
const           int N=2e5+5;
const           int INF=1e18;
const           int L = log2(N)+1;
int r;
int binexp(int a, int k,int mod=MOD){
    int ans = 1;
    while (k){
        if (k & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ans;
}
int mul(int u , int v, int mod=r){
    return ((u%mod)*(v%mod))%mod;
}
int add(int u, int v, int mod=r){
    return ((u%mod)+(v%mod)+mod)%mod;
}

struct item{
    int a,b,c,d;
    item(int aa=0,int bb=0,int cc=0,int dd=0){
        a=aa,b=bb,c=cc,d=dd;
    }
};
template <typename T, class F = function<T(const T&, const T&)>>
class SegmentTree {
    T NEUTRAL;
    int n;
    vector<T> tree;
    F func;
public:
    SegmentTree(int sz,T neutral, const F& f) : func(f) {
        NEUTRAL = neutral;
        n = (1 << (32 - __builtin_clz(sz)));
        tree.resize(n*2);
    }

    void update(int i, T value) {
        tree[i+=n] = value;
        while(i){
            i>>= 1;
            tree[i] = func(tree[2*i],tree[2*i+1]);
        }
    }

    T query(int l, int r) {
        T ansL = NEUTRAL , ansR = NEUTRAL;
        for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
            if (l&1) ansL = func(ansL,tree[l++]);
			      if (r&1) ansR = func(tree[--r],ansR);
        }
        return func(ansL, ansR);
    }
};
/*
  the tree is 0-indexed
  query the range [l, r], l and r are inclusive
  usage exemple:
  auto func = [&](int a, int b) -> int { return a+b;};
  SegmentTree<int> st(n,0,func);
*/
void solve(){
    int n,m;cin>>r>>n>>m;
    vector<item>v(n);
    for(int i=0;i<n;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        item it(a,b,c,d);
        v[i]=it;
    }
    item neutral(1,0,0,1);
    auto func = [&](item it1, item it2) -> item{
        item it;
        it.a=add(mul(it1.a,it2.a),mul(it1.b,it2.c));
        it.b=add(mul(it1.a,it2.b),mul(it1.b,it2.d));
        it.c=add(mul(it1.c,it2.a),mul(it1.d,it2.c));
        it.d=add(mul(it1.c,it2.b),mul(it1.d,it2.d));
        return it;
    };
    SegmentTree<item> st(n,neutral,func);
    for(int i=0;i<n;i++)st.update(i,v[i]);
    while(m--){
        int l,r;cin>>l>>r;
        l--;r--;
        item it=st.query(l,r);
        cout<<it.a<<" "<<it.b<<"\n"<<it.c<<" "<<it.d<<"\n\n";
    }
}
int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        //freopen("input.txt", "r",stdin);
        //freopen("output.txt", "w",stdout);
        int _=1;
        //cin >>_;
        //cout<<fixed<<setprecision(6);
        while(_--)solve();
}
