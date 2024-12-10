from setuptools import find_packages, setup

package_name = 'gpg_urdf'
#spackage_name = 'turtlesim_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['launch/gpg_sim.launch.py']),
        ('share/' + package_name, ['launch/gpg_sim_unstable_imu.launch.py']),
        ('share/' + package_name, ['launch/gpg_sim_futebol.launch.py']),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name, ['config/world_1.sdf']),
        ('share/' + package_name, ['config/world_ball.sdf']),
        ('share/' + package_name, ['config/camera.yaml']),
        ('share/' + package_name, ['config/controllers.yaml']),
        ('share/' + package_name, ['config/gpg.urdf.xml']),
        ('share/' + package_name, ['config/gpg_unstable.urdf.xml']),
        ('share/' + package_name, ['config/gpg_unstable_2.urdf.xml']),
        ('share/' + package_name, ['config/gpg_urdf.rviz']),
        ('share/' + package_name, ['config/gpg_urdf_ball.rviz']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'urdf_node = gpg_urdf.urdf_node:main',
            'cv_node = gpg_urdf.cv_node:main',
            'cv_goal = gpg_urdf.cv_goal:main'
        ],
    },
)
