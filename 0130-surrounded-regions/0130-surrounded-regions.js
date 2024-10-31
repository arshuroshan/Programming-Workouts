var solve = function(board) {
    const m = board.length;
    const n = board[0].length;

    const dfs = (i, j) => {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] !== 'O') {
            return;
        }
        board[i][j] = '.';
        const directions = [-1, 0, 1, 0, -1];
        for (let k = 0; k < 4; k++) {
            dfs(i + directions[k], j + directions[k + 1]);
        }
    };

    for (let i = 0; i < m; i++) {
        dfs(i, 0);
        dfs(i, n - 1);
    }
    for (let j = 0; j < n; j++) {
        dfs(0, j);
        dfs(m - 1, j);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === '.') {
                board[i][j] = 'O';
            } else if (board[i][j] === 'O') {
                board[i][j] = 'X';
            }
        }
    }
};