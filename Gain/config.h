#ifndef config_h
#define config_h

// define class name and unique id
#define MODEL_IDENTIFIER Gain
#define INSTANTIATION_TOKEN "{1AE5E10D-9521-4DE3-80B9-D0EAAA7D5AFF}"

#define CO_SIMULATION
#define MODEL_EXCHANGE

// define model size
#define NX 1
#define NZ 1

#define SET_FLOAT64
#define GET_OUTPUT_DERIVATIVE
#define EVENT_UPDATE

#define FIXED_SOLVER_STEP 1e-3
#define DEFAULT_STOP_TIME 3

typedef enum {
    vr_time, vr_y, vr_x, vr_c
} ValueReference;

typedef struct {

    double x;
    double y;
    double c;

} ModelData;

#endif /* config_h */
