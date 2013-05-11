#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0x05, 0x2F, 0x25, 0xC6, 0xEB, 0xDE, 0x42, 0xE1, 0x93, 0xE6, 0xF5, 0x07, 0x19, 0x38, 0xF3, 0x2D }
PBL_APP_INFO(MY_UUID,
             "Three Dominoes", "Guillaume Laforge",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;


void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Window Name");
  window_stack_push(&window, true /* Animated */);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
