#include <iostream>
#include <string>

using namespace std;

void R1_levls(int level) {
    cout << "This was written by call number " << level+1 << endl;
    if (level < 3) {
        R1_levls(level+1);
    } 
    cout << "This ALSO written by call number " << level+1 << endl;
}

void R2_Box(string first, int level) {
    if (level < 9) {
        for (int i = 0; i < 9; i++) {
            cout << first << ":" << level + 1 << "." << i + 1 << endl;
        }
        R2_Box(first, level + 1);
    }
}

void R3_first_second(string first, string second, int level) {
    char temp, temp1;
    //this is the base case
    if (level == first.size() - 1) {
        cout << first + second << endl;
    } else {
        for (int i = level; i <= first.size()-1; i++) {
            temp = first[level];
            temp1 = first[i];
            first.erase(level,1);
            first.insert(level,1,temp1);
            first.erase(i,1);
            first.insert(i, 1, temp);
            R3_first_second(first, second, level + 1);
        }
    }
}

void R4_Boxes(int count,string boxes) {
    string input;
    if (count <= 0) {
        cout << "How many boxes are in the room? ";
        cin >> count;
        R4_Boxes(count, "");
    } else if(count > 0) {
        cout << "How many boxes are in this box? ";
        cin >> count;
        for (int i = 0; i < count; i++) {
            boxes += to_string(i + 1);
            cout << "opening box " << boxes << endl;
            cout << "are there more boxes inside [y] [n]: ";
            cin >> input;
            if (input == "y") {
                boxes += "." + to_string(i+1);
                R4_Boxes(i+1,boxes);
            } else {
                cout << boxes << endl;
            }

        }
    }
}

void R16_guess(int low, int high) {
    string lowOrHigh = "";
    if (low == high) {
        cout << "your number is " << low << endl;
    } else {
        cout << "Is your number " << (low + high) / 2 << " [y] for yes. If not then is it [l]ower or [h]igher. ";
        cin >> lowOrHigh;
        if (lowOrHigh == "y") {
            R16_guess(((low + high) / 2), ((low + high) / 2));
        } else if (lowOrHigh == "l") {
            R16_guess(low, ((low + high) / 2));
        } else {
            R16_guess(((low + high) / 2), high);
        }
    }
}

int main() {
    //R1_levls(0);
    //R2_Box("BOX", 0);
    //R3_first_second("CATS","MAN", 0);
    R4_Boxes(0, "");
    //R16_guess(1, 1000000);
    
    return 0;
}