/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct cmp
{
    bool operator()(Point a, Point b) {
        if(a.x*a.x + a.y*a.y > b.x*b.x + b.y*b.y ){
            return true;
        }
        else if(a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y){
            return false;
        }
        else{
            if(a.x > b.x){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
class Solution {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        // write your code here
        // write your code here
        vector<Point> res;
        if (points.empty()||k<=0)
            return res;
        priority_queue<Point,vector<Point>,cmp> que;
        //points中的每个元素减去origin,方便进行比较
        for (auto &c : points)
        {
            c.x = c.x - origin.x;
            c.y = c.y - origin.y;
            que.push(c);
        }
        //恢复points元素的真实值,返回结果
        while (k > 0&&!que.empty())
        {
            Point tmp = que.top();
            tmp.x +=origin.x;
            tmp.y += origin.y;
            res.push_back(tmp);
            que.pop();
            --k;
        }
        return res;
    }
};
