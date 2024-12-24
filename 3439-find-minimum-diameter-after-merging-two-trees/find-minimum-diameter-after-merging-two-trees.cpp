class Solution {
public:
    pair<int,int> BFS(unordered_map<int,vector<int>>& adj,int src){
        int distance=0;
        int farthestNode=src;
        queue<int>q;
        q.push(src);
        unordered_map<int,bool>visited;
        visited[src]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int front=q.front();
                q.pop();
                farthestNode=front;
                for(auto nbr: adj[front]){
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        q.push(nbr);
                    }
                }
            }
            if(!q.empty()){
                distance++;
            }
        }
        return {farthestNode,distance};
    }

    int findDiameter(unordered_map<int,vector<int>>& adj){
        //this is one of the last node of the graph
        auto [farthestNode,dist] = BFS(adj,0);
        //now from this farthest node we have to find another farthest node
        auto [otherNode, diameter] = BFS(adj,farthestNode);

        return diameter;
    }

    unordered_map<int,vector<int>> findAdj(vector<vector<int>>& graph){
        unordered_map<int,vector<int>>adj_list;
        for(int i=0;i<graph.size();i++){
            int u=graph[i][0];
            int v=graph[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        return adj_list;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1=findAdj(edges1);
        unordered_map<int,vector<int>>adj2=findAdj(edges2);

        int dia1=findDiameter(adj1);
        int dia2=findDiameter(adj2);
        int combined=(dia1+1)/2+(dia2+1)/2+1;

        return max({dia1,dia2,combined});
    }
};