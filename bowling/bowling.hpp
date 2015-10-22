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
     int sum_in_frames(int frame_index);
     int spare_bonus(int frame_index);
     int strike_bonus(int frame_index);
};

void Game::roll(int pins) {
    rolls[current_roll++] = pins;
}

int Game::score() {
    int score = 0;
    int frame_index = 0;
    for (int frame = 0; frame < 10; frame++) {
        if (rolls[frame_index] == 10) {  //strike
            score += 10 + strike_bonus(frame_index);
            frame_index++;
        } else if (is_spare(frame_index)) {  // spare
            score += 10 + spare_bonus(frame_index);
            frame_index += 2;
        } else {
            score += sum_in_frames(frame_index);
            frame_index += 2;
        }
    }
    return score;
}

bool Game::is_spare(int frame_index) {
    return rolls[frame_index] + rolls[frame_index + 1] == 10;
}

int Game::sum_in_frames(int frame_index) {
    return rolls[frame_index] + rolls[frame_index + 1];
}

int Game::spare_bonus(int frame_index) {
    return rolls[frame_index + 2];
}

int Game::strike_bonus(int frame_index) {
    return rolls[frame_index + 1] + rolls[frame_index + 2];
}

#endif  // BOWLING_H_
