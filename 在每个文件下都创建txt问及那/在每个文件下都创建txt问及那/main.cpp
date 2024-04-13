#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void Create_file(const fs::path& directory)
{
    // ʹ��Ŀ¼·�����ļ��������������ļ�·��
    fs::path filePath = directory / "polo.txt";
    std::ofstream outFile(filePath);

    // ����ļ��Ƿ�ɹ���
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing: " << filePath << std::endl;
        return;
    }

    // ���ļ�д������
    outFile << "showtime" << std::endl;

    // �ر��ļ�
    outFile.close();
}

void TraverseDirectory(const fs::path& directory)
{
    try {
        Create_file(directory); // �ڵ�ǰĿ¼�����ļ�

        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_directory()) {
                TraverseDirectory(entry.path()); // �ݹ����
            }
        }
    }
    catch (const fs::filesystem_error& e) {//û������̷����׳��쳣
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    fs::path startPathC = "C:\\"; // ���滻Ϊ����Ҫ��������ʼ·��
    TraverseDirectory(startPathC);
    fs::path startPathD = "D:\\";
    TraverseDirectory(startPathD);
    fs::path startPathE = "E:\\";
    TraverseDirectory(startPathE);
    fs::path startPathF = "F:\\";
    TraverseDirectory(startPathF);
    return 0;
}
