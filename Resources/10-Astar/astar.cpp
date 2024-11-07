#include <ncurses.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// Define constants for grid elements
const int EMPTY    = 0;
const int OBSTACLE = 1;

// Initialize colors
void init_colors() {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);   // Default color for empty spaces
    init_pair(2, COLOR_BLACK, COLOR_WHITE);   // Color for obstacles
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);  // Low f value
    init_pair(4, COLOR_CYAN, COLOR_BLACK);    // Medium f value
    init_pair(5, COLOR_RED, COLOR_BLACK);     // High f value
    init_pair(6, COLOR_GREEN, COLOR_BLACK);   // Path color
}

// Map f values to color pairs
int f_value_to_color(int f) {
    if (f < 10)
        return 3;  // Low f value
    else if (f < 20)
        return 4;  // Medium f value
    else
        return 5;  // High f value
}

// Draw the grid with colors based on f values and path
void draw_grid(const vector<vector<int>>& grid, const vector<pair<int, int>>& path, const vector<vector<int>>& f_values) {
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == OBSTACLE) {
                attron(COLOR_PAIR(2));
                mvaddch(y, x, ACS_CKBOARD);  // Draw obstacle as a solid block
                attroff(COLOR_PAIR(2));
            } else if (find(path.begin(), path.end(), make_pair(y, x)) != path.end()) {
                attron(COLOR_PAIR(6));
                mvaddch(y, x, '*');  // Highlight current path with '*'
                attroff(COLOR_PAIR(6));
            } else {
                int f = f_values[y][x];
                attron(COLOR_PAIR(f_value_to_color(f)));
                mvaddch(y, x, '.');  // Open space with color based on f value
                attroff(COLOR_PAIR(f_value_to_color(f)));
            }
        }
    }
}

void init_ncurses() {
    initscr();      // Initialize ncurses screen
    noecho();       // Disable echoing of typed characters
    curs_set(0);    // Hide the cursor
    init_colors();  // Set up colors
}

void end_ncurses() {
    getch();
    endwin();
}

// Main loop to visualize A* search using ncurses
void visualize_a_star(const vector<vector<int>>& grid, const vector<pair<int, int>>& path, const vector<vector<int>>& f_values) {
    initscr();      // Initialize ncurses screen
    noecho();       // Disable echoing of typed characters
    curs_set(0);    // Hide the cursor
    init_colors();  // Set up colors

    while (true) {
        clear();
        draw_grid(grid, path, f_values);  // Draw the grid with the current path and f values
        refresh();

        // Simulate each frame of the search process (adjust delay as needed)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Exit condition: break out of the loop once path is fully discovered (or add a key to exit)
        if (!path.empty() && path.back() == make_pair(grid.size() - 1, grid[0].size() - 1))
            break;
    }

    // End ncurses session
    getch();
    endwin();
}

vector<vector<int>> readGrid(const string& filename, pair<int, int>& start, pair<int, int>& goal, vector<vector<int>>& f_values) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }

    vector<vector<int>> grid;
    string line;
    int row = 0;

    while (getline(file, line)) {
        vector<int> gridRow;
        for (int col = 0; col < line.size(); ++col) {
            if (line[col] == 'S') {
                // Set start coordinates
                start = {row, col};
                gridRow.push_back(0);  // Represent start as open space in the grid
            } else if (line[col] == 'G') {
                // Set goal coordinates
                goal = {row, col};
                gridRow.push_back(0);  // Represent goal as open space in the grid
            } else if (line[col] == '0') {
                gridRow.push_back(0);  // Open path
            } else if (line[col] == '1') {
                gridRow.push_back(1);  // Obstacle
            } else {
                throw runtime_error("Invalid character in grid file at row " + to_string(row) + ", col " + to_string(col));
            }
        }
        grid.push_back(gridRow);
        ++row;
    }

    file.close();

    int rows = grid.size(), cols = grid[0].size();
    f_values = vector<vector<int>>(rows, vector<int>(cols, 0));
    return grid;
}

struct Node {
    int x, y;
    int f, g, h;
    Node* parent;

    Node(int x, int y, int g = 0, int h = 0, Node* parent = nullptr) : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}

    bool operator>(const Node& other) const { return f > other.f; }
};

// Manhattan distance heuristic
int manhattan_distance(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

// Check if a point is within the grid and walkable
bool is_valid(int x, int y, const vector<vector<int>>& grid) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0;
}

// Reconstruct path from end node
vector<pair<int, int>> reconstruct_path(Node* node) {
    vector<pair<int, int>> path;
    while (node) {
        path.push_back({node->x, node->y});
        node = node->parent;
    }
    reverse(path.begin(), path.end());
    return path;
}

// A* search function
vector<pair<int, int>> a_star(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal, vector<vector<int>>& f_values) {
    int rows = grid.size(), cols = grid[0].size();
    vector<pair<int, int>> path;
    init_ncurses();

    // Priority queue to hold nodes with the lowest f scores
    priority_queue<Node*, vector<Node*>, greater<Node*>> open_set;

    // Open set and closed set for tracking nodes
    unordered_map<int, Node*> open_map, closed_map;

    // Start node
    Node* start_node = new Node(start.first, start.second, 0, manhattan_distance(start.first, start.second, goal.first, goal.second));
    f_values[start.first][start.second] = start_node->f;
    open_set.push(start_node);
    open_map[start.first * cols + start.second] = start_node;

    // Directions for moving in the grid (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!open_set.empty()) {
        clear();
        draw_grid(grid, path, f_values);  // Draw the grid with the current path and f values
        refresh();

        // Simulate each frame of the search process (adjust delay as needed)
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        // Exit condition: break out of the loop once path is fully discovered (or add a key to exit)
        // if (!path.empty() && path.back() == make_pair(grid.size() - 1, grid[0].size() - 1))
        //     break;

        Node* current                    = open_set.top();
        f_values[current->x][current->y] = current->f;

        open_set.pop();
        int current_index = current->x * cols + current->y;

        // Goal check
        if (current->x == goal.first && current->y == goal.second) {
            path = reconstruct_path(current);

            // Cleanup dynamic memory
            for (auto& entry : open_map) delete entry.second;
            for (auto& entry : closed_map) delete entry.second;

            return path;
        }

        // Move node from open set to closed set
        open_map.erase(current_index);
        closed_map[current_index] = current;

        // Explore neighbors
        for (auto& dir : directions) {
            int new_x = current->x + dir.first;
            int new_y = current->y + dir.second;

            if (!is_valid(new_x, new_y, grid))
                continue;

            int new_g              = current->g + 1;
            int new_h              = manhattan_distance(new_x, new_y, goal.first, goal.second);
            Node* neighbor         = new Node(new_x, new_y, new_g, new_h, current);
            path                   = reconstruct_path(current);
            f_values[new_x][new_y] = neighbor->f;

            int neighbor_index = new_x * cols + new_y;

            // Skip if already in closed set with a lower or equal f cost
            if (closed_map.count(neighbor_index) && closed_map[neighbor_index]->f <= neighbor->f) {
                delete neighbor;
                continue;
            }

            // Add to open set if not present, or update if a better path is found
            if (!open_map.count(neighbor_index) || open_map[neighbor_index]->f > neighbor->f) {
                open_set.push(neighbor);
                open_map[neighbor_index] = neighbor;
            } else {
                delete neighbor;
            }
        }
    }

    // Cleanup in case of no path found
    for (auto& entry : open_map) delete entry.second;
    for (auto& entry : closed_map) delete entry.second;

    return {};  // Return empty path if no path exists
}

int main() {
    pair<int, int> start, goal;
    vector<vector<int>> grid;
    vector<vector<int>> f_values;
    vector<pair<int, int>> path;

    // vector<vector<int>> grid = {{0, 0, 0, 0, 0}, {1, 1, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}};
    // pair<int, int> start     = {0, 0};
    // pair<int, int> goal      = {4, 4};

    try {
        grid = readGrid("grid2.txt", start, goal, f_values);
        cout << "Start: (" << start.first << ", " << start.second << ")" << endl;
        cout << "Goal: (" << goal.first << ", " << goal.second << ")" << endl;

        // Optional: Print the grid
        for (const auto& row : grid) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }

    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    path = a_star(grid, start, goal, f_values);
    draw_grid(grid, path, f_values);
    return 0;

    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found: ";
        for (const auto& p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}