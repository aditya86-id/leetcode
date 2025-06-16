class Solution {
private:
    std::string space(std::string caption) {
        std::string new_str = " " + caption;
        int count = 0;
        int n = new_str.length();

        for (int i = 0; i < n - 1; i++) {
            if (new_str.at(i) == ' ' && std::isalpha(new_str.at(i + 1))) {
                count++;
                if (count > 1) {
                    new_str[i + 1] = std::toupper(new_str.at(i + 1));
                } else {
                    new_str[i + 1] = std::tolower(new_str.at(i + 1));
                }
            }
        }

        // Remove all spaces
        std::string result = "";
        for (char c : new_str) {
            if (c != ' ')
                result += c;
        }

        // Truncate to 100 characters max (excluding the '#')
        if (result.length() > 99) {
            result = result.substr(0, 99);
        }

        return result;
    }

public:
    std::string generateTag(std::string caption) {
        // Convert entire string to lowercase first
        for (char &c : caption) {
            c = std::tolower(c);
        }

        std::string formatted = space(caption);
        return "#" + formatted;
    }
};
