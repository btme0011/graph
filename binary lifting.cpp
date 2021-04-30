template<typename T>
struct lca{
	T dp[N][(T)log2(N)+1];//in place of N write no of nodex in tree
	T depth[N];// depth of each node
	T ans; // get the answer
	
	lca(T p,T q,T sz,vector<vector<T>> e,T start){// two nodes whose lca u want to know,no of nodes, edge, starting node
		N=sz;
		dp=vector<vector<T>>(sz,vector<T>(log2(sz)+1));//N is no of nodes
		depth=vector<T>(sz);// depth of each node
		ans=solve(p,q,start,e);
	}
	
	void dfs(int node,vector<vector<int>> edge,int par,int dep){ // to fill the first col of DP and depth of each node
		dp[node][0]=par;
	  depth[node]=dep;

		for(int x:edge[node]){
			if(x!=par)
				dfs1(x,edge,node,dep+1);
		}
	}

	T solve(T p,T q,T start,vector<vector<T>> edge){

		dfs1(start,edge,-1,0);

		for(int i=0;i<log2(N);i++){// to fill remainin cells of dp
			for(int j=1;j<N;j++){
				if(dp[i][j-1]!=-1){
					dp[i][j]=dp[dp[i][j-1]][j-1];
				}
			}
		}

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

		for(int i=log2(20)+1;i>=0;i--){
			if(dp[p][i]!=-1 and dp[p][i]!=dp[q][i]){
				p=dp[p][i];
				q=dp[q][i];
			}
		}
		return p;
	}
};
