void readCode() {
    // CODES - IF = 0, ELSE = 1, FOR = 2, WHILE = 3, SWITCH = 4, CASE = 5, INPUT = 6, PRINT = 7, END IF = 8, END ELSE = 9, END FOR = 10,
    // END WHILE = 11, END SWITCH = 12, END CASE = 13, ASSIGN = 14
    fstream f;
    lines = 0;
    Code_Graph.sterge();
    f.open("program.txt", ios::in);
    char s[WIDTH];
    while(!f.eof()) {
        f.getline(s, WIDTH);
        if(strcmp(s, "") != 0) {
            strcpy(code[lines], s);
            ++lines;
        }
    }
}
