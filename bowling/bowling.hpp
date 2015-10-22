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
     bool is_spare(int frame_index);
};

void Game::roll(int pins) {
    rolls[current_roll++] = pins;
}

int Game::score() {
    int score = 0;
    int frame_index = 0;
    for (int frame = 0; frame < 10; frame++) {
        if (is_spare(frame_index)) {  // spare
            score += 10 + rolls[frame_index+2];
            frame_index += 2;
        } else {
            score += rolls[frame_index] + rolls[frame_index+1];
            frame_index += 2;
        }
    }
    return score;
}

bool Game::is_spare(int frame_index) {
    return rolls[frame_index] + rolls[frame_index + 1] == 10;
}

#endif  // BOWLING_H_
