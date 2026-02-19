#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        double sales[5][4] = {0}; 
        int salesperson, product;
        double amount;

        while (true) {
            cout << "\n SALESPERSON: ";
            cin >> salesperson;

            if (salesperson == 0)
                break;

            cout << "PRODUCT: ";
            cin >> product;

            cout << "AMOUNT: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;
        }

        cout << "\nSales Summary\n";
        cout << "Product\t1\t2\t3\t4\tTotal\n";

        double grandTotal = 0;

        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;
            cout << i + 1 << "\t";

            for (int j = 0; j < 4; j++) {
                cout << fixed << setprecision(2) << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        
        cout << "Total\t";
        for (int j = 0; j < 4; j++) {
            double columnTotal = 0;
            for (int i = 0; i < 5; i++) {
                columnTotal += sales[i][j];
            }
            cout << fixed << setprecision(2) << columnTotal << "\t";
        }

        cout << grandTotal << endl;

        cout << "\nRepeat again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
    