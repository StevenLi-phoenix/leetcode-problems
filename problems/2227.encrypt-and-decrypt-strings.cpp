// @leetcode id=2227 questionId=1433 slug=encrypt-and-decrypt-strings lang=cpp site=leetcode.com title="Encrypt and Decrypt Strings"
class Encrypter {
public:
    unordered_map<char, string> keyToVal;
    unordered_map<string, int> encryptedDictCount;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < (int)keys.size(); i++) {
            keyToVal[keys[i]] = values[i];
        }
        for (string& w : dictionary) {
            string enc = encrypt(w);
            if (!enc.empty()) encryptedDictCount[enc]++;
        }
    }

    string encrypt(string word1) {
        string res;
        for (char c : word1) {
            if (keyToVal.find(c) == keyToVal.end()) return "";
            res += keyToVal[c];
        }
        return res;
    }

    int decrypt(string word2) {
        auto it = encryptedDictCount.find(word2);
        return it == encryptedDictCount.end() ? 0 : it->second;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
