#include <iostream>
#include <string>

using namespace std;

void printLevels(int level) {
    if (level < 4) {

    }
}

void rearrangements(string first, string second, int count) {
    // count keeps track of how deep we are in the recurrsion

    // case that prints when weve hit bottom case 
    if (count == first.size() - 1) {
        cout << first + second << endl;
    }
    else {
        for (int i = count; i <= first.size()-1; i++) {
            swap(first[count], first[i]);
            rearrangements(first, second, count + 1);
            swap(first[count], first[i]);
        }
    }
}

int main() {
    rearrangements("CAT","MAN", 0);
    return 0;
}