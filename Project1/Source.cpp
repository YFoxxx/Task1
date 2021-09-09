#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int price1, num2, num1, price2, earnings=0;
    vector<int> sellers;
    vector<int> customer;
    vector<string> file;
    string line;
    ofstream fout;
    ifstream fin;
    int ch = 0;


    fin.open("INPUT.txt");
    if (fin.is_open()) {
        while ((ch = fin.get()) != EOF) {
            if (char(ch) != '\n') line = line + char(ch);
            else {
                file.push_back(line);
                line.clear();
            }
        }
        file.push_back(line);
        fin.close();
    }
    else {
        cout << "Error!";
    }


    num1 = file[0][0]-'0';
    num2 = file[0][2]-'0';


    for (int i = 0; i < num1*2; i++) {
        price1 = file[1][i] - '0';
        i += 1;
        sellers.push_back(price1);
    }

    for (int i = 0; i < num2*2; i++) {
        price2 = file[2][i] - '0';
        i += 1;
        customer.push_back(price2);
    }


    for (int k = 0; k < num1; k++) {
        for (int l = 0; l < num2; l++) {
            if (sellers[k] <= customer[l]) {
                //cout << customer[l]<< endl;
                earnings += customer[l];
                k += 1;
                if (k >= num1) break;

            }
            
        }
        
    }
    int globprice = customer[0];

    for (int i = 0; i < num2; ++i) {
        if (customer[i] > globprice) {
            globprice = customer[i];
        }
    }
    //cout << globprice<< " "<< earnings;
    


    fout.open("OUTPUT.txt");
    fout << globprice << " " << earnings;
    fout.close();

    sellers.clear();
    customer.clear(); 
}

