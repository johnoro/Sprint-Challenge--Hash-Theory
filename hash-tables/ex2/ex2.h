#ifndef _ex_2_h_
#define _ex_2_h_

typedef struct Ticket {
  char *source;
  char *destination;
} Ticket;

char **reconstruct_trip(Ticket **tickets, int n);
void print_route(char **route, int n);
void free_route(char **route, int n);
char *strdup(const char *str);

#endif