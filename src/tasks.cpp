#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs != nullptr && rhs != nullptr) {
        int temp;
        temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows<=0 || num_cols<=0){
        return nullptr;
    }
    int **arr = new int *[num_rows];
    for (int i = 0; i<num_rows; i++){
        arr[i] = new int [num_cols];
    }
    for (int i = 0; i<num_rows; i++){
        for (int j=0; j<num_cols; j++){
            arr[i][j] = init_value;
        }
    }
    return arr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (arr_2d_source == nullptr || arr_2d_target == nullptr){
        return false;
    }
    if (num_rows<=0 || num_cols<=0){
        return false;
    }
    for (int i = 0; i<num_rows; i++){
        for (int j = 0; j<num_cols; j++){
            arr_2d_target[i][j] = arr_2d_source[i][j];
        }
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    int temp;
    for (int i = 0; i<(arr.size()/2); i++){
        temp = arr[i];
        arr[i] = arr[arr.size()-i-1];
        arr[arr.size()-i-1] = temp;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin != nullptr && arr_end != nullptr){
        while (arr_begin<arr_end){
            swap_args(arr_begin++, arr_end--);
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (arr == nullptr){
        return nullptr;
    }
    int *mx = &arr[0];
    if (size <= 0){
        return nullptr;
    }
    for (int i = 1; i<size; i++){
        if (arr[i]>=*mx){
            mx = &arr[i];
        }
    }
    return mx;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> arr_new;
    for (int i = 0; i<arr.size(); i++){
        if (arr[i]%2!=0){
            arr_new.push_back(arr[i]);
        }
    }
    return arr_new;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> arr_new;
    for (int i = 0; i<arr_a.size(); i++){
        for (int j = 0; j<arr_b.size(); j++){
            if (arr_a[i]==arr_b[j]){
                bool is_in_vector = false;
                for (int k = 0; k<arr_new.size(); k++){
                    if (arr_a[i]==arr_new[k]) is_in_vector = true;
                }
                if (!is_in_vector) arr_new.push_back(arr_a[i]);
            }
        }
    }
    int temp;
    int size = arr_new.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr_new[j] > arr_new[j + 1]) {
                temp = arr_new[j];
                arr_new[j] = arr_new[j + 1];
                arr_new[j + 1] = temp;
            }
        }
    }
    return arr_new;
}
