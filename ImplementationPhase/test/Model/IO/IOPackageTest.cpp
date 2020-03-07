#include <gtest/gtest.h>

#include "TextFileIO_test.hpp"
#include "ImageFileIO_test.hpp"
#include "MultipleTextFileIO_test.hpp"
#include "MultipleImageFileIO_test.hpp"
#include "VideoFileIO_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
