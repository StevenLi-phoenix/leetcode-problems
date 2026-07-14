// @leetcode id=1912 questionId=2023 slug=design-movie-rental-system lang=cpp site=leetcode.com title="Design Movie Rental System"
class MovieRentingSystem {
public:
    unordered_map<long long, int> priceOf; // (shop*100000+movie) -> price
    unordered_map<int, set<pair<int, int>>> unrented; // movie -> {(price, shop)}
    set<tuple<int, int, int>> rented; // (price, shop, movie)

    long long key(int shop, int movie) {
        return (long long)shop * 100000 + movie;
    }

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceOf[key(shop, movie)] = price;
            unrented[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        auto it = unrented.find(movie);
        if (it == unrented.end()) return result;
        for (auto& [price, shop] : it->second) {
            result.push_back(shop);
            if (result.size() == 5) break;
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = priceOf[key(shop, movie)];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceOf[key(shop, movie)];
        rented.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        for (auto& [price, shop, movie] : rented) {
            result.push_back({shop, movie});
            if (result.size() == 5) break;
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
