#include <iostream>
#include <termios.h> // For terminal control
#include <unistd.h>  // For read()

int main() {
    // Save current terminal settings
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Set terminal to raw mode (disable canonical mode and echo)
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 1; // Read at least 1 character
    newt.c_cc[VTIME] = 0; // No timeout
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    std::cout << "Press arrow keys (press 'q' to quit):" << std::endl;

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == 'q') {
            break; // Exit on 'q'
        } else if (c == '\033') { // Escape sequence for special keys
            char c2, c3;
            read(STDIN_FILENO, &c2, 1); // Read '['
            read(STDIN_FILENO, &c3, 1); // Read the actual key code

            if (c2 == '[') {
                switch (c3) {
                    case 'A':
                        std::cout << "Up Arrow Pressed" << std::endl;
                        break;
                    case 'B':
                        std::cout << "Down Arrow Pressed" << std::endl;
                        break;
                    case 'C':
                        std::cout << "Right Arrow Pressed" << std::endl;
                        break;
                    case 'D':
                        std::cout << "Left Arrow Pressed" << std::endl;
                        break;
                    default:
                        std::cout << "Unknown escape sequence: " << (int)c3 << std::endl;
                        break;
                }
            }
        } else {
            std::cout << "Key pressed: " << c << std::endl;
        }
    }

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}