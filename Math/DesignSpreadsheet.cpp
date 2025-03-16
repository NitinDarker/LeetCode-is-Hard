#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Spreadsheet {
    unordered_map<string, int> grid;
    int row;

  public:
    Spreadsheet(int rows) {
        row = rows;
    }

    void setCell(string cell, int value) {
        grid[cell] = value;
        // char col = cell[0];
        // string row = cell.substr(1);
        // row = stoi(row);
    }

    void resetCell(string cell) {
        grid[cell] = 0;
    }

    int getValue(string formula) {
        if (formula[0] != '=') return 0;
        int size = formula.length();
        string x = "";
        string y = "";
        int ind = 1;
        for (int i = ind; i < size; i++) {
            if (formula[i] == '+') {
                ind = i + 1;
                break;
            }
            x += formula[i];
        }
        for (int i = ind; i < size; i++) {
            y += formula[i];
        }
    
        int res = 0;
        if (grid.find(x) != grid.end()) {
            res += grid[x];
        } else if (x[0] >= 'A' && x[0] <= 'Z') {
            res += 0;
        } else {
            res += stoi(x);
        }

        if (grid.find(y) != grid.end()) {
            res += grid[y];
        } else if (y[0] >= 'A' && y[0] <= 'Z') {
            res += 0;
        } else {
            res += stoi(y);
        }

        return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
