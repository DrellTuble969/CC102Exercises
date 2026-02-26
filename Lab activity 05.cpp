#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int students, days;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of days: ";
        cin >> days;

        vector<vector<int>> attendance(students, vector<int>(days));

        
        for (int i = 0; i < students; i++) {
            cout << "Student " << i + 1 << " attendance: ";
            for (int j = 0; j < days; j++) {
                cin >> attendance[i][j];
            }
        }

        cout << "\n";
        
        cout << left << setw(8) << "Student";
        for (int d = 0; d < days; d++) {
            cout << setw(4) << ("D" + to_string(d + 1));
        }
        cout << setw(8) << "Total"
             << setw(12) << "Percentage"
             << setw(8) << "Remarks" << endl;

        
        cout << "----------------------------------------------------" << endl;

        
        for (int i = 0; i < students; i++) {
            int total = 0;

            cout << left << setw(8) << i + 1;

            for (int j = 0; j < days; j++) {
                cout << setw(4) << attendance[i][j];
                total += attendance[i][j];
            }

            double percentage = (double)total / days * 100;

            cout << setw(8) << total;
            cout << setw(12) << fixed << setprecision(0) << percentage << "%";

            if (percentage < 50)
                cout << setw(8) << "DRP";
            else
                cout << setw(8) << "OK";

            cout << endl;
        }

        cout << "\nRun program again? (y/n): ";
        cin >> again;

        cout << "\n";

    } while (again == 'y' || again == 'Y');

    return 0;
}