/* Copyright (c) 2015, Jakub Borowski */
#ifndef BOWLING_H_
#define BOWLING_H_

class Game {
 public:
     Game() : total_score(0) {}
     void roll(int pins);
     int score();

 private:
     int total_score;
};

void Game::roll(int pins) {
    total_score += pins;
}

int Game::score() {
    return total_score;
}
#endif  // BOWLING_H_
