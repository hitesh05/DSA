#ifndef __UPDT_VAL_H__
#define __UPDT_VAL_H__
#define total_coins 100000000
#define init_val 100
typedef struct data data;
typedef data *data_ptr;
struct data
{
    int old_usr;
    int new_usr;
    int old_trans;
    int new_trans;
};
double upd_val(data_ptr detail, double val);
double after_attack(double val);

#endif