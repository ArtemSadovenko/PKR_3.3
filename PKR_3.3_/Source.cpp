#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>
#include <windows.h> 

using namespace std;

struct Student
{
	string lname;
	char B;
	char I;
	int math;
	int fis;
	int pkr;
	int oop;
	int angl;
};

void print(Student* s, int n);
void print(Student* s, int* q, int qn);
void write(Student* s, int& n);
int menu();
void LoadFromFile(Student*& s, int& n, string name);
void LoadToFile(Student* s, int n, string name);
void find_all_5(Student* s, int n, int* q, int qn);
int to_5(Student* s, int n);
void find_with_3(Student* s, int n, int* q, int qn);
int to_3(Student* s, int n);
void find_one_2(Student* s, int n, int* q, int qn);
int to_2(Student* s, int n);
bool check(int math, int pkr, int oop, int angl, int fis);
bool check(int math);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n = 1;
	Student* s = new Student[n];
	int com;
	int* q;
	int qn;
	
	do {
		do {
			com = menu();
		} while (check(com));

		switch (com) {
		case 1:
			cout << "Введіть кількість: "; cin >> n;
			s = new Student[n];
			write(s, n);
			break;
		case 2:
			print(s, n);
			break;
		case 3:
			LoadFromFile(s, n, "file.txt");
			print(s, n);
			break;
		case 4:
			cin.get(); 
			cin.sync(); 
			LoadToFile(s, n, "file.txt");
			break;
		case 5:
			qn = to_5(s, n);
			if (qn == 0) {
				cout << "Null\n";
				break;
			}
			q = new int[qn];
			find_all_5(s, n, q, qn);
			print(s, q, qn);
			break;
		case 6:
			qn = to_3(s, n);
			if (qn == 0) {
				cout << "Null\n";
				break;
			}
			q = new int[qn];
			find_with_3(s, n, q, qn);
			print(s, q, qn);
			break;
		case 7:
			qn = to_2(s, n);
			if (qn == 0) {
				cout << "Null\n";
				break;
			}
			q = new int[qn];
			find_one_2(s, n, q, qn);
			print(s, q, qn);
			break;
		case 0:
			break;
		}

	} while (com != 0);

	return 0;
}

void print(Student* s, int n) {
	cout << "---------------------------------------------------------" << endl;
	cout << "|      Студент      | Матем | Фізика | ПКР | ООП | Англ |" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		cout << "|" << setw(13) << s[i].lname << " " << s[i].I << "." << s[i].B << ". " << "|"
			<< setw(7) << s[i].math << "|" << setw(8) << s[i].fis << "|" << setw(5) << s[i].pkr << "|"
			<< setw(5) << s[i].oop << "|" << setw(6) << s[i].angl << "|\n" <<
			"---------------------------------------------------------" << endl;
	}
}

void print(Student* s, int* q, int qn) {
	cout << "---------------------------------------------------------" << endl;
	cout << "|      Студент      | Матем | Фізика | ПКР | ООП | Англ |" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < qn; i++) {
		cout << "|" << setw(13) << s[q[i]].lname << " " << s[q[i]].I << "." << s[q[i]].B << ". " << "|"
			<< setw(7) << s[q[i]].math << "|" << setw(8) << s[q[i]].fis << "|" << setw(5) << s[q[i]].pkr << "|"
			<< setw(5) << s[q[i]].oop << "|" << setw(6) << s[q[i]].angl << "|\n" <<
			"---------------------------------------------------------" << endl;
	}
}

void write(Student* s, int& n) {

	for (int i = 0; i < n; i++) {
		do {
			cout << "Student " << i + 1 << endl;
			cout << "Enter last name: "; cin >> s[i].lname;
			cout << "Enter initial 1: "; cin >> s[i].I;
			cout << "Enter initial 2: "; cin >> s[i].B;
			cout << "Enter math: "; cin >> s[i].math;
			cout << "Enter physics: "; cin >> s[i].fis;
			cout << "Enter OOP: "; cin >> s[i].oop;
			cout << "Enter PKR: "; cin >> s[i].pkr;
			cout << "Enter Angl: "; cin >> s[i].angl;
			if (check(s[i].math, s[i].oop, s[i].pkr, s[i].fis, s[i].angl)) {
				cout << "Wrong input" << endl;
			}
		} while (check(s[i].math, s[i].oop, s[i].pkr, s[i].fis, s[i].angl));
		cout << endl;
	}
}

bool check(int math, int pkr, int oop, int angl, int fis) {
	if (math < 1 || math > 5 || pkr < 1 || pkr > 5 || oop < 1 || oop > 5 || angl < 1 || angl> 5 || fis < 1 || fis > 5) {
		return true;
	}
	return false;
}

int menu() {
	int n;
	cout << "Оберіть операцію:\n Ввести список(1)\n Вивести список(2)\n Вивести список з файлу(3)\n Зберегти список(4)\n Вивести студентів з усіма оцінками\"5\"(5)\n Вивести студентів з оцінками\"3\"(6)\n Вивести студентів з оцінками\"2\"(7)\n Вихід(0))\n";
	cin >> n;
	return n;
}

bool check(int math) {
	if (math == 0 || math == 1 || math == 2 || math == 3 || math == 4 || math == 5 || math == 6 || math == 7) {
		return false;
	}
	return true;
}

void find_all_5(Student* s, int n, int* q, int qn) {
	int k = 0;
	for (int i = 0; i < n; i++){
		if (s[i].angl == 5 && s[i].oop == 5 && s[i].math == 5 && s[i].pkr == 5 && s[i].fis == 5) {
			q[k] = i;
			k++;
		}
	}
}

int to_5(Student* s, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].angl == 5 && s[i].oop == 5 && s[i].math == 5 && s[i].pkr == 5 && s[i].fis == 5) {
			k++;
		}
	}
	return k;
}

void find_with_3(Student* s, int n, int* q, int qn) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].angl == 3 || s[i].oop == 3 || s[i].math == 3 || s[i].pkr == 3 || s[i].fis == 3) {
			q[k] = i;
			k++;
		}
	}
}

int to_3(Student* s, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].angl == 3 || s[i].oop == 3 || s[i].math == 3 || s[i].pkr == 3 || s[i].fis == 3 ) {
			k++;
		}
	}
	return k;
}

void find_one_2(Student* s, int n, int* q, int qn) {
	int k = 0;
	int r = 0;
	for (int i = 0; i < n; i++) {
		/*if (s[i].angl == 3 || s[i].oop == 3 || s[i].math == 3 || s[i].pkr == 3 || s[i].fis == 3) {
			k++;
		}*/
		if (s[i].angl == 2) {
			r++;
		}
		if (s[i].oop == 2) {
			r++;
		}
		if (s[i].pkr == 2) {
			r++;
		}
		if (s[i].fis == 2) {
			r++;
		}
		if (s[i].math == 2) {
			r++;
		}
		if (r == 1) {
			q[k] = i;
			k++;
		}
		r = 0;
	}
}

int to_2(Student* s, int n) {
	int k = 0;
	int r = 0;
	for (int i = 0; i < n; i++) {
		/*if (s[i].angl == 3 || s[i].oop == 3 || s[i].math == 3 || s[i].pkr == 3 || s[i].fis == 3) {
			k++;
		}*/
		if (s[i].angl == 2) {
			r++;
		}
		if (s[i].oop == 2) {
			r++;
		}
		if (s[i].pkr == 2) {
			r++;
		}
		if (s[i].fis == 2) {
			r++;
		}
		if (s[i].math == 2) {
			r++;
		}
		if (r == 1) {
			k++;
		}
		r = 0;
	}
	return k;
}

void LoadFromFile(Student*& s, int& n, string name) {

	delete[] s;
	fstream f;
	int i = 0;
	f.open(name);
	f >> n;
	s = new Student[n];
	while (!f.eof()) {
		f >> s[i].lname;
		f >> s[i].I;
		f >> s[i].B;
		f >> s[i].angl;
		f >> s[i].math;
		f >> s[i].fis;
		f >> s[i].oop;
		f >> s[i].pkr;
		i++;
	}
	
}

void LoadToFile(Student* s, int n, string name) {

	ofstream f;
	f.open(name , ios::trunc);
	f << n<< endl;
	for (int i = 0; i < n; i++) {
		f << s[i].lname << endl;
		f << s[i].I << endl;
		f << s[i].B<<endl;
		f << s[i].angl << endl;
		f << s[i].math << endl;
		f << s[i].fis << endl;
		f << s[i].oop << endl;
		f << s[i].pkr << endl;

	}

}