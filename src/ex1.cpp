#include <iostream>
#include <vector>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::vector;

struct Position {
    int x;
    int y;
};

enum Direction {
    Up,
    Down,
    Forward,
    Backward
};

struct Move {
    Direction direction;
    int distance;
};

void moveSubmarine(Position &pos, const Move &move) {
    switch (move.direction) {
        case Up:
            pos.y -= move.distance;
            break;
        case Down:
            pos.y += move.distance;
            break;
        case Forward:
            pos.x += move.distance;
            break;
        case Backward:
            pos.x -= move.distance;
            break;
    }
}

void display(const Position &pos) {
    cout << "Submarine position: (" << pos.x << ", " << pos.y << ")" << endl;
}

int main() {
    Position submarine = {0, 0};
    vector<Move> moves = {
        {Forward, 10}, 
        {Down, 5}, 
        {Backward, 3}, 
        {Up, 2}, 
        {Forward, 5},
        {Down, 1}, 
        {Backward, 2}, 
        {Forward, 3}, 
        {Down, 1}, 
        {Up, 3},
        {Forward, 1}, 
        {Down, 5}, 
        {Backward, 2}, 
        {Forward, 6}
    };

    for (const auto &move : moves) {
        moveSubmarine(submarine, move);
    }

    display(submarine);

    return 0;
}