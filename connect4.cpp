#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include <random>
#include "connect4.h"


using namespace std;
#define radijus 35



zeton::zeton(std::string str) {
		s.setRadius(float(radijus));
		
		
		if (str == "yellow") {
			
			s.setFillColor(sf::Color::Yellow);
			if (!texture.loadFromFile("yellow.jpg"))
				std::cout << "Greska kod ucitavanja slike"<<endl;

			s.setTexture(&texture);
		}

		if (str == "red") {

			s.setFillColor(sf::Color::Red);
			if (!texture.loadFromFile("red.jpg"))
				std::cout << "Greska kod ucitavanja slike" << endl;

			s.setTexture(&texture);
		}

		s.setOutlineColor(sf::Color(0, 0,247));
		s.setOutlineThickness(-5);

}


bool ploca::pobjednik(ploca &igra){


	for (auto i = 0; i<6; i++)
	{
		for (auto j = 0; j <= 3; j++)
		{
			if (igra.zetoni[i][j] == 1 && igra.zetoni[i][j + 1] == 1
				&& igra.zetoni[i][j + 2] == 1 && igra.zetoni[i][j + 3] == 1)
			{
				cout << "Igrac1 je pobjednik!" << endl;
			
				return true;
			}
			else if (igra.zetoni[i][j] == 2 && igra.zetoni[i][j + 1] == 2
				&& igra.zetoni[i][j + 2] == 2 && igra.zetoni[i][j + 3] == 2)
			{
				cout << "Igrac2 je pobjednik!" << endl;
				
				return true;
			}
		}
	}



	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 6; j >= 3; j--)
		{
			if (igra.zetoni[i][j] == 1 && igra.zetoni[i + 1][j - 1] == 1 &&
				igra.zetoni[i + 2][j - 2] == 1 && igra.zetoni[i + 3][j - 3] == 1)
			{
				cout << "Igrac1 je pobjednik!" << endl;
		
				return true;
			}
			else if (igra.zetoni[i][j] == 2 && igra.zetoni[i + 1][j - 1] == 2
				&& igra.zetoni[i + 2][j - 2] == 2 && igra.zetoni[i + 3][j - 3] == 2)
			{
				cout << "Igrac2 je pobjednik!" << endl;
				
				return true;
			}
		}
	}


	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j < 7; j++)
		{
			if (igra.zetoni[i][j] == 1 && igra.zetoni[i + 1][j] == 1
				&& igra.zetoni[i + 2][j] == 1 && igra.zetoni[i + 3][j] == 1)
			{
				cout << "Igrac1 je pobjednik!" << endl;
			
				return true;
			}
			else if (igra.zetoni[i][j] == 2 && igra.zetoni[i + 1][j] == 2
				&& igra.zetoni[i + 2][j] == 2 && igra.zetoni[i + 3][j] == 2)
			{
				cout << "Igrac2 je pobjednik!" << endl;
				
				return true;
			}
		}
	}



	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j <=3; j++)
		{
			if (igra.zetoni[i][j] == 1 && igra.zetoni[i + 1][j + 1] == 1
				&& igra.zetoni[i + 2][j + 2] == 1 && igra.zetoni[i + 3][j + 3] == 1)
			{
				cout << "Igrac1 je pobjednik!" << endl;
		
				return true;
			}
			else if (igra.zetoni[i][j] == 2 && igra.zetoni[i + 1][j + 1] == 2
				&& igra.zetoni[i + 2][j + 2] == 2 && igra.zetoni[i + 3][j + 3] == 2)
			{
				cout << "Igrac2 je pobjednik!" << endl;
		
				return true;
			}
		}
	}

	return false;

}

void ploca::nacrtaj(int br_igraca, int stupac, zeton & zeton1, zeton& zeton2, ploca& igra) {

	stupac--;
	int i = 0;

	for (i = 5; i >= 0; --i) {

		if (igra.zetoni[i][stupac] == 0) {
			igra.zetoni[i][stupac] = br_igraca;
			break;
		}
	}

	if (br_igraca == 1) {
		float x = (2*stupac + 0.5) * radijus + stupac * 18+3;
		float y = 480 - 2*(radijus+3) * (6 - i)-2;
		
		
	    sf::Vector2f pos (x, y);
		zeton1.s.setPosition(pos);
		
	
	}

	if (br_igraca == 2) {
		float x = (2*stupac + 0.5) * radijus + stupac * 18+3;
		float y = 480 - 2 * (radijus+3) * (6 - i)-2;
	
		sf::Vector2f pos (x, y);
		zeton2.s.setPosition(pos);
	
	}

}



int ploca::racunalo(ploca &igra, zeton& zeton1, zeton& zeton2) {

	int polozaj;
	bool slobodno = false;
	static uniform_int_distribution<unsigned> u(1, 7);
	static default_random_engine e(time(0));

	while (!slobodno) {


		polozaj = u(e);
		if (igra.imaMjesta(polozaj, igra))
			break;
	}

	return polozaj;
}

void ploca::ispis() {

	for (auto i = 0; i < 6; ++i) {
		for (auto j = 0; j < 7; ++j)
		{
			cout << zetoni[i][j] << " ";
		}
		cout << endl;

	}
	cout << endl;

}


bool ploca:: imaMjesta(int stupac, ploca& igra) const {

	if (stupac < 1 || stupac>7)
		return false;

	if (igra.zetoni[0][stupac - 1] == 0)
		return true;

	return false;

}



void ploca::dogadaji(sf::Window& window, sf::Event& event, ploca& igra, zeton& zeton1, zeton& zeton2, int igrac) {

	int polozaj;

	if (event.type == sf::Event::Closed)
		window.close();

	if (event.type == sf::Event::KeyPressed) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			polozaj = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			polozaj = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			polozaj = 3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			polozaj = 4;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			polozaj = 5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
			polozaj = 6;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
			polozaj = 7;


		if (igra.imaMjesta(polozaj, igra)) {
			igra.nacrtaj(igrac, polozaj, zeton1, zeton2, igra);
			if (igrac == 1) {
				brojac1++;
				igra.tmp.push_back(zeton1);
			}

			if (igrac == 2) {
				brojac2++;
				igra.tmp.push_back(zeton2);
			}

			ukupno++;
			
		}


	}


}

