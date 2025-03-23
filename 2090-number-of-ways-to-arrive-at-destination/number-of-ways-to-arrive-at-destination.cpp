#define MOD 1000000007 
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj(n);
        for(auto r:roads){
            int u=r[0];
            int v=r[1];
            int w=r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>minQ;
        //dist, node
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>countPaths(n,0);
        minQ.push({0,0});
        dist[0]=0;
        countPaths[0]=1;
        while(!minQ.empty()){
            long long currTime=minQ.top().first;
            int node=minQ.top().second;
            minQ.pop();
            for(auto &it:adj[node]){
                int nbr=it.first;
                int roadTime=it.second;
                if(currTime+roadTime<dist[nbr]){
                    dist[nbr]=currTime+roadTime;
                    minQ.push({dist[nbr],nbr});
                    countPaths[nbr]=countPaths[node];
                }else if(currTime+roadTime==dist[nbr]){
                    countPaths[nbr]=(countPaths[nbr]+countPaths[node])%MOD;
                }
            }
        }
        return countPaths[n-1];
    }
};