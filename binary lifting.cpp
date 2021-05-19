template<typename T>
struct lca{
	T N;
	vector<vector<T>> dp;
	vector<T> depth;
	T ans; // get the answer
	
	T find(T p,T q){// get the answer
		T l1=depth[p];
		T l2=depth[q];

		if(l1<l2) {swap(l1,l2);swap(p,q);}// l1 should be greater

		T d=l1-l2; // difference

		while(d>0){
			T i=log2(d);
			p=dp[p][i];
			d-=(1<<i);
		}
		
		if(p==q) return p;
		
		
		for(int i=log2(N);i>=0;i--){
			if(dp[p][i]!=-1 and dp[p][i]!=dp[q][i]){
				p=dp[p][i];
				q=dp[q][i];
			}
		}
		return dp[p][0];
	}
	
	lca(T sz,vector<vector<T>> e,T start){//no of nodes, edge, starting node
		N=sz;
		dp=vector<vector<T>>(sz,vector<T>(log2(sz)+1));//N is no of nodes
		depth=vector<T>(sz);// depth of each node
		solve(start,e);
	}
	
	set<ll> vis;
	void dfs(int node,vector<vector<T>> edge,T par,T dep){ // to fill the first col of DP and depth of each node
		dp[node][0]=par;
		depth[node]=dep;
		vis.insert(node);
		for(int x:edge[node]){
			if(vis.count(x)==0)
				dfs(x,edge,node,dep+1);
		}
	}

	 void solve(T start,vector<vector<T>> edge){
		dfs(start,edge,-1,0);
		for(int i=1;i<log2(N);i++){// to fill remainin cells of dp
			for(int j=0;j<N;j++){
				if(dp[j][i-1]!=-1){
					dp[j][i]=dp[dp[j][i-1]][i-1];
				}else dp[j][i]=-1;
			}
		}
	}
};
