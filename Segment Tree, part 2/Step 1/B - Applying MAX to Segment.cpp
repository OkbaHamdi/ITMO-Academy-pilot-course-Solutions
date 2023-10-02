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
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pl;
#define         ordered_set tree<int, null_type,less<int>, rb_tree_tag,tre
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
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
//const           ll MOD = LLONG_MAX;
//const           int MOD = 998244353;
const           int MOD=1000000007;
const           ld eps=1e-7;
const           double PI=acos(-1);
const           int N=2e5+5;
const           ll INF=1e18;
const           int L = log2(N)+1;
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
        tree.resize(n*2,NEUTRAL);
    }
    void update(int l,int r, T value) {
        for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
            if (l&1)tree[l]=func(value,tree[l]),l++;
            if (r&1)tree[r-1]=func(value,tree[r-1]),r--;
        }
    }

    T query(int i) {
        i+=n;
        T ans = NEUTRAL;
        while(i){
            ans=func(tree[i],ans);
            i>>=1;
        }
        return ans;
    }
};
/*
  the tree is 0-indexed
  query the range [l, r], l and r are inclusive
  usage exemple:
  auto func = [&](ll a, ll b) -> ll { return a+b;};
  SegmentTree<ll> st(n,0,func);
*/
void solve(){
    int n,q;cin>>n>>q;
    auto func = [&](ll a, ll b) -> ll { return max(a,b);};
    SegmentTree<ll>st(n,0,func);
    while(q--){
        ll test;cin>>test;
        if(test==1){
            ll l,r,v;cin>>l>>r>>v;
            r--;
            st.update(l,r,v);
            continue;
        }
        ll i;cin>>i;
        cout<<st.query(i)<<endl;
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
