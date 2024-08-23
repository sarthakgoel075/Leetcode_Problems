class Solution {
public:
    string fractionAddition(string expression) {
        int i = 0;
        int n = expression.size();
        int num = 0;  // This will hold the accumulated numerator
        int deno = 1; // This will hold the accumulated denominator

        while (i < n) {
            int currnum = 0;
            int currdeno = 0;
            bool isneg = false;
            
            // Check for '-' or '+' at the start
            if (expression[i] == '-' || expression[i] == '+') {
                isneg = (expression[i] == '-');
                i++;
            }
            
            // Read the numerator
            while (i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currnum = (currnum * 10) + val;
                i++;
            }
            
            if (isneg) {
                currnum *= -1;
            }
            
            i++; // Skip the '/'
            
            // Read the denominator
            while (i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currdeno = (currdeno * 10) + val;
                i++;
            }
            
            // Perform addition of fractions: a/b + c/d = (a*d + b*c) / (b*d)
            num = num * currdeno + deno * currnum;        
            deno = deno * currdeno;
        }

        // Simplify the fraction
        int gcd = std::__gcd(abs(num), abs(deno)); // or use a custom gcd function if not available
        num /= gcd;
        deno /= gcd;

        // Handle negative denominator
        if (deno < 0) {
            num = -num;
            deno = -deno;
        }

        return to_string(num) + "/" + to_string(deno);
    }
};
