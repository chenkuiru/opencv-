#pragma once
#ifndef __OPENCV_CONTRIB_HPP__
#define __OPENCV_CONTRIB_HPP__
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
class CV_EXPORTS Directory
{
public:
	static std::vector<std::string> GetListFiles(const std::string& path, const std::string & exten = "*", bool addPath = true);
	static std::vector<std::string> GetListFilesR(const std::string& path, const std::string & exten = "*", bool addPath = true);
	static std::vector<std::string> GetListFolders(const std::string& path, const std::string & exten = "*", bool addPath = true);
};
#endif