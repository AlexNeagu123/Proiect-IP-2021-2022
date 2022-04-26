void process() {
    // CODES - IF = 0, ELSE = 1, FOR = 2, WHILE = 3, SWITCH = 4, CASE = 5, INPUT = 6, PRINT = 7, END IF = 8, END ELSE = 9, END FOR = 10,
    // END WHILE = 11, END SWITCH = 12, END CASE = 13, ASSIGN = 14
    memset(whichElse, -1, sizeof(whichElse));
    memset(until, -1, sizeof(whichElse));
    readCode();
    buildGraph();
    if(!succes) {
        return;
    }
    for(int node_id = 0; node_id < lines; node_id++) {
        currentLine = nodes[node_id].ID;
        int operationCode = findOperation();
        if(operationCode == 6 || operationCode == 7 || operationCode == 14) {
            space[nodes[node_id].ID] = ASSIGN_HEIGHT;
        }
        memset(heights, 0, sizeof(heights));
        if(operationCode == 0 || operationCode == 4 || operationCode == 5 || operationCode == 2 || operationCode == 3) {
            int limit = until[node_id];
            if(operationCode == 0) {
                limit = until[ whichElse[node_id] ] + 1;
            }
            findHeight(node_id, limit);
            space[node_id] = heights[limit];
        }
        nodes[node_id].height = space[node_id];
        nodes[node_id].offset = coord{-1, -1};
    }

    /// INTREBARE ALEX
    //findOffsets(0, coord{deskx/2+25, 25}, deskx - 50);
    for(currentLine = 0; currentLine < lines; currentLine++) {
        nodes[currentLine].code = findOperation();
    }
}
