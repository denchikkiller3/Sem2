#include <iostream>
#include <stdlib.h>
using namespace std;

class myVector {
private:
    double* parr;
    int* pqntt;
public:
    //����������� ��� ���������
    myVector() {
        cout << "\n����������� ��� ���������" << endl;
        this->parr = new double{ 0 };
        this->pqntt = new int{ 0 };
    }
    //����������� � �����������
    myVector(int qntt) {
        cout << "\n����������� � �����������" << endl;
        this->pqntt = new int{ qntt };
        this->parr = new double[qntt];
    }
    //����������� ���������
    myVector(const myVector& object) {
        cout << "\n����������� ���������" << endl;
        this->pqntt = new int{ *object.pqntt };
        this->parr = new double[*object.pqntt];
        for (int i = 0; i < *pqntt; i++)
            this->parr[i] = object.parr[i];
    }
    //����������
    ~myVector() {
        cout << "����������" << endl;
        delete[] parr;
        delete pqntt;
    };
    //������� �����
    void VectorInput() {
        line();
        cout << "������ ������ (" << *pqntt << " ��������) : " << endl;
        for (int i = 0; i < *pqntt; i++) {
            cout << "arr[" << i << "]" << ": ";
            cin >> parr[i];
        }
        cout << endl;
    }
    //������� ������
    void VectorOutput() {
        line();
        cout << "���� �������:" << endl;
        for (int i = 0; i < *pqntt; i++) {
            cout << parr[i] << endl;
        }
    }
    //������� ����������� �������� �� ������������� �������� �������
    void VectorMinMax() {
        double min = 0, max = 0;
        for (int i = 0; i < *pqntt; i++) {
            if (parr[i] >= max)
                max = parr[i];
            if (parr[i] <= min)
                min = parr[i];
        }
        line();
        cout << "̳������� �������� ������� � " << min << endl;
        cout << "����������� �������� ������� � " << max << endl;
    }
    //������� ���������� �� ���������
    void VectorUp() {
        line();
        cout << "������ �������������� �� ���������..." << endl;
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
    //������� ��������� �� ��������
    void VectorDown() {
        line();
        cout << "������ �������������� �� ��������" << endl;
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

    //����� ��, ��� ���������� ���� ������� ��� ��������� ������� ������������
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
