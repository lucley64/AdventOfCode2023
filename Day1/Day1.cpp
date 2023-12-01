//
// Created by lucle on 01/12/2023.
//

#include "Day1.h"
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <regex>

void Day1::part1() {
    std::ifstream input;


    input.open("../Day1/Part1/input.txt");

    if (input.is_open()) {
        std::string line;
        int count = 0;

        while (std::getline(input, line)) {
            const auto digits = "0123456789";
            auto n = line.find_first_of(digits);
            const auto first = line[n] - '0';
            n = line.find_last_of(digits);
            const auto last = line[n] - '0';

            count += first * 10 + last;

        }
        std::cout << "Result: " << count << std::endl;

    }

}

void Day1::part2() {

    std::ifstream input;


    input.open("../Day1/Part2/input.txt");

    if (input.is_open()) {
        std::string line;
        long count = 0;

        while (std::getline(input, line)) {

            const std::regex digits("(one|two|three|four|five|six|seven|eight|nine|\\d)");

            std::smatch match;
            auto searchStart(line.cbegin());
            std::list<std::string> resulsts;
            while(std::regex_search(searchStart, line.cend(), match, digits)) {
                resulsts.push_back(match[0]);
                searchStart +=1;
            }

            const auto first = toInt(resulsts.front());

            const auto last = toInt(resulsts.back());
            std::cout << first << " + " << last << " = " << first * 10 + last << std::endl;
            count += first * 10 + last;

        }
        std::cout << "Result: " << count << std::endl;

    }

}

int Day1::toInt(const std::string& str) {
    if (str == "one" || str == "1") {
        return 1;
    }
    if (str == "two" || str == "2") {
        return 2;
    }
    if (str == "three" || str == "3") {
        return 3;
    }
    if (str == "four" || str == "4") {
        return 4;
    }
    if (str == "five" || str == "5") {
        return 5;
    }
    if (str == "six" || str == "6") {
        return 6;
    }
    if (str == "seven" || str == "7") {
        return 7;
    }
    if (str == "eight" || str == "8") {
        return 8;
    }
    if (str == "nine" || str == "9") {
        return 9;
    }
    return 0;
}
