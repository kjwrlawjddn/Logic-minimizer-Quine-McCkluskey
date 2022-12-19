#pragma once
class QMC
{
public:

	QMC();
	~QMC();

	int reduce_array();
	void gen_table();
	void initiate_sorting();

protected:
	int n;
	int N;

	bool print_constant = false;

	//QM algorithm

	unsigned long long* maximum_array;
	char* ini_arr;
	int* M_arr;
	int* MD_arr;
	int*** RPI_arr;
	int** PI_arr;
	int** T_arr;
	int cursor;
	int* cursor_arr;


	int M_arr_row = 0;
	int RPI_arr_row_p = 0;
	int RPI_arr_row_n = 0;
	int PI_arr_row = 0;

	//whether PI or not
	int PI_arr_check = 0;
	int PI_arr_check_mid = 0;
	//present state
	int PS = 0;
	//next state	
	int NS = 0;

	//QMC fucntions

	inline unsigned long long factorial(int n);
	inline int count_minterms(char a);
	bool check_same_value();

	void print_minimized_PI(int count);

	int calculate_array();

	//table sort algorithm
	void generate_table();

	void calculate_table();
	void subtract_T_arr_row();
	void subtract_T_arr_row_freq();
	int count_frequency();
};
