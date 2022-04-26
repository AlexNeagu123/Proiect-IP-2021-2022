#include <bits/stdc++.h>
#define MAX_NUMBER_OF_ITEMS 3
#include <SFML/Graphics.hpp>
bool doDfs = true;
bool succes = true;
char verdict[500];
int WHERE = 0;

// WHERE = 0 -> meniu
// WHERE = 1 -> diagrama
// WHERE = 2 -> info1
// WHERE = 3 -> info2
// WHERE = 4 -> INFO3
// WHERE = 5 -> INFO4
// WHERE = 6 -> INFO5

using namespace std;
using namespace sf;

#include "Button.h"
#include "Variables.h"
#include "OperationFinder.h"
#include "GraphBuilder.h"
#include "HeightFinder.h"
#include "OffsetsFinder.h"
#include "CodeReader.h"
#include "Process.h"
#include "FrontEnd.h"
#include "Assemble.h"
#include "Executer.h"
#include "Runner.h"
#include "Menu.h"

void afis(char s[], int n, fstream &fout)
{
    int i;
    fout.open("program.txt",ios::out | ios::trunc);
    for(i=0; i<=n-1; i++)
        if(s[i]=='`' && s[i+1]=='n')
        {
            fout<<endl;
            i++;
        }
        else fout<<s[i];

}

void Increment(int &i)
{
    i++;
}

bool isMouseOverLine(sf::RenderWindow &window, sf::RectangleShape line1, float deskx,float desky)
{

    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    int btnPosX = line1.getPosition().x;
    int btnPosY = line1.getPosition().y;

    float btnxPosWidth = line1.getPosition().x + deskx;
    float btnyPosHeight = line1.getPosition().y + desky;

    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
    {
        return true;
    }
    return false;
}

int main()
{
#include "AA.h"
    //Meniu(window.getSize().x, window.getSize().y);

    sf::Image ImageName;
    sf::Texture TextureName;
    sf::Sprite Informatii;

    std::array<sf::Image, 6> ImageArray = { {ImageName, ImageName, ImageName, ImageName, ImageName, ImageName} };
    std::array<std::string, 6> FileNameArray = { {"Images/InfoBcg1.png", "Images/InfoBcg2.png", "Images/InfoBcg3.png", "Images/InfoBcg4.png", "Images/menu.png", "Images/InfoBcg5.png"} };
    std::array<sf::Texture, 6> TextureArray = { {TextureName, TextureName, TextureName, TextureName, TextureName, TextureName} };
    std::array<sf::Sprite, 6> SpriteArray = { {Informatii, Informatii, Informatii, Informatii, Informatii, Informatii} };

    for(int i=0; i<6; i++)
    {
        (ImageArray[i]).loadFromFile((FileNameArray[i]));
        (TextureArray[i]).loadFromImage((ImageArray[i]));
        (SpriteArray[i]).setTexture((TextureArray[i]));
    }
    float Width  = SpriteArray[0].getGlobalBounds().width;
    float Height = SpriteArray[0].getGlobalBounds().height;
    for(int i=0; i<6; i++)
        SpriteArray[i].setScale({deskx/Width, desky/Height});

    int i = 0;
    while (window.isOpen())
    {
        sf::Event event;
        doDfs = false;
        while (window.pollEvent(event))
        {
            // PATEA DE EVENTURI DACA AI NEVOIE
            if(WHERE == 1)
            {
                #include "EventMagic.h"
            }
            if(WHERE == 6) {
                if (Forward3.isMouseOver(window))
                {
                    Forward3.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    Forward3.setBackColor(sf::Color::Green);
                }
                if (BackInformatii3.isMouseOver(window))
                {
                    BackInformatii3.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    BackInformatii3.setBackColor(sf::Color(245,49,42));
                }
                if(event.type == sf::Event::Resized) {
                    #include "ResizeMagic.h"
                }
                if (event.type == event.MouseButtonReleased)
                {
                    if(Forward3.isMouseOver(window))
                    {
                        WHERE = 0;
                    }
                    if (BackInformatii3.isMouseOver(window))
                    {
                        WHERE = 4;
                    }
                }
            } else if(WHERE == 5) {
                if (Forward3.isMouseOver(window))
                {
                    Forward3.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    Forward3.setBackColor(sf::Color::Green);
                }
                if (BackInformatii3.isMouseOver(window))
                {
                    BackInformatii3.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    BackInformatii3.setBackColor(sf::Color(245,49,42));
                }
                if(event.type == sf::Event::Resized) {
                    #include "ResizeMagic.h"
                }
                if (event.type == event.MouseButtonReleased)
                {
                    if(Forward3.isMouseOver(window))
                    {
                        WHERE = 6;
                    }
                    if (BackInformatii3.isMouseOver(window))
                    {
                        WHERE = 4;
                    }
                }
            } else if(WHERE == 4) {
                if (Forward2.isMouseOver(window))
                {
                    Forward2.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    Forward2.setBackColor(sf::Color::Green);
                }
                if (BackInformatii2.isMouseOver(window))
                {
                    BackInformatii2.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    BackInformatii2.setBackColor(sf::Color(245,49,42));
                }
                if(event.type == sf::Event::Resized) {
                    #include "ResizeMagic.h"
                }
                if (event.type == event.MouseButtonReleased)
                {
                    if(Forward2.isMouseOver(window))
                    {
                        WHERE = 5;
                    }
                    if (BackInformatii2.isMouseOver(window))
                    {
                        WHERE = 3;
                    }
                }
            } else if(WHERE == 3) {
                if (Forward1.isMouseOver(window))
                {
                    Forward1.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    Forward1.setBackColor(sf::Color::Green);
                }
                if (BackInformatii1.isMouseOver(window))
                {
                    BackInformatii1.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    BackInformatii1.setBackColor(sf::Color(245,49,42));
                }
                if(event.type == sf::Event::Resized) {
                    #include "ResizeMagic.h"
                }
                if (event.type == event.MouseButtonReleased)
                {
                    if(Forward1.isMouseOver(window))
                    {
                        WHERE = 4;
                    }
                    if (BackInformatii1.isMouseOver(window))
                    {
                        WHERE = 2;
                    }
                }
            } else if(WHERE == 2) {
                        if (Forward.isMouseOver(window))
                        {
                            Forward.setBackColor(sf::Color::Magenta);
                        }
                        else
                        {
                            Forward.setBackColor(sf::Color::Green);
                        }
                        if (BackInformatii.isMouseOver(window))
                        {
                            BackInformatii.setBackColor(sf::Color::Magenta);
                        }
                        else
                        {
                            BackInformatii.setBackColor(sf::Color(245,49,42));
                        }
                        if (event.type == event.MouseButtonReleased) {
                            if (Forward.isMouseOver(window))
                            {
                                WHERE = 3;
                            }
                            if (BackInformatii.isMouseOver(window))
                            {
                                WHERE = 0;
                            }
                        }
                        if(event.type == sf::Event::Resized) {
                            #include "ResizeMagic.h"
                        }
                    }
                    else if (WHERE == 0) {
                        if (CreazaDiagrama.isMouseOver(window))
                        {
                            CreazaDiagrama.setBackColor(sf::Color(255,128,237));
                        }
                        else
                        {
                            CreazaDiagrama.setBackColor(sf::Color(255,74,17));
                        }
                        if (Info.isMouseOver(window))
                        {
                            Info.setBackColor(sf::Color(255,128,237));
                        }
                        else
                        {
                            Info.setBackColor(sf::Color(72,209,204));
                        }
                         if (Exit.isMouseOver(window))
                        {
                            Exit.setBackColor(sf::Color(255,128,237));
                        }
                        else
                        {
                            Exit.setBackColor(sf::Color(245,49,42));
                        }
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            if (CreazaDiagrama.isMouseOver(window))
                            {
                                WHERE = 1;
                            }
                            if (Exit.isMouseOver(window))
                            {
                                window.close();
                            }
                            if(Info.isMouseOver(window))
                            {
                                WHERE = 2;
                            }
                        }
                        if(event.type == sf::Event::Resized) {
                            #include "ResizeMagic.h"
                        }
                    }
            if(event.type == event.Closed)
                window.close();
        }

        if(WHERE == 1)
        {
            #include "BuildMagic.h"
        }
        // PARTEA DE DESENARE + APASARE A BUTOANELOR
        if(WHERE == 0)
        {
            window.clear();
            window.draw(SpriteArray[4]);
            CreazaDiagrama.drawTo(window);
            Info.drawTo(window);
            Exit.drawTo(window);
        }

        /// se intampla asa ca nu e mouse release
        if(WHERE == 6) {
            window.clear();
            window.draw(SpriteArray[5]);
            Forward3.drawTo(window);
            BackInformatii3.drawTo(window);
        } else if(WHERE == 5) {
            window.clear();
            window.draw(SpriteArray[3]);
            Forward3.drawTo(window);
            BackInformatii3.drawTo(window);

        } else if(WHERE == 4) {
            window.clear();
            window.draw(SpriteArray[2]);
            Forward2.drawTo(window);
            BackInformatii2.drawTo(window);

        } else
        if(WHERE == 3) {
            window.clear();
            window.draw(SpriteArray[1]);
            Forward1.drawTo(window);
            BackInformatii1.drawTo(window);
        } else
        if(WHERE == 2) {
            window.clear();
            window.draw(SpriteArray[0]);
            Forward.drawTo(window);
            BackInformatii.drawTo(window);
        }
        if (WHERE != 1) window.display();
    }
}
