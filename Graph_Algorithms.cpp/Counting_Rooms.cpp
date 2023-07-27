// Vidur Goel

//Codeforcees Handle: Vidurcodviz
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;

#define make_it_fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rept(i, a, n) for (ll i = (a); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define sorr(x) sort(x.rbegin(),x.rend()) // this is in order to do sorting in descending order
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462
#define mset multiset<ll> // it contains multiple instances of the same value in ascending order
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repd(i,a,b) for(ll i=b-1;i>=a;i--)
#define nn endl
#define setbits(n) __builtin_popcount(n)

string yup="YES";
string nope="NO";
ll fibonacci(ll n){ll a=0;ll b=1;ll c;if(n==0 || n==1){return n;}for(ll i=2;i<n+1;i++){c=a+b;a=b;b=c;}return c;}
void rev(vl &arr,ll n){rep(i,0,n){cin>>arr[i];}return;}
void prv(vl arr){rep(i,0,arr.size()){cout<<arr[i]<<" ";}cout<<nn;return;}

struct dsu{
    vl parent;
    vl size;
    
    dsu(ll n){
        size.resize(n+1);
        parent.resize(n+1);
        rep(i,0,n+1){
            make_set(i);
        }
    }

    void make_set(ll v){
        parent[v]=v;
        size[v]=1;
    }

    ll find_set(ll v){
        if(v==parent[v]){
            return v;
        }
        else{
            return parent[v]=find_set(parent[v]);
        }
    }
    void union_set(ll a,ll b){
        a=find_set(a);
        b=find_set(b);
        if(a==b){
            return;
        }
        else{
            if(size[a]>=size[b]){
                parent[b]=a;
                size[a] += size[b];
            }
            else{
                parent[a]=b;
                size[b] += size[a];
            }
        }
    }
};

void dfs(ll i,ll j,ll n,ll m,vvl & arr){
    if(i<0 || j<0 || i>n-1 || j>m-1){
        return;
    }
    else{
        if(arr[i][j]==1){
            arr[i][j]=0;
            dfs(i+1,j,n,m,arr);
            dfs(i,j+1,n,m,arr);
            dfs(i-1,j,n,m,arr);
            dfs(i,j-1,n,m,arr);
        }
    }
}

signed main(){
    make_it_fast();
    ll n,m;
    cin>>n>>m;
    vvl arr(n,vl(m));
    char a;
    rep(i,0,n){
        rep(j,0,m){
            cin>>a;
            arr[i][j]=(a=='.');
        }
    }
    ll count=0;
    rep(i,0,n){
        rep(j,0,m){
            if(arr[i][j]==1){
                dfs(i,j,n,m,arr);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}