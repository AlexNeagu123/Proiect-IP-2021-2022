void findHeight(int x, int stop) {
    // CODES - IF = 0, ELSE = 1, FOR = 2, WHILE = 3, SWITCH = 4, CASE = 5, INPUT = 6, PRINT = 7, END IF = 8, END ELSE = 9, END FOR = 10,
    // END WHILE = 11, END SWITCH = 12, END CASE = 13, ASSIGN = 14
    multiset<int> Q;
    Q.insert(x);
    set<int> processed;
    while(Q.size()) {
        int NODE = *Q.begin();
        Q.erase(Q.begin());
        processed.insert(NODE);
        if(NODE == stop) {
            continue;
        }
        currentLine = NODE;
        int operationCode = findOperation();
        if(operationCode == 6 || operationCode == 7 || operationCode == 14) {
            heights[NODE] += ASSIGN_HEIGHT;
        } else if(operationCode == 0) {
            heights[NODE] += IF_HEIGHT;
        } else if(operationCode == 2 || operationCode == 3) {
            heights[NODE] += FOR_HEIGHT;
        } else if(operationCode == 5) {
            heights[NODE] += CASE_HEIGHT;
        } else if(operationCode == 4) {
            heights[NODE] += SWITCH_HEIGHT;
        }
        if(operationCode != 10 && operationCode != 2 && operationCode != 11 && operationCode != 3) {
            for(auto it : Code_Graph.E[NODE]) {
                if(!processed.count(it)) {
                    if(heights[NODE] > heights[it]) {
                        if(Q.count(it)) {
                            Q.erase(it);
                        }
                        heights[it] = heights[NODE];
                        Q.insert(it);
                    }
                }
            }
        } else if(operationCode == 2 || operationCode == 3) {
            int to = Code_Graph.E[NODE][0];
            if(!processed.count(to)) {
                heights[ to ] = heights[NODE];
                Q.insert(to);
            }
        } else {
            int from = Code_Graph.E[NODE][0];
            int to = Code_Graph.E[from][1];
            if(!processed.count(to)) {
                heights[ to ] = heights[NODE];
                Q.insert(to);
            }
        }
    }
}
