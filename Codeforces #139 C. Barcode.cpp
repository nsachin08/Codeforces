//Problem Link - https://codeforces.com/contest/225/problem/C
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
	/* 
	
  1.	calculate the number the white pixels in each column , it will help in finding out the number of pixels to be changed accordingly.
  2.    there are two options to colour each column enitrely 
         -> colour White :
         -> colour Black :
         Total Options : 2
         Hence dp[2][m] : m is the number of columns , n is the number of rows;

         now , dp[0][k] = number of pixels to be changed if we colour kth column with white;
         	There is a constraints that the width of the pixels column wise should be between [x,y];
         	hence from .  (k-j, k) must be white competelly , where j =[x,y];
         	Hence , dp[0][k] = min ( from all such segments when they are marked as white so = dp[1][k-j] + preBlack[i]-PreBlack[i-j]);
         	Similarly for,

         	dp[1][k] = number of pixels to be changed if we colour kth column with black,
         	(K-J,K) must be black .  where j = [x,y];
         	Hence , dp[1][k] = min (from all segement when they are marked as balck so = dp[0][k-j]+ preWhite(k)-prewhite(k-j));

         	For example:
         	      x,y=[3,6]; it menas the width of the same coloured pixels must be in range 2,6;
					
				    diff =2	
				   ||	
         	      .##.#
         	      .##.#
         	      .##.#   // this doesn;t satisfy because , width is only 2 max and we required atleast 3;
				  .##.#
         	      .##.#


         	      ...####......####
         	      ...####......####
         	      ...####......####
         	      ...####......####
				  ...####......####   // this is valid , width are = {3,4,6,4} , 3 whites , 4 blacks,6 whites,4 balcks, 
         	      ...####......####
	
	 */
	clock_t begin = clock();
	file_i_o();
	ll m,n,x,y;
	cin>>m>>n>>x>>y; 
	vector<vector<char>> Arr(m , vector<char> (n));
	vector<ll> Count_White(n+1,0);
	vector<ll> Count_Black(n+1,0);

	loop(i,0,m-1)
	{
		loop(j,0,n-1)
		{
			cin>>Arr[i][j];
			if(Arr[i][j] == '.')
			{
				Count_White[j+1]++;
			}else
			{
				Count_Black[j+1]++;
			}
		}
	}

	loop(i,1,n)
	{
		Count_Black[i] += Count_Black[i-1];
		Count_White[i] += Count_White[i-1]; 
	}

	ll dp[2][n+1];
	dp[0][0]=0;
	dp[1][0]=0;

	loop(i,1,n)
	{
		ll mn1 = INT_MAX;
		ll mn2 = INT_MAX;

		loop(j,x,y)
		{
			if(i-j >=0)
			{
				mn1 = min(mn1 , dp[0][i-j] + Count_White[i] - Count_White[i-j]); // colour it black
				mn2 = min(mn2, dp[1][i-j] + Count_Black[i] - Count_Black[i-j]);
			}
		}

		dp[0][i] = mn2;
		dp[1][i] = mn1;

	}

	cout<< min (dp[0][n] , dp[1][n])<<endl;


	#ifndef ONLINE_JUDGE
		clock_t end= clock();
		cout<<"\n\n\nExecuted In:"<< double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif
	return 0;
}	
