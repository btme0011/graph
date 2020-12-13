void dfs(ll node){
	
	// word you want to do at the time of entering node
	
	vis[node]=1;
	for(ll x:edge[node]){
		if(!vis[x]){
			dfs(x);
		}
	}
	
	// work you want to do at the time of leaving node
	
}
