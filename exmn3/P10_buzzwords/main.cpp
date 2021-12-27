#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string str = "";
    while( getline(cin,str) ){
        char delimiter = ' ';
        str.erase(remove(str.begin(),str.end(),delimiter),str.end());
        size_t lenstr = size(str);
        for(size_t longitud=0;longitud<lenstr;++longitud){
            map<string,int> countword;
            for(size_t i=0;i<lenstr-longitud;++i){
                string sub_str=str.substr(i,1+longitud);
                countword[sub_str] += 1;
            }
            auto x = max_element(countword.begin(),countword.end(),[] (const std::pair<string,int>& a, const std::pair<string,int>& b)->bool{ return a.second < b.second;  } );
            if (x->second!=1){
                cout<<x->second<<endl;
            }
            //cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
