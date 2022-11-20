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

  int WarriorCount = 0;
  int WizardCount = 0;
  int ArcherCount = 0;
  int ElfCount = 0;
  int DragonbornCount = 0;

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
  }
