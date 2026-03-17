#include <iostream>
#include <iomanip>
using namespace std;


void processGrades(double grades[][100], int numStudents, int numSubjects) {
  
    cout << "\nGrade Matrix:" << endl;
    cout << "Student\\Subject";
    for (int j = 0; j < numSubjects; j++) {
        cout << "     S" << (j + 1);
    }
    cout << endl;
    
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << (i + 1) << "      ";
        for (int j = 0; j < numSubjects; j++) {
            cout << fixed << setprecision(1) << setw(8) << grades[i][j];
        }
        cout << endl;
    }
    
    
    cout << "\nStudent Averages:" << endl;
    for (int i = 0; i < numStudents; i++) {
        double sum = 0;
        for (int j = 0; j < numSubjects; j++) {
            sum += grades[i][j];
        }
        double avg = sum / numSubjects;
        cout << "Student " << (i + 1) << " average: " 
             << fixed << setprecision(2) << avg << endl;
    }
    
   
    double highestGrade = grades[0][0];
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            if (grades[i][j] > highestGrade) {
                highestGrade = grades[i][j];
            }
        }
    }
    
    cout << "\nHighest grade in the matrix: " 
         << fixed << setprecision(2) << highestGrade << endl;
}

int main() {
    int numStudents, numSubjects;
    
    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << "Enter number of subjects: ";
    cin >> numSubjects;
    
    
    double grades[100][100];
    
    
    cout << "\nEnter grades for " << numStudents << " students and " 
         << numSubjects << " subjects:" << endl;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            cout << "Enter grade for Student " << (i + 1) 
                 << ", Subject " << (j + 1) << ": ";
            cin >> grades[i][j];
        }
    }
    
    
    processGrades(grades, numStudents, numSubjects);
    
    return 0;
}