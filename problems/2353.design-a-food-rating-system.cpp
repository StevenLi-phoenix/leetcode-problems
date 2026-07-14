// @leetcode id=2353 questionId=2429 slug=design-a-food-rating-system lang=cpp site=leetcode.com title="Design a Food Rating System"
class FoodRatings {
public:
    unordered_map<string, string> foodCuisine;
    unordered_map<string, int> foodRating;
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (size_t i = 0; i < foods.size(); i++) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        int oldRating = foodRating[food];
        cuisineFoods[cuisine].erase({-oldRating, food});
        foodRating[food] = newRating;
        cuisineFoods[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
