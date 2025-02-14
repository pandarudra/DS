class ProductOfNumbers {
private:
    vector<int> v ;
    int sz ;
public:
    ProductOfNumbers() {
        v.push_back(1) ;
        sz = 0 ;
    }
    
    void add(int num) {
        if(num == 0){
            v = {1} ;
            sz = 0 ;
            return ;
        }
        v.push_back(num * v[sz]) ;
        sz++ ;
    }
    
    int getProduct(int k) {
        if(k > sz)return 0 ;
        return v[sz] / v[sz - k] ;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */