#include <iostream>
using namespace std;

typedef enum
{
	void_data_type,
	int_data_type,
    float_data_type,
    double_data_type,
    return_data_type
} Data_Type;


struct Eval_Result_Ret{
	int int_ret;
	float float_ret;
	double double_ret;
	Data_Type data_type;

};
	

#define replace(r) ((r.data_type == double_data_type)? r.double_ret : (r.data_type == float_data_type)? r.float_ret : r.int_ret)

int main(){
	
	Eval_Result_Ret r;
	r.data_type = int_data_type;
	r.int_ret = 1;
	cout<<replace(r)<<endl;
	return 0;
}
	
