
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "connect4.h"


using namespace std;

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Connect4");
    window.clear(sf::Color(3, 57, 107));
    ploca igra;
    string string1 = "yellow";
    string string2 = "red";

    zeton zeton1(string1);
    zeton zeton2(string2);

    sf::Image image;
    if (!(image.loadFromFile("board.png")))  
        std::cout << "Greska kod ucitavanja slike";   

    sf::Texture texture;                               
    texture.loadFromImage(image);  

    sf::Sprite sprite;
    sprite.setTexture(texture); 

    cout << "Upisite 1 ako zelite igru covjek/racunalo"<<endl;

    cout << "Upisite 2 ako zelite igru covjek/covjek"<<endl;

    size_t nacin_igre;

    cin >> nacin_igre;
    igra.ukupno = 0;
    igra.brojac1 = 0;
    igra.brojac2 = 0;
  


    while (window.isOpen())
    {
        bool rezultat = false;
        sf::Event event;
  
        int polozaj = 1;

        while (window.pollEvent(event))
        {
            if(igra.ukupno%2==0 && nacin_igre==1)
                igra.dogadaji(window, event, igra, zeton1, zeton2, 1);

            if (igra.ukupno % 2 == 1 && igra.brojac2<21 &&nacin_igre==1) {

                polozaj = igra.racunalo(igra, zeton1, zeton2);
   
                igra.nacrtaj(2, polozaj, zeton1, zeton2, igra);

                igra.tmp.push_back(zeton2);

                igra.brojac2++;
                igra.ukupno++;
            }

            
            if (igra.ukupno % 2 == 0 && nacin_igre == 2) {
                igra.dogadaji(window, event, igra, zeton1, zeton2, 1);
                break;
            }

            if (igra.ukupno % 2 == 1 && igra.brojac2 < 21 && nacin_igre == 2) {

                igra.dogadaji(window, event, igra, zeton1, zeton2, 2);
            }
        }


         rezultat = igra.pobjednik(igra);
         if (rezultat) {
             window.close();
             break;

         }

         if (igra.brojac1 == 21 || igra.brojac2 == 21) {
             cout << "Iskoristeni su svi zetoni, nitko nije pobijedio." << endl;
             window.close();
          }


        window.clear(sf::Color(3, 57, 107));
        window.draw(sprite);
    

        for (const auto& zeton : igra.tmp) {
            window.draw(zeton.s);
        }

        window.display();
     
    }

    return 0;
}