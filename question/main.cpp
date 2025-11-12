/*
Question 1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    vector<string> path; // store movements
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
        cout << "Path Length: -1\nSequence of movement: NIL\n";
        return 0;
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<Node> q;

    q.push({0, 0, {}});
    visited[0][0] = 1;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    string dir[] = {"right", "left", "down", "up"};

    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        if (curr.x == n-1 && curr.y == m-1) {
            cout << "Path Length: " << curr.path.size() << endl;
            cout << "Sequence of movement: ";
            for (int i = 0; i < curr.path.size(); i++) {
                cout << curr.path[i];
                if (i != curr.path.size() - 1) cout << ",";
            }
            cout << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && grid[nx][ny] == 0) {
                visited[nx][ny] = 1;
                vector<string> newPath = curr.path;
                newPath.push_back(dir[i]);
                q.push({nx, ny, newPath});
            }
        }
    }

    cout << "Path Length: -1\nSequence of movement: NIL\n";
    return 0;
}

*/

/*
Question 2

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(vector<int>& arr, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    buildMinHeap(arr, n);

    cout << "Min Heap: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}

*/
