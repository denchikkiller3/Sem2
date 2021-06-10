//������������� �������� < (��������� ������� �� ��������� ���������� ��������), *(��������� ������� ���� �������),
//����������� ����� ���������� ����� ������� �� ���������� �������� ���������� �������� � ������������� ��������� ���������� �������,
//��������� ��������� ������� ������� � ��������� � ��������� ���������� ���������� ��������.

#include <iostream>
#include <stdlib.h>
#define MAX 3

using namespace std;

class myVector {
private:
    double arr[MAX];
    int qntt;
    double value; // �������� ���������� �������� � ����� value
public:
    //����������� ��� ���������
    myVector() {
        arr[MAX - 1] = 0;
        qntt = 0;
        value = 0;
    }
    //����������� � �����������
    myVector(double cnstrArr, int cnstrQntt) {
        arr[MAX - 1] = cnstrArr;
        qntt = cnstrQntt;
        value = 0;
    }
    //����������
    ~myVector() {};

    //�������������� �������� " < "
    bool operator <(const myVector& const obj) {
        return this->getMinValue() < obj.getMinValue();
    }

    //�������������� �������� " * "
    double operator *(const myVector& obj) {
        double temp;
        temp = this->getMaxValue() * obj.getMinValue();
        return temp;
    }
    //�������������� ��������� ��� �����/������
    friend ostream& operator << (ostream& out, const myVector& numb);
    friend istream& operator >> (istream& in, myVector& numb);

    //������� ������
    void VectorOutput(void) {
        cout << "���� �������:" << endl;
        for (int i = 0; i < qntt; i++) {
            cout << arr[i] << endl;
        }
    }

    //������� ����������� ������������� �������� �������
    void VectorMax(void) {
        double max = 0;
        for (int i = 0; i < qntt; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        cout << "����������� �������� ������� � " << max << endl;
    }

    //������� ���������� �� ���������� ������� �������
    void VectorUp() {
        for (int i = 0; i < MAX - 1; i++) {
            for (int j = 0; j < MAX - 1; j++) {
                if (arr[j + 1] < arr[j]) {
                    swap(arr[j + 1], arr[j]);
                }
            }
        }
    }

    void swap(double& arrNext, double& arr) {
        double temp = arrNext;
        arrNext = arr;
        arr = temp;
    }

    //���������� ���������� �������� ������
    double getMinValue(void) const {
        return this->arr[0];
    }

    //���������� ������������� �������� ������
    double getMaxValue(void) const {
        return this->arr[MAX - 1];
    }
};
ostream& operator<<(ostream& out, const myVector& obj) {
    for (int i = 0; i != MAX; i++) {
        out << "    " << obj.arr[i] << endl;
    }
    return out;
}

istream& operator>>(istream& in, myVector& obj) {
    for (int i = 0; i != MAX; i++) {
        cout << "   arr[" << i << "]" << ": ";
        cin >> obj.arr[i];
    }
    return in;
}

int main() {
    system("chcp 1251");
    double min1, min2;

    // ����� ��� ������� � ����� myVector
    myVector vec1, vec2, vec3;
    myVector* arrayVecor[3] = { &vec1, &vec2, &vec3 };

    //vector 1
    cout << " ������ " << MAX << " ��������(-��) ��� �������:" << endl;
    cin >> vec1;
    cout << "\n ���� �������:" << endl;
    cout << vec1;
    cout << " ������ ���� ����������:" << endl;
    vec1.VectorUp();
    cout << vec1;

    //vector 2
    cout << "\n\n ������ " << MAX << " ��������(-��) ��� �������:" << endl;
    cin >> vec2;
    cout << "\n ���� �������:" << endl;
    cout << vec2;
    cout << " ������ ���� ����������:" << endl;
    vec2.VectorUp();
    cout << vec2;

    //vector 3
    cout << "\n\n ������ " << MAX << " ��������(-��) ��� �������:" << endl;
    cin >> vec3;
    cout << "\n ���� �������:" << endl;
    cout << vec3;
    cout << " ������ ���� ����������:" << endl;
    vec3.VectorUp();
    cout << vec3;

    cout << "\n ��������� ������� �� ��������� ���������� ��������:\n\n ���� 1 - ������ ������ ������ �� ������\n ���� 0 - ������� \n ���������: " << endl;
    bool compare = (*arrayVecor[0]) < (*arrayVecor[1]);
    cout << "   " << compare << endl;

    cout << "��������� ������� ������� � ��������� � ��������� ���������� ���������� ��������" << endl;
    double multiply = (*arrayVecor[0]) * (*arrayVecor[2]);
    printf("%10f\n\n", multiply);

    system("pause");
    return 0;
}