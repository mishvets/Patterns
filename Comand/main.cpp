#include <iostream>

struct Command
{
    enum Action
    {
        deposit,
        withdraw
    } action;
    int amount{0};
    bool success{false};
};

struct Account
{
    int balance{0};

    void process(Command &cmd)
    {
        switch (cmd.action)
        {
        case Command::Action::deposit:
        {
            balance += cmd.amount;
            cmd.success = true;
            break;
        }
        case Command::Action::withdraw:
        {
            if (balance < cmd.amount)
            {
                cmd.success = false;
                break;
            }
            balance -= cmd.amount;
            cmd.success = true;
            break;
        }

        default:
            break;
        }
    }
};

void check(bool res)
{
    std::cout << (res ? "OK" : "FAIL") << std::endl;
}

int main()
{

    return 0;
}