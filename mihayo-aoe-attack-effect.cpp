#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int find_sum(vector<int> &monster_lives) {
    int sum = 0;
    for (int monster_live: monster_lives) {
        sum += monster_live;
    }
    return sum;
}

int find_min_life_index(vector<int> &monster_lives) {
    int min_life = numeric_limits<int>::max();
    int min_life_index = 0;
    for (int i = 0; i < monster_lives.size(); ++i) {
        if (monster_lives[i] < min_life) {
            min_life = monster_lives[i];
            min_life_index = i;
        }
    }
    return min_life_index;
}

void attack_all(vector<int> &monster_lives, vector<int> &monster_max_lives, int except) {
    for (int i = 0; i < monster_lives.size(); ++i) {
        if (monster_lives[i] == 0) {
            continue;
        }
        if (monster_lives[i] - 1 <= monster_max_lives[i] / 2) {
            monster_lives[i] -= 1;
            attack_all(monster_lives, monster_max_lives, i);
        } else if (i != except) {
            monster_lives[i] -= 1;
        }
    }
}

int main() {
    int monster_num, monster;
    vector<int> monster_lives;
    vector<int> monster_max_lives;

    cin >> monster_num;
    for (int i = 0; i < monster_num; ++i) {
        cin >> monster;
        monster_lives.push_back(monster);
        monster_max_lives.push_back(monster);
    }

    int attack_times = 0;
    while (find_sum(monster_lives) != 0) {
        // find the minimum element's index in monster_lives
        int min_life_index = find_min_life_index(monster_lives);
        monster_lives[min_life_index] -= 1;
        if (monster_lives[min_life_index] <= monster_max_lives[min_life_index] / 2) {
            attack_all(monster_lives, monster_max_lives, min_life_index);
        }
        attack_times += 1;
    }

    cout << attack_times;
}
