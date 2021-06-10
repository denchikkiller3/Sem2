/*Створити базовий клас УЧАСНИК УЧНІВСЬКИХ ЗМАГАНЬ (задаються назва змагання, дані про учня).
Створити похідні класи ДИПЛОМАНТ (задається дані про зайняте місце) та ПРИЗЕР (задаються зайняте місце і назва призу).
Для введених даних про зайняті місця відсортувати учнів за зростанням сумарної кількості дипломів або призів і
вивести дані про кількість дипломів або призів за кожне зайняте місце.
Для перевірки використати масив вказівників на об’єкти базового класу,
яким присвоїти адреси об’єктів похідних класів.*/
#include <iostream>
using namespace std;


class Participant {
protected:
	string fullName, subject, grade;
public:
	Participant() {}
	Participant(string name, string subject, string grade) {
		fullName = name;
		this->subject = subject;
		this->grade = grade;
	}

	virtual void getInfo() {
		cout << "Name: " << fullName << endl;
		cout << "Subject: " << subject << endl;
		cout << "Grade: " << grade << endl;
	}

	string getName() {
		return fullName;
	}
	string getSubject() {
		return subject;
	}
	string getGrade() {
		return grade;
	}
	virtual int getPlace() {
		return -1;
	}
};

class Graduate : public Participant {
protected:
	int place;
public:
	Graduate(string name, string subject, string grade, int place) :
		Participant(name, subject, grade) {
		this->place = place;
	}

	virtual void getInfo() {
		Participant::getInfo();
		cout << "Place: " << place << endl;
	}

	int getPlace() {
		return place;
	}
};

class Winner : public Graduate {
protected:
	string prizeName;
public:
	Winner(string name, string subject, string grade, int place, string prize) :
		Graduate(name, subject, grade, place) {
		prizeName = prize;
	}

	virtual void getInfo() {
		Graduate::getInfo();
		cout << "Prize: " << prizeName << endl;
	}

	string getPrize() {
		return prizeName;
	}
};

typedef struct places {
	int count, place;
};
typedef struct person {
	int countOfDiplomas;
	string name;
};

places** countPlaces(int count, Participant** graduates, int* ind) {
	places** list = new places * [count];
	for (int i = 0; i < count; i++)
		list[i] = new places;
	int index = 0;

	for (int i = 0; i < count; i++) {
		bool isFounded = false;
		for (int j = 0; j < index; j++) {
			if (list[j]->place == ((Graduate*)graduates[i])->getPlace()) {
				isFounded = true;
				list[j]->count++;
				break;
			}
		}
		if (!isFounded) {
			list[index]->place = ((Graduate*)graduates[i])->getPlace();
			list[index++]->count = 1;
		}
	}
	*ind = index;

	return list;
}

person** countDiplomas(int count, Participant** graduates, int* ind) {
	person** list = new person * [count];
	for (int i = 0; i < count; i++)
		list[i] = new person;
	int index = 0;

	for (int i = 0; i < count; i++) {
		bool isFounded = false;
		for (int j = 0; j < index; j++) {
			if (list[j]->name == graduates[i]->getName()) {
				isFounded = true;
				list[j]->countOfDiplomas++;
				break;
			}
		}
		if (!isFounded) {
			list[index]->name = graduates[i]->getName();
			list[index++]->countOfDiplomas = 1;
		}
	}
	*ind = index;

	return list;
}

void sortPersons(int count, person** graduates) {
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1 - i; j++)
			if (graduates[j]->countOfDiplomas > graduates[j + 1]->countOfDiplomas) {
				person p = *graduates[j];
				*graduates[j] = *graduates[j + 1];
				*graduates[j + 1] = p;
			}
	}
}


int main() {
	Participant** participants = new Participant * [10]{
		new Graduate("Vasyl", "Math", "11-B", 3),
		new Winner("Myhailo", "Math", "11-A", 2, "Medal"),
		new Graduate("Artem", "Chemistry", "10-B", 4),
		new Winner("Maksym", "Math", "9-C", 1, "Cup"),
		new Winner("Vasyl", "Chemistry", "11-B", 2, "Medal"),
		new Graduate("Dmytro", "Math", "10-A", 3),
		new Graduate("Oleksandr", "Math", "9-B", 5),
		new Winner("Yuriy", "Chemistry", "10-B", 1, "Cup"),
		new Graduate("Petro", "Chemistry", "10-A", 3),
		new Graduate("Petro", "Math", "10-A", 3)
	};

	int* index = new int;
	places** listOfPlaces = countPlaces(10, participants, index);

	for (int i = 0; i < *index; i++) {
		cout << "Place: " << listOfPlaces[i]->place << endl;
		cout << "Count of places: " << listOfPlaces[i]->count << endl << endl;
	}

	person** persons = countDiplomas(10, participants, index);
	sortPersons(*index, persons);
	for (int i = 0; i < *index; i++) {
		cout << "Name: " << persons[i]->name << endl;
		cout << "Count of diplomas: " << persons[i]->countOfDiplomas << endl << endl;
	}

	for (int i = 0; i < 10; i++) {
		participants[i]->getInfo();
		cout << endl;
	}

	delete[] participants;
	delete index;
	delete[] listOfPlaces;
	delete[] persons;
}
