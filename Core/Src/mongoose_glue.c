// SPDX-FileCopyrightText: 2024 Cesanta Software Limited
// SPDX-License-Identifier: GPL-2.0-only or commercial
// Generated by Mongoose Wizard, https://mongoose.ws/wizard/

// Include your device-specific headers, and edit functions below
// #include "hal.h"

#include "mongoose_glue.h"


//static void timer_fn(void *arg) {
//  // Publish to MQTT topic
////  if (g_mqtt_conn != NULL) {
////    struct mg_mqtt_opts opts,opts2,opts3;
////    memset(&opts, 0, sizeof(opts));
////    opts.topic = mg_str("h745/s1");
////    opts.message = mg_str("Hi from Nucleo board ! Connected");
////    mg_mqtt_pub(g_mqtt_conn, &opts);
////  }
////	static int increment_value = 0;     // Value for topic 1 (0 to 100)
////	static int decrement_value = 100;   // Value for topic 2 (100 to 0)
////
////	 if (g_mqtt_conn != NULL) {
////	    struct mg_mqtt_opts opts1, opts2, opts3;
////	    char msg1[16], msg2[16], msg3[16];
////
////	    // Increment value from 0 to 100 for topic 1
////	    snprintf(msg1, sizeof(msg1), "%d", increment_value);
////	    memset(&opts1, 0, sizeof(opts1));
////	    opts1.topic = mg_str("nodered/d1/s1");
////	    opts1.message = mg_str(msg1);
////	    mg_mqtt_pub(g_mqtt_conn, &opts1);
////
////	    // Decrement value from 100 to 0 for topic 2
////	    snprintf(msg2, sizeof(msg2), "%d", decrement_value);
////	    memset(&opts2, 0, sizeof(opts2));
////	    opts2.topic = mg_str("nodered/d1/s2");
////	    opts2.message = mg_str(msg2);
////	    mg_mqtt_pub(g_mqtt_conn, &opts2);
////
////	    // Random value from 0 to 100 for topic 3
////	    int random_value = rand() % 101;
////	    snprintf(msg3, sizeof(msg3), "%d", random_value);
////	    memset(&opts3, 0, sizeof(opts3));
////	    opts3.topic = mg_str("nodered/d1/s3");
////	    opts3.message = mg_str(msg3);
////	    mg_mqtt_pub(g_mqtt_conn, &opts3);
////
////	    // Update increment and decrement values for next publish
////	    increment_value = (increment_value + 1) % 101;       // Reset to 0 after 100
////	    decrement_value = (decrement_value - 1 + 101) % 101; // Reset to 100 after 0
////	  }
//	static int increment_value = -100;   // Value for topic 1 (-100 to 0)
//	static int decrement_value = 0;
//
//	 if (g_mqtt_conn != NULL) {
//	    struct mg_mqtt_opts opts1, opts2, opts3;
//	    char msg1[16], msg2[16], msg3[16];
////
//	    // Increment value from -100 to 0 for topic 1
//	    snprintf(msg1, sizeof(msg1), "%d", increment_value);
//	    memset(&opts1, 0, sizeof(opts1));
//	    opts1.topic = mg_str("nodered/d2/s1");
//	    opts1.message = mg_str(msg1);
//	    mg_mqtt_pub(g_mqtt_conn, &opts1);
//
//	    // Decrement value from 0 to -100 for topic 2
//	    snprintf(msg2, sizeof(msg2), "%d", decrement_value);
//	    memset(&opts2, 0, sizeof(opts2));
//	    opts2.topic = mg_str("nodered/d2/s2");
//	    opts2.message = mg_str(msg2);
//	    mg_mqtt_pub(g_mqtt_conn, &opts2);
//
//	    // Random value from 0 to 100 for topic 3
//	    int random_value = rand() % 101;
//	    snprintf(msg3, sizeof(msg3), "%d", random_value);
//	    memset(&opts3, 0, sizeof(opts3));
//	    opts3.topic = mg_str("nodered/d2/s3");
//	    opts3.message = mg_str(msg3);
//	    mg_mqtt_pub(g_mqtt_conn, &opts3);
//
//	    // Update increment and decrement values for next publish
//	    if (increment_value < 0) {
//	      increment_value++;       // Increment towards 0
//	    } else {
//	      increment_value = -100;  // Reset to -100 after reaching 0
//	    }
//
//	    if (decrement_value > -100) {
//	      decrement_value--;       // Decrement towards -100
//	    } else {
//	      decrement_value = 0;     // Reset to 0 after reaching -100
//	    }
//	  }
//}
static void timer_fn_1(void *arg) {
	static int increment =0;
	 if (g_mqtt_conn != NULL) {
	    struct mg_mqtt_opts opts;
	    char msg[16];
	   snprintf(msg, sizeof(msg), "%d", increment);
	    memset(&opts, 0, sizeof(opts));
	    opts.topic = mg_str("nodered/d2/s1");
	    opts.message = mg_str(msg);
	    mg_mqtt_pub(g_mqtt_conn, &opts);
	    if(increment >101){
	    	increment =0;
	    }
	    else{
	    	increment++;
	    }
}
}
void glue_init_1(void) {
	  mg_timer_add(&g_mgr, 1000, MG_TIMER_REPEAT, timer_fn_1, NULL);
  MG_DEBUG(("Custom init done"));
}//2
static void timer_fn_2(void *arg) {
	static int decrement =100;
	 if (g_mqtt_conn != NULL) {
	    struct mg_mqtt_opts opts;
	    char msg[16];
	   snprintf(msg, sizeof(msg), "%d", decrement);
	    memset(&opts, 0, sizeof(opts));
	    opts.topic = mg_str("nodered/d2/s2");
	    opts.message = mg_str(msg);
	    mg_mqtt_pub(g_mqtt_conn, &opts);
	    if(decrement <0){
	    	decrement =100;
	    }
	    else{
	    	decrement--;
	    }
}
}
void glue_init_2(void) {
	  mg_timer_add(&g_mgr, 1000, MG_TIMER_REPEAT, timer_fn_2, NULL);
  MG_DEBUG(("Custom init done"));
}
static void timer_fn_3(void *arg) {
	 int random_value = rand() % 101;
	 if (g_mqtt_conn != NULL) {
	    struct mg_mqtt_opts opts;
	    char msg[16];
	   snprintf(msg, sizeof(msg), "%d", random_value);
	    memset(&opts, 0, sizeof(opts));
	    opts.topic = mg_str("nodered/d2/s3");
	    opts.message = mg_str(msg);
	    mg_mqtt_pub(g_mqtt_conn, &opts);
}
}
void glue_init_3(void) {
	  mg_timer_add(&g_mgr, 5000, MG_TIMER_REPEAT, timer_fn_3, NULL);
  MG_DEBUG(("Custom init done"));
}

//void glue_init(void) {
//	  mg_timer_add(&g_mgr, 1000, MG_TIMER_REPEAT, timer_fn, NULL);
//  MG_DEBUG(("Custom init done"));
//}

void glue_lock_init(void) {  // callback to initialize the MQTT semaphore
}

void glue_lock(void) {  // Lock mutex. Implement only if you use MQTT publish
}

void glue_unlock(void) {  // Unlock mutex. Implement only if you use MQTT publish
}

void glue_mqtt_tls_init(struct mg_connection *c) {
  bool is_tls = mg_url_is_ssl(WIZARD_MQTT_URL);
  MG_DEBUG(("%lu TLS enabled: %s", c->id, is_tls ? "yes" : "no"));
  if (is_tls) {
    struct mg_tls_opts opts;
    memset(&opts, 0, sizeof(opts));
    // opts.ca = mg_str(ca_certificate);
    mg_tls_init(c, &opts);
  }
}

// Called when we connected to the MQTT server
void glue_mqtt_on_connect(struct mg_connection *c, int code) {
  struct mg_mqtt_opts opts;
  memset(&opts, 0, sizeof(opts));
  opts.qos = 1;
  opts.topic = mg_str("device1/rx");
  mg_mqtt_sub(c, &opts);
  MG_DEBUG(("%lu code %d. Subscribing to [%.*s]", c->id, code, opts.topic.len,
            opts.topic.buf));
}

// This function gets called for every received MQTT message
void glue_mqtt_on_message(struct mg_connection *c, struct mg_str topic,
                          struct mg_str data) {
  char tmp[100];
  struct mg_mqtt_opts opts;

  mg_snprintf(tmp, sizeof(tmp), "Got [%.*s] -> [%.*s] !", topic.len, topic.buf,
              data.len, data.buf);
  MG_DEBUG(("%lu %s", c->id, tmp));

  // Send response to the TX topic
  if (g_mqtt_conn != NULL) {
    memset(&opts, 0, sizeof(opts));
    opts.topic = mg_str("device1/tx");
    opts.message = mg_str(tmp);
    mg_mqtt_pub(g_mqtt_conn, &opts);
  }
}

void glue_mqtt_on_cmd(struct mg_connection *c, struct mg_mqtt_message *mm) {
  MG_DEBUG(("%lu cmd %d qos %d", c->id, mm->cmd, mm->qos));
}

struct mg_connection *glue_mqtt_connect(struct mg_mgr *mgr,
                                        mg_event_handler_t fn) {
  const char *url = WIZARD_MQTT_URL;
  struct mg_mqtt_opts opts;
  memset(&opts, 0, sizeof(opts));
  opts.clean = true;
  return mg_mqtt_connect(mgr, url, &opts, fn, NULL);
}


void glue_sntp_on_time(uint64_t utc_time_in_milliseconds) {
  MG_INFO(("UTC time in milliseconds from SNTP: %llu, current time: %llu",
           utc_time_in_milliseconds, mg_now()));
}


// Mock a device that has 5 read/write registers at address 1000
static uint16_t s_modbus_regs[] = {11, 22, 33, 44, 55};
static uint16_t s_modbus_base = 1000;  // Base address of our registers

bool glue_modbus_read_reg(uint16_t address, uint16_t *value) {
  bool success = false;
  size_t count = sizeof(s_modbus_regs) / sizeof(s_modbus_regs[0]);
  if (address >= s_modbus_base && address < s_modbus_base + count) {
    *value = s_modbus_regs[address - s_modbus_base];
    success = true;
  }
  MG_INFO(("%s: %hu = %hu", success ? "OK" : "FAIL", address, *value));
  return success;
}

bool glue_modbus_write_reg(uint16_t address, uint16_t value) {
  bool success = false;
  size_t count = sizeof(s_modbus_regs) / sizeof(s_modbus_regs[0]);
  if (address >= s_modbus_base && address < s_modbus_base + count) {
    s_modbus_regs[address - s_modbus_base] = value;
    success = true;
  }
  MG_INFO(("%s: %hu = %hu", success ? "OK" : "FAIL", address, value));
  return success;

}


// Authenticate user/password. Return access level for the authenticated user:
//   0 - authentication error
//   1,2,3... - authentication success. Higher levels are more privileged than lower
int glue_authenticate(const char *user, const char *pass) {
  int level = 0; // Authentication failure
  if (strcmp(user, "Sarayu") == 0 && strcmp(pass, "Sarayu@123") == 0) {
    level = 7;  // Administrator
  } else if (strcmp(user, "user") == 0 && strcmp(pass, "user") == 0) {
    level = 3;  // Ordinary dude
  }
  return level;
}


// reboot
static uint64_t s_action_timeout_reboot;  // Time when reboot ends
bool glue_check_reboot(void) {
  return s_action_timeout_reboot > mg_now(); // Return true if reboot is in progress
}
void glue_start_reboot(void) {
  s_action_timeout_reboot = mg_now() + 1000; // Start reboot, finish after 1 second
}

// firmware_update
void  *glue_ota_begin_firmware_update(char *file_name, size_t total_size) {
  bool ok = mg_ota_begin(total_size);
  MG_DEBUG(("%s size %lu, ok: %d", file_name, total_size, ok));
  return ok ? (void *) 1 : NULL;
}
bool  glue_ota_end_firmware_update(void *context) {
  bool ok = mg_ota_end();
  MG_DEBUG(("ctx: %p, success: %d", context, ok));
  if (ok) {
    MG_INFO(("Rebooting in %lu ms", WIZARD_REBOOT_TIMEOUT_MS));
    mg_timer_add(&g_mgr, WIZARD_REBOOT_TIMEOUT_MS, 0,
      (void(*)(void *)) mg_device_reset, NULL);
  }
  return ok;
}
bool  glue_ota_write_firmware_update(void *context, void *buf, size_t len) {
  MG_DEBUG(("ctx: %p %p/%lu", context, buf, len));
  return mg_ota_write(buf, len);
}

// file_upload
void  *glue_file_open_file_upload(char *file_name, size_t total_size) {
  char path[128], *p = NULL;
  FILE *fp = NULL;
  if ((p = strrchr(file_name, '/')) == NULL) p = file_name;
  mg_snprintf(path, sizeof(path), "/tmp/%s", p);
#if MG_ENABLE_POSIX_FS
  fp = fopen(path, "w+b");
#endif
  MG_DEBUG(("opening [%s] size %lu, fp %p", path, total_size, fp));
  return fp;
}
bool  glue_file_close_file_upload(void *fp) {
  MG_DEBUG(("closing %p", fp));
#if MG_ENABLE_POSIX_FS
  return fclose((FILE *) fp) == 0;
#else
  return false;
#endif
}
bool  glue_file_write_file_upload(void *fp, void *buf, size_t len) {
  MG_DEBUG(("writing fp %p %p %lu bytes", fp, buf, len));
#if MG_ENABLE_POSIX_FS
  return fwrite(buf, 1, len, (FILE *) fp) == len;
#else
  return false;
#endif
}

// graph1
size_t glue_graph_get_graph1(uint32_t from, uint32_t to,
                              uint32_t *x_values, double *y_values, size_t len) {
  size_t i = 0;
  uint32_t timestamps[] = {1724576787,1724576847,1724576907,1724576967,1724577027,1724577087,1724577147,1724577207,1724577267,1724577327};  // Those are example values
  double values[] = {20.3,27.2,29.7,27.9,25.1,23.8,22.5,22.2,23.3,23.9};  // Use real device data
  for (i = 0; i < len; i++) {
    if (i >= sizeof(values) / sizeof(values[0])) break;
    x_values[i] = timestamps[i];
    y_values[i] = values[i];
  }
  (void) from, (void) to;
  return i;
}

static struct state s_state = {42, 27, 70, 10, "1.0.0", true, false, 83};
void glue_get_state(struct state *data) {
  *data = s_state;  // Sync with your device
}
void glue_set_state(struct state *data) {
  s_state = *data; // Sync with your device
}

static struct leds s_leds = {false, true, false};
void glue_get_leds(struct leds *data) {
  *data = s_leds;  // Sync with your device
}
void glue_set_leds(struct leds *data) {
  s_leds = *data; // Sync with your device
}

static struct settings s_settings = {"edit & save me", 2, 123.12345, 17, true};
void glue_get_settings(struct settings *data) {
  *data = s_settings;  // Sync with your device
}
void glue_set_settings(struct settings *data) {
  s_settings = *data; // Sync with your device
}

static struct security s_security = {"admin", "user"};
void glue_get_security(struct security *data) {
  *data = s_security;  // Sync with your device
}
void glue_set_security(struct security *data) {
  s_security = *data; // Sync with your device
}