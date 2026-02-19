#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int students, quizzes;

        cout << "ENTER NUMBER of STUDENTS: ";
        cin >> students;

        cout << "ENTER NUMBER OF QUIZZES: ";
        cin >> quizzes;

        double scores[100][100];
        double average[100];

        
        for (int i = 0; i < students; i++) {
            double sum = 0;
            cout << "\nSTUDENT" << "\t" << i + 1 << "-" <<"SCORE"<<":\n";

            for (int j = 0; j < quizzes; j++) {
              cout << "QUIZ " << j + 1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = sum / quizzes;
        }

        cout << "\n";
        cout << left << setw(10) << "STUDENT";

        for (int j = 0; j < quizzes; j++) {
            cout << setw(6) << ("Q" + to_string(j + 1));
        }

        cout << setw(10) << "AVERAGE" << endl;

        for (int i = 0; i < students; i++) {
            cout << left << setw(10) << i + 1;

            for (int j = 0; j < quizzes; j++) {
                cout << setw(6) << (int)scores[i][j];  
            }

            cout << fixed << setprecision(2)
                 << setw(10) << average[i] << endl;
        }

        cout << "\nREPEAT AGAIN? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
