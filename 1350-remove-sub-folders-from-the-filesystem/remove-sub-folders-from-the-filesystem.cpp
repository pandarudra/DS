#define all(vect) (vect).begin(),(vect).end()
class Solution {
private:
    bool CheckIfChild(string par , string t) {
        int i = 0 ;
        int N = par.length() ;
        int M = t.length() ;

        while(i < min(N , M)) {
            if(par[i] != t[i]) {
                break ;
            }
            i++ ;
        }

        return i >= N && t[N] == '/';
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int N = folder.size() ;
        sort(all(folder)) ;
        vector<string> fixedSubfolder ;

        vector<int> isChild(N , 0) ;

        for(int i = 0 ; i < N ; i++) {
            if(isChild[i]) continue ;
            string par = folder[i] ;
            for(int j = i + 1 ; j < N ; j++) {
                if(CheckIfChild(par , folder[j])) {
                    isChild[j] = 1 ;
                }else {
                    break ;
                }
            }
            fixedSubfolder.push_back(par) ;
        }

        return fixedSubfolder ;
    }
};