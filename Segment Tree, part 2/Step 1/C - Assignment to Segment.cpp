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
struct item{
    int ind,val;
    item(int i=0,int v=0){
        ind=i;
        val=v;
    }
};
item neutral;
template <typename T>
class SegmentTree {
    T NEUTRAL;
    int n;
    vector<T> tree;
public:
    SegmentTree(int sz,T neutral){
        NEUTRAL = neutral;
        n = (1 << (32 - __builtin_clz(sz)));
        tree.resize(n*2,NEUTRAL);
    }
    void update(int l,int r, T value) {
        for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
            if (l&1)tree[l]=value,l++;
            if (r&1)tree[r-1]=value,r--;
        }
    }

    T query(int i) {
        i+=n;
        T ans = NEUTRAL;
        ans.ind=-1;
        while(i){
            if(tree[i].ind>ans.ind)ans=tree[i];
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
    SegmentTree<item>st(n,neutral);
    for(int i=1;i<=q;i++){
        int test;cin>>test;
        if(test==1){
            int l,r,v;cin>>l>>r>>v;
            r--;
            item it(i,v);
            st.update(l,r,it);
            continue;
        }
        int a;cin>>a;
        item ans=st.query(a);
        cout<<ans.val<<endl;
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
