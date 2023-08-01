// Alex and Charlie are playing an online video game. Initially, there are m players in the first level, and there are next n levels. Each level introduces a new player (along with the players from the previous level). Each player has some strength which determines the difficulty of beating this player. To pass any level, select any available players and beat them.
// Alex has completed the game and beaten the rankth strongest player at every level. Now it's Charlie's turn to play. Whenever a player is beaten, Charlie's health decreases by the amount of strength of that player. So the initial health of Charlie must be greater than or equal to the sum of the strengths of players that are beaten throughout the game.
// Charlie does not want to lose to Alex, so Charlie decided to also beat the rankth strongest player at each level. What is the minimum initial health that Charlie needs to start with in order to do this?

// Example
// initial_players = [1, 2], new_players = [3, 4], rank = 2
// Charlie needs to beat the 2nd strongest player at each level.
// For the first level, players have strengths 1 and 2, so Charlie needs to beat the player with strength
// 1.
// For the second level, strengths are1, 2, and 3, so Charlie defeats strength 2.
// For the third level, strengths are 1, 2, 3, and 4, so Charlie defeats strength 3.
// Total health needed = 1 + 2 + 3 = 6.

#include <bits/stdc++.h>
using namespace std;
int health(vector<int> &initial_players, int rank)
{
    int ans = 0;
    sort(initial_players.begin(),initial_players.end());
    int c = rank;
    for(int i=initial_players.size()-1; i>=0; i--)
    {
        c--;
        if(c == 0)
        {
            ans = initial_players[i];
            return ans;
        }
    }
}
long getMinimumHealth(vector<int> initial_players, vector<int> new_players, int rank)
{
    long ans = 0;
    ans += health(initial_players, rank);
    for(int i=0; i<new_players.size(); i++)
    {
        initial_players.push_back(new_players[i]);
        ans += health(initial_players, rank);
    }
    return ans;
}

