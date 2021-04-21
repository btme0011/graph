template<typename T>
struct dja{
	vector<vector<pair<T,T>> edge;
	vector<bool> vis;
	T ans;
	dja(T n,vector<vector<pair<T,T>>> e,T a,T b){// no of nodes,edge(weight and destination),start node,destination node
		edge=e;
		vis=vector<bool>(n+1);
		starti(e,a);
		
	}
// 	for(int i=0;i<m;i++) {
// 		ll a,b,c;
// 		cin>>a>>b>>c;
// 		a--;
// 		b--;
// 		edge[a].push_back({c,b});
// 		edge[b].push_back({c,a});
// 	}
	
	void start(vector<vector<pair<T,T>>> edge,T a,T b){
		
		set<pair<T,T>> se;
		pq.push({0,a});
		vis[a]=1;
		while(!pq.empty()){
			pair<ll,ll> curr=*se.begin();
			if(visited[curr.second]!=0) {se.erase(se.begin());continue;}
			vis[curr.second]=1;
			se.erase(se.begin());		

			if(curr.second==b){
				ans=curr.first;
				break;
			}
			
			for(auto x:edge[curr.second]){// things which are connected by that node
				if(visited[x.second]==0)	{
					pq.push({x.first+curr.first,x.second});
				}
			}
		}
		
	}
};
