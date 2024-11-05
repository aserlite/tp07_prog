#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::vector;

struct Pokemon {
    string name;
    int hp;
    int attack;
    int speed;
    int max_hp; //stockage des pv initiaux pour pouvoir reset apres un combat
};

struct Trainer {
    string name;
    vector<Pokemon> pokemons;
};

void combatTour(Pokemon &attacker, Pokemon &defender) {
    if (attacker.hp > 0) {
        cout << attacker.name << " attacks " << defender.name << " for " << attacker.attack << " damage!" << endl;
        defender.hp -= attacker.attack;
        if (defender.hp < 0) defender.hp = 0;
        cout << defender.name << " has " << defender.hp << " HP left." << endl;
    }
}

void combat(Pokemon &pokemon1, Pokemon &pokemon2) {
    while (pokemon1.hp > 0 && pokemon2.hp > 0) {
        if (pokemon1.speed > pokemon2.speed) {
            combatTour(pokemon1, pokemon2);
            if (pokemon2.hp > 0) {
                combatTour(pokemon2, pokemon1);
            }
        } else if (pokemon2.speed > pokemon1.speed) {
            combatTour(pokemon2, pokemon1);
            if (pokemon1.hp > 0) {
                combatTour(pokemon1, pokemon2);
            }
        } else {
            if (rand() % 2 == 0) {
                combatTour(pokemon1, pokemon2);
                if (pokemon2.hp > 0) {
                    combatTour(pokemon2, pokemon1);
                }
            } else {
                combatTour(pokemon2, pokemon1);
                if (pokemon1.hp > 0) {
                    combatTour(pokemon1, pokemon2);
                }
            }
        }
    }

    if (pokemon1.hp > 0) {
        cout << pokemon1.name << " wins!" << endl;
    } else {
        cout << pokemon2.name << " wins!" << endl;
    }
}

void combatDresseurs(Trainer &trainer1, Trainer &trainer2) {
    size_t i = 0, j = 0;
    while (i < trainer1.pokemons.size() && j < trainer2.pokemons.size()) {
        cout << "Combat entre " << trainer1.pokemons[i].name << " de " << trainer1.name << " et " << trainer2.pokemons[j].name << " de " << trainer2.name << "!" << endl;
        combat(trainer1.pokemons[i], trainer2.pokemons[j]);
        if (trainer1.pokemons[i].hp > 0) {
            ++j; 
        } else {
            ++i;
        }
    }

    if (i < trainer1.pokemons.size()) {
        cout << trainer1.name << " wins the battle!" << endl;
    } else {
        cout << trainer2.name << " wins the battle!" << endl;
    }
}

void resetPokemons(vector<Pokemon> &pokemons) {
    for (auto &pokemon : pokemons) {
        pokemon.hp = pokemon.max_hp;
    }
}

int main() {
    srand(time(0));
    
    Pokemon pikachu = {"Pikachu", 60, 55, 90, 70};
    Pokemon bulbasaur = {"Bulbasaur", 80, 60, 45, 170};
    Pokemon charizard = {"Charizard", 180, 70, 70, 180};
    Pokemon mewtwo = {"Mewtwo", 140, 80, 110, 140};
    Pokemon eevee = {"Eevee", 80, 30, 80, 80};

    Trainer sacha = {"Sacha", {pikachu, charizard, eevee}};
    Trainer red = {"Red", {mewtwo, bulbasaur}};

    combatDresseurs(red,sacha);

    resetPokemons(sacha.pokemons);
    resetPokemons(red.pokemons);

    return 0;
}