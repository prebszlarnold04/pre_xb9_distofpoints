#include <memory>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

class DistanceSubscriber : public rclcpp::Node
{
public:
    DistanceSubscriber() : Node("distance_subscriber"), previous_point_(nullptr)
    {
        subscription_ = this->create_subscription<geometry_msgs::msg::Point>(
            "random_coordinates", 10, std::bind(&DistanceSubscriber::calculate_distance, this, std::placeholders::_1));
    }

private:
    void calculate_distance(const geometry_msgs::msg::Point::SharedPtr point)
    {
        //Ha a beérkező koordináták az első pont koordinátái, akkor csak kiírjuk azokat a képernyőre
        if (previous_point_ == nullptr)
        {
            RCLCPP_INFO(this->get_logger(), "Az első generált pontunk: x=%.2f, y=%.2f", point->x, point->y);
            previous_point_ = std::make_shared<geometry_msgs::msg::Point>(*point);
            return;
        }

        // A két pont közötti távolság kiszámítása
        double distance = std::sqrt(
            std::pow(point->x - previous_point_->x, 2) +
            std::pow(point->y - previous_point_->y, 2));

        RCLCPP_INFO(this->get_logger(), "A kapott pontok: x=%.2f, y=%.2f ; A pontok közötti távolság: %.2f", point->x, point->y, distance);
        *previous_point_ = *point; // Az aktuális pontot beállítjuk az előző pontnak
    }

    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr subscription_;
    std::shared_ptr<geometry_msgs::msg::Point> previous_point_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DistanceSubscriber>());
    rclcpp::shutdown();
    return 0;
}
