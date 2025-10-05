/*--------------------------------------------------------------*/
//∑¿÷π÷ÿ∏¥“˝”√
#ifndef	__LINE_H__
#define __LINE_H__
/*--------------------------------------------------------------*/
#include "motor.h"
#include "sensor.h"
#include "main.h"
#include "dart.h"
void track_turnright(int forward,int right,int delay);
void track_turnleft(int forward,int right,int delay);

void track_zhixian1(void);
void track_zhixian2(void);
void track_zhixian3(void);
void track_straightline(void);
void track_dart(void);

void statezero(void);
void stateone(void);
void statetwo(void);

void statezero_1(void);
void stateone_1(void);
void statetwo_1(void);


void open(void);
#endif

