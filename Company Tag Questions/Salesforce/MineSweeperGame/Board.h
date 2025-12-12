#include "Board.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stdexcept>  // Include to use std::logic_error
using namespace std;

Board::Board(int width, int height, int mineCount)
    : m_width(width)
    , m_height(height)
    , m_mineCount(mineCount)
    , m_flagCount(0)
    , m_revealedCount(0)
    , m_initialized(false)
    , m_rng(std::random_device{}())
{
    // TODO: Initialize the m_grid with proper dimensions
    // Hint: m_grid should be a 2D vector of size height x width
    m_grid.resize(m_height);
    for (int i = 0; i < m_height; ++i) {
        m_grid[i].resize(m_width);
    }
}

Board::~Board() {
    // TODO: Implement destructor if needed (currently no dynamic allocation)
}

bool Board::revealCell(int x, int y) {
    // TODO: Implement cell revealing logic
    // 1. Check if position is valid using isValidPosition()
    // 2. Get the cell at position (x, y)
    // 3. Check if cell is already revealed or flagged - return false if so
    // 4. If board not initialized, call initializeMines(x, y) and set m_initialized = true
    // 5. Reveal the cell and increment m_revealedCount
    // 6. If cell is a mine, return false (with lives system, let Game class handle life loss)
    // 7. If cell has no adjacent mines, call revealAdjacentCells(x, y)
    // 8. Return true on success

    throw std::logic_error("revealCell() function is not yet implemented");
}

bool Board::toggleFlag(int x, int y) {
    // TODO: Implement flag toggling logic
    // 1. Check if position is valid
    // 2. Get the cell at position (x, y)
    // 3. Check if cell is already revealed - return false if so
    // 4. Toggle the flag on the cell
    // 5. Update m_flagCount accordingly (increment if flagged, decrement if unflagged)
    // 6. Return true on success
    throw std::logic_error("toggleFlag() function is not yet implemented");
}

void Board::initializeMines(int firstClickX, int firstClickY) {
    // TODO: Initialize mines on the board
    // 1. Call placeMines(firstClickX, firstClickY) to place mines
    // 2. Call calculateAdjacentMines() to calculate adjacent mine counts
    throw std::logic_error("initializeMines() function is not yet implemented");
}

bool Board::isGameWon() const {
    // TODO: Check if game is won
    // Game is won when all non-mine cells are revealed
    // With lives system, we need to account for revealed mines:
    // 1. Calculate total cells and non-mine cells
    // 2. Get count of revealed mines using getRevealedMineCount()
    // 3. Calculate revealed non-mine cells (m_revealedCount - revealed mines)
    // 4. Return true if all non-mine cells are revealed
    int cnt = 0, nonMine = 0;
    int n = this.getHeight();
    int m = this.getWidth();
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0 ; i < m; ++j)
        {
            if(m_grid[i][j].isRevealed())
                cnt += 1;
            if(!m_grid[i][j].isMine())
                nonMine += 1;
        }
    }
    return nonMine == (cnt - getRevealedMineCount());
    
}

bool Board::isGameLost() const {
    // Check if game is lost
    // Game is lost when any revealed cell contains a mine
    // Loop through all cells and check if any revealed cell is a mine
    // NOTE: With lives system, this method may not be used as game continues after mine hits
    int n = this.getHeight();
    int m = this.getWidth();
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0 ; i < m; ++j)
        {
            if(m_grid[i][j].isRevealed() and m_grid[i][j].isMine())
                return true;
        }
    }
    return false;
}

bool Board::isMineAt(int x, int y) const {
    // Check if there's a mine at specific position (for lives system)
    // 1. Check if position is valid using isValidPosition()
    // 2. Return whether the cell at (x, y) contains a mine
    if (isValidPosition(x, y))
    {
        return m_grid[x][y].isMine();
    }
    return false;
}

int Board::getRevealedMineCount() const {
    // Count revealed mines (for lives system win condition)
    // 1. Loop through all cells in the grid
    // 2. Count cells that are both revealed AND contain mines
    // 3. Return the count
    // This is needed because with lives system, mines can be revealed without ending game
    
    int cnt = 0;
    int n = this.getHeight();
    int m = this.getWidth();
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0 ; i < m; ++j)
        {
            if(m_grid[i][j].isRevealed() and m_grid[i][j].isMine())
                cnt += 1;
        }
    }
    return cnt;
}

void Board::display() const {
    // TODO: Display the game board
    // 1. Print column headers (numbers 0 to width-1)
    // 2. Print horizontal separator line
    // 3. For each row:
    //    - Print row number
    //    - Print each cell's display character using getDisplayChar()
    //    - Print horizontal separator after each row
    // int n = this.getHeight();
    // int m = this.getWidth();
    // for(int i = 0; i < m; ++i)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; ++i)
    // {
    //     for (int j = 0 ; i < m; ++j)
    //     {
    //         m_grid[i][j].reset();
    //     }
    // }
    return ;
}

void Board::displayDebug() const {
    // Display debug view showing all mines
    // Similar to display() but show mines as '*' and adjacent mine counts
    // This helps with debugging and testing
    int n = getHeight();
    int m = getWidth();
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0 ; i < m; ++j)
        {
            m_grid[i][j].reset();
        }
    }

}

int Board::getWidth() const {
    // Return width value
    return m_width;
}

int Board::getHeight() const {
    // Return height value
    return m_height;
}

int Board::getMineCount() const {
    // Return mine count value
    return m_mineCount;
}

int Board::getFlagCount() const {
    // Return flag count value
    return m_flagCount;
}

int Board::getRevealedCount() const {
    // Return revealed count value
    return m_revealedCount;
}

Cell& Board::getCell(int x, int y) {
    // Return reference to cell at position (x, y)
    // Note: Be careful with coordinate system (x, y) vs (row, col)
    return m_grid[x][y];
}

const Cell& Board::getCell(int x, int y) const {
    // Return const reference to cell at position (x, y)
    return m_grid[x][y];
}

bool Board::isValidPosition(int x, int y) const {
    // Check if position (x, y) is within board bounds
    // Return true if 0 <= x < width and 0 <= y < height
    int n = getHeight();
    int m = getWidth();
    return x >= 0 and x < n and y >= 0 and y < m;
}

void Board::reset() {
    // Reset the board to initial state
    // 1. Reset m_flagCount and m_revealedCount to 0
    // 2. Set m_initialized to false
    // 3. Reset all cells in the grid using cell.reset()
    m_flagCount = 0;
    m_revealedCount = 0;
    m_initialized = false;
    int n = getHeight();
    int m = getWidth();
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0 ; i < m; ++j)
        {
            m_grid[i][j].reset();
        }
    }
}

void Board::placeMines(int excludeX, int excludeY) {
    // Place mines randomly on the board
    // 1. Create a vector of all possible positions except (excludeX, excludeY)
    // 2. Shuffle the positions using std::shuffle with m_rng
    // 3. Place mines on the first m_mineCount positions from shuffled list
    // 4. Use cell.setMine(true) to mark cells as mines
    int n = getHeight();
    int m = getWidth();
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0 ; i < m; ++j)
        {
            if (i != excludeX and j != excludeY)
            {
                pos.push_back({i, j});
            }
        }
    }
    shuffle(pos.begin(), pos.end(), m_rng);
    for (int i = 0; i < this->m_mineCount; ++i)
    {
        m_grid[pos[i].first][pos[i].second].setMine(true);
    }
}

void Board::calculateAdjacentMines() {
    // Calculate adjacent mine count for each non-mine cell
    // 1. Loop through all cells
    // 2. For each non-mine cell, count adjacent mines using countAdjacentMines()
    // 3. Set the adjacent mine count using cell.setAdjacentMines()
    int n = getHeight();
    int m = getWidth();
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0 ; i < m; ++j)
        {
            if (!m_grid[i][j].isMine())
            {
                int cnt = countAdjacentMines(i, j);
                m_grid[i][j].setAdjacentMines(cnt);
            }
        }
    }
}

int Board::countAdjacentMines(int x, int y) const {
    // Count mines in adjacent cells
    // 1. Get all adjacent positions using getAdjacentPositions()
    // 2. Count how many of those positions contain mines
    // 3. Return the count
    vector<pair<int, int>> adj = Board::getAdjacentPositions(x, y);
    int cnt = 0;
    for (auto cell: adj)
    {
        cnt += m_grid[cell.first][cell.second].isMine() ? 1: 0;
    }
    return cnt;
}

void Board::revealAdjacentCells(int x, int y) {
    // Reveal adjacent cells automatically (flood fill)
    // 1. Use a queue-based approach for breadth-first search
    // 2. Start with current position in queue
    // 3. For each position in queue:
    //    - Get adjacent positions
    //    - For each adjacent cell that is not revealed, flagged, or a mine:
    //      * Reveal the cell
    //      * Increment m_revealedCount
    //      * If cell has no adjacent mines, add to queue
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        vector<pair<int, int>> nbr = this->getAdjacentPositions(cur.first, cur.second);
        
        for (auto cell: nbr)
        {
            int r = cell.first, c = cell.second;
            if (!this->m_grid[r][c].isMine() and 
                !this->m_grid[r][c].isRevealed() and 
                !this->m_grid[r][c].isFlagged())
            {
                this->m_grid[r][c].reveal();
                this->m_revealedCount += 1;
                if( Board::countAdjacentMines(cell.first, cell.second) == 0 ) Q.push(cell);
            }
        }
    }
}

std::vector<std::pair<int, int>> Board::getAdjacentPositions(int x, int y) const {
    // Get all valid adjacent positions
    // 1. Check all 8 directions around (x, y)
    // 2. Only include positions that are within board bounds
    // 3. Return vector of valid (x, y) pairs
    vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<pair<int, int>> res;
    for (int dir = 0; dir < 8; ++dir)
    {
        int _x = x+dx[dir], _y = y+dy[dir];
        if(isValidPosition(_x, _y))
        {
            res.push_back({_x, _y});
        }
    }
    return res;
}
