class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj_list,int node,vector<int>& result){
        while(!adj_list[node].empty()){
            int nextNode=adj_list[node].back();
            adj_list[node].pop_back();
            dfs(adj_list,nextNode,result);
        }
        result.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj_list;
        unordered_map<int,int>inDegree,outDegree;
        for(auto& it:pairs){
            int u=it[0];
            int v=it[1];
            adj_list[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }
        
        int startNode=pairs[0][0];
        for(auto& it: outDegree){
            if((outDegree[it.first]-inDegree[it.first])==1){
                startNode=it.first;
                break;
            }
        }

        //dfsTraversal
        vector<int>Euclier;
        dfs(adj_list,startNode,Euclier);
        reverse(Euclier.begin(),Euclier.end());

        vector<vector<int>>result;
        for(int i=0;i<Euclier.size()-1;i++){
            result.push_back({Euclier[i],Euclier[i+1]});
        }
        return result;
    }
};