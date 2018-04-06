#include "module.h"

void* skip(list* head, int index)
{
    while (index-- > 0)
      head = head->next;
    return head->ref;
}

list* create_entry(void* location, list* next)
{
     list* entry = malloc(sizeof(list));
     entry->ref = location;
     entry->next = next;
     return entry;
}

list* prepend(list* head, void* location)
{
   return create_entry(location, head);
}

list* append(list* head, void* location)
{
   list* entry = create_entry(location, NULL);
   if(head == NULL)
       head = entry;
   else {
       list* xs  = head;
       while(xs->next != NULL)
           xs = xs->next;
       xs->next = entry;
   } return head;
}
