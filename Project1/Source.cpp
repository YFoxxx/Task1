#include <iostream>
#include <string>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int num1, price1, num2, price2, earnings=0;
    cout << "������� ���������� ��������� ";
    cin >> num1; // ��������� �� ������������ ������� �������
    int* sellers = new int[num1]; // ��������� ������ ��� �������
    for (int i = 0; i < num1; i++) {
        // ���������� ������� � ����� �������� ��� ���������
        cout << "������� ���� " << i+1 << " ��������"<< endl;
        cin >> price1;
        sellers[i] = price1;
        cout << "���� " << i+1 << " �������� - " << sellers[i] << endl;
    }
    
    cout << "������� ���������� ����������� ";
    cin >> num2; // ��������� �� ������������ ������� �������

    int* customer = new int[num2]; // ��������� ������ ��� �������
    for (int i = 0; i < num2; i++) {
        // ���������� ������� � ����� �������� ��� ���������
        cout << "������� ����, �� �������  " << i + 1 << " ���������� ����� ������ �����" << endl;
        cin >> price2;
        customer[i] = price2;
        cout << "����  " << i + 1 << " ���������� - " << customer[i] << endl;
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
    delete[] sellers; // ������� ������
    delete[] customer; // ������� ������
}

