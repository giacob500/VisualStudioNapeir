#include <iostream>
#include <vector>

void sort_copy(std::vector <int> data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		for (int j = 0; j < data.size() - (i + 1); ++j)
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
		if (i % 1000 == 0)
		{
			std::cout << ((float)i / (float)data.size()) * 100.0f << "% sorted " << std::endl;
		}
	}
}

void sort_reference(std::vector <int>& data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		for (int j = 0; j < data.size() - (i + 1); ++j)
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
		if (i % 1000 == 0)
		{
			std::cout << ((float)i / (float)data.size()) * 100.0f << "% sorted " << std::endl;
		}
	}
}

int main(int argc, char** argv)
{
	std::vector <int > data;
	for (int i = 0; i < 262144; ++i)
		data.push_back(262144 - i);

	std::cout << " Sorting by copy ..." << std::endl;
	sort_copy(data);
	std::cout << " Sorting by reference ..." << std::endl;
	sort_reference(data);
	return 0;
}