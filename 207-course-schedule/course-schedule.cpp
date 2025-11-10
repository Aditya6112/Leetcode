class Solution {
public:
    bool isCycle(int i,unordered_map<int,list<int>>& adj_list,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited){
        visited[i]=true;
        dfsVisited[i]=true;
        for(auto nbr:adj_list[i]){
            if(!visited[nbr]){
                bool checkAns=isCycle(nbr,adj_list,visited,dfsVisited);
                if(checkAns)return true;
            }else{
                if(dfsVisited[nbr])return true;
            }
        }
        dfsVisited[i]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj_list;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        for(auto p:prerequisites){
            adj_list[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(isCycle(i,adj_list,visited,dfsVisited)){
                return false;
            }
        }
        return true;
    }
};