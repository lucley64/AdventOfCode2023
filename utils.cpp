//
// Created by cytech on 08/12/23.
//

#include "utils.h"

#include <fstream>

std::vector<std::string> get_lines(const std::string& file_name) {
    std::ifstream input;
    std::vector<std::string> ret;
    input.open(file_name);
    if (input.is_open()) {
        std::string read;
        while (std::getline(input, read)) {
            ret.push_back(read);
        }
        input.close();
    }
    return ret;
}

