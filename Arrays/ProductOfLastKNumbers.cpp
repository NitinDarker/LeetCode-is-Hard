// https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class ProductOfNumbers {
    vector<int> arr;
    vector<int> prefix; // Prefix Product Array

  public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        arr.push_back(num);
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
            return;
        }
        int mul = num * prefix.back();
        prefix.push_back(mul);
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) {
            return 0;
        }
        int val = prefix[n - 1] / prefix[n - k - 1];
        return val;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
