void dfs(int node) {
    if(node == lines) {
        return;
    }
    currentLine = node;
    int operationCode = findOperation();
    if(operationCode == 6) {
        executeInput();
        dfs(node + 1);
    }
    if(operationCode == 7) {
        executePrint();
        dfs(node + 1);
    }
    if(operationCode == 14) {
        executeAssign();
        dfs(node + 1);
    }
    if(operationCode == 2) {
        bool B = executeFor();
        if(B == true) {
            dfs(Code_Graph.E[currentLine][0]);
        } else {
            dfs(Code_Graph.E[currentLine][1]);
        }
    }
    if(operationCode == 10) {
        dfs(Code_Graph.E[currentLine][0]);
    }
    if(operationCode == 0) {
        bool verdict = executeIf();
        if(verdict) {
            dfs(Code_Graph.E[currentLine][0]);
        } else {
            dfs(Code_Graph.E[currentLine][1]);
        }
    }
    if(operationCode == 8 || operationCode == 9) {
        dfs(Code_Graph.E[currentLine][0]);
    }
    if(operationCode == 3) {
        bool verdict = executeWhile();
        if(verdict) {
            dfs(Code_Graph.E[currentLine][0]);
        } else {
            dfs(Code_Graph.E[currentLine][1]);
        }
    }
    if(operationCode == 11) {
        dfs(Code_Graph.E[currentLine][0]);
    }
    if(operationCode == 4) {
        int nextNode = executeSwitch();
        dfs(nextNode);
    }
    if(operationCode == 12 || operationCode == 13 || operationCode == 5) {
        dfs(Code_Graph.E[currentLine][0]);
    }
}
