template<typename T>
struct bfs{
	queue<T> q;
	vector<bool> vis;
	
	
	T n;
	vector<vector<T>> edge;
	bfs(T sz,vector<vector<T>> e,T st){// no of nodex,edge,starting node
		edge=e;
		n=sz;
		vis=vector<bool>(sz);
		start(st);
	}
	
	void start(T st){
		q.push(st);// initial element in queue
		vis[st]=1;
		q.push(INF);
		while(!q.empty()){
			T curr=q.front();
			q.pop();

			for(ll x:edge[curr]){
				if(vis[x]==0){
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
	
