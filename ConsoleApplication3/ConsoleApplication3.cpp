#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

/*auto compute_file_size(const std::filesystem::path& path)
{
	if (std::filesystem::exists(path) && std::filesystem::is_regular_file(path))
	{
		auto file_size = std::filesystem::file_size(path);

		if (file_size != static_cast <uintmax_t> (-1))
		{
			return file_size;
		}
	}

	return static_cast <uintmax_t> (-1);
}

auto compute_directory_size(const std::filesystem::path& path)
{
	uintmax_t size = 0ULL;

	if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
	{
		for (auto const& entry : std::filesystem::recursive_directory_iterator(path))
		{
			if (std::filesystem::is_regular_file(entry.status()) || std::filesystem::is_symlink(entry.status()))
			{
				auto file_size = std::filesystem::file_size(entry);

				if (file_size != static_cast <uintmax_t> (-1))
				{
					size += file_size;
				}
			}
		}
	}

	return size;
}*/

void view_directory(const std::filesystem::path& path)
{
	if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
	{
		for (auto a : std::filesystem::directory_iterator(path))
		{
			auto file_name = a.path().filename().string();
			std::cout << "File name: ";
			std::cout << file_name << std::endl;
			std::cout << "File type: ";
			/*for (int i = 0; i<3; i++ )
			std::cout << std::vector<int> = std::filesystem::last_write_time(path);
			std::cout << "Last modified: ";*/
		}
	}
}

int main()
{
	std::filesystem::path path;
	std::cout << "Enter directory\n";
	std::cin >> path;
	
	view_directory(path);
	return 0;
}
