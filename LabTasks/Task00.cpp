#include <iostream>
using namespace std;

int main()
{
    //Declare variables and data types, naming convention [array][type][name]
    int iCount;
    int aiNumbers[10];
    int iSum = 0;

    do {
        //Prompt input count
        cout << "Count:" << endl;
        cin >> iCount;

        //Valid prompt 
        if (iCount < 1 || iCount > 10) {
            cout << "Please select a count between 1-10" << endl;
        }
    } while (iCount < 1 || iCount > 10);

    //Input loop
    for (int i = 0; i < iCount; ++i) {
        cout << "Number:" << endl;
        cin >> aiNumbers[i];
        iSum = iSum + aiNumbers[i];
    }

    //Output number with current index
    for (int i = 0; i < iCount; ++i) {
        cout << "Number[" << i << "]: " << aiNumbers[i] << endl;
    }

    //Static cast to convert int to double 
    double dAverage = static_cast<double>(iSum) / iCount;
    //Output average
    cout << "Average: " << dAverage << endl;

    return 0;
}
