#include <iostream>
#include <vector>

struct Creature;
struct Game
{
    std::vector<Creature *> creatures;
};

struct StatQuery
{
    enum Statistic
    {
        attack,
        defense
    } statistic;

    int result;
};

struct Creature
{
protected:
    Game &game;
    int base_attack;
    int base_defense;
    int attack_buff;
    int defense_buff;

    virtual void upgrade_value(void *creature, StatQuery &stat) = 0;

    void creature_modify(StatQuery &stat)
    {
        for (const auto creature : game.creatures)
        {
            creature->upgrade_value(this, stat);
        }
    }

public:
    Creature(Game &game, int base_attack, int base_defense, int attack_buff, int defense_buff) : game(game),
                                                                                                 base_attack(base_attack),
                                                                                                 base_defense(base_defense), attack_buff(attack_buff), defense_buff(defense_buff) {}
    virtual int get_attack() = 0;
    virtual int get_defense() = 0;
};

class Goblin : public Creature
{
public:
    Goblin(Game &game, int base_attack, int base_defense, int attack_buff, int defense_buff) : Creature(game, base_attack, base_defense, attack_buff, defense_buff) {}

    Goblin(Game &game) : Creature(game, 1, 1, 0, 1) {}

    int get_attack() override
    {
        StatQuery stat{StatQuery::Statistic::attack, base_attack};
        creature_modify(stat);
        return stat.result;
    }

    int get_defense() override
    {
        StatQuery stat{StatQuery::Statistic::defense, base_defense};
        creature_modify(stat);
        return stat.result;
    }

protected:
    void upgrade_value(void *creature, StatQuery &stat) override
    {
        if (this != creature)
        {
            switch (stat.statistic)
            {
            case StatQuery::Statistic::attack:
                stat.result += attack_buff;
                break;
            case StatQuery::Statistic::defense:
                stat.result += defense_buff;
                break;
            default:
                break;
            }
        }
    }
};

class GoblinKing : public Goblin
{
public:
    GoblinKing(Game &game) : Goblin(game, 3, 3, 1, 1) {}
};

void check(bool res)
{
    std::cout << (res ? "OK" : "FAIL") << std::endl;
}

int main()
{
    Game game;
    Goblin goblin(game);
    game.creatures.push_back(&goblin);
    check(1 == goblin.get_attack());
    check(1 == goblin.get_defense());

    Goblin goblin1(game);
    game.creatures.push_back(&goblin1);
    check(1 == goblin.get_attack());
    check(2 == goblin.get_defense());

    GoblinKing king(game);
    game.creatures.push_back(&king);
    check(2 == goblin.get_attack());
    check(3 == goblin.get_defense());
    return 0;
}