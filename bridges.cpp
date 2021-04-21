template<typename T>
struct bridge{
    vector<vector<T>> edge;
    vector<bool> vis;
    vector<T> tin;
    vector<T> tout;
    T timer=0;
    T n;
    vector<pair<T,T>> ans;
    bridge(T node,vector<vector<T>> e,T start){// no of nodes , edge , startting node
        edge=e;
        n=node;
        vis=vector<bool>(n);
        tin=vector<T>(n);
        tout=vector<T>(n);
        dfs(start,-1);
    }
    void dfs(int v, int p) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        for (int to : adj[v]) {
            if (to == p) continue;
            if (visited[to]) {
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] > tin[v])
                    ans.push_back({v, to});
            }
        }
    }
};
