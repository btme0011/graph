queue<ll> q;
q.push(0);// initial element in queue
q.push(INF);
set<ll> vis;
vis.insert(0);
while(!q.empty()){
		ll curr=q.front();
		q.pop();
		
		for(ll x:edge[curr]){
			if(vis.count(x)==0){
				q.push(x);
				vis.insert(x);
			}
		}
		
		
		// do what u want to do with curr element
    
		
		if(q.front()==INF){
			if(q.size()==1) break;
			q.pop();
			sign=!sign;
			q.push(INF);
		}
		
	}
	
