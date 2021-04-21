template<typename T>
struct art_pnt{
    vector<vector<T>> edge;
    vector<bool> vis;
    vector<T> tin;
    vector<T> tout;
    T timer=0;
    T n;
    vector<T> ans;
    art_pnt(T node,vector<vector<T>> e){// pass no of nodes and edge 
        edge=e;
        n=node;
        vis=vector<bool>(n);
        tin=vector<T>(n);
        tout=vector<T>(n);
        dfs(0,-1);
    }
    
    
    void dfs(T v, T p) {
        vis[v] = true;
        tin[v] = timer;
        low[v] = timer;
        timer++;

        T children=0;
        for (T to : edge[v]) {
            if (to == p) continue;// if the next node is parent continue
            if (visited[to]) {// if we have vis the node before
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] >= tin[v] && p!=-1)// > if the graph end on the other side of node 
                    ans.push_back(v);
                ++children;
            }
        }

        if(p == -1 && children > 1)
            ans.push_back(v);
    }
}
              AP
low 1    2    3    4
in  1    2    3    4    >
    N----N----N----N
 
               AP
low 1     2    3    3
in  1    2    3     4
    N----N----N-----N   ==
             |      |
             |      |
             |      |
             | -----N 5 3








