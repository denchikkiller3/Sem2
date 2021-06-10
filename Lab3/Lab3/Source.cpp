//Перевантажити операції < (порівняння векторів за значенням мінімального елемента), *(скалярний добуток двох векторів),
//відсортувати масив екземплярів класу векторів за зростанням значення мінімального елемента з використанням алгоритму сортування вибором,
//обчислити скалярний добуток векторів з найбільшим і найменшим значеннями мінімального елемента.

#include <iostream>
#include <stdlib.h>
#define MAX 3

using namespace std;

class myVector {
private:
    double arr[MAX];
    int qntt;
    double value; // записати мынымальны значення в змінну value
public:
    //Конструктор без параметрів
    myVector() {
        arr[MAX - 1] = 0;
        qntt = 0;
        value = 0;
    }
    //Конструктор з параметрами
    myVector(double cnstrArr, int cnstrQntt) {
        arr[MAX - 1] = cnstrArr;
        qntt = cnstrQntt;
        value = 0;
    }
    //Деструктор
    ~myVector() {};

    //Перевантаження операції " < "
    bool operator <(const myVector& const obj) {
        return this->getMinValue() < obj.getMinValue();
    }

    //Перевантаження операції " * "
    double operator *(const myVector& obj) {
        double temp;
        temp = this->getMaxValue() * obj.getMinValue();
        return temp;
    }
    //Перевантаження операторів для вводу/виводу
    friend ostream& operator << (ostream& out, const myVector& numb);
    friend istream& operator >> (istream& in, myVector& numb);

    //Функція виводу
    void VectorOutput(void) {
        cout << "Вивід вектора:" << endl;
        for (int i = 0; i < qntt; i++) {
            cout << arr[i] << endl;
        }
    }

    //Функція знаходження максимального значення вектора
    void VectorMax(void) {
        double max = 0;
        for (int i = 0; i < qntt; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        cout << "Максимальне значення вектора є " << max << endl;
    }

    //Функція сортування за зростанням методом вставки
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

    //Повернення мінімального значення масива
    double getMinValue(void) const {
        return this->arr[0];
    }

    //Повернення максимального значення масива
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

    // масив для векторів з типом myVector
    myVector vec1, vec2, vec3;
    myVector* arrayVecor[3] = { &vec1, &vec2, &vec3 };

    //vector 1
    cout << " Введіть " << MAX << " елементи(-ів) для вектора:" << endl;
    cin >> vec1;
    cout << "\n Вивід вектора:" << endl;
    cout << vec1;
    cout << " Вектор після сортування:" << endl;
    vec1.VectorUp();
    cout << vec1;

    //vector 2
    cout << "\n\n Введіть " << MAX << " елементи(-ів) для вектора:" << endl;
    cin >> vec2;
    cout << "\n Вивід вектора:" << endl;
    cout << vec2;
    cout << " Вектор після сортування:" << endl;
    vec2.VectorUp();
    cout << vec2;

    //vector 3
    cout << "\n\n Введіть " << MAX << " елементи(-ів) для вектора:" << endl;
    cin >> vec3;
    cout << "\n Вивід вектора:" << endl;
    cout << vec3;
    cout << " Вектор після сортування:" << endl;
    vec3.VectorUp();
    cout << vec3;

    cout << "\n Порівняння векторів за значенням мінімального елемента:\n\n Якщо 1 - другий вектор більший за перший\n Якщо 0 - навпаки \n Результат: " << endl;
    bool compare = (*arrayVecor[0]) < (*arrayVecor[1]);
    cout << "   " << compare << endl;

    cout << "Скалярний добуток векторів з найбільшим і найменшим значеннями мінімального елемента" << endl;
    double multiply = (*arrayVecor[0]) * (*arrayVecor[2]);
    printf("%10f\n\n", multiply);

    system("pause");
    return 0;
}