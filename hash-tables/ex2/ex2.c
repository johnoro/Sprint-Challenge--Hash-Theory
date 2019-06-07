#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(length);
  char **route = malloc(length * sizeof(char *));
  int i = 0;

  for (; i < length; i++) {
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  i = 0;
  char *dest = hash_table_retrieve(ht, "NONE");
  while (strcmp(dest, "NONE") != 0) {
    route[i++] = strdup(dest);
    dest = hash_table_retrieve(ht, dest);
  }
  route[i] = strdup("NONE");

  return route;
}

void print_route(char **route, int length)
{
  int i = 0;
  for (; i < length-1; i++)
    printf("%s, ", route[i]);
  printf("%s\n", route[i]);
}

void free_route(char **route, int length) {
  for (int i = 0; i < length; i++)
    free(route[i]);
  free(route);
}


#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  char **route = reconstruct_trip(tickets, 3);
  print_route(route, 3); // PDX, DCA, NONE

  for (int i = 0; i < 3; i++) {
    free(tickets[i]);
  }

  free(tickets);

  free_route(route, 3);

  return 0;
}
#endif
