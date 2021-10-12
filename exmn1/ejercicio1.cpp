#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {

    
    int N = A.size();
    vector<int> ps(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        ps[i] = A[i - 1] + ps[i - 1];
    }

    int izq_idx;
    int min_izq_idx;
    double avg;
    double avg_min;
    double avg_dos;
    double avg_prev;
    
    izq_idx = min_izq_idx = 0;
    avg = avg_min = (A[0] + A[1]) / 2.0;
    
    
    for (int i = 2; i < N; i ++) {

        avg_prev = ((double) ps[i + 1] - ps[izq_idx]) / 
                        (i - izq_idx + 1);

        avg_dos = (A[i - 1] + A[i]) / 2.0;
        
        if (avg_dos < avg_prev) {
            avg = avg_dos;
            izq_idx = i - 1;
        
}        else
            avg = avg_prev;
        
        if (avg < avg_min) {
            avg_min = avg;
            min_izq_idx = izq_idx;
        }
    }
        
    return min_izq_idx;
}