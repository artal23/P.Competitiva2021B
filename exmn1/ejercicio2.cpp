#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    
    vector<int> ADN[5];
    vector<int> res;
    int tam = S.length();
    
    for (int i=0; i<tam; i++) {
        switch (S[i]) {
            case 'A':
                ADN[1].push_back(i);
                break;
            case 'C':
                ADN[2].push_back(i);
                break;
            case 'G':
                ADN[3].push_back(i);
                break;
            case 'T':
                ADN[4].push_back(i);
                break;
        }
    }
    
    
    vector<int>::iterator itr1, itr2;
    tam = P.size();
    
    for (int i=0; i<tam; i++) {
        int j = 0;
        do {
            j++;
            if (ADN[j].size() != 0) {
                itr1 = lower_bound(ADN[j].begin(), ADN[j].end(), P[i]);
                itr2 = upper_bound(ADN[j].begin(), ADN[j].end(), Q[i]);
                itr2--;
            }
        } while ((ADN[j].size() == 0) || (itr1 == ADN[j].end()) || ((*itr1) > (*itr2)) || ((*itr1) < P[i]) || ((*itr2) > Q[i]));
        res.push_back(j);
    }
    
    return res;
    
}

int main()
{
    
    return 0;
}