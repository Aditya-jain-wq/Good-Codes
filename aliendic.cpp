#include <bits/stdc++.h>
using namespace std;

string printOrder(string dict[], int N, int k){
	vector<int> adj[k];
	for(int i=1;i<N;i++){
		string word1 = dict[i-1], word2 = dict[i];
		for(int j=0;j<min(word1.size(),word2.size());j++){
			if(word1[j] != word2[j]){
				adj[word1[j]-'a'].push_back(word2[j]-'a');
				break;
			}
		}
	}

	bool visited[k];
	for(int i=0;i<k;i++)visited[i]=false;
	stack<int> st;
	
	auto topologicalSort = [](stack<int> &st, bool visited[], vector<int> adj[],int &v, const auto topologicalSort) -> void {
		visited[v] = true;
		for(auto adjacentVer : adj[v]){
			if(!visited[adjacentVer])
				topologicalSort(st, visited, adj, adjacentVer, topologicalSort);
		}
		st.push(v);
	};

	for(int i=0;i<k;i++)
		if(!visited[i])topologicalSort(st, visited, adj, i, topologicalSort);

	string ans = "";
	while(!st.empty()){
		ans+=(char)(st.top()+'a'); //O(1)
		st.pop();
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s[n];
		for(int i=0;i<n;i++)cin>>s[i];
		cout<<printOrder(s,n,k);
	}
    return 0;
}