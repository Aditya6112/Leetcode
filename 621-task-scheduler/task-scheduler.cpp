class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>arr(26,0);
        for(auto ch:tasks){
            arr[ch-'A']++;
        }
        priority_queue<int>pq;
        for(auto it:arr){
            if(it!=0){
                pq.push(it);
            }
        }

        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(auto it:temp){
                if(it>0){
                    pq.push(it);
                }
            }

            if(pq.empty()){
                time+=temp.size();
            }else{
                time+=n+1;
            }
        }
        return time;
    }
};