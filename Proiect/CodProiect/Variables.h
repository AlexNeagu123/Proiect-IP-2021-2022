using namespace std;
using namespace sf;
const int LINES = 500;
const int WIDTH = 100;
const int KEYS = 9;
const int ASSIGN_HEIGHT = 50;
const int IF_HEIGHT = 75;
const int FOR_HEIGHT = 50;
const int FOR_WIDTH = 25;
const int CASE_HEIGHT = 50;
const int SWITCH_HEIGHT = 50;
const int FONT_SIZE = 25;
unsigned deskx = sf::VideoMode::getDesktopMode().width-50;
unsigned desky = sf::VideoMode::getDesktopMode().height-100;

char code[LINES][WIDTH];
int lines = 0, currentLine, whichIf[LINES], whichElse[LINES];
int until[LINES], cnt[LINES], heights[LINES], space[LINES], parentCase[LINES], stepsFor[LINES], cntSteps[LINES], stepsWhile[LINES];
map<string,int> variables;
char keywords[KEYS][50] = {"IF", "ELSE", "FOR", "WHILE", "SWITCH", "CASE", "INPUT", "PRINT", "END"};
struct coord {
    int x, y;
};
struct node {
    int ID;
    char info[WIDTH];
    coord offset;
    int height,until_X;
    int code;
};

vector<node> nodes(LINES + 1);
struct Graph {
    vector<int> E[WIDTH];
    void add_edge(int x, int y) {
        E[x].push_back(y);
    }
    void print(int ID) {
        cout << "Vecinii lui " << ID + 1 << " sunt : " << '\n';
        for(auto it : E[ID]) {
            cout << it + 1 << ' ';
        }
        cout << '\n';
    }
    void sterge()
    {
        for(int i = 0; i < WIDTH; ++i)
            E[i].clear();
    }
} Code_Graph;
struct expressionCalculator {
    stack<int> nums;
    stack<char> op;
    // stack - stiva
    // nums.push(ceva).
    // nums.pop();
    // nums.top().
    bool is_op(char ch) {
        if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%') {
            return true;
        }
        return false;
    }
    int val(char ch) {
        if (ch == '+' || ch == '-') {
            return 1;
        }
        if (ch == '*' || ch == '/' || ch == '%') {
            return 2;
        }
        return -1;
    }
    int do_op(char op) {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        if (op == '+') {
            b += a;
        }
        if (op == '-') {
            b -= a;
        }
        if (op == '*') {
            b *= a;
        }
        if (op == '/') {
            b /= a;
        }
        if (op == '%') {
            b %= a;
        }
        nums.push(b);
    }
    int compute(char *S) {
        char c[WIDTH];
        for(int i = 0; i < strlen(S); ++i) {
            c[i + 1] = S[i];
        }
        int n = strlen(S);
        for (int i = 1; i <= n; i++) {
            if (c[i] == '(') {
                op.push('(');
            }
            else if (c[i] == ')') {
                while(op.top() != '(') {
                    char oper = op.top();
                    op.pop();
                    do_op(oper);
                }
                op.pop();
            }
            else if (is_op(c[i])) {
                while(op.size() && val(c[i]) <= val(op.top())) {
                    do_op(op.top());
                    op.pop();
                }
                op.push(c[i]);
            }
            else {
                int nr = 0;
                int j = i;
                while(c[j] >= '0' && c[j] <= '9') {
                    nr = nr * 10 + (c[j] - '0');
                    j++;
                }
                nums.push(nr);
                i = j - 1;
            }
        }
        while(op.size()) {
            do_op(op.top());
            op.pop();
        }
        return nums.top();
    }
} Calculator;

int executeExpression(char *expression) {
    int i, j, lenVar;
    char aux[WIDTH], var[WIDTH];
    int n = strlen(expression) - 1;
    for(i = 0; i <= n; i++) {
        if(isalpha(expression[i])) {
            j = i;
            while(!strchr("*/%-+()", expression[j]) && expression[j] != NULL)
                j++;
             strcpy(aux, expression + j);
             strcpy(var, expression + i);
             var[j - i] = NULL;
             int val = variables[var];
             var[0] = '\0';
             //itoa(val, var, 10);
             sprintf(var, "%d", val);
             lenVar = strlen(var);
             strcpy(expression + i, var);
             strcpy(expression + i + lenVar, aux);
             n = strlen(expression) - 1;
        }
    }
    return Calculator.compute(expression);
}

bool isComparator(string c) {
    return (c == "<" || c == "<=" || c == ">" || c == ">=" || c == "=" || c == "!=");
}
int compare(int a, string op, int b) {
    if(op == "<=") return a <= b;
    if(op == "<") return a < b;
    if(op == ">=") return a >= b;
    if(op == ">") return a > b;
    if(op == "=") return a == b;
    if(op == "!=") return a != b;
}
bool executeCondition(vector<string> components) {
    components.pop_back();
    for(int i = 0; i < components.size(); ++i) {
        if(isComparator(components[i])) {
            if(i - 2 < 0 || i + 2 >= components.size()) {
                cout << "Eroare! Ai grija la formularea conditiilor!\n";
                exit(0);
            }
            char e1[WIDTH], e2[WIDTH];
            strcpy(e1, components[i - 1].c_str());
            strcpy(e2, components[i + 1].c_str());
            int exp1 = executeExpression(e1);
            int exp2 = executeExpression(e2);
            string cmp = components[i];
            int res = compare(exp1, cmp, exp2);
            string ins = "0";
            if(res == 1) ins = "1";
            components.erase(components.begin() + i - 2, components.begin() + i + 3);
            components.insert(components.begin() + i - 2, ins);
        }
    }
    for(int i = 0; i < components.size(); ++i) {
        if(components[i] == "and") {
            components.erase(components.begin() + i);
            components.insert(components.begin() + i, "*");
        }
        if(components[i] == "or") {
            components.erase(components.begin() + i);
            components.insert(components.begin() + i, "+");
        }
    }
    string finalOne;
    for(int i = 0; i < components.size(); ++i) {
        finalOne += components[i];
    }
    char exp[WIDTH];
    strcpy(exp, finalOne.c_str());
    int result = executeExpression(exp);
    return (result > 0);
}
