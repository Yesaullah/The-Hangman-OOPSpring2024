#include "HardCategory.h"
#include <SFML/Graphics.hpp> // Include SFML graphics library
#include <iostream>

using namespace std;
using namespace sf;

HardCategory::HardCategory(float width, float height) {
    HardCategoryselectedItemIndex = 0;

    if (!font.loadFromFile("durbank.ttf")) {
        // Error handling for font loading failure
        cerr << "Error: Font file not found or cannot be loaded." <<endl;
    }

    // Countries
    categories[0].setFont(font);
    categories[0].setString("Countries");
    categories[0].setPosition(Vector2f(width / 2, height / 4 * 2));

    // Cities
    categories[1].setFont(font);
    categories[1].setString("Cities");
    categories[1].setPosition(Vector2f(width / 2, height / 4 * 2.5));

    // Historical Figures
    categories[2].setFont(font);
    categories[2].setString("Historical Figures");
    categories[2].setPosition(Vector2f(width / 2, height / 4 * 3));

    // Set color and style for the categories
    for (int i = 0; i < MAX_HardCategoryITEMS; ++i) {
        categories[i].setFillColor(Color::White);
        categories[i].setCharacterSize(40);
    }

    // Set the first category (Countries) to be highlighted initially
    categories[HardCategoryselectedItemIndex].setFillColor(Color::Red);
}

void HardCategory::HardCategoryDraw(RenderWindow& window) {
    for (int i = 0; i < MAX_HardCategoryITEMS; ++i) {
        window.draw(categories[i]);
    }
}

void HardCategory::HardCategorymoveUp() {
    if (HardCategoryselectedItemIndex > 0) {
        categories[HardCategoryselectedItemIndex].setFillColor(Color::White);
        HardCategoryselectedItemIndex--;
        categories[HardCategoryselectedItemIndex].setFillColor(Color::Red);
    }
}

void HardCategory::HardCategorymoveDown() {
    if (HardCategoryselectedItemIndex < MAX_HardCategoryITEMS - 1) {
        categories[HardCategoryselectedItemIndex].setFillColor(Color::White);
        HardCategoryselectedItemIndex++;
        categories[HardCategoryselectedItemIndex].setFillColor(Color::Red);
    }
}

int HardCategory::GetSelectedHardCategory(){
    return HardCategoryselectedItemIndex;
}

