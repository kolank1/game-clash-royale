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
    void showWeapon() override {
        cout << "Current weapon: Sword" << endl;
    }

    void attack() override {
        cout << "Knight attacks with sword!" << endl;
    }
};

class Spear : public Weapon {
public:
    void showWeapon() override {
        cout << "Current weapon: Spear" << endl;
    }

    void attack() override {
        cout << "Knight attacks with spear!" << endl;
    }
};

class Mace : public Weapon {
public:
    void showWeapon() override {
        cout << "Current weapon: Mace" << endl;
    }

    void attack() override {
        cout << "Knight attacks with mace!" << endl;
    }
};

class Bow : public Weapon {
public:
    void showWeapon() override {
        cout << "Current weapon: Bow" << endl;
    }

    void attack() override {
        cout << "Archer attacks with bow!" << endl;
    }
};

class Crossbow : public Weapon {
public:
    void showWeapon() override {
        cout << "Current weapon: Crossbow" << endl;
    }

    void attack() override {
        cout << "Archer attacks with crossbow!" << endl;
    }
};

class Dagger : public Weapon {
public:
    void showWeapon() override {
        cout << "Current weapon: Dagger" << endl;
    }

    void attack() override {
        cout << "Archer attacks with dagger!" << endl;
    }
};

class Fireball : public Weapon {
public:
    void showWeapon() override {
        cout << "Current weapon: Fireball" << endl;
    }

    void attack() override {
        cout << "Wizard casts fireball!" << endl;
    }
};

class Freeze : public Weapon {
public:
    void showWeapon() override {
        cout << "Current weapon: Freeze" << endl;
    }

    void attack() override {
        cout << "Wizard casts freeze!" << endl;
    }
};

class Poison : public Weapon {
public:
    void showWeapon() override {
        cout << "Current weapon: Poison" << endl;
    }

    void attack() override {
        cout << "Wizard casts poison!" << endl;
    }
};

class Character {
protected:
    Weapon* weapon = nullptr;

public:
    void setWeapon(Weapon* newWeapon) {
        weapon = newWeapon;
    }

    void attack() {
        if (weapon != nullptr)
            weapon->attack();
        else
            cout << "Weapon is not selected!" << endl;
    }

    void showCurrentWeapon() {
        if (weapon != nullptr)
            weapon->showWeapon();
        else
            cout << "Weapon is not selected!" << endl;
    }

    virtual void chooseWeapon() = 0;
    virtual void showInfo() = 0;

    virtual ~Character() {}
};

class Knight : public Character {
private:
    Sword sword;
    Spear spear;
    Mace mace;

public:
    void showInfo() override {
        cout << "Current character: Knight" << endl;
    }

    void chooseWeapon() override {
        int choice;

        cout << "1. Sword(damage 20, attack speed 4)" << endl;
        cout << "2. Spear(damage 10, attack speed 2)" << endl;
        cout << "3. Mace(damage 35, attack speed 6)" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            setWeapon(&sword);
        else if (choice == 2)
            setWeapon(&spear);
        else if (choice == 3)
            setWeapon(&mace);
        else
            cout << "Wrong choice!" << endl;
    }
};

class Archer : public Character {
private:
    Bow bow;
    Crossbow crossbow;
    Dagger dagger;

public:
    void showInfo() override {
        cout << "Current character: Archer" << endl;
    }

    void chooseWeapon() override {
        int choice;

        cout << "1. Bow(damage 7, kd 4)" << endl;
        cout << "2. Crossbow(damage 35, kd 10)" << endl;
        cout << "3. Dagger(damage 5, kd 2)" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            setWeapon(&bow);
        else if (choice == 2)
            setWeapon(&crossbow);
        else if (choice == 3)
            setWeapon(&dagger);
        else
            cout << "Wrong choice!" << endl;
    }
};

class Wizard : public Character {
private:
    Fireball fireball;
    Freeze freeze;
    Poison poison;

public:
    void showInfo() override {
        cout << "Current character: Wizard" << endl;
    }

    void chooseWeapon() override {
        int choice;

        cout << "1. Fireball(damage 50, kd 15)" << endl;
        cout << "2. Freeze(damage 20, kd 5)" << endl;
        cout << "3. Poison(damage second 9, kd 10)" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            setWeapon(&fireball);
        else if (choice == 2)
            setWeapon(&freeze);
        else if (choice == 3)
            setWeapon(&poison);
        else
            cout << "Wrong choice!" << endl;
    }
};

int main() {
    Knight knight;
    Archer archer;
    Wizard wizard;

    Character* currentCharacter = nullptr;

    int choice;

    do {
        cout << endl;
        cout << "1. Select character" << endl;
        cout << "2. Select weapon" << endl;
        cout << "3. Attack" << endl;
        cout << "4. Show character" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int characterChoice;

            cout << "1. Knight" << endl;
            cout << "2. Archer" << endl;
            cout << "3. Wizard" << endl;
            cout << "Choice: ";
            cin >> characterChoice;

            if (characterChoice == 1)
                currentCharacter = &knight;
            else if (characterChoice == 2)
                currentCharacter = &archer;
            else if (characterChoice == 3)
                currentCharacter = &wizard;
            else
                cout << "Wrong choice!" << endl;
        }

        else if (choice == 2) {
            if (currentCharacter != nullptr)
                currentCharacter->chooseWeapon();
            else
                cout << "First select a character!" << endl;
        }

        else if (choice == 3) {
            if (currentCharacter != nullptr)
                currentCharacter->attack();
            else
                cout << "Character is not selected!" << endl;
        }

        else if (choice == 4) {
            if (currentCharacter != nullptr) {
                currentCharacter->showInfo();
                currentCharacter->showCurrentWeapon();
            }
            else
                cout << "Character is not selected!" << endl;
        }

    } while (choice != 0);

    return 0;
}