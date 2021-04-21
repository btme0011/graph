template<typename T>
struct scc{
	vector<bool> vis;
	vector<vector<T>> last;// final ans all the strongly connected component
	scc(T n,vector<vector<T>> edge1,vector<vector<T>> edge2){// no of nodes , edge , reverse of edge
		vis=vector<bool>(n+1);
		solve(n,edge1,edge2);
	}
	
	stack<ll> st;
	void dfs1(T node,vector<vector<ll>> edge){
		vis[node]=1;
		for(ll x:edge[node]){
			if(vis[x]==0) dfs1(x,edge);
		}
		st.push(node);
	}

	vector<ll> ans;
	void dfs2(T node,vector<vector<T>> edge){
		//deb(node);
		vis[node]=1;
		ans.push_back(node);
		for(ll x:edge[node]){
			if(vis[x]==0) dfs2(x,edge);
		}
	}

	void solve(T n,vector<vector<T>> edge1,vector<vector<T>> edge2){


		for(int i=0;i<n;i++)
			if(visited.count(i)==0)
				dfs1(i,edge1);

		for(auto &x:vis) x=0;
		
		while(!st.empty()){
			while(vis[st.top()]!=0) st.pop();
			dfs2(st.top(),edge2);
			last.push_back(ans);
			ans.clear();
		}
	}
}
