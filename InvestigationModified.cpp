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

// vector<vll>adj(N);
vll vis(N,0);   
// vector<vi> dp(N+1,vi(N+1,0)); 

vector<vector<pll>>adj(N);
set <pll> S;
ll d[N], path[N];
int nominroutes[N];
int minflights[N],maxflights[N];
ll binpow(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll invprime(ll a, ll b) {return binpow(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, invprime(b, m), m) + m) % m;} 
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))



void dijkstra(ll src)
{
    for (int node = 1; node <= N; node++)
    {
        d[node] = inf;
        nominroutes[node]=0;
        minflights[node]=INT_MAX;
        maxflights[node]=INT_MIN;
    }
    nominroutes[src]=1;
    minflights[src]=0;
    maxflights[src]=0;
    d[src] = 0;
    S.insert({d[src], src}); // dis,node
    while (!S.empty())
    {
        int node = S.begin()->second; S.erase(S.begin());

        for (auto child:adj[node])
        {
            ll adjNode = child.ft, edgeLength = child.sc;
            if (d[adjNode] > d[node] + edgeLength)
            {

                S.erase({d[adjNode], adjNode});
                d[adjNode] = d[node] + edgeLength, path[adjNode] = node;
            	nominroutes[adjNode]=nominroutes[node];
                minflights[adjNode]=minflights[node]+1;
                maxflights[adjNode]=maxflights[node]+1;
                S.insert({d[adjNode], adjNode});
            }
            else if(d[adjNode] == d[node] + edgeLength)
            {
            	nominroutes[adjNode]=mod_add(nominroutes[node],nominroutes[adjNode],MOD);
            	minflights[adjNode]=min(minflights[node]+1,minflights[adjNode]);
            	maxflights[adjNode]=max(maxflights[node]+1,maxflights[adjNode]);
            }
        }
    }
}

void soln()
{
	ll n;cin>>n;
	ll m;cin>>m;
	while(m--)
	{
		ll a;cin>>a;
		ll b;cin>>b;
		ll w;cin>>w;
		adj[a].pb({b,w});
	}

	dijkstra(1);

	cout<<d[n]<<' '<<nominroutes[n]<<' '<<
		minflights[n]<<' '<<maxflights[n];
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