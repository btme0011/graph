bool visited[10];
void dfs(ll node,vector<vector<ll>> edge,vector<bool> vis,stack<ll> &ans){
	visited[node]=1;
	for(auto x:edge[node]){
		if(visited[x]==0) dfs(x,edge,vis,ans);
	}
	ans.push(node);
}
string solve(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<ll>> edge(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		
		edge[a].push_back(b);
	}
	
	fo(i,n){
		visited[i]=0;
	}
	
	vector<bool> vis(10);
	stack<ll> ans;
	vector<ll> mans;
	for(int i=0;i<n;i++){
		if(visited[i]==0){
			dfs(i,edge,vis,ans);
			
		}
	}
	while(!ans.empty()) {mans.push_back(ans.top());ans.pop();}
	retv(mans);
}
