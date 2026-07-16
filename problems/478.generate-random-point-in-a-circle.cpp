// @leetcode id=478 questionId=915 slug=generate-random-point-in-a-circle lang=cpp site=leetcode.com title="Generate Random Point in a Circle"
class Solution {
public:
    Solution(double radius, double x_center, double y_center)
        : radius(radius), xc(x_center), yc(y_center) {
    }

    vector<double> randPoint() {
        double u = (double)rand() / RAND_MAX;
        double angle = (double)rand() / RAND_MAX * 2.0 * M_PI;
        double r = radius * sqrt(u);
        return {xc + r * cos(angle), yc + r * sin(angle)};
    }

private:
    double radius, xc, yc;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
