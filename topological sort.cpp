template<typename T>
struct ts{
	T N;
	vector<bool> visited;
	vector<ll> last;// final ans;
	ts(T n,vector<vecto<T>> edge){// no of nodes, edge
		N=n;
		visited=vector<bool>(n+1);
		solve(n,edge);
	}
	
	
	void dfs(ll node,vector<vector<ll>> edge,vector<bool> vis,stack<ll> &ans){
		visited[node]=1;
		for(auto x:edge[node]){
			if(visited[x]==0) dfs(x,edge,vis,ans);
		}
		ans.push(node);
	}
	void solve(T n,vector<vector<T>> edge){


		fo(i,n){
			visited[i]=0;
		}

		vector<bool> vis(n+1);
		stack<ll> ans;
		
		for(int i=0;i<n;i++){
			if(visited[i]==0){
				dfs(i,edge,vis,ans);
			}
		}
		while(!ans.empty()) {last.push_back(ans.top());ans.pop();}
		
	}
};
