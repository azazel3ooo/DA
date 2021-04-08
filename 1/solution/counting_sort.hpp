#pragma once
#include <string>
#include <iostream>

static const int MAX_IDX = 1000000;

template<typename T>
TVector<T> CountingSort(TVector<T>const &vector){
    TVector<T> res_vector(vector.Size());
    TVector<int> idx_vector(MAX_IDX, 0);

    for (int i = 0; i < vector.Size(); ++i){
        idx_vector[vector[i].key]++;
    }
    int t1 = 0, t2;
    for (int i = 0; i < MAX_IDX; ++i){
        t2 = idx_vector[i];
        idx_vector[i] = t1;
        t1 += t2;
    }
    for (int i = 0; i < vector.Size(); ++i){
        res_vector[idx_vector[vector[i].key]] = vector[i];
        idx_vector[vector[i].key]++;
    }
    return res_vector;
}