int in[N];
int euler[2*N];
int out[N];
int time=0;

void dfs(int node,vector<vector<int>> edge,int par){
	
	in[node]=timee;
	euler[timee]=node;
	++timee;
	for(int x:edge[node]){
		if(x!=par)
			dfs(x,edge,node);
	}
	out[node]=timee;
	euler[timee]=node;
	++timee;
}
