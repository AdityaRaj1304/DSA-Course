#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    // Declaration
    unordered_set<int> us;

    // insert()
    us.insert(10);
    us.insert(20);
    us.insert(30);

    // emplace()
    us.emplace(40);

    // Duplicate insertion ignored
    us.insert(20);

    cout << "Elements: ";
    for(auto x : us) {
        cout << x << " ";
    }
    cout << endl;

    // size()
    cout << "Size: " << us.size() << endl;

    // empty()
    if(us.empty()) {
        cout << "Set is empty" << endl;
    } else {
        cout << "Set is not empty" << endl;
    }

    // find()
    auto it = us.find(20);
    if(it != us.end()) {
        cout << "20 Found" << endl;
    } else {
        cout << "20 Not Found" << endl;
    }

    // count()
    cout << "Count of 30: " << us.count(30) << endl;

    // erase(value)
    us.erase(10);

    cout << "After erasing 10: ";
    for(auto x : us) {
        cout << x << " ";
    }
    cout << endl;

    // erase(iterator)
    auto itr = us.find(40);

    if(itr != us.end()) {
        us.erase(itr);
    }

    cout << "After erasing 40: ";
    for(auto x : us) {
        cout << x << " ";
    }
    cout << endl;

    // begin() and end()
    cout << "Using iterators: ";

    for(auto it = us.begin(); it != us.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;


    // Bucket functions
    cout << "Bucket Count: " << us.bucket_count() << endl;

    cout << "Load Factor: " << us.load_factor() << endl;

    cout << "Bucket of 20: " << us.bucket(20) << endl;

    // rehash()
    us.rehash(20);

    cout << "Bucket Count after rehash: "
         << us.bucket_count() << endl;

    // clear()
    us.clear();

    // empty() after clear
    cout << "After clear, empty = "
         << us.empty() << endl;

    return 0;
}