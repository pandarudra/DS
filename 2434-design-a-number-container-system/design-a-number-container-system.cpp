#define umap unordered_map
class NumberContainers {
private:
    umap<int , int> mpq ;
    umap<int , set<int>> get_min ;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mpq[index]){
            get_min[mpq[index]].erase(index) ;
        }
        mpq[index] = number ;
        get_min[number].insert(index) ;
    }
    
    int find(int number) {
        if(get_min.find(number) != get_min.end() && !get_min[number].empty()){
            return *get_min[number].begin() ;
        }
        return -1 ;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */