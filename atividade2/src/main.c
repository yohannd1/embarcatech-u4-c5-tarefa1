#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"

#define BUTTON_PIN 5
#define DEBOUNCING_TIME_US 200000

#define LED_RED_PIN 11
#define LED_YELLOW_PIN 12
#define LED_GREEN_PIN 13
#define INTERVAL_MS 3000

static volatile uint8_t counter = 0;

static void handle_button_press(uint gpio, uint32_t events);
static bool update_semaphore(struct repeating_timer *_);

int main() {
    stdio_init_all();

	/* gpio_init(LED_RED_PIN); */
	/* gpio_set_dir(LED_RED_PIN, GPIO_OUT); */
	/* gpio_put(LED_RED_PIN, 0); */

	/* gpio_init(LED_YELLOW_PIN); */
	/* gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT); */
	/* gpio_put(LED_YELLOW_PIN, 0); */

	/* gpio_init(LED_GREEN_PIN); */
	/* gpio_set_dir(LED_GREEN_PIN, GPIO_OUT); */
	/* gpio_put(LED_GREEN_PIN, 0); */

	gpio_init(BUTTON_PIN);
	gpio_set_dir(BUTTON_PIN, GPIO_IN);
	gpio_pull_up(BUTTON_PIN);
	gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &handle_button_press);

	/* struct repeating_timer timer; */
	/* add_repeating_timer_ms(INTERVAL_MS, update_semaphore, NULL, &timer); */

	while (true) {
		printf("Olá, mundo! %d\n", counter);
		sleep_ms(1000);
	}
}

/* static bool update_semaphore(struct repeating_timer *_) { */
/* 	gpio_put(LED_RED_PIN, counter == 0); */
/* 	gpio_put(LED_YELLOW_PIN, counter == 1); */
/* 	gpio_put(LED_GREEN_PIN, counter == 2); */

/* 	counter = (counter + 1) % 3; */

/* 	return true; */
/* } */

static void handle_button_press(uint gpio, uint32_t events) {
	static volatile uint32_t last_time = 0;

	if (gpio != BUTTON_PIN) return;
    uint32_t current_time = to_us_since_boot(get_absolute_time());

	if (current_time - last_time > DEBOUNCING_TIME_US) {
		if (!gpio_get(BUTTON_PIN)) {
			counter++;
		}
		last_time = current_time;
	}
}
