#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void Draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {
        return Index;
    }

private:
    static const int Max_Number_Of_Items = 3; 
    int Index=0;
    sf::Font font;
    sf::Text menu[Max_Number_Of_Items]; 
};
