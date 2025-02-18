#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10, item = 0;

void producer()
{
	--mutex;
	++full;
	--empty;
	item++;
	printf("Producer adds item %d to the buffer.\n", item);
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("Consumer removes item %d from the buffer.\n", item);
	item--;
	++mutex;
}

int main()
{
	int choice, i;
	printf("-----PRODUCER CONSUMER PROBLEM-----");
	printf("\n1. Press 1 to add an item (Producer)"
		"\n2. Press 2 to remove an item (Consumer)"
		"\n3. Press 3 to Exit");


	for (i = 1; i > 0; i++) {

		printf("\nEnter your choice:");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if ((mutex == 1) && (empty != 0)) {
				producer();
			}
			else {
				printf("Buffer is full!");
			}
			break;

		case 2:
			if ((mutex == 1) && (full != 0)) {
				consumer();
			}
			else {
				printf("There is no item in the Buffer");
			}
			break;

		case 3:
			exit(0);
			break;
		default:
			printf("Invalid choice\n");
		}
	}
}
