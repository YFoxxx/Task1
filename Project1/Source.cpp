#include <iostream>
#include <string>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int num1, price1, num2, price2, earnings=0;
    cout << "Введите количество продавцов ";
    cin >> num1; // получение от пользователя размера массива
    int* sellers = new int[num1]; // Выделение памяти для массива
    for (int i = 0; i < num1; i++) {
        // Заполнение массива и вывод значений его элементов
        cout << "Введите цену " << i+1 << " продавца"<< endl;
        cin >> price1;
        sellers[i] = price1;
        cout << "Цена " << i+1 << " продавца - " << sellers[i] << endl;
    }
    
    cout << "Введите количество покупателей ";
    cin >> num2; // получение от пользователя размера массива

    int* customer = new int[num2]; // Выделение памяти для массива
    for (int i = 0; i < num2; i++) {
        // Заполнение массива и вывод значений его элементов
        cout << "Введите цену, за которую  " << i + 1 << " покупатель готов купить арбуз" << endl;
        cin >> price2;
        customer[i] = price2;
        cout << "Цена  " << i + 1 << " покупателя - " << customer[i] << endl;
    }
    for (int k = 0; k < num1; k++) {
        for (int l = 0; l < num2; l++) {
            if (sellers[k] <= customer[l]) {
                //cout << customer[l]<< endl;
                earnings += customer[l];
                k += 1;

            }
            
        }
        
    }
    int globprice = customer[0];

    for (int i = 0; i < num2; ++i) {
        if (customer[i] > globprice) {
            globprice = customer[i];
        }
    }
    cout << globprice<< " "<< earnings;
    delete[] sellers; // очистка памяти
    delete[] customer; // очистка памяти
}

