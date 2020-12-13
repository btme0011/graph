int dp[N][(ll)log2(N)+1];// N is no of nodes
int depth[N];// depth of each node
void dfs1(int node,vector<vector<int>> edge,int par,int dep){ // to fill the first col of DP and depth of each node
	dp[node][0]=par;
  depth[node]=dep;
	
	for(int x:edge[node]){
		if(x!=par)
			dfs1(x,edge,node,dep+1);
	}
}

ll solve(){
	int p,q;// two nodes
	cin>>p>>q;

	dfs1(0,edge,-1,0);
	
	for(int i=0;i<log2(n);i++){// to fill remainin cells of dp
		for(int j=1;j<n;j++){
			if(dp[i][j-1]!=-1){
				dp[i][j]=dp[dp[i][j-1]][j-1];
			}
		}
	}
	
	int l1=depth[p];
	int l2=depth[q];
  
	if(l1<l2) {swap(l1,l2);swap(p,q);}// l1 should be greater
	
	int d=l1-l2; // difference
	
	while(d>0){
		int i=log2(d);
		p=dp[p][i];
		d-=(1<<i);
	}
	
	if(p==q) ret(p);
	
	for(int i=log2(20)+1;i>=0;i--){
		if(dp[p][i]!=-1 and dp[p][i]!=dp[q][i]){
			p=dp[p][i];
			q=dp[q][i];
		}
	}
	return dp[p][0];
}
