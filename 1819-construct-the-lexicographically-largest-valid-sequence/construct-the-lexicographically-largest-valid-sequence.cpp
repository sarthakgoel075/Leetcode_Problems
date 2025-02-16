class Solution {
public:
    int num;
    int size;

    bool fun(vector<int>& arr, vector<int>& visit, int ind) {
        if (ind >= size) return true; // Correct base case

        if (arr[ind] != -1) { // Skip already filled positions
            return fun(arr, visit, ind + 1);
        }

        for (int i = num; i >= 1; i--) { // Try placing largest numbers first
            if (!visit[i]) {
                visit[i] = 1;
                arr[ind] = i;

                if (i == 1) { // Special case: `1` appears only once
                    if (fun(arr, visit, ind + 1)) {
                        return true;
                    }
                } 
                else if (ind + i < size && arr[ind + i] == -1) { // Place `i` at `ind + i`
                    arr[ind + i] = i;
                    if (fun(arr, visit, ind + 1)) {
                        return true;
                    }
                    arr[ind + i] = -1; // Backtrack
                }

                visit[i] = 0; // Backtrack
                arr[ind] = -1; // Reset immediately
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        num = n;
        size = 2 * (num - 1) + 1;
        vector<int> arr(size, -1);
        vector<int> visit(num + 1, 0);
        fun(arr, visit, 0);
        return arr;
    }
};
