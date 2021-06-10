#include <iostream>
#include <stdlib.h>
using namespace std;

class myVector {
private:
    double* parr;
    int* pqntt;
public:
    //Конструктор без параметрів
    myVector() {
        cout << "\nКонструктор без параметрів" << endl;
        this->parr = new double{ 0 };
        this->pqntt = new int{ 0 };
    }
    //Конструктор з параметрами
    myVector(int qntt) {
        cout << "\nКонструктор з параметрами" << endl;
        this->pqntt = new int{ qntt };
        this->parr = new double[qntt];
    }
    //Конструктор копіювання
    myVector(const myVector& object) {
        cout << "\nКонструктор копіювання" << endl;
        this->pqntt = new int{ *object.pqntt };
        this->parr = new double[*object.pqntt];
        for (int i = 0; i < *pqntt; i++)
            this->parr[i] = object.parr[i];
    }
    //Деструктор
    ~myVector() {
        cout << "Деструктор" << endl;
        delete[] parr;
        delete pqntt;
    };
    //Функція вводу
    void VectorInput() {
        line();
        cout << "Введіть вектор (" << *pqntt << " елементів) : " << endl;
        for (int i = 0; i < *pqntt; i++) {
            cout << "arr[" << i << "]" << ": ";
            cin >> parr[i];
        }
        cout << endl;
    }
    //Функція виводу
    void VectorOutput() {
        line();
        cout << "Вивід вектора:" << endl;
        for (int i = 0; i < *pqntt; i++) {
            cout << parr[i] << endl;
        }
    }
    //Функція знаходження мінімально та таксимального значення вектора
    void VectorMinMax() {
        double min = 0, max = 0;
        for (int i = 0; i < *pqntt; i++) {
            if (parr[i] >= max)
                max = parr[i];
            if (parr[i] <= min)
                min = parr[i];
        }
        line();
        cout << "Мінімальне значення вектора є " << min << endl;
        cout << "Максимальне значення вектора є " << max << endl;
    }
    //Функція сортування по зростанню
    void VectorUp() {
        line();
        cout << "Вектор пересортований по зростанню..." << endl;
        for (int j = 0; j < *pqntt; ++j)
        {
            for (int i = 0; i < *pqntt - j - 1; ++i)
            {
                if (parr[i] > parr[i + 1]) {
                    swap(parr[i], parr[i + 1]);
                }
            }
        }
    }
    //Функція сортуання по спадання
    void VectorDown() {
        line();
        cout << "Вектор пересортований по спаданню" << endl;
        for (int j = 0; j < *pqntt - 1; ++j)
        {
            for (int i = 0; i < *pqntt - j - 1; ++i)
            {
                if (parr[i] < parr[i + 1]) {
                    swap(parr[i], parr[i + 1]);
                }
            }
        }
    }

    //Функія лінії, яка відокремлює інші функції для простішого читання користувачем
    void line() {
        cout << "-----------------------------------------------" << endl;
    }
};

int main() {
    system("chcp 1251");

    myVector* vec1 = new myVector;
    myVector vec2(10);

    vec1->VectorInput();
    vec1->VectorOutput();
    vec1->VectorMinMax();
    vec1->VectorDown();
    vec1->VectorUp();
    vec1->VectorInput();
    vec1->VectorOutput();

    vec2.VectorInput();
    vec2.VectorOutput();
    vec2.VectorMinMax();
    vec2.VectorDown();
    vec2.VectorOutput();
    vec2.VectorUp();
    vec2.VectorOutput();

    myVector vec3(vec2);

    vec3.VectorOutput();
    vec3.VectorInput();
    vec3.VectorMinMax();
    vec3.VectorDown();
    vec3.VectorOutput();
    vec3.VectorUp();
    vec3.VectorOutput();

    vec2.VectorOutput();

    delete vec1;

    system("pause");
    return 0;
}
