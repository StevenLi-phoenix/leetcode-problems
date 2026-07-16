// @leetcode id=3815 questionId=4067 slug=design-auction-system lang=cpp site=leetcode.com title="Design Auction System"
class AuctionSystem {
public:
    AuctionSystem() {
    }

    void addBid(int userId, int itemId, int bidAmount) {
        auto& userBid = bids[itemId][userId];
        if (userBid != 0) {
            items[itemId].erase({userBid, userId});
        }
        userBid = bidAmount;
        items[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);
    }

    void removeBid(int userId, int itemId) {
        int amount = bids[itemId][userId];
        items[itemId].erase({amount, userId});
        bids[itemId].erase(userId);
    }

    int getHighestBidder(int itemId) {
        auto it = items.find(itemId);
        if (it == items.end() || it->second.empty()) return -1;
        return it->second.rbegin()->second;
    }

private:
    unordered_map<int, unordered_map<int, int>> bids; // itemId -> userId -> amount
    unordered_map<int, set<pair<int, int>>> items; // itemId -> set of (amount, userId)
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
