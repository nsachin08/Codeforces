//Problem Link - https://codeforces.com/problemset/problem/785/B
/* By Shark08*/
#include<bits/stdc++.h>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>*/
// using namespace __gnu_pbds;
using namespace std;

#define ll 					long long int
#define ld 					long double 
#define mod 				1000000007
#define inf 				1e9
#define endl 				"\n"
#define pb 					push_back
#define vi					vector<ll>
#define vs 					vector<ss>
#define pii					pair<ll,ll>
#define ump					unordered_map
#define mp 					make_pair 
#define pq_max				priority_queue<ll,ll>
#define pq_min				priority_queue<ll,vector<ll>,greater<ll> >
#define all(v)				v.begin(),v.end()
#define ff 					first
#define ss      			second
#define mid(l,r) 			(l+(r-l)/2)
#define bitc(x)				__buildtin_popcount(x)
#define loop(i,a,b)			for(int i=a ; i<=b ; i++)
#define looprev(i,a,b) 		for(int i=a;i>=b;i--)
#define iter(c,it)			for(__typeof(c.begin()) it =c.begin() ; it!=c.end();it++)
#define log(args...)		{string _s = #args; replace(_s.begin(), _s.end(), ',',' ' ); stringstream __ss(_s); istream_iterator<string> _it(__ss) ; err(_it, args); }		
#define logarr(arr,a,b)     for(int z=a;z<=b;z++) cout<<(arr[z])<<" "; cout<<endl;
template<typename T> T gcd(T a, T b){ if(a%b) return gcd(b, a%b) ; return b;}
template<typename T> T lcm(T a ,T b) { return (a*(b/gcd(a,b)));}

void err(istream_iterator<string> it){}
template <typename T,typename... Args>
void err (istream_iterator<string> it, T a, Args... args){
	cout<< *it <<" = "<< a << endl;
	err(++it,args...);
}
//
//

void file_i_o()
{    
	ios_base::sync_with_stdio(false);
	//untie
	cin.tie(0);
	cout.tie(0);
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll infinity = 1234567890;

int main(int argc, char const *argv[])
{
	/* code */
	clock_t begin = clock();
	file_i_o();
	ll n,m,a,b;
	cin>>n;
	vector<pair<ll,ll>> C(n);
	loop(i,0,n-1)
	{
		cin>>a>>b;
		C[i]={a,b};
	}
	cin>>m;
	vector<pair<ll,ll>> P(m);
	loop(i,0,m-1)
	{
		cin>>a>>b;
		P[i]={a,b};
	}
	ll minR1= infinity , maxL1 = -infinity;
	ll minR2= infinity , maxL2 = - infinity;
	loop(i,0,n-1)
	{
		maxL1 = max(maxL1,C[i].first);
		minR1 = min(minR1,C[i].second);
	}

	loop(i,0,m-1)
	{
		maxL2 = max(maxL2,P[i].first);
		minR2 = min(minR2 , P[i].second);
	}

	ll res = max(maxL2 - minR1 , maxL1 - minR2);
	cout<<max(res,(ll)0)<<endl;
	

	#ifndef ONLINE_JUDGE
		clock_t end= clock();
		cout<<"\n\n\nExecuted In:"<< double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif
	return 0;
}