#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

template <typename T>
std::time_t to_time_t(T type)
{
	using namespace std::chrono;
	auto sctp = time_point_cast<system_clock::duration>(type - T::clock::now() + system_clock::now());
	return system_clock::to_time_t(sctp);
}

void view_directory(const std::filesystem::path& path)
{
	if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
	{
		for (auto a : std::filesystem::directory_iterator(path))
		{
			auto file_name = a.path().filename().string();
			std::cout << "File name: ";
			std::cout << file_name << std::endl;
			std::reverse(file_name.begin(), file_name.end());
			int i = 0;
			bool flag = 1;
			std::string type;
			while (flag)
			{
				type.push_back(file_name[i]);
				i = i + 1;
				std::string r = ".";
				if (file_name[i] == r[0]) {
					flag = 0;
				}
			}
			std::reverse(type.begin(), type.end());
			std::cout << "File type: ";
			std::cout << type << "\n";
			auto ftime = std::filesystem::last_write_time(a);
			std::time_t cftime = to_time_t(ftime);
			std::cout << "Last modified: ";
			std::cout << std::asctime(std::localtime(&cftime)) << "\n";
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::filesystem::path path;
	//path = "C:\\Тест";
	std::cout << "Enter directory\n";
	std::cin >> path;
	view_directory(path);
	return 0;
}
