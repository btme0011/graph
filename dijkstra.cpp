	vector<vector<pair<ll,ll>> edge(n);
	for(int i=0;i<m;i++) {
		ll a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		edge[a].push_back({c,b});
		edge[b].push_back({c,a});
	}
	
	
	priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
	pq.push({0,0});
	set<ll> visited;
	//visited.insert(0);
	ll cnt=0;
	vector<ll> ans;
	while(!pq.empty()){
		pair<ll,ll> curr=pq.top();
		if(visited.count(curr.second)!=0) {pq.pop();continue;}
		visited.insert(curr.second);
		pq.pop();		
		
		
		for(auto x:edge[curr.second]){// things which are connected by that node
			if(visited.count(x.second)==0)	{
				pq.push({x.first+curr.first,x.second});
			}
		}
	}
