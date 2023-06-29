#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#define radijus 37

class zeton;
class ploca;

class ploca {

	friend class zeton;
    public:

	int zetoni[6][7] = { {0,0,0,0,0,0,0},{0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0},{0,0,0,0,0,0,0} };

	std::vector<zeton> tmp;
	int brojac1, brojac2, ukupno;

	void nacrtaj(int, int, zeton&, zeton&, ploca&);

	bool pobjednik(ploca&);

	int racunalo(ploca&, zeton&, zeton&);
	bool imaMjesta(int,ploca&) const;

	void ispis();

	void dogadaji(sf::Window&, sf::Event&, ploca&, zeton&, zeton&, int);

};



class zeton {

	friend class ploca;
    public:
    sf::CircleShape s;
	zeton() = default;
	zeton(std::string);
	sf::Texture texture;
	
};


