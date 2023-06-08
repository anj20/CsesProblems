//Link:-
//....................AUTHOR:-Anurag
 
#include <bits/stdc++.h>

using namespace std;

//bultin functions
#define setbits(x) __builtin_popcountll(x) ///No of set bits 
#define tzrobits(x) __builtin_ctz(x) ///Trailing zeros 
#define lzrobits(x) __builtin_clz(x) ///Leading zeros 
#define lastset(x)   __builtin_ffs(x) //last set bit position(1-based)
 
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define arrmin(x) *min_element(all(x))
#define arrmax(x) *max_element(all(x))
#define arrsum(x) accumulate(all(x), 0LL)
#define arrpre(x) partial_sum(all(x), x.begin())
#define arrsuf(x) partial_sum(allr(x), x.rbegin()) 
#define len(x) (int) (x).size()
#define pb push_back
#define eb emplace_back
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define strline(s)               \
    string s;                      \
    getline(cin, s);               \
    if (s == "" || s == "\n") \
      getline(cin, s);
#define ft first
#define sc second
#define line cout<<'\n'
#define precise(digits) fixed << setprecision(digits)
 
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
#define smallerthan(x) order_of_keys(x)
#define index(x) find_by_order(x);


template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

ll MOD = 1e9 + 7;//1e9-7
const ll inf = 1e18;
const int N = 200007;
const double PI =  acos(-1.0);

vector<vll>adj(N);
vll vis(N,0);
vector<vll>adj_rev(N);

vll components;
vll component(N);
vll coins(N);
stack<ll> S;
void dfs_1(ll node) 
{
  vis[node] = 1;
  for (auto child:adj[node]) if (!vis[child]) dfs_1(child);
  S.push(node);
}
void dfs_2(ll node,ll par) 
{
  component[node] = par;
  vis[node] = 1;
  for (auto child:adj_rev[node])if (!vis[child]) dfs_2(child,par);
}
void Kosaraju(int n) 
{
  for (int i = 1; i <= n; i++)if (!vis[i]) dfs_1(i);

  for (int i = 1; i <= n; i++)vis[i] = 0;

  while (!S.empty()) 
  {
    int node = S.top();
    S.pop();
    if (!vis[node]) 
    {
      components.pb(node);
      dfs_2(node,node);
    }
  }
} 
vector<vll>condensed(N);
vll dp(N,-1);
vll val(N,0);

ll dfs(int root)
{
   vis[root]=1;
   ll coin=val[root];
   for(auto child:condensed[root])
   {
      if(vis[child])continue;
      coin=max(coin,val[root]+dfs(child));
   }
   return dp[root]=coin;
}

void soln()
{
	ll n;cin>>n;
	ll m;cin>>m;
  for (int i = 1; i < n+1; ++i)cin>>coins[i];
	while(m--)
	{
		ll x;cin>>x;
		ll y;cin>>y;
		adj[x].pb(y);
		adj_rev[y].pb(x);
	}
	Kosaraju(n);


  for (int i = 1; i < n+1; ++i)
  {
      val[component[i]]=(ll) val[component[i]]+coins[i];
      for(auto child:adj[i])
      {
          if(component[i]==component[child])continue;
          condensed[component[i]].pb(component[child]);
      }
  } 


  fill(all(vis),0);
  for(auto it:components)
  {
    if(vis[it])continue;
    dfs(it);
  }

  ll maxicoins=0;
  for(auto it:components)maxicoins=max(maxicoins,dp[it]);
  cout<<maxicoins;
}   
 
int main()
{
    int tt;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    tt=1;
    // cin>>tt;
    //int p=1;

    while(tt--)
    {
        //cout<<"Case #"<<p<<": ";
        soln();  
        //p++;
        line;
    }
    return 0;
}