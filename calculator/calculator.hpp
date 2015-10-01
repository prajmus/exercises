/* Copyright (c) 2015, Jakub Borowski */
#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_

#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>

std::vector<std::string> has_delimiter(std::string &str) {
    std::vector<std::string> delims;  // vector to store delimeters
    if (str[0] == '/' && str[1] == '/') {
        if (str[2] == '[') {
            str = str.substr(3);
            size_t pos = str.find_first_of(']');
            while (pos != std::string::npos) {
                delims.push_back(str.substr(0, pos));
                str = str.substr(pos+2);
                pos = str.find_first_of(']');
            }
            return delims;
        } else {
            std::string t(1, str[2]);
            str = str.substr(4);
            delims.push_back(t);
            return delims;
        }
    }
    delims.push_back(",");
    return delims;
}

bool get_next_number(std::string &line, const std::vector<std::string> &delims, int &number) {
    if (line.length() == 0)
        return false;
    size_t pos = std::string::npos;  // position of the closest delimeter
    unsigned index = 0;  // index of the delimeter in vector
    for (int i = 0; i < delims.size() ; ++i) {
        size_t tmp = line.find(delims[i]);
        if (tmp < pos) {
            pos = tmp;
            index = i;
        }
    }
    if (pos != std::string::npos) {
        number = std::stoi(line.substr(0, pos));
        line = line.substr(pos+delims[index].length());
    } else {
        number = std::stoi(line);  // last number in string (no delimeter after it)
        line = "";
    }
    return true;
}

int add(std::string numbers) {
    if (numbers.length() == 0)
        return 0;

    std::vector<std::string> delim = has_delimiter(numbers);

    std::string line;
    int sum = 0;
    std::stringstream ss(numbers);
    std::vector<int> negatives;
    while (getline(ss, line)) {
        int n = 0;
        while (get_next_number(line, delim, n)) {
            if (n < 0)
                negatives.push_back(n);
            if (n < 1001)
                sum += n;
        }
    }

    if (!negatives.empty()) {
        std::string message = "negatives not allowed: ";
        for(auto &i : negatives) {
            message += std::to_string(i);
        }
        throw std::logic_error(message);
    }

    return sum;
}

#endif  // CALCULATOR_HPP_
