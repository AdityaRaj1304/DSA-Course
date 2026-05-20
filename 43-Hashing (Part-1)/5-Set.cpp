#include <iostream>
#include <set>
using namespace std;

int main() {

    // Declaration
    set<int> s;

    // insert()
    s.insert(10);
    s.insert(30);
    s.insert(20);

    // emplace()
    s.emplace(40);

    // Duplicate ignored
    s.insert(20);

    // Traversal
    cout << "Elements: ";
    for(auto x : s) {
        cout << x << " ";
    }
    cout << endl;

    // size()
    cout << "Size: " << s.size() << endl;

    // empty()
    if(s.empty()) {
        cout << "Set is empty" << endl;
    } else {
        cout << "Set is not empty" << endl;
    }

    // find()
    auto it = s.find(20);

    if(it != s.end()) {
        cout << "20 Found" << endl;
    } else {
        cout << "20 Not Found" << endl;
    }

    // count()
    cout << "Count of 30: " << s.count(30) << endl;

    // erase(value)
    s.erase(10);

    cout << "After erasing 10: ";
    for(auto x : s) {
        cout << x << " ";
    }
    cout << endl;

    // erase(iterator)
    auto itr = s.find(40);

    if(itr != s.end()) {
        s.erase(itr);
    }

    cout << "After erasing 40: ";
    for(auto x : s) {
        cout << x << " ";
    }
    cout << endl;

    // begin() and end()
    cout << "Using iterators: ";

    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration
    cout << "Reverse order: ";

    for(auto it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // lower_bound()
    auto lb = s.lower_bound(20);

    if(lb != s.end()) {
        cout << "Lower Bound of 20: " << *lb << endl;
    }

    // upper_bound()
    auto ub = s.upper_bound(20);

    if(ub != s.end()) {
        cout << "Upper Bound of 20: " << *ub << endl;
    }


    // equal_range()
    auto p = s.equal_range(20);

    cout << "Equal Range First: ";

    if(p.first != s.end()) {
        cout << *p.first << endl;
    }

    // swap()
    set<int> s2;

    s2.insert(100);
    s2.insert(200);

    s.swap(s2);

    cout << "After swap, s contains: ";

    for(auto x : s) {
        cout << x << " ";
    }
    cout << endl;

    // clear()
    s.clear();

    cout << "After clear, empty = "
         << s.empty() << endl;

    return 0;
}