        static sf::Time text_effect_time;
        static bool show_cursor;

        text_effect_time += clock.restart();

        if (text_effect_time >= sf::seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }

        text.setString(input_text + (show_cursor ? '|' : ' '));
        //cout<<findCharacterPos(text).x;
        if(BackDiagrama.isMouseOver(window)) {
            BackDiagrama.setBackColor(sf::Color(255, 128, 237));
        } else {
            BackDiagrama.setBackColor(sf::Color(255, 42, 45));
        }
        if (btn1.isMouseOver(window) && OK_ENTER==1)
        {
            btn1.setBackColor(sf::Color(255,128,237));
        }
        else
        {
            btn1.setBackColor(sf::Color::Green);
        }
        if ( OK_ENTER==0)
        {
            btn1.setBackColor(sf::Color::Black);
        }

        if (btn2.isMouseOver(window))
        {
            btn2.setBackColor(sf::Color(255,128,237));
        }
        else
        {
            btn2.setBackColor(sf::Color(245,49,42));
        }
        if (btn3.isMouseOver(window)&& OK_LOAD == 1)
        {
            btn3.setBackColor(sf::Color(255,128,237));
        }
        else
        {
            btn3.setBackColor(sf::Color(72,209,204));
        }

        if(OK_LOAD==0)
            btn3.setBackColor(sf::Color::Black);

        window.clear();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (btn1.isMouseOver(window) && OK_ENTER == 1)
            {
                fout.open("program.txt", ios::out);
                fout.close();
                if(n!=-1)
                {
                    a[++n]='\0';
                    afis(a,n,fout);
                }
                if(OK_ENTER==1)  n=-1;
                fout.close();
                process();
                if(succes) doDfs = true;
                if(succes) {
                    findOffsets(0, coord{deskx/3 + 50, 25}, deskx - 50);
                }
                texto.setString(verdict);
                if(succes) texto.setColor(sf::Color::Green);
                else texto.setColor(sf::Color::Red);
                OK_ENTER=0;
            }

            if(btn2.isMouseOver(window))
            {
                fout.close();
                OK_ENTER=1;
                OK_LOAD=1;
                texto.setString("");
                while(!input_text.empty())
                    input_text.pop_back();
                succes = true;
                strcpy(verdict, "Programul s-a efectuat cu succes!");
                lines = 0;
                n = -1;
            }

            if(btn3.isMouseOver(window) && OK_LOAD == 1)
            {
                if(a[n-1]!='`'&& a[n]!=n && n!=-1)
                {
                    a[++n]='`';
                    a[++n]='n';
                    input_text+='\n';
                }

                fin.open("input",ios::in);
                while(fin.getline(btn3c,1000))
                {
                    input_text+=btn3c;
                    int lun=strlen(btn3c);

                    for(int i=0; i<=lun-1; i++)
                    a[++n]=btn3c[i];
                    a[++n]='`';
                    a[++n]='n';

                    input_text+='\n';
                }

                fin.close();
                OK_LOAD=0;
            }
            if(BackDiagrama.isMouseOver(window)) {
                WHERE = 0;
            }
        }

        if(isMouseOverLine(window,line1,10,deskyb))
            line1.setFillColor(sf::Color(0, 20, 255));
        else line1.setFillColor(sf::Color(187, 207, 247));
        if(isMouseOverLine(window,line2,2*deskxb/3,10))
            line2.setFillColor(sf::Color(0, 20, 255));
        else line2.setFillColor(sf::Color(187, 207, 247));

//         window.draw(pseudo1);
//         window.draw(nasi1);
//         window.draw(c1);
//         text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        for(int i = 0; i < lines && succes; ++i)
        {
            if(nodes[i].code == 2 || nodes[i].code == 3)
            {
                //Background
                ForDraw1(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, nodes[i].info, window);
                //Outline
                ForDraw2(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, nodes[i].info, window);
                //Text
                ForDraw3(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, nodes[i].info, window, font);
            }
            else if(nodes[i].code == 0)
            {
                //Background
                IfDraw1(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, nodes[i].info, window);
                //Outline
                IfDraw2(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, nodes[i].info, window);
                //Text
                IfDraw3(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, nodes[i].info, window, font);
            }
            else if(nodes[i].code == 6 || nodes[i].code == 7 || nodes[i].code == 14)
            {
                //Background
                RectangleDraw1(nodes[i].offset.x, nodes[i].offset.y, nodes[i].until_X, nodes[i].info, window);
                //Outline
                RectangleDraw2(nodes[i].offset.x, nodes[i].offset.y, nodes[i].until_X, nodes[i].info, window);
                //Text
                RectangleDraw3(nodes[i].offset.x, nodes[i].offset.y, nodes[i].until_X, nodes[i].info, window, font);
            }
            else if(nodes[i].code == 4)
            {
                //Background
                SwitchDraw1(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, Code_Graph.E[i].size(), nodes[i].info, window);
                //Outline
                SwitchDraw2(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, Code_Graph.E[i].size(), nodes[i].info, window);
                //Text
                SwitchDraw3(nodes[i].offset.x, nodes[i].offset.y, nodes[i].height, nodes[i].until_X, Code_Graph.E[i].size(), nodes[i].info, window, font);
            }
            else if(nodes[i].code == 5)
            {
                RectangleDraw3(nodes[i].offset.x, nodes[i].offset.y, nodes[i].until_X, nodes[i].info, window, font);
            }
        }
        window.draw(text);
        window.draw(texto);
        window.draw(line1);
        window.draw(line2);
        btn1.drawTo(window);
        btn2.drawTo(window);
        btn3.drawTo(window);
        BackDiagrama.drawTo(window);
        window.display();
        if(doDfs) {
            dfs(0);
        }
