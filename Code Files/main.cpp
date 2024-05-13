#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "GameScreen.h"
#include "EasyCategory.h"
#include "MediumCategory.h"
#include "HardCategory.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

const int MAX_WORDS = 15;

string AnimalWords[MAX_WORDS] = { "penguin", "koala", "ostrich", "kangaroo", "gorilla", "zebra", "hippopotamus", "octopus", "cheetah", "dolphin", "owl", "seal", "raccoon", "eagle", "wolf" };
string FruitWords[MAX_WORDS] = { "pineapple", "avocado", "blackberry", "blueberry", "apple", "banana", "peach", "pear", "plum", "grape", "kiwi", "mango", "guava", "cherry", "grapefruit" };
string BodyPartWords[MAX_WORDS] = { "head", "arm", "leg", "hand", "foot", "finger", "toe", "neck", "shoulder", "elbow", "knee", "wrist", "ankle", "hip", "back" };
string SportsWords[MAX_WORDS] = { "cricket", "archery", "badminton", "tabletennis", "taekwondo", "football", "polo", "hockey", "squash", "swimming", "rugby", "marathon", "skiing", "volleyball", "judo" };
string MovieWords[MAX_WORDS] = { "titanic", "thelionking", "jurassicpark", "harrypotter", "forrestgump", "theavengers", "findingnemo", "thewizardofoz", "toystory", "spiderman", "fastandfurious", "frozen", "inception", "theincredibles", "thematrix" };
string ProfessionWords[MAX_WORDS] = { "accountant", "architect", "chef", "nurse", "carpenter", "photographer", "teacher", "policeofficer", "firefighter", "lawyer", "engineer", "artist", "writer", "mechanic", "doctor" };
string CountryWords[MAX_WORDS] = { "greece", "argentina", "norway", "thailand", "egypt", "kenya", "newzealand", "portugal", "ireland", "switzerland", "southkorea", "mexico", "australia", "brazil", "canada" };
string CityWords[MAX_WORDS] = { "paris", "rome", "sydney", "riodejaneiro", "cairo", "istanbul", "athens", "bangkok", "amsterdam", "dubai", "venice", "barcelona", "mumbai", "prague", "toronto" };
string HistoricalFigureWords[MAX_WORDS] = { "juliuscaesar", "cleopatra", "genghiskhan", "joanofarc", "leonardodavinci", "queenelizabeth", "napoleonbonaparte", "abrahamlincoln", "mahatmagandhi", "winstonchurchill", "nelsonmandela", "mariecurie", "martinlutherking jr", "queenvictoria", "alexanderthegreat" };

string getRandomWord(const string* wordList, int size) {
    return wordList[rand() % size];
}
int main() {

    srand(time(0));
    string chosenWord = getRandomWord(SportsWords, MAX_WORDS);
    string guessedWord(chosenWord.length(), '_');
    int attempts = 7;


    RenderWindow window(VideoMode(1360, 768), "SFML Project");
    window.setFramerateLimit(60);

    Music bgmusic;
    Music Clickmusic;
    Music Changemusic;

    if (!bgmusic.openFromFile("calmmusic.ogg")) {
        cout << "Unable To Load Music" << endl;
    }
    bgmusic.setLoop(true);
    bgmusic.play();

    if (!Clickmusic.openFromFile("selectsound.wav")) {
        cout << "Unable To Load Music" << endl;
    }

    if (!Changemusic.openFromFile("clicksound.wav")) {
        cout << "Unable To Load Music" << endl;
    }

    Font font;
    if (!font.loadFromFile("durbank.ttf")) {
        cout << "Failed to load font!" << endl;
        return -1;
    }
    Text welcomeText("Welcome to Hangman", font, 120);
    welcomeText.setPosition(Vector2f(260, 750 / 4));

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.jpg")) {
        cout << "Failed to load background image!" << endl;
        return -1;
    }
    Sprite backgroundSprite(backgroundTexture);

    Menu menu(window.getSize().x, window.getSize().y);
    Gamescreen game(window.getSize().x, window.getSize().y);
    EasyCategory easy(window.getSize().x, window.getSize().y);
    Text CategoryText1("CHOOSE FROM THE ", font, 88);
    Text CategoryText2("FOLLOWING CATEGORIES: ", font, 88);
    Text GuessWordText("GUESS THE FOLLOWING WORD: ", font, 88);
    Text TotalAttemptsText("Attempts Left: " + to_string(attempts), font, 30);
    TotalAttemptsText.setString("Attempts Left: " + to_string(attempts));
    GuessWordText.setPosition(Vector2f(850 / 4, 350 / 4));
    TotalAttemptsText.setPosition(Vector2f(720, 600));
    CategoryText1.setPosition(Vector2f(420, 750 / 4));
    CategoryText2.setPosition(Vector2f(420, 1050 / 4));

    MediumCategory medium(window.getSize().x, window.getSize().y);
    HardCategory hard(window.getSize().x, window.getSize().y);

    bool inMenu = true;
    bool inGame = false;
    bool inExit = false;
    bool inEasyCategory = false;
    bool inMediumCategory = false;
    bool inHardCategory = false;
    bool inAnimal = false;
    bool inBodyPart = false;
    bool inFruit = false;
    bool inMovie = false;
    bool inSport = false;
    bool inProfession = false;
    bool inCountry = false;
    bool inCity = false;
    bool inHistFig = false;
    bool PlayingGame = false;
    bool gameWon = false;

    // Main game loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::TextEntered) {
                // Convert the ASCII code of the pressed key to the corresponding character
                char keyPressed = static_cast<char>(event.text.unicode);
                // Check if the pressed key is a letter
                if (isalpha(keyPressed)) {
                    // Convert the pressed key to lowercase
                    char guessedLetter = tolower(keyPressed);
                    // Check if the guessed letter is in the chosen word
                    bool correctGuess = (chosenWord.find(guessedLetter) != string::npos);
                    // Update guessed word with correctly guessed letters
                    for (int i = 0; i < chosenWord.length(); ++i) {
                        if (tolower(chosenWord[i]) == guessedLetter) {
                            guessedWord[i] = chosenWord[i];
                        }
                    }
                    if (!correctGuess) {
                        attempts--;
                    }
                    if (guessedWord == chosenWord) {
                        gameWon = true;
                    }
                }
            }
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyReleased:
                switch (event.key.code) {
                case Keyboard::Up:
                    if (inMenu)
                    {
                        menu.MoveUp();
                        Changemusic.play();
                    }
                    else if (inGame)
                    {
                        game.GameMoveUp();
                        Changemusic.play();
                    }
                    else if (inEasyCategory)
                    {
                        easy.EasyCategorymoveUp();
                        Changemusic.play();
                    }
                    else if (inMediumCategory)
                    {
                        medium.MediumCategorymoveUp();
                        Changemusic.play();
                    }
                    else if (inHardCategory)
                    {
                        hard.HardCategorymoveUp();
                        Changemusic.play();
                    }
                    break;
                case Keyboard::Down:
                    if (inMenu)
                    {
                        menu.MoveDown();
                        Changemusic.play();
                    }
                    else if (inGame)
                    {
                        game.GameMoveDown();
                        Changemusic.play();
                    }
                    else if (inEasyCategory)
                    {
                        easy.EasyCategorymoveDown();
                        Changemusic.play();
                    }
                    else if (inMediumCategory)
                    {
                        medium.MediumCategorymoveDown();
                        Changemusic.play();
                    }
                    else if (inHardCategory)
                    {
                        hard.HardCategorymoveDown();
                        Changemusic.play();
                    }
                    break;
                case Keyboard::Return:
                    if (inMenu) {
                        switch (menu.GetPressedItem()) {
                        case 0:
                            cout << "Play Button has been pressed" << endl;
                            Clickmusic.play();
                            inGame = true;
                            inMenu = false;
                            break;
                        case 1:
                            cout << "Options Button has been pressed" << endl;
                            Clickmusic.play();
                            break;
                        case 2:
                            cout << "Exit Button has been pressed" << endl;
                            Clickmusic.play();
                            inExit = true;
                            break;
                        }
                    }
                    else if (inGame) {
                        switch (game.GameGetPressedItem()) {
                        case 0:
                            cout << "Easy Button has been pressed" << endl;
                            Clickmusic.play();
                            inEasyCategory = true;
                            inGame = false;
                            break;
                        case 1:
                            cout << "Medium Button has been pressed" << endl;
                            Clickmusic.play();
                            inMediumCategory = true;
                            inGame = false;
                            break;
                        case 2:
                            cout << "Hard Button has been pressed" << endl;
                            Clickmusic.play();
                            inHardCategory = true;
                            inGame = false;
                            break;
                        }
                    }
                    else if (inEasyCategory) {
                        int selectedCategory = easy.GetSelectedEasyCategory();
                        switch (selectedCategory) {
                        case 0:
                            cout << "Animal Category has been selected" << endl;
                            Clickmusic.play();
                            inAnimal = true;
                            chosenWord = getRandomWord(AnimalWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inEasyCategory = false;
                            break;
                        case 1:
                            cout << "Body Parts Category has been selected" << endl;
                            Clickmusic.play();
                            inBodyPart = true;
                            chosenWord = getRandomWord(BodyPartWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inEasyCategory = false;
                            break;
                        case 2:
                            cout << "Fruits Category has been selected" << endl;
                            Clickmusic.play();
                            inFruit = true;
                            chosenWord = getRandomWord(FruitWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inEasyCategory = false;
                            break;
                        }
                    }
                    else if (inMediumCategory) {
                        int selectedCategory = medium.GetSelectedMediumCategory();
                        switch (selectedCategory) {
                        case 0:
                            cout << "Movie Category has been selected" << endl;
                            Clickmusic.play();
                            inMovie = true;
                            chosenWord = getRandomWord(MovieWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inMediumCategory = false;
                            break;
                        case 1:
                            cout << "Sports Category has been selected" << endl;
                            Clickmusic.play();
                            inSport = true;
                            chosenWord = getRandomWord(SportsWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inMediumCategory = false;
                            break;
                        case 2:
                            cout << "Profession Category has been selected" << endl;
                            Clickmusic.play();
                            inProfession = true;
                            chosenWord = getRandomWord(ProfessionWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inMediumCategory = false;
                            break;
                        }
                    }
                    else if (inHardCategory) {
                        int selectedCategory = hard.GetSelectedHardCategory();
                        switch (selectedCategory) {
                        case 0:
                            cout << "Country's Category has been selected" << endl;
                            Clickmusic.play();
                            inCountry = true;
                            chosenWord = getRandomWord(CountryWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inHardCategory = false;
                            break;
                        case 1:
                            cout << "City's Category has been selected" << endl;
                            Clickmusic.play();
                            inCity = true;
                            chosenWord = getRandomWord(CityWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inHardCategory = false;
                            break;
                        case 2:
                            cout << "Historical Figures Category has been selected" << endl;
                            Clickmusic.play();
                            inHistFig = true;
                            chosenWord = getRandomWord(HistoricalFigureWords, MAX_WORDS);
                            guessedWord = string(chosenWord.length(), '_');
                            inHardCategory = false;
                            break;
                        }
                    }
                    break;
                }
            }
        }


        if (inExit) {
            cout << "Closing window..." << endl;
            window.close();
        }

        TotalAttemptsText.setString("Attempts Left: " + to_string(attempts));

        if (attempts == 0) {
            Text loseText("You lost! The word was: " + chosenWord, font, 70);
            loseText.setPosition(Vector2f(300, 650 / 4));
            loseText.setFillColor(Color::Red);
            window.draw(loseText);
            window.display();
            continue; // Skip the rest of the loop
        }
        window.clear();
        if (inMenu) {
            window.draw(backgroundSprite);
            menu.Draw(window);
            window.draw(welcomeText);
        }
        else if (inGame) {
            window.draw(backgroundSprite);
            game.GameDraw(window);
        }
        else if (inEasyCategory) {
            window.draw(backgroundSprite);
            window.draw(CategoryText1);
            window.draw(CategoryText2);
            easy.EasyCategoryDraw(window);
        }
        else if (inMediumCategory) {
            window.draw(backgroundSprite);
            window.draw(CategoryText1);
            window.draw(CategoryText2);
            medium.MediumCategoryDraw(window);
        }
        else if (inHardCategory) {
            window.draw(backgroundSprite);
            window.draw(CategoryText1);
            window.draw(CategoryText2);
            hard.HardCategoryDraw(window);
        }
        else if (inAnimal) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70); 
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        else if (inFruit) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70); 
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        else if (inBodyPart) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70); 
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        // Repeating the same pattern for the medium categories
        else if (inMovie) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70); 
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        else if (inSport) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70); 
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        else if (inProfession) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70); 
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        // Repeating the same pattern for the hard categories
        else if (inCountry) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70); 
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        else if (inCity) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70); 
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        else if (inHistFig) {
            window.draw(backgroundSprite);
            Text guessedWordText(guessedWord, font, 70);
            guessedWordText.setPosition(Vector2f(700, 768 / 4 * 2.5));
            window.draw(guessedWordText);
            window.draw(GuessWordText);
            window.draw(TotalAttemptsText);
        }
        if (gameWon) {
            sf::Text winText("Congratulations! You won!", font, 70);
            winText.setPosition(Vector2f(300, 650 / 4));
            winText.setFillColor(Color::Green);
            window.draw(winText);
        }

        window.display();
    }

    return 0;
}
