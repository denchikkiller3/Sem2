/*
  Створити базовий клас УЧАСНИК УЧНІВСЬКИХ ЗМАГАНЬ (задаються назва змагання, дані про учня).
  Створити похідний клас ДИПЛОМАНТ (задається дані про зайняте місце) . Для введених даних про
  зайняті місця відсортувати учнів за зростанням сумарної кількості дипломів і вивести дані про
  кількість дипломів за кожне зайняте місце.
*/

#include <iostream>
#include <string>
#define QNTT 6

using namespace std;

class Student {
protected: //захищені поля, доступні при наслідуванні в дочірньому класі
    string competition;
    string name;
    string surname;
public:
    Student(string Competition, string name, string surname) :
        competition(Competition), name(name), surname(surname) {}
    ~Student() {}
};

class Dimplomant : public Student {
private:
    int place;
    int diplomaQntt;
    int firstPlaceQntt;
    int secondPlaceQntt;
    int thirdPlaceQntt;
public:
    //Виклик коструктора класу з наслідуванням Student
    Dimplomant(
        string competition = "None", string name = "None", string surname = "None", int place = 0, int diplomaQntt = 0,
        int firstPlaceQntt = 0, int secondPlaceQntt = 0, int thirdPlaceQntt = 0
    ) : Student(competition, name, surname), place(place), diplomaQntt(diplomaQntt),
        firstPlaceQntt(firstPlaceQntt), secondPlaceQntt(secondPlaceQntt), thirdPlaceQntt(thirdPlaceQntt) {}

    ~Dimplomant() {}


    //Геттери
    string getName() { return name; }
    string getSurname() { return surname; }
    string getCompetition() { return competition; }
    int getPlace() { return place; }
    int getFirstPlaceQntt() { return firstPlaceQntt; }
    int getSecondPlaceQntt() { return secondPlaceQntt; }
    int getThirdPlaceQntt() { return thirdPlaceQntt; }
    int getDiplomaQntt() { return diplomaQntt; }

    //Сеттери
    void setName(string name) { this->name = name; }
    void setSurname(string surname) { this->surname = surname; }
    void setPlace(int place) { this->place = place; }
    void setFirstPlaceQntt(int firstPlaceQntt) { this->firstPlaceQntt = firstPlaceQntt; }
    void setSecondPlaceQntt(int secondPlaceQntt) { this->secondPlaceQntt = secondPlaceQntt; }
    void setThirdPlaceQntt(int thirdPlaceQntt) { this->thirdPlaceQntt = thirdPlaceQntt; }
    void setCompetition(string competition) { this->competition = competition; }
    void setDiplomaQntt(int diplomaQntt) { this->diplomaQntt = diplomaQntt; }

    friend istream& operator >> (istream& in, Dimplomant& obj);
    friend ostream& operator << (ostream& out, Dimplomant& obj);

    bool operator <(const Dimplomant& obj) {
        return this->diplomaQntt < obj.diplomaQntt;
    }

    bool operator !=(const Dimplomant& obj) {
        return !(this->name == obj.name && this->surname == obj.surname);
    }

    bool operator ==(const Dimplomant& obj) {
        return this->name == obj.name && this->surname == obj.surname;
    }
};

istream& operator >> (istream& in, Dimplomant& obj) {
    string buffer;
    int bufferInt;

    cout << "\nEnter name of student : ";
    in >> buffer;
    obj.setName(buffer);
    cout << "Enter surname of student : ";
    in >> buffer;
    obj.setSurname(buffer);
    cout << "Enter competition's name for student : ";
    in >> buffer;
    obj.setCompetition(buffer);
    cout << "Enter place for student : ";
    in >> bufferInt;
    obj.setPlace(bufferInt);
    return in;
}

ostream& operator << (ostream& out, Dimplomant& obj) {
    printf_s("\t%-10s%-10s%-15s%-10d%-7d%-7d%-7d\n", obj.getName().c_str(), obj.getSurname().c_str(),
        obj.getCompetition().c_str(), obj.getDiplomaQntt(), obj.getFirstPlaceQntt(), obj.getSecondPlaceQntt(), obj.getThirdPlaceQntt());
    return out;
}

void inputData(Dimplomant* st);
void studentSort(Dimplomant* st);
void swap(Dimplomant* st1, Dimplomant* st2);
void placeCounter(Dimplomant* st);
void printData(Dimplomant* st);
void diplomaCounter(Dimplomant* st);

int main() {

    Dimplomant st[QNTT];

    inputData(st);
    studentSort(st);
    printData(st);

    return 0;
}

//Функція вводу данних
void inputData(Dimplomant* st) {
    for (int i = 0; i < QNTT; i++)
        cin >> st[i];
}
//Функція сортування по-зростанню
void studentSort(Dimplomant* st) {
    diplomaCounter(st);
    for (int startIndex = 0; startIndex < QNTT - 1; ++startIndex) {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < QNTT; ++currentIndex) {
            if (st[currentIndex] < st[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(st[startIndex], st[smallestIndex]);
    }
    placeCounter(st);
}

// Підфункція studentSort`a для для визначення кількості дипломів
void diplomaCounter(Dimplomant* st) {
    for (int i = 0; i < QNTT; i++) {
        int temp = st[i].getDiplomaQntt();
        for (int j = 0; j < QNTT; j++) {
            if (st[i] == st[j]) {
                temp++;
                st[i].setDiplomaQntt(temp);
            }
        }
    }
}

// Підфункція studentSort`a для обчислення кількості перших, других та третіх місць
void placeCounter(Dimplomant* st) {
    for (int i = 0; i < QNTT; i++) {
        int first = st[i].getFirstPlaceQntt(), second = st[i].getSecondPlaceQntt(), third = st[i].getThirdPlaceQntt();
        switch (st[i].getPlace()) {
        case 1: first++; st[i].setFirstPlaceQntt(first); continue;
        case 2: second++; st[i].setSecondPlaceQntt(second); continue;
        case 3: third++; st[i].setThirdPlaceQntt(third); continue;
        default: 0;
        }
    }
}

// Підфункція studentSort`a для обміну данними
void swap(Dimplomant* st1, Dimplomant* st2) {
    Dimplomant* temp = st2;
    st2 = st1;
    st1 = temp;
}

// Функція виводу данних
void printData(Dimplomant* st) {
    printf_s("\n\n\t\t\t\t---------------\n\t\t\t\t| SORTED DATA |\n\t\t\t\t---------------\n\t%-10s%-10s%-15s%-10s%-7s%-7s%-7s\n\n", "Name", "Surname", "Competition", "Dimplomas", "1-st", "2-nd", "3-th");
    for (int i = 0; i < QNTT; i++) {
        cout << st[i];
    }
}