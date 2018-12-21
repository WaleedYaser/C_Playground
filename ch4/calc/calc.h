#define NUMBER		'0'		/* signal that a number was found */
#define MATHLIB		'1'		/* signal that a library function was found */
#define VARIABLE	'2'		/* signal that a variable was found */

int getop(char s[]);

void push(double f);
double pop(void);
void print_top();
void duplicate_top();
void swap_top();
void clear();

int getch(void);
void ungetch(int);
void ungets(char s[]);
