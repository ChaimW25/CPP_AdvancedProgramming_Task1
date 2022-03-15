#include <iostream>
#include <string>
#include "mat.hpp"
//#include "mat.cpp"
using namespace std;
//using namespace ariel;
    int main() {

        std::cout << "Hello, World!" << std::endl;
//    std::cin >> row;
        string str;
        int row, col;
        char symbol1, symbol2;
        cout << "Enter number of col: ";
        cin >> col;
        cout << "Enter number of rows: ";
        cin >> row;
        cout << "Enter first symbol: ";
        cin >> symbol1;
        cout << "Enter second symbol: ";
        cin >> symbol2;
        cout << ariel:: mat(row,col,symbol1,symbol2) << endl;
        return 0;
    }
