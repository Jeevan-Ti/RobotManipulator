# 3R Robot Manipulator

<p align="justify">
This project implements manual control of a 3R-manipulator using LabVIEW, XBox & Arduino and then a fully autonomous varient, whose inverse kinematic solution is implemented using C++.
  </p>
  
## Technical details
A <a href="https://www.linkedin.com/in/vinaykumarreddykomma/" target="_blank" rel="noreferrer noopener"><u>friend</u></a> of mine later designed this 3D 3R-manipulator for an automatic soil mapping project, which use the same skeleton as the first arm design in the club. So for easier understanding I am showing it here: <br> <br>
  
![20210727_130156](https://user-images.githubusercontent.com/49190581/127200899-f5317628-6345-4f21-9465-e68cfa2b8640.gif)

<h3>
<a id="manual_code">Manual Control using LabVIEW & XBox</a>
  </h3>
  
<p align="justify">The arm has three revolute joints (excluding end-effector). So, three servo motors with adequate torque have been used as actuators.</p>
Also the keys of XBox are as below:

<img src = "https://user-images.githubusercontent.com/49190581/127202916-da942dde-f313-4e12-8a2a-4eb488e4f7c2.png" alt="xbox layout" width="400" height="auto">

<p align="justify"> Here keys 14, 16 are analog keys whose output range from `- 32,000 to 32,000` and all the other keys are just boolean.</p>

#### LabVIEW Control Panel
  
![image](https://user-images.githubusercontent.com/49190581/127184973-cc0a5b1d-22e9-42f1-b72b-733f363ba98d.png) <!--LabVIEW CP-->

#### LabVIEW Block Logic

<p align="justify"> Because of all the wiring and absence of abstraction in blocks, it might seem a little clumsy, but the implementation is pretty straignt forward. For all the boolean inputs an `adder` or a `substracter` is connected and pressing a boolean input increases or decreases the servo angle. `if - else` containers have been used to clamp the variables from incrementing beyond joint angle limit. Whereas for analog inputs, use of a down-scaler  has been made to map the analog input to range of joint angles. Also one servo we used has just a speed control, so double loop logic has been used in such case.</p>

![image](https://user-images.githubusercontent.com/49190581/127190143-81cf5fea-1d30-4465-9fd8-31c8f6327ec4.png) <!--LabVIEW block diagram-->


### Autonomous Implementation


**Content Loading !!**
