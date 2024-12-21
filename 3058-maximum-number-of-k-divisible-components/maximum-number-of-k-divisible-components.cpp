class Solution {
public:
    int dfs(int node,int par,vector<vector<int>>& adj_list,vector<int>& values,int k,int &comp){
        int sum=0;
        for(auto it:adj_list[node]){
            if(it!=par){
                sum+=dfs(it,node,adj_list,values,k,comp);
                sum%=k;
            }
        }
        sum+=values[node];
        sum%=k;
        if(sum==0)comp++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj_list(n);
        for(auto& edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        int comp=0;
        //0 is start node and -1 is assumed parent
        dfs(0,-1,adj_list,values,k,comp);
        return comp;
    }
};