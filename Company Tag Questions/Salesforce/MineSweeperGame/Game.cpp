#include "Game.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayWelcome() {
    std::cout << "╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                 MINESWEEPER                    ║" << std::endl;
    std::cout << "║                 WITH LIVES!                    ║" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    std::cout << "║  Select Difficulty Level:                      ║" << std::endl;
    std::cout << "║  1. Beginner   (8x8,  10 mines)                ║" << std::endl;
    std::cout << "║  2. Intermediate (14x14, 30 mines)             ║" << std::endl;
    std::cout << "║  3. Expert     (20x20, 80 mines)               ║" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    std::cout << "║  NEW: You have 2 lives! Hitting a mine         ║" << std::endl;
    std::cout << "║       costs 1 life, but you can continue!      ║" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    std::cout << "║  During game: Type 'h' for help, 'q' to quit   ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
}

Game::Difficulty selectDifficulty() {
    int choice;
    while (true) {
        std::cout << "\nEnter your choice (1-3): ";
        if (std::cin >> choice) {
            switch (choice) {
                case 1:
                    return Game::Difficulty::BEGINNER;
                case 2:
                    return Game::Difficulty::INTERMEDIATE;
                case 3:
                    return Game::Difficulty::EXPERT;
                default:
                    std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
                    break;
            }
        } else {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void displayDifficultyInfo(Game::Difficulty difficulty) {
    std::string levelName;
    std::string gridSize;
    int mines;
    
    switch (difficulty) {
        case Game::Difficulty::BEGINNER:
            levelName = "BEGINNER";
            gridSize = "8x8";
            mines = 10;
            break;
        case Game::Difficulty::INTERMEDIATE:
            levelName = "INTERMEDIATE";
            gridSize = "14x14";
            mines = 30;
            break;
        case Game::Difficulty::EXPERT:
            levelName = "EXPERT";
            gridSize = "20x20";
            mines = 80;
            break;
    }
    
    std::cout << "\n╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  " << levelName << " LEVEL SELECTED" << std::string(28 - levelName.length(), ' ') << "║" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    std::cout << "║  Grid Size: " << gridSize << std::string(32 - gridSize.length(), ' ') << "║" << std::endl;
    std::cout << "║  Mines: " << mines << std::string(36 - std::to_string(mines).length(), ' ') << "║" << std::endl;
    std::cout << "║  Lives: 2                                      ║" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    std::cout << "║  Good luck and have fun!                      ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
}


bool processCommand(Game game, const std::string& input) {
    std::istringstream iss(input);
    std::string command;
    iss >> command;
    
    if (command.empty()) {
        return true;
    }
    
    char cmd = command[0];
    
    switch (cmd) {
        case 'h':
        case 'H':
            game.displayHelp();
            break;
            
        case 'q':
        case 'Q':
            std::cout << "Thanks for playing!" << std::endl;
            return false;
            
        case 'n':
        case 'N':
            game.restart();
            std::cout << "New game started! Lives reset to " << game.getMaxLives() << "." << std::endl;
            break;
            
        case 'd':
        case 'D':
            if (game.getBoard()) {
                game.getBoard()->displayDebug();
            }
            break;
            
        case 'l':
        case 'L': {
            // New command to set lives
            int lives;
            if (iss >> lives) {
                game.setMaxLives(lives);
                std::cout << "Max lives set to " << game.getMaxLives() << std::endl;
            } else {
                std::cout << "Current lives: " << game.getLives() << "/" << game.getMaxLives() << std::endl;
            }
            break;
        }
            
        case 'r':
        case 'R':
        case 'f':
        case 'F': {
            int x, y;
            if (iss >> x >> y) {
            
                if (game.getBoard()->isValidPosition(x, y)) {
                    bool success = game.makeMove(x, y, cmd);
                    if (!success && (cmd == 'r' || cmd == 'R')) {
                        if (game.getBoard()->getCell(x, y).isFlagged()) {
                            std::cout << "Cannot reveal a flagged cell. Remove flag first." << std::endl;
                        } else if (game.getBoard()->getCell(x, y).isRevealed()) {
                            std::cout << "Cell already revealed." << std::endl;
                        }
                    }
                } else {
                    std::cout << "Invalid coordinates. Please check the board dimensions." << std::endl;
                }
            } else {
                std::cout << "Invalid command format. Use: " << cmd << " <x> <y>" << std::endl;
            }
            break;
        }
        
        default:
            std::cout << "Unknown command. Type 'h' for help." << std::endl;
            break;
    }
    
    return true;
}

int main() {
    try {
        displayWelcome();
        Game::Difficulty difficulty = selectDifficulty();
        displayDifficultyInfo(difficulty);
        
        // Clear input buffer after difficulty selection
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        Game game(difficulty);
        std::string input;
        
        std::cout << "\nPress Enter to start playing..." << std::endl;
        std::getline(std::cin, input);
        
        while (true) {
            std::cout << std::endl;
            game.displayGameInfo();
            game.displayBoard();
            
            if (game.isGameOver()) {
                if (game.getState() == Game::GameState::WON) {
                    std::cout << "\n🎉 CONGRATULATIONS! You won";
                    if (game.getLives() < game.getMaxLives()) {
                        std::cout << " (used " << (game.getMaxLives() - game.getLives()) << " lives)";
                    }
                    std::cout << "! 🎉" << std::endl;
                } else {
                    std::cout << "\n💀 GAME OVER - All lives lost! 💀" << std::endl;
                }
                std::cout << "Type 'n' for new game or 'q' to quit." << std::endl;
            }
            
            std::cout << "\nEnter command: ";
            std::getline(std::cin, input);
            
            if (!processCommand(game, input)) {
                
            }
            
            // Clear screen for better visibility (optional)
            // clearScreen();
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }
    
    return 0;
}