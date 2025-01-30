#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"

static void die(const char *msg);

int main() {
    stdio_init_all();

	while (true) {
		printf("Teste\n");
		sleep_ms(1000);
	}
}

static void die(const char *msg) {
	while (true) {
		printf("ERRO FATAL: %s\n", msg);
		sleep_ms(2000);
	}
}
