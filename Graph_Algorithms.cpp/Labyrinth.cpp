// Vidur Goel

//Codeforcees Handle: Vidurcodviz
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;

#define make_it_fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define nn endl

string yup="YES";
string nope="NO";
signed main(){
    make_it_fast();
    int n,m;
    cin>>n>>m;
    vector<vector<int> > arr(n,vector<int>(m));
    char a;
    pair<int,int> src=mp(0,0);
    pair<int,int> dest=mp(0,0);
    rep(i,0,n){
        rep(j,0,m){
            cin>>a;
            if(a!='#'){
                arr[i][j]=1;
            }
            else{
                arr[i][j]=0;
            }
            if(a=='A'){
                src.ff=i;
                src.ss=j;
                arr[i][j]=0;
            }
            if(a=='B'){
                dest.ff=i;
                dest.ss=j;
            }
        }
    }
    string t="";
    queue<pair<pair<int,int>,string> > q;
    q.push(mp(src,t));
    while(!q.empty()){
        int n1=q.size();
        rep(k,0,n1){
            pair<int,int> node=q.front().ff;
            string s=q.front().ss;
            q.pop();
            if(node==dest){
                cout<<yup<<nn;
                cout<<s.size()<<endl;
                cout<<s<<endl;
                return 0;
            }
            else{
                int i=node.ff;
                int j=node.ss;
                if(i+1<n && arr[i+1][j]==1){
                    s.pb('D');
                    q.push(mp(mp(i+1,j),s));
                    s.pop_back();
                    arr[i+1][j]=0;
                }
                if(j+1<m && arr[i][j+1]==1){
                    s.pb('R');
                    q.push(mp(mp(i,j+1),s));
                    s.pop_back();
                    arr[i][j+1]=0;
                }
                if(i-1>=0 && arr[i-1][j]==1){
                    s.pb('U');
                    q.push(mp(mp(i-1,j),s));
                    s.pop_back();
                    arr[i-1][j]=0;
                }
                if(j-1>=0 && arr[i][j-1]==1){
                    s.pb('L');
                    q.push(mp(mp(i,j-1),s));
                    s.pop_back();
                    arr[i][j-1]=0;
                }
            }
        }
    }
    cout<<nope<<nn;
    return 0;
}