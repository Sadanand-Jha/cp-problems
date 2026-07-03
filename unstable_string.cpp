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
    string s;
    cin>> s;

    int n = s.length();

    int odd_one = -1;
    int question_mark = -1;

    int start = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != '?') {

            if(s[i] == '1') {
                if(odd_one == -1) {
                    odd_one = (i & 1);
                }
                if(odd_one != (i & 1)) {
                    //breaking point
                    int size = (i - start);
                    count += (size * (size + 1)) / 2;
                    if(question_mark != -1) {
                        count -= ((i - question_mark) * (i - question_mark + 1)) / 2;
                        start = question_mark;
                    }
                    else start = i;
                    odd_one = !odd_one;
                }
            }
            else{
                if(odd_one == -1) {
                    odd_one = !(i & 1);
                }
                if(odd_one == (i & 1)) {
                    //breaking point
                    int size = (i - start);
                    count += (size * (size + 1)) / 2;
                    if(question_mark != -1) {
                        count -= ((i - question_mark) * (i - question_mark + 1)) / 2;
                        start = question_mark;
                    }
                    else start = i;
                    odd_one = !odd_one;
                }
            }
            question_mark = -1;
        }
        else{
            if(question_mark == -1) {
                question_mark = i;
            }
        }
    }

    count += ((n - start + 1) * (n - start)) / 2;
    cout<< count<< endl;
 
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
