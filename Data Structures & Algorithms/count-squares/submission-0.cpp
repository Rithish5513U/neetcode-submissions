class CountSquares {
public:
    map<pair<int, int>, int> points;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        points[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        for(int i = 1; i <= 1000; i++){
            if((x + i > 1000) || (y + i > 1000))
                break;
            ans += points[{x+i, y+i}] * points[{x, y+i}] * points[{x+i, y}];
        }
        for(int i = 1; i <= 1000; i++){
            if((x + i > 1000) || (y - i < 0))
                break;
            ans += points[{x+i, y-i}] * points[{x, y-i}] * points[{x+i, y}];
        }
        for(int i = 1; i <= 1000; i++){
            if((x - i < 0) || (y + i > 1000))
                break;
            ans += points[{x-i, y+i}] * points[{x, y+i}] * points[{x-i, y}];
        }
        for(int i = 1; i <= 1000; i++){
            if((x - i < 0) || (y - i < 0))
                break;
            ans += points[{x-i, y-i}] * points[{x, y-i}] * points[{x-i, y}];
        }
        return ans;
    }
};
