template<typename T>
struct bfs{
	queue<T> q;
	
	q.push(INF);
	vector<bool> vis;
	
	
	T n;
	vector<vector<T>> edge;
	bfs(T s,vector<vector<T>> e){
		edge=e;
		n=s;
		vis=vector<bool>(s);
		start();
	}
	
	void start(){
		q.push(0);// initial element in queue
		vis.insert(0);
		while(!q.empty()){
			T curr=q.front();
			q.pop();

			for(ll x:edge[curr]){
				if(vis.count(x)==0){
					q.push(x);
					vis[x]=1;
				}
			}


			// do what u want to do with curr element


			if(q.front()==INF){
				if(q.size()==1) break;
				q.pop();
				q.push(INF);
			}

		}
	}
};
	
