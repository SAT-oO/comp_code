#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Descriptor {
	int id;
	int name_length;
	char *name;
} Descriptor;

Descriptor *allocate_and_initialize_descriptor(int id, const char *name) {
	Descriptor *descrip = (Descriptor *)malloc(sizeof(Descriptor));

	descrip->id = id;
	descrip->name_length = strlen(name);
	char *name_cpy = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	*name_cpy = *name;

	descrip->name = name_cpy;
	return descrip;
}

void deallocate_descriptor(Descriptor *descriptor) {
	free(descriptor->name);
	descriptor->name = NULL;

	free(descriptor);
	descriptor = NULL;
}

#ifndef RunTests
int main() {
	Descriptor *descriptor = allocate_and_initialize_descriptor(2, "File");
	printf(
		"Id: %d, name length: %d, name: %s",
		descriptor->id,
		descriptor->name_length,
		descriptor->name
	);
-	deallocate_descriptor(descriptor);
}
#endif