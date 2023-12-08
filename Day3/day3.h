//
// Created by cytech on 04/12/23.
//

#ifndef DAY3_H
#define DAY3_H
#include <string>


class day3 {
public:
    static void part1();
    static void part2();
    static int get_number(const std::string& str, int pos);
};

class Position {
    int startPos;
    int endPos;
    int row;

public:
    Position(int, int, int);

    [[nodiscard]] int getRow() const;

    std::pair<int, int> getPos();
};

class Number : public Position{
    int number;

public:
    Number(const std::string&, int, int, int);

    [[nodiscard]] int getNumber() const;
};





#endif //DAY3_H
