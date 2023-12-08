//
// Created by cytech on 04/12/23.
//

#include "day3.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <regex>

#include "../utils.h"

void day3::part1() {
    std::ifstream input;

    input.open("../Day3/input.txt");

    if (input.is_open()) {
        std::string read;
        std::vector<std::string> lines;
        std::vector<Number> numbers;

        while (std::getline(input, read)) {
            lines.push_back(read);
        }
        std::regex numberMatch("\\d+");
        for (int i = 0; i < lines.size(); ++i) {
            for (int j = 0; j < lines[i].size(); ++j) {
                if (std::isdigit(lines[i][j])) {
                    std::string number{lines[i][j]};
                    int start = j++;
                    while (j < lines.size() && std::isdigit(lines[i][j])) {
                        number.append({lines[i][j]});
                        j++;
                    }
                    numbers.emplace_back(number, start, j, i);
                }
            }
        }
        int result = 0;
        for (auto& number: numbers) {
            bool up = number.getRow() - 1 >= 0, down = number.getRow() + 1 < lines.size();
            if (number.getPos().first - 1 >= 0 && !isdigit(lines[number.getRow()][number.getPos().first - 1])
                && lines[number.getRow()][number.getPos().first - 1] != '.'
                || number.getPos().second < lines[number.getRow()].size()
                && !isdigit(lines[number.getRow()][number.getPos().second])
                && lines[number.getRow()][number.getPos().second] != '.') {
                result += number.getNumber();
                std::cout << "Number: " << number.getNumber() << "  Posive" << std::endl;
            } else {
                for (int i = number.getPos().first - 1 > 0 ? number.getPos().first - 1 : 0;
                     i < number.getPos().second + 1 && i < lines[number.getRow()].size(); ++i) {
                    if (up && !isdigit(lines[number.getRow() - 1][i]) && lines[number.getRow() - 1][i] != '.' ||
                        down && !isdigit(lines[number.getRow() + 1][i]) && lines[number.getRow() + 1][i] != '.') {
                        result += number.getNumber();
                        std::cout << "Number: " << number.getNumber() << "  Posive" << std::endl;
                        break;
                    }
                }
            }
        }
        std::cout << "Result: " << result << std::endl;
    }
}

void day3::part2() {
    const auto lines = get_lines("../Day3/input.txt");

    std::vector<Position> gears;
    for (int i = 0; i < lines.size(); ++i) {
        for (int j = 0; j < lines[i].size(); ++j) {
            if (lines[i][j] == '*') {
                gears.emplace_back(j, j + 1, i);
            }
        }
    }

    for (auto gear: gears) {
        std::vector<int> numbers;
        if (gear.getRow() > 0) {
            if (isdigit(lines[gear.getRow() - 1][gear.getPos().first])) {
                numbers.push_back(get_number(lines[gear.getRow() - 1], gear.getPos().first));
            }
            else {
                if (gear.getPos().first > 0) {
                    numbers.push_back(get_number(lines[gear.getRow() - 1], gear.getPos().first - 1));
                }
                if(gear.getPos().first < lines[gear.getRow()].size() - 1) {
                    numbers.push_back(get_number(lines[gear.getRow() - 1], gear.getPos().first + 1));
                }
            }
        }
        if (gear.getRow() < lines.size() - 1) {
            if (isdigit(lines[gear.getRow() + 1][gear.getPos().first])) {
                numbers.push_back(get_number(lines[gear.getRow() + 1], gear.getPos().first));
            }
            else {
                if (gear.getPos().first > 0) {
                    numbers.push_back(get_number(lines[gear.getRow() + 1], gear.getPos().first - 1));
                }
                if(gear.getPos().first < lines[gear.getRow()].size() + 1) {
                    numbers.push_back(get_number(lines[gear.getRow() + 1], gear.getPos().first + 1));
                }
            }
        }
        if (gear.getPos().first > 0) {
            numbers.push_back(get_number(lines[gear.getRow()], gear.getPos().first - 1));
        }
        if(gear.getPos().first < lines[gear.getRow()].size() - 1) {
            numbers.push_back(get_number(lines[gear.getRow()], gear.getPos().first + 1));
        }


    }
}

int day3::get_number(const std::string& str, const int pos) {
    std::string number = "0";
    if(isdigit(str[pos])) {
        number = {str[pos]};
        if (pos > 0) {
            for (int i = pos - 1; i >= 0 && isdigit(str[i]); --i) {
                number = std::string{str[i]} + number;
            }
            for (int i = pos + 1; i < str.length() && isdigit(str[i]); ++i) {
                number.append({str[i]});
            }
        }
    }
    return stoi(number);
}

Number::Number(const std::string& number, const int start, const int end, const int row): Position(start, end, row) {
    this->number = stoi(number);
}

int Number::getNumber() const {
    return number;
}

Position::Position(const int start, const int end, const int row): startPos(start), endPos(end), row(row) {
}

int Position::getRow() const {
    return row;
}


std::pair<int, int> Position::getPos() {
    return {startPos, endPos};
}
