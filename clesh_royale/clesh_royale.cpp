#include <iostream>
using namespace std;

class Weapon {
public:
    virtual void attack() = 0;
    virtual void showWeapon() = 0;

    virtual ~Weapon() {}
};

int main() {
    cout << "Strategy Pattern Game" << endl;

    return 0;
}
