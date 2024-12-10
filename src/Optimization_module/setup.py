from setuptools import find_packages, setup

package_name = 'Optimization_module'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name, ['launch/evolution_based_optimizer_PID_tunner.launch.py']),
        ('share/' + package_name, ['launch/env_optimizer_PID_tunner.launch.py'])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lci',
    maintainer_email='grmc1999@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "model_node = Optimization_module.model_node:main",
            "objective_node = Optimization_module.objective_node:main",
            "proxy_node = Optimization_module.proxy_node:main",
            "PID_model_node = Optimization_module.PID_model_node:main",
            "IMU_proxy_node = Optimization_module.IMU_proxy_node:main",
            "stability_objective_node = Optimization_module.stability_objective_node:main",
            "time_enforced_objective_node = Optimization_module.stability_time_enforced_objective_node:main",
        ],
    },
)
