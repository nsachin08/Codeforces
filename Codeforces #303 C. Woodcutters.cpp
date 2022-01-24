//Problem Link - https://codeforces.com/contest/545/problem/C
/* By Shark08
	C. WoodCutters Codeforces #303 
*/
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

	/*
		There are 3 option for a tree:
		Option 0 : Fall Left;
		Option 1 : Stand Still;
		Option 2 : Fall Right;
		Total Option : 3  , make dp[n][3] : n -> number of trees;

	*/
	ll n;
	cin>>n;
	ll dp[n][3];
	vector<pair<ll,ll>> Arr(n);
	loop(i,0,n-1) // input taken;
	{
		cin>>Arr[i].first;
		cin>>Arr[i].second;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1 ;// 0th tree is made to fall left , hence total number of tree fell till 0th index is 1;
	dp[0][1] = 0 ; // 0th tree is not made to fall , hence total number of tree fel till 0th index is 0;
	dp[0][2] = 0;
	if((Arr[0].first + Arr[0].second < Arr[1].first &&  n >1 ) || n ==1) // 0th tree can be made to fall right ,
	{
		dp[0][2] = 1;
	}
	ll tmp = 0;
	loop(i,1,n-1)
	{
		tmp = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2])); // get maximum till now;
		dp[i][1] = tmp ; // if the current tree is not cut, then total umbe rof tree till i-1th will same as ith;
		if(Arr[i].first - Arr[i].second > Arr[i-1].first) // if current tree is made to fall left;
		{
			if(Arr[i].first - Arr[i].second > Arr[i-1].first + Arr[i-1].second) // if the previous tree is made to fall right;
			{
				dp[i][0] = 1+ tmp;  // take the maximum from previous and add 1 for current ;
			} 
			else
			{
				dp[i][0] = 1 + max(dp[i-1][1],dp[i-1][0]) ; // take max when previous is made to fell left or still;
			}
		}

		if( i == n-1 || Arr[i].first + Arr[i].second < Arr[i+1].first) // if the current tree is made to fall right , then no harm for previous situation , hence max from previous +1 
		{
			dp[i][2] = tmp +1;
		}

	}

	cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	#ifndef ONLINE_JUDGE
		clock_t end= clock();
		cout<<"\n\n\nExecuted In:"<< double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif
	return 0;
}
