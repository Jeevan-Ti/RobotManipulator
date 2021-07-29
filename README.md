# RobotManipulator
<p> For my personal anecdote and theory of project please visit GitHub page site <a href = "https://jeevan-ti.github.io/RobotManipulator/"><b>here</b></a>.</p>
<p>In this project I will first show the implementaion of manual control using LabVIEW, XBox & Arduino and then a fully autonomous implementation.
  
## Technical details
<p> A <a href = "https://www.linkedin.com/in/vinaykumarreddykomma/">friend</a> of mine later designed this 3D 3R-manipulator for an automatic soil mapping project, which use the same skeleton as the first arm design in the club. So for easier understanding I am showing it here: </p>

![20210727_130156](https://user-images.githubusercontent.com/49190581/127200899-f5317628-6345-4f21-9465-e68cfa2b8640.gif)

### Manual Control using LabVIEW & XBox
<p>The arm has three revolute joints (excluding end-effector). So, three servo motors with adequate torque had been used as actuators.</p>
Also the keys of XBox are as below:

![image](https://user-images.githubusercontent.com/49190581/127202916-da942dde-f313-4e12-8a2a-4eb488e4f7c2.png)

<p>Keys 14, 16 are analog keys whose output range from `- 32,000 to 32,000` and all the other keys were boolean.</p>
  
![image](https://user-images.githubusercontent.com/49190581/127184973-cc0a5b1d-22e9-42f1-b72b-733f363ba98d.png)

![image](https://user-images.githubusercontent.com/49190581/127190143-81cf5fea-1d30-4465-9fd8-31c8f6327ec4.png)


**Content Loading !!**
