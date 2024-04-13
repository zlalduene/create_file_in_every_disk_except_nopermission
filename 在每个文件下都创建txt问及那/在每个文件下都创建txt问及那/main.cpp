#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void Create_file(const fs::path& directory)
{
    // 使用目录路径和文件名创建完整的文件路径
    fs::path filePath = directory / "polo.txt";
    std::ofstream outFile(filePath);

    // 检查文件是否成功打开
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing: " << filePath << std::endl;
        return;
    }

    // 向文件写入内容
    outFile << "showtime" << std::endl;

    // 关闭文件
    outFile.close();
}

void TraverseDirectory(const fs::path& directory)
{
    try {
        Create_file(directory); // 在当前目录创建文件

        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_directory()) {
                TraverseDirectory(entry.path()); // 递归调用
            }
        }
    }
    catch (const fs::filesystem_error& e) {//没有这个盘符就抛出异常
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    fs::path startPathC = "C:\\"; // 请替换为您想要遍历的起始路径
    TraverseDirectory(startPathC);
    fs::path startPathD = "D:\\";
    TraverseDirectory(startPathD);
    fs::path startPathE = "E:\\";
    TraverseDirectory(startPathE);
    fs::path startPathF = "F:\\";
    TraverseDirectory(startPathF);
    return 0;
}
