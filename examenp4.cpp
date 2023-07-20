//Critter
#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0, int thirst = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Drink(int water = 4);
    void List();

public:
    int m_Hunger;
    int m_Boredom;
    int m_Thirst;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int thirst) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Thirst(thirst)
{}


void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    m_Thirst += time;
}

void Critter::Talk()
{
    if (m_Hunger >= 5 && m_Hunger < 10)
    {
        cout << "messiento hambriento" << endl;
    }
    if (m_Hunger >= 10 && m_Hunger < 15)
    {
        cout << "alimentame ya, o veras" << endl;
    }
    if (m_Boredom >= 5 && m_Boredom < 10)
    {
        cout << "messiento aburrido" << endl;
    }
    if (m_Boredom >= 10 && m_Boredom < 15)
    {
        cout << "juega conmigo ya, o veras" << endl;
    }
    if (m_Thirst >= 5 && m_Thirst < 10)
    {
        cout << "messiento deshidratado" << endl;
    }
    if (m_Thirst >= 10 && m_Thirst < 15)
    {
        cout << "dame de beber ya, o veras" << endl;
    }
    if (m_Hunger < 5 && m_Boredom < 5 && m_Thirst < 4)
    {
        cout << "Estoy muy feliz" << endl;
    }

    {

    }

    PassTime();
}

void Critter::Eat(int food)
{
    cout << "\nBrrupp. \n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "\nWheee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

void Critter::Drink(int water)
{
    cout << "\nGlup glup\n";
    m_Thirst -= water;
    if (m_Thirst < 0)
    {
        m_Thirst = 0;
    }
    PassTime();
}

void Critter::List()
{
    cout << "--Lista de necesidades--" << endl;
    cout << "hunger: " << m_Hunger << endl;
    cout << "boredom: " << m_Boredom << endl;
    cout << "thirst: " << m_Thirst << endl;
}

int main()
{
    

    Critter crit;
    crit.Talk();
    int choice;
    bool vida = true;
    do
    {
        cout << "\n Mascotas Virtuales\n\n";

        

        cout << "0 - Salir.\n";

        cout << "1 - Escucha a tu mascota.\n";
        cout << "2 - Alimentar.\n";
        cout << "3 - Jugar con tu mascota.\n";
        cout << "4 - Dale de beber a tu mascota.\n";
        cout << "5 - Lista de necesidades. \n";

        cout << "Elige una opción: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.Drink();
            break;
        case 5:
            crit.List();
            break;
        default:
            cout << "\n Tu elección es inválida. \n";
        }

        if (crit.m_Hunger >= 15 || crit.m_Boredom >= 15 || crit.m_Thirst >= 15)
        {
            cout << "ME HAS MATADAO (X o X), VOLVERÉ POR VENGANZA" << endl;
            break;
        }
    } while (choice != 0 || vida);
}