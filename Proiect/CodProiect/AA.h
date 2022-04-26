#include "Button.h"
    strcpy(verdict, "Programul s-a efectuat cu succes");
    fstream fout;
    fstream fin;

    char a[10000],x;
    char btn3c[1000];
    float index=18.113207547169;
    float suma=0;
    int OK_ENTER=1;
    int OK_LOAD=1;

    int n=-1;
    int nr=0;
    unsigned deskx,desky;
    deskx=sf::VideoMode::getDesktopMode().width-100;
    desky=sf::VideoMode::getDesktopMode().height-150;


    sf::RenderWindow window({deskx,desky}, "26: Diagrame Nassi-Schneiderman");
    sf::RectangleShape line1(sf::Vector2f(10,desky));
    sf::RectangleShape line2(sf::Vector2f(2*deskx/3,10));
    line1.setPosition(deskx/3,0);
    line2.setPosition(deskx/3,4*desky/5);
    line1.setFillColor(sf::Color(187, 207, 247));
    line2.setFillColor(sf::Color(187, 207, 247));


    std::string input_text;
    sf::Font font;
    font.loadFromFile("Fonts/arial.ttf");
    sf::Text text("", font);
    sf::Text texto("",font);

    float deskxb,deskyb;
    deskxb=window.getSize().x;
    deskyb=window.getSize().y;

    Button btn1("Enter", { (deskxb/3)/3, 100 }, 30, sf::Color::Green, sf::Color::White);
    Button btn2("New", { (deskxb/3)/3, 100 }, 30, sf::Color::Green, sf::Color::White);
    Button btn3("Load", { (deskxb/3)/3, 100 }, 30, sf::Color::Green, sf::Color::White);

    Button CreazaDiagrama("Creeaza Diagrama", { (deskxb/2)/3, 100 }, 30, sf::Color(255,74,17), sf::Color::White);
    Button Info("Informatii", { (deskxb/2)/3, 100 }, 30, sf::Color(72,209,204), sf::Color::White);
    Button Exit("Exit", { (deskxb/2)/3, 100 }, 30, sf::Color::Red, sf::Color::White);
    Button BackDiagrama("Back", { (deskxb/3)/3, 100 }, 30, sf::Color::Red, sf::Color::White);

    Button Forward("Inainte", { (deskxb/2)/3, 100 }, 30, sf::Color(0, 255, 0), sf::Color::White);
    Button Forward1("Inainte", { (deskxb/2)/3, 100 }, 30, sf::Color(0, 255, 0), sf::Color::White);
    Button Forward2("Inainte", { (deskxb/2)/3, 100 }, 30, sf::Color(0, 255, 0), sf::Color::White);
    Button Forward3("Inainte", { (deskxb/2)/3, 100 }, 30, sf::Color(0, 255, 0), sf::Color::White);

    Button BackInformatii("Back", { (deskxb/2)/3, 100 }, 30, sf::Color::Red, sf::Color::White);
    Button BackInformatii1("Back", { (deskxb/2)/3, 100 }, 30, sf::Color::Red, sf::Color::White);
    Button BackInformatii2("Back", { (deskxb/2)/3, 100 }, 30, sf::Color::Red, sf::Color::White);
    Button BackInformatii3("Back", { (deskxb/2)/3, 100 }, 30, sf::Color::Red, sf::Color::White);

    btn1.setFont(font);
    btn2.setFont(font);
    btn3.setFont(font);
    CreazaDiagrama.setFont(font);
    Info.setFont(font);
    Exit.setFont(font);
    BackDiagrama.setFont(font);
    Forward.setFont(font);
    Forward1.setFont(font);
    Forward2.setFont(font);
    Forward3.setFont(font);
    BackInformatii.setFont(font);
    BackInformatii1.setFont(font);
    BackInformatii2.setFont(font);
    BackInformatii3.setFont(font);
    btn1.setPosition({ 0, deskyb-100 });
    btn2.setPosition({(deskxb/3)/3,deskyb - 100});
    btn3.setPosition({2 * deskxb / 9,deskyb - 100});
    BackDiagrama.setPosition({deskxb - (deskxb/3)/3, deskyb - 100});

    CreazaDiagrama.setPosition(sf::Vector2f(deskxb / 2 - deskxb / 12, deskyb / (MAX_NUMBER_OF_ITEMS+2) * 2));
    Info.setPosition(sf::Vector2f(deskxb / 2- deskxb / 12, deskyb / (MAX_NUMBER_OF_ITEMS+2) * 3));
    Exit.setPosition(sf::Vector2f(deskxb / 2- deskxb / 12, deskyb / (MAX_NUMBER_OF_ITEMS+2) * 4));

    Forward.setPosition({deskxb - 2*(deskxb/2)/3, deskyb - 100});
    Forward1.setPosition({deskxb - 2*(deskxb/2)/3, deskyb - 100});
    Forward2.setPosition({deskxb - 2*(deskxb/2)/3, deskyb - 100});
    Forward3.setPosition({deskxb - 2*(deskxb/2)/3, deskyb - 100});
    BackInformatii.setPosition({deskxb - (deskxb/2)/3, deskyb - 100});
    BackInformatii1.setPosition({deskxb - (deskxb/2)/3, deskyb - 100});
    BackInformatii2.setPosition({deskxb - (deskxb/2)/3, deskyb - 100});
    BackInformatii3.setPosition({deskxb - (deskxb/2)/3, deskyb - 100});




    texto.setPosition(sf::Vector2f(deskx/3+10,4*desky/5+10));

    sf::Clock clock;
