#include <iostream>
using namespace std;

class GraphicsEngine {
public:
    void render() const {
        cout << "Rendering graphics...\n";
    }
};

class InputHandler {
public:
    void processInput() const {
        cout << "Processing user input...\n";
    }
};

class PhysicsEngine {
public:
    void simulatePhysics() const {
        cout << "Simulating physics...\n";
    }
};

class GameEngine {
    GraphicsEngine graphics; 
    InputHandler input;     
    PhysicsEngine physics; 

public:
    void run() const {

        cout << "Game Engine Started!\n";
        input.processInput();
        physics.simulatePhysics();
        graphics.render();
        cout << "Game Engine Running Successfully!\n";
        
    }
};

int main() {
    GameEngine game;
    game.run();

    return 0;
}