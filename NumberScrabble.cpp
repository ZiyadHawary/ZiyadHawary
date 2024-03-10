//
// Created by Ziyad Hawary on 02/03/2024.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool sum_checker(vector<int>& x) {
    if (x.size() < 3) {
        return false;
    }
    unordered_set<int> numbers_set(x.begin(), x.end());
    for (int i = 0; i < x.size() - 2; i++) {
        for (int j = i + 1; j < x.size() - 1; j++) {
            int target = 15 - (x[i] + x[j]);
            if (numbers_set.count(target) > 0) {
                return true;
            }
        }
    }
    return false;
}

void game() {
    vector<int> choices = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "**Welcome to Number Scrabble**" << endl;
    cout << "<The player to first choose three numbers that their sum is 15 wins>" << endl;
    string player1, player2;
    cout << "Enter player 1 name: ";
    cin >> player1;
    cout << "Enter player 2 name: ";
    cin >> player2;
    cout << "{1, 2, 3, 4, 5, 6, 7, 8, 9}" << endl;
    vector<int> player1_list;
    vector<int> player2_list;
    while (!choices.empty()) {
        int input1;
        cout << player1 << ": Choose a number from the following choices:";
        cin >> input1;
        while (find(choices.begin(), choices.end(), input1) == choices.end()) {
            cout << "Please select a valid choice >>> ";
            cin >> input1;
        }
        player1_list.push_back(input1);
        choices.erase(find(choices.begin(), choices.end(), input1));
        cout << player1 << "'s score is now: ";
        for (int i = 0; i < player1_list.size(); i++) {
            cout << player1_list[i] << " ";
        }
        cout << endl;
        cout << "{1, 2, 3, 4, 5, 6, 7, 8, 9}" << endl;
        if (sum_checker(player1_list)) {
            cout << player1 << " is the winner!" << endl;
            break;
        }
        int input2;
        cout << player2 << ": Choose a number from the following choices:";
        cin >> input2;
        while (find(choices.begin(), choices.end(), input2) == choices.end()) {
            cout << "Please select a valid choice >>> ";
            cin >> input2;
        }
        player2_list.push_back(input2);
        choices.erase(find(choices.begin(), choices.end(), input2));
        cout << player2 << "'s score is now: ";
        for (int i = 0; i < player2_list.size(); i++) {
            cout << player2_list[i] << " ";
        }
        cout << endl;
        cout << "{1, 2, 3, 4, 5, 6, 7, 8, 9}" << endl;
        if (sum_checker(player2_list)) {
            cout << player2 << " is the winner!" << endl;
            break;
        }
    }
}

int main() {
    game();
    return 0;
}

