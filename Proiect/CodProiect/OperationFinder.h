int findOperation() {
    // CODES - IF = 0, ELSE = 1, FOR = 2, WHILE = 3, SWITCH = 4, CASE = 5, INPUT = 6, PRINT = 7, END IF = 8, END ELSE = 9, END FOR = 10,
    // END WHILE = 11, END SWITCH = 12, END CASE = 13, ASSIGN = 14
    char components[WIDTH][WIDTH];
    char Line[WIDTH];
    strcpy(Line, code[currentLine]);
    char *comp = strtok(Line, " ");
    int number = 0;
    while(comp != NULL) {
        strcpy(components[number], comp);
        comp = strtok(NULL, " ");
        ++number;
    }
    for(int i = 0; i < strlen(components[0]); ++i) {
        if(components[0][i] <= 'z' && components[0][i] >= 'a') {
            components[0][i] -= ('a' - 'A');
        }
    }
    for(int i = 0; i < strlen(components[1]); ++i) {
        if(components[1][i] <= 'z' && components[1][i] >= 'a') {
            components[1][i] -= ('a' - 'A');
        }
    }
    for(int key = 0; key < KEYS; ++key) {
        if(strcmp(keywords[key], components[0]) == 0) {
            if(key < 8) {
                if(key == 2) {
                    if(number != 7) {
                        strcpy(verdict, "Eroare! AVETI GRIJA LA FOR!");
                        succes = false;
                        return 14;
                    }
                }
                return key;
            }
            if(!strcmp(components[1], "IF")) return 8;
            if(!strcmp(components[1], "ELSE")) return 9;
            if(!strcmp(components[1], "FOR")) return 10;
            if(!strcmp(components[1], "WHILE")) return 11;
            if(!strcmp(components[1], "SWITCH")) return 12;
            if(!strcmp(components[1], "CASE")) return 13;
        }
    }
    if(strcmp(components[1], ":=") != 0) {
        succes = false;
        strcpy(verdict, "EROARE! Introduceti doar instructiuni care exista!");
    }
    return 14;
}
