class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> food;
        unordered_set<string>made;
        for(auto s:supplies){
            made.insert(s);
        }

        int cnt=recipes.size();
        vector<bool>cooked(cnt,false);
        while(cnt--){
            for(int i=0;i<ingredients.size();i++){
                if(cooked[i]){
                    continue;
                }
                bool canMade=true;
                for(int j=0;j<ingredients[i].size();j++){
                    if(made.find(ingredients[i][j])==made.end()){
                        canMade=false;
                        break;
                    }
                }
                if(canMade){
                    made.insert(recipes[i]);
                    cooked[i]=true;
                }
            }
        }
        for(int i=0;i<cooked.size();i++){
            if(cooked[i]){
                food.push_back(recipes[i]);
            }
        }
        return food;
    }
};