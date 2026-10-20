// S0139-STL-Linked-List-App.cpp 

#include <iostream>
#include <list>
using namespace std;

template <class T>
void showList(const list<T>& lst, string caption = "") {
    cout << endl << caption;
    for (auto n : lst) {
        cout << n << ", ";
    }
    cout << endl;
}

void experiment01() {
    list<int> l1{ 1, 5, 7, 11 };
    showList(l1, "l1: ");

    l1.push_back(22);
    showList(l1, "l1: ");

    l1.push_front(77);
    showList(l1, "l1: ");

    auto it = find(l1.begin(), l1.end(), 7);
    if (it == l1.end()) {
        cout << "Value NOT found " << endl;
    }
    else {
        l1.insert(it, 6);
    }
    showList(l1, "l1: ");

    //Traversing the list - Alternative ways
    auto it2 = l1.begin();
    while (it2 != l1.end()) {
        cout << " forward " << *it2 << endl;
        it2++;
        //it2 = next(it2);
        //it2 = it2 + 1;  //ERROR 
        //advance(it2, 1);
    }

    //Backward Traversal
    auto it3 = prev(l1.end());
    while (true) {
        cout << "Back " << *it3 << endl;
        if (it3 == l1.begin()) break;
        //it3--;  
        it3 = prev(it3);
    }

    //Backward traversal- - using reverse iterator
    for (auto it4 = l1.rbegin(); it4 != l1.rend(); it4++) {
        cout << " Rev-Iterator " << *it4 << endl;
    }
}

void experiment02() {
    list<int> l1{ 11, 15, 17, 22, 5, 8, 40, 7 };
    showList(l1, "l1: ");

    //Elegant (but slow) data retrieval
    int key = 5;


    do
    {
        cout << "Enter search key [-1 to end]: ";
        cin >> key;
        if (key == -1) break;

        auto it1 = find(l1.begin(), l1.end(), key);
        if (it1 == l1.end()) {
            cout << "Data not found " << endl;
        }
        else {
            cout << "Data found: " << *it1 << endl;
        }
    } while (true);


}

//------------------------------------------------------
int main()
{
    //experiment01();
    experiment02();
    cout << "All done!\n";
}

