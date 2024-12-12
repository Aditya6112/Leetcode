class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum=0;
        priority_queue<int>maxHeap;
        for(int gift:gifts){
            maxHeap.push(gift);
        }
        while(k--){
            int num=floor(sqrt(maxHeap.top()));
            maxHeap.pop();
            maxHeap.push(num);
        }
        while(!maxHeap.empty()){
            sum+=maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};