
                        deskx=window.getSize().x;
                        desky=window.getSize().y;

                        float deskxb,deskyb;
                        deskxb=window.getSize().x;
                        deskyb=window.getSize().y;
                        line1.setSize(sf::Vector2f(10,deskyb));
                        line2.setSize(sf::Vector2f(2*deskxb/3,10));

                        line1.setPosition(deskx/3,0);
                        line2.setPosition(deskx/3,4*desky/5);

                        btn1.SizeButton({(deskxb/3)/3,100});
                        btn1.setPosition({ 0, deskyb-100 });

                        btn2.SizeButton({(deskxb/3)/3, 100});
                        btn2.setPosition({ deskxb/9,deskyb-100});

                        btn3.SizeButton({(deskxb/3)/3, 100});
                        btn3.setPosition({2*deskxb/9,deskyb-100});

                        BackDiagrama.SizeButton({(deskxb/3)/3, 100});
                        BackDiagrama.setPosition({deskxb - (deskxb/3)/3, deskyb - 100});

                        texto.setPosition(sf::Vector2f(deskx/3+10,4*desky/5+10));

                        if(WHERE == 1) {
                            process();
                            findOffsets(0, coord{deskx/3 + 50, 25}, deskx - 50);
                        }

                        BackInformatii.SizeButton({(deskxb/2)/3, 100});
                        BackInformatii.setPosition({deskxb - (deskxb/2)/3, deskyb - 100});

                        BackInformatii1.SizeButton({(deskxb/2)/3, 100});
                        BackInformatii1.setPosition({deskxb - (deskxb/2)/3, deskyb - 100});

                        BackInformatii2.SizeButton({(deskxb/2)/3, 100});
                        BackInformatii2.setPosition({deskxb - (deskxb/2)/3, deskyb - 100});

                        BackInformatii3.SizeButton({(deskxb/2)/3, 100});
                        BackInformatii3.setPosition({deskxb - (deskxb/2)/3, deskyb - 100});

                        Forward.SizeButton({(deskxb/2)/3, 100});
                        Forward.setPosition({deskxb - 2*(deskxb/2)/3, deskyb - 100});

                        Forward1.SizeButton({(deskxb/2)/3, 100});
                        Forward1.setPosition({deskxb - 2*(deskxb/2)/3, deskyb - 100});

                        Forward2.SizeButton({(deskxb/2)/3, 100});
                        Forward2.setPosition({deskxb - 2*(deskxb/2)/3, deskyb - 100});

                        Forward3.SizeButton({(deskxb/2)/3, 100});
                        Forward3.setPosition({deskxb - 2*(deskxb/2)/3, deskyb - 100});

                        CreazaDiagrama.SizeButton({ (deskxb/2)/3, 100 });
                        CreazaDiagrama.setPosition(sf::Vector2f(deskxb / 2- deskxb / 12, deskyb / (MAX_NUMBER_OF_ITEMS + 2) * 2));

                        Info.SizeButton({ (deskxb/2)/3, 100 });
                        Info.setPosition(sf::Vector2f(deskxb / 2- deskxb / 12, deskyb / (MAX_NUMBER_OF_ITEMS + 2) * 3));

                        Exit.SizeButton({(deskxb/2)/3, 100 });
                        Exit.setPosition(sf::Vector2f(deskxb / 2- deskxb / 12, deskyb / (MAX_NUMBER_OF_ITEMS + 2) * 4));

                        SpriteArray[5].setScale({deskxb/Width, deskyb/Height});
                        SpriteArray[4].setScale({deskxb/Width, deskyb/Height});
                        SpriteArray[3].setScale({deskxb/Width, deskyb/Height});
                        SpriteArray[2].setScale({deskxb/Width, deskyb/Height});
                        SpriteArray[1].setScale({deskxb/Width, deskyb/Height});
                        SpriteArray[0].setScale({deskxb/Width, deskyb/Height});

                        window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
