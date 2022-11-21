
/*****************************************************************************
*                    
*  Author:          Ricardo Rios
*  Email:           RicardoCesarRios14@outlook.com
*  Label:           P03B
*  Title:           Bolniverse Fight club
*  Course:          2143 OOP
*  Semester:        Fall 2022
* 
*  Description:
*       By way of dynamic polymorphism this program creates a fighter character
by way of reading in a list of characters from an input file and placing thoses 
characters into a vector then to a character pointer that points to a base class
and assigns random attributes withing certain parameters to said character such
as "1.d.4" or "1.d.6" damage for a warrior class, and that makes the attackers.
the defenders are generated at a ratio of 1 for every 100 attackers, but have 
the ability to regen HP. The two sides battle and the winner is decided by which
side still has characters within their vector "One could say to the last man standing".
* 
*  Usage:
*       Insert a file with a list of attackers 
* 
*  Files:           
main.cpp
dice.hpp
fighter.hpp
helpers.hpp
weapon.hpp

*****************************************************************************/


#include "dice.hpp"
#include "fighter.hpp"
#include "helpers.hpp"
#include "weapon.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <thread>

int main() {
  ifstream infile;
  ofstream outfile;
  infile.open("attackers.txt");
  outfile.open("results.txt");
  int attackersCount = 0, deffenderscount = 0;
  // taking count of character in order to keep track of how
  // many of said char to make 
  int WarriorCount = 0;
  int WizardCount = 0;
  int ArcherCount = 0;
  int ElfCount = 0;
  int DragonbornCount = 0;
//while the file is not ended infile character names and add to characters counts
// character counts determine how many instances of each char to create
  while (!infile.eof()) {
    string fighterType;
    infile >> fighterType;

    if (fighterType == "warrior") {
      WarriorCount++;
    } else if (fighterType == "wizard") {
      WizardCount++;
    } else if (fighterType == "archer") {
      ArcherCount++;
    } else if (fighterType == "elf") {
      ElfCount++;
    } else {
      DragonbornCount++;
    }
  }
  srand(time(0));
  // Attackers and Defender vectors
  vector<BaseFighter *> Attackers;
  vector<BaseFighter *> Defenders;

  BaseFighter *CurAttacker;
  BaseFighter *CurDefender;
//pushing instances of characters based on their counts
  for (int i = 0; i < WarriorCount; i++) {
    Attackers.push_back(new Warrior("attacker"));
  }

  for (int i = 0; i < WizardCount; i++) {
    Attackers.push_back(new Wizard("attacker"));
  }

  for (int i = 0; i < ArcherCount; i++) {
    Attackers.push_back(new Archer("attacker"));
  }
  for (int i = 0; i < ElfCount; i++) {
    Attackers.push_back(new Elf("attacker"));
  }

  for (int i = 0; i < DragonbornCount; i++) {
    Attackers.push_back(new DragonBorn("attacker"));
  }
// pushing defenders based on the counts of their respective 
// character into the defender vector
    for (int i = 0; i < Attackers.size() / 10; i++) {
    Defenders.push_back(new Warrior("defender"));
    Defenders.push_back(new Wizard("defender"));
    Defenders.push_back(new Archer("defender"));
    Defenders.push_back(new Elf("defender"));
    Defenders.push_back(new DragonBorn("defender"));
      } 
  //attack loop
  while (Attackers.size() && Defenders.size()) {
    for (int i = 0; i < Defenders.size(); i++) {
      Defenders[i]->regen();
    }
    CurAttacker = Attackers.back();
    CurDefender = Defenders.back();

       while (CurAttacker->alive() && CurDefender->alive()) {
      this_thread::sleep_for(chrono::milliseconds(1));
      system("clear");
      cout << "Defenders v Attackers\n";
      cout << Defenders.size() << " v " << Attackers.size() << endl;
      CurAttacker->attack(CurDefender);
      CurDefender->attack(CurAttacker);
    }
    if (!Attackers.back()->alive()) {
      Attackers.pop_back();
    }
    if (!Defenders.back()->alive()) {
      Defenders.pop_back();
    }
    if (!Attackers.back()->alive()) {
      Attackers.pop_back();
    }
    if (!Defenders.back()->alive()) {
      Defenders.pop_back();
    }
  }
    //
  if (Attackers.size() == 0) {
    cout << "Defenders won!" << endl; 
    }
   else {
    cout << "Attackers won!" << endl;
  }
   outfile << "Defenders alive: " << Defenders.size() << endl;
  outfile << "Attackers alive: " << Attackers.size() << endl;
   outfile.close();
  
  }
