
while(!pq.empty()){
	  curr=pq.top();
		visited.insert(curr);
  	pq.pop();

		for(auto x:edge[curr]){// things which are connected by that node
				pq.push(x);
		}
	}


// multiple source djastra
