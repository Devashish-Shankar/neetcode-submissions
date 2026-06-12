class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(const string& s : strs){
            encoded_string += to_string(s.length()) + "#" + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_str;
        int i = 0;
        while(i < s.length()){
            int j = s.find('#',i);
            int length = std::stoi(s.substr(i, j - i));
            i = j + 1;
            decoded_str.push_back(s.substr(i,length));
            i+=length;
        }
        return decoded_str;
    }
};
