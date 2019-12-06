#ifndef __DATA_H__
#define __DATA_H__

#include <pthread.h>
#include <stdint.h>

// Structs

typedef struct DATA_T
{
	pthread_rwlock_t lock;
	size_t           size;
	unsigned int     links;
	uint8_t          data[0];

} data_t;

typedef struct LINKED_DATA_T
{
	pthread_rwlock_t       lock;
	struct DATA_T        * data;
	struct LINKED_DATA_T * next;
	
} ldata_t;

typedef struct DOUBLE_LINKED_DATA_T
{
	pthread_rwlock_t              lock;
	struct DATA_T               * data;
	struct DOUBLE_LINKED_DATA_T * next;
	struct DOUBLE_LINKED_DATA_T * back;

} lldata_t;

// Functions

data_t   * new_data(   void   * data, size_t size);
ldata_t  * new_ldata(  data_t * data);
lldata_t * new_lldata( data_t * data);

void   * get_data(   data_t   * data);
data_t * get_ldata(  ldata_t  * element);
data_t * get_lldata( lldata_t * element);

ldata_t  * next_ldata(  ldata_t  * element);
lldata_t * next_lldata( lldata_t * element);
lldata_t * back_lldata( lldata_t * element);

ldata_t  * last_ldata(   ldata_t  * element);
lldata_t * last_lldata(  lldata_t * element);
lldata_t * first_lldata( lldata_t * element);

unsigned int get_ldata_n(      ldata_t  * root);
unsigned int get_lldata_n(     lldata_t * root);
unsigned int get_lldata_all_n( lldata_t * c_root);

void insert_ldata(  data_t * data2insert);
void insert_lldata( data_t * data2insert);

void append_ldata(  data_t * data2append);
void append_lldata( data_t * data2append);



#endif
