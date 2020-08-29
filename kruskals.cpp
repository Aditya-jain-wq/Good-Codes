/*
You are given an undirected connected graph with n vertices and m edges 
numbered from 1 to m. You have to apply Kruskal's algorithm for finding 
the Minimum Spanning Tree in G. Every second you add 1 edge to 
the spanning tree and thus complete the process in n - 1 seconds. 
Initially at t=0 there is no edge in the tree. You are given Q queries 
each having a time t. Your task it to output the edge number which was 
added during the t th second.

*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define f(i,n) for(int i=0;i<n;i++)
#define fo(i,s,n) for(int i=s;i<n;i++)
#define trav(a,x) for(auto& a : x)
#define nl "\n"
#define F first
#define S second
#define pb push_back
#define test() int t;cin>>t;while(t--)
#define deb(x) cout<<#x<<" : "<<x<<endl
#define o2(a,b) cout<<a<<" "<<b<<"\n"
#define o3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
typedef pair<int,int> pii;
typedef long long ll;
//void sieve(int n, vector<bool> &isprime){isprime[0] = isprime[1] = false;for(int i = 2; i*i < n; i++)if(isprime[i] == true)for(int j = i*i; j <= n; j+=i)isprime[j] = false;}
//int remove_first(int num){return num%(static_cast<int>(pow(10, static_cast<size_t>(log10(num)))));}

struct edge{
	int u;
	int v;
	int w;
	int index;
};

int findParent(int vertex, int parent[]){
	if(parent[vertex] == vertex)
		return vertex;
	return parent[vertex] = findParent(parent[vertex], parent);
}

int main(){
	fastio;
	// #ifndef ONLINE_JUDGE 
	// freopen("input.txt", "r", stdin); 
	// freopen("output.txt", "w", stdout); 
	// #endif
	test(){
		int n, m, q;
		cin>>n>>m>>q;
		int parent[n+1] = {0};
		iota(parent+1, parent+n+1, 1); // parent[i] = i
		edge edges[m];
		f(i,m){
			cin>>(edges[i].u)>>(edges[i].v)>>(edges[i].w);
			edges[i].index = i+1;
		}
		sort(edges, edges+m, [](const edge &a, const edge &b)->bool{
			return a.w < b.w;
		});
		vector<int> ans;
		ans.reserve(n-1);
		for(int i = 0; ans.size() < n-1; i++){
			if(findParent(edges[i].u, parent) != findParent(edges[i].v, parent)){
				ans.push_back(edges[i].index);
				parent[findParent(edges[i].u, parent)] = findParent(edges[i].v, parent);
			}
		}
		int i = 0;
		while(q--){
			cin>>i;
			cout<<ans[i-1]<<nl;
		}
	}
    return 0;
}
// read question correctly (ll vs int)(any * or + do overflow)