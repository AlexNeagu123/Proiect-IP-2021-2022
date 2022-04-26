            if(event.type == sf::Event::Resized) {
                #include "ResizeMagic.h"
            }
            else if (event.type == sf::Event::TextEntered && OK_ENTER == 1)
            {

                if (std::isprint(event.text.unicode))
                {
                    input_text += event.text.unicode;
                    x=(char)event.text.unicode;

                    a[++n]=x;
                }
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code==sf::Keyboard::Escape) window.close();
                if (event.key.code == sf::Keyboard::BackSpace && OK_ENTER==1)
                {
                    if (!input_text.empty())
                    {
                        input_text.pop_back();
                        n--;
                        if(a[n]=='`')n--;
                    }
                }
                if (event.key.code == sf::Keyboard::Return && OK_ENTER==1)
                {
                    {
                        input_text += '\n';
                        a[++n]='`';
                        a[++n]='n';
                    }
                }
            }

