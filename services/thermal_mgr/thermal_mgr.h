#pragma once

#include "lm75bd.h"
#include "errors.h"

// Temperature Thresholds
#define TEMP_TH 80
#define TEMP_HYS 75


typedef enum {
  THERMAL_MGR_EVENT_MEASURE_TEMP_CMD,
  OS_HANDLER_CHECK_OVER_TEMP,
} thermal_mgr_event_type_t;

typedef struct {
  thermal_mgr_event_type_t type;
} thermal_mgr_event_t;

#ifdef __cplusplus
extern "C" {
#endif

void initThermalSystemManager(lm75bd_config_t *config);

error_code_t thermalMgrSendEvent(thermal_mgr_event_t *event);

void addTemperatureTelemetry(float tempC);

void overTemperatureDetected(void);

void safeOperatingConditions(void);

#ifdef __cplusplus
}
#endif
