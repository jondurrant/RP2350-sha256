/**
 * Jon Durrant.
 *
 *
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "data.h"
#include "wolfssl/wolfcrypt/sha256.h"

#define DELAY 500 // in microseconds

int main() {
    const uint LED_PIN =  PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);

    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");


    uint8_t hash[32];

    uint32_t start =  to_ms_since_boot (get_absolute_time());
    Sha256 sha256[1];

    int ret;
    if ((ret = wc_InitSha256(sha256)) != 0) {
       printf("wc_InitSha256 failed\n");
    }
    else {
       wc_Sha256Update(sha256, (const byte*)data, data_length);
       wc_Sha256Final(sha256, hash);
    }

	uint32_t done =  to_ms_since_boot (get_absolute_time());

	// print resulting sha256 result
	printf("Result:\n");
	for(int i = 0; i < 32; i++) {
		printf("%02x ",  hash[i]);
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
