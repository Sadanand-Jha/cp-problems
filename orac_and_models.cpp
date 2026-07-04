#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
typedef vector<string> vs;

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

// ==========================================
// PBDS: Ordered Set & Ordered Multiset
// ==========================================
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Use pair<T, int> instead of T to implement multiset safely, or use less_equal<T> like below:
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Methods:
// st.find_by_order(k)  --> returns iterator to k-th largest element (0-indexed)
// st.order_of_key(k)   --> returns number of elements strictly smaller than k

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
// void _print(int t) {cerr << t;}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template<class T, class V>
void _print(pair<T, V> p);

template<class T>
void _print(vector<T> v);

template<class T>
void _print(set<T> v);

template<class T, class V>
void _print(map<T, V> v);

template<class T>
void _print(multiset<T> v);

template<class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}

template<class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template<class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template<class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template<class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// PBDS Debug Print support
template<class T>
void _print(ordered_set<T> v) {
    cerr << "[ ";
    for (T i: v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void solve() {
    int count = 0;
    int n;
    cin >> n;
    vi vec(n);
    vi dp(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        int maxval = 0;
        for(int u = 2 * (i + 1) - 1; u < n; u += (i + 1)) {
            if(vec[u] > vec[i]) {
                maxval = max(maxval, dp[u]);
            }
        }

        dp[i] = maxval + 1;
    }

    for(auto it: dp) {
        count = max(it, count);
    }
    cout<< count<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}