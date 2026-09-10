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

        cout << "1. Sword" << endl;
        cout << "2. Spear" << endl;
        cout << "3. Mace" << endl;
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

        cout << "1. Bow" << endl;
        cout << "2. Crossbow" << endl;
        cout << "3. Dagger" << endl;
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

        cout << "1. Fireball" << endl;
        cout << "2. Freeze" << endl;
        cout << "3. Poison" << endl;
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
        cout << "===== GAME MENU =====" << endl;
        cout << "1. Select character" << endl;
        cout << "2. Select weapon" << endl;
        cout << "3. Attack" << endl;
        cout << "4. Show character and weapon" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int characterChoice;

            cout << endl;
            cout << "1. Knight" << endl;
            cout << "2. Archer" << endl;
            cout << "3. Wizard" << endl;
            cout << "Choice: ";
            cin >> characterChoice;

            if (characterChoice == 1) {
                currentCharacter = &knight;
                cout << "Knight selected!" << endl;
            }
            else if (characterChoice == 2) {
                currentCharacter = &archer;
                cout << "Archer selected!" << endl;
            }
            else if (characterChoice == 3) {
                currentCharacter = &wizard;
                cout << "Wizard selected!" << endl;
            }
            else {
                cout << "Wrong choice!" << endl;
            }
        }

        else if (choice == 2) {
            if (currentCharacter != nullptr) {
                currentCharacter->chooseWeapon();
            }
            else {
                cout << "First select a character!" << endl;
            }
        }

        else if (choice == 3) {
            if (currentCharacter != nullptr) {
                currentCharacter->attack();
            }
            else {
                cout << "Character is not selected!" << endl;
            }
        }

        else if (choice == 4) {
            if (currentCharacter != nullptr) {
                currentCharacter->showInfo();
                currentCharacter->showCurrentWeapon();
            }
            else {
                cout << "Character is not selected!" << endl;
            }
        }

        else if (choice != 0) {
            cout << "Wrong choice!" << endl;
        }

    } while (choice != 0);

    cout << "Game closed." << endl;

    return 0;
}