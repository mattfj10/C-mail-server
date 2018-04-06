//Imports External
#include <stdlib.h>
//Defines
//Structs
typedef struct list{
    void* ref;
    struct list* next;
 } list;
//Functions
list* create_entry(void* location, list* next);
list* prepend(list* head, void* location);
list* append(list* head, void* location);
void* skip(list* head, int index);
