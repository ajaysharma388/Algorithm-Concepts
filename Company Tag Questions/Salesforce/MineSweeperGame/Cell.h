#include "Cell.h"
#include <stdexcept>  // Include to use std::logic_error

// class Cell {
//     private:
//     bool m_isMine;
//     bool m_isRevealed;
//     bool m_isFlagged;
//     bool m_adjacentMines;
//     State m_state;
// }

Cell::Cell() 
    : m_isMine(false)
    , m_isRevealed(false)
    , m_isFlagged(false)
    , m_adjacentMines(0)
    , m_state(State::HIDDEN)
{
    // Initialize cell to default state
    // All member variables should be set to default values
    // (Already initialized in initializer list above)
    this->reset();
}

bool Cell::isMine() const {
    // Return whether this cell contains a mine
    return this->m_isMine;
}

bool Cell::isRevealed() const {
    // Return whether this cell is revealed
    // Check if state is REVEALED
    return this->m_state == State::REVEALED;
}

bool Cell::isFlagged() const {
    // Return whether this cell is flagged
    // Check if state is FLAGGED
    return this->m_state == State::FLAGGED;
}

int Cell::getAdjacentMines() const {
    // Return the number of adjacent mines
    return this->m_adjacentMines;
    // throw std::logic_error("getAdjacentMines() function is not yet implemented");
}

Cell::State Cell::getState() const {
    // Return the current state of the cell
    return this->m_state;
}

void Cell::setMine(bool mine) {
    // Set whether this cell contains a mine
    this->m_isMine = mine;
    // throw std::logic_error("setMine() function is not yet implemented");
}

void Cell::setAdjacentMines(int count) {
    // Set the number of adjacent mines
    this->m_adjacentMines = count;
}

void Cell::reveal() {
    // Reveal the cell
    // Only reveal if cell is not flagged
    // Set state to REVEALED and update m_isRevealed
    if (this->m_state != State::FLAGGED)
    {
        this->m_state = State::REVEALED;
        this->m_isRevealed = true;
    }
}

void Cell::toggleFlag() {
    // Toggle flag status
    // If HIDDEN, change to FLAGGED and update m_isFlagged
    // If FLAGGED, change to HIDDEN and update m_isFlagged
    // Cannot flag a revealed cell
    if (this->m_state == State::HIDDEN)
    {
        this->m_state = State::FLAGGED;
        this->m_isFlagged = true;
    }
    else if (this->m_state == State::FLAGGED)
    {
        this->m_state = State::HIDDEN;
        this->m_isFlagged = false;
    }
}

void Cell::reset() {
    // Reset cell to initial state
    // Set all member variables back to default values
    this->m_isMine = false;
    this->m_isRevealed = false;
    this->m_isFlagged = false;
    this->m_adjacentMines = 0;
    this->m_state = State::HIDDEN;
    // throw std::logic_error("reset() function is not yet implemented");
}

char Cell::getDisplayChar() const {
    // Return character to display for this cell
    // FLAGGED: return 'F'
    // REVEALED and mine: return '*'
    // REVEALED and no adjacent mines: return ' ' (space)
    // REVEALED with adjacent mines: return '0' + adjacentMines
    // HIDDEN: return '#'
    if (this->m_isFlagged) return 'F';
    else if (this->m_isRevealed and this->m_isMine) return '*';
    else if (this->m_isRevealed)
        return this->m_adjacentMines > 0 ? this->m_adjacentMines - '0': ' '; 
    else if (this->m_state == State::HIDDEN) return '#';
    else 
        throw std::logic_error("getDisplayChar() function is not yet implemented");
}
