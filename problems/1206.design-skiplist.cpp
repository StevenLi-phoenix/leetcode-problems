// @leetcode id=1206 questionId=1337 slug=design-skiplist lang=cpp site=leetcode.com title="Design Skiplist"
class Skiplist {
public:
    static const int MAX_LEVEL = 16;

    struct Node {
        int val;
        vector<Node*> next;
        Node(int v, int level) : val(v), next(level, nullptr) {}
    };

    Node* head;
    int level;

    Skiplist() {
        head = new Node(-1, MAX_LEVEL);
        level = 1;
    }

    int randomLevel() {
        int lvl = 1;
        while (lvl < MAX_LEVEL && (rand() & 1)) lvl++;
        return lvl;
    }

    bool search(int target) {
        Node* cur = head;
        for (int i = level - 1; i >= 0; i--) {
            while (cur->next[i] && cur->next[i]->val < target) cur = cur->next[i];
        }
        cur = cur->next[0];
        return cur != nullptr && cur->val == target;
    }

    void add(int num) {
        vector<Node*> update(MAX_LEVEL, head);
        Node* cur = head;
        for (int i = level - 1; i >= 0; i--) {
            while (cur->next[i] && cur->next[i]->val < num) cur = cur->next[i];
            update[i] = cur;
        }

        int newLevel = randomLevel();
        if (newLevel > level) {
            for (int i = level; i < newLevel; i++) update[i] = head;
            level = newLevel;
        }

        Node* node = new Node(num, newLevel);
        for (int i = 0; i < newLevel; i++) {
            node->next[i] = update[i]->next[i];
            update[i]->next[i] = node;
        }
    }

    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL, head);
        Node* cur = head;
        for (int i = level - 1; i >= 0; i--) {
            while (cur->next[i] && cur->next[i]->val < num) cur = cur->next[i];
            update[i] = cur;
        }

        Node* target = update[0]->next[0];
        if (!target || target->val != num) return false;

        for (int i = 0; i < level; i++) {
            if (update[i]->next[i] != target) continue;
            update[i]->next[i] = target->next[i];
        }

        delete target;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
