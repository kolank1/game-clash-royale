#include <iostream>
using namespace std;

class Weapon {
public:
    virtual void attack() = 0;
    virtual void showWeapon() = 0;

    virtual ~Weapon() {}
};
class Sword : public Weapon {
public:
    void attack() override {
        cout << "Knight attacks with sword!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Sword" << endl;
    }
};

class Spear : public Weapon {
public:
    void attack() override {
        cout << "Knight attacks with spear!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Spear" << endl;
    }
};

class Mace : public Weapon {
public:
    void attack() override {
        cout << "Knight attacks with mace!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Mace" << endl;
    }
};

class Bow : public Weapon {
public:
    void attack() override {
        cout << "Archer attacks with bow!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Bow" << endl;
    }
};

class Crossbow : public Weapon {
public:
    void attack() override {
        cout << "Archer attacks with crossbow!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Crossbow" << endl;
    }
};

class Dagger : public Weapon {
public:
    void attack() override {
        cout << "Archer attacks with dagger!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Dagger" << endl;
    }
};

class Fireball : public Weapon {
public:
    void attack() override {
        cout << "Wizard casts fireball!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Fireball" << endl;
    }
};

class Freeze : public Weapon {
public:
    void attack() override {
        cout << "Wizard casts freeze!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Freeze" << endl;
    }
};

class Poison : public Weapon {
public:
    void attack() override {
        cout << "Wizard casts poison!" << endl;
    }

    void showWeapon() override {
        cout << "Weapon: Poison" << endl;
    }
};
int main() {
    cout << "Strategy Pattern Game" << endl;

    return 0;
}

