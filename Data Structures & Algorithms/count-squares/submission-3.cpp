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
            int d1 = points[{x+i, y+i}], d2 = points[{x+i, y-i}], d3 = points[{x-i, y+i}], d4 = points[{x-i, y-i}];
            int x1 = points[{x, y+i}], x2 = points[{x, y-i}];
            int y1 = points[{x+i, y}], y2 = points[{x-i, y}];
            ans += d1 * x1 * y1;
            ans += d2 * x2 * y1;
            ans += d3 * x1 * y2;
            ans += d4 * x2 * y2;
        }
        return ans;
    }
};
