//Problem Link - https://codeforces.com/problemset/problem/558/A
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

int main(int argc, char const *argv[])
{
	/* code */
	clock_t begin = clock();
	file_i_o();
	ll n,x,y;
	vector<pair<ll,ll>> P,N;
	cin>>n;
	loop(i,0,n-1)
	{
		cin>>x>>y;
		if(x < 0) N.pb({x,y});
		else
		{
			P.pb({x,y});
		}
	}
	if(P.size() > 0)
	{
		sort(P.begin(),P.end());
	}
	if(N.size() > 0)
	{
		sort(N.begin(),N.end(),greater<pair<ll,ll>>());
	}
	ll res=0;
	// cout<<P.size()<<" "<<N.size()<<endl;
	if(P.size() == N.size())
	{
		loop(i,0,P.size()-1)
		{
			res += (P[i].second + N[i].second);
		}
	}
	else if(P.size() >N.size())
	{
		for(ll i =0 ; i < N.size();i++)
		{
			res += (P[i].second + N[i].second);
		}

		res+= P[N.size()].second;
	}
	else
	{
		
		for(ll i =0 ; i < P.size();i++)
		{
			res += (P[i].second + N[i].second);
		}
		res += N[P.size()].second;
	}

	cout<<res<<endl;



	#ifndef ONLINE_JUDGE
		clock_t end= clock();
		cout<<"\n\n\nExecuted In:"<< double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif
	return 0;
}