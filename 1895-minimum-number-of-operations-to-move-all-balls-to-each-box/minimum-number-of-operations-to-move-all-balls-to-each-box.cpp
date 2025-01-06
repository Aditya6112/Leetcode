class Solution {
public:
    vector<int> minOperations(string boxes) {
        int size=boxes.size();
        vector<int>result(size,0);
        int curr=0;
        while(curr<size){
            //add left balls
            int start=0;
            int end=curr;
            for(int i=start;i<end;i++){
                result[curr]+=((boxes[i]-'0')*(abs(curr-i)));
            }
            //add right balls
            start=curr+1;
            end=size;
            for(int i=start;i<end;i++){
                result[curr]+=((boxes[i]-'0')*(abs(curr-i)));
            }
            curr++;
        }
        return result;
    }
};