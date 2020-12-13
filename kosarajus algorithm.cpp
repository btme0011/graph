 stack<ll> st;
set<ll> visited;
void dfs1(ll node,vector<vector<ll>> edge){
	visited.insert(node);
	for(ll x:edge[node]){
		if(visited.count(x)==0) dfs1(x,edge);
	}
	deb(node);
	st.push(node);
}

vector<ll> ans;
void dfs2(ll node,vector<vector<ll>> edge){
	//deb(node);
	visited.insert(node);
	ans.push_back(node);
	for(ll x:edge[node]){
		if(visited.count(x)==0) dfs2(x,edge);
	}
}

void solve(){
	ll n,m;
	cin>>n>>m;
	
	vector<vector<ll>> edge1(n);
	vector<vector<ll>> edge2(n);
	fo(i,m){
		int a,b;
		cin>>a>>b;
		
		edge1[a].push_back(b);
		edge2[b].push_back(a);
	}
	
	
	for(int i=0;i<n;i++)
		if(visited.count(i)==0)
			dfs1(i,edge1);
	
	visited.clear();
	
	while(!st.empty()){
		while(visited.count(st.top())!=0) st.pop();
		dfs2(st.top(),edge2);
		vdeb(ans);
		ans.clear();
	}
	
}
