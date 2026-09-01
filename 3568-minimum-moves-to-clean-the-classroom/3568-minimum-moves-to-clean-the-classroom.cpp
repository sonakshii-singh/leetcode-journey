class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        vector<pair<int,int>> litter;

       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();
        int fullMask = (1 << k) - 1;

       
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        
        vector<vector<vector<vector<int>>>> dist(
            m,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(
                    energy + 1,
                    vector<int>(1 << k, -1)
                )
            )
        );

        queue<tuple<int,int,int,int>> q;

        dist[sx][sy][energy][0] = 0;
        q.push({sx, sy, energy, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y, e, mask] = q.front();
            q.pop();

            int moves = dist[x][y][e][mask];

            if (mask == fullMask)
                return moves;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if (classroom[nx][ny] == 'X')
                    continue;

                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;
                if (id[nx][ny] != -1) {
                    nmask |= (1 << id[nx][ny]);
                }
                if (classroom[nx][ny] == 'R') {
                    ne = energy;
                }

                if (dist[nx][ny][ne][nmask] == -1) {
                    dist[nx][ny][ne][nmask] = moves + 1;
                    q.push({nx, ny, ne, nmask});
                }
            }
        }

        return -1;
    }
};