class Solution {
public:
    void dfs(vector<vector<int>>& adj,int src,vector<bool>& visited,vector<int>& comp){
        visited[src]=true;
        comp.push_back(src);
        for(auto& nbr:adj[src]){
            if(!visited[nbr]){
                dfs(adj,nbr,visited,comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int>comp;
                dfs(adj,i,visited,comp);
                
                int nodes=comp.size();
                int edg=0;
                for(auto c:comp){
                    edg+=adj[c].size();
                }
                //due to non directed counted 2 times 
                edg/=2;
                // if comp is connected then edg=nodes*(nodes-1)/2;
                if(edg==(nodes*(nodes-1))/2){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};