void executeInput() {
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    while(Line[0] == ' ') {
        strcpy(Line, Line + 1);
    }
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }
    // components[0] -> "INPUT"
    // components[1] -> Numele variabilei.
    int variable;
    printf("%s = ", components[1]);
    cin >> variable;
    variables[components[1]] = variable;
}
void executePrint() {
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    while(Line[0] == ' ') {
        strcpy(Line, Line + 1);
    }
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }

    // components[0] = "PRINT"
    // components[1] = expresie
    // PRINT expresie
    cout << executeExpression(components[1]) << '\n';
}
void executeAssign() {
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    while(Line[0] == ' ') {
        strcpy(Line, Line + 1);
    }
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }
    variables[components[0]] = executeExpression(components[2]);
}
bool executeFor() {
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    while(Line[0] == ' ') {
        strcpy(Line, Line + 1);
    }
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }
    int exp2 = executeExpression(components[5]);
    int exp1 = executeExpression(components[3]);
    if(stepsFor[currentLine] == 0) {
        if(!strcmp(components[4], "to")) {
            cntSteps[currentLine] = exp2 - exp1 + 1;
        } else if(!strcmp(components[4], "downto")){
            cntSteps[currentLine] = exp1 - exp2 + 1;
        } else {
            cout << "Eroare de sintaxa pe linia " << currentLine << '\n';
            exit(0);
        }
    }
    if(!strcmp(components[4], "to")) variables[components[1]] = exp1 + stepsFor[currentLine];
    else if(!strcmp(components[4], "downto")) variables[components[1]] = exp1 - stepsFor[currentLine];
    if(stepsFor[currentLine] + 1 <= cntSteps[currentLine]) {
        stepsFor[currentLine]++;
        return true;
    }
    stepsFor[currentLine] = 0;
    cntSteps[currentLine] = 0;
    return false;
    // FOR + variableName + := + exp1 + to + exp2 + DO
}
bool executeIf() {
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    while(Line[0] == ' ') {
        strcpy(Line, Line + 1);
    }
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }
    vector<string> condition;
    for(int i = 1; i < number; ++i) {
        condition.push_back(components[i]);
    }
    bool verdict = executeCondition(condition);
    return verdict;
}
bool executeWhile() {
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    while(Line[0] == ' ') {
        strcpy(Line, Line + 1);
    }
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }
    stepsWhile[currentLine]++;
    vector<string> condition;
    for(int i = 1; i < number; ++i) {
        condition.push_back(components[i]);
    }
    bool verdict = executeCondition(condition);
    return verdict;
}
int executeCase() {
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    while(Line[0] == ' ') {
        strcpy(Line, Line + 1);
    }
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }
    if(!strcmp(components[1], "DEFAULT")) {
        return -2e9;
    }
    int nr = executeExpression(components[1]);
    return nr;
}
int executeSwitch() {
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    while(Line[0] == ' ') {
        strcpy(Line, Line + 1);
    }
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }
    int aux = currentLine;
    for(int i = 0; i < Code_Graph.E[aux].size(); ++i) {
        currentLine = Code_Graph.E[aux][i];
        if(executeCase() == -2e9) {
            currentLine = aux;
            return Code_Graph.E[aux][i];
        }
        if(executeCase() == variables[components[1]]) {
            currentLine = aux;
            return Code_Graph.E[aux][i];
        }
    }
    currentLine = aux;
    return until[currentLine];
}
