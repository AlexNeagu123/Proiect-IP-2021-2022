using namespace sf;

/// Input, Print, Assign

void RectangleDraw1(int x, int y, int untilX, char *text, RenderWindow &window)
{
    sf::VertexArray Rectangle(sf::TriangleStrip, 4);

    Rectangle[0].position = Vector2f(untilX, y);
    Rectangle[0].color = Color(109, 184, 251);


    Rectangle[1].position = Vector2f(x, y);
    Rectangle[1].color = Color(26, 144, 249);


    Rectangle[2].position = Vector2f(untilX, y + ASSIGN_HEIGHT);
    Rectangle[2].color = Color(6, 118, 219);

    Rectangle[3].position = Vector2f(x, y + ASSIGN_HEIGHT);
    Rectangle[3].color = Color(59,160,250);

    window.draw(Rectangle);
}

void RectangleDraw2(int x, int y, int untilX, char *text, RenderWindow &window)
{
    sf::VertexArray RectangleLines(sf::LineStrip, 4);

    RectangleLines[0].position = Vector2f(untilX, y);
    RectangleLines[0].color = Color::Black;


    RectangleLines[1].position = Vector2f(x, y);
    RectangleLines[1].color = Color::Black;


    RectangleLines[2].position = Vector2f(x, y + ASSIGN_HEIGHT);
    RectangleLines[2].color = Color::Black;

    RectangleLines[3].position = Vector2f(untilX, y + ASSIGN_HEIGHT);
    RectangleLines[3].color = Color::Black;

    window.draw(RectangleLines);
}

void RectangleDraw3(int x, int y, int untilX, char *text, RenderWindow &window, Font &font)
{
    sf::Text message(text, font, FONT_SIZE);

    int numChars = strlen(text);
    float width = message.findCharacterPos(numChars-1).x - message.findCharacterPos(0).x;
    float axisX = (untilX - x)/2 - 3*width/4 + x;
    float axisY = ASSIGN_HEIGHT/2 - FONT_SIZE/2 + y;
    message.setPosition(axisX, axisY);

    window.draw(message);
}

/// For

void ForDraw1(int x, int y, int height, int untilX, char *text, RenderWindow &window)
{

    sf::VertexArray Lshape(sf::TrianglesStrip, 7);

    Lshape[0].position = sf::Vector2f(untilX, y);
    Lshape[0].color = Color(105,199,68);

    Lshape[1].position = sf::Vector2f(untilX, y + FOR_HEIGHT);
    Lshape[1].color = Color(96,192,58);

    Lshape[2].position = sf::Vector2f(x, y);
    Lshape[2].color = Color(90,179,54);

    Lshape[3].position = sf::Vector2f(x + FOR_WIDTH, y + FOR_HEIGHT);
    Lshape[3].color = Color(83,166,50);

    Lshape[4].position = sf::Vector2f(x, y + FOR_HEIGHT);
    Lshape[4].color = Color(90,179,54);

    Lshape[5].position = sf::Vector2f(x + FOR_WIDTH, y + height);
    Lshape[5].color = Color(96,192,58);

    Lshape[6].position = sf::Vector2f(x, y + height);
    Lshape[6].color = Color(105,199,68);

    window.draw(Lshape);
}

void ForDraw2(int x, int y, int height, int untilX, char *text, RenderWindow &window)
{

    sf::VertexArray Lshape(sf::LineStrip, 7);

    Lshape[0].position = sf::Vector2f(x, y);
    Lshape[0].color = Color::Black;

    Lshape[1].position = sf::Vector2f(untilX, y);
    Lshape[1].color = Color::Black;

    Lshape[2].position = sf::Vector2f(untilX, y + FOR_HEIGHT);
    Lshape[2].color = Color::Black;

    Lshape[3].position = sf::Vector2f(x + FOR_WIDTH, y + FOR_HEIGHT);
    Lshape[3].color = Color::Black;

    Lshape[4].position = sf::Vector2f(x + FOR_WIDTH, y + height);
    Lshape[4].color = Color::Black;

    Lshape[5].position = sf::Vector2f(x, y + height);
    Lshape[5].color = Color::Black;

    Lshape[6].position = sf::Vector2f(x, y);
    Lshape[6].color = Color::Black;

    window.draw(Lshape);
}

void ForDraw3(int x, int y, int height, int untilX, char *text, RenderWindow &window, Font &font)
{
    sf::Text message(text, font, FONT_SIZE);

    int numChars = strlen(text);
    float width = message.findCharacterPos(numChars-1).x - message.findCharacterPos(0).x;
    float axisX = (untilX - x)/2 - width/2 + x;
    float axisY = FOR_HEIGHT/2 - FONT_SIZE/2 + y;
    message.setPosition(axisX, axisY);

    window.draw(message);

}

/// If

void IfDraw1(int x, int y, int height, int untilX, char *text, RenderWindow &window)
{
    sf::VertexArray ifRectangle(sf::TriangleStrip, 5);

    ifRectangle[0].position = sf::Vector2f(x, y + IF_HEIGHT);
    ifRectangle[0].color = Color(128, 160, 214);

    ifRectangle[1].position = sf::Vector2f(x, y);
    ifRectangle[1].color = Color(161, 231, 255);

    ifRectangle[2].position = sf::Vector2f((untilX - x)/2 + x, y + IF_HEIGHT);
    ifRectangle[2].color = Color(194, 246, 255);

    ifRectangle[3].position = sf::Vector2f(untilX, y);
    ifRectangle[3].color = Color(195, 187, 199);

    ifRectangle[4].position = sf::Vector2f(untilX, y+IF_HEIGHT);
    ifRectangle[4].color = Color(229, 222, 224);

    window.draw(ifRectangle);
}

void IfDraw2(int x, int y, int height, int untilX, char *text, RenderWindow &window)
{
    sf::VertexArray ifRectangleLines(sf::LineStrip, 7);

    ifRectangleLines[0].position = sf::Vector2f(x, y);
    ifRectangleLines[0].color = Color::Black;

    ifRectangleLines[1].position = sf::Vector2f(x, y+IF_HEIGHT);
    ifRectangleLines[1].color = Color::Black;

    ifRectangleLines[2].position = sf::Vector2f(untilX, y + IF_HEIGHT);
    ifRectangleLines[2].color = Color::Black;

    ifRectangleLines[3].position = sf::Vector2f(untilX, y);
    ifRectangleLines[3].color = Color::Black;

    ifRectangleLines[4].position = sf::Vector2f((untilX - x)/2 + x, y + IF_HEIGHT);
    ifRectangleLines[4].color = Color::Black;

    ifRectangleLines[5].position = sf::Vector2f(x, y);
    ifRectangleLines[5].color = Color::Black;

    ifRectangleLines[6].position = sf::Vector2f(untilX, y);
    ifRectangleLines[6].color = Color::Black;

    window.draw(ifRectangleLines);
}

void IfDraw3(int x, int y, int height, int untilX, char *text, RenderWindow &window, Font &font)
{
    sf::Text message(text, font, FONT_SIZE);
    message.setColor(Color::Black);

    int numChars = strlen(text);
    float width = message.findCharacterPos(numChars-1).x - message.findCharacterPos(0).x;
    float axisX = (untilX - x)/2 - width/1.4 + x;
    float axisY = IF_HEIGHT/2 - FONT_SIZE/2 + y;
    message.setPosition(axisX, axisY);
    window.draw(message);
    message.setPosition(x + 50, y + 28);
    message.setString("Y");
    window.draw(message);
    message.setPosition(untilX - 60, y + 28);
    message.setString("N");
    window.draw(message);
    //message.setString();
}

/// Switch

void SwitchDraw1(int x, int y, int height, int untilX, int nrCases, char *text, RenderWindow &window)
{
    int caseWidth = (untilX - x) / nrCases;
    sf::VertexArray Switch(sf::TriangleStrip, (nrCases+1) * 4);

    Switch[0].position = sf::Vector2f(untilX, y);
    Switch[0].color = Color(239, 154, 12);

    Switch[1].position = sf::Vector2f(untilX, y + SWITCH_HEIGHT);
    Switch[1].color = Color(206, 133, 11);

    Switch[2].position = sf::Vector2f(x, y);
    Switch[2].color = Color(244, 168, 41);

    Switch[3].position = sf::Vector2f(x, y + SWITCH_HEIGHT);
    Switch[3].color = Color(248, 201, 122);

    int c = 3;
    for(int i = 1; i <= nrCases; ++i)
    {
        Switch[++c].position = sf::Vector2f(x + (i-1) * caseWidth, y+SWITCH_HEIGHT);
        Switch[c].color = sf::Color(214,52,31);

        Switch[++c].position = sf::Vector2f(x + (i-1) * caseWidth, y + SWITCH_HEIGHT + CASE_HEIGHT);
        Switch[c].color = sf::Color(184,44,27);

        Switch[++c].position = sf::Vector2f(x + i * caseWidth, y + SWITCH_HEIGHT);
        Switch[c].color = sf::Color(214,52,31);

        Switch[++c].position = sf::Vector2f(x + i * caseWidth, y + SWITCH_HEIGHT + CASE_HEIGHT);
        Switch[c].color = sf::Color(184,44,27);
    }

    window.draw(Switch);

}

void SwitchDraw2(int x, int y, int height, int untilX, int nrCases, char *text, RenderWindow &window)
{
    int caseWidth = (untilX - x) / nrCases;
    sf::VertexArray SwitchLines(sf::LinesStrip, 7 + (nrCases-1) * 4);

    SwitchLines[0].position = sf::Vector2f(untilX, y+SWITCH_HEIGHT);
    SwitchLines[0].color = Color::Black;

    SwitchLines[1].position = sf::Vector2f(untilX, y+height);
    SwitchLines[1].color = Color::Black;

    SwitchLines[2].position = sf::Vector2f(x, y+height);
    SwitchLines[2].color = Color::Black;

    SwitchLines[3].position = sf::Vector2f(x, y);
    SwitchLines[3].color = Color::Black;

    SwitchLines[4].position = sf::Vector2f(untilX, y);
    SwitchLines[4].color = Color::Black;

    SwitchLines[5].position = sf::Vector2f(untilX, y+SWITCH_HEIGHT);
    SwitchLines[5].color = Color::Black;

    SwitchLines[6].position = sf::Vector2f(x, y+SWITCH_HEIGHT);
    SwitchLines[6].color = Color::Black;

    int c = 6;
    for(int i = 1; i < nrCases; ++i)
    {
        SwitchLines[++c].position = sf::Vector2f(x + i * caseWidth, y+SWITCH_HEIGHT);
        SwitchLines[c].color = sf::Color::Black;

        SwitchLines[++c].position = sf::Vector2f(x + i * caseWidth, y + height);
        SwitchLines[c].color = sf::Color::Black;

        SwitchLines[++c].position = sf::Vector2f(x + (i+1) * caseWidth, y + height);
        SwitchLines[c].color = sf::Color::Black;

        SwitchLines[++c].position = sf::Vector2f(x + (i+1) * caseWidth, y + SWITCH_HEIGHT);
        SwitchLines[c].color = sf::Color::Black;
    }

    window.draw(SwitchLines);

}

void SwitchDraw3(int x, int y, int height, int untilX, int nrCases, char *text, RenderWindow &window, Font &font)
{
    sf::Text message(text, font, FONT_SIZE);

    int numChars = strlen(text);
    float width = message.findCharacterPos(numChars-1).x - message.findCharacterPos(0).x;
    float axisX = (untilX - x)/2 - width/2 + x;
    float axisY = SWITCH_HEIGHT/2 - FONT_SIZE/2 + y;
    message.setPosition(axisX, axisY);

    window.draw(message);
}
