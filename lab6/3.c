#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

struct infix {
  char target[MAX];
  char stack[MAX];
  char *s, *t;
  int top, l;
};

/* initializes elements of structure variable */
void initinfix(struct infix *pq) {
  pq->top = -1;
  strcpy(pq->target, "");
  strcpy(pq->stack, "");
  pq->l = 0;
}

/* reverses the given expression */
void setexpr(struct infix *pq, char *str) {
  pq->s = str;
  strrev(pq->s);
  pq->l = strlen(pq->s);
  *(pq->target + pq->l) = '\0';
  pq->t = pq->target + (pq->l - 1);
}

/* adds operator to the stack */
void push(struct infix *pq, char c) {
  if (pq->top == MAX - 1)
    printf("\nStack is full.\n");
  else {
    pq->top++;
    pq->stack[pq->top] = c;
  }
}

/* pops an operator from the stack */
char pop(struct infix *pq) {
  if (pq->top == -1) {
    printf("Stack is empty\n");
    return -1;
  } else {
    char item = pq->stack[pq->top];
    pq->top--;
    return item;
  }
}

/* converts the infix expr. to prefix form */
void convert(struct infix *pq) {
  char opr;
  while (*(pq->s)) {
    if (*(pq->s) == ' ' || *(pq->s) == '\t') {
      pq->s++;
      continue;
    }
    if (isdigit(*(pq->s)) || isalpha(*(pq->s))) {
      while (isdigit(*(pq->s)) || isalpha(*(pq->s))) {
        *(pq->t) = *(pq->s);
        pq->s++;
        pq->t--;
      }
    }
    if (*(pq->s) == ')') {
      push(pq, *(pq->s));
      pq->s++;
    }
    if (*(pq->s) == '*' || *(pq->s) == '+' || *(pq->s) == '/' ||
        *(pq->s) == '%' || *(pq->s) == '-' || *(pq->s) == '$') {
      if (pq->top != -1) {
        opr = pop(pq);
        while (priority(opr) > priority(*(pq->s))) {
          *(pq->t) = opr;
          pq->t--;
          opr = pop(pq);
        }
        push(pq, opr);
        push(pq, *(pq->s));
      } else
        push(pq, *(pq->s));
      pq->s++;
    }
    if (*(pq->s) == '(') {
      opr = pop(pq);
      while (opr != ')') {
        *(pq->t) = opr;
        pq->t--;
        opr = pop(pq);
      }
      pq->s++;
    }
  }
  while (pq->top != -1) {
    opr = pop(pq);
    *(pq->t) = opr;
    pq->t--;
  }
  pq->t++;
}

/* returns the priotity of the operator */
int priority(char c) {
  if (c == '$') return 3;
  if (c == '*' || c == '/' || c == '%') return 2;
  if (c == '+' || c == '-') return 1;

  return 0;
}

/* displays the prefix form of given expr. */
void show(struct infix pq) {
  while (*(pq.t)) {
    printf(" %c", *(pq.t));
    pq.t++;
  }
}

void main() {
  struct infix q;

  char expr[MAX];

  initinfix(&q);
  printf("\nEnter an expression in infix form: ");
  gets(expr);
  setexpr(&q, expr);
  convert(&q);
  printf("The Prefix expression is: ");
  show(q);
  getch();
}
