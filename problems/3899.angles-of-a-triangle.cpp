// @leetcode id=3899 questionId=4266 slug=angles-of-a-triangle lang=cpp site=leetcode.com title="Angles of a Triangle"
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c || a + c <= b || b + c <= a) return {};

        auto angleOpposite = [](double x, double y, double z) {
            double cosAngle = (y * y + z * z - x * x) / (2 * y * z);
            cosAngle = max(-1.0, min(1.0, cosAngle));
            return acos(cosAngle) * 180.0 / M_PI;
        };

        vector<double> angles = {
            angleOpposite(a, b, c),
            angleOpposite(b, a, c),
            angleOpposite(c, a, b)
        };
        sort(angles.begin(), angles.end());
        return angles;
    }
};
