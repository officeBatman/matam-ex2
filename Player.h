#ifndef EX2_Player_H
#define EX2_Player_H

#include <string>
#include "utilities.h"

const int MAX_LEVEL = 10;
const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;

class Player {
public:
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHP - The max HP of the player.
     * @param force - The initial points of force of the player.
     * @return
     *      A new instance of Player.
    */
    Player(const std::string& name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /*
     * Prints the info of the Player class
     * uses the utilities.h file to print the info
    */
    void printInfo() const;

    /*
     * Level up the player
     * if the player is already at the max level(10), do nothing
    */
    void levelUp();

    /*
     * Gets the level of the player
    */
    int getLevel() const;

    /*
     * Increase the force of the player by the given amount
    */
    void buff(int amount);

    /*
     * Heals the player by the given amount
     * if the player is already at max HP, do nothing
    */
    void heal(int amount);

    /*
     * Damage the player by the given amount
     * if the amount is smaller than 0, do nothing
     * if the amount is bigger than the HP of the player, the HP will be 0
    */
    void damage(int amount);

    /*
     * Returns true if the player has 0 HP
     * false otherwise
    */
    bool isKnockedOut() const;

    /*
     * Adds the given amount of coins to the player
    */
    void addCoins(int amount);

    /*
     * Returns true if the player has enough coins to pay the given price,
     * and removes the price from the player's coins
     * If the player doesn't have enough coins, do nothing and return false
    */
    bool pay(int cost);

    /*
     * Returns the attack strength of the player
    */
    int getAttackStrength() const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;


private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

};


#endif //EX2_Player_H