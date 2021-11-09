#include <iostream>
#include <string>
#include <vector>

/////exercise 1

template <class T>
class Pair1 {
    T n1;
    T n2;
public:
    Pair1( T _n1,  T _n2) {
        this->n1 = _n1;
        this->n2 = _n2;
    }
    T first() const {
        return n1;
    }
    T second() const {
        return n2;
    }
};

////////

///// exercise 2

template <typename T, typename S>
class Pair {
protected:
    T n1;
    S n2;
public:
    Pair(T _n1, S _n2) {
        this->n1 = _n1;
        this->n2 = _n2;
    }
    T first() const {
        return n1;
    }
    S second() const {
        return n2;
    }
};

///////

///// exercise 3 
// не смог решить эту задачу т.к. никак не получается создать класс таким образом (тут написано именно так как в методичке), 
//долго искал решение проблемы но так и не получилось, 
//может проблема в VS?
//оставил эту часть чтобы было понятно в чём именно проблема
//если не трудно можете объяснить данную проблему на вебинаре

/*
template <typename S>
class StringValuePair<std::string, S> : public Pair<std::string, S>
{

};
*/

//////

////// exercise 4

enum ECardSuit { SPADES, CLUBS, DIAMONDS, HEARTS };
enum ECardValue {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 10,
    QUEEN = 10,
    KING = 10
};
class Card {
    ECardSuit suit;
    ECardValue value;
    bool isCoverUp;
public:
    Card(ECardSuit _suit, ECardValue _value) : suit(_suit), value(_value) {
        isCoverUp = true;
    }

    void flip() {
        isCoverUp = !isCoverUp;
    }
    ECardValue getValue() const {
        return value;
    }
};

class Hand {
protected:
    int sum;
    std::vector<Card*> m_Cards;
public:
    void Add(Card* pCard) {
        m_Cards.push_back(pCard);
    }
    void Clear() {
        m_Cards.clear();
    }
    int GetTotal() {
        int  ace = 0;
        if (m_Cards.empty())
        {
            return 0;
        }
        for (size_t i = 0; i < m_Cards.size(); i++)
        {
            sum += m_Cards[i]->getValue();
        }
        for (size_t i = 0; i < m_Cards.size(); i++)
        {
            if (m_Cards[i]->getValue() == ACE)
            {
                ace++;
            }
        }
        while (ace > 0 && sum <= 11)
        {
            sum += 10;
            ace--;
        }
        return sum;
    }
};

/////// ------------- //////
class GenericPlayer : public Hand {
protected:
    std::string m_Name;
    int total = GetTotal();
public:
    virtual bool IsHitting() const = 0;
    bool IsBoosted() const {
        if (total > 21)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Bust() const {
        if (IsBoosted() == true)
        {
            std::cout << m_Name << ": Too Much!" << std::endl;
        }
    }
};
////// ------------- /////////

class Player : public GenericPlayer {
public:
    virtual bool IsHitting() const {
        if (total < 17)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Win() const {
        std::cout << "Player Won!" << std::endl;
    }
    void Lose() const {
        std::cout << "Player Lose!" << std::endl;
    }
    void Push() const {
        std::cout << "A zero-sum game!" << std::endl;
    }
};

class House : public GenericPlayer {
public:
    virtual bool IsHitting() const override {
        if (total < 17)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void FlipFirstCard() {
        m_Cards[0]->flip();
    }
};

class Deck : public Hand {
public:
    void Populate() { }
    void Shuffle() { }
    void Deal(Hand& aHand) { }
    void AddltionalCards(GenericPlayer& aGenericPlayer) { }
};

class Game {
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
public:
    void Play() {}
};

//////

int main()
{
    ////// exercise 1

    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << std::endl;

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << std::endl;
    
    ///////

    ////// exercise 2

    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << std::endl;

    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << std::endl;

    ///////

    ///// exercise 3

    /*StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';*/

    ///////

    //// exerice 4

    /////

    system("pause");
    return 0;
}
