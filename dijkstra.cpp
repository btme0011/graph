template<typename T>
struct dja{
	vector<vector<pair<T,T>>> edge;
	vector<bool> vis;
	T ans;
	dja(T n,vector<vector<pair<T,T>>> e,T a,T b){// no of nodes,edge(weight and destination),start node,destination node
		edge=e;
		vis=vector<bool>(n+1);
		starti(e,a);
		
	}
	
	void start(T a,T b){
		set<pair<T,T>> se;
		se.push({0,a});
		vis[a]=1;
		while(!se.empty()){
			pair<ll,ll> curr=*se.begin();
			if(vis[curr.second]!=0) {se.erase(se.begin());continue;}
			vis[curr.second]=1;
			se.erase(se.begin());		

			if(curr.second==b){
				ans=curr.first;
				break;
			}
			
			for(auto x:edge[curr.second]){// things which are connected by that node
				if(vis[x.second]==0)	{
					se.push({x.first+curr.first,x.second});
				}
			}
		}
		
	}
};
