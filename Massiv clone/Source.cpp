#include"array.h"

int main() {
	srand(time(NULL));
	ifstream in_file("in.txt");
	Array arr[6];

	Array zero(12, 0);
	Array twelve(12, 12);
	Array amount(zero);
	Array difference(zero);

	Array max_arr(zero);
	Array min_arr(twelve);

	while (true) {
		int choice;
		cout << " Enter 1 to read marks from file" << endl;
		cout << " Enter 2 to get marks randomly" << endl;
		cout << " Enter 3 to find student with the best marks" << endl;
		cout << " Enter 4 to find the students with the worst marks" << endl;
		cout << " Enter 5 to print out all months when each student got the best mark" << endl;
		cout << " Enter 6 to print out all months when each student got the worst mark" << endl;
		cout << " Enter 7 to record the amount of marks of all students for each month" << endl;
		cout << " Enter 8 to record the difference between marks of the best and the worst student" << endl;
		cout << " Enter 9 to print out info about all students" << endl;
		cout << " Enter 0 to exit" << endl << endl;;
		cin >> choice;
		cout << endl;
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < 6; i++)
				in_file >> arr[i];

			cout << endl;
			for (int i = 0; i < 6; i++)
				cout << arr[i] << endl;
			cout << endl;
			break;
		case 2:
			for (int i = 0; i < 6; i++)//why the same? f10 different
			{
				arr[i].random();
				cout << arr[i] << endl;
			}
			cout << endl;
			break;
		case 3:
			for (int i = 0; i < 6; i++)
				if (arr[i] > max_arr || arr[i] == max_arr)
					max_arr = arr[i];
			cout << max_arr << endl << endl;

			break;
		case 4:
			for (int i = 0; i < 6; i++)
				if (arr[i] < min_arr || arr[i] == min_arr)
					min_arr = arr[i];
			cout << min_arr << endl << endl;
			break;
		case 5:
			for (int i = 0; i < 6; i++)
				arr[i].max_el_pos();
			cout << endl;
			break;
		case 6:
			for (int i = 0; i < 6; i++)
				arr[i].min_el_pos();
			cout << endl;
			break;
		case 7:
			amount = zero;
			for (int i = 0; i < 6; i++)
				amount += arr[i];
			cout << amount << endl << endl;
			break;
		case 8:
			for (int i = 0; i < 6; i++)
			{
				if (arr[i] > max_arr || arr[i] == max_arr)
					max_arr = arr[i];
				if (arr[i] < min_arr || arr[i] == min_arr)
					min_arr = arr[i];
			}
			difference = max_arr - min_arr;
			cout << difference << endl << endl;
			break;
		case 9:
			for (int i = 0; i < 6; i++)
				cout << arr[i];
			cout << endl << endl;
			break;
		}
	}

	system("pause");
	return 0;
}