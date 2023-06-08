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
const int N = 1000007;
const double PI =  acos(-1.0);

// vector<vll>adj(N);
// vll vis(N,0);   
// vector<vi> dp(N+1,vi(N+1,0));

ll gcd(ll a, ll b)
 {
     if (a == 0)
         return b;
     return gcd(b % a, a);
 }
 ll gcdExtended(ll a, ll b, ll *x, ll *y)
 {
     if (a == 0)
     {
         *x = 0;
         *y = 1;
         return b;
     }
  
     ll x1, y1; 
     int gcd = gcdExtended(b%a, a, &x1, &y1);
  
     *x = y1 - (b/a) * x1;
     *y = x1;
  
     return gcd;
 } 
ll binpow(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll invprime(ll a, ll b) {return binpow(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, invprime(b, m), m) + m) % m;} 
ll mod_inv(ll A, ll M){ll x, y;ll g = gcdExtended(A, M, &x, &y);if (g != 1)return -1;   else{ll res = (x % M + M) % M;return res;}}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll lcm(ll a,ll b){return a*b/(gcd(a,b));}


void swap(ll &a, ll &b){a=a^b;b=a^b;a=a^b;}
 //Seive of Erathanus
bool sieve[N + 1];void createSieve(){for (ll i = 2; i < N + 1; i++)sieve[i] = true;for (ll i = 2; i * i <= N; i++)if (sieve[i])for (ll j = i * i; j <= N; j += i)sieve[j] = false;}
 // Factorial
ll fact[N],invFact[N];void precompute_fact(){fact[0] = 1,invFact[0]=1;for (ll i = 1; i < N; i++)fact[i] = (fact[i - 1] * i) % MOD,invFact[i]=invprime(fact[i],MOD);}
 // Prime Divisors of a no. 
vll primeDiv;void addPrimes(ll n){for (ll i = 2; i * i <= n; i++) if (n % i == 0){while (n % i == 0)n /= i;primeDiv.pb(i);}if (n > 1)primeDiv.pb(n);} 
 // Divisors of a no. 
vll Div;void addDivisors(ll n) {for (ll i = 1; i * i <= n; i++)if (n % i == 0){Div.pb(i);if (i * i != n)Div.pb(n / i);}}

ll nc2(ll n,ll r)
{
	ll ans=mod_mul(mod_mul(fact[n],invFact[r],MOD),invFact[n-r],MOD);
	return ans;
}

void soln()
{
	ll n;cin>>n;
	string s;cin>>s;
	ll open=0;
	for(auto it:s)
	{
		open+=(it=='('?1:-1);
		if(open<0){cout<<0;return;}
	}
	n-=len(s);
	if(open<0 or open>n or (n-open)&1){cout<<0;return;}	
	if(n==0){cout<<1;return;}
	ll closeB=open+(n-open)/2;
	ll ans=mod_sub(nc2(n,closeB),nc2(n,closeB+1),MOD);
	cout<<ans;
}   
 
int main()
{
    int tt;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    tt=1;
    precompute_fact();
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