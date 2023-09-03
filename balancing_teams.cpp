#include "bits/stdc++.h"

using namespace std;

int equalTeamSkill(const vector<int> &teamA, const vector<int> &teamB) {
    int teamA_alloc = 0, teamA_score = 0,
        teamB_alloc = 0, teamB_score = 0;

    for (const auto n: teamA) {
        if (n == 0) {
            teamA_alloc++;
        } else {
            teamA_score += n;
        }
    }

    for (const auto n: teamB) {
        if (n == 0) {
            teamB_alloc++;
        } else {
            teamB_score += n;
        }
    }

    if (teamA_alloc == 0 && teamA_score < teamB_score + teamB_alloc) {
        return -1;
    }

    if (teamB_alloc == 0 && teamB_score < teamA_score + teamA_alloc) {
        return -1;
    }

    return max(teamA_score + teamA_alloc, teamB_score + teamB_alloc);
}

int main() {
    vector<int> teamA {1, 2, 3, 0};
    vector<int> teamB {5, 0, 0};
    assert(equalTeamSkill(teamA, teamB) == 7);

    teamA = vector<int> {1, 2, 3};
    teamB = vector<int> {0, 10};
    assert(equalTeamSkill(teamA, teamB) == -1);
}