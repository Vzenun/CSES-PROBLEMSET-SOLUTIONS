// Vidur Goel

//Codeforcees Handle: Vidurcodviz

#include<iostream>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
#include<chrono>
#include<random>
#include<cassert>
#include<array>
#include<bitset>
#include<complex>
#include<cstring>
#include<functional>
#include<iomanip>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<utility>
#include<string_view>
#include<deque>
#include<iterator>
#include<sstream>

using namespace std;
using namespace chrono;

void solve_array();
void solve_single();
void solve_mul();

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

ll lmin(vl arr){return *min_element(arr.begin(),arr.end());}
ll lmax(vl arr){return *max_element(arr.begin(),arr.end());}

ll fibonacci(ll n){ll a=0;ll b=1;ll c;if(n==0 || n==1){return n;}for(ll i=2;i<n+1;i++){c=a+b;a=b;b=c;}return c;}

ll sum(vl a){ll sum=0;rep(i,0,a.size()){sum+=a[i];}return sum;}
void rev(vl &arr,ll n){rep(i,0,n){cin>>arr[i];}return;}
void prv(vl arr){rep(i,0,arr.size()){cout<<arr[i]<<" ";}cout<<nn;return;}

ll dp(vl arr,ll n,ll sum){
    if(n==0){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(sum<0){
            return 0;
        }
        else if(sum==0){
            return 1;
        }
        else{
            if(sum-arr[n-1]>=0){
                return dp(arr,n-1,sum-arr[n-1])+dp(arr,n-1,sum);
            }
            else{
                return dp(arr,n-1,sum);
            }
        }
    }

}

void solve_array(){
    ll n,sum;
    cin>>n>>sum;
    vl arr(n,0);
    rev(arr,n);
    sor(arr);
    cout<<dp(arr,n,sum)<<nn;
}

void solve_graph(){
    ll n,m;
    cin>>n>>m;
    vl a;
    vvl arr(n,a);
    rep(i,0,m){
        ll x,y;
        cin>>x>>y;
        arr[x-1].pb(y);
        arr[y-1].pb(x);
    }
}

signed main(){
    make_it_fast();
    //seive();
    //solve_mul();
    solve_array();
    //solve_single();
    //solve_graph();
    return 0;
}