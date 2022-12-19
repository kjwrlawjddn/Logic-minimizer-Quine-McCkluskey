#include "QMC.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <windows.h>
#include <bitset>

#define MAX 2147483647

using namespace std;

QMC::QMC()
{
	cout << "=============================================================================" << endl;
	cout << "=====================made by Jungwoo_Kim KwangWoon univ.=====================" << endl;
	cout << "=============================================================================" << endl;
	cout << "변수의 개수를 입력해 주세요: ";
	cin >> n;

	maximum_array = new unsigned long long[n];
	for (int i = 1; i < n + 1; i++)
	{
		maximum_array[i - 1] = (unsigned long long)((factorial(n) / (factorial((n - i)) * factorial(i))) * pow(2, (n - i)));
	}
	sort(maximum_array, maximum_array + n);

	N = (int)maximum_array[n - 1];

	delete[] maximum_array;

	//To calculate maximum possibility candidate prime implicants

	RPI_arr = new int** [2];
	for (int i = 0; i < 2; i++)
	{
		RPI_arr[i] = new int* [N];
		for (int j = 0; j < N; j++)
		{
			RPI_arr[i][j] = new int[3] {};
		}
	}

	PI_arr = new int* [(int)(pow(3, n) / n)];
	for (int i = 0; i < (int)(pow(3, n) / n); i++)
	{
		PI_arr[i] = new int[4] {};
	}

	cout << "엑셀에 작성한 진리표의 함수를 드래그 해서 붙여넣어 주세요" << endl;
	ini_arr = new char[(int)(pow(2, n))];
	for (int i = 0; i < (int)(pow(2, n)); i++)
	{
		cin >> ini_arr[i];
		if (count_minterms(ini_arr[i]) > 0)
		{
			RPI_arr[0][RPI_arr_row_p][0] = i;
			RPI_arr_row_p++;
		}
	}

	system("cls");
	cout << "=============================================================================" << endl;
	cout << "=====================made by Jungwoo_Kim KwangWoon univ.=====================" << endl;
	cout << "=============================================================================" << endl;
	cout << "calculating..." << endl;

	MD_arr = new int[(int)(pow(2, n))];
	for (int i = 0; i < (int)(pow(2, n)); i++)
	{
		MD_arr[i] = count_minterms(ini_arr[i]);
	}

	M_arr = new int[RPI_arr_row_p];

	for (int j = 0; j < (int)(pow(2, n)); j++)
	{
		if (count_minterms(ini_arr[j]) == 1)
		{
			M_arr[M_arr_row] = j;
			M_arr_row++;
		}
	}
}
QMC::~QMC()
{

	for (int i = 0; i < (int)(pow(3, n) / n); i++)
	{
		delete[] PI_arr[i];
	}
	delete[] PI_arr;

	delete[] M_arr;

	for (int i = 0; i < PI_arr_row; i++)
	{
		delete[] T_arr[i];
	}
	delete[] T_arr;
}

int QMC::reduce_array()
{
	return calculate_array();
}
void QMC::gen_table()
{
	generate_table();
}
void QMC::initiate_sorting()
{
	calculate_table();
}

inline int QMC::count_minterms(char a)
{
	if (a == '0')
		return 0;
	else if (a == '1')
		return 1;
	else
		return 2;
}
inline unsigned long long QMC::factorial(int n)
{
	unsigned long long product = 1;
	for (int i = n; i > 0; i--)
	{
		product *= i;
	}
	return product;
}
bool QMC::check_same_value()
{
	if (RPI_arr_row_n != 0)
	{
		for (int i = RPI_arr_row_n - 1; i >= 0; i--)
		{
			if ((
				(RPI_arr[NS][RPI_arr_row_n][1] ^ RPI_arr[NS][i][1]) |
				((RPI_arr[NS][RPI_arr_row_n][0] & (~RPI_arr[NS][RPI_arr_row_n][1])) ^ (RPI_arr[NS][i][0] & (~RPI_arr[NS][i][1])))) == 0)
				return false;
		}
	}
	return true;
}
//quine mcckluskey algorithm
int QMC::calculate_array()
{
	NS = 1 ^ PS;

	if (RPI_arr_row_p == 1)
	{
		PI_arr[PI_arr_row][0] = RPI_arr[PS][0][0];
		PI_arr[PI_arr_row][1] = RPI_arr[PS][0][1];
		PI_arr[PI_arr_row][2] = ~PI_arr[PI_arr_row][1];
		PI_arr[PI_arr_row][3] = PI_arr[PI_arr_row][0] & PI_arr[PI_arr_row][2];
		PI_arr_row++;
		return 0;
	}
	else if (RPI_arr_row_p == 0)
	{
		return 0;
	}
	else
	{
		PI_arr_check = 0;
		for (int i = 0; i < RPI_arr_row_p; i++)
		{
			PI_arr_check_mid = 0;
			for (int j = i + 1; j < RPI_arr_row_p; j++)
			{
				if (((((RPI_arr[PS][i][0] & (~RPI_arr[PS][i][1])) ^ (RPI_arr[PS][j][0] & (~RPI_arr[PS][j][1]))) &
					(((RPI_arr[PS][i][0] & (~RPI_arr[PS][i][1])) ^ (RPI_arr[PS][j][0] & (~RPI_arr[PS][j][1]))) - 1)) | (RPI_arr[PS][i][1] ^ RPI_arr[PS][j][1])) == 0)
				{
					RPI_arr[NS][RPI_arr_row_n][0] = RPI_arr[PS][i][0];
					RPI_arr[NS][RPI_arr_row_n][1] = ((RPI_arr[PS][i][0] & (~RPI_arr[PS][i][1])) ^ (RPI_arr[PS][j][0] & (~RPI_arr[PS][j][1]))) | RPI_arr[PS][i][1];
					RPI_arr[NS][RPI_arr_row_n][2] = 0;
					//As enter present loop, this element is not the prime implicant.
					RPI_arr[PS][i][2] = 1;
					RPI_arr[PS][j][2] = 1;
					//일단 대입한다. 이후 동일한 항이 있다면 RPI_arr_row_n를 증가시키지 않는다. 일단 대입먼저 해보고 결정하기 때문에 RPI_arr_row_n값이 초과될 수도 있다.
					//이것은 PI는 아니므로 PI_arr_check를 증가시킨다.
					PI_arr_check++;
					PI_arr_check_mid++;
					//check_same_value()를 이용해 여태까지의 u에서 같은 값이 있었는지 확인한다. 같은 값이 없다면 RPI_arr_row_n를 증가한다.
					//이때 RPI_arr[RPI_arr_row_n][i][0]값이 0인 경우에는 원래도 0이 저장되어 있기 때문에 예외로 빼어준다. 
					if ((RPI_arr[NS][RPI_arr_row_n][0] | RPI_arr[NS][RPI_arr_row_n][1]) != 0)
					{
						if (check_same_value())
						{
							RPI_arr_row_n++;
						}
					}
					else
					{
						RPI_arr_row_n++;;
					}

				}
			}
			//i가 모든 j와 비교를 끝냈을 때, RPI_arr[PS][i][2]가 0이면 PI이므로 PI에 대입한다.
			if ((RPI_arr[PS][i][2] | PI_arr_check_mid) == 0)
			{
				PI_arr[PI_arr_row][0] = RPI_arr[PS][i][0];
				PI_arr[PI_arr_row][1] = RPI_arr[PS][i][1];
				PI_arr[PI_arr_row][2] = ~PI_arr[PI_arr_row][1];
				PI_arr[PI_arr_row][3] = PI_arr[PI_arr_row][0] & PI_arr[PI_arr_row][2];
				PI_arr_row++;
			}
		}
		PS = NS;
		RPI_arr_row_p = RPI_arr_row_n;
		RPI_arr_row_n = 0;
		if (PI_arr_check != 0)
			return 1;
		else
			return 0;
	}
}

void QMC::print_minimized_PI(int count)
{
	if (print_constant)
	{
		cout << " + ";
	}
	else
	{
		system("cls");
		print_constant = true;
		cout << "=============================================================================" << endl;
		cout << "=====================made by Jungwoo_Kim KwangWoon univ.=====================" << endl;
		cout << "=============================================================================" << endl;
		cout << "\nminimized boolean expression : ";
	}
	for (int i = 0; i < n; i++)
	{
		if ((((1 << (n - i - 1)) & PI_arr[count][1]) >> (n - i - 1)) == 0)
		{
			if ((((1 << (n - i - 1)) & PI_arr[count][0]) >> (n - i - 1)) == 1)
			{
				cout << (char)('A' + i);
			}
			else
			{
				cout << (char)('A' + i) << "'";
			}
		}
	}
}

//table sorting algorithm
void QMC::generate_table()
{
	T_arr = new int* [PI_arr_row];
	for (int i = 0; i < PI_arr_row; i++)
	{
		T_arr[i] = new int[M_arr_row + 1] {};
	}

	for (int i = 0; i < PI_arr_row; i++)
	{
		for (int j = 0; j < M_arr_row; j++)
		{
			if ((M_arr[j] & PI_arr[i][2]) == PI_arr[i][3])
			{
				T_arr[i][j] = 1;
			}
			else
				T_arr[i][j] = 0;
		}
	}
}
void QMC::calculate_table()
{
	//memory manage
	delete[] ini_arr;
	delete[] MD_arr;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			delete[] RPI_arr[i][j];
		}
		delete[] RPI_arr[i];
	}
	delete[] RPI_arr;

	cursor = 0;
	cursor_arr = new int[PI_arr_row] {};
	int temp;

	for (int i = 0; i < PI_arr_row; i++)
	{
		cursor_arr[i] = i;
	}
	//find essential prime implicants
	for (int j = 0; j < M_arr_row; j++)
	{
		temp = 0;
		for (int i = 0; i < PI_arr_row; i++)
		{
			temp += T_arr[i][j];
			if ((temp == 1) && (T_arr[i][j] == 1))
				cursor = i;
		}
		if (temp == 1)
		{
			cursor_arr[cursor] = MAX;
			print_minimized_PI(cursor);
			subtract_T_arr_row();
		}
	}

	sort(cursor_arr, cursor_arr + PI_arr_row);

	int freq = 0;
	while (1)
	{
		freq = count_frequency();
		if (freq == 0)
			break;

		subtract_T_arr_row_freq();
		print_minimized_PI(cursor);
		sort(cursor_arr, cursor_arr + PI_arr_row);
	}
	cout << "\n\n\n\n\n\n\n\n\n";
}

void QMC::subtract_T_arr_row()
{
	for (int i = 0; i < PI_arr_row; i++)
	{
		if (i != cursor)
		{
			for (int j = 0; j < M_arr_row; j++)
			{
				T_arr[i][j] = T_arr[i][j] & (~T_arr[cursor][j]);
			}
		}
	}
	for (int j = 0; j < M_arr_row; j++)
	{
		T_arr[cursor][j] = 0;
	}
	T_arr[cursor][M_arr_row] = 0;
}

void QMC::subtract_T_arr_row_freq()
{
	int i = 0;
	int temp = 0;
	for (cursor_arr[i]; cursor_arr[i] < MAX; i++)
	{
		if (cursor_arr[i] != cursor)
		{
			for (int j = 0; j < M_arr_row; j++)
			{
				T_arr[cursor_arr[i]][j] = T_arr[cursor_arr[i]][j] & (~T_arr[cursor][j]);
			}
		}
		else
		{
			temp = i;
		}
	}
	for (int j = 0; j < M_arr_row + 1; j++)
	{
		T_arr[cursor][j] = 0;
	}
	cursor_arr[i] = MAX;
}

int QMC::count_frequency()
{
	int temp = 0;
	int finish = 0;
	int i = 0;
	for (cursor_arr[i]; cursor_arr[i] < MAX; i++)
	{
		T_arr[cursor_arr[i]][M_arr_row] = 0;
		for (int j = 0; j < M_arr_row; j++)
		{
			T_arr[cursor_arr[i]][M_arr_row] += T_arr[cursor_arr[i]][j];
		}
		if (temp < T_arr[cursor_arr[i]][M_arr_row])
		{
			temp = T_arr[cursor_arr[i]][M_arr_row];
			cursor = cursor_arr[i];
		}
	}

	return temp;
}

