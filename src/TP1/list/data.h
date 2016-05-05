#ifndef G__DATA__
#define G__DATA__

typedef struct data  data;

data * construct_data(const char * name,
                      const int old);

void delete_data(data* data_to_free);

int eq_data(const data* f,
            const data* s);


int get_age(data * data);

const char * get_name (data * data);

void print_data(data * data);

#endif
