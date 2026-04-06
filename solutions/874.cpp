class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();

        unordered_set<string> st;
        for(vector<int>& obs : obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxDist = 0;

        pair<int, int> dir= {0, 1};

        for(int i = 0; i<n; i++){
            if(commands[i] == -2){
                dir = {-dir.second, dir.first}; //left
            }else if(commands[i] == -1){
                dir = {dir.second, -dir.first}; //right
            }else{
                for(int j = 0; j<commands[i]; j++){
                    int X = x + dir.first;
                    int Y = y + dir.second;

                    string nextKey = to_string(X) + "_" + to_string(Y);

                    if(st.find(nextKey) != st.end()){
                        break; // vo possible hi nhi hai
                    }

                    x = X;
                    y = Y;
                }
            }

            maxDist = max(maxDist, x*x + y*y);
        }
        return maxDist;
    }
};