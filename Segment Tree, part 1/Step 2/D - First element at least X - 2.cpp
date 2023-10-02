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
  auto func = [&](ll a, ll b) -> ll { return a+b;};
  SegmentTree<ll> st(n,0,func);
*/
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    auto func = [&](int a, int b)->int{return max(a,b);};
    SegmentTree<int>st(n,-1,func);
    for(int i=0;i<n;i++)st.update(i,v[i]);
    while(m--){
        int test;cin>>test;
        if(test==1){
            int i,a;cin>>i>>a;
            st.update(i,a);
            continue;
        }
        int pos,k;cin>>k>>pos;
        int l=pos,r=n-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            int a=st.query(pos,mid);
            if(a>=k){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        cout<<ans<<endl;
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
