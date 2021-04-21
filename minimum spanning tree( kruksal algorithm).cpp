template<typename T>
struct mst{
	
	mst(T n,vector<tuple<T,T,T>> edge){// no of nodes,<weight,node a, node b>
		solve(n,edge);
	}
	
	
	string solve(T n,vector<tuple<T,T,T>> edge){
// 		int n,m;
// 		cin>>n>>m;

// 		vector<tuple<ll,ll,ll>> edge;
// 		for(int i=0;i<m;i++){
// 			ll a,b,c;
// 			cin>>a>>b>>c;

// 			edge.push_back({c,a,b});
// 		}
		vector<tuple<ll,ll,ll>> ans;
		sort(edge.begin(),edge.end());

		vector<T> par(n);
		vector<T> size(n);

		for(int i=0;i<n;i++){
			par[i]=i;
			size[i]=1;
		}

		
		for(int i=0;i<(ll)edge.size();i++){
			ll a=get<1>(edge[i]);
			ll b=get<2>(edge[i]);
			while(a!=par[a]){
				a=par[a];
			}
			while(b!=par[b]){
				b=par[b];
			}
			if(a!=b){
				ans.push_back({a,b,get<0>(edge[i])});
				if(size[a]>size[b]){
					par[b]=par[a];
					size[a]+=size[b];
				}else{
					par[a]=par[b];
					size[b]+=size[a];
				}
			}
		}
	}
};
