class Robot {
public:

    pair<int, int> pos = {0,0};
    int width = 0;
    int height = 0;
    int dir = 0;
    // east = 0
    // North = 1
    // West = 2
    // south = 3

    Robot(int wid, int heig) {
        width = wid;
        height = heig;
    }
    
    void step(int num) {
        int perimeter = 2 * (width + height - 2);
        
        if (num >= perimeter) {
            num %= perimeter;
            if (pos.first == 0 && pos.second == 0) dir = 3;
        }

        while (num > 0) {
            if (dir == 0) {
                int steps = min(num, (width - 1) - pos.first);
                pos.first += steps;
                num -= steps;
            } else if (dir == 1) {
                int steps = min(num, (height - 1) - pos.second);
                pos.second += steps;
                num -= steps;
            } else if (dir == 2) {
                int steps = min(num, pos.first);
                pos.first -= steps;
                num -= steps;
            } else if (dir == 3) {
                int steps = min(num, pos.second);
                pos.second -= steps;
                num -= steps;
            }

            if (num > 0) {
                dir = (dir + 1) % 4;
            }
        }
    }
    
    vector<int> getPos() {
        vector<int> res = {pos.first, pos.second};
        return res;
    }
    
    string getDir() {
        switch(dir % 4){
            case 0 : return "East";
            case 1 : return "North";
            case 2 : return "West";
            case 3 : return "South";
            break;
        }
        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */