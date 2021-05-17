#include <iostream>
#include <vector>
using namespace std;

template<class Iter, class T>
Iter binary_find(Iter begin, Iter end, T val) {
    // lower_bound() повертає ітератор, який вказує на першу позицію в
    // відсортованії послідовності, обмеженою діапазоном [first, last),
    // в яку можна вставити значення value, не порушуючи впорядкованості.
    Iter i = lower_bound(begin, end, val);
    return i;
}

int main() {
    system("chcp 1251");
    int x, myint;
    vector<int> v1;

    // штучне заповнення елементів масиву (для прикладу)
    for (x = 1; x<=10; ++x) {
        v1.push_back((x*x*2)/(x+x));
    }

    cout << "Vector 1 has those numbers:\n";
    for (x = 0; x < v1.size(); ++x) {
        cout << v1.at(x) << " " ;
    }
    cout << "\n\n";

    vector<int> v2;
    // введення елементів у масив з консолі безпочередньо користувачем
    cout << "Please enter some integers (enter 0 to end):\n";
    do {
        cin >> myint;
        if (myint == 0) break;
        v2.push_back(myint);
    } while (1);

    cout << "Vector 2 stores " << v2.size() << " numbers:\n";
    for (x = 0; x < v2.size(); ++x) {
        cout << v2.at(x) << " " ;
    }
    cout << "\n\n";

    // бінарний пошук на прикладі строк
    vector<string> values = {"AAAAAA", "AB", "AD", "BCD", "CD", "DD"};
    vector<string> tests =  {"AB", "CD", "AD", "DD"};

    cout << "Strings \"AAAAAA\", \"AB\", \"AD\", \"BCD\", \"CD\", \"DD\".\n"
            "Search for \"AB\", \"CD\", \"AD\", \"DD\".\nBinary search...\n";

    for(x = 0 ; x < tests.size(); x++) {
        int pos = binary_find(values.begin(), values.end(), tests.at(x)) - values.begin();
        cout << tests.at(x) << " found at: " << pos << "\n";
    }
    
    return 0;
}
