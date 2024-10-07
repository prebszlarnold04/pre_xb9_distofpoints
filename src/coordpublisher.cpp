#include <chrono>
#include <memory>
#include <random>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

using namespace std::chrono_literals;

class CoordinatePublisher : public rclcpp::Node
{
public:
    CoordinatePublisher() : Node("coordinate_publisher")
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Point>("random_coordinates", 10);
        timer_ = this->create_wall_timer(1000ms, std::bind(&CoordinatePublisher::publish_coordinates, this));
    }

private:
    void publish_coordinates()
    {
        auto message = geometry_msgs::msg::Point();
        message.x = random_coordinate();
        message.y = random_coordinate();
        message.z = 0.0; // Z tengely nem szükséges, mivel 2D koordinátákat használunk :)
        RCLCPP_INFO(this->get_logger(), "A generált pontok: x=%.2f, y=%.2f", message.x, message.y);
        publisher_->publish(message);
    }

    double random_coordinate()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-200.0, 200.0);
        return dis(gen);
    }

    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CoordinatePublisher>());
    rclcpp::shutdown();
    return 0;
}
