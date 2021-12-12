#include <string>
#include <iostream>
#include "Animal.h"
#include <map>
#include <fstream>

void saveInformationInFile(vector<Animal> allAnimal, ofstream& ofile, ifstream& ifile) {
	if (!allAnimal.empty()) {
		for (int i = 0; i < allAnimal.size(); i++) {
			ofile.write((char*)&allAnimal[i], sizeof(Animal));
		}
	}
	ifile.close();
	ofile.close();
}

int main()
{
	setlocale(LC_ALL, "ru");
	map<string, int> animals;
	int max, min;
	Animal in("unknown", "unknown", "unknown", 1);
	map<string, int> ::iterator i1;
	vector<Animal> allAnimal;
	string info;
	int position = 0;
	ifstream ifile;
	ifile.open("input.txt");
	if (!(ifile.peek() == EOF)) {
		while (ifile.read((char*)&in, sizeof(Animal))) {
			allAnimal.push_back(in);
			position++;
		}
	}
	int action;
	ofstream ofile;
	ofile.open("input.txt", fstream::out);
	while (true) {
		system("cls");
		cout << "Консольное меню: " << endl;
		cout << "Введите '1' для добавления нового животного." << endl;
		cout << "Введите '2' для удаления информации о животном." << endl;
		cout << "Введите '3' для вывода информации о конкретном животном." << endl;
		cout << "Введите '4' для вывода животных с одинаковой кличкой." << endl;
		cout << "Введите '5' для вывода информации о самом старом и самом молодом животном каждого вида." << endl;
		cout << "Введите '6' для подсчёта количества различных видов животных у каждого владельца." << endl;
		cout << "Введите '7' для вывода информации о всех данных." << endl;
		cout << "Введите '0' для выхода из консольного приложения." << endl;
		cout << "=================================================" << endl;
		cin >> action;
		switch (action) {
		case 0:
			system("cls");
			cout << "Работа приложения завершена.";
			saveInformationInFile(allAnimal, ofile, ifile);
			exit(0);
			break;
		case 1:
			system("cls");
			try {
				string owner, typeOfAnimal, alias;
				int age;
				cin.ignore();
				cout << "Введите вид животного(*)";
				getline(cin, typeOfAnimal);
				cout << "Введите кличку животного(не обязательно)";
				getline(cin, alias);
				cout << "Введите возраст животного(*)";
				cin >> age;
				cout << "Введите владельца животного(*)";
				cin.ignore();
				getline(cin, owner);
				Animal temp(owner, typeOfAnimal, alias, age);
				allAnimal.push_back(temp);
			}
			catch (exception e) {
				cout << e.what();
				saveInformationInFile(allAnimal, ofile, ifile);
				exit(0);
			}
			cout << "Информация успешно добавлена." << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			if (allAnimal.empty()) {
				cout << "Информация ещё не добавлена." << endl;
				system("pause");
				break;
			}
			cout << "Информация о всех данных." << endl;
			for (int i = 0; i < allAnimal.size(); i++) {
				cout << "id №" << i << " - " << allAnimal[i] << endl;
			}
			cout << "Введите id для удаления, либо введите 0 для выхода." << endl;
			cin >> action;
			switch (action) {
			case 0:
				break;
			default:
				allAnimal.erase(allAnimal.begin() + action);
				cout << "Информация удалена." << endl;
				system("pause");
			}
			break;
		case 3:
			system("cls");
			if (allAnimal.empty()) {
				cout << "Информация ещё не добавлена." << endl;
				system("pause");
				break;
			}
			cout << "Введите вид животного." << endl;
			cin.ignore();
			getline(cin, info);
			cout << "=======================================" << endl;
			for (int i = 0; i < allAnimal.size(); i++) {
				if (allAnimal[i].getTypeOfAnimal() == info) cout << allAnimal[i] << endl;
			}
			system("pause");
			break;
		case 4:
			system("cls");
			if (allAnimal.empty()) {
				cout << "Информация ещё не добавлена." << endl;
				system("pause");
				break;
			}
			cout << "Введите кличку животного." << endl;
			cin.ignore();
			getline(cin, info);
			cout << "=======================================" << endl;
			for (int i = 0; i < allAnimal.size(); i++) {
				if (allAnimal[i].getAlias() == info) cout << allAnimal[i] << endl;
			}
			system("pause");
			break;
		case 5:
			system("cls");
			if (allAnimal.empty()) {
				cout << "Информация ещё не добавлена." << endl;
				system("pause");
				break;
			}
			for (int i = 0; i < allAnimal.size(); i++) {
				if (animals.count(allAnimal[i].getTypeOfAnimal()) == 0) {
					animals.insert(make_pair(allAnimal[i].getTypeOfAnimal(), 1));
				}
			}
			for (i1 = animals.begin(); i1 != animals.end(); i1++) {
				max = -1;
				min = 9999L;
				for (int i = 0; i < allAnimal.size(); i++) {
					if (i1->first == allAnimal[i].getTypeOfAnimal()) {
						if (allAnimal[i].getAge() > max) max = allAnimal[i].getAge();
						if (allAnimal[i].getAge() < min) min = allAnimal[i].getAge();
					}
				}
				cout << "Вид животного : " << i1->first << ". Минимальный возраст - " << min << ". Максимальный возраст - " << max << "." << endl;
			}
			animals.clear();
			system("pause");
			break;
		case 6:
			system("cls");
			if (allAnimal.empty()) {
				cout << "Информация ещё не добавлена." << endl;
				system("pause");
				break;
			}
			for (int i = 0; i < allAnimal.size(); i++) {
				if (animals.count(allAnimal[i].getTypeOfAnimal()) == 0) {
					animals.insert(make_pair(allAnimal[i].getTypeOfAnimal(), 1));
				}
				else {
					animals.at(allAnimal[i].getTypeOfAnimal())++;
				}
			}
			i1 = animals.begin();
			for (int i = 0; i1 != animals.end(); i1++, i++) {
				cout << "Вид животного : " << i1->first << ", количество " << i1->second << endl;
			}
			animals.clear();
			system("pause");
			break;
		case 7:
			system("cls");
			cout << "Информация о всех данных." << endl;
			for (int i = 0; i < allAnimal.size(); i++) {
				cout << allAnimal[i] << endl;
			}
			system("pause");
			break;
		default:
			cout << "Введена неверная цифра" << endl;
			system("pause");
			break;
		}
	}
}
