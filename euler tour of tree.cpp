template<typename T>
struct ett{
	vector<T> in;
	vector<T> euler;// ans
	vector<T> out;
	int time=0;
	
	ett(T n,vector<vector<T>> e,T start){ // no of nodes , edge, starting node of tree
		in=vector<T>(n+1);
		out=vector<T>(n+1);
		euler=vector<T>(2*(n+1));
		dfs(start,e,-1);
		
	}

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
}
