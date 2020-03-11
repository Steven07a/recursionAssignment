#include <iostream>
#include <string>

using namespace std;

void rearrangements(string first, string second, int count) {
    string temp = "";
    int length = first.length();
    if (count == first.length() - 1) {
        cout << first << endl;
    } else {
        for (int i = count; i < first.length(); i++) {
            temp = first[count];
            if (count <= first.length()) {
                if (i == length - 1) {
                    temp = first[i];
                    first.erase(i, 1);
                    first.insert(count, 1, temp[0]);
                } else {
                    first.erase(count, 1);
                    first.insert(i, 1, temp[0]);
                }
            }
            rearrangements(first, second, count+1);
        }
    }
}

int main()
{
    int count = 0;
    rearrangements("cats", "fish",count);
}

