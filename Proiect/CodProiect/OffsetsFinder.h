void findOffsets(int x, coord P, int until_X) {
    queue<int> Q;
    nodes[x].offset = P;
    nodes[x].until_X = until_X;
    Q.push(x);
    while(Q.size()) {
        int nod = Q.front();
        Q.pop();
        if(nod == lines) {
            continue;
        }
        currentLine = nod;
        int operationCode = findOperation();
        if(operationCode == 6 || operationCode == 7 || operationCode == 14) {
            int to = Code_Graph.E[nod][0];
            nodes[to].offset = nodes[nod].offset;
            nodes[to].offset.y += ASSIGN_HEIGHT;
            nodes[to].until_X = nodes[nod].until_X;
            Q.push(to);
        }
        if(operationCode == 0) {

            int afterIf = until[whichElse[nod]] + 1;

            if(nodes[afterIf].offset.x == -1) {
                nodes[afterIf].offset = nodes[nod].offset;
                nodes[afterIf].offset.y += nodes[nod].height;
                nodes[afterIf].until_X = nodes[nod].until_X;
                Q.push(afterIf);
            }

            int YES = Code_Graph.E[ nod ][0];
            int NO = Code_Graph.E[ nod ][1];
            nodes[YES].offset = nodes[NO].offset = nodes[nod].offset;
            nodes[YES].offset.y += IF_HEIGHT;
            nodes[NO].offset.y += IF_HEIGHT;
            int len = nodes[nod].until_X - nodes[nod].offset.x;
            nodes[NO].offset.x += len / 2;
            nodes[YES].until_X = nodes[nod].until_X - len / 2;
            nodes[NO].until_X = nodes[nod].until_X;
            Q.push(YES);
            Q.push(NO);

        }
        if(operationCode == 2 || operationCode == 3) {

           int in = Code_Graph.E[nod][0];
           nodes[in].offset = nodes[nod].offset;
           nodes[in].offset.y += FOR_HEIGHT;
           nodes[in].offset.x += FOR_WIDTH;
           nodes[in].until_X = nodes[nod].until_X;
           Q.push(in);

        }

        if(operationCode == 10 || operationCode == 11) {
            int from = Code_Graph.E[nod][0];
            int to = Code_Graph.E[from][1];
            if(nodes[to].offset.x == -1) {
                nodes[to].offset = nodes[from].offset;
                nodes[to].offset.y += nodes[from].height;
                nodes[to].until_X = nodes[nod].until_X;
                Q.push(to);
            }
        }
            // CODES - IF = 0, ELSE = 1, FOR = 2, WHILE = 3, SWITCH = 4, CASE = 5, INPUT = 6, PRINT = 7, END IF = 8, END ELSE = 9, END FOR = 10,
            // END WHILE = 11, END SWITCH = 12, END CASE = 13, ASSIGN = 14
        if(operationCode == 4) {
            int afterSwitch = until[nod] + 1;
            nodes[afterSwitch].offset = nodes[nod].offset;
            nodes[afterSwitch].offset.y += nodes[nod].height;
            nodes[afterSwitch].until_X = nodes[nod].until_X;
            Q.push(afterSwitch);
            int cases = Code_Graph.E[nod].size();
            int lenCase = (nodes[nod].until_X - nodes[nod].offset.x) / cases;
            for(int i = 0; i < Code_Graph.E[nod].size(); ++i) {
                int curCase = Code_Graph.E[nod][i];
                nodes[curCase].offset = nodes[nod].offset;
                nodes[curCase].offset.y += SWITCH_HEIGHT;
                nodes[curCase].offset.x = nodes[nod].offset.x + i * lenCase;
                nodes[curCase].until_X = nodes[nod].offset.x + (i + 1) * lenCase;
                Q.push(curCase);
            }
        }
        if(operationCode == 5) {
            int to = Code_Graph.E[nod][0];
            nodes[to].offset = nodes[nod].offset;
            nodes[to].offset.y += CASE_HEIGHT;
            nodes[to].until_X = nodes[nod].until_X;
            Q.push(to);
        }
    }
}
