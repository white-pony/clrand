#include <CL/cl.h>


struct clrand_context {
	cl_device_id device;
	cl_context context;
	cl_command_queue queue;
	cl_mem dev_seed;
	cl_program program;
	cl_kernel uniform;
	cl_kernel uniform_float;
	cl_kernel normal_float;
	cl_kernel normal;

	int parallel_thread_num;
};

typedef struct clrand_context clrand_context;

void check_for_error(cl_int error, char *error_message);

int clrand_init(clrand_context* ctx, cl_device_id device, cl_context cl_ctx, cl_command_queue queue, int parallel_thread_num);
int clrand_release(clrand_context* ctx);

int clrand_set_seed(clrand_context* ctx, int seed);

int clrand_uniform(clrand_context* ctx, cl_mem buffer, cl_int buf_size);
int clrand_uniform_float(clrand_context* ctx, cl_mem buffer, cl_int buf_size);
int clrand_normal_float(clrand_context* ctx, cl_mem buffer, cl_int buf_size);
