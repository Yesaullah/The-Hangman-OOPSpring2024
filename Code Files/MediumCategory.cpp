#include "MediumCategory.h"
#include <SFML/Graphics.hpp> // Include SFML graphics library
#include <iostream>

using namespace std;
using namespace sf;

MediumCategory::MediumCategory(float width, float height) {
    MediumCategoryselectedItemIndex = 0;

    if (!font.loadFromFile("durbank.ttf")) {
        // Error handling for font loading failure
        cerr << "Error: Font file not found or cannot be loaded." << endl;
    }

    // Movies
    categories[0].setFont(font);
    categories[0].setString("Movies");
    categories[0].setPosition(Vector2f(width / 2, height / 4 * 2));

    // Sports
    categories[1].setFont(font);
    categories[1].setString("Sports");
    categories[1].setPosition(Vector2f(width / 2, height / 4 * 2.5));

    // Profession
    categories[2].setFont(font);
    categories[2].setString("Profession");
    categories[2].setPosition(Vector2f(width / 2, height / 4 * 3));

    // Set color and style for the categories
    for (int i = 0; i < MAX_MediumCategoryITEMS; ++i) {
        categories[i].setFillColor(Color::White);
        categories[i].setCharacterSize(40);
    }

    // Set the first category (Movies) to be highlighted initially
    categories[MediumCategoryselectedItemIndex].setFillColor(Color::Red);
}

void MediumCategory::MediumCategoryDraw(RenderWindow& window) {
    for (int i = 0; i < MAX_MediumCategoryITEMS; ++i) {
        window.draw(categories[i]);
    }
}

void MediumCategory::MediumCategorymoveUp() {
    if (MediumCategoryselectedItemIndex > 0) {
        categories[MediumCategoryselectedItemIndex].setFillColor(Color::White);
        MediumCategoryselectedItemIndex--;
        categories[MediumCategoryselectedItemIndex].setFillColor(Color::Red);
    }
}

void MediumCategory::MediumCategorymoveDown() {
    if (MediumCategoryselectedItemIndex < MAX_MediumCategoryITEMS - 1) {
        categories[MediumCategoryselectedItemIndex].setFillColor(Color::White);
        MediumCategoryselectedItemIndex++;
        categories[MediumCategoryselectedItemIndex].setFillColor(Color::Red);
    }
}

int MediumCategory:: GetSelectedMediumCategory(){
    return MediumCategoryselectedItemIndex;
}
