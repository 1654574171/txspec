#pragma once

typedef enum METIRC_TYPE
{
    kMT_COUNTER = 0,
    kMT_GAUGE = 1,
    kMT_HISTOGRAM = 2,
    kMT_SUMMARY = 3
} metric_type_t;
