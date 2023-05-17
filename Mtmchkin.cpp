#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
    m_player(playerName)
{
    m_cards = new Card[numOfCards];
    m_cardsSize = numOfCards;
    m_cardsCurr = 0;
    m_gameStatus = GameStatus::MidGame;

    for(int i = 0; i < numOfCards; i++)
    {
        m_cards[i] = cardsArray[i];
    }
}

void Mtmchkin::playNextCard()
{
    Card& card = m_cards[m_cardsCurr];

    //prints card info
    card.printInfo();

    //player encounters card
    card.applyEncounter(m_player);
    m_cardsCurr++;
    m_cardsCurr = m_cardsCurr % m_cardsSize;

    //prints the player info
    m_player.printInfo();
}

bool Mtmchkin::isOver() const
{
    return GameStatus::MidGame != m_gameStatus;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards;
}
