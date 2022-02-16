#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty) {
    std::cout << "------------------------------------------------------------\n";
    std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room...\n" ;
    std::cout << "Enter the correct code to continue...\n";
}

bool PlayGame(int Difficulty) {
    PrintIntro(Difficulty);
    const int CodeA = rand() % (Difficulty + 2) + 1;
    const int CodeB = rand() % (Difficulty + 2) + 1;
    const int CodeC = rand() % (Difficulty + 2) + 1;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code \n";
    std::cout << "The codes add-up to: " << CodeSum << "\n";
    std::cout << "The codes multiply to give: " << CodeProduct << "\n\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\n*** You guessed the code! You can move on to the next level.\n";
        std::cout << "------------------------------------------------------------\n\n";
        return true;
    }
    else {
        std::cout << "\n*** You entered the wrong code! Try again.\n";
        std::cout << "------------------------------------------------------------\n\n";
        return false;
    }
    

}

int main() {
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while(LevelDifficulty <= MaxDifficulty) {
        bool LevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();
        
        if (LevelComplete == true) {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n------------------";
    std::cout << "\n*** You have successfully broken into all 5 security rooms!\n";
    std::cout << "------------------\n";

    return 0;
}
