
#include<iostream>
#include<cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Klasy.h"
#include <windows.h>
#include <winbase.h>
#include <future>
#include <thread>
#include <stdio.h>
#include <chrono>
#include <ctime>
#include <filesystem>
#include<string>
#include<regex>

import Zadaniowe;
import Teksty;

using namespace sf;
using namespace std;
namespace fs = filesystem;

int rozgrywka(Gracz<Ogolne_punkty_z_gry>& przenoszenie)
{
    instrukcja();

    int  zycie = 3;
    int punkty = 0;
    int n=0;
    // create the window
    RenderWindow window(VideoMode(900, 880), "Gra Pacman - Pagenta", Style::Default);

    window.setFramerateLimit(120.f);

    float dt;
    Clock dt_clock;


    RectangleShape box1;
    box1.setPosition(30, 370);
    box1.setSize(Vector2f(550, 20));
    box1.setFillColor(Color::Transparent);

    RectangleShape box11;
    box11.setPosition(580, 550);
    box11.setSize(Vector2f(550, 20));
    box11.setFillColor(Color::Transparent);

    RectangleShape box111;
    box111.setPosition(880, 10);
    box111.setSize(Vector2f(50, 500));
    box111.setFillColor(Color::Transparent);

    RectangleShape box1111;
    box1111.setPosition(80, 1);
    box1111.setSize(Vector2f(900, 30));
    box1111.setFillColor(Color::Transparent);

    const float szerokosc = 60.f;

    CircleShape player(szerokosc / 2);
    player.setFillColor(Color::Magenta);
    player.setPosition(720, 550);

    CircleShape points(10);
    points.setFillColor(Color(139, 0, 139));
    points.setPosition(300, 500);
    CircleShape points1(10);
    points1.setFillColor(Color(139, 0, 139));
    points1.setPosition(50, 50);
    CircleShape points2(10);
    points2.setFillColor(Color(139, 0, 139));
    points2.setPosition(600, 200);
    CircleShape points3(10);
    points3.setFillColor(Color(139, 0, 139));
    points3.setPosition(350, 50);
    CircleShape points4(10);
    points4.setFillColor(Color(139, 0, 139));
    points4.setPosition(400, 800);
    CircleShape points5(10);
    points5.setFillColor(Color(139, 0, 139));
    points5.setPosition(250, 400);
    CircleShape points6(10);
    points6.setFillColor(Color(139, 0, 139));
    points6.setPosition(50, 400);
    CircleShape points7(10);
    points7.setFillColor(Color(139, 0, 139));
    points7.setPosition(850, 50);
    CircleShape points8(10);
    points8.setFillColor(Color(139, 0, 139));
    points8.setPosition(830, 820);
    CircleShape points9(10);
    points9.setFillColor(Color(139, 0, 139));
    points9.setPosition(500, 430);

    //sciany
    std::vector<RectangleShape> walls;



    CircleShape duch(szerokosc / 2, 3);
    duch.setFillColor(Color(194, 53, 107));
    duch.setPosition(0, 15);

    CircleShape uch(szerokosc / 2, 3);
    uch.setFillColor(Color(194, 53, 107));
    uch.setPosition(220, 500);

    FloatRect nextPos;

    FloatRect nastepnapoz;
    float predkosc = 100.f;
    Vector2f ustawienie;
    Vector2f velocity;


    float bok, dol;
    bok = 200;
    dol = 150;
    RectangleShape b;
    b.setSize(Vector2f(100, 100));
    b.setPosition(bok, dol);



    //RectangleShape object; ///
    //object.setSize(sf::Vector2f(30, 700));
    //object.setFillColor(sf::Color::White);
    //object.setPosition(80, 80);

    //RectangleShape object1; ///
    //object1.setSize(sf::Vector2f(30, 300));
    //object1.setFillColor(sf::Color::White);
    //object1.setPosition(740, 80);

    //RectangleShape object11;
    //object11.setSize(sf::Vector2f(30, 300));
    //object11.setFillColor(sf::Color::White);
    //object11.setPosition(740, 490);

    //RectangleShape srodek1;
    //srodek1.setSize(sf::Vector2f(80, 20));
    //srodek1.setFillColor(sf::Color::White);
    //srodek1.setPosition(320, 350);

    //RectangleShape srodek11;
    //srodek11.setSize(sf::Vector2f(80, 20));
    //srodek11.setFillColor(sf::Color::White);
    //srodek11.setPosition(500, 350);

    //RectangleShape srodek111;
    //srodek111.setSize(sf::Vector2f(260, 20));
    //srodek111.setFillColor(sf::Color::White);
    //srodek111.setPosition(320, 520);

    //RectangleShape srodek1111;
    //srodek1111.setSize(sf::Vector2f(20, 180));
    //srodek1111.setFillColor(sf::Color::White);
    //srodek1111.setPosition(320, 350);

    //RectangleShape srodek11111;
    //srodek11111.setSize(sf::Vector2f(20, 180));
    //srodek11111.setFillColor(sf::Color::White);
    //srodek11111.setPosition(560, 350);


    RectangleShape portal;
    portal.setPosition(720, 600);
    portal.setRotation(180);
    portal.setFillColor(Color::Transparent);
    portal.setSize(Vector2f(70, 70));

    RectangleShape kk;
    kk.setSize(sf::Vector2f(350, 100));
    kk.setFillColor(sf::Color::White);
    kk.setPosition(450, 100);

    RectangleShape s;
    s.setSize(sf::Vector2f(100, 350));
    s.setFillColor(sf::Color::White);
    s.setPosition(700, 100);

    RectangleShape wall;
    wall.setSize(Vector2f(500, 100));
    wall.setFillColor(sf::Color::White);
    wall.setPosition(300, 700);

    RectangleShape ff;
    ff.setSize(sf::Vector2f(100, 400));
    ff.setFillColor(sf::Color::White);
    ff.setPosition(100, 400);

    RectangleShape cc;
    cc.setSize(sf::Vector2f(250, 100));
    cc.setFillColor(sf::Color::White);
    cc.setPosition(100, 200);

    RectangleShape gg;
    gg.setSize(sf::Vector2f(100, 100));
    gg.setFillColor(sf::Color::White);
    gg.setPosition(100, 100);

    RectangleShape qq;
    qq.setSize(sf::Vector2f(100, 200));
    qq.setFillColor(sf::Color::White);
    qq.setPosition(450, 500);

    walls.push_back(gg);
    walls.push_back(qq);
    walls.push_back(cc);
    walls.push_back(ff);
    walls.push_back(kk);
    walls.push_back(wall);
    walls.push_back(s);

    RectangleShape d;
    d.setPosition(20, 20);
    d.setSize(Vector2f(20, 20));
    d.setFillColor(Color::Cyan);
    //
     //   walls.push_back(f11);
    /*    walls.push_back(f);
        walls.push_back(f1);
        walls.push_back(srodek1111);
        walls.push_back(srodek11111);
        walls.push_back(srodek111);
        walls.push_back(srodek11);
        walls.push_back(srodek1);
        walls.push_back(object11);
        walls.push_back(object1);
        walls.push_back(object);  */                                          //----------------------------------TU

    RectangleShape pud;
    pud.setSize(sf::Vector2f(900, 20));
    pud.setPosition(50, 850);
    pud.setFillColor(Color::Transparent);

    RectangleShape ud;
    ud.setSize(sf::Vector2f(30, 800));
    ud.setPosition(10, 40);
    ud.setFillColor(Color::Transparent);

    RectangleShape sud;
    sud.setSize(sf::Vector2f(30, 800));
    sud.setPosition(870, 10);
    sud.setFillColor(Color::Transparent);

    while (window.isOpen())
    {
        dt = dt_clock.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            {
                window.close();
            }


        }

        //poruszanie 
        ustawienie.y = 0.f;
        ustawienie.x = 0.f;

        velocity.y = 0.f;
        velocity.x = 0.f;

        if (Keyboard::isKeyPressed(Keyboard::D)) ustawienie.x += predkosc * dt;
        if (Keyboard::isKeyPressed(Keyboard::S)) ustawienie.y += predkosc * dt;
        if (Keyboard::isKeyPressed(Keyboard::W)) ustawienie.y += -predkosc * dt;
        if (Keyboard::isKeyPressed(Keyboard::A)) ustawienie.x += -predkosc * dt;
        if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::Space))  ustawienie.x += predkosc * 2 * dt;
        if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::Space)) ustawienie.y += predkosc * 2 * dt;
        if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::Space)) ustawienie.y += -predkosc * 2 * dt;
        if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::Space)) ustawienie.x += -predkosc * 2 * dt;

        //uptade




        // clear the window w
        window.clear(Color(216, 191, 216));
        //kolizje





       // FloatRect player_boundingBox = player.getGlobalBounds();



        FloatRect playerBounds = player.getGlobalBounds();
        FloatRect wallBounds = wall.getGlobalBounds();
        nextPos = playerBounds;
        nextPos.left += velocity.x;
        nextPos.top += velocity.y;
        for (auto& wall : walls)
        {
            if (wallBounds.intersects(nextPos))
            {

                //Bottom collision
                if (playerBounds.top < wallBounds.top
                    && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                    && playerBounds.left < wallBounds.left + wallBounds.width
                    && playerBounds.left + playerBounds.width > wallBounds.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                }

                //Top collision
                if (playerBounds.top > wallBounds.top
                    && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                    && playerBounds.left < wallBounds.left + wallBounds.width
                    && playerBounds.left + playerBounds.width > wallBounds.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
                }
                //Right collision
                if (playerBounds.left < wallBounds.left
                    && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                    && playerBounds.top < wallBounds.top + wallBounds.height
                    && playerBounds.top + playerBounds.height > wallBounds.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
                }
                //Left collision
                if (playerBounds.left > wallBounds.left
                    && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                    && playerBounds.top < wallBounds.top + wallBounds.height
                    && playerBounds.top + playerBounds.height > wallBounds.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);

                }

            }

        }


        FloatRect ss = s.getGlobalBounds();


        for (auto& s : walls)
        {
            if (ss.intersects(nextPos))
            {

                //Bottom collision
                if (playerBounds.top < ss.top
                    && playerBounds.top + playerBounds.height < ss.top + ss.height
                    && playerBounds.left < ss.left + ss.width
                    && playerBounds.left + playerBounds.width > ss.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, ss.top - playerBounds.height);
                }

                //Top collision
                if (playerBounds.top > ss.top
                    && playerBounds.top + playerBounds.height > ss.top + ss.height
                    && playerBounds.left < ss.left + ss.width
                    && playerBounds.left + playerBounds.width > ss.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, ss.top + ss.height);
                }
                //Right collision
                if (playerBounds.left < ss.left
                    && playerBounds.left + playerBounds.width < ss.left + ss.width
                    && playerBounds.top < ss.top + ss.height
                    && playerBounds.top + playerBounds.height > ss.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(ss.left - playerBounds.width, playerBounds.top);
                }
                //Left collision
                if (playerBounds.left > ss.left
                    && playerBounds.left + playerBounds.width > ss.left + ss.width
                    && playerBounds.top < ss.top + ss.height
                    && playerBounds.top + playerBounds.height > ss.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(ss.left + ss.width, playerBounds.top);

                }

            }

        }




        FloatRect k = kk.getGlobalBounds();


        for (auto& kk : walls)
        {
            if (k.intersects(nextPos))
            {

                //Bottom collision
                if (playerBounds.top < k.top
                    && playerBounds.top + playerBounds.height < k.top + k.height
                    && playerBounds.left < k.left + k.width
                    && playerBounds.left + playerBounds.width > k.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, k.top - playerBounds.height);
                }

                //Top collision
                if (playerBounds.top > k.top
                    && playerBounds.top + playerBounds.height > k.top + k.height
                    && playerBounds.left < k.left + k.width
                    && playerBounds.left + playerBounds.width > k.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, k.top + k.height);
                }
                //Right collision
                if (playerBounds.left < k.left
                    && playerBounds.left + playerBounds.width < k.left + k.width
                    && playerBounds.top < k.top + k.height
                    && playerBounds.top + playerBounds.height > k.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(k.left - playerBounds.width, playerBounds.top);
                }
                //Left collision
                if (playerBounds.left > k.left
                    && playerBounds.left + playerBounds.width > k.left + k.width
                    && playerBounds.top < k.top + k.height
                    && playerBounds.top + playerBounds.height > k.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(k.left + k.width, playerBounds.top);

                }

            }

        }




        FloatRect f = ff.getGlobalBounds();


        for (auto& ff : walls)
        {
            if (f.intersects(nextPos))
            {

                //Bottom collision
                if (playerBounds.top < f.top
                    && playerBounds.top + playerBounds.height < f.top + f.height
                    && playerBounds.left < f.left + f.width
                    && playerBounds.left + playerBounds.width > f.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, f.top - playerBounds.height);
                }

                //Top collision
                if (playerBounds.top > f.top
                    && playerBounds.top + playerBounds.height > f.top + f.height
                    && playerBounds.left < f.left + f.width
                    && playerBounds.left + playerBounds.width > f.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, f.top + f.height);
                }
                //Right collision
                if (playerBounds.left < f.left
                    && playerBounds.left + playerBounds.width < f.left + f.width
                    && playerBounds.top < f.top + f.height
                    && playerBounds.top + playerBounds.height > f.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(f.left - playerBounds.width, playerBounds.top);
                }
                //Left collision
                if (playerBounds.left > f.left
                    && playerBounds.left + playerBounds.width > f.left + f.width
                    && playerBounds.top < f.top + f.height
                    && playerBounds.top + playerBounds.height > f.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(f.left + f.width, playerBounds.top);

                }

            }

        }




        FloatRect c = cc.getGlobalBounds();


        for (auto& cc : walls)
        {
            if (c.intersects(nextPos))
            {

                //Bottom collision
                if (playerBounds.top < c.top
                    && playerBounds.top + playerBounds.height < c.top + c.height
                    && playerBounds.left < c.left + c.width
                    && playerBounds.left + playerBounds.width > c.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, c.top - playerBounds.height);
                }

                //Top collision
                if (playerBounds.top > c.top
                    && playerBounds.top + playerBounds.height > c.top + c.height
                    && playerBounds.left < c.left + c.width
                    && playerBounds.left + playerBounds.width > c.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, c.top + c.height);
                }
                //Right collision
                if (playerBounds.left < c.left
                    && playerBounds.left + playerBounds.width < c.left + c.width
                    && playerBounds.top < c.top + c.height
                    && playerBounds.top + playerBounds.height > c.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(c.left - playerBounds.width, playerBounds.top);
                }
                //Left collision
                if (playerBounds.left > c.left
                    && playerBounds.left + playerBounds.width > c.left + c.width
                    && playerBounds.top < c.top + c.height
                    && playerBounds.top + playerBounds.height > c.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(c.left + c.width, playerBounds.top);

                }

            }

        }


        FloatRect q = qq.getGlobalBounds();


        for (auto& qq : walls)
        {
            if (q.intersects(nextPos))
            {

                //Bottom collision
                if (playerBounds.top < q.top
                    && playerBounds.top + playerBounds.height < q.top + q.height
                    && playerBounds.left < q.left + q.width
                    && playerBounds.left + playerBounds.width > q.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, q.top - playerBounds.height);
                }

                //Top collision
                if (playerBounds.top > q.top
                    && playerBounds.top + playerBounds.height > q.top + q.height
                    && playerBounds.left < q.left + q.width
                    && playerBounds.left + playerBounds.width > q.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, q.top + q.height);
                }
                //Right collision
                if (playerBounds.left < q.left
                    && playerBounds.left + playerBounds.width < q.left + q.width
                    && playerBounds.top < q.top + q.height
                    && playerBounds.top + playerBounds.height > q.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(q.left - playerBounds.width, playerBounds.top);
                }
                //Left collision
                if (playerBounds.left > q.left
                    && playerBounds.left + playerBounds.width > q.left + q.width
                    && playerBounds.top < q.top + q.height
                    && playerBounds.top + playerBounds.height > q.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(q.left + q.width, playerBounds.top);

                }

            }

        }



        FloatRect g = gg.getGlobalBounds();


        for (auto& gg : walls)
        {
            if (g.intersects(nextPos))
            {

                //Bottom collision
                if (playerBounds.top < g.top
                    && playerBounds.top + playerBounds.height < g.top + g.height
                    && playerBounds.left < g.left + g.width
                    && playerBounds.left + playerBounds.width > g.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, g.top - playerBounds.height);
                }

                //Top collision
                if (playerBounds.top > g.top
                    && playerBounds.top + playerBounds.height > g.top + g.height
                    && playerBounds.left < g.left + g.width
                    && playerBounds.left + playerBounds.width > g.left)
                {
                    velocity.y = 0.f;
                    player.setPosition(playerBounds.left, g.top + g.height);
                }
                //Right collision
                if (playerBounds.left < g.left
                    && playerBounds.left + playerBounds.width < g.left + g.width
                    && playerBounds.top < g.top + g.height
                    && playerBounds.top + playerBounds.height > g.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(g.left - playerBounds.width, playerBounds.top);
                }
                //Left collision
                if (playerBounds.left > g.left
                    && playerBounds.left + playerBounds.width > g.left + g.width
                    && playerBounds.top < g.top + g.height
                    && playerBounds.top + playerBounds.height > g.top)
                {
                    velocity.x = 0.f;
                    player.setPosition(g.left + g.width, playerBounds.top);

                }

            }

        }



        player.move(ustawienie);

        // if(player.getPosition().y!=420) duch.move(Vector2f(0.4, 0));


        float op = 840;
        if (player.getPosition().x < 0)player.setPosition(0, player.getPosition().y);
        if (player.getPosition().y < 0)player.setPosition(player.getPosition().x, 0);
        if (player.getPosition().x > op)player.setPosition(op, player.getPosition().y);
        if (player.getPosition().y > op)player.setPosition(player.getPosition().x, op);
        window.draw(points);
        window.draw(points1);
        window.draw(points2);
        window.draw(points3);
        window.draw(points4);
        window.draw(points5);
        window.draw(points7);
        window.draw(points6);
        window.draw(points8);
        window.draw(points9);

        window.draw(portal);
        if (playerBounds.intersects(points.getGlobalBounds()))
        {
            points.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points1.getGlobalBounds()))
        {
            points1.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points1.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points2.getGlobalBounds()))
        {
            points2.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points2.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points3.getGlobalBounds()))
        {
            points3.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points3.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points4.getGlobalBounds()))
        {
            points4.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points4.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points5.getGlobalBounds()))
        {
            points5.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points5.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points6.getGlobalBounds()))
        {
            points6.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points6.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points7.getGlobalBounds()))
        {
            points7.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points7.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points8.getGlobalBounds()))
        {
            points8.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points8.move(3000, 5000);
            punkty++;

        }
        if (playerBounds.intersects(points9.getGlobalBounds()))
        {
            points9.setFillColor(Color::Transparent);
            cout << "Punkt" << endl;
            points9.move(3000, 5000);
            punkty++;

        }
        if (punkty >= 7)
        {

            portal.setFillColor(Color(75, 0, 130));

        }

        sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
        {

        }


        Text tekst;
        tekst.setFont(font);
        tekst.setPosition(450, 450);
        tekst.setString("Aby zamknac gre, kliknij ESC");
        tekst.setFillColor(sf::Color::Transparent);
        tekst.setCharacterSize(24);

        window.draw(box1);
        window.draw(box11);
        window.draw(box111);
        window.draw(box1111);
        FloatRect ddd = duch.getGlobalBounds();

        window.draw(duch);
        duch.move(0, 2);
        if (ddd.intersects(box1.getGlobalBounds())) duch.move(2, -2);
        if (ddd.intersects(box11.getGlobalBounds())) duch.move(2, -2);
        if (ddd.intersects(box111.getGlobalBounds())) duch.move(0, -3);
        if (ddd.intersects(box1111.getGlobalBounds())) duch.move(-2, -2);


        if (ddd.intersects(player.getGlobalBounds()))
        {
            zycie--;
            cout << "Kontakt z duchem!, Akutualne punkyt zycia: " << zycie << endl;
            // duch.setPosition(5,5);
            player.setPosition(720, 550);

        }


        //
        if (duch.getPosition().x < 0)duch.setPosition(0, duch.getPosition().y);
        if (duch.getPosition().y < 0)duch.setPosition(duch.getPosition().x, 0);
        if (duch.getPosition().x > op)duch.setPosition(op, duch.getPosition().y);
        if (duch.getPosition().y > op)duch.setPosition(duch.getPosition().x, op);

           
        //n == punkty;

       // auto funkcja = async(launch::async, sprawdzanie, n==punkty);
        
       

        if (playerBounds.intersects(portal.getGlobalBounds()))
        {
            
           // funkcja.get();
            if (punkty >= 7)
            {

                tekst.setFillColor(Color::Black);
                
            }

        }


        window.draw(pud);
        window.draw(ud);
        window.draw(sud);
        FloatRect dud = uch.getGlobalBounds();
        window.draw(uch);
        uch.move(0, 2);
        if (dud.intersects(pud.getGlobalBounds())) uch.move(-2, -2);
        if (dud.intersects(ud.getGlobalBounds())) uch.move(0, -4);
        if (dud.intersects(box1111.getGlobalBounds())) uch.move(2, -2);
        if (dud.intersects(sud.getGlobalBounds())) uch.move(0, 1);

        if (dud.intersects(player.getGlobalBounds()))
        {
            zycie--;
            cout << "Kontakt z duchem!, Akutualne punkyt zycia: " << zycie << endl;
            // duch.setPosition(5,5);
            player.setPosition(720, 550);

        }

        if (zycie == 0) {
            cout << "Stracono wszystkie punkty zycia!" << endl;
            RenderWindow window2(VideoMode(700, 300), "Gra Pacman - Pagenta", Style::Default);

            window2.setFramerateLimit(120.f);
            while (window2.isOpen())

            {
                Event event2;
                while (window2.pollEvent(event2))
                {

                    if (event2.type == Event::Closed)
                        window2.close();
                    if (event2.type == Event::KeyPressed && event2.key.code == Keyboard::Escape)
                    {
                        window2.close();

                        
                    }


                }
                Text ttekst;
                ttekst.setFont(font);
                ttekst.setPosition(26, 40);
                ttekst.setString("\t\t\t          Game\n \t\t\t          Over\n Wcisnij ESC - zamkniecie");
                ttekst.setFillColor(sf::Color::White);
                ttekst.setCharacterSize(50);

                window2.clear(Color::Black);
                window2.draw(ttekst);
                window2.display();

                if (window2.isOpen() == false)
                {
                    window.close();
                }
                

            }
        }



        window.draw(player);

        for (auto& i : walls)
        {
            window.draw(i);
        }
        window.draw(tekst);

        // window.draw(b);
        // window.draw(object11);

         // end the current frame
        window.display();
    }
    przenoszenie.punktacja_calkowita.punkty_zycia = zycie;
    przenoszenie.punktacja_calkowita.punkty_wyniku = punkty;
    return 0;
}










int main(int argc, char* argv[])
{
    
    string PlikWejsciowy = "aaa", PlikWyjsciowy = "bbb";
    for (int i = 1; i < argc - 1; i++)
    {
        string a = argv[i];
        if (a == "-wej")
        {
            PlikWejsciowy = argv[i + 1];
            i++;
        }
        else if (a == "-wyj")
        {
            PlikWyjsciowy = argv[i + 1];
            i++;
        }

    }

    if ((PlikWejsciowy == "aaa") || (PlikWyjsciowy == "bbb"))
        //
    {
        PlikWejsciowy = "Ranking.txt"; PlikWyjsciowy = "Ranking.txt";
    }
    else
        //
    {
        cout << "....................................................................................................." << endl;
        cout << "" << endl;
        cout << "Podano bledne parametry dla programu, ponizej znajduje sie instrukcja:" << endl << endl;
        pomoc();
        return 0;
    }

    SYSTEMTIME st;
    GetSystemTime(&st);


    Gra WSalka(PlikWejsciowy);
    cout << "....................................................................................................." << endl;
    cout << "Aktualna data: " << st.wDay << "-" << st.wMonth << "-" << st.wYear << endl;
    cout << "Gra: " << WSalka.nazwa_gry << endl;
    cout << "Ilosc zapisanych gier w rankingu: " << WSalka.ilosc_gier << endl;

    cout << "....................................................................................................." << endl << endl;

    if (WSalka.nazwa_gry == "Niepoprawna nazwa" || WSalka.miasto == "Niepoprawne miasto")
    {
        return 0;
    }

    int Opcja = 0;
    int gra;

    
    while (Opcja != 4)
    {
        Opcja = wybor();
        if (Opcja == 1)
        {
            Gracz<Ogolne_punkty_z_gry> nowy_gracz;
            gra = rozgrywka(nowy_gracz);
            cout << "" << endl;
            
            nowy_gracz.ustawianie_gracza();
            WSalka.Ranking.nowy_gracz(nowy_gracz);
            WSalka.ilosc_gier++;
            cout << "" << endl;
        }
        if (Opcja == 2)
        {
            cout << "" << endl;
            Ranking Posortowana(WSalka.Ranking);
            Posortowana.sortowanie_listya();
            Posortowana.wypisywanie_od_najslabszego();

            cout << "" << endl;
         

        }
        if (Opcja == 3)
        {
            cout << "" << endl;
            WSalka.usuwanie_gracza();
            cout << "" << endl;
        }


    }
    

    WSalka.zapis(PlikWyjsciowy);
    
    
 
 
    thread uno(pomiar_czasu);
    uno.join();




    cout << endl;

    ifstream mojPlik;
    mojPlik.open("Ranking.txt");
    if (mojPlik.good()) {
        vector<future<int>> wektorfuture;
        string dane;
        int ldz = 0;
        while (getline(mojPlik, dane)) {
            wektorfuture.emplace_back(async(launch::async, dziewczyny, dane));

        }
        for (int i = 0; i < wektorfuture.size(); i++) {
            ldz += wektorfuture[i].get();
        }
        cout << "Liczba dziewczyn zapisanych w rankingu: " << ldz << endl;
    }
    else cout << "Nie uda³o siê otworzyc pliku\n";

    cout << "....................................................................................................." << endl << endl;








    return 0;











   
}