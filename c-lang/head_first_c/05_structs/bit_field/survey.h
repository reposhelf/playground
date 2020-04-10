#ifndef SURVEY_H
#define SURVEY_H

typedef struct {
    unsigned int first_visit:1;
    unsigned int come_again:1;
    unsigned int fingers_lost:4;
    unsigned int shark_attack:1;
    unsigned int days_a_week:3;
} survey;

typedef struct {
    unsigned int first_visit;
    unsigned int come_again;
    unsigned int fingers_lost;
    unsigned int shark_attack;
    unsigned int days_a_week;
} bad_survey;

#endif