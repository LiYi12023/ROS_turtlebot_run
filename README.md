# ROS_turtlebot_run
此專案用於使turtlebot在模擬環境中，能夠自動移動並在發生碰撞後轉向。  
This is the code used to let turtlebot move and avoidance obstacle automatically.
## 使用方法 Usage
**1. 下載 Download**  
在終端機中首先移動至想存取的工作環境中，接著下載檔案：  
Moves to the work space and then clone the project.  
`$ git clone https://github.com/LiYi12023/ROS_turtlebot_run.git`

**2. 編輯及建立程式 Edit and build**  
在終端機中輸入以下資料，以更新並建立程式  
Add the environment variables and build the program.  
` $ source devel/setup.bash`  
` $ catkin_make`  


**3. 選擇程式  Choose the code**   

程式 Program|介紹 Introduction 
:------:|:----------:   
go_straight.cpp| 使turtlebot不斷前進  
 -|Let turtlebot go straight    
try_getinf.cpp|獲得Bumper的資訊 
 -|Get the bumper information 
run_avoid.cpp|使turtlebot不斷前進，並在碰撞後轉向 
 -|Let turtlebot go straight and change direction when bumper was hit
run_avoid.launch|使用roslaunch開啟
 -|Open by the roslaunch   
## 測試 Test
**1. go_straight**  
`$ roslaunch turtlebot_gazebo turtlebot_world.launch`  
`$ rosrun ROS_turtlebot_run go_straight`  

**2. try_getinf**  
`$ roslaunch turtlebot_gazebo turtlebot_world.launch`  
`$ rosrun ROS_turtlebot_run try_getinf`  

**3. run_avoid**  
`$ roslaunch turtlebot_gazebo turtlebot_world.launch`  
`$ rosrun ROS_turtlebot_run run_avoid`  

**4. run_avoid.launch**  
`$ roslaunch turtlebot_gazebo turtlebot_world.launch`  
`$ roslaunch ROS_turtlebot_run run_avoid.launch`  

## LICENSE
請查看資料夾中LICENSE檔案，以獲得更多相關資訊。  
Please see the LICENSE file for more information.
