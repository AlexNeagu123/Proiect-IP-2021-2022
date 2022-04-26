void buildGraph() {
    // CODES - IF = 0, ELSE = 1, FOR = 2, WHILE = 3, SWITCH = 4, CASE = 5, INPUT = 6, PRINT = 7, END IF = 8, END ELSE = 9, END FOR = 10,
    // END WHILE = 11, END SWITCH = 12, END CASE = 13, ASSIGN = 14
    for(currentLine = 0; currentLine < lines; ++currentLine) {
        nodes[currentLine].ID = currentLine;
        int operation = findOperation();
        strcpy(nodes[currentLine].info, code[currentLine]);
        if(operation == 0) {
            int sz = strlen(code[currentLine]);
            //sz - 5..sz
            nodes[currentLine].info[sz - 5] = NULL;
        }
    }
    nodes[lines].ID = lines;
    strcpy(nodes[lines].info, "END");
    stack<int> ifs;
    for(currentLine = 0; currentLine < lines; ++currentLine) {
        int operationCode = findOperation();
        if(succes == false) {
            return;
        }
        if(operationCode == 0) {
            ifs.push(currentLine);
        } else if(operationCode == 1) {
            if(ifs.empty()) {
                strcpy(verdict, "EROARE! Nu exista else fara if!:)");
                succes = false;
                return;
            }
            whichIf[currentLine] = ifs.top();
            whichElse[ifs.top()] = currentLine;
            ifs.pop();
        }
    }
    stack<int> operation[6];
    for(currentLine = 0; currentLine < lines; ++currentLine) {
        int operationCode = findOperation();
        if(operationCode == 5) {
            if(operation[4].empty()) {
                strcpy(verdict, "EROARE! Atentie la Switchuri");
                succes = false;
                return;
            }
            parentCase[currentLine] = operation[4].top();
        }
        if(operationCode < 6) {
            operation[operationCode].push(currentLine);
            //cout << currentLine << '\n';
        }
        if(operationCode >= 8 && operationCode < 14) {
            int corespondent = operationCode - 8;
            if(operation[corespondent].empty()) {
                strcpy(verdict, "Eroare! Nu puteti pune end fara o instructiune care il precede!");
                succes = false;
                return;
            }
            until[operation[corespondent].top()] = currentLine;
            operation[corespondent].pop();
        }
    }
    for(currentLine = 0; currentLine < lines; ++currentLine) {
        int operationCode = findOperation();
        if(operationCode >= 0 && operationCode <= 5 && until[currentLine] == -1) {
            strcpy(verdict, "Eroare! Aveti grija sa puneti end la finalul structurilor de baza!");
            succes = false;
            return;
        }
        if(operationCode == 0 && whichElse[currentLine] == -1) {
            strcpy(verdict, "Eroare! Dupa if trebuie neaparat sa urmeze un else!");
            succes = false;
            return;
        }
    }
    for(currentLine = 0; currentLine < lines; ++currentLine) {
        int operationCode = findOperation();
        if(operationCode == 6 || operationCode == 7 || operationCode == 14) {
            Code_Graph.add_edge(currentLine, currentLine + 1);
        }
        if(operationCode == 0) {
            // manage ifs
            Code_Graph.add_edge(currentLine, currentLine + 1);
            if(whichElse[currentLine] != -1) {
                Code_Graph.add_edge(currentLine, whichElse[currentLine] + 1);
            }
            // manage end ifs
            if(whichElse[currentLine] == -1) {
                Code_Graph.add_edge(until[currentLine], until[currentLine] + 1);
            } else {
                Code_Graph.add_edge(until[currentLine], until[ whichElse[currentLine] ] + 1);
            }
        }
        if(operationCode == 1 || operationCode == 10 || operationCode == 8 || operationCode == 11) {
            continue;
        }
        if(operationCode == 2 || operationCode == 3) {
            Code_Graph.add_edge(currentLine, currentLine + 1); // intra in for
            Code_Graph.add_edge(currentLine, until[currentLine] + 1); // scapa din for
            Code_Graph.add_edge(until[currentLine], currentLine);
        }
        if(operationCode == 9) {
            Code_Graph.add_edge(currentLine, currentLine + 1);
        }
        if(operationCode == 5) {
            int from = currentLine, to = until[from], par = parentCase[currentLine];
            Code_Graph.add_edge(par, from);
            Code_Graph.add_edge(from, from + 1);
            Code_Graph.add_edge(to, until[par]);
        }
        if(operationCode == 12) {
            Code_Graph.add_edge(currentLine, currentLine + 1);
        }
    }
}
