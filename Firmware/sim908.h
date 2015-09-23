#ifndef _SIM908_H
#define _SIM908_H

#include <stdint.h>
#include <stdbool.h>

/*Custom structures*/

typedef struct
{
	float time_utc;/*hhmmss.sss*/
	float longitude;
	char NS; /*N:North S:South*/
	float latitude;
	char EW; /*E:East W:West*/
	uint16_t satelite_count;
	float hdop; /*Horizontal dilution of precision*/
	float altitude;
	uint8_t crc;
}gps_data_t;

/*SIM908 common functions*/

void SIM908_Module_on(void);
void SIM908_Module_off(void);

/*GPS related functions*/
bool SIM908_GPS_init(void);
bool SIM908_GPS_begin(void);
int SIM908_GPS_getStatus(void);
bool SIM908_GPS_getData(gps_data_t* gps_data);

/*GSM related functions*/
bool SIM908_GSM_init(void);
bool SIM908_GSM_begin(void);
int SIM908_GSM_getStatus(void);
bool SIM908_getSMS(char* lastSMS);
bool SIM908_sendSMS(char* SMS);

#endif
