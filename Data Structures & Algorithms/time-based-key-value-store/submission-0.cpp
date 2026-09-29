class TimeMap {
   private:
    unordered_map<string, vector<pair<int, string>>> store;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { store[key].emplace_back(timestamp, value); }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) {
            return "";
        }
        const auto& entries = it->second;
        int left = 0;
        int right = entries.size() - 1;
        string result = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (entries[mid].first <= timestamp) {
                result = entries[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
