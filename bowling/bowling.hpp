/* Copyright (c) 2015, Jakub Borowski */
#ifndef BOWLING_H_
#define BOWLING_H_

class Game {
 public:
     void roll(int pins);
     int score();

 private:
     int current_roll = 0;
     int rolls[21] = {};
};

void Game::roll(int pins) {
    rolls[current_roll++] = pins;
}

int Game::score() {
    int score = 0;
    int i = 0;
    for (int frame = 0; frame < 10; frame++) {
        if (rolls[i] + rolls[i+1] == 10) { // spare
            score += 10 + rolls[i+2];
            i += 2;
        } else {
            score += rolls[i] + rolls[i+1];
            i += 2;
        }
    }
    return score;
}
#endif  // BOWLING_H_
