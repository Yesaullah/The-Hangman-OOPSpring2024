#include "EasyCategory.h"
#include <SFML/Graphics.hpp> // Include SFML graphics library
#include <iostream>

using namespace std;
using namespace sf;

EasyCategory::EasyCategory(float width, float height) {
    EasyCategoryselectedItemIndex = 0;

    if (!font.loadFromFile("durbank.ttf")) {
        // Error handling for font loading failure
        cerr << "Error: Font file not found or cannot be loaded." << endl;
    }

    // Animals
    categories[0].setFont(font);
    categories[0].setString("Animals");
    categories[0].setPosition(Vector2f(width / 2, height / 4 * 2));

    // Body parts
    categories[1].setFont(font);
    categories[1].setString("Body Parts");
    categories[1].setPosition(Vector2f(width / 2, height / 4 * 2.5));

    // Fruits
    categories[2].setFont(font);
    categories[2].setString("Fruits");
    categories[2].setPosition(Vector2f(width / 2, height / 4 * 3));

    // Set color and style for the categories
    for (int i = 0; i < MAX_EasyCategoryITEMS; ++i) {
        categories[i].setFillColor(Color::White);
        categories[i].setCharacterSize(40);
    }

    // Set the first category (Animals) to be highlighted initially
    categories[EasyCategoryselectedItemIndex].setFillColor(Color::Red);
}

void EasyCategory::EasyCategoryDraw(RenderWindow& window) {
    for (int i = 0; i < MAX_EasyCategoryITEMS; ++i) {
        window.draw(categories[i]);
    }
}

void EasyCategory::EasyCategorymoveUp() {
    if (EasyCategoryselectedItemIndex > 0) {
        categories[EasyCategoryselectedItemIndex].setFillColor(Color::White);
        EasyCategoryselectedItemIndex--;
        categories[EasyCategoryselectedItemIndex].setFillColor(Color::Red);
    }
}

void EasyCategory::EasyCategorymoveDown() {
    if (EasyCategoryselectedItemIndex < MAX_EasyCategoryITEMS - 1) {
        categories[EasyCategoryselectedItemIndex].setFillColor(Color::White);
        EasyCategoryselectedItemIndex++;
        categories[EasyCategoryselectedItemIndex].setFillColor(Color::Red);
    }
}

int EasyCategory:: GetSelectedEasyCategory() {
    return EasyCategoryselectedItemIndex;
}
