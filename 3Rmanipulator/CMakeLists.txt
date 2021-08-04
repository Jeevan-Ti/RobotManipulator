add_library(3Rmanipulator
	src/3Rmanipulator.cpp
  "src/utilities/Point.h" "src/utilities/Point.cpp" "src/utilities/Kinematics.h" "src/utilities/Kinematics.cpp" "src/utilities/Angle.h" "src/utilities/Angle.cpp")

target_include_directories(3Rmanipulator PUBLIC src src/utilities)
