#include <math.h>  // for fabs()
#include <float.h> // for DBL_MIN
#include "config.h"
#include "model.h"

#define V_MIN (0.1)
#define EVENT_EPSILON (1e-10)


void setStartValues(ModelInstance *comp) {
    M(x) =  0;
    M(y) =  0;

}

Status calculateValues(ModelInstance *comp) {
    UNUSED(comp);
    M(y) = M(c) * M(x);
    return OK;
}

Status getFloat64(ModelInstance* comp, ValueReference vr, double values[], size_t nValues, size_t* index) {

    ASSERT_NVALUES(1);
    calculateValues(comp);

    switch (vr) {
        case vr_time:
            values[(*index)++] = comp->time;
            return OK;
        case vr_x:
            values[(*index)++] = M(x);
            return OK;
        case vr_y:
            values[(*index)++] = M(y);
            return OK;
        case vr_c:
            values[(*index)++] = M(c);
            return OK;
        default:
            logError(comp, "Get Float64 is not allowed for value reference %u.", vr);
            return Error;
    }
}

Status setFloat64(ModelInstance* comp, ValueReference vr, const double value[], size_t nValues, size_t* index) {

    ASSERT_NVALUES(1);

    switch (vr) {

        case vr_x:
            M(x) = value[(*index)++];
            return OK;
        case vr_c:
            M(c) = value[(*index)++];
            return OK;
        default:
            logError(comp, "Unexpected value reference: %u.", vr);
            return Error;
    }
}

Status getOutputDerivative(ModelInstance *comp, ValueReference valueReference, int order, double *value) {

    UNUSED(value);
    if (order != 1) {
        logError(comp, "The output derivative order %d for value reference %u is not available.", order, valueReference);
        return Error;
    }

    switch (valueReference) {
    default:
        logError(comp, "The output derivative for value reference %u is not available.", valueReference);
        return Error;
    }
}

void eventUpdate(ModelInstance *comp) {

    comp->nominalsOfContinuousStatesChanged = false;
    comp->terminateSimulation  = false;
    comp->nextEventTimeDefined = false;
}

void getContinuousStates(ModelInstance *comp, double x[], size_t nx) {
    UNUSED(nx);
    UNUSED(comp);
    UNUSED(x);
}

void setContinuousStates(ModelInstance *comp, const double x[], size_t nx) {
    UNUSED(nx);
    UNUSED(comp);
    UNUSED(x);
}

void getDerivatives(ModelInstance *comp, double dx[], size_t nx) {
    UNUSED(nx);
    UNUSED(comp);
    UNUSED(dx);
}

void getEventIndicators(ModelInstance *comp, double z[], size_t nz) {

    UNUSED(nz);
    UNUSED(comp);
    UNUSED(z);
}
