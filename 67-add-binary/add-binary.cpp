class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        stack<int> s1, s2, s3;

        for (auto ch : a) s1.push(ch - '0');
        for (auto ch : b) s2.push(ch - '0');

        // Add common digits
        while (!s1.empty() || !s2.empty()) {
            int x = (!s1.empty() ? s1.top() : 0);
            int y = (!s2.empty() ? s2.top() : 0);
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();

            int sum = x + y + carry;
            s3.push(sum % 2);
            carry = sum / 2;
        }

        // Final carry
        if (carry) s3.push(carry);

        // Construct result string
        string result = "";
        while (!s3.empty()) {
            result += (s3.top() + '0');
            s3.pop();
        }

        return result;
    }
};
