#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

string name;
string answer;

void clearScreen() {
    system("cls");
}

void askQuestion(const string &question, const string &optionA, const string &optionB, const string &optionC, char correctAnswer, int &score) {
    clearScreen();
    cout << question << endl;
    cout << "a) " << optionA << endl;
    cout << "b) " << optionB << endl;
    cout << "c) " << optionC << endl;
    cout << "Twoja odpowiedz: ";
    cin >> answer;

    if (answer == correctAnswer) {
        cout << "Dobra odpowiedz!" << endl;
        score++;
    } else {
        cout << "Zle! Poprawna odpowiedz: '" << correctAnswer << "'." << endl;
    }

    Sleep(2000);
}

int main() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, 9);
    cout << "\aImie: ";
    cin >> name;
    int points = 0;

    clearScreen();
    cout << "3";
    Sleep(1000);
    clearScreen();
    cout << "3..2";
    Sleep(1000);
    clearScreen();
    cout << "3..2..1..";
    Sleep(1000);
    clearScreen();

    cout << name << ", Witaj w quizie!!!" << endl;

    askQuestion("Jaki kon widzi tak samo z przodu i z tylu?", " W okularach", "Slepy", "Spostrzegawczy", 'b', points);
    askQuestion("Ktore kolo najmniej sie zuzywa na zakretach?", " Prawe przednie", "Lewe tylnie", "Zapasowe", 'c', points);
    askQuestion("Jaki kolor jest najbardziej wystrzalowy?", "Granat", "Czern", "Czerwien", 'a', points);
    askQuestion("Kto jest synem Twojego ojca, ale nie jest Twoim rodzenstwem?", "Adoptowany syn taty", "Ja", "Taka osoba nie moze istniec!", 'b', points);

    clearScreen();
    cout << "Gratulacje, ukonczyles quiz!" << endl;
    cout << "Liczba punktow: " << points << "/4" << endl;

    if (points == 1) {
        cout << "Nastepnym razem bedzie lepiej!" << endl;
    } else if (points >= 2 && points <= 4) {
        cout << "DObra robota!" << endl;
    } else if (points == 5) {
        cout << "Jestes najlepszy!" << endl;
    }

    return 0;
}
