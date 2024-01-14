#include <iostream>
#include <vector>

std::pair<int, int> apply_rule(int rule, int x, int y) {
    if (rule == 1 && x < 4) {
        x = 4;
    } else if (rule == 2 && y < 3) {
        y = 3;
    } else if (rule == 3 && x > 0) {
        x = 0;
    } else if (rule == 4 && y > 0) {
        y = 0;
    } else if (rule == 5 && x + y >= 4 && y > 0) {
        y = y - (4 - x);
        x = 4;
    } else if (rule == 6 && x + y >= 3 && x > 0) {
        x = x - (3 - y);
        y = 3;
    } else if (rule == 7 && x + y <= 4 && y > 0) {
        x = x + y;
        y = 0;
    } else if (rule == 8 && x + y <= 3 && x > 0) {
        y = x + y;
        x = 0;
    } else if (rule == 9 && std::make_pair(x, y) == std::make_pair(0, 2)) {
        x = 2;
        y = 0;
    }
    return std::make_pair(x, y);
}

std::vector<int> water_jug(int x, int y, std::vector<int>& state_space) {
    int initial_x = x;
    int initial_y = y;
    for (int i = 1; i <= 9; ++i) {
        x = initial_x;
        y = initial_y;
        std::pair<int, int> result = apply_rule(i, x, y);
        x = result.first;
        y = result.second;

        if (std::make_pair(x, y) == std::make_pair(initial_x, initial_y)) {
            continue;
        } else {
            std::cout << "Rule applied: " << x << " " << y << std::endl;
            state_space.push_back(i);
            if (std::make_pair(x, y) == std::make_pair(2, 0)) {
                return state_space;
            } else {
                water_jug(x, y, state_space);
            }
        }
    }
    return state_space;
}

int main() {
    int x = 0; // Set the initial values of x and y as needed
    int y = 0;
    std::vector<int> state_space;
    water_jug(x, y, state_space);

    return 0;
}
