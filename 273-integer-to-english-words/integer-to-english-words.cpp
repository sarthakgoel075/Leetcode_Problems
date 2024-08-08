#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<int, string> belowten = {{0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
    unordered_map<int, string> belowtwenty = {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};
    unordered_map<int, string> belowhundred = {{20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};

    string solve(int n){
        if (n < 10) {
            return belowten[n];
        }
        if (n < 20) {
            return belowtwenty[n];
        }
        if (n < 100) {
            return belowhundred[(n / 10) * 10] + (n % 10 ? " " + solve(n % 10) : "");
        }
        if (n < 1000) {
            return belowten[n / 100] + " Hundred" + (n % 100 ? " " + solve(n % 100) : "");
        }
        if (n < 1000000) {
            return solve(n / 1000) + " Thousand" + (n % 1000 ? " " + solve(n % 1000) : "");
        }
        if (n < 1000000000) {
            return solve(n / 1000000) + " Million" + (n % 1000000 ? " " + solve(n % 1000000) : "");
        }
        return solve(n / 1000000000) + " Billion" + (n % 1000000000 ? " " + solve(n % 1000000000) : "");
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return solve(num);
    }
};
