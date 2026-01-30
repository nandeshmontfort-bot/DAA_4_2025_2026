class Solution 
{
  public:
    bool path(int node, vector<vector<int>>&adjlist, vector<bool>&visited, int count, int n) 
    {
        if(count == n)
        {
            return true;
        }
        
        for(int next:adjlist[node])
        {
            if(!visited[next])
            {
                visited[next] = true;
                if (path(next,adjlist,visited,count+1,n))
                {
                    return true;
                }
                visited[next] = false;
            }
        }
        return false;
    }
    
    bool check(int n, int m, vector<vector<int>>&edges) 
    {
        vector<vector<int>> adjlist(n);
        for(auto &e : edges) 
        {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        
        for(int i = 0; i < n; i++) 
        {
            vector<bool> visited(n, false);
            visited[i] = true;
            if(path(i, adjlist, visited, 1, n))
            {
                return true;
            }
        }
        return false;
    }
};
