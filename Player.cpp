#include "Player.h"

Player::Player(const std::string& name, int maxHP, int force)
{
    m_name = name;
    m_level = 1;
    m_force = force < 0 ? DEFAULT_FORCE : force;
    m_maxHP = maxHP <= 0 ? DEFAULT_MAX_HP : maxHP;
    m_HP = m_maxHP;
    m_coins = 0;
}

void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if (m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int amount)
{
    if (amount > 0)
    {
        m_force += amount;
    }
}

void Player::heal(int amount)
{
    if (amount > 0)
    {
        m_HP += amount;
        if (m_HP > m_maxHP)
        {
            m_HP = m_maxHP;
        }
    }
}

void Player::damage(int amount)
{
    if (amount > 0)
    {
        m_HP -= amount;
        if (m_HP < 0)
        {
            m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    return m_HP == 0;
}

void Player::addCoins(int amount)
{
    if (amount > 0)
    {
        m_coins += amount;
    }
}

bool Player::pay(int cost)
{
    if (cost < 0) {
        return true;
    }
    if (m_coins >= cost) {
        m_coins -= cost;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}
