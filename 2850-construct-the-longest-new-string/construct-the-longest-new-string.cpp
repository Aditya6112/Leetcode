class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y)return x*4+2*z;
        return min(x,y)*4+2*z+2;
    }
};