from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='pre_xb9_distofpoints',
            executable='coordpublisher',
            name='coordpublisher',
             output='screen'
        ),
        Node(
            package='pre_xb9_distofpoints',
            executable='coordsubscriber',
            name='coordsubscriber',
            output='screen'
        ),
    ])