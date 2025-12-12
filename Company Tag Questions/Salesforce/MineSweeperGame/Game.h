#include "Game.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <chrono>

Game::Game(Difficulty difficulty)
    : m_board(nullptr)
    , m_gameState(GameState::NOT_STARTED)
    , m_difficulty(difficulty)
    , m_firstMove(true)
    , m_lives(DEFAULT_MAX_LIVES)
    , m_maxLives(DEFAULT_MAX_LIVES)
{
    // Minimal constructor implementation to prevent test skips
    // Create a basic board to prevent segfaults, but other functions will still throw
    try {
        initializeBoard();
    } catch (const std::logic_error&) {
        // Fallback: create a minimal board to prevent crashes
        m_board = new Board(8, 8, 10);
    }
}

Game::~Game() {
    delete m_board;
}

void Game::start() {
    // TODO: Start the game
    // 1. Set game state to IN_PROGRESS
    // 2. Record start time using std::chrono::steady_clock::now()
    // 3. Set m_firstMove to true
    throw std::logic_error("start() function is not yet implemented");
}

void Game::restart() {
    // TODO: Restart the game
    // 1. Delete current board
    // 2. Initialize new board
    // 3. Reset game state to NOT_STARTED
    // 4. Set m_firstMove to true
    // 5. Reset lives using resetLives() for full restart
    throw std::logic_error("restart() function is not yet implemented");
}

bool Game::makeMove(int x, int y, char action) {
    // TODO: Make a move in the game
    // 1. If game not started, call start()
    // 2. If game is over, return false
    // 3. Handle action 'r'/'R' for reveal:
    //    - Call board->revealCell(x, y)
    //    - If unsuccessful and cell is a mine (Lives System):
    //      * Call loseLife() to reduce lives
    //      * If hasLivesRemaining(), continue game and show mine hit message
    //      * If no lives left, set state to LOST and record end time
    // 4. Handle action 'f'/'F' for flag:
    //    - Call board->toggleFlag(x, y)
    // 5. Call updateGameState() to check win/loss conditions
    // 6. Set m_firstMove to false
    throw std::logic_error("makeMove() function is not yet implemented");
}

Game::GameState Game::getState() const {
    // Return current game state (this works)
    return m_gameState;
}

bool Game::isGameOver() const {
    // TODO: Return true if game is won or lost
    throw std::logic_error("isGameOver() function is not yet implemented");
}

double Game::getElapsedTime() const {
    // TODO: Calculate and return elapsed time in seconds
    throw std::logic_error("getElapsedTime() function is not yet implemented");
}

int Game::getLives() const {
    // TODO: Return the current number of lives remaining
    throw std::logic_error("getLives() function is not yet implemented");
}

int Game::getMaxLives() const {
    // Return maximum number of lives (this works)
    return m_maxLives;
}

bool Game::hasLivesRemaining() const {
    // Return true if player has lives remaining (this works)
    return m_lives > 0;
}

void Game::setMaxLives(int maxLives) {
    // TODO: Set maximum number of lives
    // 1. Check if maxLives is positive
    // 2. Set m_maxLives to maxLives
    // 3. Reset current lives to maxLives
    throw std::logic_error("setMaxLives() function is not yet implemented");
}

void Game::resetLives() {
    // TODO: Reset current lives to maximum lives
    // Set m_lives = m_maxLives
    throw std::logic_error("resetLives() function is not yet implemented");
}

void Game::displayBoard() const {
    // TODO: Display the game board
    // Call board->display() if board exists
    throw std::logic_error("displayBoard() function is not yet implemented");
}

void Game::displayGameInfo() const {
    // TODO: Display game information
    // 1. Show difficulty level name (BEGINNER/INTERMEDIATE/EXPERT)
    // 2. Show grid dimensions and mine count
    // 3. Show flag count and remaining mines
    // 4. Show lives information (current/max lives) - NEW for lives system
    // 5. Show elapsed time
    // 6. Show current game status with lives-specific messages:
    //    - For IN_PROGRESS: warn if lives lost
    //    - For WON: show lives used if any
    //    - For LOST: show lives-specific game over message
    throw std::logic_error("displayGameInfo() function is not yet implemented");
}

void Game::displayHelp() const {
    // TODO: Display help information
    // Show available commands, game legend, objective, and lives system info:
    // 1. Commands (reveal, flag, help, quit, new game, debug)
    // 2. Legend (symbols and their meanings)
    // 3. Lives System explanation:
    //    - Starting lives count
    //    - Life loss on mine hit
    //    - Continuation after mine hit
    //    - Game over when all lives lost
    // 4. Objective (reveal all non-mine cells)
    throw std::logic_error("displayHelp() function is not yet implemented");
}

Board* Game::getBoard() {
    // Return pointer to board (this works to prevent segfaults)
    return m_board;
}

const Board* Game::getBoard() const {
    // Return const pointer to board (this works to prevent segfaults)
    return m_board;
}

void Game::initializeBoard() {
    // TODO: Initialize board based on difficulty
    // 1. Get width, height, and mine count using getDifficultySettings()
    // 2. Create new Board with these parameters
    throw std::logic_error("initializeBoard() function is not yet implemented");
}

void Game::updateGameState() {
    // TODO: Update game state based on board conditions
    // 1. If game is IN_PROGRESS:
    //    - Check if board->isGameWon(), set state to WON and record end time
    // NOTE: With lives system, don't check isGameLost() here anymore
    // Mine hits are handled in makeMove() and only end game when lives run out
    throw std::logic_error("updateGameState() function is not yet implemented");
}

void Game::getDifficultySettings(int& width, int& height, int& mines) const {
    // TODO: Set difficulty parameters based on m_difficulty
    // BEGINNER: 8x8, 10 mines
    // INTERMEDIATE: 14x14, 30 mines  
    // EXPERT: 20x20, 80 mines
    throw std::logic_error("getDifficultySettings() function is not yet implemented");
}

void Game::loseLife() {
    // TODO: Reduce lives by 1 if lives > 0
    throw std::logic_error("loseLife() function is not yet implemented");
}

void Game::continueAfterLifeLost() {
    // TODO: Handle continuation after life lost
    // The mine that was hit remains revealed as a warning
    // The game continues in IN_PROGRESS state
    // No other changes needed - player can continue from current state
    throw std::logic_error("continueAfterLifeLost() function is not yet implemented");
}