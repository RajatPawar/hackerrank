#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<string> split_string(string);

int get_count_from_xy(int x, int y, int n) {
    int counter = 0;
    
    if(x < 0 || y < 0) return -1;
    if(x > n || y > n) return -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { 
            if(i == x && j == y) 
                return counter;
            counter++;
        }
    }
    return -1;
}

void get_xy_from_count(int counter, int *x, int *y, int n) {
  int my = 0;

  if (counter < 0 || counter > n*n) {
    *x = -1;
    *y = -1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (my == counter) {
          *x = i;
          *y = j;
          return;
      }
      my++;
    }
  }
  *x = -1;
  *y = -1;
}

int is_edge_xy(int x, int y, int n) {
    n = n - 1;
    if(!x && y == n) return 1;
    if(x == n && !y) return 1;
    if(x == n && y == n) return 1;
    if(!x && !y) return 1;
    return 0;
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    vector<int> graph[grid.size() * grid.size()];
    int counter = 0;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid.size(); j++) {
            graph[get_count_from_xy(i, j, grid.size())].push_back(get_count_from_xy(i - 1, j - 1, grid.size()));
            graph[get_count_from_xy(i, j, grid.size())].push_back(get_count_from_xy(i + 1, j + 1, grid.size()));
            graph[get_count_from_xy(i, j, grid.size())].push_back(get_count_from_xy(i, j - 1, grid.size()));
            graph[get_count_from_xy(i, j, grid.size())].push_back(get_count_from_xy(i - 1, j, grid.size()));

            graph[get_count_from_xy(i, j, grid.size())].push_back(get_count_from_xy(i + 1, j, grid.size()));
            graph[get_count_from_xy(i, j, grid.size())].push_back(get_count_from_xy(i, j + 1, grid.size()));
            graph[get_count_from_xy(i, j, grid.size())].push_back(get_count_from_xy(i + 1, j - 1, grid.size()));
            graph[get_count_from_xy(i, j, grid.size())].push_back(get_count_from_xy(i - 1, j + 1, grid.size()));
        }
    }

    int source = get_count_from_xy(startX, startY, grid.size()),
        dest = get_count_from_xy(goalX, goalY, grid.size());

    queue<int> q;

    int level = 0, nowDiff, prevDiff;

    int visited[grid.size() * grid.size()];
    memset(visited, 0, grid.size() * grid.size() * sizeof(int));

    q.push(source);
    
    while(!q.empty()) {

        int neighbour = q.front();
        visited[neighbour] = 1;
        q.pop();

        int x = 0, y = 0;
        get_xy_from_count(neighbour, &x, &y, grid.size());
        if(grid[x][y] != 'X') {
            for(int i = 0; i < graph[neighbour].size(); i++) {
            if(!visited[graph[neighbour][i]]) {
                    q.push(graph[neighbour][i]);
                    visited[graph[neighbour][i]] = 1;
                }
            }
        }

        if(neighbour == dest) return level;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
