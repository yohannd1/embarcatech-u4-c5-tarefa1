#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"

#define LED_RED_PIN 11
#define LED_YELLOW_PIN 12
#define LED_GREEN_PIN 13
#define INTERVAL_MS 3000

static void die(const char *msg);

int main() {
    stdio_init_all();

	gpio_init(LED_RED_PIN);
	gpio_set_dir(LED_RED_PIN, GPIO_OUT);

	gpio_init(LED_YELLOW_PIN);
	gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);

	gpio_init(LED_GREEN_PIN);
	gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

	while (true) {
		gpio_put(LED_RED_PIN, 1);
		gpio_put(LED_YELLOW_PIN, 0);
		gpio_put(LED_GREEN_PIN, 0);
		sleep_ms(INTERVAL_MS);

		gpio_put(LED_RED_PIN, 0);
		gpio_put(LED_YELLOW_PIN, 1);
		sleep_ms(INTERVAL_MS);

		gpio_put(LED_YELLOW_PIN, 0);
		gpio_put(LED_GREEN_PIN, 1);
		sleep_ms(INTERVAL_MS);
	}
}

static void die(const char *msg) {
	while (true) {
		printf("ERRO FATAL: %s\n", msg);
		sleep_ms(2000);
	}
}
