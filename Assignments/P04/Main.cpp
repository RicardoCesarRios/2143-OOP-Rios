/*****************************************************************************
 *
 *  Author:           Ricardo Rios
 *  Email:            RicardoCesarRios14@outlook.com
 *  Label:            Program 4
 *  Title:            Rock Paper Scissors Lizard Spock
 *  Course:           2143 Object oriented Programming
 *  Semester:         Fall 2022
 *
 *  Description:
 *        This program interates through a map with a set of inputs in order to
 *determine Whether one input will beat the other according to the rules of Rock
 *Paper Scissors Lizard Spock from The show The Big Bang Theory Usage: In order
 *to use the program run the program follow the listed instructions and the
 *        Program will reply with the appropriate answer
 *
 *  Files:          main.cpp
 *                  emojis.h
 *****************************************************************************/

#include <iostream>
//#include "emoji.h"    //https://github.com/99x/emojicpp
#include <functional> // needed for `bind`
#include <map>
#include <random>
#include <string>

using namespace std;

#define ROCK u8"\U0000270A"
#define PAPER u8"\U0000270B"
#define SCISSORS u8"\U0001F44C"
#define LIZARD u8"\U0001F918"
#define SPOCK u8"\U0001F596"

#define ROCK2 u8"\U0001F5FB"
#define PAPER2 u8"\U0001F4C3"
#define SCISSORS2 u8"\U0001F52A"
#define LIZARD2 u8"\U0001F438"
#define SPOCK2 u8"\U0001F596"

/**
 * This class is used to test the random number generators by creating an
 * array with the same sides as some die. Then counting the values generated
 * between 1 and die size. There should be an equal number in every slot, which
 * for a 20 sided die is about .05 or 5 percent in each.
 *
 */
class Tester {
  int *arr;
  int size;

public:
  Tester() : size{20} {
    arr = new int[size + 1];
    initArr();
  }

  Tester(int size) : size{size} {
    arr = new int[size + 1];
    initArr();
  }

  void initArr() {
    for (int i = 0; i < size + 1; i++) {
      arr[i] = 0;
    }
  }

  // add random value to distribution table
  void load(int i) { arr[i]++; }

  // generate  the distribution table
  void distro(double res[], double total) {
    for (int i = 0; i < size + 1; i++) {
      res[i] = (double)arr[i] / total;
    }
  }
};

/**
 * RandRoll
 * @description: A class to implement roll playing dice rolls.
 * @methods:
 * private:
 *      int Random(Max) : returns a value between 0 and max.
 *      int Random(Min , Max) : returns a value between min and max
 *      void init(int , int)  : initialize class
 * public:
 *      DieRoll()
 *      DieRoll(int)
 *      DieRoll(int,int)
 *      void setDie(int)    : set sides
 *      int Roll(int,int)   :  NEEDS FIXING!!!!!!
 */
class DieRoll {
  int sides;

  int Random(int max) { return 1 + (rand() % max); }

  // min = 40 max = 100
  int Random(int min, int max) { return 1 + min + (rand() % (max - min)); }
  void init(int _seed, int _sides) {
    sides = _sides;
    srand(_seed);
  }

public:
  DieRoll() {
    // cout << "default base" << endl;
    init(time(0), 6);
  }
  DieRoll(int _seed) {
    // cout << "overloaded const" << endl;
    init(_seed, 6);
  }
  DieRoll(int _seed, int _sides) {
    // cout << "overloaded const" << endl;
    init(_seed, _sides);
  }

  void setDie(int _sides) { sides = _sides; }

  // NEEDS FIXING!!!
  int Roll(int sides, int times) {
    int sum = 0;
    while (times--) {
      sum += Random(sides);
    }
    return sum;
  }
};

/**
 * RandRoll
 * @description: A random die roller using a "better" random
 *      number generator. Docs: https://www.cplusplus.com/reference/random/
 *
 * @methods:
 *     int Roll(int)    : give the "sides" will return an int between 1 and
 * sides inclusive.
 *
 */
class RandRoll {
  default_random_engine generator;
  uniform_int_distribution<int> dieMap[21];

public:
  /**
   * Constructor
   *
   * @description: Create an stl array that has the common dice values
   *              loaded as uniform distribution types.
   *
   *  Wasteful, as not every array location has a uniform distribution
   *  associated with it. Could you make it less wasteful?
   */
  RandRoll() {
    dieMap[4] = uniform_int_distribution<int>(1, 4);
    dieMap[6] = uniform_int_distribution<int>(1, 6);
    dieMap[8] = uniform_int_distribution<int>(1, 8);
    dieMap[10] = uniform_int_distribution<int>(1, 10);
    dieMap[12] = uniform_int_distribution<int>(1, 12);
    dieMap[20] = uniform_int_distribution<int>(1, 20);
  }

  /**
   * Generate a random number depending on the "sides" of the dice.
   */
  int Roll(int sides) {
    int diceRoll = dieMap[sides](generator);
    return diceRoll;
  };
};

/**
 * Hands
 *
 * @description: A static class that only has references to
 *      emojis for printing out Rock Paper Scissors Lizard Spock
 *
 * @methods:
 *      string RandHand()   : returns a random hand (emoji)
 *      string Rock()       : returns the emoji for "rock"
 *      string Paper()      : returns the emoji for "paper"
 *      string Scissors()   : returns the emoji for "scissors"
 *      string Lizard()     : returns the emoji for "lizard"
 *      string Spock()      : returns the emoji for "spock"
 */
struct Hands {
  const string rock = ROCK2;
  const string paper = PAPER2;
  const string scissors = SCISSORS2;
  const string lizard = LIZARD2;
  const string spock = SPOCK2;

  static map<string, string> Emojis; // stl map
  //         name  , emoji

  static map<string, string> Names; // stl map
  //         emoji  , name

  static string RandHand() {
    auto it = Emojis.begin(); // iterator to front of map

    std::advance(it, rand() % Emojis.size()); // advance some random amnt
                                              //   of steps

    string random_hand = it->second; // grab emoji from map

    return random_hand; // return rand emoji
  }

  static string Rock() { return Emojis["rock"]; }
  static string Paper() { return Emojis["paper"]; }
  static string Scissors() { return Emojis["scissors"]; }
  static string Lizard() { return Emojis["lizard"]; }
  static string Spock() { return Emojis["spock"]; }
};

// initialize static data member for
// hands struct (class)
map<string, string> Hands::Emojis = {{"rock", ROCK2},
                                     {"paper", PAPER2},
                                     {"scissors", SCISSORS2},
                                     {"lizard", LIZARD2},
                                     {"spock", SPOCK2}};
// initialize static data member for
// hands struct (class)
map<string, string> Hands::Names = {{ROCK2, "rock"},
                                    {PAPER2, "paper"},
                                    {SCISSORS2, "scissors"},
                                    {LIZARD2, "lizard"},
                                    {SPOCK2, "spock"}};

/**
 * Rock Paper Scissors Lizard Spock
 *
 * @description: A class to run the rock papers scissors game
 *
 * Scissors cuts Paper
 * Paper covers Rock
 * Rock crushes Lizard
 * Lizard poisons Spock
 * Spock smashes Scissors
 * Scissors decapitates Lizard
 * Lizard eats Paper
 * Paper disproves Spock
 * Spock vaporizes Rock
 * Rock crushes Scissors
 */

/**
 * ClassPlayer
 *
 * Description:
 *     Creates an instance of "Player" which is used as a container for the
 * emojis and indicated choice of attack
 *
 * Public Methods:
 Player()
 *       string getCname()
 *       void sethand
 *       friend ostream &operator<<      
 *
 * Protected Methods:
 *       
 *
 * Usage:
 *
 *      The user will not be touching these functions as they used as constructors
 */

class Player : public Hands {
protected:
  string hand;

public:
  Player() { hand = RandHand(); }
  string getCname() { return Hands::Names[hand]; }
  void sethand(string a) { hand = Hands::Emojis[a]; }

  friend ostream &operator<<(ostream &os, const Player &P) {
    return os << P.hand;
  }
};


/**
 * class RPSLS : public DieRoll, public Hands
 * 
 * Description:
 *      This contains the flesh of the program it mainly consists of the rules 
 *       for the game as well as methods that exist mainly to display data to
 *       the console  
 * Public Methods:
 *       int GameMenu()
 *       string PlayerMenu()
 *        void Displayemoji
 *       int Solution returns a map cordinate
 * Private Methods:
 *      - map<string, map<string, int>> SolutionsMap;
 *      
 *      
 * 
 * Usage: 
 * 
 *      In order to ulilize the class simply add parameters to the map such as 
 *      Items in the rows and allocate an array of values that will serve as a key
 *      
 *      
 */


class RPSLS : public DieRoll, public Hands {
private:
  map<string, map<string, int>> SolutionsMap;
  string characters[5] = {"rock", "paper", "scissors", "lizard", "spock"};

public:
  RPSLS() {
    int rules[][5] = {{0, -1, 1, 1, -1},
                      {1, 0, -1, -1, 1},
                      {-1, 1, 0, 1, -1},
                      {-1, 1, -1, 0, 1},
                      {1, -1, 1, -1, 0}};
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        SolutionsMap[characters[i]][characters[j]] = rules[i][j];
      }
    }
  }

  //----------------------------------------------------------------------------------

    /**
     * Public: int GameMenu()
     * 
     * Description:
     *     Displays two options to the console for the player to choose
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *     Returns an int that decides the game type that will run
     */
  int GameMenu() {
    int gameMenu;
    cout << "Please select the gamemode you'd like to play by entering 1 0r "
            "2 \n";
    cout << "Options are as follows \n";
    cout << "Option 1 CPU vs CPU \n";
    cout << "Option 2 Player vs CPU \n";
    cout << endl;
    cin >> gameMenu;
    return gameMenu;
  }
  //----------------------------------------------------------------------------------

    /**
     * Public string PlayerMenu()
     * 
     * Description:
     *     Displays weapon options to the console for the player to choose
     *     runs if player decided to play themselves rather than comp v comp
     * Params:
     *      - N/A
     * 
     * Returns:
     *      Retuns the weapon chosen by the player 
     */
  
  string PlayerMenu() {
    string playerMenu;

    cout << "!CAUTION! (Case sensitive) \n";
    cout << "Please choose one of the following options  \n";
    cout << "rock, paper, scissors, lizard, or spock\n";
    cin >> playerMenu;
    cout << endl;
    return playerMenu;
  }

    /**
     * Public void Displayemoji
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      -  Void Player P1 holds and displays the emoji correlating the the map
     *         coordiante given to Player instance 1
     *
     *      - Void Player CPU holds and displays the emoji correlating the the map
     *        coordiante given to Player instance 2
     *      - 
     *      - 
     * 
     * Returns:
     *     Nothing
     */
  void Displayemoji(Player P1, Player CPU) {
    cout << endl;
    cout << "CPU1 USED: " << P1;
    cout << endl;
    cout << endl;
    cout << "CPU2 USED: " << CPU;
  }


    /**
     * Public Int Solution()
     * 
     * Description:
     *      Reads in two values use them as coordinates for the map 
     *      And returns the Values that is locates at said Coordinate
     * 
     * Params:
     *      - String a The row value of the map
     *      - string b The column value of the map 
     *      - 
     * 
     * Returns:
     *     Int Value within a coordinate on a map
     */
  int Solution(string a, string b) 
  { 
    return SolutionsMap[a][b]; 
  }

  RPSLS(int seed) : DieRoll(seed) { cout << "Rock: " << Rock() << endl; }
};

int main() {
  int gameMenu, Solution;
  string playerMenu;
  RPSLS Game;
  Player CPU1;
  Player CPU2;
  Player P1;
  gameMenu = Game.GameMenu();

  if (gameMenu == 1) {
    Game.Displayemoji(CPU1, CPU2);
    Solution = Game.Solution(CPU1.getCname(), CPU2.getCname());
    if (Solution == 1) {
      cout << endl;
      cout << "!ITS SUPER EFFECTIVE CPU 1 wins!";
      cout << endl;
    } else if (Solution == -1) {
      cout << endl;
      cout << "!ITS SUPER EFFECTIVE CPU 2 wins!";
      cout << endl;
    } else {
      cout << endl;
      cout << "Tie no one wins.";
      cout << endl;
    }
  }
  if (gameMenu == 2) {
    playerMenu = Game.PlayerMenu();
    P1.sethand(playerMenu);

    Game.Displayemoji(P1, CPU1);
    cout << endl;
    Solution = Game.Solution(P1.getCname(), CPU1.getCname());
    if (Solution == 1) {
      cout << endl;
      cout << "!ITS SUPER EFFECTIVE CPU1/PLAYER WINS!";

    } else if (Solution == -1) {
      cout << endl;
      cout << "!ITS SUPER EFFECTIVE CPU 1 wins!";
      cout << endl;

    } else {
      cout << endl;
      cout << "Tie no one wins.";
      cout << endl;
    }
  }

  return 0;
}
