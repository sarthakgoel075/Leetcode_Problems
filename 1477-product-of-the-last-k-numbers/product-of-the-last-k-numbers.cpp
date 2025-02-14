class ProductOfNumbers {
public:
    vector<int> product;
    
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            product.clear(); // Reset because multiplication with zero invalidates previous values
        } else if (product.empty()) {
            product.push_back(num);
        } else {
            product.push_back(product.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k > product.size()) return 0; // If more elements are requested than available, return 0
        int t = product.size() - 1;
        int x = t - k;
        
        if (x < 0) return product[t]; // This handles cases where we need the full product
        return product[t] / product[x];
    }
};
