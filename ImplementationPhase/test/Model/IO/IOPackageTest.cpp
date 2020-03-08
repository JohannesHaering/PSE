#define TESTDIR _TESTDIR

#include <gtest/gtest.h>

#include "TextFileIO_test.hpp"
#include "ImageFileIO_test.hpp"
#include "MultipleTextFileIO_test.hpp"
#include "MultipleImageFileIO_test.hpp"
#include "VideoFileIO_test.hpp"

#include "TextFileIO.hpp"
#include "ImageFileIO.hpp"
#include "NeuralNetworkFacade.hpp"
#include "Data.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

int main(int argc, char **argv)
{
  struct stat info;

  if (stat(TESTDIR, &info) != 0)
  {
    mkdir(TESTDIR, 0);
    mkdir(TESTDIR + "\\readdir", 0);
    mkdir(TESTDIR + "\\writedir", 0);
  }
  else
  {
    if (stat(TESTDIR + "\\readdir", &info) != 0)
    {
      mkdir(TESTDIR + "\\readdir", 0);

      auto io = TextFileIO();
      io.writeFile(TESTDIR + "\\readdir\\testTXT.txt", Data<std::string>("foo"));

      auto io = ImageFileIO();
      cv::Mat mat(64, 64, CV_32F, cv::Scalar(0, 0, 0));
      io.writeFile(Data<cv::Mat>(mat), TESTDIR + "\\readir\\testBMPWrite.bmp");
    }
    if (stat(TESTDIR + "\\writedir", &info) !=)
    {
      mkdir(TESTDIR + "\\writedir", 0);
    }
  }

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
