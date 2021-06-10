
#include <iostream>
#include <stdlib.h>
#define MAX 11
using namespace std;

class myVector {
private:
    double arr[MAX];
    int qntt;
public:
    //�����������
    myVector() {
        arr[MAX - 1] = 0;
        qntt = 0;
    }
    myVector(double cnstrArr, int cnstrQntt) {
        arr[MAX - 1] = cnstrArr;
        qntt = cnstrQntt;
    }
    //����������
    ~myVector() {
        cout << "class is not working" << endl;
    };
    //������� �����
    void VectorInput() {
        line();
        cout << "������ ������:" << endl;
        for (int i = 0; i < qntt; i++) {
            cout << "arr[" << i << "]" << ": ";
            cin >> arr[i];
            //qntt = i;
        }
        cout << endl;
    }
    //������� ������
    void VectorOutput() {
        line();
        cout << "���� �������:" << endl;
        for (int i = 0; i < qntt; i++) {
            cout << arr[i] << endl;
        }
    }
    //������� ����������� �������� �� ������������� �������� �������
    void VectorMinMax() {
        double min = 0, max = 0;
        for (int i = 0; i < qntt; i++) {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
        line();
        cout << "̳������� �������� ������� � " << min << endl;
        cout << "����������� �������� ������� � " << max << endl;
    }
    //������� ���������� �� ���������
    void VectorUp() {
        line();
        cout << "������ �������������� �� ���������..." << endl;
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
    //������� ��������� �� ��������
    void VectorDown() {
        line();
        cout << "������ �������������� �� ��������" << endl;
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

    //����� ��, ��� ���������� ���� ������� ��� ��������� ������� ��� �����������
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