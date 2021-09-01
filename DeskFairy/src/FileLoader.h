#pragma once

#include <string>

using Bytes = unsigned char;

//文件加载器
class FileLoader
{
public:
	static Bytes* Load(const std::string filePath, unsigned int* outSize);

	static void Release(Bytes* byteData);
};

