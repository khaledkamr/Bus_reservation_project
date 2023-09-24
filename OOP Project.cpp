#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;

class b
{
    char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

    void install(); //data about the bus
    void allotment(); //to reserve your seat
    void Empty();
    void show(); //data about specific bus
    void avail();
    void position(int i); //count the seats
}

bus[10];

class b_vip : public b
{
};

void vline(char ch)
{
    for (int i = 80; i > 0; i--)
    {
        cout << ch;
    }
}

void b::install()
{
    cout << "Enter bus no: ";
    cin >> bus[p].busn;

    cout << "\nEnter Driver's name: ";
    cin >> bus[p].driver;

    cout << "\nArrival time: ";
    cin >> bus[p].arrival;

    cout << "\nDeparture: ";
    cin >> bus[p].depart;

    cout << "\nFrom: \t\t\t";
    cin >> bus[p].from;

    cout << "\nTo: \t\t\t";
    cin >> bus[p].to;

    bus[p].Empty();

    p++;
}

void b::allotment()
{
    int seat;
    char number[5];

top:
    cout << "Bus no: ";
    cin >> number;
    int n;

    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
        {
            break;
        }
    }

    while (n <= p)
    {
        cout << "\nSeat Number: ";
        cin >> seat;

        if (seat > 32)
        {
            cout << "\nThere are only 32 seats available in this bus.";
        }
        else
        {
            if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0)
            {
                cout << "Enter passanger's name: ";
                cin >> bus[n].seat[seat / 4][(seat % 4) - 1];
                break;
            }
            else cout << "The seat no. is already reserved.\n";
        }
    }

    if (n > p)
    {
        cout << "Enter correct bus no.\n";
        goto top;
    }
}

void b::Empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}

void b::show()
{
    int n;
    char number[5];
    cout << "Enter bus no: ";
    cin >> number;

    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
        {
            break;
        }
    }

    while (n <= p)
    {
        vline('*');

        cout << "Bus no: \t" << bus[n].busn
            << "\nDriver: \t" << bus[n].driver
            << "\t\tArrival time: \t" << bus[n].arrival
            << "\tDeparture time:" << bus[n].depart
            << "\nFrom: \t\t" << bus[n].from
            << "\t\tTo: \t\t" << bus[n].to << "\n";

        vline('*');
        bus[0].position(n);
        int a = 1;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;

                if (strcmp(bus[n].seat[i][j], "Empty") != 0)
                {
                    cout << "\nThe seat no " << (a - 1) << " is reserved for " << bus[n].seat[i][j] << ".";
                }
            }
        }
        break;
    }
    if (n > p) cout << "Enter correct bus no: ";
}

void b::position(int l)
{

    int s = 0; p = 0;

    for (int i = 0; i < 8; i++)
    {
        cout << "\n";

        for (int j = 0; j < 4; j++)
        {
            s++;

            if (strcmp(bus[l].seat[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];

                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
            }
        }
    }
    cout << "\n\nThere are " << p << " seats empty in Bus No: " << bus[l].busn;
}

void b::avail()
{
    for (int n = 0; n < p; n++)
    {
        vline('*');

        cout << "Bus no: \t" << bus[n].busn << "\nDriver: \t" << bus[n].driver
            << "\t\tArrival time: \t" << bus[n].arrival << "\tDeparture Time: \t"
            << bus[n].depart << "\nFrom: \t\t" << bus[n].from << "\t\tTo: \t\t\t"
            << bus[n].to << "\n";

        vline('*');
        vline('_');
    }
}

int main()
{
    system("cls");
    int w;

top:
    cout << "\n\n\n";
    cout << "\t\t **welcome to bus reservation project** \n\n\n";
    cout << "\t would you like a bus or vip bus ? \n\n";
    cout << "\t 1) bus \t\t 2) vip bus \t\t 3) otherwise(stuff only) \n";
    cout << "\n\t Enter your choice:-> ";

    int n;
    cin >> n;

    switch (n)
    {
    case 1:
        while (1)
        {
            cout << "\n\n\t 1.Reservation\n\t"
                << " 2.Show\n\t"
                << " 3.Buses Available. \n\t"
                << " 4.Exit \n\t"
                << " 5.go to the main menu";
            cout << "\n\n\tEnter your choice:-> ";

            cin >> w;

            switch (w)
            {
            case 1:  bus[p].allotment();
                cout << "Price : 50$" << endl;
                break;

            case 2:  bus[0].show();
                break;

            case 3:  bus[0].avail();
                break;

            case 4:  exit(0);
                break;

            case 5: goto top;
            }
        }

    case 2:
        while (1)
        {
            cout << "\n\n\t 1.Reservation\n\t"
                << " 2.Show\n\t"
                << " 3.Buses Available. \n\t"
                << " 4.Exit \n\t"
                << " 5.go to the main menu";
            cout << "\n\n\tEnter your choice:-> ";

            cin >> w;

            switch (w)
            {
            case 1:  bus[p].allotment();
                cout << "Price: 100$" << endl;
                break;

            case 2:  bus[0].show();
                break;

            case 3:  bus[0].avail();
                break;

            case 4:  exit(0);
                break;

            case 5: goto top;
            }
        }

    case 3:
        while (1)
        {
            cout << "\n\n\t 1) install \t\t 2) go back to the main menu "
                << "\n\n\t Enter your choice:-> ";

            int x;
            cin >> x;

            switch (x)
            {
            case 1: bus[p].install();
                break;

            case 2: goto top;
            }
        }
    }
    return 0;
}