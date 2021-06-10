
#include <iostream>
#include <stdlib.h>
#define MAX 11
using namespace std;

class myVector {
private:
    double arr[MAX];
    int qntt;
public:
    //Конструктор
    myVector() {
        arr[MAX - 1] = 0;
        qntt = 0;
    }
    myVector(double cnstrArr, int cnstrQntt) {
        arr[MAX - 1] = cnstrArr;
        qntt = cnstrQntt;
    }
    //Деструктор
    ~myVector() {
        cout << "class is not working" << endl;
    };
    //Функція вводу
    void VectorInput() {
        line();
        cout << "Введіть вектор:" << endl;
        for (int i = 0; i < qntt; i++) {
            cout << "arr[" << i << "]" << ": ";
            cin >> arr[i];
            //qntt = i;
        }
        cout << endl;
    }
    //Функція виводу
    void VectorOutput() {
        line();
        cout << "Вивід вектора:" << endl;
        for (int i = 0; i < qntt; i++) {
            cout << arr[i] << endl;
        }
    }
    //Функція знаходження мінімально та таксимального значення вектора
    void VectorMinMax() {
        double min = 0, max = 0;
        for (int i = 0; i < qntt; i++) {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
        line();
        cout << "Мінімальне значення вектора є " << min << endl;
        cout << "Максимальне значення вектора є " << max << endl;
    }
    //Функція сортування по зростанню
    void VectorUp() {
        line();
        cout << "Вектор пересортований по зростанню..." << endl;
        for (int j = 0; j < qntt; ++j)
        {
            for (int i = 0; i < qntt - j - 1; ++i)
            {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                }
            }
        }
    }
    //Функція сортуання по спадання
    void VectorDown() {
        line();
        cout << "Вектор пересортований по спаданню" << endl;
        for (int j = 0; j < qntt - 1; ++j)
        {
            for (int i = 0; i < qntt - j - 1; ++i)
            {
                if (arr[i] < arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                }
            }
        }
    } 

    //Функія лінії, яка відокремлює інші функції для простішого читання для користувача
    void line() {
        cout << "-----------------------------------------------" << endl;
    }
};

int main() {

    setlocale(LC_ALL, "Ukrainian");

    myVector vec(0, 10);
    vec.VectorInput();
    vec.VectorOutput();
    vec.VectorMinMax();
    vec.VectorDown();
    vec.VectorOutput();
    vec.VectorUp();
    vec.VectorOutput();

    system("pause");
    return 0;
}