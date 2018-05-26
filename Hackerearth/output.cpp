i = 1, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(1)
visit[1] = 1, cnt = 1
f[1].size() = 1
f[1][0] = 2, visit[2] = 0
dfs(f[1][0]) = dfs(2)
visit[2] = 1, cnt = 2
f[2].size() = 1
f[2][0] = 3, visit[3] = 0
dfs(f[2][0]) = dfs(3)
visit[3] = 1, cnt = 3
f[3].size() = 1
f[3][0] = 1, visit[1] = 1
ans = 3
i = 2, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(2)
visit[2] = 1, cnt = 1
f[2].size() = 1
f[2][0] = 3, visit[3] = 0
dfs(f[2][0]) = dfs(3)
visit[3] = 1, cnt = 2
f[3].size() = 1
f[3][0] = 1, visit[1] = 0
dfs(f[3][0]) = dfs(1)
visit[1] = 1, cnt = 3
f[1].size() = 1
f[1][0] = 2, visit[2] = 1
ans = 3
i = 3, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(3)
visit[3] = 1, cnt = 1
f[3].size() = 1
f[3][0] = 1, visit[1] = 0
dfs(f[3][0]) = dfs(1)
visit[1] = 1, cnt = 2
f[1].size() = 1
f[1][0] = 2, visit[2] = 0
dfs(f[1][0]) = dfs(2)
visit[2] = 1, cnt = 3
f[2].size() = 1
f[2][0] = 3, visit[3] = 1
ans = 3
i = 4, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(4)
visit[4] = 1, cnt = 1
f[4].size() = 1
f[4][0] = 7, visit[7] = 0
dfs(f[4][0]) = dfs(7)
visit[7] = 1, cnt = 2
ans = 2
i = 5, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(5)
visit[5] = 1, cnt = 1
f[5].size() = 1
f[5][0] = 9, visit[9] = 0
dfs(f[5][0]) = dfs(9)
visit[9] = 1, cnt = 2
ans = 2
i = 6, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(6)
visit[6] = 1, cnt = 1
f[6].size() = 1
f[6][0] = 7, visit[7] = 0
dfs(f[6][0]) = dfs(7)
visit[7] = 1, cnt = 2
ans = 2
i = 7, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(7)
visit[7] = 1, cnt = 1
ans = 1
i = 8, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(8)
visit[8] = 1, cnt = 1
ans = 1
i = 9, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(9)
visit[9] = 1, cnt = 1
ans = 1
i = 10, cnt = 0
visit[0] = 0
visit[1] = 0
visit[2] = 0
visit[3] = 0
visit[4] = 0
visit[5] = 0
visit[6] = 0
visit[7] = 0
visit[8] = 0
visit[9] = 0
visit[10] = 0
dfs(10)
visit[10] = 1, cnt = 1
ans = 1
final ans = 1