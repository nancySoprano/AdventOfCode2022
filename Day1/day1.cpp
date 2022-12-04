#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <algorithm>


using namespace std;



int main() {
    cout << "day1" << endl;
    ifstream input("input.txt");
    vector<string> packs;

    if(!input) {
        cerr << "input not found\n" <<endl;
        exit(1);
    }

    string str;

    while (getline(input, str, '\n')){
        packs.push_back(str);
    }

    vector<int> kcalPacks;
    int kcal;

    for (auto s : packs)
        kcalPacks.push_back(atoi(s.c_str()));

    int total;
    vector<int> totalKcalPacks;
    totalKcalPacks.reserve(100);

    for (int i=0; i<kcalPacks.size() ; i++){
        if (kcalPacks[i] == 0){
            totalKcalPacks.push_back(total);
            total = 0;
        }
        total += kcalPacks[i];
    }


    /* PART 2*/
    vector<int> sorted;
    sort(totalKcalPacks.begin(),totalKcalPacks.end(), greater<int>());
    int top3total;
    for (int i=0; i<3; ++i){
        cout << i+1 << ". "<< totalKcalPacks[i] << endl;
        top3total += totalKcalPacks[i];
    }

    cout << "Day 1 Part 1: Calories count of the richest pack is: " << *max_element (begin(totalKcalPacks), end(totalKcalPacks)) << endl;
    cout << "Top 3 Elves are carrying: " << top3total-1 << " kcalories in total." << endl;
    input.close();
    cout << "end of file" <<endl;

}