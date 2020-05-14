// Card dealing program
//#include <iostream.h>
//#include <iomanip.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

void shuffle(int [][13]);
void deal(const int [][13], const char *[], const char *[]);

int main()
{
    const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[13] ={"Ace", "Deuce", "Three", "Four",
                     "FIve", "Six", "Seven", "Eight",
                     "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[4][13] = {0};

    srand(time(NULL));

    shuffle(deck);
    deal(deck, face, suit);

    return 0;
}

void shuffle(int wDeck[][13])
{
    int row, column;

    for (int card = 1; card <= 52; card++){
        row = rand() % 4;
        column = rand() % 13;

        while (wDeck[row][column] != 0){
            row =rand() % 4;
            column = rand() % 13;
        }

        wDeck[row][column] = card;
    }
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]){
    
    for (int card = 1; card <= 52; card++){
        for (int row = 0; row<= 3; row++){
            for (int column = 0; column <=12; column++){
                if(wDeck[row][column] == card)
                    cout << setw(5) << setiosflags(ios::right)
                        << wFace[column]<< " of "
                        << setw(8) << setiosflags(ios::left)
                        << wSuit[row] << (card % 2 == 0 ? '\n' :'\t');

            }
        }
    }
}