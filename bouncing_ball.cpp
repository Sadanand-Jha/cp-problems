#include<bits/stdc++.h>
using namespace std;
 
#define int long long
typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef stack<int> sti;
typedef queue<int> qi;
typedef vector<pair<long, long> > vpll;
 
 
#define endl "\n"
#define Ft front
#define Bk back
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
 
const ll MOD = 1e9 + 7;
 
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
 
 
 
 
void solve() {
    int count = 0;
    int n;
    cin>>n;
    int p, k;
    cin>> p>> k;
    string s;
    cin>> s;
    int x, y;
    cin>> x>> y;

    p--;

    vi dp(n, LLONG_MAX);
    
    int answer = LLONG_MAX;
    for(int i = p; i < p + k; i++) {
        vc vec;
        int cost = (i - p) * y;

        for(int j = 0; j * k + i < n; j++) {
            vec.push_back(s[i + j * k]);
        }

        vi cost_vec(vec.size(), 0);

        for(int k = 0; k < vec.size(); k++){
            if(vec[k] == '0') {
                cost_vec[k] = x;
            }
        }

        for(int k = cost_vec.size() - 2; k >= 0; k--) {
            cost_vec[k] = cost_vec[k + 1] + cost_vec[k];
        }

        for(int j = 0; j < vec.size(); j++) {
            dp[j * k + i] = cost_vec[j];
        }
    }

    // for(auto it: dp) {
    //     cout<< it << ' ';
    // }
    // cout<< endl;

    // for(int i = 0; i < n; i++) {
    //     cout<< dp[i]<< ' '<< i<< endl;
    // }

    for(int i = 0; i < n - p; i++) {
        // cout<< "this is i "<< i<<endl;
        // cout<< " this is first jump " << i + p<< ' ';        
        int cost = i * y;
        if(dp[i + p] == LLONG_MAX) continue;
        cost += dp[p + i];
        // if(i == 1) {
            // cout<< endl;
            // cout<< "this is cost "<< cost << ' ';
            // cout<< "this is dp"<< dp[i + p]<< '\n';
        // }
        // cout<< cost<< ' ';
        answer = min(answer, cost);
    }
    cout<< answer<<' ';
    cout<< endl;
 
}
 
 
 
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
