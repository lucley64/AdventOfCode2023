//
// Created by lucle on 02/12/2023.
//

#include "day2.h"

#include <fstream>
#include <iostream>
#include <regex>

void day2::part1() {
    std::ifstream input;


    input.open("../day2/input.txt");

    if (input.is_open()) {
        std::string line;
        int count = 0;

        while (std::getline(input, line)) {
            size_t startPos = 5, endPos = line.find(": ");
            auto game = atoi(line.substr(startPos, endPos - startPos).c_str());
            startPos = endPos + 2;
            std::string colors;
            const std::regex greenMatch("(\\d+) green");
            const std::regex redMatch("(\\d+) red");
            const std::regex blueMatch("(\\d+) blue");
            auto valid = true;
            while (valid && (endPos = line.find("; ", startPos)) != std::string::npos) {
                colors = line.substr(startPos, endPos - startPos);
                std::smatch res;
                if (std::regex_search(colors.cbegin(), colors.cend(), res, redMatch)) {
                    const auto redCount = atoi(res[0].str().c_str());
                    valid = redCount <= 12;
                }
                if (valid && std::regex_search(colors.cbegin(), colors.cend(), res, greenMatch)) {
                    const auto greenCount = atoi(res[0].str().c_str());
                    valid = greenCount <= 13;
                }
                if (valid && std::regex_search(colors.cbegin(), colors.cend(), res, blueMatch)) {
                    const auto blueCount = atoi(res[0].str().c_str());
                    valid = blueCount <= 14;
                }

                startPos = endPos + 2;
            }
            if (valid) {
                colors = line.substr(startPos, line.size() - startPos);
                std::smatch res;
                if (std::regex_search(colors.cbegin(), colors.cend(), res, redMatch)) {
                    const auto redCount = atoi(res[0].str().c_str());
                    valid = redCount <= 12;
                }
                if (valid && std::regex_search(colors.cbegin(), colors.cend(), res, greenMatch)) {
                    const auto greenCount = atoi(res[0].str().c_str());
                    valid = greenCount <= 13;
                }
                if (valid && std::regex_search(colors.cbegin(), colors.cend(), res, blueMatch)) {
                    const auto blueCount = atoi(res[0].str().c_str());
                    valid = blueCount <= 14;
                }
                if (valid) {
                    count += game;
                }
            }
        }
        std::cout << "Result: " << count << std::endl;
    }
}

void day2::part2() {
    std::ifstream input;


    input.open("../day2/input.txt");

    if (input.is_open()) {
        std::string line;
        int count = 0;

        while (std::getline(input, line)) {
            size_t startPos = 5, endPos = line.find(": ");
            auto game = atoi(line.substr(startPos, endPos - startPos).c_str());
            startPos = endPos + 2;
            std::string colors;
            const std::regex greenMatch("(\\d+) green");
            const std::regex redMatch("(\\d+) red");
            const std::regex blueMatch("(\\d+) blue");
            int maxRed = 0, maxGreen = 0, maxBlue = 0;
            while ((endPos = line.find("; ", startPos)) != std::string::npos) {
                colors = line.substr(startPos, endPos - startPos);
                std::smatch res;
                if (std::regex_search(colors.cbegin(), colors.cend(), res, redMatch)) {
                    const auto redCount = atoi(res[0].str().c_str());
                    maxRed = maxRed < redCount ? redCount : maxRed;
                }
                if (std::regex_search(colors.cbegin(), colors.cend(), res, greenMatch)) {
                    const auto greenCount = atoi(res[0].str().c_str());
                    maxGreen = maxGreen < greenCount ? greenCount : maxGreen;
                }
                if (std::regex_search(colors.cbegin(), colors.cend(), res, blueMatch)) {
                    const auto blueCount = atoi(res[0].str().c_str());
                    maxBlue = maxBlue < blueCount ? blueCount : maxBlue;
                }

                startPos = endPos + 2;
            }
            colors = line.substr(startPos, line.size() - startPos);
            std::smatch res;
            if (std::regex_search(colors.cbegin(), colors.cend(), res, redMatch)) {
                const auto redCount = atoi(res[0].str().c_str());
                maxRed = maxRed < redCount ? redCount : maxRed;
            }
            if (std::regex_search(colors.cbegin(), colors.cend(), res, greenMatch)) {
                const auto greenCount = atoi(res[0].str().c_str());
                maxGreen = maxGreen < greenCount ? greenCount : maxGreen;
            }
            if (std::regex_search(colors.cbegin(), colors.cend(), res, blueMatch)) {
                const auto blueCount = atoi(res[0].str().c_str());
                maxBlue = maxBlue < blueCount ? blueCount : maxBlue;
            }
            count += maxRed * maxGreen * maxBlue;
        }
        std::cout << "Result: " << count << std::endl;
    }
}
