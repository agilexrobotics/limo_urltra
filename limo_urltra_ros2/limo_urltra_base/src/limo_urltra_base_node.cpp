
#include "limo_urltra_base/limo_urltra_driver.h"

using namespace AgileX;
std::shared_ptr<LimourltraDriver> robot;

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<LimourltraDriver>("limo_urltra"));
  rclcpp::Rate rate(20);
  rate.sleep();
  rclcpp::shutdown();

  return 0;
}
