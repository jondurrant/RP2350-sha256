/**
 * Jon Durrant.
 *
 *
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "data.h"
#include "pico/sha256.h"

#define DELAY 500 // in microseconds

int main() {
    const uint LED_PIN =  PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);

    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    pico_sha256_state_t state;

    uint32_t start =  to_ms_since_boot (get_absolute_time());
	int rc = pico_sha256_start_blocking(&state, SHA256_BIG_ENDIAN, true); // using some DMA system resources
	hard_assert(rc == PICO_OK);
	pico_sha256_update_blocking(&state, (const uint8_t*)data, data_length);

	// Get the result of the sha256 calculation
	sha256_result_t result;
	pico_sha256_finish(&state, &result);

	uint32_t done =  to_ms_since_boot (get_absolute_time());

	// print resulting sha256 result
	printf("Result:\n");
	for(int i = 0; i < SHA256_RESULT_BYTES; i++) {
		printf("%02x ", result.bytes[i]);
		if ((i+1) % 16 == 0) printf("\n");
	}

	uint32_t ms = done - start;
	printf("SHA256 calculate in %d ms\n", ms);


    while (true) { // Loop forever
        gpio_put(LED_PIN, 1);
        sleep_ms(DELAY);
        gpio_put(LED_PIN, 0);
        sleep_ms(DELAY);
    }

}
