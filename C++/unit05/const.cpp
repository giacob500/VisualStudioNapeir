#include <iostream>
#include <string>

std::string join(const std::string& a, const std::string& b)
{
	//return a + b;
	std::string c = a;
	std::string d = b;
	std::string output = c.append(d);
	return output;
}

int main(int argc, char** argv)
{
	std::string greeting = join(std::string("Hello,"), std::string(" World!"));
	std::cout << greeting << std::endl;
	return 0;
}